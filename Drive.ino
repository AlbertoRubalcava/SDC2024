int i = 0;

void drive(){
  if ((Xbox.getAnalogHat(RightHatY, i) > 5000 || Xbox.getAnalogHat(RightHatY, i) < -5000) && (Xbox.getAnalogHat(RightHatX, i) > 5000 || Xbox.getAnalogHat(RightHatX, i) < -5000)) {
        int rightHatX = Xbox.getAnalogHat(RightHatX, i);
        int rightHatY = Xbox.getAnalogHat(RightHatY, i);

        // Map joystick values to motor speed range -400 - 400
    int leftSpeed = map(rightHatY, -32768, 32767, -400, 400);
    int rightSpeed = map(rightHatX, -32768, 32767, -400, 400);

        moveRobot(leftSpeed, rightSpeed);
        stopIfFault();
  } 

  if(Xbox.getAnalogHat(RightHatY, i) > 5000 || Xbox.getAnalogHat(RightHatY, i) < -5000){
    int rightHatY = Xbox.getAnalogHat(RightHatY, i);

    int speed = map(rightHatY, -32768, 32767, -400, 400);

    moveRobot(speed,speed);
  }

  if(Xbox.getAnalogHat(RightHatX, i) > 5000){
    int rightHatX = Xbox.getAnalogHat(RightHatX, i);

    int speed = map(rightHatX, -32768, 32767, -400, 400);

    moveRobot(speed,0); //turn right
  }

  if(Xbox.getAnalogHat(RightHatX, i) < -5000){
    int rightHatX = Xbox.getAnalogHat(RightHatX, i);

    int speed = map(rightHatX, -32768, 32767, -400, 400);

    moveRobot(0,speed); //turn left
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