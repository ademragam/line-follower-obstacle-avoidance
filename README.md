# Line Follower & Obstacle Avoidance Robot 🤖

This project is an Arduino-based robot that follows a black line using IR sensors and avoids obstacles using an ultrasonic sensor.

## Features
- Line following with two IR sensors
- Obstacle detection using an ultrasonic sensor
- Automatic switching between line following and obstacle avoidance
- Simple and readable Arduino code

## Hardware Used
- Arduino Uno
- Motor driver (e.g. L298N)
- 2x DC motors
- 2x IR line sensors
- Ultrasonic sensor (HC-SR04)

## How It Works
- If no obstacle is detected, the robot follows the line.
- If an obstacle is detected, the ultrasonic mode is activated to avoid collisions.

## Picture

<img width="316" height="423" alt="Screenshot 2025-05-01 124953" src="https://github.com/user-attachments/assets/759d0a5e-d4d3-4ec9-9aaa-b122c815132d" />


## Setup
1. Upload the `.ino` file to the Arduino.
2. Connect the sensors and motors according to the code.
3. Open the Serial Monitor (9600 baud) to view sensor values.

## Learning Outcome
This project helped me understand sensor-based navigation, basic robotics logic, and structured Arduino programming.

## Author
Adem Ragam
