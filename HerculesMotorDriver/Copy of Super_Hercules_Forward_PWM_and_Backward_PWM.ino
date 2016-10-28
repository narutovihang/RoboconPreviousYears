int i = 0, 
IN1 = 26,
IN2 = 28,
P = 7;

void setup()
{
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
}

void loop()
{
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW); 
 for(i = 0; i<=255; i++) // go to full speed from 0 to 255 
 {
   analogWrite(P,i);
   delay(50);
 }
 i=0; //stop
 delay(500);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH); 
 for(i = 0; i<=255; i++)
 { analogWrite(P,i); // go to full speed from 0 to 255
   delay(50);
 }
 i=0; // stop
 delay(500);
}
