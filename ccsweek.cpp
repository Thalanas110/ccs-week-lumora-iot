/*
 * PIR Motion Sensor with I2C LCD and Low-Tone Piezo
 * PIR Trigger: Pin 10
 * Piezo Buzzer: Pin 11
 * LCD SDA: A4
 * LCD SCL: A5
 */

#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// for some dumb reason the lcd is at 0x27, so we initialize at 0x27 instead
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pirPin = 10;
const int ledPin = 13;
const int piezoPin = 11;

int sensorState = LOW;
int val = 0;

// main melody notes
#define NOTE_C4 262
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3,
  NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4,
  4, 4, 4, 4
};

int currentNote = 0;
unsigned long previousNoteTime = 0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);

  Serial.begin(9600); // 30 ms delay for start warmups

  // Initialize the LCD and turn on the backlight
  lcd.init();
  lcd.backlight();

  Serial.println("System Ready.");

  // Print the ready state
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Detecting Motion"); // trimmed to 16 chars
}

void loop() {
  val = digitalRead(pirPin);

  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);

    if (sensorState == LOW) {
      Serial.println("Motion detected!");
      toneSong();
      updateMovementDisplay();   // runs continuously while motion is detected
      delay(100);
      sensorState = HIGH;
    }
  }
  else {
    digitalWrite(ledPin, LOW);

    noSong();

    if (sensorState == HIGH) {
      Serial.println("Motion ended.");
      updateStillDisplay();
      sensorState = LOW;
    }
  }
}

// function that gets triggered when motion is detected.
void updateMovementDisplay() {
  lcd.setCursor(0, 0);
  lcd.print("MOVEMENT FOUND!!");
  lcd.setCursor(0, 1);
  lcd.print("Welcome, GCians!");
}

// when movement is no longer detected afterwards
void updateStillDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Detecting Motion"); // replace with something much better
}

// function for song.
// replace the tone with the necessary tone.
// gagawin ni aliana
void toneSong() {
  unsigned long currentTime = millis();
  int noteDuration = 1000 / noteDurations[currentNote];
  int pauseBetweenNotes = noteDuration * 1.30; // standard 30% gap between notes

  if (currentTime - previousNoteTime >= pauseBetweenNotes) {
    previousNoteTime = currentTime;

    if (melody[currentNote] != 0) {
      tone(piezoPin, melody[currentNote], noteDuration);
    } 
    else {
      noTone(piezoPin); // explicit rest on 0-frequency notes
    }

    currentNote++;
    if (currentNote >= 8) {
      currentNote = 0;
    }
  }
}

void noSong() {
  // Stop the tone when motion ends
  noTone(piezoPin);
}