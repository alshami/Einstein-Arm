 
#include <Servo.h>


Servo hand_servo0;
Servo hand_servo1;
Servo hand_servo2;
Servo hand_servo3;
Servo hand_servo4;  // create servo object to control a servo
                // a maximum of eight servo objects can be created
 
int pos0, pos1, pos2, pos3, pos4 = 0;    // variable to store the servo position

void setup()
{
  hand_servo0.attach(0);  
  hand_servo1.attach(1);  
  hand_servo2.attach(2);  
  hand_servo3.attach(3); 
  hand_servo4.attach(4);  // attaches the servo on pin 9 to the servo object
  for (int x = 0; x < 3; x++)
    {
      hand_servo4.write(180);
      delay(1000);
      hand_servo3.write(180);
      delay(1000);
      hand_servo2.write(180);
      delay(1000);
      hand_servo1.write(180);
      delay(1000);
      hand_servo0.write(180);
      delay(1000);
      hand_servo4.write(0);
      hand_servo3.write(0);
      hand_servo2.write(0);
      hand_servo1.write(0);
      hand_servo0.write(0);
      delay(1000);
}
}
void loop()
{

}

/*
void loop()   // count up loop
{
    for (int x = 0; x = 3; x++)
    {
      hand_servo4.write(180);
      delay(1000);
      hand_servo3.write(180);
      delay(1000);
      hand_servo2.write(180);
      delay(1000);
      hand_servo1.write(180);
      delay(1000);
      hand_servo0.write(180);
      delay(1000);
      hand_servo4.write(0);
      hand_servo3.write(0);
      hand_servo2.write(0);
      hand_servo1.write(0);
      hand_servo0.write(0);
      delay(1000);
    }
}
*/
/* 
void loop()
{
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    hand_servo4.write(pos);              // tell servo to go to position in variable 'pos'
    hand_servo2.write(pos);
    hand_servo0.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees
  {
    hand_servo4.write(pos);              // tell servo to go to position in variable 'pos'
    hand_servo2.write(pos);
    hand_servo0.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

*/
