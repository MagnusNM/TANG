#include <Arduino.h>

#include <PubSubClient.h> // Needed for MQTT
#include <WiFi.h>         // Needed for WiFi
#include <Wire.h>         // Needed for I2C

#include <iostream>       // Needed for string conversion later

#include <network_info.h> // File that contains SSID, pwd, and MQTT server address

char msg[50];   // Used for the MQTT payload

#define Si7021_address 0x40 // I2C address for the temp/RH sensor

WiFiClient espClient;
PubSubClient client(espClient);


/*
The relay class assigns a pin to active a relay for X milliseconds upon calling the enable method. 
The update method will automatically turn off the relay after X milliseconds have passed.
*/
class relay{
  private:
  unsigned long previous_millis;
  int relay_pin;
  int on_time;

  public:
  relay(int relay_input){
    relay_pin = relay_input;
    pinMode(relay_pin,OUTPUT);
  }

  void enable(int on_time_input){
    digitalWrite(relay_pin,HIGH);
    on_time = on_time_input;
    previous_millis = millis();
  }

  void update(){
    unsigned long current_millis = millis();
    if(current_millis - previous_millis >= on_time){
      digitalWrite(relay_pin,LOW);
      digitalWrite(2,LOW);
    }   
  }
  
  
};

class sensor{
  public:
  int period;
  int address;
  float relative_humidity;
  float temperature;
  float measurement_payload[2];

  sensor(int address_input,int period_input){
    address = address_input;
    period = period_input;
    Wire.beginTransmission(address);
    Wire.endTransmission();
  }
  float* get_measurement(){
    unsigned int data[2];


    Wire.beginTransmission(address); // Begin comms with the Si70217
    Wire.write(0xE5); // Ask for a humidity reading
    Wire.endTransmission(address);
    //delay(50);
    Wire.requestFrom(address,2);
    if (Wire.available()==2){
      data[0] = Wire.read();
      data[1] = Wire.read();
    }
    relative_humidity = ((data[0]*256.0)+data[1]);
    relative_humidity = ((125*relative_humidity) / 65536) - 6;
    
  Wire.beginTransmission(address); // Begin comms with the Si70217
  Wire.write(0xE3); // Ask for a temperature reading
  Wire.endTransmission(address);
  //delay(50);
  Wire.requestFrom(address,2);
  if (Wire.available()==2){
    data[0] = Wire.read();
    data[1] = Wire.read();
  }
  temperature = ((data[0]*256.0)+data[1]);
  temperature = ((175.72*temperature) / 65536) - 46.85;

  measurement_payload[0] = relative_humidity;
  measurement_payload[1] = temperature;

  return(measurement_payload);
  }

  void update(){
    
  }
};

relay digdig(23);
relay dugdug(19);

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("mining/shutdown_button_digdig");
      client.subscribe("mining/shutdown_button_dugdug");
      client.subscribe("esp32/temperature");
      client.subscribe("esp32/humidity");
      client.subscribe("esp32/heartbeat");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String payload;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    payload += (char)message[i];
  }
  Serial.println();

  /* 
  In order to feed the payload to the enable() method, it needs to be a integer. 
  However, to convert the string to an int, we need to convert the string to a C string from a C++ string,
  since the atoi() function only takes C strings. atoi() will silently fail, so we first check if the value is >0.
  */

  if(String(topic) == "mining/shutdown_button_digdig") {
    int integer_payload = atoi(payload.c_str());
    if(integer_payload){
      digdig.enable(integer_payload);
    }
  }
  else if(String(topic) == "mining/shutdown_button_dugdug") {
    int integer_payload = atoi(payload.c_str());
    if(integer_payload){
      dugdug.enable(integer_payload);
    }
  }
}

void setup() {
  Wire.begin();
  Serial.begin(9600);

  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  
  
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  digdig.update();
  dugdug.update();
}