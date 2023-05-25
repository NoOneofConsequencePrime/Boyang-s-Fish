#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Adafruit_VL53L0X.h>

MPU6050 mpu6050(Wire);
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
VL53L0X_RangingMeasurementData_t meas;

void setup() {
    // pinMode(26, OUTPUT);

    Serial.begin(115200);
    Wire.begin();
    // mpu6050.begin();
    // mpu6050.calcGyroOffsets(true);

    while (!Serial) {delay(1);}
    if (!lox.begin()) {
      Serial.println("Failed to boot");
      while (1);
    }

    Serial.println("Testing");
}

void loop() {
  // mpu6050.update();
  // Serial.println(mpu6050.getAccZ());
  lox.rangingTest(&meas, false);
  if (meas.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(meas.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }
  delay(20);

  // digitalWrite(26, HIGH);
  // delay(100);
  // digitalWrite(26, LOW);
  // delay(100);
  // Serial.println("Running");
}