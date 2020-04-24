int A_1A = 0;
int A_1B = 1;
int M_trig = 7;
int M_echo = 6;
int R_trig = 9;
int R_echo = 8;
int L_trig = A5;
int L_echo = A4;
int motor1PinA = 2;
int motor1PinB = 3;
int motor2PinA = 4;
int motor2PinB = 5;
int enablerPin = 10;
int enablelPin = 11;
int motorPin[4] = {2, 3, 4, 5};
int left[4] = {1, 0, 0, 1};
int front[4] = {0 , 1, 0, 1};
int right[4] = {0, 1, 1, 0};
int back[4] = {1, 0, 1, 0};
//0=left, 1=forward, 2=right

void setup() {
    pinMode(A_1A, OUTPUT);
    pinMode(A_1B, OUTPUT);
    pinMode(M_trig, OUTPUT);
    pinMode(M_echo, INPUT);
    pinMode(R_trig, OUTPUT);
    pinMode(R_echo, INPUT);
    pinMode(L_trig, OUTPUT);
    pinMode(L_echo, INPUT);

    pinMode(motor1PinA, OUTPUT);
    pinMode(motor1PinB, OUTPUT);
    pinMode(enablelPin, OUTPUT);
    analogWrite(enablelPin, 80);

    pinMode(motor2PinA, OUTPUT);
    pinMode(motor2PinB, OUTPUT);
    pinMode(enablerPin, OUTPUT);
    analogWrite(enablerPin, 80);
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
