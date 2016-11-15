//Srijana Sapkota, Naser Alshami
//ECE 478, Intellignet Robotics, Fall 2016
//Effective Range: 10-80 cm 
//Source : http://www.geeetech.com/wiki/index.php/SHARP_IR_Ranger_Sensor_GP2D12_for_Arduino
//Code for testing IR sensor outputs 
// Outputs monitored using Serial Monitor tool in Arduino

char GP2D12;
char a,b;
void setup()
{
 Serial.begin(9600); //
}
void loop()
{
 int val;
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
}
float read_gp2d12_range(byte pin)
{
 int tmp;
 tmp = analogRead(pin);
 if (tmp < 3)return -1;
 return (6787.0 /((float)tmp - 3.0)) - 4.0;
}


