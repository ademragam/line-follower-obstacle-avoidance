// Global variables
int rightIR;      // Right IR sensor value
int leftIR;       // Left IR sensor value
int distanceUS;   // Distance from ultrasonic sensor

void setup() {

  // Start serial communication
  Serial.begin(9600);

  // Motor control pins
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  // Ultrasonic sensor pins
  pinMode(11, OUTPUT); // Trigger pin
  pinMode(12, INPUT);  // Echo pin

  // IR sensor pins
  pinMode(A0, INPUT);  // Right IR
  pinMode(A1, INPUT);  // Left IR
}

// Line follower logic
void lineFollower() {
  rightIR = analogRead(A0); // Read right IR sensor
  leftIR  = analogRead(A1); // Read left IR sensor

  Serial.println(rightIR);
  Serial.println(leftIR);

  if (rightIR < 300 && leftIR < 300) {
    moveForward(); // Both sensors on line
  } else {
    if (rightIR < 300) {
      turnLeft(); // Line on right side
    } else if (leftIR < 300) {
      turnRight(); // Line on left side
    }
  }
}

// Ultrasonic obstacle avoidance
void ultrasonicMode() {

  // Send ultrasonic pulse
  digitalWrite(11, HIGH);
  delayMicroseconds(1000);
  digitalWrite(11, LOW);

  // Receive echo
  distanceUS = pulseIn(12, HIGH);
  Serial.println(distanceUS);

  if (distanceUS < 500) {
    turnLeft(); // Obstacle very close
  } else if (distanceUS > 900) {
    turnRight(); // Obstacle far
  } else {
    moveForward(); // Safe distance
  }
}

// Move forward
void moveForward() {
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

// Turn left
void turnLeft() {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

// Turn right
void turnRight() {
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}

void loop() {

  // Measure distance
  digitalWrite(11, HIGH);
  delayMicroseconds(1000);
  digitalWrite(11, LOW);

  distanceUS = pulseIn(12, HIGH);
  Serial.println(distanceUS);

  if (distanceUS > 1500) {
    lineFollower(); // No obstacle → follow line
  } else {
    ultrasonicMode(); // Obstacle detected
  }
}
