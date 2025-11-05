# Arduino Human-Following Robot

This project contains an Arduino sketch for a simple 2WD robot that follows a human or object. It uses two IR sensors for steering (detecting if the object is to the left or right) and an ultrasonic sensor to maintain a set distance from the target.

## 🤖 Features

* **Target Following:** The robot moves forward when a target is detected within a specific range (10-30 cm).
* **Steering:** Uses two IR sensors to steer left or right, keeping the target centered.
* **Obstacle Avoidance:** Moves backward if the target gets too close (less than 10 cm).
* **Idle State:** Stops if the target is too far away or lost.
* **Startup Sequence:** Performs a servo sweep on startup to indicate it's active.

## 🛠️ Hardware Required

* Arduino (UNO, Nano, etc.)
* 2WD Robot Chassis with 2 DC Motors
* H-Bridge Motor Driver (e.g., L298N, L293D)
* 2x IR Proximity Sensors (Digital Out)
* 1x Ultrasonic Sensor (e.g., HC-SR04)
* 1x Micro Servo (e.g., SG90)
* Battery Pack (for motors and Arduino)
* Jumper Wires

## 📦 Libraries

You must install the following libraries in your Arduino IDE:

* [`NewPing`](https://bitbucket.org/teckel12/arduino-newping/wiki/Home) (by Tim Eckel)
* `Servo` (comes pre-installed with the Arduino IDE)

> **Note:** The original code comments mention `AFMotor`. This sketch **does not** use the Adafruit Motor Shield library. It uses direct pin control for a generic H-Bridge driver.

## 🔌 Wiring & Pinout

| Component | Pin | Arduino Pin |
| :--- | :--- | :--- |
| **Ultrasonic Sensor** | `TRIGGER_PIN` | `A1` |
| | `ECHO_PIN` | `A0` |
| **IR Sensor (Right)** | `OUT` | `A2` |
| **IR Sensor (Left)**| `OUT` | `A3` |
| **Servo Motor** | `Signal` | `D10` |
| **Motor Driver** | `IN1` (Motor 1) | `D5` |
| | `IN2` (Motor 1) | `D6` |
| | `IN3` (Motor 2) | `D7` |
| | `IN4` (Motor 2) | `D8` |

*Connect motor driver power inputs to your battery pack and `GND` to Arduino `GND`.*

## ⚙️ How It Works

The logic is based on the state of the two IR sensors and the distance from the ultrasonic sensor.

1.  **Check Sensors:** The robot reads the distance (in cm) and the digital state of the left and right IR sensors.
2.  **Make Decision:**
    * **Target Centered (Move Forward):** If `RIGHT == 1`, `LEFT == 1`, and `10 <= distance <= 30`.
    * **Target on Right (Turn Right):** If `RIGHT == 0` and `LEFT == 1`.
    * **Target on Left (Turn Left):** If `RIGHT == 1` and `LEFT == 0`.
    * **Too Close (Move Backward):** If `1 < distance < 10`.
    * **Stop (Target Lost/Idle):** If `RIGHT == 1`, `LEFT == 1`, and distance is *not* in the "follow" range.

## 🚀 How to Use

1.  Clone or download this repository.
2.  Install the `NewPing` library from the Arduino IDE Library Manager.
3.  Wire your components according to the pinout table above.
4.  Open the `.ino` file in the Arduino IDE.
5.  Select your board and port.
6.  Upload the sketch.

## 👤 Author

* **Media Clashers**
* Youtube: [Media Clashers](https://www.youtube.com/channel/UCHY4RulTk-YcQn4lFOlpA3w)
