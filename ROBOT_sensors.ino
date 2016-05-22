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



                                              // Odometry
 void counterl()
 {
    //Update count
      pulsesl++;    
 }

 void counterr()
 {
    //Update count
      pulsesr++;    
 }
 
 void Odom()
 {
   if (millis() - timeoldl >= 1000){  // Uptade every one second, this will be equal to reading frecuency (Hz)./
 
  //Don't process interrupts during calculations
   detachInterrupt(2);
   detachInterrupt(3);
   //Note that this would be 60*1000/(millis() - timeold)*pulses if the interrupt
   //happened once per revolution
   rpml = (60 * 1000 / pulsesperturn )/ (millis() - timeoldl)* pulsesl;
   timeoldl = millis();
   pulsesl = 0;
   //Restart the interrupt processing
   attachInterrupt(2, counterl, FALLING);
   attachInterrupt(3, counterr, FALLING);
   }

   if (millis() - timeoldr >= 1000){  // Uptade every one second, this will be equal to reading frecuency (Hz)./
   //Don't process interrupts during calculations
   detachInterrupt(2);
   detachInterrupt(3);
   //Note that this would be 60*1000/(millis() - timeold)*pulses if the interrupt
   //happened once per revolution
   rpmr = (60 * 1000 / pulsesperturn )/ (millis() - timeoldr)* pulsesr;
   timeoldr = millis();
   pulsesr = 0;   
   //Restart the interrupt processing
   attachInterrupt(2, counterl, FALLING);
   attachInterrupt(3, counterr, FALLING);
   }
  } 
