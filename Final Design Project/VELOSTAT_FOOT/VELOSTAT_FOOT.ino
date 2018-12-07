#include <Adafruit_NeoPixel.h>

// analog input pin that the Velostat is connected to

const int analogInPin1 = A5;
const int analogInPin2 = A4;
const int numLEDs = 26;

// value read from the Velostat
int frontPad1 = 0;
int backPad2 = 0;    

int fMAX, fMIN, fDIFF, fTRIG, fNORM;  // front pad variables 
int bMIN, bMAX, bDIFF, bTRIG, bNORM;  // back pad variables 
   
#define PIN A3 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLEDs, PIN, NEO_GRB + NEO_KHZ800);
// how to use the strip:  Adafruit_NeoPixel(number of pixels in strip, pin number, pixel type flags);

void setup() {
  
  strip.begin();
  strip.show();           // init pixels to 'off'
  
  Serial.begin(9600);

  // init Analog Pin as PULLUP (meaning it sends out voltage)
  digitalWrite(analogInPin1, HIGH);
  digitalWrite(analogInPin2, HIGH);


  for (int i = 0; i < numLEDs; i++) {
        strip.setPixelColor(i, 10, 10, 10);
        strip.show();
        delay(100);
  }
  for (int i = 0; i < numLEDs; i++) {
        int currBack = analogRead(analogInPin2);
        int currFront = analogRead(analogInPin1);
        
        if(currBack > bMAX) { bMAX = currBack; }
        if(currBack < bMIN) { bMIN = currBack; }
        if(currFront > fMAX) { fMAX = currFront; }
        if(currFront < fMIN) { fMIN = currFront; }
        strip.setPixelColor(i, 0, 0, 100);
        strip.show();
        delay(500);
  }

  fDIFF = fMAX - fMIN;
  bDIFF = bMAX - bMIN;
  fNORM = (bDIFF / fDIFF);
  bNORM = (fDIFF / bDIFF);
  fTRIG = (fMAX - (fDIFF / 2)) * fNORM;
  bTRIG = (bMAX - (bDIFF / 2)) * bNORM;



  for (int i = 0; i < numLEDs; i++) {
      strip.setPixelColor(i, 10, 10, 10);
      strip.show();
      delay(50);
   }
}

void loop() {

  // baseline readings with analog readings subtracted
  int fREAD = analogRead(analogInPin1) * fNORM;
  int bREAD = analogRead(analogInPin2) * bNORM;

  // CODE THAT TELLS US WHERE THE AVG AMOUNT OF PRESSURE IS
  //  If the avg amount of pressure is on back of foot -> bad 
  // Otherwise -> good
    
  int b = 0; // boolean int
  int counter = 0;
  int avgF = 0;
  int avgB = 0;
    
  while(fTRIG > fREAD || bTRIG > bREAD) {
    Serial.println(counter);
    b = 1;
    counter++;
    fREAD = analogRead(analogInPin1) * fNORM;
    bREAD = analogRead(analogInPin2) * bNORM;
    
    avgF += fREAD;
    avgB += bREAD;
  }
    
  if(b == 1) {
    
    b = 0;
     
    avgF = (avgF / counter);
    avgB = (avgB / counter);
    
    if (avgF > avgB) {
      for (int i = 0; i < numLEDs; i++) {
        strip.setPixelColor(i, 100, 0, 0);
        strip.show();
        delay(50);
      }
    } else {
      for (int i = 0; i < numLEDs; i++) {
          strip.setPixelColor(i, 0, 100, 0);
          strip.show();
          delay(50);
      }
    }
    
    delay(5000); // delay allows the final result to be shown 
      
    // turn all white
    for (int i = 0; i < numLEDs; i++) {
        strip.setPixelColor(i, 10, 10, 10);
        strip.show();
        delay(50);
    }
  }
  
  // ##### VELOSTAT CODE ############################

  // print the results to the serial monitor:
  
  //Serial.println(front_base);
  //Serial.println(back_base);

  Serial.print("frontPad1 = " );
  Serial.println(frontPad1);
  Serial.print("backPad2 = " );
  Serial.println(backPad2);
  delay(1000);

}
