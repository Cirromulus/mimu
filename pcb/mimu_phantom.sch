EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 6100 2000 3800 1600
U 5E6CC751
F0 "Mimu_base" 50
F1 "mimu_base.sch" 50
$EndSheet
$Comp
L Regulator_Switching:MCP16331CH U3
U 1 1 5E6A462C
P 2500 2950
F 0 "U3" H 2500 3317 50  0000 C CNN
F 1 "MCP16331CH" H 2500 3226 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 2550 2700 50  0001 L CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20005308C.pdf" H 1300 3600 50  0001 C CNN
	1    2500 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C_IN1
U 1 1 5E6A4EB3
P 1100 3000
F 0 "C_IN1" H 1215 3046 50  0000 L CNN
F 1 "10uF" H 1215 2955 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1138 2850 50  0001 C CNN
F 3 "~" H 1100 3000 50  0001 C CNN
	1    1100 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C_IN2
U 1 1 5E6A593E
P 1550 3000
F 0 "C_IN2" H 1665 3046 50  0000 L CNN
F 1 "10uF" H 1665 2955 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1588 2850 50  0001 C CNN
F 3 "~" H 1550 3000 50  0001 C CNN
	1    1550 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C_B1
U 1 1 5E6A72EB
P 3100 2700
F 0 "C_B1" H 3215 2746 50  0000 L CNN
F 1 "100nF" H 3215 2655 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3138 2550 50  0001 C CNN
F 3 "~" H 3100 2700 50  0001 C CNN
	1    3100 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:D D_B1
U 1 1 5E6A7F82
P 3750 2550
F 0 "D_B1" H 3750 2766 50  0000 C CNN
F 1 "1N4148" H 3750 2675 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323_HandSoldering" H 3750 2550 50  0001 C CNN
F 3 "~" H 3750 2550 50  0001 C CNN
	1    3750 2550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5E6A8BB6
P 1100 3300
F 0 "#PWR03" H 1100 3050 50  0001 C CNN
F 1 "GND" H 1105 3127 50  0000 C CNN
F 2 "" H 1100 3300 50  0001 C CNN
F 3 "" H 1100 3300 50  0001 C CNN
	1    1100 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R_TOP1
U 1 1 5E6AF9AF
P 4750 3500
F 0 "R_TOP1" H 4820 3546 50  0000 L CNN
F 1 "31.2k" H 4820 3455 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 4680 3500 50  0001 C CNN
F 3 "~" H 4750 3500 50  0001 C CNN
	1    4750 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R_BOT1
U 1 1 5E6AFD6D
P 4750 3950
F 0 "R_BOT1" H 4820 3996 50  0000 L CNN
F 1 "10k" H 4820 3905 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 4680 3950 50  0001 C CNN
F 3 "~" H 4750 3950 50  0001 C CNN
	1    4750 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  2850 1100 2850
Wire Wire Line
	1550 2850 1100 2850
Connection ~ 1100 2850
Wire Wire Line
	1100 3150 1550 3150
Connection ~ 1100 3150
Wire Wire Line
	1100 3150 1100 3300
Connection ~ 1550 2850
$Comp
L power:GND #PWR04
U 1 1 5E6B5136
P 2500 3350
F 0 "#PWR04" H 2500 3100 50  0001 C CNN
F 1 "GND" H 2505 3177 50  0000 C CNN
F 2 "" H 2500 3350 50  0001 C CNN
F 3 "" H 2500 3350 50  0001 C CNN
	1    2500 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 3350 2500 3250
Wire Wire Line
	4750 3800 4750 3700
Wire Wire Line
	4750 3700 2950 3700
Wire Wire Line
	2950 3700 2950 3050
Wire Wire Line
	2950 3050 2900 3050
Connection ~ 4750 3700
Wire Wire Line
	4750 3700 4750 3650
Wire Wire Line
	3100 2950 3100 3050
Wire Wire Line
	3200 2950 3100 2950
Connection ~ 3700 2950
Wire Wire Line
	3500 2950 3700 2950
Wire Wire Line
	4000 3250 4250 3250
Connection ~ 4000 3250
Wire Wire Line
	4000 3300 4000 3250
$Comp
L power:GND #PWR09
U 1 1 5E6B64D1
P 4000 3300
F 0 "#PWR09" H 4000 3050 50  0001 C CNN
F 1 "GND" H 4005 3127 50  0000 C CNN
F 2 "" H 4000 3300 50  0001 C CNN
F 3 "" H 4000 3300 50  0001 C CNN
	1    4000 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 3250 4000 3250
Connection ~ 4250 2950
Wire Wire Line
	4250 2950 4000 2950
$Comp
L Device:L L1
U 1 1 5E6AD4A9
P 3350 2950
F 0 "L1" V 3450 2950 50  0000 C CNN
F 1 "15uH" V 3260 2950 50  0000 C CNN
F 2 "Inductors_SMD:L_7.3x7.3_H4.5" H 3350 2950 50  0001 C CNN
F 3 "Würth 7447779115" H 3350 2950 50  0001 C CNN
	1    3350 2950
	0    1    1    0   
$EndComp
$Comp
L Device:D_Schottky D1
U 1 1 5E6ACB46
P 3100 3200
F 0 "D1" V 3054 3279 50  0000 L CNN
F 1 "B1100" V 3145 3279 50  0000 L CNN
F 2 "Diodes_SMD:D_SMA" H 3100 3200 50  0001 C CNN
F 3 "~" H 3100 3200 50  0001 C CNN
	1    3100 3200
	0    1    1    0   
$EndComp
$Comp
L Device:C C_out2
U 1 1 5E6A68AC
P 4250 3100
F 0 "C_out2" H 4365 3146 50  0000 L CNN
F 1 "10uF" H 4365 3055 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 4288 2950 50  0001 C CNN
F 3 "~" H 4250 3100 50  0001 C CNN
	1    4250 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C_out1
U 1 1 5E6A672D
P 3700 3100
F 0 "C_out1" H 3815 3146 50  0000 L CNN
F 1 "10uF" H 3815 3055 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3738 2950 50  0001 C CNN
F 3 "~" H 3700 3100 50  0001 C CNN
	1    3700 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2950 3100 2950
Connection ~ 3100 2950
Wire Wire Line
	2900 2850 2950 2850
Wire Wire Line
	2950 2550 3100 2550
Wire Wire Line
	2950 2550 2950 2850
Wire Wire Line
	3100 2950 3100 2850
Wire Wire Line
	3900 2550 4000 2550
Wire Wire Line
	4000 2550 4000 2950
Connection ~ 4000 2950
Wire Wire Line
	4000 2950 3700 2950
Wire Wire Line
	3600 2550 3100 2550
Connection ~ 3100 2550
$Comp
L power:GND #PWR07
U 1 1 5E6CD10F
P 3100 3350
F 0 "#PWR07" H 3100 3100 50  0001 C CNN
F 1 "GND" H 3105 3177 50  0000 C CNN
F 2 "" H 3100 3350 50  0001 C CNN
F 3 "" H 3100 3350 50  0001 C CNN
	1    3100 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5E6CD38C
P 4750 4150
F 0 "#PWR013" H 4750 3900 50  0001 C CNN
F 1 "GND" H 4755 3977 50  0000 C CNN
F 2 "" H 4750 4150 50  0001 C CNN
F 3 "" H 4750 4150 50  0001 C CNN
	1    4750 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4150 4750 4100
$Comp
L power:VCC #PWR015
U 1 1 5E6A55A0
P 4850 2950
F 0 "#PWR015" H 4850 2800 50  0001 C CNN
F 1 "VCC" V 4868 3077 50  0000 L CNN
F 2 "" H 4850 2950 50  0001 C CNN
F 3 "" H 4850 2950 50  0001 C CNN
	1    4850 2950
	0    1    1    0   
$EndComp
Text GLabel 2150 1050 1    50   Input ~ 0
XLR_HOT
Text GLabel 2400 1050 1    50   Input ~ 0
XLR_COLD
Text GLabel 2650 1050 1    50   Input ~ 0
XLR_GND
$Comp
L power:+BATT #PWR0101
U 1 1 5E6CDE97
P 850 2800
F 0 "#PWR0101" H 850 2650 50  0001 C CNN
F 1 "+BATT" H 865 2973 50  0000 C CNN
F 2 "" H 850 2800 50  0001 C CNN
F 3 "" H 850 2800 50  0001 C CNN
	1    850  2800
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0102
U 1 1 5E6CE2D2
P 1200 1800
F 0 "#PWR0102" H 1200 1650 50  0001 C CNN
F 1 "+BATT" V 1215 1927 50  0000 L CNN
F 2 "" H 1200 1800 50  0001 C CNN
F 3 "" H 1200 1800 50  0001 C CNN
	1    1200 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	850  2850 850  2800
$Comp
L Device:R R3
U 1 1 5E6CFBA0
P 2150 1350
F 0 "R3" H 2000 1400 50  0000 L CNN
F 1 "6.8Ohm 0.1%" H 1600 1300 50  0000 L CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2080 1350 50  0001 C CNN
F 3 "e.g. KOA Speer RS73 High-Precision Flat Chip Resistors" H 2150 1350 50  0001 C CNN
	1    2150 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5E6D0E42
P 2400 1350
F 0 "R4" H 2470 1396 50  0000 L CNN
F 1 "6.8Ohm 0.1%" H 2470 1305 50  0000 L CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2330 1350 50  0001 C CNN
F 3 "e.g. KOA Speer RS73 High-Precision Flat Chip Resistors" H 2400 1350 50  0001 C CNN
	1    2400 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 1200 2400 1050
Wire Wire Line
	2150 1050 2150 1200
Wire Wire Line
	2150 1500 2150 1650
Wire Wire Line
	2150 1650 2300 1650
Wire Wire Line
	2400 1650 2400 1500
Wire Wire Line
	2300 1650 2300 1800
Connection ~ 2300 1650
Wire Wire Line
	2300 1650 2400 1650
$Comp
L power:GND #PWR0107
U 1 1 5E6DA84C
P 2650 1650
F 0 "#PWR0107" H 2650 1400 50  0001 C CNN
F 1 "GND" H 2655 1477 50  0000 C CNN
F 2 "" H 2650 1650 50  0001 C CNN
F 3 "" H 2650 1650 50  0001 C CNN
	1    2650 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 1650 2650 1050
Wire Wire Line
	4250 2950 4750 2950
Wire Wire Line
	4750 2950 4750 3350
Connection ~ 4750 2950
Wire Wire Line
	4750 2950 4850 2950
$Comp
L Connector:TestPoint TP1
U 1 1 5E6D2D69
P 2300 1800
F 0 "TP1" H 2242 1826 50  0000 R CNN
F 1 "TestPoint" H 2242 1917 50  0000 R CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 2500 1800 50  0001 C CNN
F 3 "~" H 2500 1800 50  0001 C CNN
	1    2300 1800
	-1   0    0    1   
$EndComp
$Comp
L Connector:TestPoint TP4
U 1 1 5E6D362C
P 2950 3700
F 0 "TP4" V 2750 3850 50  0000 C CNN
F 1 "TestPoint" V 2850 3750 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 3150 3700 50  0001 C CNN
F 3 "~" H 3150 3700 50  0001 C CNN
	1    2950 3700
	0    -1   -1   0   
$EndComp
Connection ~ 2950 3700
$Comp
L Connector:TestPoint TP3
U 1 1 5E6D91F6
P 4750 2950
F 0 "TP3" H 4700 3150 50  0000 L CNN
F 1 "TestPoint" H 4700 3250 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 4950 2950 50  0001 C CNN
F 3 "~" H 4950 2950 50  0001 C CNN
	1    4750 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 2850 2100 2850
$Comp
L Device:CP C5
U 1 1 5E71F447
P 1300 1950
F 0 "C5" H 1418 1996 50  0000 L CNN
F 1 "0.1uF" H 1418 1905 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D4.0mm_P2.00mm" H 1338 1800 50  0001 C CNN
F 3 "~" H 1300 1950 50  0001 C CNN
	1    1300 1950
	1    0    0    -1  
$EndComp
Connection ~ 1300 1800
Wire Wire Line
	1300 1800 1200 1800
$Comp
L power:GND #PWR0108
U 1 1 5E71FAE9
P 1700 2200
F 0 "#PWR0108" H 1700 1950 50  0001 C CNN
F 1 "GND" H 1705 2027 50  0000 C CNN
F 2 "" H 1700 2200 50  0001 C CNN
F 3 "" H 1700 2200 50  0001 C CNN
	1    1700 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 1800 1700 1800
Connection ~ 2300 1800
$Comp
L Device:CP C4
U 1 1 5E740344
P 1700 1950
F 0 "C4" H 1818 1996 50  0000 L CNN
F 1 "0.1uF" H 1818 1905 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D4.0mm_P2.00mm" H 1738 1800 50  0001 C CNN
F 3 "~" H 1700 1950 50  0001 C CNN
	1    1700 1950
	1    0    0    -1  
$EndComp
Connection ~ 1700 1800
Wire Wire Line
	1700 1800 2100 1800
$Comp
L Device:CP C6
U 1 1 5E7407AD
P 2100 1950
F 0 "C6" H 2218 1996 50  0000 L CNN
F 1 "0.1uF" H 2218 1905 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D4.0mm_P2.00mm" H 2138 1800 50  0001 C CNN
F 3 "~" H 2100 1950 50  0001 C CNN
	1    2100 1950
	1    0    0    -1  
$EndComp
Connection ~ 2100 1800
Wire Wire Line
	2100 1800 2300 1800
Wire Wire Line
	2100 2100 1700 2100
Wire Wire Line
	1700 2100 1300 2100
Connection ~ 1700 2100
Wire Wire Line
	1700 2200 1700 2100
$EndSCHEMATC
