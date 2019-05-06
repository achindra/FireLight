/*
 * FireLight
 * This code generates fireplace like light effect
 * 
 * Chip: ATTiny85
 */

int elapsedTimeSinceOn = 0;
int lastFlickerDelay = 10;
int torchLED_pin = 0;


void realFire() {
  int brightness = random(10);
  int duration = random(10);

  switch (brightness) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      analogWrite(torchLED_pin, random(120) + 50);
      break;
    case 6:
    case 7:
      analogWrite(torchLED_pin, random(120) + 85);
      break;
    case 8:
    case 9:
      analogWrite(torchLED_pin, random(120) + 135);
      break;
  }

  switch (duration) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      lastFlickerDelay = 100;
      break;
    case 5:
    case 6:
      lastFlickerDelay = 200;
      break;
    case 7:
    case 8:
      lastFlickerDelay = 500;
      break;
    case 9:
      lastFlickerDelay = 50;
      break;
  }

}

void setup() {
  pinMode(0, OUTPUT); //LED on Model B
  pinMode(1, OUTPUT); //LED on Model A  or Pro
  pinMode(4, OUTPUT);
  elapsedTimeSinceOn = millis();
}

void loop() {
  analogWrite(4, random(80) + 35);
  analogWrite(0, random(120) + 135);
  analogWrite(1, random(120) + 135);
  delay(random(100));
  if ((elapsedTimeSinceOn % lastFlickerDelay) == 0) {
    // let's make the torch flicker
    realFire();
    delay(random(100));
  }
}
