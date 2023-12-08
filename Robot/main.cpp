/**
 * Line-Following Robot for mbedLPC1768
 *
 * 
 *
 * @author Andrei Coroama
 * @version 1.0
 */

// Import Libraries
#include "mbed.h"
#include "motordriver.h"

RawSerial  pc(USBTX, USBRX);

// Constants
float SPEED = .4; // Max Speed of Robot
float LINE_THRESHOLD = .8; // Analog IR Value of line
float DIF_THRESHOLD = 0.2; // Difference between left or right sensor with center sensor

// Motor Instantiation
Motor leftMotor(p23, p18, p19, 1); // pwm, fwd, rev, can brake 
Motor rightMotor(p24, p14, p17, 1); // pwm, fwd, rev, can brake

// IR Sensors
AnalogIn leftSensor(p15);
AnalogIn centerSensor(p16);
AnalogIn rightSensor(p20);

// Methods
void findLine();
void checkSensors();
void turnRight();
void turnLeft();
void straight();

// Global Variables
float caliRight = 0; // calibration ratio for right IR sensor
float caliLeft = 0; // calibration ratio for left IR sensor
int prevDir = 0; // prev direction of Robot
float leftDif = 0; // difference between left IR and center IR
float rightDif = 0; // difference between right IR and center IR

float leftSpeed = 0; // varible used in findLine()
float rightSpeed = 0; // varible used in findLine()

int main() {
    // Calibrate Sensors to Center Sensor (Only Necessary with very bad sensors)
    caliRight = centerSensor/rightSensor; // Set equal to 1 if sensors are dependable
    caliLeft = centerSensor/leftSensor; // Set equal to 1 if sensors are dependable
    while (true)
    {
        checkSensors();
        wait_us(1);
    }
}

/**
 * Checks the IR sensors and determines how to move accordingly
 */
void checkSensors() {
    leftDif = leftSensor - centerSensor*caliLeft;
    rightDif = rightSensor*caliRight - centerSensor*caliLeft;

    if (leftDif > DIF_THRESHOLD)
    {
        turnLeft();
    }
    else if (rightDif > DIF_THRESHOLD)
    {
        turnRight();
    }
    else if (leftDif < -DIF_THRESHOLD && rightDif < -DIF_THRESHOLD)
    {
        straight();
    }
    else
    {
        if (centerSensor < LINE_THRESHOLD)
        {
            if (prevDir == 1)
            {
                leftMotor.speed(.4);
                rightMotor.speed(0.1);
            }
            else if (prevDir == -1)
            {
                rightMotor.speed(.4);
                leftMotor.speed(0.1);
            }
        }
        else if (prevDir != 0)
        {
            if (prevDir == -1)
            {
                leftMotor.speed(.4);
                rightMotor.speed(0.1);
            }
            else if (prevDir == 1)
            {
                rightMotor.speed(.4);
                leftMotor.speed(0.1);
            }
        }
        else
        {
            findLine();
        }
    }
}

/**
 * If robot isn't on a line, it systematically searches for a line by spiralling
 * outwards until a line is found.
 */
void findLine() {
    leftDif = 0;
    rightDif = 0;
    leftSpeed = .75;
    rightSpeed = 0;
    for (float s = .1; s < .75 ; s += 0.0000001)
    {
        leftDif = leftSensor*caliLeft - centerSensor;
        rightDif = rightSensor*caliRight - centerSensor;
        if (leftDif < DIF_THRESHOLD && rightDif < DIF_THRESHOLD)
        {
            leftMotor.speed(leftSpeed);
            rightMotor.speed(s);
        }
        else
        {
            break;
        }
    }
}

/**
 * Sets Robot's motors to turn left
 */
void turnLeft() {
    prevDir = -1;
    rightMotor.speed(SPEED);
    leftMotor.speed(SPEED*.75);
    return;
}

/**
 * Sets Robot's motors to turn right
 */
void turnRight() {
    prevDir = 1;
    leftMotor.speed(SPEED);
    rightMotor.speed(SPEED*.75);
    return;
}

/**
 * Sets Robot's motors to go straight
 */
void straight() {
    leftMotor.speed(SPEED);
    rightMotor.speed(SPEED);
    prevDir = 0;
}
