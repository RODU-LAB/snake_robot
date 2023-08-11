#include "Snake.h"
#include "Arduino.h"


void Move::begin(){
  pwm.begin();
  pwm.setPWMFreq(60);
}



int Move::servo1(int angle){
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(0,0,pul);
} 


int Move::servo2(int angle){
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(1,0,pul);
} 


int Move::servo3(int angle){
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(2,0,pul);
} 


int Move::servo4(int angle){
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(3,0,pul);
} 


int Move::servo5(int angle){
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(12,0,pul);
} 


int Move::servo6(int angle){
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(13,0,pul);
} 


int Move::servo7(int angle){
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(14,0,pul);
} 


int Move::servo8(int angle){
  int pul = map(angle,0,180,150,600);
  pwm.setPWM(15,0,pul);
} 




void Move::Start(){   
      servo1(90+offset+amplitude*cos(3*lag));
      servo2(90+amplitude*cos(2*lag));
      servo3(90+amplitude*cos(1*lag));
      servo4(90+amplitude*cos(0*lag));
      servo5(90+amplitude*cos(-1*lag));
      servo6(90+amplitude*cos(-2*lag));
      servo7(90+amplitude*cos(-3*lag));
      servo8(90+amplitude*cos(-4*lag));
    }

void Move::Forward(int amplitude, int delaytime){
      for(counter = 0; counter < 360; counter += 1){
        delay(1);
        servo1(90+amplitude*cos(frequency*counter*3.14159/180+3*lag));
        servo2(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
        servo3(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
        servo4(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
        servo5(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));
        servo6(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
        servo7(90+amplitude*cos(frequency*counter*3.14159/180-3*lag));
        servo8(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      }
    }

void Move::Reverse(int amplitude, int delaytime){
      for(counter = 0; counter < 360; counter += 1){
        delay(1);
        servo1(90+amplitude*cos(frequency*counter*3.14159/180+3*lag));
        servo2(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
        servo3(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
        servo4(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
        servo5(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));
        servo6(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
        servo7(90+amplitude*cos(frequency*counter*3.14159/180-3*lag));
        servo8(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      }
    }

void Move::Right(int amplitude, int delaytime){
       for(counter = 0; counter < 10; counter += 1){
        delay(delayTime);
        servo1(90+offset+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
        servo2(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
        servo3(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
        servo4(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
        servo5(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
        servo6(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
        servo7(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
        servo8(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
        }
          
  // Continue right turn
      for(counter = 11; counter < 350; counter += 1){
        delay(delayTime);
        servo1(90+offset+rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
        servo2(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
        servo3(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
        servo4(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
        servo5(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
        servo6(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
        servo7(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
        servo8(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      }    
  // Ramp down turn offset
      for(counter = 350; counter < 360; counter += 1)  {
        delay(delayTime);
        servo1(90+offset+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
        servo2(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
        servo3(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
        servo4(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
        servo5(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
        servo6(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
        servo7(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
        servo8(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));     
      }
    }

void Move::Left(int amplitude, int delaytime){
       for(counter = 0; counter < 10; counter += 1){
        delay(delayTime);
        servo1(90+offset+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
        servo2(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
        servo3(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
        servo4(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
        servo5(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
        servo6(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
        servo7(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
        servo8(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      }  
  // Continue right turn
      for(counter = 11; counter < 350; counter += 1){
        delay(delayTime);
        servo1(90+offset+leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
        servo2(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
        servo3(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
        servo4(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
        servo5(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
        servo6(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
        servo7(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
        servo8(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      }    
  // Ramp down turn offset
      for(counter = 350; counter < 360; counter += 1){
        delay(delayTime);
        servo1(90+offset+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
        servo2(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
        servo3(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
        servo4(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
        servo5(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
        servo6(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
        servo7(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
        servo8(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));     
      }
    }

