// defines pins numbers
const int trigPin = 9;
const int echoPin = 6;
const int buzzer = 11;
const int ledPin = 13;

// defines variables
long duration;
int distance;
const int targetDistance = 100; // Target distance in cm

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication

  // Beep twice at startup
  tone(buzzer, 1000); // Set the buzzer to 1000Hz (1kHz)
  delay(100); // Beep duration
  noTone(buzzer); // Turn off the buzzer
  delay(100); // Pause between beeps
  tone(buzzer, 1000); // Set the buzzer to 1000Hz (1kHz) again
  delay(100); // Beep duration
  noTone(buzzer); // Turn off the buzzer
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  if (distance == targetDistance) {
    tone(buzzer, 1000); // Set the buzzer to 1000Hz (1kHz)
    digitalWrite(ledPin, HIGH);
  } else {
    noTone(buzzer); // Turn off the buzzer
    digitalWrite(ledPin, LOW);
  }

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(100); // Slight delay to reduce serial monitor spam
}
