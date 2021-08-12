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
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 60F5E2B5
P 4900 3750
F 0 "A1" H 4900 2661 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 4900 2570 50  0000 C CNN
F 2 "obd2_display:DIP-30_590_ELL" H 4900 3750 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 4900 3750 50  0001 C CNN
	1    4900 3750
	1    0    0    -1  
$EndComp
NoConn ~ 5400 3150
NoConn ~ 5400 3250
NoConn ~ 5400 4450
NoConn ~ 5400 4350
NoConn ~ 5400 4250
NoConn ~ 5400 4150
NoConn ~ 5400 4050
NoConn ~ 5400 3950
NoConn ~ 5400 3850
NoConn ~ 5400 3750
NoConn ~ 5400 3550
NoConn ~ 5000 2750
$Comp
L power:GND #PWR03
U 1 1 60F5F06E
P 6650 5050
F 0 "#PWR03" H 6650 4800 50  0001 C CNN
F 1 "GND" H 6655 4877 50  0000 C CNN
F 2 "" H 6650 5050 50  0001 C CNN
F 3 "" H 6650 5050 50  0001 C CNN
	1    6650 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 5050 6400 5050
Wire Wire Line
	5000 5050 5000 4750
Wire Wire Line
	4900 4750 4900 5050
Wire Wire Line
	4900 5050 5000 5050
Connection ~ 5000 5050
$Comp
L obd2_lib:HC05 D4
U 1 1 60F63B90
P 7550 3050
F 0 "D4" H 7728 2651 50  0000 L CNN
F 1 "HC05" H 7728 2560 50  0000 L CNN
F 2 "obd2_display:SIP-8" H 7550 3050 50  0001 C CNN
F 3 "" H 7550 3050 50  0001 C CNN
	1    7550 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 5050 6200 3550
Wire Wire Line
	6200 3550 7150 3550
Connection ~ 6200 5050
Wire Wire Line
	6200 5050 6100 5050
NoConn ~ 7150 3750
NoConn ~ 7150 3250
Wire Wire Line
	5100 2750 5100 2650
Wire Wire Line
	5100 2450 6600 2450
Wire Wire Line
	6600 2450 6600 3650
Wire Wire Line
	6600 3650 7150 3650
Wire Wire Line
	4400 3550 4200 3550
Wire Wire Line
	4200 3550 4200 2550
Wire Wire Line
	4200 2550 6650 2550
Wire Wire Line
	6650 2550 6650 3450
Wire Wire Line
	6650 3450 7150 3450
$Comp
L Device:R R1
U 1 1 60F64C88
P 5700 3100
F 0 "R1" H 5770 3146 50  0000 L CNN
F 1 "4700" H 5770 3055 50  0000 L CNN
F 2 "obd2_display:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5630 3100 50  0001 C CNN
F 3 "~" H 5700 3100 50  0001 C CNN
	1    5700 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 60F658EB
P 5700 3600
F 0 "R2" H 5770 3646 50  0000 L CNN
F 1 "10000" H 5770 3555 50  0000 L CNN
F 2 "obd2_display:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5630 3600 50  0001 C CNN
F 3 "~" H 5700 3600 50  0001 C CNN
	1    5700 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 60F65D18
P 5950 3100
F 0 "R3" H 6020 3146 50  0000 L CNN
F 1 "4700" H 6020 3055 50  0000 L CNN
F 2 "obd2_display:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5880 3100 50  0001 C CNN
F 3 "~" H 5950 3100 50  0001 C CNN
	1    5950 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 60F66190
P 5950 3600
F 0 "R4" H 6020 3646 50  0000 L CNN
F 1 "10000" H 6020 3555 50  0000 L CNN
F 2 "obd2_display:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5880 3600 50  0001 C CNN
F 3 "~" H 5950 3600 50  0001 C CNN
	1    5950 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 60F6665C
P 6250 2800
F 0 "R5" H 6320 2846 50  0000 L CNN
F 1 "4700" H 6320 2755 50  0000 L CNN
F 2 "obd2_display:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6180 2800 50  0001 C CNN
F 3 "~" H 6250 2800 50  0001 C CNN
	1    6250 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 60F66BF5
P 6250 3250
F 0 "R6" H 6320 3296 50  0000 L CNN
F 1 "10000" H 6320 3205 50  0000 L CNN
F 2 "obd2_display:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6180 3250 50  0001 C CNN
F 3 "~" H 6250 3250 50  0001 C CNN
	1    6250 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3750 5700 5050
Connection ~ 5700 5050
Wire Wire Line
	5700 5050 5000 5050
Wire Wire Line
	5950 3750 5950 5050
Connection ~ 5950 5050
Wire Wire Line
	5950 5050 5700 5050
Wire Wire Line
	6250 3400 6250 5050
Connection ~ 6250 5050
Wire Wire Line
	6250 5050 6200 5050
Wire Wire Line
	5950 3450 5950 3350
Wire Wire Line
	6250 3100 6250 3000
Wire Wire Line
	6250 3000 6800 3000
Wire Wire Line
	6800 3000 6800 3350
Wire Wire Line
	6800 3350 7150 3350
Connection ~ 6250 3000
Wire Wire Line
	6250 3000 6250 2950
Wire Wire Line
	4400 3650 4150 3650
Wire Wire Line
	4150 3650 4150 2450
Wire Wire Line
	4150 2450 4600 2450
Wire Wire Line
	4600 2450 4600 2500
Wire Wire Line
	4600 2500 6250 2500
Wire Wire Line
	6250 2500 6250 2650
Wire Wire Line
	5950 3350 6150 3350
Wire Wire Line
	6150 3350 6150 3850
Wire Wire Line
	6150 3850 7150 3850
Connection ~ 5950 3350
Wire Wire Line
	5950 3350 5950 3250
Wire Wire Line
	4400 3850 4050 3850
Wire Wire Line
	4050 3850 4050 2400
Wire Wire Line
	4050 2400 5950 2400
Wire Wire Line
	5950 2400 5950 2950
Wire Wire Line
	4400 3750 4100 3750
Wire Wire Line
	4100 3750 4100 2350
Wire Wire Line
	4100 2350 5700 2350
Wire Wire Line
	5700 2350 5700 2950
Wire Wire Line
	5700 3450 5700 3350
Wire Wire Line
	5700 3350 5800 3350
Wire Wire Line
	5800 3350 5800 2600
Wire Wire Line
	5800 2600 6850 2600
Wire Wire Line
	6850 2600 6850 3150
Wire Wire Line
	6850 3150 7150 3150
Connection ~ 5700 3350
Wire Wire Line
	5700 3350 5700 3250
$Comp
L obd2_lib:OLED_128_64_7 D1
U 1 1 60F6E7D2
P 2050 4700
F 0 "D1" H 1892 3635 50  0000 C CNN
F 1 "OLED_128_64_7" H 1892 3726 50  0000 C CNN
F 2 "obd2_display:SIP-7" H 2050 4700 50  0001 C CNN
F 3 "" H 2050 4700 50  0001 C CNN
	1    2050 4700
	-1   0    0    1   
$EndComp
Wire Wire Line
	5100 2650 3200 2650
Wire Wire Line
	3200 2650 3200 2900
Wire Wire Line
	3200 4400 2500 4400
Connection ~ 5100 2650
Wire Wire Line
	5100 2650 5100 2450
Wire Wire Line
	4900 5050 3700 5050
Wire Wire Line
	2500 5050 2500 4500
Connection ~ 4900 5050
Wire Wire Line
	4400 4450 2650 4450
Wire Wire Line
	2650 4450 2650 4300
Wire Wire Line
	2650 4300 2500 4300
Wire Wire Line
	4400 4250 2500 4250
Wire Wire Line
	2500 4250 2500 4200
Wire Wire Line
	4400 3950 2800 3950
Wire Wire Line
	2800 3950 2800 4100
Wire Wire Line
	2800 4100 2500 4100
Wire Wire Line
	4400 4050 2900 4050
Wire Wire Line
	2900 4050 2900 4000
Wire Wire Line
	2900 4000 2500 4000
Wire Wire Line
	4400 4150 2700 4150
Wire Wire Line
	2700 4150 2700 3900
Wire Wire Line
	2700 3900 2500 3900
$Comp
L obd2_lib:Touh D2
U 1 1 60F7AF62
P 2250 3100
F 0 "D2" H 2117 2585 50  0000 C CNN
F 1 "Touh" H 2117 2676 50  0000 C CNN
F 2 "obd2_display:SIP-3" H 2250 3100 50  0001 C CNN
F 3 "" H 2250 3100 50  0001 C CNN
	1    2250 3100
	-1   0    0    1   
$EndComp
Wire Wire Line
	2650 3000 3000 3000
Wire Wire Line
	3000 3000 3000 5050
Connection ~ 3000 5050
Wire Wire Line
	3000 5050 2500 5050
Wire Wire Line
	3200 2900 2650 2900
Connection ~ 3200 2900
Wire Wire Line
	3200 2900 3200 4400
Wire Wire Line
	4400 3450 3650 3450
Wire Wire Line
	3650 3450 3650 2800
Wire Wire Line
	3650 2800 2650 2800
$Comp
L obd2_lib:Switch_Block_My D3
U 1 1 60F83CD2
P 4900 5400
F 0 "D3" H 5328 5151 50  0000 L CNN
F 1 "Switch_Block_My" H 5328 5060 50  0000 L CNN
F 2 "obd2_display:SIP-4" H 4900 5400 50  0001 C CNN
F 3 "" H 4900 5400 50  0001 C CNN
	1    4900 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 5650 3550 5650
Wire Wire Line
	3550 2700 4800 2700
Wire Wire Line
	4800 2700 4800 2750
$Comp
L power:VCC #PWR01
U 1 1 60F87491
P 2300 5400
F 0 "#PWR01" H 2300 5250 50  0001 C CNN
F 1 "VCC" H 2315 5573 50  0000 C CNN
F 2 "" H 2300 5400 50  0001 C CNN
F 3 "" H 2300 5400 50  0001 C CNN
	1    2300 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 5550 2300 5550
Wire Wire Line
	2300 5550 2300 5400
$Comp
L Device:R R7
U 1 1 60F8A421
P 7350 4550
F 0 "R7" H 7420 4596 50  0000 L CNN
F 1 "100" H 7420 4505 50  0000 L CNN
F 2 "obd2_display:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7280 4550 50  0001 C CNN
F 3 "~" H 7350 4550 50  0001 C CNN
	1    7350 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 3650 6600 4400
Wire Wire Line
	6600 4400 7350 4400
Connection ~ 6600 3650
Wire Wire Line
	4400 5850 3700 5850
Wire Wire Line
	3700 5850 3700 5050
Connection ~ 3700 5050
Wire Wire Line
	3700 5050 3000 5050
Wire Wire Line
	7350 4700 7350 5350
Wire Wire Line
	7350 5350 4050 5350
Wire Wire Line
	4050 5350 4050 5750
Wire Wire Line
	4050 5750 4400 5750
Wire Wire Line
	4400 4350 4050 4350
Wire Wire Line
	4050 4350 4050 5350
Connection ~ 4050 5350
NoConn ~ 4400 3150
NoConn ~ 4400 3250
$Comp
L Device:R R8
U 1 1 60F9CA59
P 7700 4550
F 0 "R8" H 7770 4596 50  0000 L CNN
F 1 "220" H 7770 4505 50  0000 L CNN
F 2 "obd2_display:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7630 4550 50  0001 C CNN
F 3 "~" H 7700 4550 50  0001 C CNN
	1    7700 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D5
U 1 1 60F9D074
P 7700 5100
F 0 "D5" V 7739 4982 50  0000 R CNN
F 1 "LED" V 7648 4982 50  0000 R CNN
F 2 "obd2_display:SIP-2" H 7700 5100 50  0001 C CNN
F 3 "~" H 7700 5100 50  0001 C CNN
	1    7700 5100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 3350 4250 3350
Wire Wire Line
	4250 3350 4250 2300
Wire Wire Line
	4250 2300 8000 2300
Wire Wire Line
	8000 2300 8000 4300
Wire Wire Line
	8000 4300 7700 4300
Wire Wire Line
	7700 4300 7700 4400
Wire Wire Line
	7700 4700 7700 4950
Wire Wire Line
	7700 5250 7700 5600
Wire Wire Line
	7700 5600 7000 5600
Wire Wire Line
	7000 5600 7000 4800
Wire Wire Line
	7000 4800 6400 4800
Wire Wire Line
	6400 4800 6400 5050
Connection ~ 6400 5050
Wire Wire Line
	6400 5050 6250 5050
$Comp
L power:PWR_FLAG #FLG01
U 1 1 60FA86EA
P 8800 2850
F 0 "#FLG01" H 8800 2925 50  0001 C CNN
F 1 "PWR_FLAG" H 8800 3023 50  0000 C CNN
F 2 "" H 8800 2850 50  0001 C CNN
F 3 "~" H 8800 2850 50  0001 C CNN
	1    8800 2850
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 60FA8C0E
P 9200 2850
F 0 "#FLG02" H 9200 2925 50  0001 C CNN
F 1 "PWR_FLAG" H 9200 3023 50  0000 C CNN
F 2 "" H 9200 2850 50  0001 C CNN
F 3 "~" H 9200 2850 50  0001 C CNN
	1    9200 2850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J1
U 1 1 60FA9454
P 8750 5400
F 0 "J1" H 8778 5376 50  0000 L CNN
F 1 "POWER_SW" H 8778 5285 50  0000 L CNN
F 2 "obd2_display:SIP-2" H 8750 5400 50  0001 C CNN
F 3 "~" H 8750 5400 50  0001 C CNN
	1    8750 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 5550 2300 6150
Wire Wire Line
	2300 6150 8000 6150
Wire Wire Line
	8000 6150 8000 5400
Wire Wire Line
	8000 5400 8550 5400
Connection ~ 2300 5550
Wire Wire Line
	8550 5500 6100 5500
Wire Wire Line
	6100 5500 6100 5050
Connection ~ 6100 5050
Wire Wire Line
	6100 5050 5950 5050
$Comp
L power:VCC #PWR05
U 1 1 60FB1FBC
P 9200 3250
F 0 "#PWR05" H 9200 3100 50  0001 C CNN
F 1 "VCC" H 9215 3423 50  0000 C CNN
F 2 "" H 9200 3250 50  0001 C CNN
F 3 "" H 9200 3250 50  0001 C CNN
	1    9200 3250
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 60FB26BC
P 8850 3250
F 0 "#PWR04" H 8850 3000 50  0001 C CNN
F 1 "GND" H 8855 3077 50  0000 C CNN
F 2 "" H 8850 3250 50  0001 C CNN
F 3 "" H 8850 3250 50  0001 C CNN
	1    8850 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 3250 9200 2850
Wire Wire Line
	8850 3250 8850 3100
Wire Wire Line
	8850 3100 8800 3050
Wire Wire Line
	8800 3050 8800 2850
Wire Wire Line
	3550 2700 3550 5300
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 60FAE37F
P 3300 5300
F 0 "#FLG0101" H 3300 5375 50  0001 C CNN
F 1 "PWR_FLAG" H 3300 5473 50  0000 C CNN
F 2 "" H 3300 5300 50  0001 C CNN
F 3 "~" H 3300 5300 50  0001 C CNN
	1    3300 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 5300 3550 5300
Connection ~ 3550 5300
Wire Wire Line
	3550 5300 3550 5650
$Sheet
S 9450 1150 600  700 
U 60FBB860
F0 "Sheet60FBB85F" 50
F1 "file60FBB85F.sch" 50
$EndSheet
$EndSCHEMATC
