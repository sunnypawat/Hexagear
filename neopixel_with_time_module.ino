#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN        11
#define NUMPIXELS 61
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int once_0[] = {24, 25, 28, 30, 40, 42, 45, 47, 54, 55};
const int once_1[] = {25, 29, 41, 46, 54};
const int once_2[] ={24, 25, 28, 40, 41, 42};
const int once_3[] ={24, 25, 28, 41, 42, 45, 47, 54, 55};
const int once_4[] ={24, 28, 30, 41, 42, 45, 55};
const int once_5[] ={24, 25, 28, 30, 41, 45, 47, 54, 55};
const int once_6[] ={24, 25, 28, 30, 40, 41, 45, 47, 54, 55};
const int once_7[] ={24, 25, 28, 41, 42, 45, 55};
const int once_8[] ={24, 25, 28, 30, 40, 41, 42, 45, 47, 54, 55};
const int once_9[] ={24, 25, 28, 30, 41, 42, 45, 47, 54, 55};

const int * onceNumber[] = {
  once_0,
  once_1,
  once_2,
  once_3,
  once_4,
  once_5,
  once_6,
  once_7,
  once_8,
  once_9,
};

const unsigned short onceSizes[] = {
    sizeof(once_0)/sizeof(once_0[0]),
    sizeof(once_1)/sizeof(once_1[0]),
    sizeof(once_2)/sizeof(once_2[0]),
    sizeof(once_3)/sizeof(once_3[0]),
    sizeof(once_4)/sizeof(once_4[0]),
    sizeof(once_5)/sizeof(once_5[0]),
    sizeof(once_6)/sizeof(once_6[0]),
    sizeof(once_7)/sizeof(once_7[0]),
    sizeof(once_8)/sizeof(once_8[0]),
    sizeof(once_9)/sizeof(once_9[0]),
};

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif  
  pixels.begin();
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(0,150,0));
  pixels.show();
}

void loop() {
  tmElements_t tm;
  pixels.clear();
  
  if (RTC.read(tm)) {
    Serial.print("Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.write('\n');
    for(int i = 0; i < onceSizes[tm.Second%10]; i++) {
      pixels.setPixelColor(onceNumber[tm.Second%10][i]-1, pixels.Color(0,150,0));
    }
    pixels.show();
   
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
  delay(1000);
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}
