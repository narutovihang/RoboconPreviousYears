#include <IRremote.h>
#define PIN_IR 3
#define PIN_DETECT 2
#define LED 13
#define switch1 8
#define switch2 9

IRsend irsend;
void setup()
{
  pinMode(PIN_DETECT, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(switch1, OUTPUT);
  pinMode(switch2, OUTPUT);
  
  irsend.enableIROut(38);
  irsend.mark(0);
}
void loop()
{
  int beamStatus = digitalRead(PIN_DETECT);
  if(beamStatus == 1)
  {
    digitalWrite(LED, LOW);
	
    digitalWrite(switch1, HIGH);
    digitalWrite(switch2, LOW);
    delay(3000);
    digitalWrite(switch1, LOW);
    digitalWrite(switch2, HIGH);
  }
  else
  {
    digitalWrite(LED, HIGH);
  }
}