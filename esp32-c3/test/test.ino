void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  static bool police = false;
  
  if (!digitalRead(2)) {
    Serial.println("Button pressed");
    police = !police;
    delay(500);
    digitalWrite(5, HIGH);
  }

  if (police) {
    digitalWrite(5, !digitalRead(5));
    digitalWrite(1, !digitalRead(1));
    delay(100);
  }
  else {
    digitalWrite(5, LOW);
    digitalWrite(1, LOW);
  }
}
