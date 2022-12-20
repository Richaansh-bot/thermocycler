#include "max6675.h"

int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

#define RPWM 10
#define LPWM 11
#define REN 8
#define LEN 9


int pot;
int out1;
int out2;


float set = 90;
float cur = 0;

float error = 0;
float prev_err = 0;
int Time = millis();

float P = 0;
float I = 0;
float D = 0;

float kp = 50.0;
float kd = 200.0;
float ki = 00.4;

void setup() {
  Serial.begin(9600);
  pinMode(RPWM,OUTPUT);
  pinMode(LPWM,OUTPUT);
  pinMode(LEN,OUTPUT);
  pinMode(REN,OUTPUT);
  digitalWrite(REN,HIGH);
  digitalWrite(LEN,HIGH);

  Serial.println("max6675.h");

  delay(500);

}
 
 
void loop() {
  
    cur = thermocouple.readCelsius();
    error = set - cur;
    P = kp*error;
    I += ki*error;
    
    int prev_time = Time;

    Time = millis();

    float elap_time = (Time - prev_time)/1000.0;

    D = kd*((error-prev_err)/elap_time);

    int sum = P + I + D;    



    if(sum>255)
      sum = 255;
    if(sum<0)
      sum = 0;      

    analogWrite(RPWM,0);
    analogWrite(LPWM,sum);

    prev_err = error;
    Serial.println(cur);    


  delay(300);


    
}
