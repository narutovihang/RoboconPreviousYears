#define detect1 7
#define detect2 6
#define output 13
void setup()
{
  pinMode(detect1, INPUT);
  pinMode(detect2, INPUT);
  pinMode(output, OUTPUT);
}
void loop()
{
  int beamStatus1=digitalRead (detect1);
  int beamStatus2=digitalRead (detect2);
  if (beamStatus1 ==1 || beamStatus2==1)
   digitalWrite(output, LOW);
  else
    digitalWrite(output,HIGH);
}
