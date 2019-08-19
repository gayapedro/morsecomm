#define dotduration 300
unsigned long time;
int LDRpin = A5;
int durationOn = 0;
int durationOff = 0;
String phrase = "";
String charCode = "";

void setup() {
  Serial.begin(9600);
  pinMode(A5, INPUT);
}

void loop() {
  time = millis();
  while(analogRead(LDRpin)<=110);
  Serial.println(analogRead(LDRpin));
  durationOn = millis()-time;
  if(durationOn>(dotduration-10)&&durationOn<(dotduration+10)){
    charCode += ".";
    Serial.print(charCode);
  }else if(durationOn>(3*dotduration-10)&&durationOn<(3*dotduration+10)){
    charCode += "-";
    Serial.print(charCode);
  }
  time = millis();
  while(analogRead(LDRpin)>=150&&(millis()-time<5*dotduration));
  durationOff = millis()-time;
  if(durationOff >= 5*dotduration){
    //Serial.print(charCode);
    charCode = "";
  }
  delay(500);
}
