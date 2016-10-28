
    #define yellow_led PORTD.F0
    #define blue_led PORTD.F1

    int yellow_OR_blue[12];
    int yellow_value[12], blue_value[12], i ;
	int arraySize = 5;

    int ADC_Value(int channel)
     {
       return ADC_Read(channel);
     }

    void checkStatus()
     {
          // Yellow Value
           yellow_led = 1;
           Delay_ms(10);
		   for(i=0; i<arraySize; i++)
         {
           yellow_value[i] = ADC_Value(i);
		   Delay_ms(1);
		 }  
           yellow_led = 0;
            
		  // Blue Value	
           blue_led = 1;
           Delay_ms(10);
		   for(i=0; i<arraySize; i++)
		 {
           blue_value[i] = ADC_Value(i);
		   Delay_ms(1);
         }
		   blue_led = 0;
		   
		   // Comparison 
		   for(i=0; i<arraySize; i++)
		 {
           if(((blue_value[i]-yellow_value[i]) < 15 ) && ((yellow_value[i]-blue_value[i]) < 15 ))
             {
               yellow_OR_blue[i] = 2;
             }
           else
             {
               if(blue_value[i] > yellow_value[i])
                 {
                   yellow_OR_blue[i] = 0;
                 }
               if(yellow_value[i] > blue_value[i])
                 {
                    yellow_OR_blue[i] = 1;
                 }
              }
          }
    }

    void setup()
     {
      TRISD = 0b00000000;
      ANSEL = 0b11111111;
      ANSELH = 0b11111111;
      TRISA = 0b11111111;
      TRISB = 0b11111111;
      TRISE = 0b1111;
      ADC_Init();
   }

    void loop()
     {
        while(1)
         {
            checkStatus();
			
         }
     }


    void main()
     {
       setup();
       loop();
     }
