#include <MatrixMotionSensor.h>

MatrixMotion Motion;

void setup()
{
    Serial.begin(115200);
    Serial.print("Starting...\n");
    if (Motion.begin()){
        Serial.print("Motion Sensor Activated");
    };
}

void loop()
{
    Serial.println("===============================================================");
    // Temperature unit: Degree Celsius
    Serial.print("Temperature=");
    Serial.println(Motion.getTemperature());
    delay(200);
}