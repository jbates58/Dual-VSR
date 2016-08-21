/**************************************************************

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

***************************************************************/


//Included Code Libraries
#include <LiquidCrystal.h>


// these constants won't change.  But you can change the size of
// your LCD using them:
const int numRows = 4;
const int numCols = 20;


// initialize the LCD 20z4 Display with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(void) 
{
  Serial.begin(9600);
         // set up the LCD's number of columns and rows:
    lcd.begin(numCols, numRows);
        // Print a message to the LCD.
    Serial.println("    Dual Battery       VSR Controller   ");

}

void loop(void) 
{

    



}


    
void Start_Battery()    
{
    // Read and display BATTERY 1 (START BATTERY) Voltage based on A0 Pin Reading
    int sensorvoltage1 = analogRead (A0);
    float voltage1 = sensorvoltage1 * (15.0/ 1023.0);
    Serial.print ("Start Batteru Voltage");
    Serial.print (voltage1);
    Serial.println ("V");
}



void AUX_Battery (void)
{
    // Read and display BATTERY 2 (AUX BATTERY) Voltage based on A1 Pin Reading
    int sensorvoltage2 = analogRead (A1);
    float voltage2 = sensorvoltage2 * (15.0/ 1023.0);
    Serial.print ("AUX Battery Voltage");
    Serial.print (voltage2);
    Serial.println ("V");
}



void PV_Voltage()    
{
    // Read and display Solar PV Voltage Going into MPPT Controller based on A2 Pin Reading
    int sensorvoltage1 = analogRead (A2);
    float voltage3 = sensorvoltage1 * (15.0/ 1023.0);
    Serial.print ("PV Voltage");
    Serial.print (voltage3);
    Serial.println ("V");
}



void Start_Battery_Amps (void)
{
    // convert Start Battery 50 amp bidirectional sensor reading into amps based on A3 pin Reading
    int sensoramps1 = analogRead (A3);
    float amps = ((float) sensoramps1*0.3)-156.9; 
    Serial.print ("Start Battery Current");
    Serial.print (amps);
    Serial.println ("A");
}



void AUX_Battery_Amps (void)
{
    // convert Aux Battery 50 amp bidirectional sensor reading into amps based on A4 pin Reading
    int sensoramps2 = analogRead (A4);
    float amps = ((float) sensoramps2*0.3)-156.9; 
    Serial.print (" AUX Battery Current");
    Serial.print (amps);
    Serial.println ("A");
}



void PV_Amps (void)
{
    // convert 50 amp bidirectional sensor reading into amps based on A5 pin Reading
    int sensoramps3 = analogRead (A5);
    float amps = ((float) sensoramps3*0.3)-156.9; 
    Serial.print ("PV Inmput Current");
    Serial.print (amps);
    Serial.println ("A");
}

