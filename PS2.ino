#include <SoftwareSerial.h>          //库文件

SoftwareSerial BT(2,3);           //设置蓝牙与板子的连接端口。  pin 5  接蓝牙的 TXD    pin 6 接蓝牙的 RXD
char X; //定义一个变量存数据。
int JoyStick1_X = A1; //x
int JoyStick1_Y = A0; //y 
int JoyStick1_Z = 8; //key4
int JoyStick2_X = A3; //x
int JoyStick2_Y = A2; //y 
int JoyStick2_Z = 9;
int pz1 = 1; // 上一次读取的值
int pz2 = 1;
int a=1;
int b=2;
void setup() 
{
  Serial.begin(9600); // 57600 bps
  Serial.println("蓝牙连接正常");     //串口监视器显示蓝牙正常状态
  BT.begin(38400);                  //蓝牙通信速率，默认一般为 38400
  pinMode(JoyStick1_Z, INPUT);      //设置模拟和数字端口的输入输出模式
  pinMode(JoyStick2_Z, INPUT);
   pinMode(JoyStick1_X, INPUT);
  pinMode(JoyStick2_X, INPUT);
   pinMode(JoyStick1_Y, INPUT);
  pinMode(JoyStick2_Y, INPUT);
  
  
}
void loop() 
{
  int x1,y1,z1,x2,y2,z2;         //设置端口
  char X;
  char Y;
  x1=analogRead(JoyStick1_X);//手柄x值控制小车左右移动，手柄y值控制小车前后移动，手柄z值是数字量，z=1或0，控制车灯的亮灭。
  y1=analogRead(JoyStick1_Y);//AD转换，将手柄0-5V电压转换为10位二进制数据（0~1023），对采样数据进行判决。
  z1=digitalRead(JoyStick1_Z);
  x2=analogRead(JoyStick2_X);
  y2=analogRead(JoyStick2_Y);
  z2=digitalRead(JoyStick2_Z);
  if(x2>600)                  //x值采样判决
  { 
    if(x1>600)
   {BT.print("5");}           //根据采样数据发送相关指令符号。
   else
   { BT.print("L");}
   }
  else if(y2>600)             //y值采样判决
  { 
    if(x1>600)
    {
      BT.print("Z");
    }
    else if(x1<400)
    {
       BT.print("X");
    }
    else
    {BT.print("F");}
  }
  else if(y2<400)
  { 
   BT.print("B");
  }
   else if(x2<400)
   {
    if(x1<400)
   {BT.print("6");}
    else
    {BT.print("R");}
   }
   else if((z1!=pz1)||(z2!=pz2))
   {
     if((z1==0)||(z2==0))
     {
       BT.print(a);
       a=!a;
       pz1=z1;
       pz2=z2;
     }
   }
   else if(y1>600)
   {
     BT.print("3");
   }
   else if(y1<400)
   {
     BT.print("4");
   }
   else {BT.print("S");}
  delay(10);
}
