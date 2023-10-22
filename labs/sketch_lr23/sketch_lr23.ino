/*  RCTiming_capacitance_meter

 *   Paul Badger 2008

 *  Demonstrates use of RC time constants to measure the value of a capacitor

 *

 * Theory   A capacitor will charge, through a resistor, in one time constant, defined as T seconds where

 *    TC = R * C

 *

 *    TC = time constant period in seconds

 *    R = resistance in ohms

 *    C = capacitance in farads (1 microfarad (ufd) = .000001 farad = 10^-6 farads )

 *

 *    The capacitor's voltage at one time constant is defined as 63.2% of the charging voltage.

 *

 *  Hardware setup:

 *  Test Capacitor between common point and ground (positive side of an electrolytic capacitor  to common)

 *  Test Resistor between chargePin and common point

 *  220 ohm resistor between dischargePin and common point

 *  Wire between common point and analogPin (A/D input)

 */
#include <LiquidCrystal.h>
#define analogPin      0          // analog pin for measuring capacitor voltage
#define chargePin      13         // pin to charge the capacitor - connected to one end of the charging resistor
#define dischargePin   11         // pin to discharge the capacitor
#define resistorValue  10000.0F   // change this to whatever resistor value you are using

                                  // F formatter tells compiler it's a floating point value

unsigned long startTime;
unsigned long elapsedTime;
float microFarads;                // floating point variable to preserve precision, make calculations
float nanoFarads;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // (RS, E, DB4, DB5, DB6, DB7)
void setup(){

  pinMode(chargePin, OUTPUT);     // set chargePin to output

  digitalWrite(chargePin, LOW);

  lcd.begin(16, 2);
}

void loop(){

  digitalWrite(chargePin, HIGH);  // set chargePin HIGH and capacitor charging

  startTime = millis();

  while(analogRead(analogPin) < 648){       // 647 is 63.2% of 1023, which corresponds to full-scale voltage

  }

  elapsedTime= millis() - startTime;

 // convert milliseconds to seconds ( 10^-3 ) and Farads to microFarads ( 10^6 ),  net 10^3 (1000)

  microFarads = ((float)elapsedTime / resistorValue) * 1000;

  if (microFarads > 1){

    lcd.print((long)microFarads);       // print the value to serial port

    lcd.print(" mF");         // print units and carriage return

  }

  else

  {

    // if value is smaller than one microFarad, convert to nanoFarads (10^-9 Farad).

    // This is  a workaround because Serial.print will not print floats

    nanoFarads = microFarads * 1000.0;      // multiply by 1000 to convert to nanoFarads (10^-9 Farads)

    lcd.print((long)nanoFarads);         // print the value to serial port

    lcd.print(" nF");          // print units and carriage return

  }

  /* dicharge the capacitor  */

  digitalWrite(chargePin, LOW);             // set charge pin to  LOW

  pinMode(dischargePin, OUTPUT);            // set discharge pin to output

  digitalWrite(dischargePin, LOW);          // set discharge pin LOW

  while(analogRead(analogPin) > 0){         // wait until capacitor is completely discharged

  }

  pinMode(dischargePin, INPUT);            // set discharge pin back to input
}