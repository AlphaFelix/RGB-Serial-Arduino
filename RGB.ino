int redpin = 8;
int greenpin = 9;
int bluepin =10;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);

  Serial.begin(9600);
}

void setRGB(int value, char colorLed) {
  switch(colorLed) {
    case 'r' :
      analogWrite(redpin, value);
      break;

    case 'g':
      analogWrite(greenpin, value);
      break;

    case 'b' :
      analogWrite(bluepin, value);
      break;

    case 'l' :
      analogWrite(redpin, value);
      analogWrite(greenpin, value);
      analogWrite(bluepin, value);
      break;
  }  
}

void loop() {
  // put your main code here, to run repeatedly:
  char color = 'a';
  String valueString = "0";
  int valueInt = 0;
  String statusCom = "OK";
  
  if(Serial.available()) {
    color = Serial.read();
    if(color == 'r' || color == 'g' || color == 'b' || color == 'l') {
      valueString = Serial.readString();
    }
  }  
  valueInt = valueString.toInt();
  if(valueInt<0 || valueInt>255) {
    statusCom = "ERROR";
  }
  else {
    setRGB(valueInt, color);
  }
  Serial.println(statusCom);
    
  delay(100);

}
