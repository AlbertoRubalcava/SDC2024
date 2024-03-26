int i = 0;

int pos = 0; //default position
int putter = 0; //default putter angle

int minPos = 0; // Minimum servo position for the swing
int maxPos = 90; // Maximum servo position for the swing

const int maxStep = 50; //200 Steps per revolution for 200/4 = 50 for 90 degree adjustment
const int nineDegree = 5; //Change 9 degrees per click - 90/9 = 10 different adjustments, so 50/10 is 5 steps per 9 degrees
int stepSize = 1; // Change in angle per step, Smaller = Slower : Greater = Faster
unsigned long stepDelay = 11; // Greater = Slower : Smaller = Faster

void arm(){
  if (Xbox.getButtonClick(A, i)){ 
    Serial.println(F("A : Swing!"));
      for (int pos = minPos; pos <= maxPos; pos += stepSize) {  // most likely want to change this to go up slower/constant
        myservo.write(pos);            
        delay(stepDelay);              
      }
  
    delay(1000);

      // Move back from 90 degrees to 0 degrees
      for (int pos = maxPos; pos >= minPos; pos -= stepSize) { 
        myservo.write(pos);             
        delay(stepDelay);              
      }
 }

  if(Xbox.getButtonClick(LB,i) || Xbox.getButtonClick(RB, i)){
    adjustPutter();
  }

  if(Xbox.getButtonClick(UP, i) || Xbox.getButtonClick(DOWN, i)){
    adjustPower();
  }
}

void adjustPutter(){
  if (Xbox.getButtonClick(LB, i)){
    Serial.println(F("LB : Decreasing Putter Angle"));
    if (putter - nineDegree >= 0) { // Check if moving -9 degrees keeps within the 90-degree limit
      // Rotate stepper motor -9 degrees
      for (int step = 0; step < nineDegree; step++) {
        digitalWrite(dirPin, LOW); // Set motor direction counterclockwise
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(2000); // Adjust delay to control speed
        digitalWrite(stepPin, LOW);
        delayMicroseconds(2000);
      }
      putter -= nineDegree; // Update the current step position
    }
  }

  if (Xbox.getButtonClick(RB, i)){
    Serial.println(F("RB : Increasing Putter Angle"));
      if (putter + nineDegree <= maxStep) { // Check if moving +9 degrees keeps within the 90-degree limit
        // Rotate stepper motor 9 degrees
        for (int step = 0; step < nineDegree; step++) {
          digitalWrite(dirPin, HIGH); // Set motor direction clockwise
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000); // Adjust delay to control speed
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
        }
      putter += nineDegree; // Update the current step position
    }
    }
}



void adjustPower(){ // or adjust position
  if (Xbox.getButtonClick(UP, i)) {
    if(stepDelay >=1){ //ensure stepDelay doesnt go below 0
      stepDelay -= 5; // Smaller the number the faster
      Serial.println(F("Up : Increasing Force " +stepDelay));
  }
    if (Xbox.getButtonClick(DOWN, i)) {
      Serial.println(F("Down : Decreasing Force " +stepDelay));
      stepDelay += 5;
    }
  }
}