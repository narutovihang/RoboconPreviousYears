#include <PS2X_lib.h>

PS2X ps2x;

//PINS---------------------------------------------------------------------
int 
error =  0, 
lefty =  0,
leftx =  0,
rightx=  0,
clk   = 13,
data  = 12,
cmd   = 11,
att   = 10, 
up    =  2, 
un    =  A3, 
dp    =  1,
dn    =  A2,
lp    =  A1,
ln    =  A4,
rp    =  4,
rn    =  A5,
pwm1  =  3,  
pwm2 =   5,
pwm3 =   6,
pwm4 =   9
;

// SETUP --------------------------------------------------------------------
void setup()
{
  
  error=ps2x.config_gamepad(clk,cmd,att,data,true,false);
  pinMode( A5, OUTPUT);
  pinMode( A4, OUTPUT);
  pinMode( A3, OUTPUT);
  pinMode( A2, OUTPUT);
  pinMode( A1, OUTPUT);
  
  pinMode( 4 , OUTPUT);
  pinMode( 2, OUTPUT);
  pinMode( 1, OUTPUT);
  
}

// MAIN LOOP -----------------------------------------------------------------
void loop()
{
  ps2x.read_gamepad();
  
      
  //-------------------------------   
  lefty = ps2x.Analog(PSS_LY);
  lefty = map(lefty,0,255,255,-255);
  if(lefty > 5)
  {
    
    drive(lp, ln, lefty);
    drive(rp, rn, lefty);  
  
  } 
  else if(lefty < -5)
  {
    lefty = (-1)*lefty;
    
    drive(ln, lp, lefty);
    drive(rn, rp, lefty);
    
  }
  else
  {
    halt(lp, ln, rp, rn);
  }
   
  //--------------------------------        
  leftx = ps2x.Analog(PSS_LX);
  leftx = map(leftx,0,255,-255,255);
  if(leftx > 5)
  {
    
    drive(up, un, leftx);
    drive(dp, dn, leftx);  
  
  } 
  else if(leftx < -5)
  {
    leftx = (-1)*leftx;
    
    drive(un, up, leftx);
    drive(dn, dp, leftx);
    
  }
  else
  {
    halt(up, un, dp, dn);
  }
  
  //---------------------------------            
  rightx = ps2x.Analog(PSS_RX);
  rightx = map(rightx,0,255,-255,255);
  if(rightx > 5)
  {

    drive(up, un, rightx);
    drive(dn, dp, rightx);  
    drive(ln, lp, rightx);
    drive(rp, rn, rightx); 
  }
  if(rightx < -5)
  {
    rightx = (-1)*rightx;
    
    drive(un, up, rightx);
    drive(dp, dn, rightx);  
    drive(lp, ln, rightx);
    drive(rn, rp, rightx); 
    
  }
3.

  
  delay(50); // Delay to prevent sudden change in motor direction 
}


// DRIVE ----------------------------------------------------------------
void drive(int h, int l, int value)
{
  analogWrite(pwm1, value);
  analogWrite(pwm2, value);
  analogWrite(pwm3, value);
  analogWrite(pwm4, value);
  digitalWrite(h, HIGH);
  digitalWrite(l, 0);
}
void halt(int a, int b, int c, int d)
{
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
}
