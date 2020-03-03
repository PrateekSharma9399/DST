#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
const char arduinoId = '2';
void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(13,OUTPUT);
}
String totalString="";
int stat  =0;
void loop(){
  while(mySerial.available()){
    char a = mySerial.read();
    totalString += a;
    stat = 1;
  }
  if(stat){
    Serial.println(totalString);
    if(totalString[0] == arduinoId){
      digitalWrite(13,HIGH);
      Serial.println("Mein chl gya");
      delay(300);
      digitalWrite(13,LOW);
    }
    totalString = "";
    stat = 0;  
  }
}

