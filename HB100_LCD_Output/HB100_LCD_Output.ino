/* FreqMeasure - Example with LCD output
 * http://www.pjrc.com/teensy/td_libs_FreqMeasure.html
 * 
 * Slightly modified by @3zuli for use with HB100 doppler radar module
 *
 * This example code is in the public domain.
 *
 * Frequency input pin: 8. Connect the IF pin from the preamp board to this pin.
 * This should work with Arduino Uno, Nano, Pro mini and simillar.
 * For other boards, see the FreqMeasure documentation (link above).
 *
 * 16x2 character display is connected exactly as in the LiquidCrystal library examples:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
 
 
#include "FreqMeasure/FreqMeasure.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(57600);
  lcd.begin(16, 2);
  lcd.print("Freq:");
  lcd.setCursor(10,0);
  lcd.print("Speed:");
  FreqMeasure.begin();
}

double sum=0;
int count=0;

void loop() {
  if (FreqMeasure.available()) {
    // average 30 readings together
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count > 30) {
      float frequency = FreqMeasure.countToFrequency(sum / count);
      float spd = frequency / 19.49; //conversion from frequency to kilometers per hour (sorry, imperial guys :)
      //to improve speed, we update only the bottom row of the LCD
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print(frequency);
      lcd.print("Hz");
      //lcd.print("       ");
      lcd.setCursor(8,1);
      lcd.print(spd);
      lcd.print("km/h");
      sum = 0;
      count = 0;
    }
  }
}

