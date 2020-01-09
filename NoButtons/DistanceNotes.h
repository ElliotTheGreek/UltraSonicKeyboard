/////////////////////////////////////////////
// LIBRARIES
#include <MIDI.h> 
MIDI_CREATE_DEFAULT_INSTANCE();
#include <Thread.h>
#include <ThreadController.h> 

// defines sonic pin numbers
const int trigPin = 9;
const int echoPin = 10;


// defines variables
float duration;
int distance;
int lastNote = -1;
int c = 1;

// using buttons these variables should become controllable
float distanceMin = 3.0;
float distanceMax = 100.0;
float noteSpan = 12;
float lowNote = 36;


ThreadController cpu;
Thread threadReadDistanceNotes;

void setup() {
  // setup the pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(31250); // 115200 for hairless - 31250 for MOCO lufa

  threadReadDistanceNotes.setInterval(10);
  threadReadDistanceNotes.onRun(readDistanceNotes);

  cpu.add(&threadReadDistanceNotes);
}

void loop() {
  cpu.run();
}

float getDistance() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  float duration = pulseIn(echoPin, HIGH);
  // Calculating the distance in centimeters
  return duration*0.034/2;
}


void readDistanceNotes() {
  distance = getDistance();
  if (distance > 2 && distance <= distanceMax) {
// turn our distance into a range from 0.0 to 1.0
    float range = (distance - distanceMin) / (distanceMax - distanceMin);
    if(distance >= distanceMax) {
      range = 1.0;
    }
    if(distance <= distanceMin) {
      range = 0.0;
    }

// get the nearest note at that position add 'lowNote' so we start higher up the keyboard where the fun notes are
    int note = round(lowNote + (range * noteSpan));

// if the note changed turn the last note on and play the new note
    if (lastNote !=  note ){
      if( lastNote != -1) {
        MIDI.sendNoteOff(lastNote, 127, c);
      }
      MIDI.sendNoteOn(note, 127, c);
      lastNote = note;
    }
  } else {
// if we went out of range shut the last note on if there was one
    if( lastNote != -1) {
      MIDI.sendNoteOff(lastNote, 127, c);
    }
    lastNote = -1;
  }
}