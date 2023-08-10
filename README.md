# Snake Robot: 

![image](https://github.com/RODU-LAB/snake_robot/assets/121866753/66ca2901-a544-41e3-bba8-5bb2475cccfb)


snake 로봇은 Rodu에서 개발한 교육용 로봇이다. 실제 뱀의 움직임을 모방하여 움직이고 gui를 통해 조작 및 기능 설정들이 가능하다.

### **사용물품**

---

- Arduino Nano 1개
- sg90 모터 8개
- 바퀴 12쌍
- pca9685 board 1개
- 
### **GUI(어플리케이션)**

---

![image](https://github.com/RODU-LAB/snake_robot/assets/121866753/8374fda8-f11d-433f-a237-cf71175e677e)

![image](https://github.com/RODU-LAB/snake_robot/assets/121866753/6aa0f1b3-091d-4da4-8f4a-55ead13bd129)



### ****Hardware Architecture****

---

![emoti2](https://user-images.githubusercontent.com/71277820/229018453-7f779820-db51-48f2-86ec-d5417581d183.jpeg)

### ****Software Architecture**** & Workflow

---

![EMOTI_graph](https://user-images.githubusercontent.com/71277820/229018476-8cc22a08-1a2a-4687-bc25-529a08dde858.png)

### install

---

```bash

cd ~/catkin_ws/src
git clone https://github.com/ggh-png/EMOTIROBOT.git
git clone https://github.com/ROBOTIS-GIT/DynamixelSDK.git
cd ~/catkin_ws && catkin_make
```

```bash
pip install pyaudio
pip install google-cloud-speech
pip install google-cloud-texttospeech
pip install playsound
pip install six
pip install openai
```

### launch

---

```bash
roslaunch EMOTI_core EMOTI_core.launch
```
