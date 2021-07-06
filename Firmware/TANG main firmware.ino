
#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>

#include <OneWire.h>
#include <DallasTemperature.h>


// SI7021 I2C address is 0x40(64)
#define si7021Addr 0x40

// Replace the next variables with your SSID/Password combination
const char* ssid = "MNM";
const char* password = "k1gju32mnm";

// Add your MQTT Broker IP address, example:
//const char* mqtt_server = "192.168.1.144";
const char* mqtt_server = "192.168.1.18";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg1 = 0;
long lastMsg2 = 0;
char msg[50];
int value = 0;

// SI7021 vars
float temperature = 0;
float humidity = 0;

int counter = 0;

float capmoisture1avg = 0;
float capmoisture2avg = 0;
float capmoisture3avg = 0;
float capmoisture1total = 0;
float capmoisture2total = 0;
float capmoisture3total = 0;
float capmoisture1 = 0;
float capmoisture2 = 0;
float capmoisture3 = 0;


//1-wire temp sens
const int oneWireBus = 26;     
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);


// LED Pin
const int ledPin = 2;
const int relayPin = 23;
const int capmoisture1pin = 33;
const int capmoisture2pin = 39;
const int capmoisture3pin = 35;


void setup() {
  Serial.begin(115200);
  // default settings
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(capmoisture1pin, INPUT);
  pinMode(capmoisture2pin, INPUT);
  pinMode(capmoisture3pin, INPUT);

  Wire.begin();
  Wire.beginTransmission(si7021Addr);
  Wire.endTransmission();
  delay(300);

  //onewire
  sensors.begin();
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic esp32/output, you check if the message is either "on" or "off". 
  // Changes the output state according to the message
  if (String(topic) == "esp32/LEDoutput") {
    Serial.print("Changing output to ");
    if(messageTemp == "on"){
      Serial.println("on");
      digitalWrite(ledPin, HIGH);
    }
    else if(messageTemp == "off"){
      Serial.println("off");
      digitalWrite(ledPin, LOW);
    }
  }

  if (String(topic) == "esp32/RELAYoutput") {
    Serial.print("Changing output to ");
    if(messageTemp == "on"){
      Serial.println("on");
      digitalWrite(relayPin, HIGH);
    }
    else if(messageTemp == "off"){
      Serial.println("off");
      digitalWrite(relayPin, LOW);
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("esp32/output");
      client.subscribe("esp32/LEDoutput");
      client.subscribe("esp32/RELAYoutput");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Multisampling with averaging to reduce noise
  long now1 = millis();
  if (now1 - lastMsg1 > 5000) {
    lastMsg1 = now1;

    // CAP MOISTURE READINGS
    capmoisture1 = analogRead(capmoisture1pin);
    capmoisture1total = capmoisture1total + capmoisture1;
    capmoisture2 = analogRead(capmoisture2pin);
    capmoisture2total = capmoisture2total + capmoisture2;
    capmoisture3 = analogRead(capmoisture3pin);
    capmoisture3total = capmoisture3total + capmoisture3;
    
    counter++;
  }


  // publishing averaged readings to MQTT every 5 minutes
  long now2 = millis();
  if (now2 - lastMsg2 > 300000) {
    lastMsg2 = now2;

    // Divide the totals by number of readings and reset totals and counter. Pass avg to mqtt publish
    capmoisture1avg = capmoisture1total/counter;
    capmoisture2avg = capmoisture2total/counter;
    capmoisture3avg = capmoisture3total/counter;

    capmoisture1total = 0;
    capmoisture2total = 0;
    capmoisture3total = 0;
    counter = 0;

    // CAP MOISTURE READINGS
    char moisture1String[8];
    dtostrf(capmoisture1avg, 1, 2, moisture1String);
    Serial.print("moisture1String: ");
    Serial.println(moisture1String);
    client.publish("esp32/moisture1", moisture1String);

    char moisture2String[8];
    dtostrf(capmoisture2avg, 1, 2, moisture2String);
    Serial.print("moisture2String: ");
    Serial.println(moisture2String);
    client.publish("esp32/moisture2", moisture2String);

    char moisture3String[8];
    dtostrf(capmoisture3avg, 1, 2, moisture3String);
    Serial.print("moisture3String: ");
    Serial.println(moisture3String);
    client.publish("esp32/moisture3", moisture3String);

    // ANALOG TEMP READINGS
    sensors.requestTemperatures(); 
    float temperatureC = sensors.getTempCByIndex(0);
    char temperatureCString[8];
    dtostrf(temperatureC, 1, 2, temperatureCString);
    Serial.print("Tempsensor ");
    Serial.print(temperatureCString);
    Serial.println("ºC");
    client.publish("esp32/temperature1", temperatureCString);
    
  /*
    // SI7021 READING
    unsigned int data[2];
     
    Wire.beginTransmission(si7021Addr);
    //Send humidity measurement command
    Wire.write(0xF5);
    Wire.endTransmission();
    delay(500);
       
    // Request 2 bytes of data
    Wire.requestFrom(si7021Addr, 2);
    // Read 2 bytes of data to get humidity
    if(Wire.available() == 2)
    {
      data[0] = Wire.read();
      data[1] = Wire.read();
    }
       
    // Convert the data
    float humidity  = ((data[0] * 256.0) + data[1]);
    humidity = ((125 * humidity) / 65536.0) - 6;
   
    Wire.beginTransmission(si7021Addr);
    // Send temperature measurement command
    Wire.write(0xF3);
    Wire.endTransmission();
    delay(500);
       
    // Request 2 bytes of data
    Wire.requestFrom(si7021Addr, 2);
     
    // Read 2 bytes of data for temperature
    if(Wire.available() == 2)
    {
      data[0] = Wire.read();
      data[1] = Wire.read();
    }
   
    // Convert the data
    float temp  = ((data[0] * 256.0) + data[1]);
    float celsTemp = ((175.72 * temp) / 65536.0) - 46.85;
    //float fahrTemp = celsTemp * 1.8 + 32;
    
    // Convert the value to a char array
    char tempString[8];
    dtostrf(celsTemp, 1, 2, tempString);
    Serial.print("Temperature: ");
    Serial.println(tempString);
    client.publish("esp32/temperature", tempString);

    
    // Convert the value to a char array
    char humString[8];
    dtostrf(humidity, 1, 2, humString);
    Serial.print("Humidity: ");
    Serial.println(humString);
    client.publish("esp32/humidity", humString);


  */



    
  }
}
