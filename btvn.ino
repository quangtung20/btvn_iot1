int count;
boolean cmp=true;
boolean cmps;

ICACHE_RAM_ATTR void nhayled()
{
for(uint64_t i;i<2000000;i++)
{
  if(digitalRead(0))
  {
  cmps=true;
  break;
  }
  else
  cmps=false;
}
 if(cmps)
 digitalWrite(2,!digitalRead(2));
 else
 cmp=!cmp;
}

void setup() {
pinMode(16,OUTPUT);
pinMode(2,OUTPUT);
attachInterrupt(digitalPinToInterrupt(0),nhayled,FALLING);
Serial.begin(9600);
}

void loop() {
 if(cmp)
    {
      count=500;
    }
    else
      count=1000;
 digitalWrite(16,!digitalRead(16));
 Serial.println(digitalRead(16));
 delay(count);
  
}
