/*Copyright by GPSoft (GicoPiro 2014)*/

long time[2] = {0, 0}, cm[2] = {0, 0};
int echo[2] = {7, 9}, trig[2] = {8, 10}, engines[2] = {11, 13};
long minDistance = 45;
boolean turningRight = false, turningLeft = false;
  
 void setup(){
   initSensors(0);
   initSensors(1);
   initEngines(0);
   initEngines(1);
}

void initSensors(int num){
  pinMode(echo[num], INPUT);
  pinMode(trig[num], OUTPUT);
}

void initEngines(int num){
  pinMode(engines[num], OUTPUT);
}

void engineLogic(){
 
  if (!checkSensors(0) && !checkSensors(1) && !turningRight && !turningLeft){
    digitalWrite(engines[0], HIGH);
    digitalWrite(engines[1], HIGH);
  }else{
    turningRight = true;
  }
 
 if (turningRight){
   turningLeft = false;
   digitalWrite(engines[1], LOW);
   digitalWrite(engines[0], HIGH);
   if (!checkSensors(0) && !checkSensors(1)){
     turningRight = false;
   }else{
     turningLeft = true;
   }
 }
 
 if (turningLeft){
   turningRight = false;
   digitalWrite(engines[0], LOW);
   digitalWrite(engines[1], HIGH);
   if (!checkSensors(0) && !checkSensors(1)){
     turningLeft = false;
   }else{
     turningRight = true;
   }
 }
  
}

boolean checkSensors(int num){
 digitalWrite(trig[num], LOW);
 delayMicroseconds(2);
 digitalWrite(trig[num], HIGH);
 delayMicroseconds(2);
 digitalWrite(trig[num], LOW);
 
 time[num] = pulseIn(echo[num], HIGH);
 /*
  v = 2s/t
  s = vt/2
  v = 340 m/s
  s = 340*(time/1000000)/2
 */
 cm[num] = time[num]/58.2;
 if(cm[num] <= minDistance && cm[num] != 0){
   return true;
 }else{
   return false;
 }
}

void loop(){
 engineLogic();
}

