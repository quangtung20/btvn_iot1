String data;
void setup(){
  pinMode(16, OUTPUT);
  Serial.begin(9600);
}

char buff[8];
void loop(){
  if(Serial.available() > 0){
    data=Serial.readString();
  }
   for (uint8_t len = 1;len<=data.length()+1; len++){
    data.toCharArray(buff,len);
   }
    Serial.println(buff);
    if(strstr(buff,"LED ON")!=NULL)
    {
     digitalWrite(16,0);
    }
    if(strstr(buff,"LED OFF")!=NULL)
    {
     digitalWrite(16,1);
    }
}
