# 🌱 Arduino-Based Smart Plant Irrigation System

💧 This project is a **smart irrigation system** built with Arduino that automatically waters a plant based on soil moisture levels and displays real-time data on an OLED screen.

---

## 🔧 Components Used

- Arduino Uno/Nano
- Soil Moisture Sensor (Analog)
- Water Pump (with relay or MOSFET driver)
- OLED Display (SSD1306 128x32 I2C)
- Jumper wires, breadboard, external power source for pump

---

## 🧠 How It Works

1. The **soil moisture sensor** reads the current moisture level from the plant's soil.
2. If the moisture is **below a set threshold** (`400` by default), the **water pump is activated** for 5 seconds.
3. The system displays the real-time **moisture readings** on the OLED screen.
4. The loop runs every 60 seconds to check the moisture again.

---

## 🧪 Calibration

- You should calibrate the `moistureThreshold` based on your specific sensor and soil.
- Use `Serial.println(soilMoisture);` during development to monitor the readings and determine the dry/wet thresholds.

---

## 📦 Libraries Required

Make sure to install these libraries from the Arduino Library Manager:
- Adafruit SSD1306
- Adafruit GFX
- Wire (Built-in)

---

## ⚠️ Disclaimer

Use external power (e.g., 5V adapter) to drive the water pump instead of Arduino’s 5V pin to avoid damaging your board.

---

## 🛠️ Future Improvements

- Add DHT11/DHT22 sensor to also monitor humidity and temperature.
- Use a real-time clock (RTC) for scheduled watering.
- Add a buzzer or notification system for critical soil dryness.
