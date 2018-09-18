#include <Servo.h>
Servo myservo1;
Servo myservo2;
#include <AFMotor.h>
int stat,pos=0;
AF_DCMotor leftMotor1(1, MOTOR12_1KHZ); // create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor leftMotor2(2, MOTOR12_1KHZ); // create motor #2, using M2 output, set to 1kHz PWM frequency
AF_DCMotor rightMotor1(3, MOTOR34_1KHZ);// create motor #3, using M3 output, set to 1kHz PWM frequency
AF_DCMotor rightMotor2(4, MOTOR34_1KHZ);// create motor #4, using M4 output, set to 1kHz PWM frequency
void setup() 
{
 myservo1.attach(10);
 myservo2.attach(9);
 Serial.begin(9600); 
}
void loop()
{
    Serial.println(stat);
    Release();
     if(stat==0)
     Forward();
     else
    { 
     //Release();
     stat=0;
     //delay(1000);
    }
}  
  void Forward()
 {
   for (pos = 0; pos <= 25; pos += 1) 
  { 
    myservo1.write(pos);
   
    delay(15);
  }
  for (pos = 25; pos >= 0; pos -= 1) 
  {
    myservo1.write(pos);
    delay(15);
  }
  leftMotor1.run(FORWARD);
  leftMotor1.setSpeed(150);
  leftMotor2.run(FORWARD);
  leftMotor2.setSpeed(150);
  rightMotor1.run(FORWARD);
  rightMotor1.setSpeed(150);
  rightMotor2.run(FORWARD);
  rightMotor2.setSpeed(150);
  //delay(20000);
  stat=1;
}
void Release()
{
  leftMotor1.run(RELEASE);
  leftMotor2.run(RELEASE);
  rightMotor1.run(RELEASE);
  rightMotor2.run(RELEASE);
  for (pos = 0; pos <= 45; pos += 1) 
  { 
    myservo2.write(pos);
    delay(1000);
   }
  
  for (pos = 45; pos >= 0; pos -= 1) 
  {
    myservo2.write(pos);
    delay(1000);
  }
  //delay(2000);
}
