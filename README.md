# LineFollowingRobot
Built with the mbed LPC1768, this line-following robot uses IR sensors to find and track a line on the floor.
## Introduction
The goal of this project is to have a robot seek a line and follow it. In order to do this, 3 analog IR sensors are used: left, center, and right. The idea behind a line-following robot is when the left sensor is over the line, the robot must turn left. If the right sensor is over the line, it must turn right. If the center sensor is over the line, it goes straight. This project however uses a slightly different approach to account for inconsistencies in the IR reflectivity of the floor's surface.

## Coponents
- mbed LPC1768
- SparkFun Motor Driver - Dual TB6612FNG
- 2 DC Brushless Motors (ROB-13302)
- 2 Wheels
- 3 SparkFun RedBot Sensor - Line Follower
- 5V power supply
