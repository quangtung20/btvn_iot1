#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer webServer(80);
char* ssid = "Cong Thanh";
char* pass = "12346789";

const char MainPage[] PROGMEM = R"=====(
  <!DOCTYPE html> 
  <html>
   <head> 
       <title>Web bật đèn</title> 
       <style> 
          body {text-align:center;}
          h1 {color:#003300;}
          a {text-decoration: none;color:#FFFFFF;}
          .bt_on {height:50px; width:100px; margin:10px 0;background-color:#F0F600;border-radius:7px;me-5;}
          .bt_off {height:50px; width:100px; margin:10px 0;background-color:#000200;border-radius:7px;me-5;}
       </style>
       <meta charset="UTF-8">
   </head>
   <body> 
      <h1>BTVN3</h1> 
      <div>
        <button class="bt_on"><a href="/onD1">Bật</a></button>
        <button class="bt_off"><a href="/offD1">Tắt</a></button>
      </div>
      <div>
        <button class="bt_on"><a href="/onD2">Bật</a></button>
        <button class="bt_off"><a href="/offD2">Tắt</a></button>
      </div>
   </body> 
  </html>
)=====";
//=========================================//
void setup() {
  pinMode(2,OUTPUT);
  pinMode(16,OUTPUT);
  digitalWrite(2,HIGH);
  digitalWrite(16,HIGH);
  WiFi.begin(ssid,pass);
  Serial.begin(9600);
  Serial.print("Connecting");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print("...");
  }
  Serial.println(WiFi.localIP());

  webServer.on("/",mainpage);
  webServer.on("/onD1",on_D1);
  webServer.on("/offD1",off_D1);
  webServer.on("/onD2",on_D2);
  webServer.on("/offD2",off_D2);
  webServer.begin();
}
void loop() {
  webServer.handleClient();
}
void mainpage(){
  String s = FPSTR(MainPage);
  webServer.send(50,"text/html",s);
}
void on_D1(){
  digitalWrite(2,LOW);
  String s = FPSTR(MainPage);
  webServer.send(50,"text/html",s);
}
void off_D1(){
  digitalWrite(2,HIGH);
  String s = FPSTR(MainPage);
  webServer.send(50,"text/html",s);
}
void on_D2(){
  digitalWrite(16,LOW);
  String s = FPSTR(MainPage);
  webServer.send(50,"text/html",s);
}
void off_D2(){
  digitalWrite(16,HIGH);
  String s = FPSTR(MainPage);
  webServer.send(50,"text/html",s);
}
