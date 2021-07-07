EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x15_Female J?
U 1 1 60EB5BF0
P 2350 6100
F 0 "J?" H 2200 7000 50  0000 L CNN
F 1 "Conn_01x15_Female" H 1900 5300 50  0000 L CNN
F 2 "" H 2350 6100 50  0001 C CNN
F 3 "~" H 2350 6100 50  0001 C CNN
	1    2350 6100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x15_Female J?
U 1 1 60EB76DA
P 3200 6100
F 0 "J?" H 3100 7000 50  0000 C CNN
F 1 "Conn_01x15_Female" H 3150 5300 50  0000 C CNN
F 2 "" H 3200 6100 50  0001 C CNN
F 3 "~" H 3200 6100 50  0001 C CNN
	1    3200 6100
	-1   0    0    -1  
$EndComp
Wire Notes Line style solid
	2500 6000 2500 5400
Wire Notes Line style solid
	3050 5400 3050 6000
Wire Notes Line style solid
	3050 6000 2500 6000
Wire Notes Line style solid
	2500 5550 3050 5550
Wire Notes Line style solid
	3000 5550 3000 5450
Wire Notes Line style solid
	2900 5450 2900 5550
Wire Notes Line style solid
	2750 5450 2750 5500
Wire Notes Line style solid
	2750 5500 2650 5500
Wire Notes Line style solid
	2650 5500 2650 5450
Wire Notes Line style solid
	2650 5450 2550 5450
Wire Notes Line style solid
	2550 5450 2550 5500
Wire Notes Line style solid
	2750 5450 3000 5450
Wire Notes Line style solid
	2650 6850 2900 6850
Wire Notes Line style solid
	2900 6850 2900 6600
Wire Notes Line style solid
	2900 6600 2650 6600
Wire Notes Line style solid
	2650 6600 2650 6850
Text Notes 2650 5800 0    50   ~ 0
WROOM\nCHIP
Text Notes 2700 6750 0    50   ~ 0
USB
Wire Notes Line style solid
	2350 6800 2350 5400
Wire Notes Line style solid
	3200 5400 3200 6800
Wire Notes Line style solid
	3200 6800 2900 6800
Wire Notes Line style solid
	2350 5400 3200 5400
Wire Notes Line style solid
	2650 6800 2350 6800
Text GLabel 3400 5400 2    50   BiDi ~ 0
GPIO23
Text GLabel 3400 5500 2    50   BiDi ~ 0
GPIO22
Text GLabel 3400 5600 2    50   BiDi ~ 0
GPIO1
Text GLabel 3400 5700 2    50   BiDi ~ 0
GPIO3
Text GLabel 3400 5800 2    50   BiDi ~ 0
GPIO21
Text GLabel 3400 5900 2    50   BiDi ~ 0
GPIO19
Text GLabel 3400 6000 2    50   BiDi ~ 0
GPIO18
Text GLabel 3400 6100 2    50   BiDi ~ 0
GPIO5
Text GLabel 3400 6200 2    50   BiDi ~ 0
GPIO17
Text GLabel 3400 6300 2    50   BiDi ~ 0
GPIO16
Text GLabel 3400 6400 2    50   BiDi ~ 0
GPIO4
Text GLabel 3400 6500 2    50   BiDi ~ 0
GPIO2
Text GLabel 3400 6600 2    50   BiDi ~ 0
GPIO15
$Comp
L power:GND #PWR?
U 1 1 60ECAFA5
P 3400 6700
F 0 "#PWR?" H 3400 6450 50  0001 C CNN
F 1 "GND" V 3405 6572 50  0000 R CNN
F 2 "" H 3400 6700 50  0001 C CNN
F 3 "" H 3400 6700 50  0001 C CNN
	1    3400 6700
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 60ECC2D9
P 3400 6800
F 0 "#PWR?" H 3400 6650 50  0001 C CNN
F 1 "+3V3" V 3415 6928 50  0000 L CNN
F 2 "" H 3400 6800 50  0001 C CNN
F 3 "" H 3400 6800 50  0001 C CNN
	1    3400 6800
	0    1    1    0   
$EndComp
NoConn ~ 2150 6800
$Comp
L power:GND #PWR?
U 1 1 60ECD4CE
P 2150 6700
F 0 "#PWR?" H 2150 6450 50  0001 C CNN
F 1 "GND" V 2155 6572 50  0000 R CNN
F 2 "" H 2150 6700 50  0001 C CNN
F 3 "" H 2150 6700 50  0001 C CNN
	1    2150 6700
	0    1    1    0   
$EndComp
Text GLabel 2150 5400 0    50   BiDi ~ 0
EN
Text GLabel 2150 5500 0    50   BiDi ~ 0
GPIO36
Text GLabel 2150 5600 0    50   BiDi ~ 0
GPIO39
Text GLabel 2150 5700 0    50   BiDi ~ 0
GPIO34
Text GLabel 2150 5800 0    50   BiDi ~ 0
GPIO35
Text GLabel 2150 5900 0    50   BiDi ~ 0
GPIO32
Text GLabel 2150 6000 0    50   BiDi ~ 0
GPIO33
Text GLabel 2150 6100 0    50   BiDi ~ 0
GPIO25
Text GLabel 2150 6200 0    50   BiDi ~ 0
GPIO26
Text GLabel 2150 6300 0    50   BiDi ~ 0
GPIO27
Text GLabel 2150 6400 0    50   BiDi ~ 0
GPIO14
Text GLabel 2150 6500 0    50   BiDi ~ 0
GPIO12
Text GLabel 2150 6600 0    50   BiDi ~ 0
GPIO13
Text GLabel 4150 5400 0    50   BiDi ~ 0
GPIO23
Text GLabel 4350 5400 2    50   BiDi ~ 0
TER_6
Wire Wire Line
	4350 5400 4150 5400
Text GLabel 4150 5500 0    50   BiDi ~ 0
GPIO22
Text GLabel 4150 5600 0    50   BiDi ~ 0
GPIO1
Text GLabel 4150 5700 0    50   BiDi ~ 0
GPIO3
Text GLabel 4150 5800 0    50   BiDi ~ 0
GPIO21
Text GLabel 4150 5900 0    50   BiDi ~ 0
GPIO19
Text GLabel 4150 6000 0    50   BiDi ~ 0
GPIO18
Text GLabel 4150 6100 0    50   BiDi ~ 0
GPIO5
Text GLabel 4150 6200 0    50   BiDi ~ 0
GPIO17
Text GLabel 4150 6300 0    50   BiDi ~ 0
GPIO16
Text GLabel 4150 6400 0    50   BiDi ~ 0
GPIO4
Text GLabel 4150 6500 0    50   BiDi ~ 0
GPIO2
Text GLabel 4150 6600 0    50   BiDi ~ 0
GPIO15
Text GLabel 4350 5500 2    50   BiDi ~ 0
SCL
Wire Wire Line
	4150 5500 4350 5500
NoConn ~ 4350 5600
NoConn ~ 4350 5700
Wire Wire Line
	4350 5700 4150 5700
Wire Wire Line
	4350 5600 4150 5600
Text Notes 2000 6850 0    50   ~ 0
VIN
Text GLabel 4350 5800 2    50   BiDi ~ 0
SDA
Wire Wire Line
	4350 5800 4150 5800
Text GLabel 4350 5900 2    50   BiDi ~ 0
TER_5
Text GLabel 4350 6000 2    50   BiDi ~ 0
TER_4
Text GLabel 4350 6200 2    50   BiDi ~ 0
TER_3
Text GLabel 4350 6300 2    50   BiDi ~ 0
TER_2
Wire Wire Line
	4150 6300 4350 6300
Wire Wire Line
	4350 6200 4150 6200
NoConn ~ 4350 6100
Wire Wire Line
	4350 6100 4150 6100
Wire Wire Line
	4150 6000 4350 6000
Wire Wire Line
	4350 5900 4150 5900
Text GLabel 4350 6400 2    50   BiDi ~ 0
TER_8
Text GLabel 4350 6500 2    50   BiDi ~ 0
TER_7
Wire Wire Line
	4350 6400 4150 6400
Wire Wire Line
	4350 6500 4150 6500
Text GLabel 4350 6600 2    50   BiDi ~ 0
GRV_5-2
Wire Wire Line
	4350 6600 4150 6600
Text GLabel 1400 5500 2    50   BiDi ~ 0
GPIO36
Text GLabel 1400 5600 2    50   BiDi ~ 0
GPIO39
Text GLabel 1400 5700 2    50   BiDi ~ 0
GPIO34
Text GLabel 1400 5800 2    50   BiDi ~ 0
GPIO35
Text GLabel 1400 5900 2    50   BiDi ~ 0
GPIO32
Text GLabel 1400 6000 2    50   BiDi ~ 0
GPIO33
Text GLabel 1400 6100 2    50   BiDi ~ 0
GPIO25
Text GLabel 1400 6200 2    50   BiDi ~ 0
GPIO26
Text GLabel 1400 6300 2    50   BiDi ~ 0
GPIO27
Text GLabel 1400 6400 2    50   BiDi ~ 0
GPIO14
Text GLabel 1400 6500 2    50   BiDi ~ 0
GPIO12
Text GLabel 1400 6600 2    50   BiDi ~ 0
GPIO13
Text GLabel 1250 5500 0    50   BiDi ~ 0
GRV_3-1
Text GLabel 1250 5600 0    50   BiDi ~ 0
GRV_3-2
Text GLabel 1250 5700 0    50   BiDi ~ 0
GRV_2-1
Text GLabel 1250 5800 0    50   BiDi ~ 0
GRV_2-2
Text GLabel 1250 5900 0    50   BiDi ~ 0
GRV_1-1
Text GLabel 1250 6000 0    50   BiDi ~ 0
GRV_1-2
Text GLabel 1250 6100 0    50   BiDi ~ 0
GRV_4-1
Text GLabel 1250 6200 0    50   BiDi ~ 0
GRV_4-2
Text GLabel 1250 6300 0    50   BiDi ~ 0
TER_9
Text GLabel 1250 6400 0    50   BiDi ~ 0
GRV_5-1
Text GLabel 1250 6600 0    50   BiDi ~ 0
TER_1
Wire Wire Line
	1250 6400 1400 6400
NoConn ~ 1250 6500
Wire Wire Line
	1250 6500 1400 6500
Wire Wire Line
	1400 6600 1250 6600
Wire Wire Line
	1250 6300 1400 6300
Wire Wire Line
	1400 6200 1250 6200
Wire Wire Line
	1250 6100 1400 6100
Wire Wire Line
	1400 6000 1250 6000
Wire Wire Line
	1250 5900 1400 5900
Wire Wire Line
	1400 5800 1250 5800
Wire Wire Line
	1250 5700 1400 5700
Wire Wire Line
	1400 5600 1250 5600
Wire Wire Line
	1250 5500 1400 5500
$EndSCHEMATC
