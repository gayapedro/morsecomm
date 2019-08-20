#define dotduration 10
unsigned long time;
int LDRpin = A5;
int durationOn = 0;
int durationOff = 0;
String phrase = "";
String charCode = "";
String digits[36] = {".-","-...","-.-.","-..",".","..-.",
                      "--.","....","..",".---","-.-",".-..",
                      "--","-.","---",".--.","--.-",".-.",
                      "...","-","..-","...-",".--","-..-",
                      "-.--","--..","-----",".----","..---","...--",
                      "....-",".....","-....","--...","---..","----."};
String translate[36] = {"a","b","c","d","e","f",
                        "g","h","i","j","k","l",
                        "m","n","o","p","q","r",
                        "s","t","u","v","w","x",
                        "y","z","0","1","2","3",
                        "4","5","6","7","8","9"};

void setup() {
  Serial.begin(9600);
  pinMode(A5, INPUT);
}

void morseToText(String charCode) {
  int index;
  for(int k=0;k<36;k++){
    if(charCode == digits[k]) index = k;
    //Serial.println(index);
  }
  Serial.print(translate[index]);
}

void loop() {
  time = millis();
  while(analogRead(LDRpin)<=180);
  durationOn = millis()-time;
  if(durationOn>(dotduration-10)&&durationOn<(dotduration+10)){
    charCode += ".";
  }else if(durationOn>(3*dotduration-10)&&durationOn<(3*dotduration+10)){
    charCode += "-";
  }
  time = millis();
  while(analogRead(LDRpin)>=180&&(millis()-time<5*dotduration));
  durationOff = millis()-time;
  if(durationOff >= 5*dotduration){
    //Serial.print(charCode);
    morseToText(charCode);
    //Serial.println("oi");
    //if(charCode != "") morseToText(charCode);
    charCode = "";
  }
}
