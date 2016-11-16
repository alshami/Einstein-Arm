// einstein Head Arduino Code ECE478 - Fall15
// Waleed Alhaddad and David Hernandez
// Using arduino Uno R3 with Sensor Shield

#include <Servo.h>  // servo library

// Servo variables using wire labeling
Servo E7, E2; // eyes UpDwn=E7, LeftRight=E2
Servo M3, M5; // cheeks/mouth Right=M3, Left=M5
Servo B4, B6; // Brows Right=B4, Left=B6
Servo N9, N10; // Neck sideTilt=N10, rotate"No"=N9
Servo U8, U1;  // Unknown-using for Jaw Left=U8, Right=U1

Servo shoulder, rotate; // Shoulder control servos

void setup(){
 // assigning variable to i/o pins
  E2.attach(2); // moves eyes left/right
  E7.attach(7); // moves eyes up/down
  M3.attach(3); // right cheek
  M5.attach(5); // left cheek
  B4.attach(4); // right brow
  B6.attach(6); // left brow
  N9.attach(9); // rotate neck left/right "No"
  N10.attach(10); // tilt neck side to side
  //U8.attach(8); // Not used
  U1.attach(1); // moving jaw up/down

  shoulder.attach(0); // move shoulder up/down
  rotate.attach(13); // rotate shoulder
  
  pinMode(11, OUTPUT); // left eye Led
  pinMode(12, OUTPUT); // right eye Led
  digitalWrite(11, HIGH); // turn left eye LED On
  digitalWrite(12,HIGH); // turn right eye LED on

//Serial.begin(9600); // Default connection rate for my BT module

  // initial state for head
//  neckNeutral();
//  eyesNeutral();
}

void loop(){
  //test();
    eyesON();
  //eyesOFF();
//eyesBlink();
//eyeWink();
  //browRight();
  shiftyEyes();
  //eyesLeft();
  //UpDownEyes();
//mouthOpenCloseSlow();
//  mouthOpenCloseFast();
//  motionNo();
// NeckTilt();
//  shoulderUp();
  shoulderRotate();

  }

void test(){
// function used for indivudual servo testing purposes
// DOWN:15 -- MIDDLE 165 --- UP:200 E7
// Left:25 -- Middle: 90 -- Right:145 N9
// tiltright:45 -- tiltmiddle: 60 --tiltleft: 100 N10
  //E7.write(127);
  U1.write(100);
  delay(500);
  U1.write(150);
  delay(1000);
  //B6.write(170);
  //delay(1U100);
  //B4.write(70);
  //delay(1000);
  //E2.write(30);
  //delay(1000);
  //N10.write(00);
  //delay(2000);
  //E2.write(100);
  // E7.write(0);

}
void motionNo(){
  neckNeutral();
  delay(500);
  neckTurnRight();
  delay(500);
//  neckNeutral();
//  delay(500);
  neckTurnLeft();
  delay(500);
  neckTurnRight();
  delay(500);
  neckNeutral();
  delay(500);
}
void NeckTilt(){
neckTiltLeft();
 delay(500);
// neckNeutral();
 // delay(500);
 neckTiltRight();
  delay(500);
  neckTiltLeft();
  delay(500);
  neckTiltRight();
  //delay(500);
  neckNeutral();
  delay(1500);
}
void mouthOpenCloseFast(){
   U1.write(100);
  delay(200);
  U1.write(150);
  delay(200);
}
void mouthOpenCloseSlow(){
   U1.write(100);
  delay(500);
  U1.write(150);
  delay(500);
}
void mouthOpen(){
   U1.write(100);
  delay(200);

}
void mouthClose(){
  U1.write(150);
  delay(200);
}
void shiftyEyes(){
//  eyesNeutral();
  //delay(500);
  eyesRight();
  delay(500);
//  eyesNeutral();
//  delay(500);
  eyesLeft();
  delay(500);
}
void UpDownEyes(){
  eyesUp();
  delay(500);
  eyesDown();
   delay(500);
}
void neckNeutral(){
  N9.write(90);
  delay(500);
  N10.write(60);
}
void neckTurnRight(){
  N9.write(145);
}
void neckTurnLeft(){
  N9.write(20);
}
void neckTiltLeft(){
N10.write(100);
}
void neckTiltRight(){
N10.write(30);
}
void eyesNeutral(){
E2.write(50);
delay(500);
 E7.write(165);
}
void eyesLeft(){
E2.write(110); // E2.write(80);
}
void eyesRight(){
E2.write(10);
}
void eyesUp(){
E7.write(180);
}
void eyesDown(){
E7.write(15);
}
void browRight(){
  B4.write(200);
  delay(1000);
  B4.write(10);
  delay(1000);
}
void browLeft(){
  B6.write(220);
}
void eyesBlink(){
  eyesON();
  delay(4000);
  eyesOFF();
  delay(500);
}
void eyesON(){
  digitalWrite(11,HIGH ); // turn left eye LED On
  digitalWrite(12,HIGH); // turn right eye LED on
}
void eyesOFF(){
  digitalWrite(11, LOW); // turn left eye LED On
  digitalWrite(12,LOW); // turn right eye LED on
}
void eyeWink(){
  digitalWrite(12,LOW); // turn right eye LED off
  delay(1000);
  digitalWrite(12,HIGH); // turn right eye LED on
  delay(1000);
}

void shoulderUp(){
  shoulder.write(0);
  delay(5000);
  shoulder.write(30);
  delay(5000);
  shoulder.write(60);
  delay(5000);
  shoulder.write(90);
  delay(5000);
  shoulder.write(120);
  delay(5000);
  shoulder.write(150);
  delay(5000);
  shoulder.write(180);
  delay(5000);
}

void shoulderRotate() {
  rotate.write(180);
  delay(5000);
  rotate.write(150);
  delay(5000);
    rotate.write(120);
  delay(5000);
    rotate.write(90);
  delay(5000);
    rotate.write(60);
  delay(5000);
    rotate.write(30);
  delay(5000);
  rotate.write(0);
  delay(5000);
}


