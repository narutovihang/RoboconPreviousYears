#include <IRremote.h>
#define PIN_IR 3
#define PIN_DETECT1 4
#define PIN_DETECT2 5
#define PIN_DETECT3 6


IRsend irsend;
void setup()
{
  pinMode(PIN_DETECT1, INPUT);
  pinMode(PIN_DETECT2, INPUT);
  pinMode(PIN_DETECT3, INPUT);
  Serial.begin(9600);
  
  irsend.enableIROut(38);
  irsend.mark(0);
}
void loop()
{
  int beamStatus1 = !digitalRead(PIN_DETECT1);
  int beamStatus2 = !digitalRead(PIN_DETECT2);
  int beamStatus3 = !digitalRead(PIN_DETECT3);
  
  Serial.print("Beam1 = ");
  Serial.print(beamStatus1);
  Serial.print(" : ");
  
  Serial.print("Beam2 = ");
  Serial.print(beamStatus2);
  Serial.print(" : ");
  
  Serial.print("Beam3 = ");
  Serial.println(beamStatus3);
  if( (beamStatus1 == HIGH && beamStatus2 == LOW && beamStatus3 == LOW) || (beamStatus1 == LOW && beamStatus2 == HIGH && beamStatus3 == LOW) || (beamStatus1 == LOW && beamStatus2 == LOW && beamStatus3 == HIGH) )
  {
    analogWrite(9,0);
    analogWrite(11,0);
    delay(500);
  }
    analogWrite( 9, 100);
    analogWrite(11,0);
    delay(500);
}

