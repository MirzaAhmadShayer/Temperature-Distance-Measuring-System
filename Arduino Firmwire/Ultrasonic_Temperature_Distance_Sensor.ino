const int pingPin = 3; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 2; // Echo Pin of Ultrasonic Sensor
int val;
int tempPin = 1; //A1

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(pingPin, OUTPUT); //initialising pin 3 as output
   pinMode(echoPin, INPUT);  //initialising pin 2 as input
}

void loop() {
  delay(200);

   //Code loop for LM35
   val = analogRead(tempPin);
   float mv = (val/1024.0)*5000;
   float cel = mv/10;
   //Serial.print("Temperature = ");
   Serial.println(cel);
   //Serial.print(" *C");
   //Serial.println();
  
  //Code loop for HC-SR04
   long duration, inches, cm;
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   //inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   //Serial.print("Distance = ");
   //Serial.println();
   //Serial.print("In Inches: ");
  // Serial.print(inches);
   //Serial.print(" inches");
   //Serial.println();
   //Serial.print("In Centimeters: ");
   Serial.println(cm);
   //Serial.print(" cm");
   //Serial.println();

}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
