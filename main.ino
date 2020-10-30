#include <Servo.h>
//Declare Global intreger
const int trigPin = 3;
const int echoPin = 2;
int cm = 100;
Servo servongho;

void setup() {
  Serial.begin(9600);
  servongho.attach(7);
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}


void loop() {
  long duration, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  if (cm <= 10) {
    Serial.print("[UltraStatus] Object Detected!");
    Serial.println();
    servongho.write(90);
    delay(50);
    servongho.write(-90);
  }
  else {
    Serial.print("[UltraStatus] No Object Detected.");
    Serial.println();
  }
  delay(1000);
}
