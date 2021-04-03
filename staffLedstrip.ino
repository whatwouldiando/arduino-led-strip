#include <FastLED.h>
#define NUM_LEDS 192
#define LED_PIN     7

int lit_leds[] = {0,1,2,3,4,5,6,7,8,};
int lit_leds_size = 9;


CRGB leds[NUM_LEDS];

void fill_leds(){
  for(int i = 0; i < NUM_LEDS; i++){
    if(i == lit_leds[0] || i == (lit_leds[0] + 96) % NUM_LEDS){
      leds[i] = CRGB(0, 50, 150);
    }
     else if(i == (lit_leds[0] + 48) % NUM_LEDS || i == (lit_leds[0] + 144) % NUM_LEDS){
      leds[i] = CRGB(100, 50, 0);
    }
    else if(i == lit_leds[1] ||  i == (lit_leds[1] + 96) % NUM_LEDS){
      leds[i] = CRGB(0, 100, 100);
    }
     else if(i == (lit_leds[1] + 48) % NUM_LEDS || i == (lit_leds[1] + 144) % NUM_LEDS){
      leds[i] = CRGB(100, 100, 0);
    }
     else if(i == lit_leds[2] || i == (lit_leds[2] + 96) % NUM_LEDS){
      leds[i] = CRGB(0, 150, 50);
    }
    else if(i == (lit_leds[2] + 48) % NUM_LEDS || i == (lit_leds[2] + 144) % NUM_LEDS){
      leds[i] = CRGB(50, 150, 0);
    }
     else if(i == lit_leds[3] || i == (lit_leds[3] + 96) % NUM_LEDS){
      leds[i] = CRGB(0, 225, 25);
    }
     else if(i == (lit_leds[3] + 48) % NUM_LEDS || i == (lit_leds[3] + 144) % NUM_LEDS){
      leds[i] = CRGB(25, 225, 0);
    }
     else if(i == lit_leds[4] || i == (lit_leds[4] + 96) % NUM_LEDS){
      leds[i] = CRGB(0, 255, 0);
    }
    else if(i == (lit_leds[4] + 48) % NUM_LEDS || i == (lit_leds[4] + 144) % NUM_LEDS){
      leds[i] = CRGB(0, 255, 0);
    }
        else if(i == lit_leds[5] || i == (lit_leds[5] + 96) % NUM_LEDS){
      leds[i] = CRGB(0, 225, 25);
    }
       else if(i == (lit_leds[5] + 48) % NUM_LEDS || i == (lit_leds[5] + 144) % NUM_LEDS){
      leds[i] = CRGB(25, 225, 0);
    }
        else if(i == lit_leds[6] || i == (lit_leds[6] + 96) % NUM_LEDS){
      leds[i] = CRGB(0, 150, 50);
    }
       else if(i == (lit_leds[6] + 48) % NUM_LEDS || i == (lit_leds[6] + 144) % NUM_LEDS){
      leds[i] = CRGB(50, 150, 0);
    }
        else if(i == lit_leds[7] || i == (lit_leds[7] + 96) % NUM_LEDS){
      leds[i] = CRGB(0, 100, 100);
    }
         else if(i == (lit_leds[7] + 48) % NUM_LEDS || i == (lit_leds[7] + 144) % NUM_LEDS){
      leds[i] = CRGB(100, 100, 0);
    }
        else if(i == lit_leds[8] || i == (lit_leds[8] + 96) % NUM_LEDS){
      leds[i] = CRGB(0, 50, 150);
    }
         else if(i == (lit_leds[8] + 48) % NUM_LEDS || i == (lit_leds[8] + 144) % NUM_LEDS){
      leds[i] = CRGB(150, 50, 0);
    }
    else{
      leds[i] = CRGB(0,0,0);
    }
  }
}

void move_leds_up(){
  for(int i = 0; i < lit_leds_size; i++){
    lit_leds[i] = (lit_leds[i] + 1) % NUM_LEDS;
  }
}
void setup() {
  // put your setup code here, to run once:
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
 
}


void loop() {
  fill_leds();
  FastLED.show();
  delay(40);
  move_leds_up();
  // put your main code here, to run repeatedly:
 // for(int i = 0; i < NUM_LEDS; i++){
 // leds[i] = CRGB(0, 255, 0);
 // FastLED.show();
 // delay(10);
 // leds[i] = CRGB(0, 0, 0);
 // FastLED.show();
 // delay(10);
 // }
  
  //leds[0] = CRGB(0, 255, 0);
 // FastLED.show();
  //delay(500);
  //leds[0] = CRGB(0, 0, 255);
  //FastLED.show();
  //delay(500);
}
