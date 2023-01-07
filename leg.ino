#include <Servo.h>

Servo servo;
Servo servo2;

float angle = 0;
float angle2 = 360;
void setup(){
 servo.attach(14);
 servo2.attach(15); 
}

void loop(){
 delay(2);
 if(angle>=360){
  angle -= 360;
 }
 if(angle2<=0){
  angle2 += 360;
 }
 angle+=2;
 angle2-=2;
 servo.write(angle);
 servo2.write(angle2);
}
