#include <MeOrion.h>

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

MeUltrasonicSensor ultrasonic(PORT_7);
MeUltrasonicSensor ultrasonicRightHand(PORT_4);

uint8_t motorspeed = 255;


void setup() {
  Serial.begin(9600);
}

void moveForward(
    int motorSpeed1 = motorspeed,   // default value for motorSpeed is 255
    int motorSpeed2 = motorspeed,   // additional params can be indicated
    unsigned int delayTimeInMs = 0  // default value for delayTimeInMs is 0
    ) {
    motor1.run(-motorSpeed1);
    motor2.run(motorSpeed2);

    if (delayTimeInMs != 0) {delay(delayTimeInMs);}
}

void moveBackward(
    int motorSpeed1 = motorspeed,
    int motorSpeed2 = motorspeed,
    unsigned int delayTimeInMs = 0
    ) {
    motor1.run(motorSpeed1);
    motor2.run(-motorSpeed2);

    if (delayTimeInMs != 0) {delay(delayTimeInMs);}
}

void stopMotors(
    unsigned int delayTimeInMs = 0
    ) {
    motor1.stop();
    motor2.stop();

    if (delayTimeInMs != 0) {delay(delayTimeInMs);}
}

int changeDefaultMotorSpeed(int newMotorSpeed) {
    motorspeed = newMotorSpeed;
    return motorspeed;
}

int getDistance() {
    return ultrasonic.distanceCm();
}

int getDistanceRightHand() {
    return ultrasonicRightHand.distanceCm();
}

void d(unsigned int delayTimeInMs) {
    delay(delayTimeInMs);
}

void loop() {
  while (getDistance() >= 50) {
    moveForward(100, motorspeed, 500);
    moveForward(motorspeed, 100, 500);

    Serial.println(getDistance());
  }

  stopMotors(5000);
}



