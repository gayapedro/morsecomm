#define led 8
#define dotduration 300
unsigned long time;
String textToMorse;
String charCode;
String digits[36] = {".-","-...","-.-.","-..",".","..-.",
                      "--.","....","..",".---","-.-",".-..",
                      "--","-.","---",".--.","--.-",".-.",
                      "...","-","..-","...-",".--","-..-",
                      "-.--","--..","-----",".----","..---","...--",
                      "....-",".....","-....","--...","---..","----."};
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  charCode = "";
  textToMorse = "";
}

void dotFlash(){
  time = millis();
  digitalWrite(led, HIGH);
  while(millis()<(time+dotduration));
  digitalWrite(led, LOW);
}

void dashFlash(){
  time = millis();
  digitalWrite(led, HIGH);
  while(millis()<(time+dotduration*3));
  digitalWrite(led, LOW);
}

void interval(){
  time = millis();
  while(millis()<(time+dotduration));
}

void space() {
  time = millis();
  while(millis()<(time+dotduration*7));
}

void loop() {
  if(Serial.available()>0){
    textToMorse = Serial.readString();
    for(int i=0;i<textToMorse.length();i++){
      if(isDigit(textToMorse[i])) charCode = digits[textToMorse[i]-22];
      else charCode = digits[textToMorse[i]-97];
      for(int j=0;j<charCode.length();j++){
        if(charCode[j]=='.') dotFlash();
        else dashFlash();
        if(j != charCode.length()-1) interval();
        else{
          if(i != textToMorse.length()-1) space();
        }
      }
    }
  }
}
