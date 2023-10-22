//светофор
const int LEDrot=12;
const int LEDgelb=11;
const int LEDgruen=10;
int cnt=0;
int state=0;
char mode;

void setup() {
  pinMode(LEDrot, OUTPUT);
  pinMode(LEDgelb, OUTPUT);
  pinMode(LEDgruen, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) { 
  mode = Serial.read();
  
  State(mode);
  delay(11111);
  }

  // if (mode == "N")
  // cnt++;
  // if(cnt==100) {
  //   cnt=0;
  //   Statemaschine();
  // }

  // delay(10);
}

void State(char mode) {
  switch(mode) {
    case 'R': {
      digitalWrite(LEDrot, HIGH);
      digitalWrite(LEDgelb, LOW);
      digitalWrite(LEDgruen, LOW);
      Serial.println("Включён режим red");
      break;
    }
    case 'G': {
      digitalWrite(LEDrot, LOW);
      digitalWrite(LEDgelb, LOW);
      digitalWrite(LEDgruen, HIGH);
      Serial.println("Включён режим green");
      break;
    }
  }
}

void Statemaschine(void) {
  switch(state) {
    case 0: {
      digitalWrite(LEDrot, LOW);
      digitalWrite(LEDgelb, LOW);
      digitalWrite(LEDgruen, LOW);
      break;
    }
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