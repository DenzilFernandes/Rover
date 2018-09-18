void setup() {
  
  Serial.begin(9600);  
}
void loop() {
  // read the sensor on analog A0:
  int rain =digitalRead(4);
  int soil=digitalRead(7);
   if(rain==1)
   Serial.print("Not raining");
   else
   Serial.print("Raining");
   Serial.print("\t");
   if(soil==0)
   Serial.println("Moisture is present");
   else
   Serial.println("No moisture");
   delay(300);
   
}
