#include <PRIZM.h>

PRIZM prizm;

bool hasStopped= false;

void setup() {
  prizm.PrizmBegin();
  prizm.setMotorInvert(1,1);
  Serial.begin(9600); 
  prizm.setServoPosition(1,20);
}

void loop() {

int distance = prizm.readSonicSensorCM(2);

if(distance >= 15 && hasStopped == false){
  Serial.print("Moving Forward");
  prizm.setMotorSpeeds(360,360);
  delay(500);
} else if (distance < 15){
  Serial.print("Stopping");
  prizm.setMotorPowers(125,125);
  delay(50);
  prizm.setServoPosition(1,180);
  hasStopped= true;
} else {
 if(hasStopped = true && distance >= 10 ){
  Serial.print("Starting Turn");
  prizm.setMotorSpeeds(-90,90);
  prizm.setServoPosition(1,90);
  delay(1000);
  prizm.setMotorSpeeds(360,360);
  delay(4000);
  prizm.setMotorSpeeds(90,-90);
  delay(1000);
  prizm.setMotorSpeeds(360,360);
  delay(2000);
  Serial.print("Ending");
  prizm.PrizmEnd();
 }
}
}
