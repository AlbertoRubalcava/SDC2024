#include <XBOXRECV.h>
#include "DualVNH5019MotorShield.h"
#include <SoftwareSerial.h>
#include <Servo.h>

#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

SoftwareSerial mySerial(52,53); //Define software serial, 53 is TX, 52 is RX
char buff[4]={0x80,0x06,0x03,0x77}; //distance sensor
unsigned char data[11]={0}; //distance sensor

DualVNH5019MotorShield md;

Servo myservo;

const int dirPin = 11; 
const int stepPin = 8; 

USB Usb;
XBOXRECV Xbox(&Usb);
int i = 0; //controller initialization - only one controller so always 0

bool laserStatus = false; //initialize laser to false/off

void setup() {
  Serial.begin(115200);

#if !defined(__MIPSEL__)
  while (!Serial);
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nXbox Wireless Receiver Library Started"));

  myservo.attach(7); //servo

  pinMode(stepPin,OUTPUT);  //stepper
  pinMode(dirPin,OUTPUT); //stepper

  md.init(); //motors

  digitalWrite(31,LOW); // initialize laser to off

  myservo.write(45); //initalizie servo to 45 degrees    
  delay(5);  
}

void drive(); //drive robot depending on joystick input
void arm(); //main function swings club using servo
void laser(); //turns on/off laser
void distance(); //reads and outputs distance + calculates force
void killDrive(); //turns all motors off if error
void killSensors(); //turns all sensors/lasers off if error
void moveRobot(); //sets speeds of motors

void loop(){
  
  Usb.Task();

  if (Xbox.XboxReceiverConnected) {
    if (Xbox.Xbox360Connected[0]) {
      drive(); 
      arm(); 
      laser();
      distance();
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
