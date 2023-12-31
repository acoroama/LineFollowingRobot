# LineFollowingRobot by Andrei Coroama
Built with the mbed LPC1768, this line-following robot uses IR sensors to find and track a line on the floor.
## Introduction
The goal of this project is to have a robot seek a line and follow it. In order to do this, 3 analog IR sensors are used: left, center, and right. The idea behind a line-following robot is when the left sensor is over the line, the robot must turn left. If the right sensor is over the line, it must turn right. If the center sensor is over the line, it goes straight. This project however uses a slightly different approach to account for inconsistencies in the IR reflectivity of the floor's surface.

![Sensors](https://github.com/acoroama/LineFollowingRobot/assets/101741705/b206ca70-4034-46da-a285-89376289747f)

### Line-Following Methodology
Since it is possible to run into the issue of inconsistent IR reflectivity in the surface the robot is on, a different line-following method is proposed.
After all sensors have been calibrated by resetting robot on a blank white surface, the difference between the left and right sensors compared to the center sensor will be recorded.
##### note that there must be a set lineThreshold (for what the IR sensors read when over the line) and DifThreshold (for when \n      either the center or (left or right) sensors is over the line)
The following cases are listed:
1. LeftDifference > DifThreshold
   - turnLeft
1. RightDiffernce > DifThreshold
   - turnRight
1. CenterSensor > LineThreshold
   - straight
1. (abs(LeftDifference) < DifThreshold) && (abs(RightDifference) < DifThreshold)
   - findLine
#### With these cases, the robot should be able to follow any relatively simple line track.
## Coponents
To replicate this project, the following parts are required:
- Mbed LPC1768
- SparkFun Motor Driver - Dual TB6612FNG
- 2 DC Brushless Motors (ROB-13302)
- 2 Wheels
- 3 SparkFun RedBot Sensor - Line Follower
- 5V power supply
- Chasis to hold all the parts (Sparkfun RedBot robot chasis used in this case)
## Wiring
Connect the components in the following manner:

![lpc1768_pinout](https://github.com/acoroama/LineFollowingRobot/assets/101741705/1bac0fe0-1f45-47a8-a63c-082263e49bea)

### Motors

![Motors](https://github.com/acoroama/LineFollowingRobot/assets/101741705/8d7d18a9-5e0e-4e6e-8a2f-4ff8c8701292)

| Dual Motor Driver Breakout  | Left Motor |
| :---: | :---: |
| A01  | Pos  |
| A02  | Neg  |

| Dual Motor Driver Breakout  | Right Motor |
| :---: | :---: |
| B01  | Pos  |
| B02  | Neg  |

### Motor Driver

![Motor_Driver](https://github.com/acoroama/LineFollowingRobot/assets/101741705/c1584ab2-4235-4bd4-952a-e5450e63cc8c)

| Dual Motor Driver Breakout  | Mbed LPC1768 | 5V |
| :---: | :---: | :---: |
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

### IR Sensors

![IR_Sensor](https://github.com/acoroama/LineFollowingRobot/assets/101741705/635a1f5f-e565-4a6c-9adb-5eee79bb2827)

| Mbed LPC1768  | Left Sensor | 
| :---: | :---: |
| p15 | OUT |
| VOUT | VCC |
| GND  | GND |

| Mbed LPC1768  | Center Sensor | 
| :---: | :---: |
| p16 | OUT |
| VOUT | VCC |
| GND  | GND |

| Mbed LPC1768  | Right Sensor | 
| :---: | :---: |
| p20 | OUT |
| VOUT | VCC |
| GND  | GND |

Here is an image of robot completely wired up:

![Wiring](https://github.com/acoroama/LineFollowingRobot/assets/101741705/4a8db695-ecec-4f33-b729-c9ea83d047b9)

## Project Demonstration
Here is a youtube [link](https://youtube.com/shorts/89yhff2wmAQ?feature=share) demonstrating the line-following capabilities of the robot.



 
