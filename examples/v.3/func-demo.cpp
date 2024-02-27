#include <MeOrion.h>
#include <map>

using namespace std;

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeUltrasonicSensor ultrasonic(PORT_3);

uint8_t motorspeed = 255;
map<int, int> motorSpeeds = {
    {1, 255},
    {2, 200},
    {3, 150},
    {4, 100},
    {5, 50}
};
map<int, int> delayTimes = {
    {1, 1000},
    {2, 2000},
    {3, 3000},
    {4, 4000},
    {5, 5000}
};

void setup() {
    // optional: Serial.print()
}

void moveForward(
    int motorSpeed1 = motorSpeed,   // default value for motorSpeed is 255
    int motorSpeed2 = motorSpeed,   // additional params can be indicated
    unsigned int delayTimeInMs = 0  // default value for delayTimeInMs is 0
    ) {
    motor1.run(-motorSpeed1);
    motor2.run(motorSpeed2);

    if (delayTimeInMs != 0) {
      delay(delayTimeInMs);
    }
}

void moveBackward(
    int motorSpeed1 = motorSpeed,
    int motorSpeed2 = motorSpeed,
    unsigned int delayTimeInMs = 0
    ) {
    motor1.run(motorSpeed1);
    motor2.run(-motorSpeed2);

    if (delayTimeInMs != 0) {
      delay(delayTimeInMs);
    }
}

void stopMotors(
    unsigned int delayTimeInMs = 0
    ) {
    motor1.stop();
    motor2.stop();

    if (delayTimeInMs != 0) {
      delay(delayTimeInMs);
    }
}

int changeDefaultMotorSpeed(int newMotorSpeed) {
    motorspeed = newMotorSpeed;
    return motorspeed;
}

int getDistance() {
    return ultrasonic.distanceCm();
}

void d(unsigned int delayTimeInMs) {
    delay(delayTimeInMs);
}


void loop() {
    moveForward(100, motorspeed, 500);  // motor1, motor2, delayTimeInMs

    if (getDistance() <= 50) {               // check for distance, if less than 50,
        moveForward(motorspeed, 10, 1500);  // then move forward

        if (getDistance() <= 20) {              // if still less than 20
            moveBackward(0, motorspeed, 2000);  // then move backward
        }
    }
    
    // the same for the other direction
    moveForward(motorspeed, 100, 500);

    if (getDistance() <= 50) {
        moveBackward(motorspeed, 100, 500);

        if (getDistance() <= 20) {
            moveBackward(0, motorspeed, 2000);
        }
    }

    moveForward(motorspeed, motorspeed, 2000);
}
