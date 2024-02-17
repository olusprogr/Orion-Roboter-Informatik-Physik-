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
}

void loop() {
  /* Run motor1 backward and motor2 forward at the specified speed */
  motor1.run(-100);
  motor2.run(motorspeed);
  delay(500);
  if (ultrasonic.distanceCm() <= 50) {
    motor1.run(-motorspeed);
    motor2.run(10);
    delay(1500);

    if (ultrasonic.distanceCm() <= 20) {
      motor1.stop();
      motor2.run(-motorspeed);
      delay(2000);
      }
  }
  
  motor1.run(-motorspeed);
  motor2.run(100);
  delay(500);
  if (ultrasonic.distanceCm() <= 50) {
    motor1.run(10);
    motor2.run(motorspeed);
    delay(1500);
    
    if (ultrasonic.distanceCm() <= 20) {
      motor1.stop();
      motor2.run(-motorspeed);
      delay(2000);
      }
  }
  

  

  /* Print the distance measured by the ultrasonic sensor in centimeters */
  Serial.print("Distance in cm: ");
  Serial.println(ultrasonic.distanceCm());
}
