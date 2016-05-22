/* 
 *   // IrButton = results.value;
  if (results.value==0xFF6897) mode = 0; // 1
  if (results.value==0xFF9867) mode = 1; // 2
  if (results.value==0xFFB04F) mode = 2; // 3
 // if (results.value==0xFF4AB5) mode = 3; // 0    
 // Serial.print(mode); 
 // Serial.println(" mode");  
 
  if (results.value==0xFF30CF) spda = spda + 10; // 4
  if (results.value==0xFF10EF) spda = spda - 10; // 7
  if (results.value==0xFF7A85) spdb = spdb + 10; // 6
  if (results.value==0xFF5AA5) spdb = spdb - 10; // 9
   
  if (mode == 2) { 
  if (results.value==0xFF629D) moveForward(); // UP
  if (results.value==0xFF22DD) moveLeft(); // LEFT 
  if (results.value==0xFFA857) moveBackward(); // DWN
  if (results.value==0xFFC23D) moveRight(); // RIGHT
  if (results.value==0xFF02FD) moveStop(); // OK


   if (results.value==0xFF42BD) { dirb = 0; dira = 0; } // *
   if (results.value==0xFF52AD) { dirb = 1; dira = 1; } // #
   if (results.value==0xFF18E7) { spda = spda + 10; spdb = spda; 
        if (spda > 255) spda = 255; if (spdb > 255) spdb = 255; }  // 5
   if (results.value==0xFF38C7) { spda = spda - 10; spdb = spda; 
        if (spda < 0) spda = 0; if (spdb < 0) spdb = 0; } // 8
        }

        
 */
