#include <SoftwareSerial.h>
#include <Servo.h>

//設定10、11為藍芽通訊阜，(分別TXD、RXD)
SoftwareSerial BTSerial(10,11);
Servo myservo;

void setup() {
  BTSerial.begin(9600);
  myservo.attach(5);
}

void loop() {
  if(BTSerial.available()){
    char command = BTSerial.read();
    //Serial.println(command);
    if(command != 0){
      //敲下去
      myservo.write(150);
      delay(500);
      myservo.write(0);
    }
    else {
      //歸位
      myservo.write(0);
    }
  }
}
