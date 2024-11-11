void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  delay(5000); // Wait for 5 seconds 
  digitalWrite(13, LOW);
  delay(5000); // Wait for 5 seconds 

}