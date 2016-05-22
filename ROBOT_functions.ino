//                                        ------------------Infrared read (0) ------------------  
/* void IR_read() 
{ 
    //в results будут помещаться принятые и 
 //декодированные ик команды
 //if (irrecv.decode(&results)) {
   if (results.value != 0xFF4AB5) IrButton = results.value;
    if (results.value==0xFF4AB5) { mode = 0; controlvar = 0; } // 0 
    if (results.value==0xFF6897) { mode = 1; controlvar = 1; } // 1
    if (results.value==0xFF9867) { mode = 2; controlvar = 2; } // 2
    if (results.value==0xFFB04F) { mode = 3; controlvar = 3; } // 3
    if (results.value==0xFF30CF) { mode = 4; controlvar = 4; } // 4
    if (results.value==0xFF18E7) controlvar = 5; // 5
    if (results.value==0xFF7A85) controlvar = 6; // 6
    if (results.value==0xFF10EF) controlvar = 7; // 7
    if (results.value==0xFF38C7) controlvar = 8;  // 8  
    if (results.value==0xFF5AA5) controlvar = 9; // 9
    if (results.value==0xFF629D) controlvar = 10; // UP
    if (results.value==0xFF22DD) controlvar = 11; // LEFT 
    if (results.value==0xFFA857) controlvar = 12; // DWN
    if (results.value==0xFFC23D) controlvar = 13; // RIGHT
    if (results.value==0xFF02FD) controlvar = 14;// OK
    if (results.value==0xFF42BD) controlvar = 15; // *
    if (results.value==0xFF52AD) controlvar = 16; // #
//     }

}  
*/
     
//                                        ------------------Infrared control (mode 1) ------------------  

/* void IR_control() { 
  if (irrecv.decode(&results)) {
  IR_read(); 
  irrecv.resume();
  }
switch (controlvar) {
// case 4: spda = spda + 10; // 4
// case 7: spda = spda - 10; // 7
// case 6: spdb = spdb + 10; // 6
// case 9: spdb = spdb - 10; // 9   
  case 10: movdir = 1; break;
  case 11: moveLeft(); delay(500); break;
  case 12: movdir = 2; break;
  case 13: moveRight(); delay(500); break;
  case 14: movdir = 0; break;
  case 5: spda = spda + 10; spdb = spda; 
        if (spda > 255) spda = 255; if (spdb > 255) spdb = 255; break;
  case 8: spda = spda - 10; spdb = spda; 
        if (spda < 100) spda = 100; if (spdb < 100) spdb = 100; break;
  }
  controlvar = 17;
  
  if (movdir == 1) moveForward(); 
  if (movdir == 2) moveBackward();
  if (movdir == 0) moveStop();
 }
*/
  
                                     // ----------------- Free running (mode 2)------------------
void FreeRun() {

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

  
//                                     ------------------ Remote control (mode 3) ------------------  
void RemoteControl() {
/*   if ( radio.available() )
  {
    // Read the data payload until we've received everything
      // Fetch the data payload
     radio.read( joystick, sizeof(joystick) );
  }
  else
  {    
   //   Serial.println("No radio available");
  }

x = joystick[0];
y = joystick[1];

if (x > 530) {
  spdb = map(x, 530, 1024, 255, 0); 
  spda = map(x, 530, 1024, 255, 0); 
  if (y > 530)  dira = 0;
    else dira = 1;
    if (y < 500)  dirb = 0;
    else dirb = 1;
 }

if (x < 500) {
  spdb = map(x, 0, 500, 255, 0); 
  spda = map(x, 0, 500, 255, 0); 
  if (y > 530)  dira = 1;
    else dira = 0;
    if (y < 500)  dirb = 1;
    else dirb = 0;
 }
    digitalWrite(D1, dira);  // Задаем направление вращения
    digitalWrite(D2, dirb);
    analogWrite(M1, spda);       // Задаем скорость вращения
    analogWrite(M2, spdb);
    delay(20);  
 / */  
} 
//                                        ------------------folow (mode 4) ------------------  

void folow() { 
// 
int dist, lastdist;
scan(); 
  if (cm < 25) moveBackward();
  if (cm > 35) moveForward();
  if (cm < 35 && cm > 25) moveStop();
}

