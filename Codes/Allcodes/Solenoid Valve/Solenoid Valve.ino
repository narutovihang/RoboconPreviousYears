/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 22;
int led1 = 30;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led,HIGH);
  digitalWrite(led1,LOW);
  delay(500);
  digitalWrite(led,LOW);
  digitalWrite(led1,HIGH);
  delay(500);
  
}
