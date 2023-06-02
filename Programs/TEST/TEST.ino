#include <Adafruit_MotorShield.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <utility/Adafruit_PWMServoDriver.h>

MPU6050 mpu6050(Wire);
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *TankB = AFMS.getMotor(1);
Adafruit_DCMotor *TankF = AFMS.getMotor(2);
Adafruit_DCMotor *PumpL = AFMS.getMotor(3);
Adafruit_DCMotor *PumpR = AFMS.getMotor(4);

void setup() {
    Serial.begin(115200);
    while (!Serial) {delay(1);}
    Wire.begin();
    AFMS.begin();
    // mpu6050.begin();
    // mpu6050.calcGyroOffsets(true);
    // ca = mpu6050.getAccZ();

    Serial.println("Testing");
    delay(5000);
}

void fillTanks(float iSpd) {
  int spd = iSpd*255;
  if (spd > 0) {
    TankF -> setSpeed(spd); TankF -> run(FORWARD);
    TankB -> setSpeed(spd); TankB -> run(FORWARD);
  } else if (spd < 0) {
    TankF -> setSpeed(-spd); TankF -> run(BACKWARD);
    TankB -> setSpeed(-spd); TankB -> run(BACKWARD);
  } else {
    TankF -> setSpeed(0); TankF -> run(RELEASE);
    TankB -> setSpeed(0); TankB -> run(RELEASE);
  }
}

void driveL(float iSpd) {
  int spd = iSpd*255;
  if (spd > 0) {
    PumpL -> setSpeed(spd); PumpL -> run(FORWARD);
  } else {
    PumpL -> setSpeed(0); PumpL -> run(RELEASE);
  }
}

void driveR(float iSpd) {
  int spd = iSpd*255;
  if (spd > 0) {
    PumpR -> setSpeed(spd); PumpR -> run(FORWARD);
  } else {
    PumpR -> setSpeed(0); PumpR -> run(RELEASE);
  }
}

void loop() {
  fillTanks(0);
  driveL(0);
  driveR(0);

  delay(50000);
  driveL(1);
  delay(4000);
  driveL(0); driveR(1);
  delay(4000);
  driveR(0);
  delay(120000);

  // delay(50000);
  // fillTanks(1);
  // delay(30000);
  // fillTanks(0);
  // delay(5000);
  // driveL(1); driveR(1);
  // delay(5000);
  // driveL(0); driveR(0);
  // delay(10000);
  // fillTanks(-1);
  // delay(30000);
  // fillTanks(0);
  // delay(120000);

  // delay(50000);
  // fillTanks(1);
  // delay(32000);
  // fillTanks(0);
  // delay(10000);
  // fillTanks(-1);
  // delay(30000);
  // fillTanks(0);
  // delay(120000);

  // delay(50000);
  // driveL(1);
  // driveR(1);
  // delay(5000);
  // driveL(0);
  // driveR(0);
  // delay(120000);

  // delay(50000);
  // driveL(1);
  // delay(3000);
  // driveL(0);
  // driveR(1);
  // delay(3000);
  // driveR(0);
  // delay(120000);

  // mpu6050.update();
  // Serial.print("AccZ:");
  // Serial.println(mpu6050.getAccZ());
  // a = mpu6050.getAccZ()-ca;
  // d += a/0.02;
  // Serial.println(d);
  delay(20);

}