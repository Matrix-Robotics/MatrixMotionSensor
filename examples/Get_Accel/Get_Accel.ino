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
    // Accel unit: mm/s^2
    Serial.print("ax=");
    Serial.println(Motion.getAccel(x));
    Serial.print("ay=");
    Serial.println(Motion.getAccel(y));
    Serial.print("az=");
    Serial.println(Motion.getAccel(z));

    delay(250);
}