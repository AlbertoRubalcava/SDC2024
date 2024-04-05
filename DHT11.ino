
void temp() {
  tempF=HT.readTemperature(true); //Command to Have Variable Equal Temperature Sensor Reading in Farenheit

  Serial.print("Temp(F)... "); //Print Message to Serial Monitor
  Serial.println(tempF); //Print Value to Serial Monitor
    // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.setCursor(13,0);
  lcd.print(tempF);
  lcd.setCursor(18,0);
  lcd.print("F");

//--------------------------

  lcd.setCursor(0,1);
  lcd.print("Servo Speed: ");

  //------------
  lcd.setCursor(0,2);
  lcd.print("Stepper Angle: ");

  //---------------
  
  delay(dT);
  lcd.clear();
}