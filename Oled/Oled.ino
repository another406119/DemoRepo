#include <Wire.h>
#include <Si7021.h>
#include <MapleCoOS.h>

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
#include "cSys.h"
#include "defTypes.h"
#include "cOrignal.h"

cSys sysObj;
cOrignal orignalFunc;
Si7021 Si;

uchar ledState = 0;
#define led1(val)  { if(val) gpio_write_bit(GPIOB, 5, 0); else gpio_write_bit(GPIOB, 5, 1);}

// the setup function runs once when you press reset or power the board
void setup() {
  //LED
  pinMode(PB5, OUTPUT);
  //I2C
  Wire.begin();
  //串口
  Serial1.begin(115200);
  
  if (Si.detectSensor())
  {
    // The sensor is detected. Lets carry on!
    Serial1.println("Device detected"); 
  }
  else
  {
    Serial1.println("Device NOT detected");
    while (1)
    {;;} // The sensor is not detected. Let's just stay here forever.
  }
}

// the loop function runs over and over again forever
void loop() {
/*  sysObj.state = 1;
  gpio_write_bit(GPIOB, 5, sysObj.state);
  delay(500);
  sysObj.state = 0;
  gpio_write_bit(GPIOB, 5, sysObj.state);
  delay(500);*/
  float temperature, humidity;
  
  temperature = Si.getTemperature();
  humidity = Si.getHumidity();

  // And output the data
  Serial1.print("Temperature: ");
  Serial1.print(temperature);
  Serial1.print(" C, Humidity: ");
  Serial1.print(humidity);
  Serial1.println(" %RH");
  delay(1000);
}


void cOrignal::comWrite(uchar com, uchar *buf, uchar len){
  if(com==1)
    Serial1.write(buf, len);
}
