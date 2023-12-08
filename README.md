# LineFollowingRobot
Built with the mbed LPC1768, this line-following robot uses IR sensors to find and track a line on the floor.
## Introduction
The goal of this project is to have a robot seek a line and follow it. In order to do this, 3 analog IR sensors are used: left, center, and right. The idea behind a line-following robot is when the left sensor is over the line, the robot must turn left. If the right sensor is over the line, it must turn right. If the center sensor is over the line, it goes straight. This project however uses a slightly different approach to account for inconsistencies in the IR reflectivity of the floor's surface.
### Line_Following Methodoligy
Since it is possible to run into the issue of inconsisten IR reflectivity in the surface the robot is on, a different line-following method is proposed.
After all sensors have been calibrated by resetting robot on a blank white surface, the difference between the left and right sensors compared to the center sensor will be recorded. 
##### note that there must be a set lineThreshold (for what the IR sensors read when over the line) and DifThreshold (for when \n      either the center or (left or right) sensors is over the line)
The following cases are listed:
1. LeftDifference > DifThreshold
   - turnLeft
1. RightDiffernce > DifThreshold
   - turnRight
1. CenterSensor > LineThreshold
1. 
3. _
## Coponents
- mbed LPC1768
- SparkFun Motor Driver - Dual TB6612FNG
- 2 DC Brushless Motors (ROB-13302)
- 2 Wheels
- 3 SparkFun RedBot Sensor - Line Follower
- 5V power supply
