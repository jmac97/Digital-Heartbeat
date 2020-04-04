#import <Arduino.h>

class Beat {
    float pause;
    unsigned long current;
    unsigned long previous;
    int pin;
    float bpm;
    
  public:
    Beat(float bpm_, int pin_) {
      pin = pin_;
      bpm = bpm_;
      previous = 0;
      pause = ((1000 / ((bpm / 60) * 1000)) * 1000) - 275;
      pinMode(pin, OUTPUT);
    }

    void lubDub() {
      current = millis();

      if (current - previous <= pause) {
        analogWrite(pin, 0);
      }

      if (current - previous > pause && current - previous <= pause + 100) {
        analogWrite(pin, 200);
      }

      if (current - previous > pause + 100 && current - previous <= pause + 200) {
        analogWrite(pin, 0);
      }

      if (current - previous > pause + 200 && current - previous <= pause + 275) {
        analogWrite(pin, 255);
      }

      if (current - previous > pause + 275) {
        previous = current;
      }
    }
};
