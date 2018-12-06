#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MeMCore.h>

MeDCMotor motor_9(M1);
MeDCMotor motor_10(M2);
MeLEDMatrix ledMtx_2(2);
MeUltrasonicSensor ultraSensor(PORT_1);
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void Read_CNY70();
double temp1;
double CNY70;
double SPD;
double Offset_R_motor;
double Offset_L_motor;
int count=0,dis=0,i=0;

void Read_CNY70()
{
    temp1 = digitalRead(15);
    temp1 += (2) * (digitalRead(14));
    temp1 += (4) * (digitalRead(17));
    temp1 += (8) * (digitalRead(16));
    temp1 += (16) * (digitalRead(18));
    CNY70 = temp1;
}

void setup(){  
    ledMtx_2.setBrightness(1);
    ledMtx_2.setBrightness(6);
    pinMode(15,INPUT);
    pinMode(14,INPUT);
    pinMode(17,INPUT);
    pinMode(16,INPUT);
    pinMode(18,INPUT);
    ledMtx_2.drawStr(0,0+7,"0");
}
void loop(){
    Read_CNY70();
    dis = ultraSensor.distanceCm();
    if(((CNY70)==(4))){
        motor_9.run(-150);
        motor_10.run(150);
    }
    else{
        if((((CNY70)==(2))) || (((CNY70)==(6))) || (((CNY70)==(1))) || (((CNY70)==(7)))|| (((CNY70)==(3)))){
            motor_9.run(-210);
            motor_10.run(10);
        }
        else{
             if((((CNY70)==(8))) || (((CNY70)==(12))) || (((CNY70)==(16))) || (((CNY70)==(28)))|| (((CNY70)==(24)))){
                motor_9.run(-10);
                motor_10.run(160);
                }
             else{
                if(((CNY70)==(31))){
                    ++count;
                    motor_9.run(-100);
                    motor_10.run(100);
                    delay(200);
                }
            }
        }
    }
  if(dis <15 && i==0)
  {
    i = 1;
    motor_9.run(-10);
    motor_10.run(210);
    delay(300);
    motor_9.run(-100);
    motor_10.run(100);
    delay(800);
    motor_9.run(-210);
    motor_10.run(10);
    delay(300);
    motor_9.run(-100);
    motor_10.run(100);
    delay(800);
    motor_9.run(-210);
    motor_10.run(10);
    delay(300);
    motor_9.run(-100);
    motor_10.run(100);
    delay(200);
  }
  if (count == 1)
    ledMtx_2.drawStr(0,0+7,"1");
  if (count == 2)
    ledMtx_2.drawStr(0,0+7,"2");
  if (count == 3)
    ledMtx_2.drawStr(0,0+7,"3");
  if (count == 4)
    ledMtx_2.drawStr(0,0+7,"4");
  if (count == 5)
    ledMtx_2.drawStr(0,0+7,"5");
  if (count == 6)
    ledMtx_2.drawStr(0,0+7,"6");
  if (count == 7)
    ledMtx_2.drawStr(0,0+7,"7");
  if (count == 8){
    ledMtx_2.drawStr(0,0+7,"8");
     while(1)
     {
        motor_9.run(0);
        motor_10.run(0);
     }
  }  
}

