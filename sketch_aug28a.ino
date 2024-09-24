// Define pins for the RGB channels
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  // Set the pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // // Turn the RGB strip Red for 2 seconds
  // analogWrite(redPin, 255);    // Max brightness for Red
  // analogWrite(greenPin, 0);    // Green off
  // analogWrite(bluePin, 0);     // Blue off
  // delay(10000);  // Wait for 2 seconds
  
  // Turn the RGB strip Green for 2 seconds
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);  // Max brightness for Green
  analogWrite(bluePin, 0);
  delay(10000);  // Wait for 2 seconds

  //    // Turn the RGB strip yellow for 2 seconds
  // analogWrite(redPin, 255);
  // analogWrite(greenPin, 100);
  // analogWrite(bluePin, 0);   // Max brightness for Blue
  // delay(10000);  // Wait for 2 seconds
  
  // // Turn the RGB strip Blue for 2 seconds
  // analogWrite(redPin, 0);
  // analogWrite(greenPin, 0);
  // analogWrite(bluePin, 255);   // Max brightness for Blue
  // delay(10000);  // Wait for 2 seconds

  //    // Turn the RGB strip yellow for 2 seconds
  // analogWrite(redPin, 255);
  // analogWrite(greenPin, 100);
  // analogWrite(bluePin, 0);   // Max brightness for Blue
  // delay(3000);  // Wait for 2 seconds

    
  // // Turn the RGB strip Blue for 2 seconds
  // analogWrite(redPin, 0);
  // analogWrite(greenPin, 0);
  // analogWrite(bluePin, 255);   // Max brightness for Blue
  // delay(1500);  // Wait for 2 seconds

  //   // Turn the RGB strip PINK for 2 seconds
  // analogWrite(redPin, 255);
  // analogWrite(greenPin, 0);
  // analogWrite(bluePin, 100);   // Max brightness for Blue
  // delay(10000);  // Wait for 2 seconds

  //   // Turn the RGB strip yellow for 2 seconds
  // analogWrite(redPin, 255);
  // analogWrite(greenPin, 100);
  // analogWrite(bluePin, 0);   // Max brightness for Blue
  // delay(3000);  // Wait for 2 seconds
  

  // // Turn the RGB strip OFF for 2 seconds
  // analogWrite(redPin, 0);
  // analogWrite(greenPin, 0);
  // analogWrite(bluePin, 0);
  // delay(2000);  // Wait for 2 seconds
}
