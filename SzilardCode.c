#include <Servo.h>
Servo myServo;
Servo myServo2;
#include<EduIntro.h>
#include <LiquidCrystal.h> //Idézze be az LCD kijelzőhöz való részletet a könyvtárból
LiquidCrystal lcd(13, 12, A0, A3, A2, A1);
int ablakvaltas = 0;
int ignore = 0;
long Timer = 0;
long Timer2 = 0;
long TimerEnd = 100;
int nyitas = 0;
int csukas = 0;
int servoallapot = 90;
int servoallapot2 = 0;
int SwitchState = 0;
int SwitchState2 = 0;
int C;
int C2;
int led = 2;
int gomb = 4;
int bekapcs = 0;
int y = A5;
int x = A4;
int oldal = 0;
int minhom = 19;
int maxhom = 24;
int ablakAb = 5;
int ablakAk = 7;
int ablakBb = 8;
int ablakBk = 9;
int fel = 0;
int le = 0;
int bal = 0;
int jobb = 0;

void setup() {

pinMode(x, INPUT);
pinMode(y, INPUT);
pinMode(ablakAb, INPUT);
pinMode(ablakAk, INPUT);
pinMode(ablakBb, INPUT);
pinMode(ablakBk, INPUT);
lcd.begin(16, 2);
Serial.begin(9600);
pinMode(led, OUTPUT);
lcd.setCursor(0,0);
lcd.print("Welcome!");
delay(1000);
lcd.clear();
myServo.attach(3);
myServo2.attach(6);
myServo.write(90);
myServo2.write(0);

}

void loop() {
Timer++;
if(Timer >= TimerEnd){
  Timer = 0;
  lcd.clear();
  oldal++;
  if(oldal == 3){ oldal = 0;}
}

if(oldal == 0){
lcd.setCursor(0,0);
lcd.print("Belso hom:");
lcd.print(C);
lcd.setCursor(12,0);
lcd.print("C");

lcd.setCursor(0,2);
lcd.print("Kulso hom:");
lcd.print(C2);
lcd.setCursor(12,2);
lcd.print("C");}

if(oldal == 1){
  if(bekapcs == 1 || bekapcs == 2){
    lcd.setCursor(0,0);
    lcd.print("Bekapcsolva!");}
  if(bekapcs == 0 || bekapcs == 3){
    lcd.setCursor(0,0);
    lcd.print("Kikapcsolva!");
  }
}

if(oldal == 2){
    lcd.setCursor(0,0);
    lcd.print("Maximalis hom:");
    lcd.print(maxhom);
    lcd.setCursor(0,2);
    lcd.print("Minimalis hom:");
    lcd.print(minhom);
}

DHT11 dht11a(11);
DHT11 dht11(10);

C = dht11.readCelsius();
//  Serial.print("C: ");
 // Serial.println(C);

C2 = dht11a.readCelsius();
C2 = C2 - 2;
 // Serial.print("C2: ");
 // Serial.println(C2);

dht11.update(); 
dht11a.update(); 

if(bekapcs == 1 || bekapcs == 2) {
  digitalWrite(led, HIGH);
}

if(bekapcs == 3 || bekapcs == 0) {
  digitalWrite(led,LOW);
}

if(digitalRead(gomb) == HIGH &&  bekapcs == 0){
  bekapcs = 1;
  goto oldalvaltas0;}
if(digitalRead(gomb) == LOW &&  bekapcs == 1){
  bekapcs = 2;}
if(digitalRead(gomb) == HIGH &&  bekapcs == 2){
  bekapcs = 3;
  goto oldalvaltas0;}
if(digitalRead(gomb) == LOW &&  bekapcs == 3){
  bekapcs = 0;}
  delay(5);

if(ignore == 1){
oldalvaltas0:
lcd.clear();
oldal = 1;
Timer = 1;}

Timer2++;
if(Timer2 == TimerEnd){
  if(minhom > C){
    ablakvaltas = 1;}
  if(maxhom <= C){
    ablakvaltas = 2;}
    Timer2 = 0;}

if(bekapcs == 1 || bekapcs == 2){
  if(ablakvaltas == 1){
    if(servoallapot > 0 && digitalRead(ablakBb) == LOW && digitalRead(ablakBk) == LOW){
      servoallapot = servoallapot - 1;
      myServo.write(servoallapot);}
    if(servoallapot2 < 90 && digitalRead(ablakAb) == LOW && digitalRead(ablakAk) == LOW){
      servoallapot2 = servoallapot2 + 1;
      myServo2.write(servoallapot2);}}

  if(ablakvaltas == 2){ 
    if(servoallapot < 90 && digitalRead(ablakBb) == LOW && digitalRead(ablakBk) == LOW){
      servoallapot = servoallapot + 1;
      myServo.write(servoallapot);}
    if(servoallapot2 > 0 && digitalRead(ablakAb) == LOW && digitalRead(ablakAk) == LOW){
      servoallapot2 = servoallapot2 - 1;
      myServo2.write(servoallapot2);}}}

SwitchState = analogRead(x); //A potméter ált meghat feszültség -> motor sebesség.
SwitchState2 = analogRead(y);

if(SwitchState <= 300 && fel == 0 && minhom <= 30 && minhom + 2 < maxhom){
  fel = 1;}
if(SwitchState >= 301 && SwitchState <= 599 && fel == 1 ){
  minhom = minhom + 1;
  fel = 0;
  goto oldalvaltas2;
  }

if(SwitchState >= 600 && le == 0 && minhom >= 15 && minhom + 1 < maxhom){
  le = 1;}
if(SwitchState >= 301 && SwitchState <= 599 && le == 1){
  minhom = minhom - 1;
  le = 0;
  goto oldalvaltas2;
  }

if(SwitchState2 <= 490 && jobb == 0 && maxhom <= 30 && minhom + 1 < maxhom){
  jobb  = 1;}
if(SwitchState2 >= 491 && SwitchState2 <= 559 && jobb == 1){
  maxhom = maxhom + 1;
  jobb = 0;
  goto oldalvaltas2;
  }

if(SwitchState2 >= 600 && bal == 0 && maxhom >= 15 && minhom + 2 < maxhom){
  bal = 1;}
if(SwitchState2 >= 301 && SwitchState2 <= 599 && bal == 1){
  maxhom = maxhom - 1;
  bal = 0;
  goto oldalvaltas2;
  }

if(ignore == 1){
oldalvaltas2:
lcd.clear();
oldal = 2;
Timer = 1;}
Serial.println(Timer2);
}
