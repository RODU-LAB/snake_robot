#include <Wire.h> //i2c통신 라이브러리
#include <Adafruit_PWMServoDriver.h> //서보 드라이버 라이브러리

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// Define servo objects for the snake segments

int servo1(int angle){ 
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(0,0,pul);
}


// hello world 

int servo2(int angle){ 
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(1,0,pul);
}

int servo3(int angle){ 
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(2,0,pul);
}

int servo4(int angle){ 
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(3,0,pul);
}

int servo5(int angle){ 
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(12,0,pul);
}

int servo6(int angle){ 
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(13,0,pul);
}

int servo7(int angle){ 
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(14,0,pul);
}

int servo8(int angle){ 
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(15,0,pul);
}
 
// Define variables
int forwardPin = 14;  // Remote control movement pins
int reversePin = 15;
int rightPin = 16;
int leftPin = 17;

int forwardVal = 0;  // Remote control variables
int reverseVal = 0;
int rightVal = 0;
int leftVal = 0;

int counter = 0; // Loop counter variable
float lag = .5712; // Phase lag between segments
int frequency = 1; // Oscillation frequency of segments.
int amplitude = 40; // Amplitude of the serpentine motion of the snake
int rightOffset = 5; // Right turn offset
int leftOffset = -5; // Left turn offset
int offset = 6; // Variable to correct servos that are not exactly centered
int delayTime = 7; // Delay between limb movements
int startPause = 5000;  // Delay time to position robot
int test = -3; // Test varialble takes values from -6 to +5
  
void setup() 
{ 

  pwm.begin();
  pwm.setOscillatorFrequency(27000000); //이건 녹칸다도 잘 모르겠음!
  pwm.setPWMFreq(60);


 
// Put snake in starting position 
//   servo1(90+offset+amplitude*cos(3*lag));
//   servo2(90+amplitude*cos(2*lag));
//   servo3(90+amplitude*cos(1*lag));
//   servo4(90+amplitude*cos(0*lag));
//   servo5(90+amplitude*cos(-1*lag));
//   servo6(90+amplitude*cos(-2*lag));
//   servo7(90+amplitude*cos(-3*lag));
//   servo8(90+amplitude*cos(-4*lag));
    // Pause to position robot
} 
  
  
void loop() 
{


  for(counter = 0; counter < 360; counter += 1)  {
    delay(1);
    servo1(90+offset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
    servo2(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
    servo3(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
    servo4(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
    servo5(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    servo6(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
    servo7(90+amplitude*cos(frequency*counter*3.14159/180-3*lag));
    servo8(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
  
  }

////  Read movement pins
//  forwardVal = digitalRead(forwardPin);
//  reverseVal = digitalRead(reversePin);
//  rightVal = digitalRead(rightPin);
//  leftVal = digitalRead(leftPin);
//  
//// Forward motion
//  if (forwardVal == HIGH){
//    for(counter = 0; counter < 360; counter += 1)  {
//      delay(delayTime);
//      s1.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
//      s2.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
//      s3.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
//      s4.write(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
//      s5.write(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
//      s6.write(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
//      s7.write(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));
//      s8.write(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
//      s9.write(90+amplitude*cos(frequency*counter*3.14159/180-3*lag));
//      s10.write(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
//      s11.write(90+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
//      s12.write(90+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
//    }
//  }
//
//// Reverse motion
//  if (reverseVal == HIGH){
//    for(counter = 360; counter > 0; counter -= 1)  {
//      delay(delayTime);
//      s1.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
//      s2.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
//      s3.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
//      s4.write(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
//      s5.write(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
//      s6.write(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
//      s7.write(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));
//      s8.write(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
//      s9.write(90+amplitude*cos(frequency*counter*3.14159/180-3*lag));
//      s10.write(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
//      s11.write(90+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
//      s12.write(90+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
//    }    
//  }
//  
//// Right turn
//  if (rightVal == HIGH){
//// Ramp up turn offset
//    for(counter = 0; counter < 10; counter += 1)  {
//      delay(delayTime);
//      s1.write(90+offset+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
//      s2.write(90+offset+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
//      s3.write(90+offset+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
//      s4.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
//      s5.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
//      s6.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
//      s7.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
//      s8.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
//      s9.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
//      s10.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
//      s11.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
//      s12.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
//    }  
//// Continue right turn
//    for(counter = 11; counter < 350; counter += 1)  {
//      delay(delayTime);
//      s1.write(90+offset+rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
//      s2.write(90+offset+rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
//      s3.write(90+offset+rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
//      s4.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
//      s5.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
//      s6.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
//      s7.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
//      s8.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
//      s9.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
//      s10.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
//      s11.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
//      s12.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
//    }    
//// Ramp down turn offset
//    for(counter = 350; counter < 360; counter += 1)  {
//      delay(delayTime);
//      s1.write(90+offset+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
//      s2.write(90+offset+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
//      s3.write(90+offset+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
//      s4.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
//      s5.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
//      s6.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
//      s7.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
//      s8.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
//      s9.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
//      s10.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
//      s11.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
//      s12.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
//    } 
//  } 
//  
//// Left turn
//  if (leftVal == HIGH){
//// Ramp up turn offset
//    for(counter = 0; counter < 10; counter += 1)  {
//      delay(delayTime);
//      s1.write(90+offset+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
//      s2.write(90+offset+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
//      s3.write(90+offset+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
//      s4.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
//      s5.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
//      s6.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
//      s7.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
//      s8.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
//      s9.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
//      s10.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
//      s11.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
//      s12.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
//    }  
//// Continue left turn
//    for(counter = 11; counter < 350; counter += 1)  {
//      delay(delayTime);
//      s1.write(90+offset+leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
//      s2.write(90+offset+leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
//      s3.write(90+offset+leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
//      s4.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
//      s5.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
//      s6.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
//      s7.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
//      s8.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
//      s9.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
//      s10.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
//      s11.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
//      s12.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
//    }    
//// Ramp down turn offset
//    for(counter = 350; counter < 360; counter += 1)  {
//      delay(delayTime);
//      s1.write(90+offset+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
//      s2.write(90+offset+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
//      s3.write(90+offset+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
//      s4.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
//      s5.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
//      s6.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
//      s7.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
//      s8.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
//      s9.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
//      s10.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
//      s11.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
//      s12.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
//    } 
//  } 
}
