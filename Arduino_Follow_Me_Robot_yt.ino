//Arduino Human Following Robot
// You have to Install the AFMotor and NewPing library Before Uploading the sketch//
// To install the libraries ( first download the AF Motor driver, NewPing and Servo Library zip file //
// then Go to Skecth >> Include Library >> Add .Zip Library >> Select The downloaded zip file >> Done) //
// Contact me on instagram for any question(Insta Id : M_ideas_youtube)


#include<NewPing.h>
#include<Servo.h>
 
#define RIGHT A2
#define LEFT A3
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100

#define IN1 5
#define IN2 6
#define IN3 7
#define IN4 8
  

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

#define MOTOR_SPEED 255 // Adjust the speed as needed

Servo myservo;
 
int pos =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
myservo.attach(10);
{
for(pos = 90; pos <= 180; pos += 1){
  myservo.write(pos);
  delay(15);
} for(pos = 180; pos >= 0; pos-= 1) {
  myservo.write(pos);
  delay(15);
}for(pos = 0; pos<=90; pos += 1) {
  myservo.write(pos);
  delay(15);
}
}
pinMode(RIGHT, INPUT);
pinMode(LEFT, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(50);
 unsigned int distance = sonar.ping_cm();
// Serial.print("distance");
// Serial.println(distance);


int Right_Value = digitalRead(RIGHT);
int Left_Value = digitalRead(LEFT);

// Serial.print("RIGHT");
// Serial.println(Right_Value);
// Serial.print("LEFT");
// Serial.println(Left_Value);

if((Right_Value==1) && (distance>=10 && distance<=30)&&(Left_Value==1))
{
  moveForward(MOTOR_SPEED);
}
else if((Right_Value==0) && (Left_Value==1)) 
{
  turnRight(MOTOR_SPEED);
}
else if((Right_Value==1)&&(Left_Value==0)) 
{
  turnLeft(MOTOR_SPEED);
}
else if((Right_Value==1)&&(Left_Value==1)) 
{
  stopmotors(MOTOR_SPEED);
}
else if(distance > 1 && distance < 10) 
  {
    moveBackward(MOTOR_SPEED);
  }
}
void moveForward(int speed) 
{
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, speed);
  digitalWrite(IN3, HIGH);
  analogWrite(IN4, speed);
  Serial.println("moveForward");
}
void turnLeft( int speed) 
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  Serial.println("turnleft");
}
void turnRight( int speed) 
{
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, speed/1.22994);
  digitalWrite(IN3, HIGH);
  analogWrite(IN4, speed/2.3181818);
  Serial.println("turnright"); 
}
void moveBackward(int speed) 
{
  digitalWrite(IN1, speed);
  analogWrite(IN2, HIGH);
  digitalWrite(IN3, speed);
  analogWrite(IN4, HIGH);
  Serial.println("moveBackward");
}
void stopmotors(int speed) 
{
  digitalWrite(IN1, LOW);
  analogWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  analogWrite(IN4, LOW);
  Serial.println("stop motors");
}
