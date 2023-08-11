#include <Snake.h>
#include <Wire.h> //i2c통신 라이브러리

Move snake;

void setup() 
{ 
  snake.begin();


} 
  
  
void loop(){
  if(Serial.available() > 0){ //데이터가 수신되는지 확인
    char ch = Serial.read();
  }
}
