#include <Servo.h>
//Declare Global intreger
const int trigPin = 3;
const int echoPin = 2;
int cm = 0;
Servo servongho;

void setup() {
  Serial.begin(9600);
  servongho.attach(8);
}

long microsecondsToCentimeters(long microseconds)
{
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
    Serial.println("[UltraStatus] Object Detected!");
    servongho.write(12 0);
    delay(1000);
    servongho.write(0);
    delay(1000); 
  }
  else {
    Serial.println("[UltraStatus] No Object Detected.");
    servongho.write(0);
  }
  delay(1000);
}
