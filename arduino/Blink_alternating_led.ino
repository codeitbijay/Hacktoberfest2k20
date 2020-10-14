// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(12, HIGH);// turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);
  delay(1000);                       // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(13, HIGH);
  delay(1000);                       // wait for a second
}
