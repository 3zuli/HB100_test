# HB100_test
A quick test of the cheap HB100 doppler radar module. Can be bought on ebay for ~$5. The module works by 
outputting a square waveform from its IF pin at frequency of the detected Doppler shift. However this signal is only
a copule microvolts peak-to-peak, so we need a pre-amplifier to boost the signal to 5V logic levels.

Datasheet of the module: https://www.openimpulse.com/blog/wp-content/uploads/wpsc/downloadables/HB100_Microwave_Sensor_Application_Note.pdf

HW requirements:
* Arduino Uno / Nano / Pro mini
* HB100 module + pre-amp board
* 1602 or similar LCD 

SW requirements:
* FreqMeasure library http://www.pjrc.com/teensy/td_libs_FreqMeasure.html (located in /HB100_LCD_Output/FreqMeasure folder)

The "design" folder contains design files of the pre-amp board for Eagle. The circuit was taken from the above
datasheet, I just designed the PCB for it. Ready-made preamp boards are available from here:
http://www.limpkin.fr/index.php?post/2013/08/09/Making-the-electronics-for-a-%247-USD-doppler-motion-sensor

The "HB100_LCD_output" folder contains the Arduino source code. The code is just the slightly modified LCD example from FreqMeasure. In the loop, we take 30 frequency measurements, then get the average value and display it on the LCD. This was tested on an Arduino Nano and should work as well on Uno and Pro Mini. For other boards, see the FreqMeasure documentation below.

Additional info:
* http://jpnelson.com/post/37623468093/microwave-motion-sensors-for-fun-and-profit-hb100
* http://forum.arduino.cc/index.php?topic=61989.0
* http://www.limpkin.fr/index.php?post/2013/08/09/Making-the-electronics-for-a-%247-USD-doppler-motion-sensor
