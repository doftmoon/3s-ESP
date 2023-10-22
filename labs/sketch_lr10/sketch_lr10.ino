const int LED=13;
const int LDR=0;
const int Poti=1;
int cnt=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(LDR) > analogRead(Poti)) {
    cnt=0;
  }
  if(analogRead(LDR) < analogRead(Poti)) {
    cnt++;
  }

  if(cnt>300) {
    digitalWrite(LED, HIGH);
    
    do {
      delay(5000);
    } while(analogRead(LDR) < analogRead(Poti));
    cnt=0;
    digitalWrite(LED, LOW);
  }

  delay(10);
}
