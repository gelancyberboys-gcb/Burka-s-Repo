const int trigPin1 = 2; 
const int echoPin1 = 3;
const int trigPin2 = 4; 
const int echoPin2 = 5;
const int buzzerPin = 9; 

const int forwardThreshold = 70; // Adjusted for stability
const int groundThreshold = 40;  // Lowered to avoid detecting the floor itself

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Ensure buzzer starts OFF
  digitalWrite(buzzerPin, LOW);
  Serial.begin(9600);
}

void loop() {
  // Read Sensor 1
  int distForward = getDistance(trigPin1, echoPin1);
  delay(30); // CRITICAL: Wait for sound waves to die down before next sensor

  // Read Sensor 2
  int distGround = getDistance(trigPin2, echoPin2);
  delay(30);

  // LOGIC: Only trigger if distance is GREATER than 2cm (ignores errors) 
  // and LESS than threshold.
  
  if (distForward > 2 && distForward <= forwardThreshold) {
    // Forward Alert: Short sharp beeps
    digitalWrite(buzzerPin, HIGH);
    delay(70);
    digitalWrite(buzzerPin, LOW);
    delay(70);
  } 
  else if (distGround > 2 && distGround <= groundThreshold) {
    // Ground Alert: Long slow beeps
    digitalWrite(buzzerPin, HIGH);
    delay(400);
    digitalWrite(buzzerPin, LOW);
    delay(200);
  } 
  else {
    // Force the buzzer OFF if nothing is detected
    digitalWrite(buzzerPin, LOW);
  }
}

int getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Timeout set to 20ms (~3.4 meters) to keep the stick fast
  long duration = pulseIn(echo, HIGH, 20000); 
  
  if (duration == 0) return 999; // If no hit, return a huge distance
  return duration * 0.034 / 2;
}
