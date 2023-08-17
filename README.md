# Snake Robot

![image](https://github.com/RODU-LAB/snake_robot/assets/121866753/66ca2901-a544-41e3-bba8-5bb2475cccfb)


snake 로봇은 Rodu에서 개발한 교육용 로봇이다.  
실제 뱀의 움직임을 모방하여 움직이고 gui를 통해 조작 및 기능 설정들이 가능하다.

---
## ****Hardware****


### **사용물품**

- Arduino Nano 1개
- pca9685 board 1개
- sg90 모터 8개
- 바퀴 12쌍
- 각종 점퍼선
- 배터리


### ****회로도****
![image](https://github.com/RODU-LAB/snake_robot/assets/121866753/50f6ba2f-8a35-4a5b-a5a5-d27f5a3a5541)


### ****부품 및 설계 STL****

![image](https://github.com/RODU-LAB/snake_robot/assets/121866753/fbd81cc1-ccb8-4cbd-9747-11e51d6585d7)


## ****Software****


### ****아두이노 및 아두이노 라이브러리****
- **Snake.h**  
  - Move snake; => Move 뒤에 자신이 사용하고자 하는 변수명으로 설정(여기는 snake로 설정)
      
  - snake.begin(); ⇒ 모터 기본설정 코드
  - snake.Start(); ⇒ 뱀 초기 모션 설정
  - snake.Forward(); ⇒ 전진 코드  
  - snake.Reverse(); ⇒ 후진 코드  
  - snake.Right(); ⇒ 오른쪽 코드  
  - snake.Left(); ⇒ 왼쪽 코드  

- example
  ```c++
  #include <Snake.h> // Snake.h 라이브러리 추가
  #include <Wire.h> // i2c통신 라이브러리 추가

  Move snake; // class함수 Move를 snake로 호출

  void setup() 
  { 
    snake.begin(); // 모터 설정
    snake.Start(); // 뱀 초기 위치 설정
    delay(5000); // 5초 대기


  } 
  
  
  void loop(){
    snake.Forward(); // 뱀 전진 코드 실행
  }
  ```
### ****QT GUI****
- **⚙️ 개발 환경**
  - PYQT5
  - QT designer

- ****💻 디자인****
  
  ![image](https://github.com/RODU-LAB/snake_robot/assets/121866753/eb2361f9-4594-4987-881d-6aeaa9117a60)
  ![image](https://github.com/RODU-LAB/snake_robot/assets/121866753/428d2aee-657b-46d4-bb3c-d83c75f14fe4)

- ****🎮 기능****    
  - 조이스틱을 통해 로봇을 제어할 수 있음
  - 조이스틱 하단의 버튼을 통해 회전이 가능함
  - 총 4개의 설정 상태를 저장할 수 있음(반지름, 속도)
  - 본인이 원하는 값을 입력하고 변경을 누르면 변경 상태가 저장되고 이를 누르면 해당 설정값으로 뱀이 움직임


### ****문제점****

1. 통신과 gui를 연결하는 과정에서 통신에 의한 딜레이 떄문에 gui 업데이트의 오류가 있음
2. 통신관련 부분을 스레드로 작성하여 해결하고자 함

