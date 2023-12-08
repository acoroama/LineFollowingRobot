# LineFollowingRobot
Built with the mbed LPC1768, this line-following robot uses IR sensors to find and track a line on the floor.
## Introduction
The goal of this project is to have a robot seek a line and follow it. In order to do this, 3 analog IR sensors are used: left, center, and right. The idea behind a line-following robot is when the left sensor is over the line, the robot must turn left. If the right sensor is over the line, it must turn right. If the center sensor is over the line, it goes straight. This project however uses a slightly different approach to account for inconsistencies in the IR reflectivity of the floor's surface.
### Line-Following Methodology
Since it is possible to run into the issue of inconsisten IR reflectivity in the surface the robot is on, a different line-following method is proposed.
After all sensors have been calibrated by resetting robot on a blank white surface, the difference between the left and right sensors compared to the center sensor will be recorded.
##### note that there must be a set lineThreshold (for what the IR sensors read when over the line) and DifThreshold (for when \n      either the center or (left or right) sensors is over the line)
The following cases are listed:
1. LeftDifference > DifThreshold
   - turnLeft
1. RightDiffernce > DifThreshold
   - turnRight
1. CenterSensor > LineThreshold
   - straight
1. (abs(LeftDifference) < LineThreshold) && (abs(RightDifference) < LineThreshold)
   - findLine
With these cases, the robot should be able to follow any relatively simple line tracks.
## Coponents
To replicate this project, the following parts are required:
- mbed LPC1768
- SparkFun Motor Driver - Dual TB6612FNG
- 2 DC Brushless Motors (ROB-13302)
- 2 Wheels
- 3 SparkFun RedBot Sensor - Line Follower
- 5V power supply
- chasis to hold all the parts (Sparkfun RedBot robot chasis used in this case)
## Wiring
Connect the components in the following maner:
### Motors

| Dual Motor Driver Breakout  | Left Motor |
| ------------- | ------------- |
| A01  | Pos  |
| A02  | Neg  |

| Dual Motor Driver Breakout  | Right Motor |
| ------------- | ------------- |
| B01  | Pos  |
| B02  | Neg  |

### Motor Driver
| Dual Motor Driver Breakout  | Mbed LPC1768 | 5V |
| ------------- | ------------- | --- |
| VCC | VOUT | NC |
| NC | VIN | Pos |
| VM | NC | Pos |
| GND | GND | GND |
| PWMA | p23 | NC |
| AI1 | p18 | NC |
| AI2 | p19 | NC |
| PWMB | p24 | NC |
| BI1 | p17 | NC |
| BI2 | p14 | NC |
| STBY | VOUT | NC |

 
