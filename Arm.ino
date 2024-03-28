int pos = 0; 
int putter = 0; 

const int maxStep = 50; //200 Stepper Steps per revolution for 200/4 = 50 for 90 degree adjustment
const int nineDegree = 5; //Change 9 degrees per click - 90/9 = 10 different adjustments, so 50/10 is 5 steps per 9 degrees

int minPos = 0; 
int maxPos = 90; 
int midPos = 45;
int stepSize = 5; // Change in angle per step, Smaller = Slower : Greater = Faster
unsigned long stepDelay = 21; // Greater = Slower : Smaller = Faster

void arm(){
  if (Xbox.getButtonClick(A, i)){ 
    Serial.println(F("A : Swing!"));
      //move from 45 degrees to 90 degrees (wind up)
      for (pos = midPos; pos >= minPos; pos -= stepSize) {  
        myservo.write(pos);            
        delay(20);   
      }
  
      delay(1000);

      // move from 90 to 0 degrees (full swing)
      for (pos = minPos; pos <= maxPos; pos += stepSize) { 
        myservo.write(pos);             
        delay(stepDelay);              
      }
      delay(100);

      // move from 0 degrees back to 45 degrees (back to original state)
      for (pos = maxPos; pos >= midPos; pos -= stepSize) { 
        myservo.write(pos);             
        delay(stepDelay);              
      }
 }

    adjustPutter();

    adjustPower();

}

void adjustPutter(){
  if (Xbox.getButtonClick(LB, i)){
    Serial.println(F("LB : Decreasing Putter Angle"));
    if (putter - nineDegree > 0) { 
      // Rotate stepper motor -9 degrees
      for (int step = 0; step < nineDegree; step++) {
        digitalWrite(dirPin, LOW); // Set motor direction counterclockwise
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(2000); // Adjust delay to control speed
        digitalWrite(stepPin, LOW);
        delayMicroseconds(2000);
      }
      putter -= nineDegree; 
    }
  }

  if (Xbox.getButtonClick(RB, i)){
    Serial.println(F("RB : Increasing Putter Angle"));
      if (putter + nineDegree < maxStep) { 
        // Rotate stepper motor 9 degrees
        for (int step = 0; step < nineDegree; step++) {
          digitalWrite(dirPin, HIGH); // Set motor direction clockwise
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000); // Adjust delay to control speed
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
        }
      putter += nineDegree; 
    }
    }
}



void adjustPower(){ // or adjust position
  if (Xbox.getButtonClick(UP, i)) {
    if(stepDelay >1){ //ensure stepDelay doesnt go below 0
      stepDelay -= 5; // Smaller the number the faster
      Serial.println(F("Up : Increasing Force " ));
    }
  }
    if (Xbox.getButtonClick(DOWN, i)) {
      Serial.println(F("Down : Decreasing Force "));
      stepDelay += 5;
    }
  }