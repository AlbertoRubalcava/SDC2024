//Comment
void laser(){
  if (Xbox.getButtonClick(B, i)){

    if(laserStatus){ // If TRUE then laser is ON, so turn off.
      Serial.println(F("B : Laser OFF"));
      laserStatus = false;
      digitalWrite(31,LOW);
    }
    else{
      Serial.println(F("B : Laser ON"));
      laserStatus = true;
      digitalWrite(31,HIGH);
    }

  }
} 

void distance(){
  /*
  if(mySerial.available()>0) {
      delay(50);
      for(int i=0;i<11;i++)
      {
        data[i]=mySerial.read();
      }
      unsigned char Check=0;
      for(int i=0;i<10;i++)
      {
        Check=Check+data[i];
      }
      Check=~Check+1;
      if(data[10]==Check)
      {
        if(data[3]=='E'&&data[4]=='R'&&data[5]=='R')
        {
          Serial.println("Out of range");
        }
        else
        {
          float distance=0;
          distance=(data[3]-0x30)*100+(data[4]-0x30)*10+(data[5]-0x30)*1+(data[7]-0x30)*0.1+(data[8]-0x30)*0.01+(data[9]-0x30)*0.001;
          Serial.print("Distance = ");
          Serial.print(distance,3);
          Serial.println(" M");
        }
      }
      else
      {
        Serial.println("Invalid Data!");
      }
    }
    */
  }

void killSensors(){
  digitalWrite(31, LOW);
  //turn distance sensor off
}