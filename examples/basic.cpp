#include <MeOrion.h>

/* Creates two instances of the MeDCMotor class and initialize them with pins M1 and M2 */
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

/* Creates an instance of the MeUltrasonicSensor and initialize them with the port PORT_3,
indicating the connection port of the ultrasonic sensor. */
MeUltrasonicSensor ultrasonic(PORT_3);

/* Initialising the motorspeed */
uint8_t motorspeed = 245;

void setup() {
  /* Initialize serial communication with a baud rate of 9600 */
  Serial.begin(9600);

  int controlMotor(int motor1, int motor2) {
    if (motorspeed < 0 || motorspeed > 250) {
        Serial.print("motorspeed should be in the range [0, 250]");
    } return 0
      
    motor1.run(motor1);
    motor2.run(motor2);
    return 1
}

void loop() {
  /* Run motor1 backward and motor2 forward at the specified speed */
  controlMotor(-240, 240)

  /* Print the distance measured by the ultrasonic sensor in centimeters */
  Serial.print("Distance in cm: ");
  Serial.println(ultrasonic.distanceCm());
  delay(50);

  /* Check if the distance measured by the ultrasonic sensor is less than or equal to 30 cm */
  if (ultrasonic.distanceCm()<= 30) {
    /* If so, run motor1 forward at a speed of 150, stop motor2, and delay for 3 seconds */
    motor1.run(150);
    motor2.stop();
    delay(3000);
  }
}
