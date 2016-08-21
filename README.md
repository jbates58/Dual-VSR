# Dual-VSR
Arduino based Dual Battery VSR



**************************************************************

Dual Battery VSR Controller:
     -Reads 2 seperate battery voltages
     -Controls the switching of a relay based on voltages - Will work either way, so if AUX battery is over trip threshold from PV input, it will link to charge MAIN battery.
     -Measures the current INTO or OUT of both batteries
     - Displays START & AUX Battery VOLTAGE and CURRENT flows on a 20x4 LCD screen
     - Displays START & AUX Battery VOLTAGE and CURRENT flows via Serial out at 9600BPS

***************************************************************

Arduino Pinouts:
     -A0 - Start Battery Voltage
     -A1 - Auxilary Battery Voltage
     -A2 - Solar PV Voltage (before MPPT Controller)
     -A3 - Start Battery Current IN/OUT
     -A4 - Auxillary Battery Current IN/OUT
     -A5 - Solar PV Charge Current

***************************************************************

LCD Pinouts:

 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
     - ends to +5V and ground
     - wiper to LCD VO pin (pin 3)

***************************************************************
