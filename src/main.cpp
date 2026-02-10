#include <Arduino.h>
int fsrPin = A0; // the FSR and 10K pulldown are connected to a0
void setup() {
// write your initialization code here
    Serial.begin(9600);
}

void loop() {
// write your code here
    int fsrReading = analogRead(fsrPin); // the voltage at the junction of the FSR and pulldown

    Serial.println(fsrReading);
    delay(300);
}