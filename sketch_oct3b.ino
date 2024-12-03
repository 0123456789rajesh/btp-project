#include <Adafruit_NeoPixel.h>

// Define the digital pins for the push buttons
#define UP_BUTTON     2
#define DOWN_BUTTON   3
#define LEFT_BUTTON   4
#define RIGHT_BUTTON  7

// Define the pin for the WS2812B LED strip and the number of LEDs
#define LED_PIN       6
#define LED_COUNT     450  // Total number of LEDs

// Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Variables for coordinates (x, y) on a 4x4 grid


int x = 0;  // initial X-coordinate 
int y = 1;  // initial Y-coordinate 
int x1 =0; // previous X-coordinate 
int y1 =0;  // previous Y-coordinate 
int x2 =0; // previous to previous X-coordinate 
int y2 = 0; // previous to previous Y-coordinate 

// Function to print the current coordinates to the Serial Monitor
void printCoordinates() {
  Serial.print("Current coordinates: (");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.println(")");
}



void setup() {
  // Set up the push button pins as inputs
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);

  // Initialize the LED strip
  strip.begin();
  strip.show();delay(1000);  // Initialize all LEDs to 'off'

  // Start the serial monitor to display coordinates
  Serial.begin(9600);

  // Print the initial coordinates and light the initial LED
  printCoordinates();
  lightup_led(x, y, x1, y1, x2, y2);
  // lightup_led(1, 1,0, 1, 0, 0);
  // delay(2000);
  // lightup_led(1, 2, 1, 1, 0, 1);
  // delay(2000);
  // lightup_led(2, 2, 1, 2, 1, 1);
  // delay(2000);
  // lightup_led(2, 3, 2, 2, 1, 2);
  // delay(2000);
  // lightup_led(3, 3, 2, 3, 2, 2);
  // delay(2000);
  
}

void loop() {
  // Check if the up button is pressed
  if (digitalRead(UP_BUTTON) == LOW) {
    // Serial.println("Parth");
    if (y < 3) {
      y2 = y1;
      x2 = x1;
      y1 = y;
      x1 = x;
      y++;  // Increase the y-coordinate
    Serial.println("UP button pressed");
    printCoordinates();
      lightup_led(x, y, x1, y1 , x2, y2);
      delay(200);  // Debounce delay
    }
  }

  // Check if the down button is pressed
  if (digitalRead(DOWN_BUTTON) == LOW) {
    if (y > 0) {
      y2 = y1;
      x2 = x1;
      y1 = y;
      x1 = x;
      y--;  // Decrease the y-coordinate
       Serial.println("DOWN button pressed");
       printCoordinates();
        lightup_led(x, y, x1, y1 , x2, y2);
      delay(200);  // Debounce delay
    }
  }

  // Check if the left button is pressed
  if (digitalRead(LEFT_BUTTON) == LOW) {
    if (x > 0) {
      y2 = y1;
      x2 = x1;
      y1 = y;
      x1 = x;
      x--;  // Decrease the x-coordinate
          Serial.println("LEFT button pressed");
          printCoordinates();
          lightup_led(x, y, x1, y1 , x2, y2);
      delay(200);  // Debounce delay
    }
  }

  // Check if the right button is pressed
  if (digitalRead(RIGHT_BUTTON) == LOW) {
    if (x < 3) {
      y2 = y1;
      x2 = x1;
      y1 = y;
      x1 = x;
      x++;  // Increase the x-coordinate
       Serial.println("RIGHT button pressed");
       printCoordinates();
     lightup_led(x, y, x1, y1 , x2, y2);
      delay(200);  // Debounce delay
    }
  }

  // Light up the LEDs based on current and previous coordinates

  lightup_led(x, y, x1, y1 , x2, y2);
  
    // lightup_led(0, 1, 0, 0 , 0, 0);
    // delay(3000);
    // lightup_led(1, 1, 0, 1 , 0, 0);
    // delay(3000);
    // lightup_led(1, 2, 1, 1 , 0, 1);
    // delay(3000);
    // lightup_led(2, 2, 1, 2 , 1, 1);
    // delay(3000);
    // lightup_led(2, 3, 2, 2 , 1, 2);
    // delay(3000);
    // lightup_led(3, 3, 2, 3 , 2, 2);
    // delay(3000);
 
}


// Function to light up the LED based on current and previous coordinates
void lightup_led(int x, int y, int x1, int y1, int x2, int y2) {

      int junction_led = (x1)*4 + (y1) ;

    if(junction_led ==0) {
      Serial.println("0000");
      if((x == 0)&&(y == 1)&&(x2 == 0)&&(y2 == 0)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 0; i <= 10; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 11; i <= 13; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Red
        }for (int i = 253; i <= 267; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Red
        }
        strip.show();
        delay(1000);
      } if((x == 0)&&(y == 1)&&(x2 == 1)&&(y2 == 0)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 0; i <= 10; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 11; i <= 13; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Red
        }for (int i = 253; i <= 264; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Red
        }for (int i = 265; i <= 267; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }
        strip.show();delay(1000);
      } if((x == 1)&&(y == 0)&&(x2 == 0)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 0; i <= 2 ; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255)); 
        }for (int i = 3; i <= 13 ; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Red
        }for (int i = 256 ; i <= 267; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 253 ; i <= 255; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }
         strip.show();delay(1000);
      }
   } 
   
   if(junction_led ==4) {
    Serial.println("4444");
      if((x == 1)&&(y == 1)&&(x2 == 0)&&(y2 == 0)){
        // Set the rest of the LEDs (18 to 449) to red (R=255, G=0, B=0)
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        } for (int i = 89; i <= 91; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 92; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 253; i <= 255; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i = 256; i <= 267; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 238; i <= 252; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }
        strip.show();delay(1000);
      } if((x == 0)&&(y == 0)&&(x2 == 1)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        } for (int i = 101; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }for (int i = 253; i <= 264; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i = 264; i <= 267; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 89; i <= 100; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 238; i <= 252; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }
        strip.show();delay(1000);
      } if ((x == 1)&&(y == 1)&&(x2 == 2)&&(y2 == 0)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 92; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 250; i <= 252; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }for (int i = 89; i <= 91; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 238; i <= 249; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 253; i <= 267; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }
        strip.show();delay(1000);
      } if ((x == 2)&&(y == 0)&&(x2 == 1)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 101; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i = 241; i <= 252; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 238; i <= 240; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 89; i <= 100; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 253; i <= 267; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }
        strip.show();delay(1000);
      } if ((x == 2)&&(y == 0)&&(x2 == 0)&&(y2 == 0)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 241; i <= 255; i++) {
        strip.setPixelColor(i, strip.Color(0, 255,0));  // Green
        }for (int i = 238; i <= 240; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }for (int i = 256; i <= 267; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }for (int i = 89; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }
        strip.show();delay(1000);
      }if ((x == 0)&&(y == 0)&&(x2 == 2)&&(y2 == 0)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 250; i <= 264; i++) {
        strip.setPixelColor(i, strip.Color(0, 255,0));  // Green
        }for (int i = 238 ;i <= 249; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }for (int i = 265 ;i <= 267; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }for (int i = 89; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }
        strip.show();delay(1000);
      }
   } 
   
   if(junction_led == 2) {
    Serial.println("2222");
      if((x == 0)&&(y == 3)&&(x2 == 0)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 26; i <= 40; i++) {
        strip.setPixelColor(i, strip.Color(0, 255,0));  // Green
        }for (int i = 14; i <= 25; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }for (int i = 41; i <= 43; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }for (int i = 372; i <= 386; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }
        strip.show();delay(1000);
      }if((x == 0)&&(y == 1)&&(x2 == 0)&&(y2 == 3)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 17; i <= 31; i++) {
        strip.setPixelColor(i, strip.Color(0, 255,0));  // Green
        }for (int i = 14; i <= 16; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }for (int i = 32; i <= 43; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }for (int i = 372; i <= 386; i++) {
        strip.setPixelColor(i, strip.Color(255, 0,0));  // Green
        }
        strip.show();delay(1000);
      }if((x == 1)&&(y == 2)&&(x2 == 0)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for(int i = 26; i <= 28; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }for (int i = 375; i <= 386; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 372; i <= 374; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 14; i <= 25; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 29; i <= 43; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }
        strip.show();delay(1000);
      }if((x == 0)&&(y == 1)&&(x2 == 1)&&(y2 == 2)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i =  384; i <= 386; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i = 17; i <= 28; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 14; i <= 16; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 372; i <= 383; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 29; i <= 43; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }
        strip.show();delay(1000);
      }if((x == 0)&&(y == 3)&&(x2 == 1)&&(y2 == 2)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 384; i <= 386; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }for (int i = 29; i <= 40; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 41; i <= 43; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 372; i <= 383; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 14; i <= 28; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }
        strip.show();delay(1000);
      }if((x == 1)&&(y == 2)&&(x2 == 0)&&(y2 == 3)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 29; i <= 31; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i =  375; i <= 386; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 32; i <= 43; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 372; i <= 374; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }for (int i = 14; i <= 28; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));  // Green
        }
        strip.show();delay(1000);
      }
   } 
   

   if(junction_led == 1) {
    Serial.println("1111");
      if((x == 0)&&(y == 2)&&(x2 == 0)&&(y2 == 0)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 11; i <= 25; i++) {
        strip.setPixelColor(i, strip.Color(0, 255,0));  // Green
        }for (int i = 0; i <= 10; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 26; i <= 28; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 283; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }if((x == 0)&&(y == 0)&&(x2 == 0)&&(y2 == 2)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 3; i <= 16; i++) {
        strip.setPixelColor(i, strip.Color(0, 255,0));  // Green
        }for (int i = 0; i <= 2; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 17; i <= 28; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 283; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }if((x == 1)&&(y == 1)&&(x2 == 0)&&(y2 == 0)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 11; i <= 13; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }for (int i = 283; i <= 294; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 0; i <= 10; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 295; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 14; i <= 28; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }
      if((x == 0)&&(y == 0)&&(x2 == 1)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 283; i <= 285; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i = 3; i <= 13; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 0; i <= 2; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 286; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 14; i <= 28; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }

      if((x == 1)&&(y == 1)&&(x2 == 0)&&(y2 == 2)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 283; i <= 294; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 14; i <= 16; i++) {
        strip.setPixelColor(i, strip.Color(0, 0 , 255));  // Green
        }for (int i = 17; i <= 28; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 295; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 0; i <= 13; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }

      if((x == 0)&&(y == 2)&&(x2 == 1)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 283; i <= 285; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }for (int i = 14; i <= 25; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 26; i <= 28; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 286; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 0; i <= 13; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }
   } 
   
   if(junction_led ==3) {

        if((x == 1)&&(y == 3)&&(x2 == 0)&&(y2 == 2)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 41; i <= 43; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }for (int i = 402; i <= 413; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 29; i <= 40; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 414; i <= 416; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }

      if((x == 0)&&(y == 2)&&(x2 == 1)&&(y2 == 3)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 402; i <= 404; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i = 32; i <= 43; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 405; i <= 416; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 29; i <= 31; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }
   } 



    if(junction_led == 5) {
      if((x == 0)&&(y == 1)&&(x2 == 2)&&(y2 ==  1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 286 ; i <= 300; i++) {
        strip.setPixelColor(i, strip.Color(0, 255,0));  // Green
        }for (int i = 283; i <= 285; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 301; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 74; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }
      if((x == 2 )&&(y == 1)&&(x2 == 0)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 295; i <= 308; i++) {
        strip.setPixelColor(i, strip.Color(0, 255,0));  // Green
        }for (int i = 283; i <= 294; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 309; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 74; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }

      if((x == 1)&&(y == 0)&&(x2 == 1)&&(y2 ==  2)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 86 ; i <= 100; i++) {
        strip.setPixelColor(i, strip.Color(0, 255,0));  // Green
        }for (int i = 74; i <= 85; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 101; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 283; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 2)&&(x2 == 1)&&(y2 == 0)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 77; i <= 91; i++) {
        strip.setPixelColor(i, strip.Color(0, 255,0));  // Green
        }for (int i = 74; i <= 76; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 92; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 283; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }

      if((x == 1)&&(y == 2)&&(x2 == 0)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 77; i <= 88; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 295; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i = 74; i <= 76; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 283; i <= 294; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 89; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 298; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }
      if((x == 0)&&(y == 1)&&(x2 == 1)&&(y2 == 2)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 86; i <= 88; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }for (int i = 286; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 74; i <= 85; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 283; i <= 285; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 89; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 298; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 2)&&(x2 == 2)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 298; i <= 300; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }for (int i = 77; i <= 88; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 74; i <= 76; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 301; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 89; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 283; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 1)&&(x2 == 1)&&(y2 == 2)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 86; i <= 88; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i = 298 ; i <= 308; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 74; i <= 85; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 309; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 89; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 283; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }

      if((x == 0)&&(y == 1)&&(x2 == 1)&&(y2 == 0)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 89; i <= 91; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i = 286; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 92; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 283; i <= 285; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 74; i <= 88; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 298; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }
       if((x == 1)&&(y == 0)&&(x2 == 0)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 295; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }for (int i = 89; i <=100 ; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i = 283; i <= 294; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 101; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 74; i <= 88; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 298; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }

      if((x == 2)&&(y == 1)&&(x2 == 1)&&(y2 == 0)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 89; i <= 91; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 100));  // Green
        }for (int i = 298; i <= 308; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 92; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 309; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 283; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 74; i <= 88; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 0)&&(x2 == 2)&&(y2 == 1)){
        for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));  // Red
        }for (int i = 298; i <= 300; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));  // Green
        }for (int i = 89; i <= 100; i++) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));  // Green
        }for (int i = 301; i <= 311; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 101; i <= 103; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 283; i <= 297; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }for (int i = 74; i <= 88; i++) {
        strip.setPixelColor(i, strip.Color(255, 0 , 0));  // Green
        }
        strip.show();delay(1000);
      }
   }

    if(junction_led == 6) {
      if((x == 0)&&(y == 2)&&(x2 == 2)&&(y2 ==  2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 369 , 383 , 0 , 255,  0);
        setcolorpatch( 357 , 368 , 255, 0,  0);
        setcolorpatch( 384 , 386 , 255, 0,  0);
        setcolorpatch( 59 ,  88 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2 )&&(y == 2)&&(x2 == 0)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 360 , 374 ,  0 , 255, 0);
        setcolorpatch( 357 , 359 , 255, 0,  0);
        setcolorpatch( 375 , 386 , 255, 0,  0);
        setcolorpatch( 59 ,  88 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 1)&&(x2 == 1)&&(y2 ==  3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 71 ,  85 , 0 , 255, 0);
        setcolorpatch( 59 , 70 , 255, 0,  0);
        setcolorpatch( 86 , 88 , 255, 0,  0);
        setcolorpatch( 357 ,386 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1 )&&(y == 3)&&(x2 == 1)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 62 , 76 , 0 , 255,  0);
        setcolorpatch( 59 , 62 , 255, 0,  0);
        setcolorpatch( 77 , 88 , 255, 0,  0);
        setcolorpatch( 357 ,386 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 3)&&(x2 == 0)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 62 ,  73 , 0 , 255, 0); //green
        setcolorpatch( 372,  374 , 0 , 0, 255); //turn color
        setcolorpatch( 59 , 61 , 255, 0,  0);
        setcolorpatch( 375 , 386 , 255, 0,  0);
        setcolorpatch( 74 ,88 , 255, 0,  0);
        setcolorpatch( 357 ,371 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 0)&&(y == 2)&&(x2 == 1)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 372 ,  383 , 0 , 255, 0); //green
        setcolorpatch( 71,  73 , 255 , 0, 100); //turn color
        setcolorpatch( 384 , 386 , 255, 0,  0);
        setcolorpatch( 59 , 70 , 255, 0,  0);
        setcolorpatch( 74 ,88 , 255, 0,  0);
        setcolorpatch( 357 ,371 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 3)&&(x2 == 2)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 62 ,  73 , 0 , 255, 0); //green
        setcolorpatch( 369,  371 , 255 , 0, 100); //turn color
        setcolorpatch( 59 , 61 , 255, 0,  0);
        setcolorpatch( 357 , 368 , 255, 0,  0);
        setcolorpatch( 74 ,88 , 255, 0,  0);
        setcolorpatch( 372 ,386 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 2)&&(x2 == 1)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 360 ,  371 , 0 , 255, 0); //green
        setcolorpatch( 71,  73 , 0 , 0, 255); //turn color
        setcolorpatch( 59 , 70 , 255, 0,  0);
        setcolorpatch( 357 , 359, 255, 0,  0);
        setcolorpatch( 74 ,88 , 255, 0,  0);
        setcolorpatch( 372 ,386 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 0)&&(y == 2)&&(x2 == 1)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 372 ,  383 , 0 , 255, 0); //green
        setcolorpatch( 74,  76 , 0 , 0, 255); //turn color
        setcolorpatch( 384 , 386 , 255, 0,  0);
        setcolorpatch( 77 , 88, 255, 0,  0);
        setcolorpatch( 59 ,73 , 255, 0,  0);
        setcolorpatch( 357, 371 , 255, 0,  0);
        strip.show();delay(1000);
      }
       if((x == 1)&&(y == 1)&&(x2 == 0)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 74 ,  85 , 0 , 255, 0); //green
        setcolorpatch( 372,  374 , 255 , 0, 100); //turn color
        setcolorpatch( 375 , 386 , 255, 0,  0);
        setcolorpatch( 86, 88, 255, 0,  0);
        setcolorpatch( 59 ,73 , 255, 0,  0);
        setcolorpatch( 357, 371 , 255, 0,  0);
        strip.show();delay(1000);
      }

      if((x == 2)&&(y == 2)&&(x2 == 1)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 360,  371 , 0 , 255, 0); //green
        setcolorpatch( 74,  76 , 255 , 0, 100); //turn color
        setcolorpatch( 357 , 359 , 255, 0,  0);
        setcolorpatch( 77, 88, 255, 0,  0);
        setcolorpatch( 59 ,73 , 255, 0,  0);
        setcolorpatch( 372, 386 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 1)&&(x2 == 2)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 74,  85 , 0 , 255, 0); //green
        setcolorpatch( 369,  371 , 0 , 0, 255); //turn color
        setcolorpatch( 357 , 368 , 255, 0,  0);
        setcolorpatch( 86, 88, 255, 0,  0);
        setcolorpatch( 59 ,73 , 255, 0,  0);
        setcolorpatch( 372, 386 , 255, 0,  0);
        strip.show();delay(1000);
      }
   }
   

    if(junction_led == 7) {
      if((x == 0)&&(y == 3)&&(x2 == 2)&&(y2 ==  3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 405 , 419 , 0 , 255,  0);
        setcolorpatch( 402 , 404 , 255, 0,  0);
        setcolorpatch( 419 , 431 , 255, 0,  0);
        setcolorpatch( 59 ,  73 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 3)&&(x2 == 0)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 414 , 428 ,  0 , 255, 0);
        setcolorpatch( 402 , 413 , 255, 0,  0);
        setcolorpatch( 429 , 431 , 255, 0,  0);
        setcolorpatch( 59 ,  73 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 0)&&(y == 3)&&(x2 == 1)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 405 , 416 , 0 , 255, 0); //green
        setcolorpatch( 59,  61 , 0 , 0, 255); //turn color
        setcolorpatch( 402 , 404 , 255, 0,  0);
        setcolorpatch( 61 , 73 , 255, 0,  0);
        setcolorpatch( 417,  431 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 2)&&(x2 == 0)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 59 ,  70 , 0 , 255, 0); //green
        setcolorpatch( 414,  416 , 255 , 0, 100); //turn color
        setcolorpatch( 402 , 413 , 255, 0,  0);
        setcolorpatch( 71 , 73 , 255, 0,  0);
        setcolorpatch( 417,  431 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 3)&&(x2 == 1)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 417 ,  428 , 0 , 255, 0); //green
        setcolorpatch( 59,  61 , 255 , 0, 100); //turn color
        setcolorpatch( 429 , 431 , 255, 0,  0);
        setcolorpatch( 62 , 73 , 255, 0,  0);
        setcolorpatch( 402,  416 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 2)&&(x2 == 2)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 59 ,  70 , 0 , 255, 0); //green
        setcolorpatch( 417, 419 , 0 , 0, 255); //turn color
        setcolorpatch( 420 , 431 , 255, 0,  0);
        setcolorpatch( 71 , 73 , 255, 0,  0);
        setcolorpatch( 402,  416 , 255, 0,  0);
        strip.show();delay(1000);
      }
   }

    if(junction_led == 8) {
      if((x == 1)&&(y == 0)&&(x2 == 3)&&(y2 ==  0)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 235 , 249 , 0 , 255,  0);
        setcolorpatch( 223 , 234 , 255, 0,  0);
        setcolorpatch( 250 , 252 , 255, 0,  0);
        setcolorpatch( 119 , 133 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3)&&(y == 0)&&(x2 == 1)&&(y2 == 0)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 226 , 240 ,  0 , 255, 0);
        setcolorpatch( 223 , 225 , 255, 0,  0);
        setcolorpatch( 241 , 252 , 255, 0,  0);
        setcolorpatch( 119 , 133 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 1)&&(x2 == 1)&&(y2 == 0)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 119 , 130 , 0 , 255, 0); //green
        setcolorpatch( 238,  240 , 0 , 0, 255); //turn color
        setcolorpatch( 131 , 133 , 255, 0,  0);
        setcolorpatch( 241 , 252 , 255, 0,  0);
        setcolorpatch( 223 , 237 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 0)&&(x2 == 2)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 238 , 249 , 0 , 255, 0); //green
        setcolorpatch( 119,  121 , 255 , 0, 100); //turn color
        setcolorpatch( 250 , 252 , 255, 0,  0);
        setcolorpatch(  122, 133 , 255, 0,  0);
        setcolorpatch( 223 , 237 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 1)&&(x2 == 3)&&(y2 == 0)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 119 ,  130 , 0 , 255, 0); //green
        setcolorpatch( 235, 237 , 255 , 0, 100); //turn color
        setcolorpatch( 131 , 133 , 255, 0,  0);
        setcolorpatch( 223 ,234 , 255, 0,  0);
        setcolorpatch( 238 , 252 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 0)&&(y == 3)&&(x2 == 2)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 226 , 237 , 0 , 255, 0); //green
        setcolorpatch( 119, 121 , 0 , 0, 255); //turn color
        setcolorpatch( 223 , 225 , 255, 0,  0);
        setcolorpatch( 122 , 133 , 255, 0,  0);
        setcolorpatch( 238 , 252 , 255, 0,  0);
        strip.show();delay(1000);
      }
   }

   if(junction_led == 9) {
      if((x == 1)&&(y == 1)&&(x2 == 3)&&(y2 ==  1)){
        setcolorpatch( 0 , LED_COUNT ,  0, 0, 0);
        setcolorpatch( 301 , 314 , 0 , 255,  0);
        setcolorpatch( 298 , 300 , 255, 0,  0);
        setcolorpatch( 315 , 326 , 255, 0,  0);
        setcolorpatch( 119 , 148 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3 )&&(y == 1)&&(x2 == 1)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 309 , 323 ,  0 , 255, 0);
        setcolorpatch( 298 , 308 , 255, 0,  0);
        setcolorpatch( 324 , 326 , 255, 0,  0);
        setcolorpatch( 119 , 148 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 2)&&(x2 == 2)&&(y2 ==  0)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 131 ,  145 , 0 , 255, 0);
        setcolorpatch( 119 , 130 , 255, 0,  0);
        setcolorpatch( 146 , 148 , 255, 0,  0);
        setcolorpatch( 298, 326 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2 )&&(y == 0)&&(x2 == 2)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 122 , 136 , 0 , 255,  0);
        setcolorpatch( 119 , 121 , 255, 0,  0);
        setcolorpatch( 137 , 148 , 255, 0,  0);
        setcolorpatch( 298, 326 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 2)&&(x2 == 1)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 134 ,  145 , 0 , 255, 0); //green
        setcolorpatch( 309,  311 , 0 , 0, 255); //turn color
        setcolorpatch( 146 , 148 , 255, 0,  0);
        setcolorpatch( 298 , 308, 255, 0,  0);
        setcolorpatch( 119, 133 , 255, 0,  0);
        setcolorpatch( 312, 326 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 1)&&(x2 == 2)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 301 ,  311 , 0 , 255, 0); //green
        setcolorpatch( 134,  136 , 255 , 0, 100); //turn color
        setcolorpatch( 137 , 148 , 255, 0,  0);
        setcolorpatch( 298 , 300, 255, 0,  0);
        setcolorpatch( 119, 133 , 255, 0,  0);
        setcolorpatch( 312, 326 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 2)&&(x2 == 3)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 134 ,  145 , 0 , 255, 0); //green
        setcolorpatch( 312,  314 , 255 , 0, 100); //turn color
        setcolorpatch( 146 , 148 , 255, 0,  0);
        setcolorpatch( 315 , 326, 255, 0,  0);
        setcolorpatch( 119, 133 , 255, 0,  0);
        setcolorpatch( 298, 311 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3)&&(y == 1)&&(x2 == 2)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 312 ,  323 , 0 , 255, 0); //green
        setcolorpatch( 134,  136 , 0 , 0, 255); //turn color
        setcolorpatch( 137 , 148 , 255, 0,  0);
        setcolorpatch( 324 , 326, 255, 0,  0);
        setcolorpatch( 119, 133 , 255, 0,  0);
        setcolorpatch( 298, 311 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 1)&&(x2 == 2)&&(y2 == 0)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 301 ,  311 , 0 , 255, 0); //green
        setcolorpatch( 131,  133 , 0 , 0, 255); //turn color
        setcolorpatch( 298 , 300 , 255, 0,  0);
        setcolorpatch( 119 , 130, 255, 0,  0);
        setcolorpatch( 134, 148 , 255, 0,  0);
        setcolorpatch( 312, 326 , 255, 0,  0);
        strip.show();delay(1000);
      }
       if((x == 2)&&(y == 0)&&(x2 == 1)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 122 ,  133 , 0 , 255, 0); //green
        setcolorpatch( 309,  311 , 255 , 0, 100); //turn color
        setcolorpatch( 298 , 308 , 255, 0,  0);
        setcolorpatch( 119 , 121, 255, 0,  0);
        setcolorpatch( 134, 148 , 255, 0,  0);
        setcolorpatch( 312, 326 , 255, 0,  0);
        strip.show();delay(1000);
      }

      if((x == 3)&&(y == 1)&&(x2 == 2)&&(y2 == 0)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 312,  323 , 0 , 255, 0); //green
        setcolorpatch( 131,  133 , 255 , 0, 100); //turn color
        setcolorpatch( 119 , 130 , 255, 0,  0);
        setcolorpatch( 324 , 326, 255, 0,  0);
        setcolorpatch( 134, 148 , 255, 0,  0);
        setcolorpatch( 298, 311 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 0)&&(x2 == 3)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 122,  133 , 0 , 255, 0); //green
        setcolorpatch( 312,  314 , 0 , 0, 255); //turn color
        setcolorpatch( 119 , 121 , 255, 0,  0);
        setcolorpatch( 315 , 326, 255, 0,  0);
        setcolorpatch( 134, 148 , 255, 0,  0);
        setcolorpatch( 298, 311 , 255, 0,  0);
        strip.show();delay(1000);
      }
   }
   
   if(junction_led == 10) {
      if((x ==1 )&&(y == 2)&&(x2 == 3)&&(y2 ==  2)){
        setcolorpatch( 0 , LED_COUNT , 0, 0, 0);
        setcolorpatch( 354 , 368 , 0 , 255,  0);
        setcolorpatch( 342 , 353 , 255, 0,  0);
        setcolorpatch( 369 , 371 , 255, 0,  0);
        setcolorpatch( 134 , 162 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3 )&&(y == 2)&&(x2 == 1)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 345 , 359 ,  0 , 255, 0);
        setcolorpatch( 342 , 344 , 255, 0,  0);
        setcolorpatch( 360 , 371 , 255, 0,  0);
        setcolorpatch( 134 , 162 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 3)&&(x2 == 2)&&(y2 ==  1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 146 ,  159 , 0 , 255, 0);
        setcolorpatch( 134 , 145 , 255, 0,  0);
        setcolorpatch( 160 , 162 , 255, 0,  0);
        setcolorpatch( 342 , 371 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2 )&&(y == 1)&&(x2 == 2)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 137 , 151 , 0 , 255,  0);
        setcolorpatch( 134 , 136 , 255, 0,  0);
        setcolorpatch( 152 , 162 , 255, 0,  0);
        setcolorpatch( 342 , 371 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 3)&&(x2 == 1)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch(  149,  159 , 0 , 255, 0); //green
        setcolorpatch( 357,  359 , 0 , 0, 255); //turn color
        setcolorpatch( 160 , 162 , 255, 0,  0);
        setcolorpatch( 360 , 371 , 255, 0,  0);
        setcolorpatch( 342 , 356 , 255, 0,  0);
        setcolorpatch( 134 , 148 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 2)&&(x2 == 2)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 357 ,  368 , 0 , 255, 0); //green
        setcolorpatch( 149,  151 , 255 , 0, 100); //turn color
        setcolorpatch( 152 , 162 , 255, 0,  0);
        setcolorpatch( 369 , 371 , 255, 0,  0);
        setcolorpatch( 342 , 356 , 255, 0,  0);
        setcolorpatch( 134 , 148 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 3)&&(x2 == 3)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 149 ,  159 , 0 , 255, 0); //green
        setcolorpatch( 354,  356 , 255 , 0, 100); //turn color
        setcolorpatch( 160 , 162 , 255, 0,  0);
        setcolorpatch( 342 , 353 , 255, 0,  0);
        setcolorpatch( 357 , 371 , 255, 0,  0);
        setcolorpatch( 134 , 148 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3)&&(y == 2)&&(x2 == 2)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 345 ,  356 , 0 , 255, 0); //green
        setcolorpatch( 149,  151 , 0 , 0, 255); //turn color
        setcolorpatch( 152 , 162 , 255, 0,  0);
        setcolorpatch( 342 , 344 , 255, 0,  0);
        setcolorpatch( 357 , 371 , 255, 0,  0);
        setcolorpatch( 134 , 148 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 2)&&(x2 == 2)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0, 0, 0); //red
        setcolorpatch( 357 ,  368 , 0 , 255, 0); //green
        setcolorpatch( 146,  148 , 0 , 0, 255); //turn color
        setcolorpatch( 134 , 145 , 255, 0,  0);
        setcolorpatch( 369 , 371 , 255, 0,  0);
        setcolorpatch( 342 , 356 , 255, 0,  0);
        setcolorpatch( 149 , 162 , 255, 0,  0);
        strip.show();delay(1000);
      }
       if((x == 2)&&(y == 1)&&(x2 == 1)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 137 ,  148 , 0 , 255, 0); //green
        setcolorpatch( 357,  359 , 255 , 0, 100); //turn color
        setcolorpatch( 134 , 136 , 255, 0,  0);
        setcolorpatch( 360 , 371 , 255, 0,  0);
        setcolorpatch( 342 , 356 , 255, 0,  0);
        setcolorpatch( 149 , 162 , 255, 0,  0);
        strip.show();delay(1000);
      }

      if((x == 3)&&(y == 2)&&(x2 == 2)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 345,  356 , 0 , 255, 0); //green
        setcolorpatch( 146,  148 , 255 , 0, 100); //turn color
        setcolorpatch( 134 , 145 , 255, 0,  0);
        setcolorpatch( 342 , 344 , 255, 0,  0);
        setcolorpatch( 357 , 371 , 255, 0,  0);
        setcolorpatch( 149 , 162 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 1)&&(x2 == 3)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 137,  148 , 0 , 255, 0); //green
        setcolorpatch( 354,  356 , 0 , 0, 255); //turn color
        setcolorpatch( 134 , 136 , 255, 0,  0);
        setcolorpatch( 342 , 353 , 255, 0,  0);
        setcolorpatch( 357 , 371 , 255, 0,  0);
        setcolorpatch( 149 , 162 , 255, 0,  0);
        strip.show();delay(1000);
      }
   }
   
   if(junction_led == 11) {
      if((x == 3)&&(y == 3)&&(x2 == 1)&&(y2 ==  3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 429 , 431 , 0 , 255,  0);
        setcolorpatch( 163 , 174 , 0 , 255,  0);
        setcolorpatch( 417 , 428 , 255, 0,  0);
        setcolorpatch( 175 , 177 , 255, 0,  0);
        setcolorpatch( 149 , 162 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 3)&&(x2 == 3)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 163 , 165 ,  0 , 255, 0);
        setcolorpatch( 420 , 431 ,  0 , 255, 0);
        setcolorpatch( 166 , 177 , 255, 0,  0);
        setcolorpatch( 417 , 419 , 255, 0,  0);
        setcolorpatch( 149 , 162 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 1)&&(y == 3)&&(x2 == 2)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT ,0 , 0, 0); //red
        setcolorpatch( 420 , 431 , 0 , 255, 0); //green
        setcolorpatch( 160,  162 , 0 , 0, 255); //turn color
        setcolorpatch( 149 , 159 , 255, 0,  0);
        setcolorpatch( 417 , 419 , 255, 0,  0);
        setcolorpatch( 163 , 177 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 2)&&(x2 == 1)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0, 0, 0); //red
        setcolorpatch( 152 , 162 , 0 , 255, 0); //green
        setcolorpatch( 429,  431 , 255 , 0, 100); //turn color
        setcolorpatch( 149 , 151 , 255, 0,  0);
        setcolorpatch( 417 , 428 , 255, 0,  0);
        setcolorpatch( 163 , 177 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3)&&(y == 3)&&(x2 == 2)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 163 , 174 , 0 , 255, 0); //green
        setcolorpatch( 160, 162 , 255 , 0, 100); //turn color
        setcolorpatch( 175 , 177 , 255, 0,  0);
        setcolorpatch( 149 , 159 , 255, 0,  0);
        setcolorpatch( 417 , 431 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 2)&&(x2 == 3)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 152 , 162 , 0 , 255, 0); //green
        setcolorpatch( 163, 165 , 0 , 0, 255); //turn color
        setcolorpatch( 166 , 177 , 255, 0,  0);
        setcolorpatch( 149 , 151 , 255, 0,  0);
        setcolorpatch( 417 , 431 , 255, 0,  0);
        strip.show();delay(1000);
      }
   }

   if(junction_led == 12) {
      if((x == 3)&&(y == 1)&&(x2 == 2)&&(y2 == 0)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 211 , 222 , 0 , 255, 0); //green
        setcolorpatch( 223,  225 , 0 , 0, 255); //turn color
        setcolorpatch( 208 , 210 , 255, 0,  0);
        setcolorpatch( 226 , 237 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 0)&&(x2 == 3)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch(  223, 234 , 0 , 255, 0); //green
        setcolorpatch( 220,  222 , 255 , 0, 100); //turn color
        setcolorpatch( 208 , 219 , 255, 0,  0);
        setcolorpatch( 235 , 237 , 255, 0,  0);
        strip.show();delay(1000);
      }
   } 

    if(junction_led == 13) {
      if((x == 3)&&(y == 2)&&(x2 == 3)&&(y2 ==  0)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 196 , 210 , 0 , 255,  0);
        setcolorpatch( 193 , 195 , 255, 0,  0);
        setcolorpatch( 211 , 222 , 255, 0,  0);
        setcolorpatch( 312 , 326 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3)&&(y == 0)&&(x2 == 3)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 205 , 219 ,  0 , 255, 0);
        setcolorpatch( 193 , 204 , 255, 0,  0);
        setcolorpatch( 220 , 222 , 255, 0,  0);
        setcolorpatch( 312 , 326 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3)&&(y == 2)&&(x2 == 2)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 196 , 207 , 0 , 255, 0); //green
        setcolorpatch( 324,  326 , 0 , 0, 255); //turn color
        setcolorpatch( 193 , 195 , 255, 0,  0);
        setcolorpatch( 312 , 323 , 255, 0,  0);
        setcolorpatch( 208 , 222 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 1)&&(x2 == 3)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 315 , 326 , 0 , 255, 0); //green
        setcolorpatch( 205,  207 , 255 , 0, 100); //turn color
        setcolorpatch( 193 , 204 , 255, 0,  0);
        setcolorpatch( 312 , 314 , 255, 0,  0);
        setcolorpatch( 208 , 222 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 1)&&(x2 == 3)&&(y2 == 0)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 315 , 326 , 0 , 255, 0); //green
        setcolorpatch( 208, 210 , 0 , 0, 255); //turn color
        setcolorpatch( 211 , 222 , 255, 0,  0);
        setcolorpatch( 312 , 314 , 255, 0,  0);
        setcolorpatch( 193, 207 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3)&&(y == 0)&&(x2 == 2)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 208 , 219 , 0 , 255, 0); //green
        setcolorpatch( 324, 326 , 255 , 0, 100); //turn color
        setcolorpatch( 220 , 222 , 255, 0,  0);
        setcolorpatch( 312 , 323 , 255, 0,  0);
        setcolorpatch( 193, 207 , 255, 0,  0);
        strip.show();delay(1000);
      }
   } 
  
   if(junction_led == 14) {
      if((x == 3)&&(y == 3)&&(x2 == 3)&&(y2 ==  1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 181 , 195 , 0 , 255,  0);
        setcolorpatch( 178 , 180 , 255, 0,  0);
        setcolorpatch( 196 , 207 , 255, 0,  0);
        setcolorpatch( 342 , 356 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3)&&(y == 1)&&(x2 == 3)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0);
        setcolorpatch( 190 , 204 ,  0 , 255, 0);
        setcolorpatch( 178 , 189 , 255, 0,  0);
        setcolorpatch( 205 , 207 , 255, 0,  0);
        setcolorpatch( 342 , 356 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3)&&(y == 3)&&(x2 == 2)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 181 , 192 , 0 , 255, 0); //green
        setcolorpatch( 342,  344 , 0 , 0, 255); //turn color
        setcolorpatch( 178 , 180 , 255, 0,  0);
        setcolorpatch( 345 , 356 , 255, 0,  0);
        setcolorpatch( 193 , 207 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 2)&&(x2 == 3)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 342 , 353 , 0 , 255, 0); //green
        setcolorpatch( 190,  192 , 255 , 0, 100); //turn color
        setcolorpatch( 178 , 189 , 255, 0,  0);
        setcolorpatch( 354 , 356 , 255, 0,  0);
        setcolorpatch( 193 , 207 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 2)&&(y == 2)&&(x2 == 3)&&(y2 == 1)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 342 , 353 , 0 , 255, 0); //green
        setcolorpatch( 193, 195 , 0 , 0, 255); //turn color
        setcolorpatch( 196 , 207 , 255, 0,  0);
        setcolorpatch( 354 , 356 , 255, 0,  0);
        setcolorpatch( 178 , 192 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3)&&(y == 1)&&(x2 == 2)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 193 , 204 , 0 , 255, 0); //green
        setcolorpatch( 342, 344 , 255 , 0, 100); //turn color
        setcolorpatch( 205 , 207 , 255, 0,  0);
        setcolorpatch( 345 , 356 , 255, 0,  0);
        setcolorpatch( 178 , 192 , 255, 0,  0);
        strip.show();delay(1000);
      }
   }
   
   if(junction_led == 15) {
      if((x == 2)&&(y == 3)&&(x2 == 3)&&(y2 == 2)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch( 166 , 177 , 0 , 255, 0); //green
        setcolorpatch( 178,  180 , 0 , 0, 255); //turn color
        setcolorpatch( 163 , 165 , 255, 0,  0);
        setcolorpatch( 181 , 192 , 255, 0,  0);
        strip.show();delay(1000);
      }
      if((x == 3)&&(y == 2)&&(x2 == 2)&&(y2 == 3)){
        setcolorpatch( 0 , LED_COUNT , 0 , 0, 0); //red
        setcolorpatch(  178, 189 , 0 , 255, 0); //green
        setcolorpatch( 175,  177 , 255 , 0, 100); //turn color
        setcolorpatch( 163 , 174 , 255, 0,  0);
        setcolorpatch( 190 , 192 , 255, 0,  0);
        strip.show();delay(1000);
      }
   } 



}



void setcolorpatch(uint16_t a , uint16_t b , uint8_t r1 ,uint8_t g1, uint8_t b1){
  if (b == LED_COUNT){
    for (uint16_t i = a; i < b; i++) {
        strip.setPixelColor(i, strip.Color(r1, g1, b1));  // Green
        }

  }
    else {
      for (uint16_t i = a; i <= b; i++) {
        strip.setPixelColor(i, strip.Color(r1, g1, b1));  // Green
        }
    }
}





