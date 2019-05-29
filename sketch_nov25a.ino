
// defining pin numbers
const int trigPin = 9;
const int echo1 = 10;
const int echo2 = 11;
const int echo3 = 6;
int led1=12;
int led2=8;
int led3=7;



// defining variables
long duration1;
int distance1;
int safetyDistance1;
long duration2;
int distance2;
int safetyDistance2;
long duration3;
int distance3;
int safetyDistance3;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echo1, INPUT); // Sets the echoPin as an Input
pinMode(led1,OUTPUT);
pinMode(echo2, INPUT); // Sets the echoPin as an Input
pinMode(led2,OUTPUT);
pinMode(echo3, INPUT); // Sets the echoPin as an Input
pinMode(led3,OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration1 = pulseIn(echo1, HIGH);
distance1= microsecondsToCentimeters(duration1);

safetyDistance1 = distance1;
if (safetyDistance1 <= 5){
  digitalWrite(led1, LOW);
}
else{
  digitalWrite(led1, HIGH);
}

//////////////////////
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration2 = pulseIn(echo2, HIGH);
distance2= microsecondsToCentimeters(duration2);

safetyDistance2 = distance2;
if (safetyDistance2 <= 5){
  digitalWrite(led2, LOW);
}
else{
  digitalWrite(led2, HIGH);
}


///////////////////////////////////

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration3= pulseIn(echo3, HIGH);
distance3= microsecondsToCentimeters(duration3);

safetyDistance3 = distance3;
if (safetyDistance3<= 5){
  digitalWrite(led3, LOW);
}
else{
  digitalWrite(led3, HIGH);
}


}
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
