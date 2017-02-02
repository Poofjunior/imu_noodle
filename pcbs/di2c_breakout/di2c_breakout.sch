EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:double_jump_electric_component_library
LIBS:synthego_component_library
LIBS:di2c_breakout-cache
EELAYER 25 0
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
NoConn ~ 8200 3300
$Comp
L R R4
U 1 1 587058C5
P 5600 4300
F 0 "R4" V 5680 4300 50  0000 C CNN
F 1 "130" V 5600 4300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5530 4300 50  0001 C CNN
F 3 "" H 5600 4300 50  0000 C CNN
F 4 "Panasonic Electronic Components" H 5600 4300 60  0001 C CNN "Manufacturer"
F 5 "ERJ-3EKF1300V" H 5600 4300 60  0001 C CNN "Manufacturer Number"
F 6 "1%" H 5600 4300 60  0001 C CNN "Precision"
	1    5600 4300
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 58705B5F
P 5600 4600
F 0 "R5" V 5680 4600 50  0000 C CNN
F 1 "750" V 5600 4600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5530 4600 50  0001 C CNN
F 3 "" H 5600 4600 50  0000 C CNN
F 4 "Panasonic Electronic Components" H 5600 4600 60  0001 C CNN "Manufacturer"
F 5 "ERJ-3EKF7500V" H 5600 4600 60  0001 C CNN "Manufacturer Number"
F 6 "1%" H 5600 4600 60  0001 C CNN "Precision"
	1    5600 4600
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 58705BF4
P 5600 4000
F 0 "R3" V 5680 4000 50  0000 C CNN
F 1 "750" V 5600 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5530 4000 50  0001 C CNN
F 3 "" H 5600 4000 50  0000 C CNN
F 4 "Panasonic Electronic Components" H 5600 4000 60  0001 C CNN "Manufacturer"
F 5 "ERJ-3EKF7500V" H 5600 4000 60  0001 C CNN "Manufacturer Number"
	1    5600 4000
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 58705E7E
P 6550 3350
F 0 "R7" V 6630 3350 50  0000 C CNN
F 1 "130" V 6550 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6480 3350 50  0001 C CNN
F 3 "" H 6550 3350 50  0000 C CNN
F 4 "Panasonic Electronic Components" H 6550 3350 60  0001 C CNN "Manufacturer"
F 5 "ERJ-3EKF1300V" H 6550 3350 60  0001 C CNN "Manufacturer Number"
F 6 "1%" H 6550 3350 60  0001 C CNN "Precision"
	1    6550 3350
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 5870605A
P 6550 3650
F 0 "R8" V 6630 3650 50  0000 C CNN
F 1 "750" V 6550 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6480 3650 50  0001 C CNN
F 3 "" H 6550 3650 50  0000 C CNN
F 4 "Panasonic Electronic Components" H 6550 3650 60  0001 C CNN "Manufacturer"
F 5 "ERJ-3EKF7500V" H 6550 3650 60  0001 C CNN "Manufacturer Number"
F 6 "1%" H 6550 3650 60  0001 C CNN "Precision"
	1    6550 3650
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 587060A2
P 6550 3050
F 0 "R6" V 6630 3050 50  0000 C CNN
F 1 "750" V 6550 3050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6480 3050 50  0001 C CNN
F 3 "" H 6550 3050 50  0000 C CNN
F 4 "Panasonic Electronic Components" H 6550 3050 60  0001 C CNN "Manufacturer"
F 5 "ERJ-3EKF7500V" H 6550 3050 60  0001 C CNN "Manufacturer Number"
F 6 "1%" H 6550 3050 60  0001 C CNN "Precision"
	1    6550 3050
	1    0    0    -1  
$EndComp
Text Notes 4050 2200 0    60   ~ 0
Populate termination resistors ONLY on the last peripheral in a set.
Text Notes 5400 3350 0    60   ~ 0
DSCL\ntermination\nresistors
Text Notes 6400 2600 0    60   ~ 0
DSDA\ntermination\nresistors
$Comp
L C C2
U 1 1 5879BF70
P 9650 2750
F 0 "C2" H 9675 2850 50  0000 L CNN
F 1 "0.1uF" H 9675 2650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9688 2600 50  0001 C CNN
F 3 "" H 9650 2750 50  0000 C CNN
F 4 "AVX Corporation" H 9650 2750 60  0001 C CNN "Manufacturer"
F 5 "0603YC104KAT2A" H 9650 2750 60  0001 C CNN "Manufacturer Number"
F 6 "10%" H 9650 2750 60  0001 C CNN "Precision"
F 7 "16V" H 9650 2750 60  0001 C CNN "Description"
F 8 "X7R" H 9650 2750 60  0001 C CNN "Temperature Coefficient"
	1    9650 2750
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5879C083
P 9300 2750
F 0 "C1" H 9325 2850 50  0000 L CNN
F 1 "1uF" H 9325 2650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9338 2600 50  0001 C CNN
F 3 "" H 9300 2750 50  0000 C CNN
F 4 "AVX Corporation" H 9300 2750 60  0001 C CNN "Manufacturer"
F 5 "0603YC105KAT2A" H 9300 2750 60  0001 C CNN "Manufacturer Number"
F 6 "10%" H 9300 2750 60  0001 C CNN "Precision"
F 7 "16V" H 9300 2750 60  0001 C CNN "Description"
F 8 "X7R" H 9300 2750 60  0001 C CNN "Temperature Coefficient"
	1    9300 2750
	1    0    0    -1  
$EndComp
Text Label 6350 3300 2    60   ~ 0
DSDA0_N
Text Label 6350 3400 2    60   ~ 0
DSDA0_P
Text Label 5300 4250 2    60   ~ 0
DSCL0_P
Text Label 5300 4350 2    60   ~ 0
DSCL0_N
Text Label 2650 2400 2    60   ~ 0
DSCL0_P
Text Label 2650 2300 2    60   ~ 0
DSCL0_N
Text Label 2650 2600 2    60   ~ 0
DSDA0_N
Text Label 2650 2500 2    60   ~ 0
DSDA0_P
Wire Wire Line
	7000 3550 7100 3550
Wire Wire Line
	7100 3650 7100 3650
Wire Wire Line
	7100 4350 7100 3650
Wire Wire Line
	8500 3450 8200 3450
Wire Wire Line
	8200 3550 8250 3550
Wire Wire Line
	7650 4100 7650 4150
Wire Wire Line
	7000 4250 7000 3550
Wire Wire Line
	7750 2700 7750 2750
Wire Wire Line
	7550 2750 7550 2700
Wire Wire Line
	5450 4150 5750 4150
Wire Wire Line
	5750 4150 5750 4250
Wire Wire Line
	5750 4250 7000 4250
Connection ~ 5600 4150
Wire Wire Line
	5750 4450 5750 4350
Wire Wire Line
	5450 4450 5750 4450
Connection ~ 5600 4450
Wire Wire Line
	5600 4750 5600 4800
Wire Wire Line
	5600 3800 5600 3850
Wire Wire Line
	6350 3300 6450 3300
Wire Wire Line
	6450 3300 6450 3200
Wire Wire Line
	6450 3200 6750 3200
Wire Wire Line
	6750 3200 6750 3300
Wire Wire Line
	6750 3300 7100 3300
Connection ~ 6550 3200
Wire Wire Line
	7100 3400 6750 3400
Wire Wire Line
	6750 3500 6750 3400
Wire Wire Line
	6450 3500 6750 3500
Wire Wire Line
	6450 3500 6450 3400
Wire Wire Line
	6450 3400 6350 3400
Connection ~ 6550 3500
Wire Wire Line
	6550 2700 6550 2900
Wire Notes Line
	6850 4200 6400 4200
Wire Notes Line
	6400 4200 6400 2650
Wire Notes Line
	6400 2650 6850 2650
Wire Notes Line
	6850 2650 6850 4200
Wire Wire Line
	6550 3800 6550 3850
Wire Notes Line
	5800 5000 5800 3400
Wire Notes Line
	5800 3400 5400 3400
Wire Notes Line
	5400 3400 5400 5000
Wire Notes Line
	5400 5000 5800 5000
Wire Wire Line
	9650 2550 9650 2600
Wire Wire Line
	9300 2550 9300 2600
Wire Wire Line
	9300 2950 9300 2900
Wire Wire Line
	9650 2950 9650 2900
Wire Wire Line
	5750 4350 7100 4350
Wire Wire Line
	5450 4150 5450 4250
Wire Wire Line
	5450 4250 5300 4250
Wire Wire Line
	5450 4450 5450 4350
Wire Wire Line
	5450 4350 5300 4350
Wire Wire Line
	3250 2300 3450 2300
Wire Wire Line
	3450 2400 3250 2400
Wire Wire Line
	3450 2500 3250 2500
Wire Wire Line
	3450 2600 3250 2600
Wire Wire Line
	2750 2600 2650 2600
Wire Wire Line
	2750 2500 2650 2500
Wire Wire Line
	2750 2400 2650 2400
Wire Wire Line
	2750 2300 2650 2300
Connection ~ 3450 2600
Connection ~ 3450 2500
Connection ~ 3450 2400
$Comp
L GNDD #PWR01
U 1 1 58797A1E
P 7650 4150
F 0 "#PWR01" H 7650 3900 50  0001 C CNN
F 1 "GNDD" H 7650 4000 50  0000 C CNN
F 2 "" H 7650 4150 50  0000 C CNN
F 3 "" H 7650 4150 50  0000 C CNN
	1    7650 4150
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR02
U 1 1 58797CB0
P 9650 2950
F 0 "#PWR02" H 9650 2700 50  0001 C CNN
F 1 "GNDD" H 9650 2800 50  0000 C CNN
F 2 "" H 9650 2950 50  0000 C CNN
F 3 "" H 9650 2950 50  0000 C CNN
	1    9650 2950
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR03
U 1 1 58797E99
P 6700 2750
F 0 "#PWR03" H 6700 2500 50  0001 C CNN
F 1 "GNDD" H 6700 2600 50  0000 C CNN
F 2 "" H 6700 2750 50  0000 C CNN
F 3 "" H 6700 2750 50  0000 C CNN
	1    6700 2750
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR04
U 1 1 587980B3
P 5600 4800
F 0 "#PWR04" H 5600 4550 50  0001 C CNN
F 1 "GNDD" H 5600 4650 50  0000 C CNN
F 2 "" H 5600 4800 50  0000 C CNN
F 3 "" H 5600 4800 50  0000 C CNN
	1    5600 4800
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR05
U 1 1 58798216
P 9300 2950
F 0 "#PWR05" H 9300 2700 50  0001 C CNN
F 1 "GNDD" H 9300 2800 50  0000 C CNN
F 2 "" H 9300 2950 50  0000 C CNN
F 3 "" H 9300 2950 50  0000 C CNN
	1    9300 2950
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR06
U 1 1 587983CF
P 3450 2850
F 0 "#PWR06" H 3450 2600 50  0001 C CNN
F 1 "GNDD" H 3450 2700 50  0000 C CNN
F 2 "" H 3450 2850 50  0000 C CNN
F 3 "" H 3450 2850 50  0000 C CNN
	1    3450 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2300 3450 2850
$Comp
L CONN_02X05 P1
U 1 1 58780C1B
P 3000 2500
F 0 "P1" H 3000 2800 50  0000 C CNN
F 1 "CONN_02X05" H 3000 2200 50  0000 C CNN
F 2 "double_jump_electric_component_library:3M_ribbon_connector_thru_5x2_.05in_pitch_45210-600230" H 3000 1300 50  0001 C CNN
F 3 "http://multimedia.3m.com/mws/media/905148O/3m-shrouded-boardmount-header-452-series-cd2437.pdf" H 3000 1300 50  0001 C CNN
F 4 "3M" H 3000 2500 60  0001 C CNN "Manufacturer"
F 5 "45210-520230" H 3000 2500 60  0001 C CNN "Manufacturer Number"
	1    3000 2500
	1    0    0    1   
$EndComp
Wire Wire Line
	3250 2700 3450 2700
Connection ~ 3450 2700
Wire Wire Line
	2050 2700 2750 2700
$Comp
L PCA9615 U1
U 1 1 588E5A17
P 8000 3900
F 0 "U1" H 8650 4900 60  0000 C CNN
F 1 "PCA9615" H 7950 4950 60  0000 C CNN
F 2 "Housings_SSOP:TSSOP-10_3x3mm_Pitch0.5mm" H 8000 3900 60  0001 C CNN
F 3 "" H 8000 3900 60  0001 C CNN
	1    8000 3900
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X04 P2
U 1 1 588E6994
P 3150 3800
F 0 "P2" H 3150 4050 50  0000 C CNN
F 1 "CONN_01X04" V 3250 3800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 3150 3800 50  0001 C CNN
F 3 "" H 3150 3800 50  0000 C CNN
	1    3150 3800
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P3
U 1 1 588E6AB5
P 3150 4450
F 0 "P3" H 3150 4700 50  0000 C CNN
F 1 "CONN_01X04" V 3250 4450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 3150 4450 50  0001 C CNN
F 3 "" H 3150 4450 50  0000 C CNN
	1    3150 4450
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR07
U 1 1 588E6B9A
P 2600 3850
F 0 "#PWR07" H 2600 3600 50  0001 C CNN
F 1 "GNDD" H 2600 3700 50  0000 C CNN
F 2 "" H 2600 3850 50  0000 C CNN
F 3 "" H 2600 3850 50  0000 C CNN
	1    2600 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	2950 3750 2250 3750
Wire Wire Line
	2950 3650 2250 3650
Text Label 2250 3750 2    60   ~ 0
SDA
Text Label 2250 3650 2    60   ~ 0
SCL
Text Label 8500 3450 0    60   ~ 0
SDA
Text Label 8250 3550 0    60   ~ 0
SCL
Wire Wire Line
	6700 2750 6700 2700
Wire Wire Line
	6700 2700 6550 2700
Wire Wire Line
	2950 3950 2900 3950
Wire Wire Line
	2950 3850 2600 3850
$Comp
L GNDD #PWR08
U 1 1 588ED404
P 2900 4700
F 0 "#PWR08" H 2900 4450 50  0001 C CNN
F 1 "GNDD" H 2900 4550 50  0000 C CNN
F 2 "" H 2900 4700 50  0000 C CNN
F 3 "" H 2900 4700 50  0000 C CNN
	1    2900 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 4400 2900 4700
Wire Wire Line
	2950 4600 2900 4600
Connection ~ 2900 4600
Wire Wire Line
	2950 4500 2900 4500
Connection ~ 2900 4500
$Comp
L R R1
U 1 1 588ED93D
P 1900 2700
F 0 "R1" V 1980 2700 50  0000 C CNN
F 1 "0" V 1900 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1830 2700 50  0001 C CNN
F 3 "" H 1900 2700 50  0000 C CNN
F 4 "Panasonic Electronic Components" H 1900 2700 60  0001 C CNN "Manufacturer"
F 5 "ERJ-3GEY0R00V" H 1900 2700 60  0001 C CNN "Manufacturer Number"
	1    1900 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	1750 2700 1600 2700
$Comp
L R R2
U 1 1 588EDC5C
P 1900 2950
F 0 "R2" V 1980 2950 50  0000 C CNN
F 1 "0" V 1900 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1830 2950 50  0001 C CNN
F 3 "" H 1900 2950 50  0000 C CNN
F 4 "Panasonic Electronic Components" H 1900 2950 60  0001 C CNN "Manufacturer"
F 5 "ERJ-3GEY0R00V" H 1900 2950 60  0001 C CNN "Manufacturer Number"
	1    1900 2950
	0    1    1    0   
$EndComp
$Comp
L GNDD #PWR09
U 1 1 588EDD01
P 1600 2950
F 0 "#PWR09" H 1600 2700 50  0001 C CNN
F 1 "GNDD" H 1600 2800 50  0000 C CNN
F 2 "" H 1600 2950 50  0000 C CNN
F 3 "" H 1600 2950 50  0000 C CNN
	1    1600 2950
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 2700 2150 2950
Wire Wire Line
	2150 2950 2050 2950
Connection ~ 2150 2700
Wire Wire Line
	1750 2950 1600 2950
Wire Notes Line
	2200 2600 2200 3100
Wire Notes Line
	2200 3100 1650 3100
Wire Notes Line
	1650 3100 1650 2600
Wire Notes Line
	1650 2600 2200 2600
Text Notes 1650 3300 0    60   ~ 0
Populate one or the other\nbut NOT both
Text GLabel 7550 2700 1    60   Input ~ 0
VDDB
Text GLabel 5600 3800 1    60   Input ~ 0
VDDB
Text GLabel 6550 3850 3    60   Input ~ 0
VDDB
Text GLabel 2700 4300 0    60   Input ~ 0
VDDB
Wire Wire Line
	2950 4400 2900 4400
Wire Wire Line
	2700 4300 2950 4300
Text GLabel 2900 3950 0    60   Input ~ 0
VDDA
Text GLabel 7750 2700 1    60   Input ~ 0
VDDA
Text GLabel 9300 2550 1    60   Input ~ 0
VDDA
Text GLabel 9650 2550 1    60   Input ~ 0
VDDA
$Comp
L C C4
U 1 1 588F0681
P 10600 2750
F 0 "C4" H 10625 2850 50  0000 L CNN
F 1 "0.1uF" H 10625 2650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 10638 2600 50  0001 C CNN
F 3 "" H 10600 2750 50  0000 C CNN
F 4 "AVX Corporation" H 10600 2750 60  0001 C CNN "Manufacturer"
F 5 "0603YC104KAT2A" H 10600 2750 60  0001 C CNN "Manufacturer Number"
F 6 "10%" H 10600 2750 60  0001 C CNN "Precision"
F 7 "16V" H 10600 2750 60  0001 C CNN "Description"
F 8 "X7R" H 10600 2750 60  0001 C CNN "Temperature Coefficient"
	1    10600 2750
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 588F068C
P 10250 2750
F 0 "C3" H 10275 2850 50  0000 L CNN
F 1 "1uF" H 10275 2650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 10288 2600 50  0001 C CNN
F 3 "" H 10250 2750 50  0000 C CNN
F 4 "AVX Corporation" H 10250 2750 60  0001 C CNN "Manufacturer"
F 5 "0603YC105KAT2A" H 10250 2750 60  0001 C CNN "Manufacturer Number"
F 6 "10%" H 10250 2750 60  0001 C CNN "Precision"
F 7 "16V" H 10250 2750 60  0001 C CNN "Description"
F 8 "X7R" H 10250 2750 60  0001 C CNN "Temperature Coefficient"
	1    10250 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 2550 10600 2600
Wire Wire Line
	10250 2550 10250 2600
Wire Wire Line
	10250 2950 10250 2900
Wire Wire Line
	10600 2950 10600 2900
$Comp
L GNDD #PWR010
U 1 1 588F0696
P 10600 2950
F 0 "#PWR010" H 10600 2700 50  0001 C CNN
F 1 "GNDD" H 10600 2800 50  0000 C CNN
F 2 "" H 10600 2950 50  0000 C CNN
F 3 "" H 10600 2950 50  0000 C CNN
	1    10600 2950
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR011
U 1 1 588F069C
P 10250 2950
F 0 "#PWR011" H 10250 2700 50  0001 C CNN
F 1 "GNDD" H 10250 2800 50  0000 C CNN
F 2 "" H 10250 2950 50  0000 C CNN
F 3 "" H 10250 2950 50  0000 C CNN
	1    10250 2950
	1    0    0    -1  
$EndComp
Text GLabel 10250 2550 1    60   Input ~ 0
VDDB
Text GLabel 10600 2550 1    60   Input ~ 0
VDDB
Text GLabel 1600 2700 0    60   Input ~ 0
VDDA
$EndSCHEMATC
