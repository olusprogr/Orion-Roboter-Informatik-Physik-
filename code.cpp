#include <MeOrion.h>

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

MeUltrasonicSensor ultrasonic(PORT_3);

uint8_t motorspeed = 245;

void setup() {
  Serial.begin(9600);
}

void loop() {
  motor1.run(-motorspeed);
  motor2.run(motorspeed);
  
  Serial.print("Distance in cm:");
  Serial.println(ultrasonic.distanceCm());
  delay(50);

  if (ultrasonic.distanceCm()<= 30) {
    motor1.run(150);
    motor2.stop();
    delay(3000);
  }
}
