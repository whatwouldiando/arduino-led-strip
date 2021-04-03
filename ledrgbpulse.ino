#include <FastLED.h>
#define NUM_LEDS 192
#define LED_PIN     7

int flux_size = 10;
int start_point = 0;
int max_brightness = 255;
CRGB leds[NUM_LEDS];
CHSV color = CHSV(HUE_BLUE, 255, max_brightness);


void pulse(int pulselength, int start){
  int currentled = start;
  for (int i = 0; i< pulselength; i++){
    currentled = (start + i) % NUM_LEDS; //to ensure wrap around of led array in case pulselength exceeds array of leds
    leds[currentled] = color;
    FastLED.show();
    delay(30);
    leds[currentled] = CRGB::Black;
  }
}

void changehue(){
  if (color.hue == HUE_BLUE){
    color.hue = HUE_RED;
  }
  else if(color.hue == HUE_RED){
    color.hue = HUE_GREEN;
  }
  else{
    color.hue = HUE_BLUE;
  }
}
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  pulse(flux_size, start_point);
  color.val = 50; // changing brightness to dim
  pulse(flux_size, start_point);
  color.val = max_brightness;
  pulse(20, start_point); //longer pulse
  color.val = 50;
  pulse(20, start_point);
  color.val = max_brightness;
  pulse(flux_size, 90); //pulse further down strip
  color.val = 50;
  pulse(flux_size, 90);
  color.val = max_brightness;
  pulse(20, 90);
  color.val = 50;
  pulse(20, 90);
  color.val = max_brightness;
  changehue(); //cycle colors 
}
