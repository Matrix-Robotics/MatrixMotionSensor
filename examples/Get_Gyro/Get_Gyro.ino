#include <MatrixMotionSensor.h>

MatrixMotion Motion;

void setup()
{
    Serial.begin(115200);
    Serial.print("Starting...\n");
    if (Motion.begin()){
        Serial.println("Matirx Motion Sensor Activated");
    }
    else{
        Serial.println("Matirx Motion Sensor activation failed");
    }
}

void loop()
{
    Serial.println("===============================================================");
    // Gyro unit: degree per second
    Serial.print("gx=");
    Serial.println(Motion.getGyro(x));
    Serial.print("gy=");
    Serial.println( Motion.getGyro(y));
    Serial.print("gz=");
    Serial.println(Motion.getGyro(z));

    delay(250);
}