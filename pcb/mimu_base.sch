EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	2300 1700 2300 2200
Wire Wire Line
	10050 3900 9750 3900
Wire Wire Line
	9750 4000 10050 4000
Wire Wire Line
	9950 4100 9750 4100
Wire Wire Line
	9950 4350 9950 4100
Wire Wire Line
	9850 3650 9850 4200
Wire Wire Line
	9850 4200 9750 4200
Wire Wire Line
	4300 5300 4300 5450
Wire Wire Line
	5150 5300 4300 5300
$Comp
L power:GND #PWR010
U 1 1 5E6D3691
P 4800 5850
F 0 "#PWR010" H 4800 5600 50  0001 C CNN
F 1 "GND" H 4805 5677 50  0000 C CNN
F 2 "" H 4800 5850 50  0001 C CNN
F 3 "" H 4800 5850 50  0001 C CNN
	1    4800 5850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 5E6D3670
P 9950 4350
F 0 "#PWR014" H 9950 4100 50  0001 C CNN
F 1 "GND" H 9955 4177 50  0000 C CNN
F 2 "" H 9950 4350 50  0001 C CNN
F 3 "" H 9950 4350 50  0001 C CNN
	1    9950 4350
	1    0    0    -1  
$EndComp
Text GLabel 10050 4000 2    50   Input ~ 0
SCL
Text GLabel 10050 3900 2    50   Input ~ 0
SDA
Wire Wire Line
	7350 4150 7350 4800
Wire Wire Line
	7250 4800 7250 4150
Text GLabel 7350 4150 1    50   Input ~ 0
SCL
Text GLabel 7250 4150 1    50   Input ~ 0
SDA
Wire Wire Line
	8150 4050 7750 4050
Wire Wire Line
	7750 4150 7750 4800
Wire Wire Line
	7750 4150 8150 4150
Wire Wire Line
	7850 4250 7850 4800
Wire Wire Line
	7850 4250 8150 4250
Wire Wire Line
	7950 4350 8150 4350
$Comp
L power:GND #PWR016
U 1 1 5E6D3655
P 7750 4000
F 0 "#PWR016" H 7750 3750 50  0001 C CNN
F 1 "GND" H 7800 3850 50  0000 C CNN
F 2 "" H 7750 4000 50  0001 C CNN
F 3 "" H 7750 4000 50  0001 C CNN
	1    7750 4000
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 4800 7950 4350
$Comp
L Connector:Conn_01x05_Male J1
U 1 1 5E6D364E
P 8350 4150
F 0 "J1" H 8322 4082 50  0000 R CNN
F 1 "OPT" H 8322 4173 50  0000 R CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x05_P1.27mm_Vertical" H 8350 4150 50  0001 C CNN
F 3 "~" H 8350 4150 50  0001 C CNN
	1    8350 4150
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5E6D3648
P 4300 5850
F 0 "#PWR08" H 4300 5600 50  0001 C CNN
F 1 "GND" H 4305 5677 50  0000 C CNN
F 2 "" H 4300 5850 50  0001 C CNN
F 3 "" H 4300 5850 50  0001 C CNN
	1    4300 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5E6D3642
P 4300 5600
F 0 "C1" H 4415 5646 50  0000 L CNN
F 1 "0.1uF" H 4415 5555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4338 5450 50  0001 C CNN
F 3 "~" H 4300 5600 50  0001 C CNN
	1    4300 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 2650 2300 2400
$Comp
L power:GND #PWR06
U 1 1 5E6D3629
P 2300 2650
F 0 "#PWR06" H 2300 2400 50  0001 C CNN
F 1 "GND" H 2305 2477 50  0000 C CNN
F 2 "" H 2300 2650 50  0001 C CNN
F 3 "" H 2300 2650 50  0001 C CNN
	1    2300 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 2400 2300 2400
Wire Wire Line
	6850 4150 6850 4800
Text GLabel 6850 4150 1    50   Input ~ 0
MUTE
Wire Wire Line
	2300 1400 2300 1300
Text GLabel 2300 1300 1    50   Input ~ 0
MUTE
Text GLabel 7550 4150 1    50   Input ~ 0
BUTT
Wire Wire Line
	7050 4800 7050 4150
Text GLabel 7050 4150 1    50   Input ~ 0
LED_R
Text GLabel 2250 5100 1    50   Input ~ 0
LED_R
$Comp
L power:GND #PWR05
U 1 1 5E6D3602
P 3700 6150
F 0 "#PWR05" H 3700 5900 50  0001 C CNN
F 1 "GND" H 3705 5977 50  0000 C CNN
F 2 "" H 3700 6150 50  0001 C CNN
F 3 "" H 3700 6150 50  0001 C CNN
	1    3700 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5E6D35FC
P 9050 5400
F 0 "#PWR017" H 9050 5150 50  0001 C CNN
F 1 "GND" H 9055 5227 50  0000 C CNN
F 2 "" H 9050 5400 50  0001 C CNN
F 3 "" H 9050 5400 50  0001 C CNN
	1    9050 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 4000 6350 4000
Wire Wire Line
	5650 4100 6250 4100
Wire Wire Line
	5650 4200 6450 4200
Wire Wire Line
	5650 4300 7450 4300
$Comp
L power:GND #PWR012
U 1 1 5E6D35F2
P 5150 4650
F 0 "#PWR012" H 5150 4400 50  0001 C CNN
F 1 "GND" H 5155 4477 50  0000 C CNN
F 2 "" H 5150 4650 50  0001 C CNN
F 3 "" H 5150 4650 50  0001 C CNN
	1    5150 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4800 6450 4200
Wire Wire Line
	6350 4800 6350 4000
Wire Wire Line
	6250 4800 6250 4100
Wire Wire Line
	7450 4300 7450 4800
Wire Wire Line
	8750 5400 9050 5400
Wire Wire Line
	5150 3700 5150 3600
Wire Wire Line
	5150 4650 5150 4600
$Comp
L Connector:AVR-ISP-6 ISP1
U 1 1 5E6D35CC
P 5250 4200
F 0 "ISP1" H 4921 4296 50  0000 R CNN
F 1 "AVR-ISP-6" H 4921 4205 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" V 5000 4250 50  0001 C CNN
F 3 " ~" H 3975 3650 50  0001 C CNN
	1    5250 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 1050 3200 1050
Wire Wire Line
	3500 1350 3500 1450
Wire Wire Line
	3850 1050 3800 1050
$Comp
L Connector:XLR3 INPUT1
U 1 1 5E6D35BD
P 3500 1050
F 0 "INPUT1" H 3500 1300 50  0000 C CNN
F 1 "XLR3" H 3700 800 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3500 1050 50  0001 C CNN
F 3 "" H 3500 1050 50  0001 C CNN
	1    3500 1050
	1    0    0    -1  
$EndComp
$Comp
L mimu_phantom-rescue:H11F1M-custom U1
U 1 1 5E6D35B7
P 2650 2300
F 0 "U1" H 2700 2650 50  0000 L CNN
F 1 "AQY211EH" H 2700 2550 50  0000 L CNN
F 2 "custom:DIP-4_bubble_W7.62mm" H 2600 2300 50  0001 C CNN
F 3 "doc/semi_eng_ge1a_aqy21_e.pdf" H 2600 2300 50  0001 C CNN
	1    2650 2300
	1    0    0    -1  
$EndComp
$Comp
L mimu_phantom-rescue:Conn_TOF_flipped-custom SENS1
U 1 1 5E6D35B1
P 9550 4100
AR Path="/5E6D35B1" Ref="SENS1"  Part="1" 
AR Path="/5E6CC751/5E6D35B1" Ref="SENS1"  Part="1" 
F 0 "SENS1" H 9468 3675 50  0000 C CNN
F 1 "Sens" H 9468 3766 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9550 4100 50  0001 C CNN
F 3 "~" H 9550 4100 50  0001 C CNN
	1    9550 4100
	-1   0    0    1   
$EndComp
Wire Wire Line
	2300 2200 2350 2200
$Comp
L mimu_phantom-rescue:R-mimu3000-rescue-mimu_phantom-rescue R2
U 1 1 5E6D35AA
P 2300 1550
F 0 "R2" V 2380 1550 50  0000 C CNN
F 1 "1k" V 2200 1550 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 2230 1550 50  0001 C CNN
F 3 "" H 2300 1550 50  0001 C CNN
	1    2300 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5E6D368A
P 4800 5600
F 0 "C2" H 4915 5646 50  0000 L CNN
F 1 "0.1uF" H 4915 5555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4838 5450 50  0001 C CNN
F 3 "~" H 4800 5600 50  0001 C CNN
	1    4800 5600
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0105
U 1 1 5E6DBFFF
P 4800 5150
F 0 "#PWR0105" H 4800 5000 50  0001 C CNN
F 1 "VCC" H 4817 5323 50  0000 C CNN
F 2 "" H 4800 5150 50  0001 C CNN
F 3 "" H 4800 5150 50  0001 C CNN
	1    4800 5150
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0106
U 1 1 5E6DC40D
P 9850 3650
F 0 "#PWR0106" H 9850 3500 50  0001 C CNN
F 1 "VCC" H 9867 3823 50  0000 C CNN
F 2 "" H 9850 3650 50  0001 C CNN
F 3 "" H 9850 3650 50  0001 C CNN
	1    9850 3650
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATtiny:ATtiny48-AU U2
U 1 1 5E6D369E
P 6950 5400
F 0 "U2" V 6900 5900 50  0000 C CNN
F 1 "ATTINY88AU" H 6950 5400 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 7550 5400 50  0001 C CIN
F 3 "../doc/ATtiny4888" H 6150 5750 50  0001 C CNN
	1    6950 5400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4800 5150 4800 5400
Wire Wire Line
	5150 5400 4800 5400
Connection ~ 4800 5400
Wire Wire Line
	4800 5400 4800 5450
Wire Wire Line
	4300 5850 4300 5750
Wire Wire Line
	4800 5850 4800 5750
$Comp
L power:VCC #PWR018
U 1 1 5E6BC5B9
P 7850 3900
F 0 "#PWR018" H 7850 3750 50  0001 C CNN
F 1 "VCC" H 7867 4073 50  0000 C CNN
F 2 "" H 7850 3900 50  0001 C CNN
F 3 "" H 7850 3900 50  0001 C CNN
	1    7850 3900
	1    0    0    -1  
$EndComp
Text GLabel 4000 1450 2    50   Input ~ 0
XLR_HOT
Text GLabel 3200 1450 0    50   Input ~ 0
XLR_COLD
Text GLabel 3150 1050 0    50   Input ~ 0
XLR_GND
Text Notes 2000 5400 2    50   ~ 0
(4,5V-1.3V)/8mA = 400R\n(  3V-1.3V)/8mA = 333R
Text Notes 1200 1650 0    50   ~ 0
(4,5V-1,5V)/3mA = 1k\n(  3V-1,5V)/3mA = 500R
Text Notes 2350 2300 2    50   ~ 0
I_Fon = 1.2mA-3mA
Wire Wire Line
	2900 2400 3850 2400
Text GLabel 2450 5100 1    50   Input ~ 0
LED_G
$Comp
L Device:LED_Dual_ACA D2
U 1 1 616E1DAD
P 2350 5800
F 0 "D2" V 2396 5590 50  0000 R CNN
F 1 "LED_Dual_ACA" V 2305 5590 50  0000 R CNN
F 2 "LED_THT:LED_Rectangular_W5.0mm_H2.0mm-3Pins" H 2350 5800 50  0001 C CNN
F 3 "~" H 2350 5800 50  0001 C CNN
	1    2350 5800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR01
U 1 1 616E2973
P 2350 6200
F 0 "#PWR01" H 2350 5950 50  0001 C CNN
F 1 "GND" H 2355 6027 50  0000 C CNN
F 2 "" H 2350 6200 50  0001 C CNN
F 3 "" H 2350 6200 50  0001 C CNN
	1    2350 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 6200 2350 6100
$Comp
L Device:R R1
U 1 1 616E5D77
P 2250 5350
F 0 "R1" H 2100 5400 50  0000 L CNN
F 1 "390R" H 2000 5300 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" V 2180 5350 50  0001 C CNN
F 3 "~" H 2250 5350 50  0001 C CNN
	1    2250 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 616E6236
P 2450 5350
F 0 "R5" H 2520 5396 50  0000 L CNN
F 1 "390R" H 2520 5305 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" V 2380 5350 50  0001 C CNN
F 3 "~" H 2450 5350 50  0001 C CNN
	1    2450 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 5200 2450 5100
Wire Wire Line
	3700 5800 3700 5900
Text GLabel 7150 4150 1    50   Input ~ 0
LED_G
Wire Wire Line
	7150 4800 7150 4150
Text GLabel 3150 4200 0    50   Input ~ 0
ATT
Wire Wire Line
	7550 4800 7550 4150
Wire Wire Line
	7850 3900 7850 3950
Wire Wire Line
	7850 3950 8150 3950
Wire Wire Line
	7750 4050 7750 4000
Text GLabel 5850 2400 2    50   Input ~ 0
ATT
Wire Wire Line
	3850 1050 3850 1450
Wire Wire Line
	3500 1450 3200 1450
Wire Wire Line
	3850 1450 4000 1450
Connection ~ 3850 1450
Wire Wire Line
	3850 1450 3850 2400
$Comp
L mimu_phantom-rescue:H11F1M U4
U 1 1 617224A8
P 4850 2300
F 0 "U4" H 4825 1933 50  0000 C CNN
F 1 "H11F1M" H 4825 2024 50  0000 C CNN
F 2 "Package_DIP:DIP-6_W7.62mm" H 4800 2300 50  0001 C CNN
F 3 "https://www.electrokit.com/uploads/productfile/41014/0900766b812cfb59.pdf" H 4800 2300 50  0001 C CNN
	1    4850 2300
	-1   0    0    1   
$EndComp
Wire Wire Line
	3850 2400 4600 2400
Connection ~ 3850 2400
$Comp
L power:GND #PWR02
U 1 1 617263B7
P 5250 2000
F 0 "#PWR02" H 5250 1750 50  0001 C CNN
F 1 "GND" H 5255 1827 50  0000 C CNN
F 2 "" H 5250 2000 50  0001 C CNN
F 3 "" H 5250 2000 50  0001 C CNN
	1    5250 2000
	-1   0    0    1   
$EndComp
Wire Wire Line
	5250 2000 5250 2200
Wire Wire Line
	5250 2200 5150 2200
Wire Wire Line
	5150 2400 5350 2400
Text Notes 6200 2100 0    50   ~ 0
(4,5V-1,5V)/30mA = 100R\n(  3V-1,5V)/30mA = 50R
$Comp
L mimu_phantom-rescue:R-mimu3000-rescue-mimu_phantom-rescue R6
U 1 1 6173EC5F
P 5500 2400
F 0 "R6" V 5580 2400 50  0000 C CNN
F 1 "100R" V 5400 2400 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" V 5430 2400 50  0001 C CNN
F 3 "" H 5500 2400 50  0001 C CNN
	1    5500 2400
	0    1    1    0   
$EndComp
Wire Wire Line
	5650 2400 5850 2400
Connection ~ 3500 1450
Wire Wire Line
	3500 1450 3500 2200
Wire Wire Line
	4600 2200 3500 2200
Wire Wire Line
	2900 2200 3500 2200
Connection ~ 3500 2200
$Comp
L Switch:SW_MEC_5E SW1
U 1 1 616F2647
P 3700 5600
F 0 "SW1" V 3654 5748 50  0000 L CNN
F 1 "SW_Push" V 3745 5748 50  0000 L CNN
F 2 "digikey:Switch_Tactile_SMD_6x6mm_PTS645" H 3700 5800 50  0001 C CNN
F 3 "https://www.digikey.de/product-detail/en/schurter-inc/1301-9314-24/486-4184-2-ND/8536716" H 3700 5800 50  0001 C CNN
	1    3700 5600
	0    1    1    0   
$EndComp
Text GLabel 3700 5200 1    50   Input ~ 0
BUTT
$Comp
L mimu_phantom-rescue:R-mimu3000-rescue-mimu_phantom-rescue R7
U 1 1 616ECC8F
P 3300 5100
F 0 "R7" V 3380 5100 50  0000 C CNN
F 1 "1k" V 3200 5100 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" V 3230 5100 50  0001 C CNN
F 3 "" H 3300 5100 50  0001 C CNN
	1    3300 5100
	-1   0    0    1   
$EndComp
Wire Wire Line
	3700 5200 3700 5300
Wire Wire Line
	3700 5300 3300 5300
Wire Wire Line
	3300 5300 3300 5250
Connection ~ 3700 5300
Wire Wire Line
	3700 5300 3700 5400
Connection ~ 4300 5300
$Comp
L power:VCC #PWR0104
U 1 1 5E6DBBD0
P 4300 5150
F 0 "#PWR0104" H 4300 5000 50  0001 C CNN
F 1 "VCC" H 4317 5323 50  0000 C CNN
F 2 "" H 4300 5150 50  0001 C CNN
F 3 "" H 4300 5150 50  0001 C CNN
	1    4300 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5150 4300 5300
$Comp
L power:VCC #PWR0108
U 1 1 61706AB2
P 3300 4950
F 0 "#PWR0108" H 3300 4800 50  0001 C CNN
F 1 "VCC" H 3317 5123 50  0000 C CNN
F 2 "" H 3300 4950 50  0001 C CNN
F 3 "" H 3300 4950 50  0001 C CNN
	1    3300 4950
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0109
U 1 1 61719CE4
P 5150 3600
F 0 "#PWR0109" H 5150 3450 50  0001 C CNN
F 1 "VCC" H 5167 3773 50  0000 C CNN
F 2 "" H 5150 3600 50  0001 C CNN
F 3 "" H 5150 3600 50  0001 C CNN
	1    5150 3600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPDT SW2
U 1 1 616EBE4E
P 3650 4200
F 0 "SW2" H 3650 4485 50  0000 C CNN
F 1 "SW_SPDT" H 3650 4394 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm_NumberLabels" H 3650 4200 50  0001 C CNN
F 3 "~" H 3650 4200 50  0001 C CNN
	1    3650 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 4200 3450 4200
Text GLabel 6050 4650 1    50   Input ~ 0
OC1A
Text GLabel 6150 4650 1    50   Input ~ 0
OC1B
Text GLabel 4000 4100 2    50   Input ~ 0
OC1A
Text GLabel 4000 4300 2    50   Input ~ 0
OC1B
Wire Wire Line
	3850 4100 4000 4100
Wire Wire Line
	4000 4300 3850 4300
Wire Wire Line
	6150 4800 6150 4650
Wire Wire Line
	6050 4650 6050 4800
NoConn ~ 8450 4800
NoConn ~ 8350 4800
NoConn ~ 8250 4800
NoConn ~ 8150 4800
NoConn ~ 8050 4800
NoConn ~ 6950 4800
NoConn ~ 6550 4800
NoConn ~ 6650 4800
NoConn ~ 5950 4800
NoConn ~ 5750 4800
NoConn ~ 5650 4800
NoConn ~ 5550 4800
NoConn ~ 5450 4800
Wire Wire Line
	3700 5300 3800 5300
Wire Wire Line
	3800 5300 3800 5400
Wire Wire Line
	3800 5800 3800 5900
Wire Wire Line
	3800 5900 3700 5900
Connection ~ 3700 5900
Wire Wire Line
	3700 5900 3700 6150
Wire Wire Line
	2250 5100 2250 5200
$EndSCHEMATC
