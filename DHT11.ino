
void temp() {
  tempC=HT.readTemperature(); //Command to Have Variable Equal Temperature Sensor Reading in Celcius
  tempF=HT.readTemperature(true); //Command to Have Variable Equal Temperature Sensor Reading in Farenheit
  Serial.print("Temp(C)... "); //Print Message to Serial Monitor
  Serial.println(tempC); //Print Value to Serial Monitor
  Serial.print("Temp(F)... "); //Print Message to Serial Monitor
  Serial.println(tempF); //Print Value to Serial Monitor
    // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temperature (C)");
  lcd.setCursor(1,1);
  lcd.print(tempC);
  lcd.setCursor(0,2);
  lcd.print("Temperature (F): ");
  lcd.setCursor(1,3);
  lcd.print(tempF);
  delay(dT);
  lcd.clear();
}