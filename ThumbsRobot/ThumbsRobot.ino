#include <Servo.h>

#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwmDriver = Adafruit_PWMServoDriver(0x40);

Servo servo[6];
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  servo[0].attach(9);
  servo[1].attach(10);
  servo[2].attach(11);

  servo[3].attach(3);
  servo[4].attach(5);
  servo[5].attach(6);

  //pwmDriver.begin();
  //pwmDriver.setPWMFreq(51);
  Serial.begin(9600);
  //pwmDriver.setPWM(0, 0, 500);  // ID, on Time, off Time out of 4096
   //#define MIN_MG90S 102  //  4096 / 40 == 102.4 based on a general servo range
  //#define MAX_MG90S 512 // 4096 / 8 == 512    based on a general servo range
  //#define FREQUENCY_MG90SS 51 // 50 Hz (needs to add 1)
}

int tempADC[3] = {0};
void loop() {
  // put your main code here, to run repeatedly:
  
  tempADC[0] = analogRead(A0);
  servo[0].write(map(tempADC[0] , 0, 1023, 0, 180));
  servo[3].write(map(tempADC[0] , 0, 1023, 0, 180));

  tempADC[1] = analogRead(A1);
  servo[1].write(map(tempADC[1], 0, 1023, 0, 180));
  servo[4].write(map(tempADC[1], 0, 1023, 0, 180));
  

  tempADC[2] = analogRead(A2);
  servo[2].write(map(tempADC[2], 0, 1023, 0, 180));
  servo[5].write(map(tempADC[2], 0, 1023, 0, 180));

//  tempADC[0] = analogRead(A0);
////  pwmDriver.setPWM(0, 0, map(tempADC[0], 0, 1023, 102, 512));
//  servo[1].write(map(tempADC[0], 0, 1023, 0, 180));
//  servo[3].write(map(tempADC[0], 0, 1023, 0, 180));
//  servo[4].write(map(tempADC[0], 0, 1023, 0, 180));
//  servo[5].write(map(tempADC[0], 0, 1023, 0, 180));
  
  // delay(10);

}
