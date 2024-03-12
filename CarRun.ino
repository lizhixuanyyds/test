#include <Servo.h> 
#include <SoftwareSerial.h>   
SoftwareSerial BT(8,9);           //璁剧疆钃濈墮涓庢澘瀛愮殑杩炴帴绔彛銆�  pin 5 鎺ヨ摑鐗欑殑 TXD    pin 6 鎺ヨ摑鐗欑殑 RXD
char X;
char Y; 
    // 鍙崇數鏈哄悗閫�(IN4)
void setup()
{
   Serial.begin(38400); //涓插彛鐩戣鍣ㄩ�氫俊閫熺巼锛�38400
 pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  BT.begin(38400);                  //钃濈墮閫氫俊閫熺巼锛岄粯璁や竴鑸负 38400
}
void jingxi1()
{
int i=0;
for(i=0;i<=255;i++)
{
  delay(8);
analogWrite(6,i);
analogWrite(3,i);
analogWrite(10,i);
analogWrite(5,i);
}
for(i=255;i>=0;i--)
{
analogWrite(6,i);
analogWrite(3,i);
analogWrite(10,i);
analogWrite(5,i);
delay(6);
}
}
void jingxi2()
{
  int i=0;
  for(i=0;i<=255;i++)
{
  delay(20);
analogWrite(6,i);
analogWrite(3,i);
analogWrite(10,i);
analogWrite(5,i);
}
for(i=255;i>=0;i--)
{
analogWrite(6,i);
analogWrite(3,i);
analogWrite(10,i);
analogWrite(5,i);
delay(15);
}
}
void jingxi3()
{
digitalWrite(4,HIGH);
}
void jingxi4()
{
digitalWrite(4,LOW);
}
void kong()
{
digitalWrite(3,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(10,LOW);
  
}
void loop()
{
  if (Serial.available())           //妫�娴嬶細銆愪覆鍙ｃ�戝鏋滄暟鎹啓鍏ワ紝鍒欐墽琛屻��
  {
    X = Serial.read();              //鎶婂啓鍏ョ殑鏁版嵁缁欏埌鑷畾涔夊彉閲�  X
    BT.print(X);                    //鎶婃暟鎹粰钃濈墮
  }
  if (BT.available()) 
  {
   X=BT.read();
   if(X=='I')
   {
int i=0;
for(i=0;i<=255;i++)
{
  delay(8);
analogWrite(6,i);
analogWrite(3,i);
analogWrite(10,i);
analogWrite(5,i);
}
for(i=255;i>=0;i--)
{
analogWrite(6,i);
analogWrite(3,i);
analogWrite(10,i);
analogWrite(5,i);
delay(6);
}
}
   else if(X=='H')
  {
  int i=0;
  for(i=0;i<=255;i++)
{
  delay(20);
analogWrite(6,i);
analogWrite(3,i);
analogWrite(10,i);
analogWrite(5,i);
}
for(i=255;i>=0;i--)
{
analogWrite(6,i);
analogWrite(3,i);
analogWrite(10,i);
analogWrite(5,i);
delay(15);
}
}
  else if(X=='J')
   {
digitalWrite(4,HIGH);
}
   else if(X=='G')
  {
digitalWrite(3,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(10,LOW);
  
}
   else if(X=='E')
  {
digitalWrite(4,LOW);
}
}
}



