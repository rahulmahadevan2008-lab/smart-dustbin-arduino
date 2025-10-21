#smart_dustbin.ino
#include <Servo.h> // Include the Servo library to control the lid motor

// Define pin connections
const int trigPin = 9;     // Trigger pin of ultrasonic sensor
const int echoPin = 10;    // Echo pin of ultrasonic sensor
const int servoPin = 6;    // Signal pin for servo motor

Servo lidServo; // Create a servo object to control the lid

void setup() {
  pinMode(trigPin, OUTPUT);  // Set trigger pin as output
  pinMode(echoPin, INPUT);   // Set echo pin as input
  lidServo.attach(servoPin); // Attach servo to its pin
  lidServo.write(0);         // Start with lid closed (0 degrees)
  Serial.begin(9600);        // Start serial monitor for debugging
}

void loop() {
  long duration;
  int distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure time taken for echo to return
  duration = pulseIn(echoPin, HIGH, 30000);  //30ms timeout

  // Convert time to distance in centimeters
  distance = duration * 0.034 / 2;

  // Print distance to serial monitor (for testing)
  Serial.print("Distance: ");
  Serial.println(distance);

  // If object is detected within 20 cm, open the lid
  if (distance > 5 && distance < 20) {
    lidServo.write(90);       // Rotate servo to open lid
    delay(3000);              // Wait 3 seconds
    lidServo.write(0);        // Rotate servo back to close lid
  }

  delay(500);                 // Wait before next detection cycle
}
