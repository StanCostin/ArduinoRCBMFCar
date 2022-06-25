#include <Servo.h>
#include <NewPing.h>
#define MOTORA_1 2
#define MOTORA_2 3
#define MOTORB_1 4
#define MOTORB_2 5
#define LED1FRONT 10
#define LED2FRONT 11
#define LED3BACK 6
#define LED4BACK 7
#define SOUNDCAR 8
#define SERVOMOTOR 9
#define TRIG A1
#define ECHO A2
#define SENSORSOUND A0
#define MAX_DISTANCE 200
NewPing sonar(TRIG, ECHO, MAX_DISTANCE);
Servo obstacle;
String readData;
char data = 0;
boolean goesFwd = false;
int distance = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTORA_1, OUTPUT);
  pinMode(MOTORA_2, OUTPUT);
  pinMode(MOTORB_1, OUTPUT);
  pinMode(MOTORB_2, OUTPUT);
  pinMode(LED1FRONT, OUTPUT);
  pinMode(LED2FRONT, OUTPUT);
  pinMode(LED3BACK, OUTPUT);
  pinMode(LED4BACK, OUTPUT);
  pinMode(SOUNDCAR, OUTPUT);
  obstacle.attach(9);

  obstacle.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  
  Serial.begin(9600); 
}

int lookRight(){  
  obstacle.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  obstacle.write(115);
  return distance;
}

int lookLeft(){
  obstacle.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  obstacle.write(115);
  return distance;
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void goForward() {
  digitalWrite(MOTORA_1, HIGH);
  digitalWrite(MOTORA_2, LOW);
  digitalWrite(MOTORB_1, HIGH);
  digitalWrite(MOTORB_2, LOW);
  
}

void stopNow() {

  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, LOW);
  
}

void goBackWard() {
  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, HIGH);
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, HIGH);
}

void goLeft() {

  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, HIGH);
  digitalWrite(MOTORA_1, HIGH);
  digitalWrite(MOTORA_2, LOW);
}

void goRight() {

  digitalWrite(MOTORB_1, HIGH);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(MOTORA_2, HIGH);
  digitalWrite(MOTORA_1, LOW);
  
}

void frontLightsOn() {

  digitalWrite(LED1FRONT, HIGH);
  digitalWrite(LED2FRONT, HIGH);
  
}

void frontLightsOff() {

  digitalWrite(LED1FRONT, LOW);
  digitalWrite(LED2FRONT, LOW);
  
}

void backLightsOn() {

  digitalWrite(LED3BACK, HIGH);
  digitalWrite(LED4BACK, HIGH);
  
}

void backLightsOff() {

  digitalWrite(LED3BACK, LOW);
  digitalWrite(LED4BACK, LOW);
  
}

void hornOn() {
  tone(SOUNDCAR, 340);
}

void hornOff() {
  noTone(SOUNDCAR);
}

void moveStop(){
  
  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, LOW);
}

void moveForward(){

  if(!goesFwd){

    goesFwd=true;
    
  digitalWrite(MOTORA_1, HIGH);
  digitalWrite(MOTORA_2, LOW);
  digitalWrite(MOTORB_1, HIGH);
  digitalWrite(MOTORB_2, LOW);
  
  }
}

void moveBackward(){

  goesFwd=false;

  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, HIGH);
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, HIGH);
  
}

void turnRight(){

  digitalWrite(MOTORB_1, HIGH);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(MOTORA_2, HIGH);
  digitalWrite(MOTORA_1, LOW);
  
  delay(250);
  
  digitalWrite(MOTORB_1, HIGH);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(MOTORA_2, HIGH);
  digitalWrite(MOTORA_1, LOW);
 
}

void turnLeft(){

  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, HIGH);
  digitalWrite(MOTORA_1, HIGH);
  digitalWrite(MOTORA_2, LOW);

  delay(250);
  
  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, HIGH);
  digitalWrite(MOTORA_1, HIGH);
  digitalWrite(MOTORA_2, LOW);
}


void commandForward(){
  digitalWrite(MOTORA_1, HIGH);
  digitalWrite(MOTORA_2, LOW);
  digitalWrite(MOTORB_1, HIGH);
  digitalWrite(MOTORB_2, LOW);

  delay(1500);

  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, LOW);
  
}

void commandBackward(){
  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, HIGH);
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, HIGH);

  delay(1500);

  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, LOW);
  
}

void commandLeft(){
  obstacle.write(180);
  delay(500);
  obstacle.write(90);
  delay(500);
  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, HIGH);
  digitalWrite(MOTORA_1, HIGH);
  digitalWrite(MOTORA_2, LOW);

  delay(1500);

  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, LOW);
  
}

void commandRight(){
  obstacle.write(0);
  delay(500);
  obstacle.write(90);
  delay(500);
  digitalWrite(MOTORB_1, HIGH);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(MOTORA_2, HIGH);
  digitalWrite(MOTORA_1, LOW);

  delay(1500);

  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, LOW);
  
}

void commandStop(){
  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

//  if(Serial.available() > 0) {
//    stopNow();
//    char data = Serial.read();
//    Serial.println(data);
//    if(data == 'F') {
//      goForward();
//    } else if (data == 'W'){
//      frontLightsOn();
//    } else if (data == 'w') {
//      frontLightsOff();
//    } else if (data == 'U') {
//      backLightsOn();
//    } else if (data == 'u') {
//      backLightsOff();
//    } else if (data == 'D') {
//      stopNow();
//    } else if (data == 'S'){
//      stopNow();
//    } else if (data == 'B') {
//      goBackWard();
//    } else if (data == 'L') {
//      goLeft();
//    } else if (data == 'R') {
//      goRight();
//    } else if (data == 'V') {
//      hornOn();
//    }  else if (data == 'v') {
//      hornOff();
//    }
//    else {
//      data = '0';
//    }  
//  }


//  long sum = 0;
//  for(int i=0;i<100;i++)
//  {
//    sum+=analogRead(SENSORSOUND);
//  }
//  sum/=100;
//  
//  if (sum>=10) digitalWrite(LED1FRONT, HIGH); else digitalWrite(LED1FRONT, LOW);
//  if (sum>=20) digitalWrite(LED2FRONT, HIGH); else digitalWrite(LED2FRONT, LOW);
//  if (sum>=30) digitalWrite(LED3BACK, HIGH); else digitalWrite(LED3BACK, LOW);
//  if (sum>=40) digitalWrite(LED4BACK, HIGH); else digitalWrite(LED4BACK, LOW);
//  if (sum>=50) digitalWrite(LED1FRONT, HIGH); else digitalWrite(LED1FRONT, LOW);
//  if (sum>=60) digitalWrite(LED2FRONT, HIGH); else digitalWrite(LED2FRONT, LOW);
//  if (sum>=70) digitalWrite(LED3BACK, HIGH); else digitalWrite(LED3BACK, LOW);
//  if (sum>=80) digitalWrite(LED4BACK, HIGH); else digitalWrite(LED4BACK, LOW);
//  if (sum>=90) digitalWrite(LED1FRONT, HIGH); else digitalWrite(LED1FRONT, LOW);
//  if (sum>=95) digitalWrite(LED3BACK, HIGH); else digitalWrite(LED3BACK, LOW);
//  if (sum>=100) digitalWrite(LED1FRONT, HIGH); else digitalWrite(LED1FRONT, LOW);
//  if (sum>=200) digitalWrite(LED2FRONT, HIGH); else digitalWrite(LED2FRONT, LOW);
//  if (sum>=300) digitalWrite(LED3BACK, HIGH); else digitalWrite(LED3BACK, LOW);
//  if (sum>=350) digitalWrite(LED4BACK, HIGH); else digitalWrite(LED4BACK, LOW);
//  if (sum>=400) digitalWrite(LED1FRONT, HIGH); else digitalWrite(LED1FRONT, LOW);
//  if (sum>=450) digitalWrite(LED2FRONT, HIGH); else digitalWrite(LED2FRONT, LOW);
//  if (sum>=500) digitalWrite(LED3BACK, HIGH); else digitalWrite(LED3BACK, LOW);
//  if (sum>=550) digitalWrite(LED4BACK, HIGH); else digitalWrite(LED4BACK, LOW);
//  if (sum>=600) digitalWrite(LED1FRONT, HIGH); else digitalWrite(LED1FRONT, LOW);
//  if (sum>=650) digitalWrite(LED2FRONT, HIGH); else digitalWrite(LED2FRONT, LOW);
//  if (sum>=700) digitalWrite(LED3BACK, HIGH); else digitalWrite(LED3BACK, LOW);
//  if (sum>=750) digitalWrite(LED4BACK, HIGH); else digitalWrite(LED4BACK, LOW);
//  if (sum>=800) digitalWrite(LED1FRONT, HIGH); else digitalWrite(LED1FRONT, LOW);
//  if (sum>=850) digitalWrite(LED2FRONT, HIGH); else digitalWrite(LED2FRONT, LOW);
//  if (sum>=900) digitalWrite(LED3BACK, HIGH); else digitalWrite(LED3BACK, LOW);
//  if (sum>=940) digitalWrite(LED4BACK, HIGH); else digitalWrite(LED4BACK, LOW);
//  if (sum>=980) digitalWrite(LED1FRONT, HIGH); else digitalWrite(LED1FRONT, LOW);
//  if (sum>=1000) digitalWrite(LED2FRONT, HIGH); else digitalWrite(LED2FRONT, LOW);
//  Serial.println(sum);
//  obstacle.write(sum/10*12);
//  goLeft();
//  delay(sum/100);
//  stopNow();
//  delay(sum);
//  goRight();
//  delay(sum);
//  stopNow();
//  delay(sum);
  //delay(10);
  

  
  if(Serial.available() > 0)
  {
    readData = "";
  }

  while(Serial.available()){
      data = ((byte)Serial.read());
      
      if(data == ':') {
        break;
      } else { 
        readData += data;
      }
      delay(1);
    }

  Serial.println(readData);
  
  if(readData == "UP") {
    goForward();
  } else if (readData == "DOWN") {
    goBackWard();
  } else if (readData == "LEFT") {
    goLeft();
  } else if (readData == "RIGHT") {
    goRight();
  } else if (readData == "HONK") {
    hornOn();
  } else if (readData == "STOP HONK") {
    hornOff();
  } else if (readData == "TURN ON FRONT LIGHTS") {
    frontLightsOn();
  } else if (readData == "TURN OFF FRONT LIGHTS") {
    frontLightsOff();
  } else if (readData == "TURN ON BACK LIGHTS") {
    backLightsOn();
  } else if (readData == "TURN OFF BACK LIGHTS") {
    backLightsOff();
  } else if (readData == "STOP") {
    stopNow();
  } else if (readData == "DISCONNECT") {
    stopNow();
    hornOff();
    frontLightsOff();
    backLightsOff();
  } else {
    data = 0;
  }

  if(readData == "OBSTACLE ON") {
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
  
  if (distance <= 35){
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);
    
    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
    
  } else if(readData == "OBSTACLE OFF") {
    moveStop();
    obstacle.write(115);
    distance = 0;
  } else if(readData == "OBSTACLEDISC") {
    moveStop();
    distance = 0;
    obstacle.write(115);
  }

  if(readData.startsWith("!")) {
    String commandValue = readData.substring(1);

    if(commandValue.startsWith("TURN ON LEFT FRONT LIGHT")) {
      
      digitalWrite(LED1FRONT, HIGH);
      
    } else if(commandValue.startsWith("TURN OFF LEFT FRONT LIGHT")) {
      
      digitalWrite(LED1FRONT, LOW);
      
    } else if(commandValue.startsWith("TURN ON RIGHT FRONT LIGHT")) {
      
      digitalWrite(LED2FRONT, HIGH);
      
    } else if(commandValue.startsWith("TURN OFF RIGHT FRONT LIGHT")) {
      
      digitalWrite(LED2FRONT, LOW);
      
    } else if(commandValue.startsWith("TURN ON LEFT BACK LIGHT")) {
      
      digitalWrite(LED4BACK, HIGH);
      
    } else if(commandValue.startsWith("TURN OFF LEFT BACK LIGHT")) {
      
      digitalWrite(LED4BACK, LOW);
      
    } else if(commandValue.startsWith("TURN ON RIGHT BACK LIGHT")) {
      
      digitalWrite(LED3BACK, HIGH);
      
    } else if(commandValue.startsWith("TURN OFF RIGHT BACK LIGHT")) {
      
      digitalWrite(LED3BACK, LOW);
      
    } else if(commandValue.startsWith("TURN ON FRONT LIGHTS")) {
      
      frontLightsOn();
      
    } else if(commandValue.startsWith("TURN OFF FRONT LIGHTS")) {
      
      frontLightsOff();
      
    } else if(commandValue.startsWith("TURN ON BACK LIGHTS")) {
      
      backLightsOn();
      
    } else if(commandValue.startsWith("TURN OFF BACK LIGHTS")) {
      
      backLightsOff();
      
    } else if(commandValue.startsWith("LIGHTS ON")) {

      frontLightsOn();
      backLightsOn();

    } else if(commandValue.startsWith("LIGHTS OFF")) {

      frontLightsOff();
      backLightsOff();
       
    } else if(commandValue.startsWith("BLINK")) {

      frontLightsOn();
      delay(1000);
      frontLightsOff();
      delay(1000);
      backLightsOn();
      delay(1000);
      backLightsOff();
      delay(1000);
      
    } else if(commandValue.startsWith("MOVE FORWARD")) {

      commandForward();
      delay(1500);
      commandStop();
      readData = "";
      commandValue = "";
       
    } else if(commandValue.startsWith("MOVE BACKWARD")) {

      commandBackward();
      delay(1500);
      commandStop();
      readData = "";
      commandValue = "";
       
    } else if(commandValue.startsWith("TURN LEFT")) {

      commandLeft();
      delay(1000);
      commandStop();
      readData = "";
      commandValue = "";
       
    } else if(commandValue.startsWith("TURN RIGHT")) {

      commandRight();
      delay(1000);
      commandStop();
      readData = "";
      commandValue = "";
      
    }
  }
  
}
