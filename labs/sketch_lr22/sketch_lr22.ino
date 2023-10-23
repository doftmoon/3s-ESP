#include <Servo.h>

const int MAX_L=900;
const int MIN_L=200;
const int FR=0;
int val;
int angle;

Servo myServo;
void setup()
{
 // attach serv to pin 9
 myServo.attach(9);
}

void loop()
{
 val = analogRead(FR);

 val = map(val, MIN_L, MAX_L, 180, 0);
 angle = constrain(val, 0, 180);

 myServo.write(angle);
}