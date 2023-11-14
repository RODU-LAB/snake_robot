#include <ESP32Servo.h>                                // Servo 라이브러리 헥사 선언
#include "BluetoothSerial.h"

//#define USE_PIN // Uncomment this to use PIN during pairing. The pin is specified on the line below
const char *pin = "1234"; // Change this to more secure PIN.
String device_name = "Snake_robot20";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

// 모터 핀 선언(총 10개 사용)
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;
Servo myservo8;
Servo myservo9;
Servo myservo10;


int counter = 0; // Loop counter variable
float lag = .6981 ; // Phase lag between segments
int frequency = 1; // Oscillation frequency of segments.
int amplitude = 40; // Amplitude of the serpentine motion of the snake
int rightOffset = 10; // Right turn offset
int leftOffset = -10; // Left turn offset
int offset = 6; // Variable to correct servos that are not exactly centered
int delayTime = 7; // Delay between limb movements
int startPause = 5000;  // Delay time to position robot
int test = -3; // Test varialble takes values from -6 to +


//위치 설정
int pos = 0;


// 모터 핀 선언(총 10개 사용)
int servoPin1 = 2;
int servoPin2 = 4; 
int servoPin3 = 16;
int servoPin4 = 17;
int servoPin5 = 5;
int servoPin6 = 12;
int servoPin7 = 14;
int servoPin8 = 27;
int servoPin9 = 26;
int servoPin10 = 25;

int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;
int value5 = 0;
int value6 = 0;
int value7 = 0;
int value8 = 0;
int value9 = 0;
int value10 = 0;
int amp = 0;
int fre = 0;


String ft;

void setup() {
  
     // 시리얼 선언
     Serial.begin(9600);

     // 블루투스 시리얼 선언
     SerialBT.begin(device_name);

     // 핀 모드 선언
     pinMode (servoPin1, OUTPUT);
     pinMode (servoPin2, OUTPUT);
     pinMode (servoPin3, OUTPUT);
     pinMode (servoPin4, OUTPUT);
     pinMode (servoPin5, OUTPUT);
     pinMode (servoPin6, OUTPUT);
     pinMode (servoPin7, OUTPUT);
     pinMode (servoPin8, OUTPUT);
     pinMode (servoPin9, OUTPUT);
     pinMode (servoPin10, OUTPUT);


     // 서보 모터 선언
     myservo1.attach(servoPin1);
     myservo2.attach(servoPin2);
     myservo3.attach(servoPin3);
     myservo4.attach(servoPin4);
     myservo5.attach(servoPin5);
     myservo6.attach(servoPin6);
     myservo7.attach(servoPin7);
     myservo8.attach(servoPin8);
     myservo9.attach(servoPin9);
     myservo10.attach(servoPin10);


     // 홈 위치 선언
//     myservo1.write(90); 
//     myservo2.write(90);
//     myservo3.write(90);
//     myservo4.write(90);
//     myservo5.write(90);
//     myservo6.write(90);
//     myservo7.write(90);
//     myservo8.write(90);
//     myservo9.write(90);
//     myservo10.write(90);

     // 초기 딜레이 시간
     delay(startPause);
     
//     // 홈 위치 선언
     myservo1.write(90+amplitude*cos(4*lag)); 
     myservo2.write(90+amplitude*cos(3*lag));
     myservo3.write(90+amplitude*cos(2*lag));
     myservo4.write(90+amplitude*cos(1*lag));
     myservo5.write(90+amplitude*cos(0*lag));
     myservo6.write(90+amplitude*cos(-1*lag));
     myservo7.write(90+amplitude*cos(-2*lag));
     myservo8.write(90+amplitude*cos(-3*lag));
     myservo9.write(90+amplitude*cos(-4*lag));
     myservo10.write(90+amplitude*cos(-5*lag));

     // 초기 딜레이 시간
     delay(startPause);
}



void forward(int amp, int freq){
  amplitude = amp;
  frequency = freq;  
  
  for(counter = 0; counter < 360; counter += 1){
    delay(delayTime);
    myservo1.write(90+amplitude*cos(frequency*counter*3.14159/180+4*lag));
    myservo2.write(90+amplitude*cos(frequency*counter*3.14159/180+3*lag));
    myservo3.write(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
    myservo4.write(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
    myservo5.write(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
    myservo6.write(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    myservo7.write(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
    myservo8.write(90+amplitude*cos(frequency*counter*3.14159/180-3*lag));
    myservo9.write(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
    myservo10.write(90+amplitude*cos(frequency*counter*3.14159/180-5*lag));
  }
}


void backward(int amp, int freq){
  amplitude = amp;
  frequency = freq;
  
  for(counter = 360; counter > 0; counter -= 1)  {
    delay(delayTime);
    myservo1.write(90+amplitude*cos(frequency*counter*3.14159/180+4*lag));
    myservo2.write(90+amplitude*cos(frequency*counter*3.14159/180+3*lag));
    myservo3.write(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
    myservo4.write(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
    myservo5.write(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
    myservo6.write(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    myservo7.write(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
    myservo8.write(90+amplitude*cos(frequency*counter*3.14159/180-3*lag));
    myservo9.write(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
    myservo10.write(90+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
  }
}

void left(int amp, int freq){
  amplitude = amp;
  frequency = freq;
  
  for(counter = 0; counter < 10; counter += 1)  {
    delay(delayTime);
    myservo1.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
    myservo2.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
    myservo3.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
    myservo4.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
    myservo5.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
    myservo6.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    myservo7.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
    myservo8.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
    myservo9.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
    myservo10.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
  }  
  
  
  for(counter = 11; counter < 350; counter += 1)  {
    delay(delayTime);
    myservo1.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
    myservo2.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
    myservo3.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
    myservo4.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
    myservo5.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
    myservo6.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    myservo7.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
    myservo8.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
    myservo9.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
    myservo10.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
  }    
  
  for(counter = 350; counter < 360; counter += 1)  {
    delay(delayTime);
    myservo1.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
    myservo2.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
    myservo3.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
    myservo4.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
    myservo5.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
    myservo6.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    myservo7.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
    myservo8.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
    myservo9.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
    myservo10.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
  }  
}

void right(int amp, int freq){
  amplitude = amp;
  frequency = freq;
  
  for(counter = 0; counter < 10; counter += 1)  {
    delay(delayTime);
    myservo1.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
    myservo2.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
    myservo3.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
    myservo4.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
    myservo5.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
    myservo6.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    myservo7.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
    myservo8.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
    myservo9.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
    myservo10.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
  }  

  for(counter = 11; counter < 350; counter += 1)  {
    delay(delayTime);
    myservo1.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
    myservo2.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
    myservo3.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
    myservo4.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
    myservo5.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
    myservo6.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    myservo7.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
    myservo8.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
    myservo9.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
    myservo10.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
  }    

  for(counter = 350; counter < 360; counter += 1)  {
    delay(delayTime);
    myservo1.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
    myservo2.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
    myservo3.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
    myservo4.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
    myservo5.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
    myservo6.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    myservo7.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
    myservo8.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
    myservo9.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
    myservo10.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
  }  
}

void home_position(int amp){
  amplitude = amp;
   
  myservo1.write(90+amplitude*cos(4*lag)); 
  myservo2.write(90+amplitude*cos(3*lag));
  myservo3.write(90+amplitude*cos(2*lag));
  myservo4.write(90+amplitude*cos(1*lag));
  myservo5.write(90+amplitude*cos(0*lag));
  myservo6.write(90+amplitude*cos(-1*lag));
  myservo7.write(90+amplitude*cos(-2*lag));
  myservo8.write(90+amplitude*cos(-3*lag));
  myservo9.write(90+amplitude*cos(-4*lag));
  myservo10.write(90+amplitude*cos(-5*lag));
}


void speecial_1(){
  myservo1.write(90);
  delay(10);
  myservo2.write(90);
  delay(10);
  myservo3.write(90);
  delay(10);
  myservo4.write(90);
  delay(10);
  myservo5.write(90);
  delay(10);
  myservo6.write(90);
  delay(10);
  myservo7.write(90);
  delay(10);
  myservo8.write(90);
  delay(10);
  myservo9.write(90);
  delay(10);
  myservo10.write(90);
  delay(10);
}

void speecial_2(){
  myservo1.write(90);
  myservo2.write(90); 
  myservo3.write(180);
  myservo4.write(90);
  myservo5.write(90);
  myservo6.write(180);
  myservo7.write(90);
  myservo8.write(90);
  myservo9.write(180);
  myservo10.write(90);  
}


void go(int value1,int value2,int value3,int value4,int value5,int value6,int value7,int value8,int value9,int value10){
  myservo1.write(value1);
  myservo2.write(value2);
  myservo3.write(value3);
  myservo4.write(value4);
  myservo5.write(value5);
  myservo6.write(value6);
  myservo7.write(value7);
  myservo8.write(value8);
  myservo9.write(value9);
  myservo10.write(value10);
}

void loop(){
  
  if (SerialBT.available()) {
      
    String data = SerialBT.readStringUntil('\n'); // 개행 문자까지 읽음

    int amp = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // amp 값을 잘랐으므로 나머지 문자열로 업데이트
  
    int freq = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // 속도 값을 잘랐으므로 나머지 문자열로 업데이트
      
    int value1 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // 모터1 값을 잘랐으므로 나머지 문자열로 업데이트
      
    int value2 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // 모터2 값을 잘랐으므로 나머지 문자열로 업데이트
  
    int value3 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // 모터3 값을 잘랐으므로 나머지 문자열로 업데이트
  
    int value4 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // 모터4 값을 잘랐으므로 나머지 문자열로 업데이트
  
    int value5 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // 모터5 값을 잘랐으므로 나머지 문자열로 업데이트
  
    int value6 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // 모터6 값을 잘랐으므로 나머지 문자열로 업데이트
  
    int value7 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // 모터7 값을 잘랐으므로 나머지 문자열로 업데이트
  
    int value8 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // 모터8 값을 잘랐으므로 나머지 문자열로 업데이트
      
    int value9 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // 모터9 값을 잘랐으므로 나머지 문자열로 업데이트
  
    int value10 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1); // 모터10 값을 잘랐으므로 나머지 문자열로 업데이트
  
    String ft = data;

    Serial.print(amp);
    Serial.print(freq);
    Serial.print(value1);
    Serial.print(value2);
    Serial.print(value3);
    Serial.print(value4);
    Serial.print(value5);
    Serial.print(value6);
    Serial.print(value7);
    Serial.print(value8);
    Serial.print(value9);
    Serial.print(value10);
    Serial.println(ft);
    
      
    if(ft == "w"){
      forward(amp,freq);
    }
      
    if (ft == "s"){
      backward(amp,freq);    
    }
      
    if (ft == "d"){
      left(amp,freq);
    }       
    
    if (ft == "a"){
      right(amp,freq);  
    }
  
    if(ft=="h"){
      home_position(amp);
    }
  
    if(ft=="l"){
      speecial_1();
    }
  
    if(ft=="r"){
      speecial_2();
    }

    if(ft=="g"){
      go(value1, value2, value3, value4, value5, value6, value7, value8, value9, value10);
    }
  }
}
