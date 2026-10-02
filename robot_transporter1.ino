#include <Servo.h>

#define D1_PWM 6
#define D1_IN1 A0
#define D1_IN2 A1

#define D2_PWM 9
#define D2_IN1 A2
#define D2_IN2 A3

#define D3_PWM 3
#define D3_IN1 2
#define D3_IN2 4

#define D4_PWM 5
#define D4_IN1 7
#define D4_IN2 8

#define PIN_LIFT 10
#define PIN_CAPIT 11

Servo servoLift;
Servo servoCapit;

void setup() {
  Serial.begin(9600);
  
  pinMode(D1_IN1, OUTPUT); pinMode(D1_IN2, OUTPUT);
  pinMode(D2_IN1, OUTPUT); pinMode(D2_IN2, OUTPUT);
  pinMode(D3_IN1, OUTPUT); pinMode(D3_IN2, OUTPUT);
  pinMode(D4_IN1, OUTPUT); pinMode(D4_IN2, OUTPUT);

  servoLift.attach(PIN_LIFT);
  servoCapit.attach(PIN_CAPIT);

  remTotal();
  servoLift.write(90); 
  servoCapit.write(60);
}

void loop() {
  if (Serial.available() > 0) {
    char tombol = Serial.read();
    
    switch (tombol) {
      case 'w':
        jalanMotor(D1_PWM, D1_IN1, D1_IN2, 1);
        jalanMotor(D2_PWM, D2_IN1, D2_IN2, 1);
        jalanMotor(D3_PWM, D3_IN1, D3_IN2, 1);
        jalanMotor(D4_PWM, D4_IN1, D4_IN2, 1);
        Serial.println("Maju");
        break;

      case 's':
        jalanMotor(D1_PWM, D1_IN1, D1_IN2, -1);
        jalanMotor(D2_PWM, D2_IN1, D2_IN2, -1);
        jalanMotor(D3_PWM, D3_IN1, D3_IN2, -1);
        jalanMotor(D4_PWM, D4_IN1, D4_IN2, -1);
        Serial.println("Mundur");
        break;

      case 'd':
        jalanMotor(D1_PWM, D1_IN1, D1_IN2, 1);
        jalanMotor(D2_PWM, D2_IN1, D2_IN2, -1);
        jalanMotor(D3_PWM, D3_IN1, D3_IN2, -1);
        jalanMotor(D4_PWM, D4_IN1, D4_IN2, 1);
        Serial.println("Geser Kanan");
        break;

      case 'a':
        jalanMotor(D1_PWM, D1_IN1, D1_IN2, -1);
        jalanMotor(D2_PWM, D2_IN1, D2_IN2, 1);
        jalanMotor(D3_PWM, D3_IN1, D3_IN2, 1);
        jalanMotor(D4_PWM, D4_IN1, D4_IN2, -1);
        Serial.println("Geser Kiri");
        break;

      case 'x':
        remTotal();
        Serial.println("STOP");
        break;

      case 'u':
        servoLift.write(180);
        Serial.println("Lift Naik");
        break;
        
      case 'j':
        servoLift.write(0);
        Serial.println("Lift Turun");
        break;
        
      case 'k':
        servoLift.write(90);
        Serial.println("Lift Diam");
        break;
        
      case 'o':
        servoCapit.write(60);
        Serial.println("Capit Buka");
        break;
        
      case 'c':
        servoCapit.write(150);
        Serial.println("Capit Tutup");
        break;

      default:
        break;
    }
  }
}

void jalanMotor(int pwm, int in1, int in2, int arah) {
  analogWrite(pwm, 150);
  
  if (arah == 1) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (arah == -1) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(pwm, 0);
  }
}

void remTotal() {
  jalanMotor(D1_PWM, D1_IN1, D1_IN2, 0);
  jalanMotor(D2_PWM, D2_IN1, D2_IN2, 0);
  jalanMotor(D3_PWM, D3_IN1, D3_IN2, 0);
  jalanMotor(D4_PWM, D4_IN1, D4_IN2, 0);
}