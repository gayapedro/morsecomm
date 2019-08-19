#define led 8
#define dotduration 1000
String textToMorse;
String charCode;
String digits[36] = {".-","-...","-.-.","-..",".","..-.",
                      "--.","....","..",".---","-.-",".-..",
                      "--","-.","---",".--.","--.-",".-.",
                      "...","-","..-","...-",".--","-..-",
                      "-.--","--..","-----",".----","..---","...--",
                      "....-",".....","-....","--...","---..","----."};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  charCode = "";
  textToMorse = "";
}

void dotFlash(){
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    textToMorse = Serial.readString();
    for(int i=0;i<textToMorse.length();i++){
      if(isDigit(textToMorse[i])) charCode = digits[textToMorse[i]-22];
      else charCode = digits[textToMorse[i]-97];
    }
  }
}
