#include "SmartLight.h"


void setup() {
    SmartLight SMTask = SmartLight(13, 12, 11, 1000);

    Serial.begin(9600);
    Serial.println("Hello World!");
}

void loop() {

}