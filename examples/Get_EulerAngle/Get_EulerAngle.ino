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
    // Euler Angle unit: Angle (Degree)
    // Roll range -180 to 180
    Serial.print("roll=");
    Serial.println(Motion.getRoll());

    // pitch range -90 to 90
    Serial.print("pitch=");
    Serial.println(Motion.getPitch());

    // Yaw range -180 to 180
    Serial.print("yaw=");
    Serial.println(Motion.getYaw());

    delay(250);
}