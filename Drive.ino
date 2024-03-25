void drive(){
  if (Xbox.getAnalogHat(RightHatY, i) > 3000 || Xbox.getAnalogHat(RightHatY, i) < -3000 || Xbox.getAnalogHat(RightHatX, i) > 3000 || Xbox.getAnalogHat(RightHatX, i) < -3000) {
        int rightHatX = Xbox.getAnalogHat(RightHatX, i);
        int rightHatY = Xbox.getAnalogHat(RightHatY, i);

        // Map joystick values to motor speed range -400 - 400
        int leftSpeed = map(rightHatY + rightHatX, -65534, 65534, -400, 400);
        int rightSpeed = map(rightHatY - rightHatX, -65534, 65534, -400, 400);

        moveRobot(leftSpeed, rightSpeed);
        stopIfFault();
  } 
}

void moveRobot(int leftSpeed, int rightSpeed) {
  md.setM1Speed(leftSpeed);
  md.setM2Speed(rightSpeed);
}

void killDrive(){
  md.setM1Speed(0);
  md.setM2Speed(0);
  //Write to LCD Screen - Error
}

void stopIfFault(){
  if (md.getM1Fault())
  {
    Serial.println("M1 fault");
    while(1);
  }
  if (md.getM2Fault())
  {
    Serial.println("M2 fault");
    while(1);
  }
}