//конечный автомат

const int LEDrot=12;
const int LEDgelb=11;
const int LEDgruen=10;
int cnt=0;
int state=1;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDrot, OUTPUT);
  pinMode(LEDgelb, OUTPUT);
  pinMode(LEDgruen, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  cnt++;
  if(cnt==100) {
    cnt=0;
    Statemaschine();
  }

  delay(10);
}

void Statemaschine(void) {
  switch(state) {
    case 1: {
      digitalWrite(LEDrot, HIGH);
      digitalWrite(LEDgelb, LOW);
      digitalWrite(LEDgruen, LOW);
      state++;
      break;
    }
    case 2: {
      digitalWrite(LEDrot, HIGH);
      digitalWrite(LEDgelb, HIGH);
      digitalWrite(LEDgruen, LOW);
      state++;
      break;
    }
    case 3: {
      digitalWrite(LEDrot, LOW);
      digitalWrite(LEDgelb, LOW);
      digitalWrite(LEDgruen, HIGH);
      state++;
      break;
    }
    case 4: {
      digitalWrite(LEDrot, LOW);
      digitalWrite(LEDgelb, HIGH);
      digitalWrite(LEDgruen, LOW);
      state=1;
      break;
    }
  }
}
