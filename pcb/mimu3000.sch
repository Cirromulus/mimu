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
L MCU_Microchip_ATtiny:ATtiny48-AU U2
U 1 1 5E29D77C
P 4900 5400
F 0 "U2" V 4850 5900 50  0000 C CNN
F 1 "ATTINY48U" H 4900 5400 50  0000 C CNN
F 2 "Housings_QFP:TQFP-32_7x7mm_Pitch0.8mm" H 5500 5400 50  0001 C CIN
F 3 "" H 4100 5750 50  0001 C CNN
	1    4900 5400
	0    -1   -1   0   
$EndComp
$Comp
L mimu3000-rescue:R R1
U 1 1 5E29E9BB
P 7700 3150
F 0 "R1" V 7780 3150 50  0000 C CNN
F 1 "580R" V 7700 3150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7630 3150 50  0001 C CNN
F 3 "" H 7700 3150 50  0001 C CNN
	1    7700 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 5E2AE194
P 7700 3450
F 0 "C1" H 7818 3496 50  0000 L CNN
F 1 "47µ" H 7818 3405 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 7738 3300 50  0001 C CNN
F 3 "~" H 7700 3450 50  0001 C CNN
	1    7700 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 3600 7700 3800
Wire Wire Line
	7700 3800 7750 3800
$Comp
L Device:Battery BT1
U 1 1 5E2BAE3F
P 1000 3450
F 0 "BT1" H 1108 3496 50  0000 L CNN
F 1 "3V" H 1108 3405 50  0000 L CNN
F 2 "Battery_Holders:Keystone_2468_2xAAA" V 1000 3510 50  0001 C CNN
F 3 "~" V 1000 3510 50  0001 C CNN
	1    1000 3450
	1    0    0    -1  
$EndComp
$Comp
L custom:Conn_TOF SENS1
U 1 1 5E2CBB84
P 4300 3500
F 0 "SENS1" H 4218 3075 50  0000 C CNN
F 1 "Sens" H 4218 3166 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 4300 3500 50  0001 C CNN
F 3 "~" H 4300 3500 50  0001 C CNN
	1    4300 3500
	-1   0    0    1   
$EndComp
Wire Wire Line
	4500 3500 4600 3500
Wire Wire Line
	4600 3500 4600 3750
$Comp
L custom:H11F1M U1
U 1 1 5E2A0546
P 8050 3900
F 0 "U1" H 8100 4250 50  0000 L CNN
F 1 "AQY211EH" H 8100 4150 50  0000 L CNN
F 2 "Package_DIP:DIP-4_W7.62mm" H 8000 3900 50  0001 C CNN
F 3 "doc/semi_eng_ge1a_aqy21_e.pdf" H 8000 3900 50  0001 C CNN
	1    8050 3900
	1    0    0    -1  
$EndComp
$Comp
L Connector:XLR3 INPUT1
U 1 1 5E29E533
P 8900 2650
F 0 "INPUT1" H 8900 2900 50  0000 C CNN
F 1 "XLR3" H 9100 2400 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8900 2650 50  0001 C CNN
F 3 "" H 8900 2650 50  0001 C CNN
	1    8900 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 2650 9200 2650
Wire Wire Line
	8900 2950 8900 3050
Wire Wire Line
	8550 2650 8600 2650
$Comp
L Device:R_POT RV1
U 1 1 5E2BA12E
P 1650 5800
F 0 "RV1" H 1581 5846 50  0000 R CNN
F 1 "R_POT" H 1581 5755 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Alps_RK09Y11_Single_Horizontal" H 1650 5800 50  0001 C CNN
F 3 "~" H 1650 5800 50  0001 C CNN
	1    1650 5800
	1    0    0    -1  
$EndComp
$Comp
L Connector:AVR-ISP-6 ISP1
U 1 1 5E2B28C5
P 2550 4400
F 0 "ISP1" H 2221 4496 50  0000 R CNN
F 1 "AVR-ISP-6" H 2221 4405 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" V 2300 4450 50  0001 C CNN
F 3 " ~" H 1275 3850 50  0001 C CNN
	1    2550 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 4850 2450 4800
Wire Wire Line
	2450 3900 2450 3800
Wire Wire Line
	1650 5650 1650 5200
Wire Wire Line
	6700 5400 7050 5400
Wire Wire Line
	3100 5400 2850 5400
Wire Wire Line
	2850 5300 2850 5400
Wire Wire Line
	2850 5300 3100 5300
Wire Wire Line
	5400 4500 5400 4800
Wire Wire Line
	4200 4800 4200 4300
Wire Wire Line
	4300 4800 4300 4200
Wire Wire Line
	4400 4800 4400 4400
Wire Wire Line
	5200 4800 5200 3300
Wire Wire Line
	4500 3300 5200 3300
Wire Wire Line
	5300 3400 5300 4800
Wire Wire Line
	4500 3400 5300 3400
$Comp
L power:+3V0 #PWR01
U 1 1 5E41CB28
P 1000 2750
F 0 "#PWR01" H 1000 2600 50  0001 C CNN
F 1 "+3V0" H 1015 2923 50  0000 C CNN
F 2 "" H 1000 2750 50  0001 C CNN
F 3 "" H 1000 2750 50  0001 C CNN
	1    1000 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5E41D9E2
P 1000 3700
F 0 "#PWR03" H 1000 3450 50  0001 C CNN
F 1 "GND" H 1005 3527 50  0000 C CNN
F 2 "" H 1000 3700 50  0001 C CNN
F 3 "" H 1000 3700 50  0001 C CNN
	1    1000 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+3V0 #PWR05
U 1 1 5E4210BA
P 2450 3800
F 0 "#PWR05" H 2450 3650 50  0001 C CNN
F 1 "+3V0" H 2465 3973 50  0000 C CNN
F 2 "" H 2450 3800 50  0001 C CNN
F 3 "" H 2450 3800 50  0001 C CNN
	1    2450 3800
	1    0    0    -1  
$EndComp
$Comp
L power:+3V0 #PWR09
U 1 1 5E4218B0
P 2850 5300
F 0 "#PWR09" H 2850 5150 50  0001 C CNN
F 1 "+3V0" H 2865 5473 50  0000 C CNN
F 2 "" H 2850 5300 50  0001 C CNN
F 3 "" H 2850 5300 50  0001 C CNN
	1    2850 5300
	1    0    0    -1  
$EndComp
Connection ~ 2850 5300
$Comp
L power:+3V0 #PWR08
U 1 1 5E4223E1
P 1650 5200
F 0 "#PWR08" H 1650 5050 50  0001 C CNN
F 1 "+3V0" H 1665 5373 50  0000 C CNN
F 2 "" H 1650 5200 50  0001 C CNN
F 3 "" H 1650 5200 50  0001 C CNN
	1    1650 5200
	1    0    0    -1  
$EndComp
$Comp
L power:+3V0 #PWR02
U 1 1 5E422BFE
P 4700 3100
F 0 "#PWR02" H 4700 2950 50  0001 C CNN
F 1 "+3V0" H 4715 3273 50  0000 C CNN
F 2 "" H 4700 3100 50  0001 C CNN
F 3 "" H 4700 3100 50  0001 C CNN
	1    4700 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5E423825
P 2450 4850
F 0 "#PWR07" H 2450 4600 50  0001 C CNN
F 1 "GND" H 2455 4677 50  0000 C CNN
F 2 "" H 2450 4850 50  0001 C CNN
F 3 "" H 2450 4850 50  0001 C CNN
	1    2450 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 4500 5400 4500
Wire Wire Line
	2950 4400 4400 4400
Wire Wire Line
	2950 4300 4200 4300
Wire Wire Line
	2950 4200 4300 4200
$Comp
L power:GND #PWR010
U 1 1 5E4346AD
P 7050 5400
F 0 "#PWR010" H 7050 5150 50  0001 C CNN
F 1 "GND" H 7055 5227 50  0000 C CNN
F 2 "" H 7050 5400 50  0001 C CNN
F 3 "" H 7050 5400 50  0001 C CNN
	1    7050 5400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5E434B19
P 1650 6350
F 0 "#PWR012" H 1650 6100 50  0001 C CNN
F 1 "GND" H 1655 6177 50  0000 C CNN
F 2 "" H 1650 6350 50  0001 C CNN
F 3 "" H 1650 6350 50  0001 C CNN
	1    1650 6350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5E434EA3
P 4600 3750
F 0 "#PWR04" H 4600 3500 50  0001 C CNN
F 1 "GND" H 4605 3577 50  0000 C CNN
F 2 "" H 4600 3750 50  0001 C CNN
F 3 "" H 4600 3750 50  0001 C CNN
	1    4600 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3100 4700 3600
Wire Wire Line
	4500 3600 4700 3600
$Comp
L power:GND #PWR011
U 1 1 5E4388C2
P 900 6350
F 0 "#PWR011" H 900 6100 50  0001 C CNN
F 1 "GND" H 905 6177 50  0000 C CNN
F 2 "" H 900 6350 50  0001 C CNN
F 3 "" H 900 6350 50  0001 C CNN
	1    900  6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  5150 900  5500
$Comp
L Device:R R2
U 1 1 5E2D7AE9
P 900 5650
F 0 "R2" H 970 5696 50  0000 L CNN
F 1 "90R" H 970 5605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 830 5650 50  0001 C CNN
F 3 "~" H 900 5650 50  0001 C CNN
	1    900  5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  6100 900  6350
$Comp
L Device:LED D1
U 1 1 5E2C9905
P 900 5950
F 0 "D1" V 800 6100 50  0000 R CNN
F 1 "LED" V 700 6100 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 900 5950 50  0001 C CNN
F 3 "~" H 900 5950 50  0001 C CNN
	1    900  5950
	0    -1   -1   0   
$EndComp
Text GLabel 900  5150 1    50   Input ~ 0
LED
Text GLabel 5000 4350 1    50   Input ~ 0
LED
Wire Wire Line
	5000 4800 5000 4350
Wire Wire Line
	1650 5950 1650 6350
Text GLabel 2050 5800 2    50   Input ~ 0
POT
Wire Wire Line
	2050 5800 1800 5800
Text GLabel 4900 4350 1    50   Input ~ 0
POT
Wire Wire Line
	4900 4800 4900 4350
Text GLabel 7700 2900 1    50   Input ~ 0
MUTE
Wire Wire Line
	7700 3000 7700 2900
Text GLabel 4800 4350 1    50   Input ~ 0
MUTE
Wire Wire Line
	4800 4350 4800 4800
Wire Wire Line
	7750 4000 7700 4000
$Comp
L power:GND #PWR06
U 1 1 5E443817
P 7700 4250
F 0 "#PWR06" H 7700 4000 50  0001 C CNN
F 1 "GND" H 7705 4077 50  0000 C CNN
F 2 "" H 7700 4250 50  0001 C CNN
F 3 "" H 7700 4250 50  0001 C CNN
	1    7700 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 4250 7700 4000
$Comp
L Connector:XLR3 OUTPUT1
U 1 1 5E29E552
P 8900 3450
F 0 "OUTPUT1" H 8900 3700 50  0000 C CNN
F 1 "XLR3" H 9100 3200 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8900 3450 50  0001 C CNN
F 3 "" H 8900 3450 50  0001 C CNN
	1    8900 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 3050 9400 3050
Wire Wire Line
	8550 2650 8550 3450
Wire Wire Line
	9250 2650 9250 3450
Wire Wire Line
	8600 3450 8550 3450
Wire Wire Line
	9200 3450 9250 3450
Connection ~ 9250 3450
Wire Wire Line
	9250 3450 9250 4000
Wire Wire Line
	8900 3750 9400 3750
Wire Wire Line
	9400 3750 9400 3050
Wire Wire Line
	1000 3700 1000 3650
Wire Wire Line
	1000 3250 1000 3200
Wire Wire Line
	1000 2800 1000 2750
$Comp
L Switch:SW_DPST_x2 SW1
U 1 1 5E4634A0
P 1000 3000
F 0 "SW1" V 954 3098 50  0000 L CNN
F 1 "ONOFF" V 1045 3098 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 1000 3000 50  0001 C CNN
F 3 "~" H 1000 3000 50  0001 C CNN
	1    1000 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	8900 3800 8900 3750
Wire Wire Line
	8300 3800 8900 3800
Connection ~ 8900 3750
Wire Wire Line
	8300 4000 9250 4000
$EndSCHEMATC