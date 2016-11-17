//Effective Range: 10-80 cm 

//Code for testing IR sensor outputs 
// Outputs monitored using Serial Monitor tool in Arduino

#include <Servo.h>  // Servo library

#define NECK_NEUTRAL 90
#define NECK_SLOW_LEFT 45
#define NECK_LEFT 20
#define NECK_SLOW_RIGHT 120
#define NECK_RIGHT 145

Servo N9, E2;


char GP2D12;
char GP2D12_b;
char a,b,x,y;
int rs_val;
int ls_val;

void setup()
{
 Serial.begin(9600); //
  N9.attach(9);
 // E2.attach(2);
  //digitalWrite(11, HIGH); // turn left eye LED On
  //digitalWrite(12,HIGH); // turn right eye LED on

}
void loop()
{

 GP2D12=read_gp2d12_range(0);
 a=GP2D12/10;
 b=GP2D12%10;
 rs_val=a*10+b;

 GP2D12_b=read_gp2d12_range(1);
 x=GP2D12_b/10;
 y=GP2D12_b%10;
 ls_val=x*10+y;

if ((rs_val>10&&rs_val<80) && (ls_val>10&&ls_val<80))
{
   Serial.print("Right Sensor: ");
   Serial.print(a,DEC);//
   Serial.print(b,DEC);//
   Serial.print("cm - ");//
   Serial.print("Left  Sensor 2: ");
   Serial.print(x,DEC);//
   Serial.print(y,DEC);//
   Serial.println("cm  ");//
}
if ((rs_val>10&&rs_val<80) && (ls_val<10|ls_val>80))
{
   Serial.print("Right Sensor: ");
   Serial.print(a,DEC);//
   Serial.print(b,DEC);//
   Serial.print("cm - ");//
   Serial.println("Sensor 2: over");
}
if ((rs_val<10|rs_val>80) && (ls_val>10&&ls_val<80))
{
   Serial.print("Sensor 1: over - ");
   Serial.print("Sensor 2: ");
   Serial.print(x,DEC);//
   Serial.print(y,DEC);//
   Serial.println("cm  ");//
}
  else Serial.println("over");
   delay(50);
   
}

float read_gp2d12_range(byte pin)
{
 int tmp;
 tmp = analogRead(pin);
 if (tmp < 3)return -1;
 return (6787.0 /((float)tmp - 3.0)) - 4.0;
}

/*
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
*/

void fuzzy(){
  float rs_close, rs_medium, rs_far;
  float ls_close, ls_medium, ls_far;

  float sum_all_mins, sum_rotation_times_min;
  float final_fuzzy_output;
  float min1, min2, min3, min4, min5, min6, min7, min8, min9;
  
  if (rs_val <= 20)
  {
    rs_close = 1;
    rs_medium = 0;
    rs_far = 0;
  }
  if (rs_val > 20 && rs_val < 40)
  {
    rs_close = (-rs_val/20) + 2;
    rs_medium = (rs_val/20) - 1;
    rs_far = 0;
  }
  if (rs_val = 40)
  {
    rs_close = 0;
    rs_medium = 1;
    rs_far = 0;
  }
  if (rs_val > 40 && rs_val < 60)
  {
    rs_close = 0;
    rs_medium = (-rs_val/20) + 3;
    rs_far = (rs_val/20) - 2;
  }
  if (rs_val >= 60)
  {
    rs_close = 0;
    rs_medium = 0;
    rs_far = 1;
  }

   if (ls_val <= 20)
  {
    ls_close = 1;
    ls_medium = 0;
    ls_far = 0;
  }
  if (ls_val > 20 && ls_val < 40)
  {
    ls_close = (-ls_val/20) + 2;
    ls_medium = (ls_val/20) - 1;
    ls_far = 0;
  }
  if (ls_val = 40)
  {
    ls_close = 0;
    ls_medium = 1;
    ls_far = 0;
  }
  if (ls_val > 40 && ls_val < 60)
  {
    ls_close = 0;
    ls_medium = (-rs_val/20) + 3;
    ls_far = (rs_val/20) - 2;
  }
  if (ls_val >= 60)
  {
    ls_close = 0;
    ls_medium = 0;
    ls_far = 1;
  }
    min1 = min(ls_close, rs_close);
    min2 = min(ls_close, rs_medium);
    min3 = min(ls_close, rs_far);
    min4 = min(ls_medium, rs_close);
    min5 = min(ls_medium, rs_medium);
    min6 = min(ls_medium, rs_far);
    min7 = min(ls_far, rs_close);
    min8 = min(ls_far, rs_medium);
    min9 = min(ls_far, rs_far);

    sum_all_mins = min1+min2+min3+min4+min5+min6+min7+min8+min9;

    sum_rotation_times_min = (min1 *NECK_NEUTRAL) + (min2 * NECK_SLOW_LEFT) + (min3 * NECK_LEFT) + (min4 * NECK_SLOW_RIGHT) + (min5 * NECK_NEUTRAL) + (min6 * NECK_SLOW_LEFT) + (min7 * NECK_RIGHT) + (min8 * NECK_SLOW_RIGHT) + (min9 * NECK_NEUTRAL);

    final_fuzzy_output = sum_rotation_times_min/sum_all_mins;

    N9.write(final_fuzzy_output);
  
}
