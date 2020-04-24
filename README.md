## Car Free Sun
```태양광 자율주행차 By Team Cluster```<br />
2019.12.23
***
### **I. 개요**
<img src=image/0.png width="70%" height="70%"/><br />
**Car Free Sun**은  4차 산업혁명의 핵심기술인 ```자율주행 자동차```와 신재생 에너지인 ```태양광
에너지```의 결합을 통해 <u>지속 가능성이 높고 미래 지향적인 자동차</u>를 만들어 보자는 아이디어에서 시작되었습니다.  

이 작품은 Team Cluster에 의해 제작되었고, 제10회 4차 산업혁명 SW경진대회에 출품되어 입상하였습니다.

해당 작품의 가장 큰 특징들은 다음과 같습니다.

- 태양광 패널을 부착하여 태양광 에너지를 인프라로써 활용할 수 있게 하였습니다.
- 초음파 센서를 활용하여 구현하였고, 더 나아가면 외부와도 실시간적인 통신을 할 수 있도록 하는 자율주행을 적용하였습니다.
- 4차 산업혁명의 핵심 기술과 더불어 환경도 생각하여 <u>친환경적이고 미래 지향적이며</u>, 차세대 교통 인프라에 발맞춤할 수 있습니다. 

***
### **II. 작품의 제작 목적/필요성**
<img src=image/1.png width="80%" height="80%"/><br />
태양광 에너지가 신.재생 에너지에서 차지하는 공급률은 '17 기준 약 ```9.2%```에 미치지 않아, 다른 나라들에 비해 매우 낮은 수치를 가지고 있음. 작품에서는 태양광을 에너지원으로 기용함으로써 재생 가능한 에너지를 생산할 수 있고, 이 에너지를 자동차에 효과적으로 사용할 수 있음.<br /> <br />
<img src=image/2.png width="90%" height="90%"/> <br />
구글의 자율주행 자동차 개발 프로젝트를 기점으로 자율주행 기술이 출현하고 성장하게 되었음. IHS(영국)와 Mckinsey(미국)의 전망에 의하면 ‘15~’20 간의 자율주행차 출하량은 연간 약 ```134%```의 성장률을 보일 것이며, 신차 시장 내에서 자율주행차가 차지하는 비중이 점차 늘어날 것으로 예측되었음. 또한 향후 약 15년에 자율주행차는 약 ```2100만 대``` 출하될 것으로, 자율주행 모드를 탑재한 차량이 전체 차량 중 75%를 차지할 것으로 추정되었음. 4차 산업혁명의 핵심 기술인 자율주행을 결합하여 작품을 제작함으로써 <u>차세대 자동차 산업에 기여할 수 있고, 더 나아가 무인 교통 인프라에 접목시켜 발전</u>할 수 있을 것임.

***
### **III. 모델 제작 과정**
1. 차체 밑판을 원하는 크기에 맞게 설계한 후, ```MDF```를 설계도에 따라 레이저 커터로 제단함.
2. 바퀴 모터, 브레드보드, 초음파 센서, 모터 드라이버, 아두이노 센서를 해당 위치에 고정함.
3. 각 부품을 회로에 맞게 브레드 보드와 아두이노에 연결함.
4. 바퀴를 모터에 연결하고 코드 값을 아두이노에 업로드함.
5. ```Inventor 3D```로 차체를 모델링 하여 출력한다.
6. 차체 밑판과 출력한 윗판 차체를 조립한다.
7. 태양광 패널을 아두이노와 연결하여 차체 위에 고정한다.


***
### **IV. 프로그래밍**
모델 센서 기반 자율주행 작동 코드: autodrivecar.ino
```c
//COPYRIGHT TEAM CLUSTER ALL RIGHT RESERVED.
int motorPin[4] = {2, 3, 4, 5};
int left[4] = {1, 0, 0, 1};
int front[4] = {0 , 1, 0, 1};
int right[4] = {0, 1, 1, 0};
int back[4] = {1, 0, 1, 0};
//0=left, 1=forward, 2=right
...

void setup() {
    pinMode(motor1PinA, OUTPUT);
    pinMode(motor1PinB, OUTPUT);
    pinMode(enablelPin, OUTPUT);
    analogWrite(enablelPin, 80);
    ...

}

float detection(int trig, int echo) {
    digitalWrite(trig, LOW);
    digitalWrite(echo, LOW);
    delayMicroseconds(2);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    unsigned long duration = pulseIn(echo, HIGH);
    return duration / 29 / 2;
}

void move(float L, float M, float R) {
    if (L > 15 && M > 15 && R > 15) {
        for (int i=0; i<4; i++) {
            digitalWrite(motorPin[i], front[i]);
        }
    }
    else {
        for (int i=0; i<4; i++) {
            digitalWrite(motorPin[i], back[i]);
        }
        delay(700);
        L = detection(L_trig, L_echo);
        M = detection(M_trig, M_echo);
        R = detection(R_trig, R_echo);
        if (L < R) {
            for (int i=0; i<4; i++) {
                digitalWrite(motorPin[i], right[i]);
            }
        }
        else {
            for (int i=0; i<4; i++) {
                digitalWrite(motorPin[i], left[i]);
            }
        }
        delay(100);
    }
}

void loop() {
    digitalWrite(A_1A, LOW);
    digitalWrite(A_1B, HIGH);

    float L_distance = detection(L_trig, L_echo);
    float M_distance = detection(M_trig, M_echo);
    float R_distance = detection(R_trig, R_echo);
    move(L_distance, M_distance, R_distance);
}
```


***
### **V. 우수성 및 기대 효과**
- 4차 산업혁명의 핵심 기술인만큼 높은 발전 가능성을 가지고 있으며, 탑승자의 안전과 편의성이 향상될 수 있음. 
- Inventor 3D로 모델링하여 차체를 제작하기 때문에 소비자가 <u>직접 원하는 모델과 디자인을 선택할 수 있는 높은 다양성</u>을 지님.
- 태양광으로 생산되는 신.재생 에너지를 활용하여, 기존에 휘발유, 경유나 LPG 등의 화석 연료를 사용하는 대부분의 자동차들보다 <u>환경 친화적이고 지속 가능성이 높으며</u>, 이를 개선하고 활용하는 데에 있어 무한정한 잠재력을 지니고 있음.
- 자율주행을 위해서는 외부 데이터와의 통신이 필요하며, 이 과정에서 구축되는 교통 데이터베이스는 교통산업의 안전과 안정성을 향상시킬 수 있음.
- 이러한 자율주행과 친환경 에너지의 조합으로 교통 분야의 미래 지향성이 증가할 것이며, 첨단적이고 지속 가능성이 높은 발전을 기대할 수 있음.


***
### **VI. 덧붙여서**
업로드된 파일들은 자율주행 자동차 모델 제작 및 아두이노 코딩, 프로그래밍에 사용된 파일들입니다.

본 파일들의 저작권은 ```Team Cluster```에 귀속되며 <u>어떠한 산업적 목적으로도 2차적으로 재가공/사용될 수 없음</u>을 밝힙니다.

***
Copyright 2019. <u>Team Cluster</u> All Rights Reserved.