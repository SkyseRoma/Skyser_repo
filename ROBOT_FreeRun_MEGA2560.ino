#include <SPI.h>
//#include <nRF24L01.h>
//#include <RF24.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h> 

//----lightStrip_2812-----
#define PIN 8
int r,g,b;
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

// Motor
#define D1 2          // Направление   in4
#define M1 3          // ШИМ           in3
#define D2 4          // Направление   in2
#define M2 5          // ШИМ           in1
int spda = 150;  
int spdb = 150;
bool dira = 1; 
bool dirb = 1;
int movdir;

//Servo
 Servo Headservo;
 int pos = 90;
 
//Ultrasonic_sensor
int echoPin = 45; 
int trigPin = 47; 
int fDistance;                // distance in front of the robot
int lDistance;                // distance on the left side of the robot
int rDistance;                // distance on the right side of the robot
unsigned int duration, cm; 

void setup() {
  Serial.begin(9600);
  delay(1000);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  

  // Servo
  Headservo.attach(11);

}

void loop() {
pos = 90;
headTurn ();   
scan(); 
  if (cm < 20) {
//    spda = 150;
//    spdb = 150;
    moveStop();                        //Stop 
    pos = 1; headTurn ();                       //Turn Head Right
    scan();                              //Take a reading
    rDistance = cm;                      //Store that to the distance on the right side
    pos = 180; headTurn ();                        //Turn Head Left            
    scan();                              //Take a reading
    lDistance = cm;                      //Store that to the distance on the left side
    
    if(lDistance < rDistance){           //Left distance smaller than right?
      moveRight();                       //Move right for a second
      delay(300);
      moveForward();                     //Then move forward
      }
      else{
        moveLeft();                       //Move right for a second
        delay(300);
        moveForward();                     //Then move forward
      }

   }
//  delay(20);
//  else {
   moveForward();
//  }
}


                                          // Ultrasonic scan
void scan(){
//  motionsense = digitalRead(MotionSense);
    
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  cm = duration / 58;
  Serial.println(cm);  
}


                                             // LED Strip 
//Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
 //     delay(wait);
  }
}


 //                                            ------------------MOTION--------------------

void moveForward(){
    digitalWrite(D1, 1);  // направление
    digitalWrite(D2, 1);
    analogWrite(M1, (255 - spda));  // скорость
    analogWrite(M2, (255 - spdb));
    colorWipe(strip.Color(255, 255, 255), 50);
}

void moveBackward(){
    digitalWrite(D1, 0);  // направление
    digitalWrite(D2, 0);
    analogWrite(M1, spda);  // скорость
    analogWrite(M2, spdb);
    colorWipe(strip.Color(0, 0, 255), 50);
}

void moveRight(){
    digitalWrite(D1, 0);  
    digitalWrite(D2, 1);
    analogWrite(M1, spda);      
    analogWrite(M2, (255 - spdb)); 
    colorWipe(strip.Color(0, 255, 0), 50);
    //delay(100);
}

void moveLeft(){
    digitalWrite(D1, 1); 
    digitalWrite(D2, 0);
    analogWrite(M1, (255 - spda));   
    analogWrite(M2, spdb);
    colorWipe(strip.Color(255, 255, 0), 50);
    //delay(100);
}

void moveStop(){
    digitalWrite(D1, 0);  
    digitalWrite(D2, 0);
    analogWrite(M1, 0);       
    analogWrite(M2, 0);
    colorWipe(strip.Color(255, 0, 0), 50);
}

void headTurn () {
   Serial.println(pos);
  Headservo.write(pos);
  delay(500);
}


