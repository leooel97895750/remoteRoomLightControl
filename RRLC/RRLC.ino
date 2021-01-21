#include <SoftwareSerial.h>
#include <Servo.h>

//設定10、11為藍芽通訊阜，(分別TXD、RXD)
SoftwareSerial BTSerial(10,11);
Servo myservo;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  myservo.attach(9);
  Serial.println("Ready");
}

void loop() {
  if(BTSerial.available()){
    char command = BTSerial.read();
    Serial.println(command);
    if(command == 'o'){
      //開啟訊號，順轉伺服馬達
      Serial.println("open");
      myservo.write(180);
    }
    else if(command == 'c'){
      //關閉訊號，逆轉伺服馬達
      Serial.println("close");
      myservo.write(0);
    }
  }
  if(Serial.available()){
    BTSerial.write(Serial.read());
  }
}
