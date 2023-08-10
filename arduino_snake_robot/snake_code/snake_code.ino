#include <Snake.h>
#include <Wire.h> //i2c통신 라이브러리



void serial_data(){
    String data = Serial.readStringUntil('\n');
    int value1 = data.substring(0,data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1);
    int value2 = data.substring(0,data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1);
    String value3 = data;
}

void setup() {
  snake.begin();
  snake.Start();
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}


void loop() {
  if( Serial.available()){
    serial_data();
    
    if(value3 == 'a'){
      
    }
  
    if(value3 == 'b'){
      
    }
    
    if(value3 == 'c'){
      
    }
    
    if(value3 == 'd'){
      
    }
  }
}
