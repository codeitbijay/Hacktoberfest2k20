int input;
void setup() {
Serial.begin(9600);
pinMode(7,OUTPUT);
pinMode(A1,INPUT);
}

void loop() {
  input = analogRead(A1);
  Serial.println(input);
  //delay(1000);
  if(input>512)
  {
    digitalWrite(7,LOW);
  }
  else
  {
    digitalWrite(7,HIGH);
  }
  delay(1000);

}
