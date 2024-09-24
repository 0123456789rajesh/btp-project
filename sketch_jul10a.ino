#include <AFMotor.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

// Create instances for two TCS34725 sensors
Adafruit_TCS34725 tcs1 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
Adafruit_TCS34725 tcs2 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// Initialize motors
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// Speed variables
const int maxSpeed = 255; // Maximum speed
const int minSpeed = 0;   // Minimum speed
const int constantSpeed = 100; // Constant speed for green
const int backwardSpeed = 150; // Constant speed for violet
const int initial_threshhold = 100;
int motorSpeed = 0; // Current speed
const int speedStep = 10; // Speed increment/decrement step

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Initialize the TCA9548A multiplexer
  Wire.begin();
  selectMuxChannel(0);
  if (tcs1.begin()) {
    Serial.println("Found TCS34725 sensor 1");
  } else {
    Serial.println("No TCS34725 sensor 1 found ... check your connections");
    while (1); // halt!
  }

  selectMuxChannel(1);
  if (tcs2.begin()) {
    Serial.println("Found TCS34725 sensor 2");
  } else {
    Serial.println("No TCS34725 sensor 2 found ... check your connections");
    while (1); // halt!
  }
  
  motor1.setSpeed(255);
  motor1.run(RELEASE);
  motor2.setSpeed(255);
  motor2.run(RELEASE);
  motor3.setSpeed(255);
  motor3.run(RELEASE);
  motor4.setSpeed(255);
  motor4.run(RELEASE);
}

void loop() {
  uint16_t r1, g1, b1, c1;
  uint16_t r2, g2, b2, c2;
  float r1Normalized, g1Normalized, b1Normalized;
  float r2Normalized, g2Normalized, b2Normalized;
  String color1 = ""; 
  String color2 = ""; 
  String detectedColor = "";

  // Read RGBC values from the first sensor
  selectMuxChannel(0);
  tcs1.getRawData(&r1, &g1, &b1, &c1);
  r1Normalized = (float)r1 / (float)c1 * 255.0;
  g1Normalized = (float)g1 / (float)c1 * 255.0;
  b1Normalized = (float)b1 / (float)c1 * 255.0;

  // Read RGBC values from the second sensor
  selectMuxChannel(1);
  tcs2.getRawData(&r2, &g2, &b2, &c2);
  r2Normalized = (float)r2 / (float)c2 * 255.0;
  g2Normalized = (float)g2 / (float)c2 * 255.0;
  b2Normalized = (float)b2 / (float)c2 * 255.0;
 
  int R1 = int(r1Normalized);
  int G1 = int(g1Normalized);
  int B2 = int(b1Normalized);
  int R2 = int(r2Normalized);
  int G2 = int(g2Normalized);
  int B3 = int(b2Normalized);

  // Determine color for the first sensor
  if((R1 > B2) && (G1>B2)&&(67<R1<120)&&(100<G1<125)&&(60<B2<105)&&(-10<G1-R1<50)&&(G1-B2>17)) {
    color1 = "Yellow";
  } else if((B2>R1) && (B2>G1)&&(55<R1<115)&&(61<G1<115)&&(105<B2<135)&&(B2-R1<70)&&(R1>100)) {
    color1 = "Pink";
  }else if((G1>R1) && (G1>B2)&&(25<R1<85)&&(120<G1<160)&&(70<B2<99)) {
    color1 = "Green";
  }else if((B2>R1) && (B2>G1)&&(13<R1<75)&&(70<G1<99)&&(135<B2<190)) {
    color1 = "Blue";
  }  else if((R1 > B2 ) && (R1 > G1)&&(90<R1<170)&&(50<G1<120)&&(50<B2<100)) {
    color1 = "Red";
  } else {
    color1 = "Undetected";
  }
  
   // Determine color for the second sensor
if((R2 > B3) && (G2 > B3) && (67 < R2 && R2 < 120) && (100 < G2 && G2 < 125) && (60 < B3 && B3 < 115) && (-10 < G2 - R2 && G2 - R2 < 50) && (G2 - B3 > 13)) {
    color2 = "Yellow";
}else if((B3 > R2) && (B3 > G2) && (55 < R2 && R2 < 115) && (61 < G2 && G2 < 117) && (105 < B3 && B3 < 135)&&(B3-R2<30)&&(R2>100)) {
    color2 = "Pink";
} else if((G2 > R2) && (G2 > B3) && (25 < R2 && R2 < 102) && (120 < G2 && G2 < 160) && (70 < B3 && B3 < 105)) {
    color2 = "Green";
} else if((B3 > R2) && (B3 > G2) && (13 < R2 && R2 < 75) && (70 < G2 && G2 < 99) && (135 < B3 && B3 < 190)) {
    color2 = "Blue";
}  else if((R2 > B3)  && (90 < R2 && R2 < 170) && (50 < G2 && G2 < 120) && (50 < B3 && B3 < 110)) {
    color2 = "Red";
} else {
    color2 = "Undetected";
}

  // Logical OR for detected color
  if (color1 == "Red" || color2 == "Red") {
    detectedColor = "Red";
  } else if (color1 == "Green" || color2 == "Green") {
    detectedColor = "Green";
  } else if (color1 == "Blue" || color2 == "Blue") {
    detectedColor = "Blue";
  } else if (color1 == "Yellow" || color2 == "Yellow") {
    detectedColor = "Yellow";
  } else if (color1 == "Pink" || color2 == "Pink") {
    detectedColor = "Pink";
  } else {
    detectedColor = "Undetected";
  }

  // Print the values to the Serial Monitor
  Serial.print("R1: "); Serial.print(r1Normalized, 2);
  Serial.print(" G1: "); Serial.print(g1Normalized, 2);
  Serial.print(" B1: "); Serial.print(b1Normalized, 2);
  Serial.print(" Color1: "); Serial.println(color1);

  Serial.print("R2: "); Serial.print(r2Normalized, 2);
  Serial.print(" G2: "); Serial.print(g2Normalized, 2);
  Serial.print(" B2: "); Serial.print(b2Normalized, 2);
  Serial.print(" Color2: "); Serial.println(color2);

  Serial.print("Detected Color: "); Serial.println(detectedColor);

  // Control motor based on detected color
  if(detectedColor == "Undetected") {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    Serial.println("Motor stopped");
    delay(1000);
  } else if(detectedColor == "Red") {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    Serial.println("Motor stopped");
  } else if(detectedColor == "Green") {
    motor1.setSpeed(motorSpeed * 1.3);
    motor1.run(FORWARD);
    motor2.setSpeed(motorSpeed);
    motor2.run(FORWARD);
    motor3.setSpeed(motorSpeed * 2);
    motor3.run(FORWARD);  
    motor4.setSpeed(motorSpeed * 1.6);
    motor4.run(FORWARD);
    Serial.println("Motor running at constant speed");
    if( G1 > G2){
       steerLeft();
      }else if( G1 < G2){
       steerRight();
      }
  }  else if(detectedColor == "Blue") {
  if (motorSpeed < initial_threshhold) {
    motorSpeed = initial_threshhold;
     motor1.setSpeed(motorSpeed * 1.3);
    motor1.run(FORWARD);
    motor2.setSpeed(motorSpeed);
    motor2.run(FORWARD);
    motor3.setSpeed(motorSpeed * 2);
    motor3.run(FORWARD);  
    motor4.setSpeed(motorSpeed * 1.6);
    motor4.run(FORWARD);
      Serial.print("Motor accelerating: "); Serial.println(motorSpeed);
       if( B2 > B3){
       steerLeft();
      }else if( B2 < B3){
       steerRight();
      }
      delay(500);
  } else if(motorSpeed < maxSpeed) {
      motorSpeed += speedStep;
      motor1.setSpeed(motorSpeed * 1.3);
    motor1.run(FORWARD);
    motor2.setSpeed(motorSpeed);
    motor2.run(FORWARD);
    motor3.setSpeed(motorSpeed * 2);
    motor3.run(FORWARD);  
    motor4.setSpeed(motorSpeed * 1.6);
    motor4.run(FORWARD);
      Serial.print("Motor accelerating: "); Serial.println(motorSpeed);
       if( B2 > B3){
       steerLeft();
      }else if( B2 < B3){
       steerRight();
      }
      delay(500);
    }
    else if(motorSpeed > maxSpeed) {
      motorSpeed = maxSpeed;
      motor1.setSpeed(motorSpeed * 1.3);
    motor1.run(FORWARD);
    motor2.setSpeed(motorSpeed);
    motor2.run(FORWARD);
    motor3.setSpeed(motorSpeed * 2);
    motor3.run(FORWARD);  
    motor4.setSpeed(motorSpeed * 1.6);
    motor4.run(FORWARD);
      Serial.print("Motor accelerating: "); Serial.println(motorSpeed);
       if( B2 > B3){
       steerLeft();
      }else if( B2 < B3){
       steerRight();
      }
      delay(500);
    }
  }else if(detectedColor == "Pink") {
    if(motorSpeed > minSpeed) {
      motorSpeed -= speedStep;
    motor1.setSpeed(motorSpeed * 1.3);
    motor1.run(FORWARD);
    motor2.setSpeed(motorSpeed);
    motor2.run(FORWARD);
    motor3.setSpeed(motorSpeed * 2);
    motor3.run(FORWARD);  
    motor4.setSpeed(motorSpeed * 1.6);
    motor4.run(FORWARD);
      Serial.print("Motor decelerating: "); Serial.println(motorSpeed);
       if( (G1 < G2)||(R1 > R2)){
       steerLeft();
      }else if( (G1 > G2)||( R1<R2)){
       steerRight();
      }
    }
  } else if(detectedColor == "Yellow") {
   motor1.setSpeed(backwardSpeed * 1.3);
    motor1.run(BACKWARD);

    motor2.setSpeed(backwardSpeed);
    motor2.run(BACKWARD);

    motor3.setSpeed(backwardSpeed * 2);
    motor3.run(BACKWARD);

    motor4.setSpeed(backwardSpeed * 1.6);
    motor4.run(BACKWARD);
    Serial.println("Motor running backward at constant speed");
     if( (G1 < G2)||(R1 > R2)){
       steerLeftBack();
      }else if( (G1 > G2)||( R1<R2)){
       steerRightBack();
      }
  }
 



  // Wait for 1.5 second before taking another reading
  delay(100);
}

// Functions for steering (Left, Right, LeftBack, RightBack)
void steerLeft() {
  motor1.setSpeed((constantSpeed / 3) * 1.3);  
  motor1.run(FORWARD);
  motor4.setSpeed((constantSpeed / 3) * 1.6);
  motor4.run(FORWARD);

  motor3.setSpeed(constantSpeed * 2);
  motor3.run(FORWARD);
  motor2.setSpeed(constantSpeed);
  motor2.run(FORWARD);
   Serial.println("Steering left");
}

void steerRight() {
  motor1.setSpeed(constantSpeed * 1.3);
  motor1.run(FORWARD);
  motor4.setSpeed(constantSpeed * 1.6);
  motor4.run(FORWARD);

  motor3.setSpeed((constantSpeed / 3) * 2);
  motor3.run(FORWARD);
  motor2.setSpeed((constantSpeed / 3));
  motor2.run(FORWARD);
  Serial.println("Steering right");
}

void steerLeftBack() {
  motor1.setSpeed((constantSpeed / 3) * 1.3);  
  motor1.run(BACKWARD);
  motor4.setSpeed((constantSpeed / 3) * 1.6);
  motor4.run(BACKWARD);

  motor3.setSpeed(constantSpeed * 2);
  motor3.run(BACKWARD);
  motor2.setSpeed(constantSpeed);
  motor2.run(BACKWARD);
   Serial.println("Steering left back");
}

void steerRightBack() {
  motor1.setSpeed(constantSpeed * 1.3);
  motor1.run(BACKWARD);
  motor4.setSpeed(constantSpeed * 1.6);
  motor4.run(BACKWARD);

  motor3.setSpeed((constantSpeed / 3) * 2);
  motor3.run(BACKWARD);
  motor2.setSpeed((constantSpeed / 3));
  motor2.run(BACKWARD);
  Serial.println("Steering right back");
}


void selectMuxChannel(uint8_t channel) {
  if (channel > 7) return;

  Wire.beginTransmission(0x70); // TCA9548A address is 0x70
  Wire.write(1 << channel);
  Wire.endTransmission();
}

