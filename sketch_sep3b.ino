#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Adafruit_Sensor.h>
#include <OneWire.h>
#include <DallasTemperature.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

#define OLED_RESET -1

Adafruit_SH1106 display(OLED_RESET);
// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);


void setup() {
  sensors.begin();  // Start up the library
  Serial.begin(115200);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  delay(500);
  sensors.requestTemperatures();
  float t = sensors.getTempCByIndex(0);
  //clear display
  display.clearDisplay();

  // display temperature
  // display.setTextSize(1);
  // display.setCursor(0,0);
  // display.println("Temperature:");
  display.setTextSize(3);
  if((t<100)&&(t>0)){
    display.setCursor(14,24);
  }
  else
  {
    display.setCursor(4,24);
  }
  
  display.print(t,1);
  
  
  display.setTextSize(1);
  display.print(" ");
  display.cp437(true);
  display.write(167);
  display.setTextSize(3);
  display.print("C");

  
  display.display(); 
}