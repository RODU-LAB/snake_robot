#ifndef _Snake_h
#define _Snake_h

#include <Adafruit_PWMServoDriver.h>

class Move{

  public:

    void begin();
 

    //모터 설정
    int servo1(int angle);
    int servo2(int angle);
    int servo3(int angle);
    int servo4(int angle);
    int servo5(int angle);
    int servo6(int angle);
    int servo7(int angle);
    int servo8(int angle);


    //뱀 움직임
    void Start();  //시작
    void Forward(int amplitude, int delaytime);  //전진
    void Reverse(int amplitude, int delaytime);  //후진
    void Right(int amplitude, int delaytime);  //오른쪽
    void Left(int amplitude, int delaytime);  //왼쪽
  

  private:
  
    int counter = 0; // Loop counter variable
    float lag = .8975; // Phase lag between segments
    int frequency = 1; // Oscillation frequency of segments.
    int amplitude = 40; // Amplitude of the serpentine motion of the snake
    int rightOffset = 5; // Right turn offset
    int leftOffset = -5; // Left turn offset
    int offset = 6; // Variable to correct servos that are not exactly centered
    int delayTime = 7; // Delay between limb movements
    int startPause = 5000;  // Delay time to position robot
    int test = -3; // Test varialble takes values from -6 to +5

    Adafruit_PWMServoDriver pwm;
  
  };
  
#endif