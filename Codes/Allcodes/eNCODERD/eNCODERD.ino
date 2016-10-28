volatile int count = 0, rev = 0;

void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, foo, CHANGE);   
}

void loop()
{
  Serial.println(millis());
  Serial.println(rev);
  if( millis() > 60000 && millis() < 60020 )
  {
    Serial.print("Rebhalution = ");
    Serial.println(rev);
  } 
}
void foo()
{
  count++;
  if(count == 60)
  {
    rev++;
  }
}
