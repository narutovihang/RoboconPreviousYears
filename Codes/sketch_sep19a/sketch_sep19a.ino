#include<SoftwareSerial.h>

SoftwareSerial Serial1(3,2);  //rx,tx

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop()
{
  String trans;
  String rex;
  while(Serial.available()>0)
    {
      char transchar=Serial.read();
      trans +=transchar;
      delay(5);
    }
   if(trans!="")
    {
      Serial.println(trans);
      Serial1.println(trans);
      trans="";
    }
    while(Serial1.available()>0)
    {
      char rexchar=Serial1.read();
      rex+=rexchar;
      delay(5);
    }
    if(rex!="")
    {
      Serial.println(rex);
      rex="";
      //Serial.println(rex);
    }
    
    
}

