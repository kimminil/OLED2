#include <Arduino.h>
#include <SSD1306.h>
SSD1306   display(0x3c, 4, 5, GEOMETRY_128_32);


int val = 0;
void setup(){
  Serial.begin(115200);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.drawString(10, 10, "Hello World");
  display.display();
}
void loop(){
  
  display.setColor(BLACK);
  display.drawString(10,10,"Hello World");
  display.fillRect(80,11,100,33);
  display.display();

  val = analogRead(0);
  Serial.println(val);
  
  display.setColor(WHITE);
  display.drawString(10,10,String(val));
  display.display();

  delay(100);
  display.setColor(BLACK);
  display.drawString(10,10,String(val));
  display.display();
}