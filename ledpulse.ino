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
    //currentled = (currentled + i) % NUM_LEDS;
    Serial.print("current led =");
    Serial.print(currentled);
    leds[currentled+i] = color;
    Serial.print("color hue=");
    Serial.print(color.h);
    Serial.print("color sat=");
    Serial.print(color.s);
    Serial.print("color val=");
    Serial.print(color.v);
    Serial.print("RGB values =");
    Serial.print(leds[currentled].r);
    Serial.print(leds[currentled].g);
    Serial.print(leds[currentled].b);
    FastLED.show();
    delay(30);
    leds[currentled+i] = CRGB::Black;
  }
}
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("pulse size =");
  Serial.print(flux_size);
  Serial.print("start point =");
  Serial.print(start_point);
  Serial.print("brightness =");
  Serial.print(color.val);
  Serial.println("pulsing.");
  pulse(flux_size, start_point);
  color.val = 50;
  Serial.print("pulse size =");
  Serial.print(flux_size);
  Serial.print("start point =");
  Serial.print(start_point);
  Serial.print("brightness =");
  Serial.print(color.val);
  Serial.println("pulsing.");
  pulse(flux_size, start_point);
  color.val = max_brightness;
  pulse(20, start_point);
  color.val = 50;
  pulse(20, start_point);
  color.val = max_brightness;
  pulse(flux_size, 90);
  color.val = 50;
  pulse(flux_size, 90);
  color.val = max_brightness;
  pulse(20, 90);
  color.val = 50;
  pulse(20, 90);
  color.val = max_brightness;
    
}
