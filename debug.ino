void debug() {
 // Serial.println("Nrf24L01 Receiver Starting");
 
//IR_buttons
// Serial.print("Button pressed:");
// Serial.println(controlvar);
// Serial.print("Mode:");
 Serial.println(cm);
Serial.println(" ");
/*motion sensor
 Serial.print(" Motion ");
 Serial.println(motionsense);
*/

/*Ultrasonic distance
 Serial.print(" Distance: ");
 Serial.print(cm); 
 Serial.println(" cm"); 
Serial.println(" ");
 /*Joystick 
 Serial.print("X = ");
 Serial.print(joystick[0]);
 Serial.print(" Y = ");      
 Serial.println(joystick[1]); 
*/

 //Odometry
 Serial.print("RPM_Right = ");
 Serial.println(rpmr,DEC);
 Serial.print("RPM_Left = ");
 Serial.println(rpml,DEC);
Serial.println(" ");
 /* Motor Speed
 Serial.print(" Motor A: "); 
 Serial.println(spda);  
 Serial.print(" Motor B: "); 
 Serial.println(spdb);
 Serial.println(" "); */
}

