
int oldRGB[3] = {
  0,0,0};

void setup(){
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT); 
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  // anode
  digitalWrite(13,HIGH);

  // cathodes
  analogWrite(9,255);  
  analogWrite(10,255); 
  analogWrite(11,255); 

  Serial.begin(19200);
}

void loop(){
  int val = analogRead(A0);
  val = constrain(val,600,900);
  if(abs(val - oldRGB[0]) > 12){
    int mval = map(val,600,900,0,255);
    analogWrite(9,mval);
    oldRGB[0] = val;
    Serial.print("B ");
    Serial.print(mval);
    Serial.print('\n');
  }
  delay(10);

  val = analogRead(A1);
  val = constrain(val,600,900);
  if(abs(val - oldRGB[1]) > 12){
    int mval = map(val,600,900,0,255);
    analogWrite(10,mval);
    oldRGB[1] = val;
    Serial.print("R ");
    Serial.print(mval);
    Serial.print('\n');
  }
  delay(10);

  val = analogRead(A2);
  val = constrain(val,600,900);
  if(abs(val - oldRGB[2]) > 12){
    int mval = map(val,600,900,0,255);    
    analogWrite(11,mval);
    oldRGB[2] = val;
    Serial.print("G ");
    Serial.print(mval);
    Serial.print('\n');
  }
  delay(10);

}
