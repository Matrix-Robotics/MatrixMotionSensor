#include <MatrixMotionSensor.h>

MatrixMotion Motion;

void setup()
{
    Serial.begin(115200);
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
    // Temperature unit: Degree Celsius
    Serial.print("Temperature=");
    Serial.println(Motion.getTemperature());
    delay(250);
}