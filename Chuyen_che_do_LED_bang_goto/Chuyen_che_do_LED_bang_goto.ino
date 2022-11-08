#define nutnhan1 10
#define nutnhan2 11

int ledpin[] = {2,3,4,5,6,7,8,9};

int delayandcheck(int mdelay, int button)
{
  for(int i = 0 ; i < (mdelay/10) ; i++)
  {
    if(digitalRead(button) == 1)
    {
      return 1;
    }
    delay(10);    
  }
}

//Nút nhấn 1
void sangduoi()
{
  for(int i = 0 ; i < 8 ; i++)
  {
    digitalWrite(ledpin[i],HIGH);
    //delayandcheck(500,nutnhan2)
    if(delayandcheck(500,nutnhan2) == 1)
    {
      digitalWrite(ledpin[i],LOW); 
      goto bailout;
    }  
    digitalWrite(ledpin[i],LOW);  
  }
  bailout: ;
}

//Nút nhấn 2
void sangtat()
{
  for(int i = 0 ; i < 4 ; i++)
  {
    for (int j = 0 ; j < 8 ; j++)
    {     
      digitalWrite(ledpin[j],HIGH); 
      //delayMicroseconds(10);
    }
    //delayandcheck(500,nutnhan1);
    if(delayandcheck(500,nutnhan1) == 1)
    {
      for (int k = 0 ; k < 8 ; k++)
      {     
        digitalWrite(ledpin[k],LOW);        
      }
      goto bailout;
    }
    for (int k = 0 ; k < 8 ; k++)
    {     
      digitalWrite(ledpin[k],LOW);  
      //delayMicroseconds(10);
    } 
    //delayandcheck(500,nutnhan1);  
    if(delayandcheck(500,nutnhan1) == 1)
    {
      goto bailout;
    }     
  }
  bailout: ; 
}

void setup() {
  
  for(int i = 0 ; i < 8 ; i++)
  {
    pinMode(ledpin[i],OUTPUT);
  }
  for(int i = 0 ; i < 8 ; i++)
  {
    digitalWrite(ledpin[i],LOW);
  }
   
}

void loop() {

  if(digitalRead(nutnhan2) == 1)
    {
      sangtat();
    }
  if(digitalRead(nutnhan1) == 1)
    {
      sangduoi();
    }


  delay(10);
       
  
  
}
