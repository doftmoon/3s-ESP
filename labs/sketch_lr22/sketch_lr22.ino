#include <Servo.h>

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