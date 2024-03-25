#include <XBOXRECV.h>
#include "DualVNH5019MotorShield.h"
//include distance sensor stuff

DualVNH5019MotorShield md;

USB Usb;
XBOXRECV Xbox(&Usb);

void setup() {
  //add distance sensor
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial);
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nXbox Wireless Receiver Library Started"));

  md.init();
}

void loop(){
  
  Usb.Task();

  if (Xbox.XboxReceiverConnected) {
    if (Xbox.Xbox360Connected[0]) {\
      drive();
      arm();
      laser();
    }
    else{
      killDrive(); //kill drive motors if controller disconnects
      killSensors(); //kill sensors if controller disconnects
    } 
  }
      else{
      killDrive(); //kill drive motors if receiver disconnects
      killSensors(); //kill sensors if receiver disconnects
    } 
}
