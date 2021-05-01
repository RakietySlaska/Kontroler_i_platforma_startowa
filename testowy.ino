#include <TM1637Display.h>
#include <Servo.h> //Biblioteka odpowiedzialna za serwa
#define CLK 4
#define DIO 3
Servo servo; //Tworzymy obiekt, dzięki któremu możemy odwołać się do serwa 
TM1637Display display(CLK, DIO);
int pozycja = 20;

void setup() {
  pinMode(10, INPUT_PULLUP); //Przycisk startu
  pinMode(9, OUTPUT); //dioda ssr
  pinMode(8, OUTPUT); //dioda
  pinMode(12, OUTPUT); //PRZ
  pinMode(2, OUTPUT); //Buzzer
  servo.attach(5);  //Serwomechanizm podłączony do pinu 9
  digitalWrite(12, LOW);
}

void loop() {
display.setBrightness(0x0f);
display.clear();
if (digitalRead(10) == LOW) {
  minus();
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
  //Początek migania
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(20,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(19,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(18,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(17,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(16,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(15,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(14,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(13,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(12,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(11,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(10,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(9,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(8,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(7,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(6,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  serwo();
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(5,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(4,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(3,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(2,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  display.showNumberDec(1,false,2,2);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  delay(500);
  //Koniec migania
  go();  
  digitalWrite(11, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(11, LOW);
  digitalWrite(2, LOW);
  digitalWrite(12, LOW);
  delay(2000);
  servo.write(0); 
}
  else{
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
  }  
}
void go(){
    uint8_t goMe[]={
  SEG_A|SEG_F|SEG_E|SEG_D|SEG_C,
  SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F, }; 
  display.clear();
  display.setSegments(goMe, 2, 0);
}

void minus() {
  uint8_t lMe[]={
  SEG_F|SEG_E|SEG_D,
  SEG_G,
};
display.setSegments(lMe, 2, 0);
}

void serwo() {
  servo.write(0); //Wykonaj ruch
}
