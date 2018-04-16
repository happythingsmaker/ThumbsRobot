// Thumbs Robot made by Eunchan Park
// http://Youtube.com/EunchanPark

#include <Servo.h>

Servo servo[6];

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  servo[0].attach(9);
  servo[1].attach(10);
  servo[2].attach(11);

  servo[3].attach(3);
  servo[4].attach(5);
  servo[5].attach(6);
}

int tempADC[3] = {0};

void loop() {  
  tempADC[0] = analogRead(A0);
  servo[0].write(map(tempADC[0] , 0, 1023, 0, 180));
  servo[3].write(map(tempADC[0] , 0, 1023, 0, 180));

  tempADC[1] = analogRead(A1);
  servo[1].write(map(tempADC[1], 0, 1023, 0, 180));
  servo[4].write(map(tempADC[1], 0, 1023, 0, 180));

  tempADC[2] = analogRead(A2);
  servo[2].write(map(tempADC[2], 0, 1023, 0, 180));
  servo[5].write(map(tempADC[2], 0, 1023, 0, 180));
}
