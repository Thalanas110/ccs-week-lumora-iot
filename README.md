# **PIR Motion Detection Welcome System** (Simple version)

## **Overview**

This project is an Arduino-based motion detection system designed to provide real-time visual and audio feedback when movement is detected. It uses a Passive Infrared (PIR) sensor to detect motion, an I2C LCD to display messages, an LED for visual indication, and a piezo buzzer to play a short melody. The system is suitable for applications such as automated welcome displays, smart door systems, and event-based interactive setups.

---

## **Features**

* Real-time motion detection using PIR sensor
* Dynamic LCD message display via I2C interface
* LED indicator for motion events
* Melody playback using a piezo buzzer
* Non-blocking timing using `millis()` for smooth operation
* Event-driven system behavior

---

## **Hardware Components**

* Arduino Uno (or compatible board)
* PIR Motion Sensor
* 16x2 I2C LCD Display
* Piezo Buzzer
* LED
* Resistors (as needed)
* Jumper wires

---

## **Pin Configuration**

| Component    | Arduino Pin |
| ------------ | ----------- |
| PIR Sensor   | D10         |
| LED          | D13         |
| Piezo Buzzer | D11         |
| LCD SDA      | A4          |
| LCD SCL      | A5          |

---

## **Installation & Setup**

1. Connect all components according to the pin configuration above.
2. Install required libraries:

   * `Wire.h` (built-in)
   * `LiquidCrystal_I2C.h`
3. Upload the code to the Arduino board using the Arduino IDE.
4. Open the Serial Monitor (9600 baud rate) for debugging output.

---

## **How It Works**

The system continuously monitors the PIR sensor for motion. When motion is detected, the LED is activated, a welcome message is displayed on the LCD, and a melody is played through the buzzer. When motion stops, the system returns to its idle state by turning off the LED, stopping the sound, and resetting the display.

---

## **Project Structure**

```
project-root/
├── src/            — Arduino source code
├── lib/            — required libraries
├── docs/           — documentation and diagrams
└── README.md       — project documentation
```

---

## **Dependencies**

| Library             | Purpose           |
| ------------------- | ----------------- |
| Wire.h              | I2C communication |
| LiquidCrystal_I2C.h | LCD control       |

---

## **Applications**

* Smart door welcome systems
* School or event booth displays
* Basic IoT interaction systems
* Security motion alerts

---

## **Future Improvements**

* Add Wi-Fi module for IoT integration
* Log motion events to a database
* Replace buzzer with voice output module
* Improve LCD UI/UX with animations

---

## **Author**

Developed as part of an IoT-based embedded systems project for CCS week by Team Lumora.


