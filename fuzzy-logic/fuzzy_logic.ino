//Srijana Sapkota, Naser Alshami
//ECE 478, Intellignet Robotics, Fall 2016
//Effective Range: 10-80 cm 
//Source : http://www.geeetech.com/wiki/index.php/SHARP_IR_Ranger_Sensor_GP2D12_for_Arduino
//Code for testing IR sensor outputs 
// Outputs monitored using Serial Monitor tool in Arduino

#include <Servo.h>  // Servo library
Servo N9, E2;

int val;
char GP2D12;
char a,b;
void setup()
{
 Serial.begin(9600); //
  N9.attach(9);
  E2.attach(2);
  digitalWrite(11, HIGH); // turn left eye LED On
  digitalWrite(12,HIGH); // turn right eye LED on
}
void loop()
{
 GP2D12=read_gp2d12_range(0);
 a=GP2D12/10;
 b=GP2D12%10;
 val=a*10+b;
 if(val>10&&val<80)
 {
   Serial.print(a,DEC);//
   Serial.print(b,DEC);//
   Serial.println("cm");//
 }
 else Serial.println("over");//
 delay(50);
  sensor();
}
void sensor()
{
if (val>10&&val<30)
{
  neckTurnRight();
  delay(500);
  neckTurnRight();
}
if (val>30&&val<50)
{
  neckNeutral();
  delay(500);
  eyesNeutral();
}
if (val>50)
{
  neckTurnLeft();
  delay(500);
  eyesLeft();
}
}

float read_gp2d12_range(byte pin)
{
 int tmp;
 tmp = analogRead(pin);
 if (tmp < 3)return -1;
 return (6787.0 /((float)tmp - 3.0)) - 4.0;
}

void neckNeutral(){
  N9.write(90);
}

void neckTurnRight(){
  N9.write(145);
}
void neckTurnLeft(){
  N9.write(20);
}

void eyesNeutral(){
E2.write(50);
delay(500);
}
void eyesLeft(){
E2.write(110); // E2.write(80);
}
void eyesRight(){
E2.write(10);
}
