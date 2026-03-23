# Burka-s-Repo

# Smart Blind Stick 🦯

An Arduino-based assistive device designed for the visually impaired to detect obstacles and ground hazards in real-time.

## 🚀 How it Works
* Forward Sensor: Detects waist-level obstacles (walls, people). Alerts with short, sharp beeps.
* Ground Sensor: Detects stairs and drops. Alerts with long, slow beeps.

## 🛠 Hardware
* Arduino Uno/Nano
* 2x HC-SR04 Ultrasonic Sensors
* 1x Active Buzzer

## 🔌 Pin Configuration
| Component | Trig Pin | Echo Pin |
| :--- | :--- | :--- |
| Forward Sensor | 2 | 3 |
| Ground Sensor | 4 | 5 |
| Buzzer | 9 | - |

## ⚙️ Usage
Upload the code to your Arduino using the Arduino IDE.
