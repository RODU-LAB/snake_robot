#include <Snake.h>
#include <Wire.h> //i2c통신 라이브러리

Move snake;



void setup() {
  snake.begin();
  snake.Start();
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}


void loop() {
  if( Serial.available()){
    String data = Serial.readStringUntil('\n');
    int value1 = data.substring(0,data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1);
    int value2 = data.substring(0,data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1);
    String value3 = data;
    
  if(value3 == "f"){
    digitalWrite(13,HIGH);
    snake.Forward(value1,value2);
    
  }


  if(value3 == "l"){
    digitalWrite(13,LOW);
    snake.Left(value1,value2);
  }


  if(value3 == "r"){
    digitalWrite(13,HIGH);
    snake.Right(value1,value2);
  }
 }
}
