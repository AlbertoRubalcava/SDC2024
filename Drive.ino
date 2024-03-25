void drive(){
if (Xbox.getAnalogHat(RightHatY, i) > 7500 || Xbox.getAnalogHat(RightHatY, i) < -7500) {
            Serial.print(F("RightHatY: "));
            Serial.print(Xbox.getAnalogHat(RightHatY, i));
            int x;
            x = Xbox.getAnalogHat(RightHatY, i);
            if(x>28000)
            md.setM1Speed(x/85);
            else if(x>10000)
            md.setM1Speed(x/120);
            else if(x<-10000)
            md.setM1Speed(x/120);
            else if(x<10000 || 10000)
            md.setM1Speed(0);
          }
          Serial.println();
        }

void killDrive(){
  md.setSpeeds(0);
}