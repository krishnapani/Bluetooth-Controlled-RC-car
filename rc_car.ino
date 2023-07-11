#include <SoftwareSerial.h>

SoftwareSerial bluetooth(0, 1); // RX, TX pins for Bluetooth module
int in1 = 9;
int in2 = 10;
int in3 = 11;
int in4 = 12;
int enA = 5;
int enB = 6;-

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  bluetooth.begin(9600); // set Bluetooth serial communication baud rate
}

void loop() {
  if (bluetooth.available() > 0) {
    char data = bluetooth.read(); // read incoming data from Bluetooth module
    if (data == 'F') { // move forward
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enA, 255);
      analogWrite(enB, 255);
    } else if (data == 'B') { // move backward
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enA, 255);
      analogWrite(enB, 255);
    } else if (data == 'R') { // turn right
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enA, 200);
      analogWrite(enB, 150);
    } else if (data == 'L') { // turn left
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enA, 150);
      analogWrite(enB, 200);
    }else if (data == 'G') { // move forward left
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    } else if (data == 'I') { // move forward right
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    } else if (data == 'H') { // move backward left
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    } else if (data == 'J') { // move backward right
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    } else if (data == 'S') { // stop
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
  }
}