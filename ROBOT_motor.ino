
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

