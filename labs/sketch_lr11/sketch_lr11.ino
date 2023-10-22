//секундомер
#define FIRST_SEGMENT_PIN 2
#define SEGMENT_COUNT 7

byte numberSegments[10] = {
  0b00111111, 0b00001010, 0b01011101, 0b01011110, 0b01101010,
  0b01110110, 0b01110111, 0b00011010, 0b01111111, 0b01111110,
};

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i < SEGMENT_COUNT; ++i) {
    pinMode(i + FIRST_SEGMENT_PIN, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int number = (millis() / 1000) % 10;
  int mask = numberSegments[number];

  for(int i = 0; i < SEGMENT_COUNT; ++i) {
    boolean enableSegment = bitRead(mask, i);
    digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
  }
}
