#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int soilMoisturePin = A0;
const int pumpPin = 13;
const int moistureThreshold = 400; //but it will change according to conditions

void setup() {
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);

  if(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 initialization failed!"));
    for(;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F("Bitki Sulama Sistemi"));
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  int soilMoisture = analogRead(soilMoisturePin);

  display.setTextSize(1);
  display.setCursor(0,0);
  display.print(F("Nem Seviyesi: "));
  display.print(soilMoisture);
  display.display();

  if (soilMoisture < moistureThreshold) {
    digitalWrite(pumpPin, HIGH);
    delay(5000);
    digitalWrite(pumpPin, LOW);
  }

  delay(60000);
  display.clearDisplay();
}

