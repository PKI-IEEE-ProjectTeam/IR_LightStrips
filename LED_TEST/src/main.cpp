#include "FastLED.h"

#define DATA_PIN 3 
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 14 //Number of LEDS
#define BRIGHTNESS 96 

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); //Make sure to delay for at least 3 seconds
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); //Init LEDs
  FastLED.setBrightness(BRIGHTNESS); //Set the brightness for the LEDs
}

/*
Note, not all the colors defined in the FastLED library will be able to be displayed
For example, medium purple will just display white
*/

//Clear all LED's
void ledClear(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(delayTime);
}

//Set all LEDs to a specific color 
void ledSetAll(CRGB crgb) {
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = crgb;
    FastLED.show();
  }
}

// switches on all LEDs. Each LED is shown in random color.
// numIterations: indicates how often LEDs are switched on in random colors
// delayTime: indicates for how long LEDs are switched on.
void showProgramRandom(int numIterations, long delayTime) {
  for (int iteration = 0; iteration < numIterations; ++iteration) {
    for (int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CHSV(random8(),255,255); // hue, saturation, value
    }
    FastLED.show();
    delay(delayTime);
  }
}

// Shifts a single LED from the start of strip to the end.
// crgb: color of shifted pixel
// delayTime: indicates how long the pixel is shown on each LED
void ledShiftToEnd(CRGB crgb, long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = crgb;
    FastLED.show();
    delay(delayTime);
    leds[i] = CRGB::Black;
  }
}

//Shifts a single LED from the end of the strip to the start
// crgb: color of shifted LED
// delayTime: indicates how long the pixel is shown on each LED
void ledShiftToStart(CRGB crgb, long delayTime) {
  for (int i = NUM_LEDS; i >= 0; --i) {
    leds[i] = crgb;
    FastLED.show();
    delay(delayTime);
    leds[i] = CRGB::Black;
  }
}

void ledShiftDown(int n) {

  for (int i = NUM_LEDS - 1; i > 0; i--) {
    leds[i] = leds[i-1];
  };
}

//Makes a single LED blibk
//crgb: color of the LED
//ledPosition: which LED is blinked
//delayTime: indicates how fast the blink is
//Delay is called twice, once for high, once for low
void ledBlink(CRGB crgb, int ledPosition, long delayTime) {
  leds[ledPosition] = crgb;
  FastLED.show();
  delay(delayTime);
  leds[ledPosition] = CRGB::Black;
  FastLED.show();
  delay(delayTime);
}

//Sets a single LED
//crgb: color of the LED
//ledPosition: which LED is set
void ledSet(CRGB crgb, int ledPosition) {
  leds[ledPosition] = crgb;
  FastLED.show();
}

//Clears a single LED
//ledPosition: which LED is cleared
void ledClear(CRGB crgb, int ledPosition) {
  leds[ledPosition] = CRGB::Black;
  FastLED.show();
}

//Sets LEDs in a range
//crgb: color of the set LEDs
//ledStart: start of the range
//ledEnd: end of range
void ledSetRange(CRGB crgb, int ledStart, int ledEnd) {
  for (int i = ledStart; i <= ledEnd; ++i) {
    leds[i] = crgb;
    FastLED.show();
  }
}

//Clears LEDs in a range
//ledStart: start of the range
//ledEnd: end of range
void ledClearRange(int ledStart, int ledEnd) {
  for (int i = ledStart; i <= ledEnd; ++i) {
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}

void ledBlinkRange(CRGB crgb, int ledStart, int ledEnd, long delayTime) {
  for (int i = ledStart; i <= ledEnd; ++i) {
      leds[i] = crgb;
      FastLED.show();
  }

  delay(delayTime);
  for (int i = ledStart; i <= ledEnd; ++i) {
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  delay(delayTime);
}


void ledBlinkAll(CRGB crgb, long delayTime) {
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = crgb;
    FastLED.show();
  }
  delay(delayTime);
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  delay(delayTime);
}


// Shifts multiple pixel from the start of strip to the end. The color of each pixel is randomized.
// delayTime: indicates how long the pixels are shown on each LED
void showProgramShiftMultiPixel(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) { 
    for (int j = i; j > 0; --j) {
      leds[j] = leds[j-1];
    }
    CRGB newPixel = CHSV(random8(), 255, 255);
    leds[0] = newPixel;
    FastLED.show();
    delay(delayTime);
  }
}
//Rotates the led array left n times
void ledLeftRotate(int n) {
    n %= NUM_LEDS;
  
    CRGB temp[NUM_LEDS];

    for (int i = 0; i < NUM_LEDS - n; i++)
        temp[i] = leds[n + i];

    for (int i = 0; i < n; i++)
        temp[NUM_LEDS - n + i] = leds[i];

    for (int i = 0; i < NUM_LEDS; i++)
        leds[i] = temp[i];

    FastLED.show();
}

//Rotates the led array right n times
void ledRightRotate(int n) {
  int m = NUM_LEDS - n;
  ledLeftRotate(m);
}

// main program
void loop() {

  //Some example code

  ledClear(2500); // clean up
  showProgramRandom(100, 100); // show "random" program
  
  ledClear(2500); // clean up
  showProgramRandom(10, 1000); // show "random" program
  
  ledClear(2500); // clean up
  ledShiftToEnd(CRGB::Blue, 250); // show "shift single pixel from start to end" with blue pixel
  
  ledClear(2500); // clean up
  ledShiftToStart(CRGB::Maroon, 100); // show "shift a single pixel from end to start" with maroon pixel

  ledClear(2500); // clean up

  ledSetAll(CRGB::Purple);  //making it all purple
  ledShiftToEnd(CRGB::Red, 100); // show "shift a single pixel from end to start" with red pixel

  ledClear(2500); // clean up
  showProgramShiftMultiPixel(500); // show "shift multi pixel" program
  
  ledClear(2500); // clean up
  showProgramShiftMultiPixel(50); // show "shift multi pixel" program

  ledClear(2500); // clean up
  ledBlinkAll(CRGB::Green, 250); //Blink everything green
  ledClear(100);
  ledBlinkRange(CRGB::Yellow, 3, 5, 250); //Blink LEDs 3 through 5 yellow
  ledClear(2500); // clean up

  ledSetRange(CRGB::Orange, 2, 5); //Set LEDs 3 through 5 Orange
  delay(500); 
  ledClearRange(3, 4); //Clear LEDs 3 and 4
  delay(500);
  ledClear(2500); //clean up

  //Crimmas lights
  //Set odd numbered LEDs to green
  for (int i = 0; i <= NUM_LEDS; i = i + 2) {
    ledSet(CRGB::Green, i);
  }

  //Set odd numbered LEDs to red
   for (int i = 1; i <= NUM_LEDS; i = i + 2) {
    ledSet(CRGB::Red, i);
  }

  //Rotate!
  for (int i = 0; i <= 10; i++) {
    delay(500);
    ledLeftRotate(1);
  }

  ledClear(2500); 

}