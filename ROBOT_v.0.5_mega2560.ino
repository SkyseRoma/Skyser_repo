
#include <SPI.h>
//#include <nRF24L01.h>
//#include <RF24.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h> 
#include "IRremote.h"
#include "ROBOT_incluses.h"



                                                     /****** SETUP******/ 
void setup()  
{
  Serial.begin(9600);
  delay(1000);
 // Serial.println("Nrf24L01 Receiver Starting");
 // radio.begin();
 // radio.openReadingPipe(1,pipe);
 // radio.startListening();;

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  

  pinMode(MotionSense, INPUT);
  
//начинаем прослушивание ик сигналов
 irrecv.enableIRIn();


   //Use statusPin to flash along with interrupts
//   pinMode(encoder_pin_l, INPUT);
//   pinMode(encoder_pin_r, INPUT);  
   
   //Interrupt 0 is digital pin 2, so that is where the IR detector is connected
   //Triggers on FALLING (change from HIGH to LOW)
   attachInterrupt(2, counterl, FALLING);
   attachInterrupt(3, counterr, FALLING);
   // Initialize
   pulsesl = 0;
   pulsesr = 0;
   rpml = 0;
   rpmr = 0;
   timeoldl = 0;
   timeoldr = 0;

// Servo
  Headservo.attach(11);
}//--(end setup )---


void loop() {  
/* if (irrecv.decode(&results)) {
  IR_read(); 
  irrecv.resume(); 
} */
   switch (mode) {
      case 3: RemoteControl();
      break;
      case 2: FreeRun();
      break;
 //     case 1: IR_control();
      break;
      case 0: folow();
      break;
   }
   Odom();
 //  debug(); 
 scan ();

}

//--(end main loop )---
