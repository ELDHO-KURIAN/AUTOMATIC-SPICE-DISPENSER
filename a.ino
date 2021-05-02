const int stepPin = 6; // define pin for step
const int dirPin = 5;  // define pin for direction
int x;
int y;
int val;
int stp;
int q;
int rot;
int ro;
int relay;
int zero;
char chr;
int tmr;
int valx;
int srv;
int mode;
int delay1;
int delay2;
int delay3;
int lcdd;
int delay4;

#define CdK 18
#define DT 19
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
unsigned long lastButtonPress = 0;
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int pres;
int me=0;
//int ro;
int counter2 =0;
int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";
int btnprs;














float value = 65285; 
#include "HX711.h"
#include <Servo.h>
Servo myservo;

float calibration_factor =394702.00; 
#define zero_factor 8299177

#define DOUT  3
#define CLK   4
#define DEC_POINT  2

float offset=0;
float get_units_kg();




HX711 scale(DOUT, CLK);
void setup() {

Serial.begin(9600);
lcd.init();
  lcd.backlight();
 digitalWrite(13,HIGH);
  Serial.println("Load Cell");
  scale.set_scale(calibration_factor); 
  scale.set_offset(zero_factor);   
  scale.tare();
  pinMode(CdK,INPUT);
  pinMode(DT,INPUT);
pinMode(8,INPUT);
  lastStateCLK = digitalRead(CdK);
  attachInterrupt(4, updateEncoder, CHANGE);
  attachInterrupt(5, updateEncoder, CHANGE);
  me=0;
pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(12,INPUT);
  pinMode(13,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
  pinMode(30,OUTPUT);
  pinMode(31,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(35,OUTPUT);
  pinMode(36,OUTPUT);
  pinMode(37,OUTPUT);
  pinMode(9,INPUT);
lcdd=0;
delay2=0;
delay3=0;
 digitalWrite(13,HIGH);
val=1;
 zero=0; 
noInterrupts();                       // disable all interrupts
  
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = value;                        // preload timer
  TCCR1B |= (1 << CS10)|(1 << CS12);    // 1024 prescaler 
  TIMSK1 |= (1 << TOIE1);               // enable timer overflow interrupt ISR
  interrupts();  // enable all interrupts
lcd.print("SPICE DISPENSER");
delay(1000);
lcd.clear();
lcd.print("MADE BY");
lcd.setCursor(0,1);
lcd.print("ELDHO KURIAN");
delay(1000);
lcd.clear();
lcd.print("STARTING....");
delay(2000);
lcd.clear();

}
ISR(TIMER1_OVF_vect)                    // interrupt service routine for overflow
{
  
  TCNT1 = value;  // preload timer
  if(valx==1){
  tmr=tmr+1;
  srv=srv+1;
}
if(mode==0){
  delay4++;
}

}
void loop() {
 mode = digitalRead(9);
   y = digitalRead(12);
  
if(val==1){
  
  digitalWrite(13,LOW);
  digitalWrite(dirPin, HIGH);
  digitalWrite(stepPin,HIGH);
  delayMicroseconds(6000);
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(6000);
 
  if(y==0){
    val=0;
    x=0;
    valx=0;
    tmr=0;
    
    delay(1200);
    digitalWrite(13,HIGH);
    digitalWrite(relay,LOW);
      scale.tare();
      delay2=0;
      delay3=0;
  }
}


    
   if(mode==1){
    delay2=0;
  if(delay1==0){
    lcd.clear();
    lcd.print(" BLE MODE");
    delay1 ++;
  }
if(Serial.available()){
  chr = Serial.read();

 
    if(chr=='a'){
      Serial.println("ok");
      q=1;
      rot=80;
      relay=23;
      myservo.attach(22);
      
    }
  


    if(chr=='b'){
      Serial.println("ok");
      q=1;
      rot=105;
      relay=25;
      myservo.attach(24);
    }
  
 
    if(chr=='c'){
      Serial.println("ok");
      q=1;
      rot=125;
      relay=27;
      myservo.attach(26);
    }
  
 
    if(chr=='d'){
      Serial.println("ok");
      q=1;
      rot=157;
      relay=29;
      myservo.attach(28);
    }
  
  
    if(chr=='e'){
      Serial.println("ok");
      q=1;
      rot=180;
      relay=31;
      myservo.attach(30);
    }
  
 
    if(chr=='f'){
      Serial.println("ok");
      q=1;
      rot=5;
      relay=33;
      myservo.attach(32);
      
    }
  
 
    if(chr=='g'){
      Serial.println("ok");
      q=1;
      rot=27;
      relay=35;
      myservo.attach(34);
      
    }
  
 
    if(chr=='h'){
      Serial.println("ok");
      q=1;
      rot=55;
      relay=37;
      myservo.attach(36);
      
    }
  

 
  if(chr=='i'){
    ro=ro+10;
  }
  if(chr=='j'){
    ro=ro-10;
  }
       
}

   }  




if(val==0 && q==1){
  if(zero==0){
    scale.tare();
  }
  if(x<rot){
    lcdd=0;
    zero=1;
    digitalWrite(13,LOW);
  digitalWrite(dirPin, LOW);
  digitalWrite(stepPin,HIGH);
  delayMicroseconds(6000);
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(6000);
  x=x+1;
  
  }
  if(x>=rot){
  valx=1;
  }

  
 if(x>=rot && tmr>80){
  digitalWrite(13,HIGH);
  digitalWrite(relay,HIGH);
  myservo.write(60);
  if(srv >= 60){
   myservo.write(0);
   srv=0; 
  }
  float val1;
  Serial.print("Reading: ");
  String data = String(get_units_kg()+offset, DEC_POINT);
  val1=data.toFloat();
  if(delay3==0){
    lcd.clear();
  lcd.print("  DISPENSING..");
  lcd.setCursor(0,1);
  lcd.print("  PLEASE WAIT");
    delay3 ++;
  }
 
 if(val1>ro){
 digitalWrite(relay,LOW);
 valx=0;
 tmr=0;
 myservo.write(0);
  x=0;
  q=0;
  delay1=0;
 counter=0;
  val=1;
  zero=0;
  lcdd=0;
  delay2=0;
  lcd.clear();
 }
  Serial.print(data);
  Serial.println(" g");
  
 
 }
  }
   

if(mode==0){
  
delay1=0;
int btnState = digitalRead(8);
if(counter>0){
  lcdd=1;
}
if(delay2<1){
    lcd.clear();
    lcd.print(" MANUAL MODE");
    delay2 ++;
  }

if(lcdd==1){
 switch(counter){

        case 0:
        delay2=0;
        lcdd=0;
        break;
        case 1:
        lcd.setCursor(1,0);
        lcd.print("CONTAINER 1");
        break;
        case 2:
        lcd.setCursor(1,0);
        lcd.print("CONTAINER 2");
        break;
        case 3:
        lcd.setCursor(1,0);
        lcd.print("CONTAINER 3");
        break;
        case 4:
        lcd.setCursor(1,0);
        lcd.print("CONTAINER 4");
        break;
        case 5:
        lcd.setCursor(1,0);
        lcd.print("CONTAINER 5");

        break;
        case 6:
        lcd.setCursor(1,0);
        lcd.print("CONTAINER 6");
        break;
        case 7:
        lcd.setCursor(1,0);
        lcd.print("CONTAINER 7");
        break;
        case 8:
        lcd.setCursor(1,0);
        lcd.print("CONTAINER 8");
        break;
 }
}
     if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
       me =1;
      btnprs ++;
      
      if(btnprs>1){
         if(counter==1){
          lcdd=0;
      Serial.println("ok");
      q=1;
      rot=80;
      relay=23;
      myservo.attach(22);
      counter=0;
        delay3=0;
    }
  

    if(counter==2){
      lcdd=0;
      Serial.println("ok");
      q=1;
      rot=105;
      relay=25;
      myservo.attach(24);
      counter=0;
        delay3=0;
    }
  
 
    if(counter==3){
      lcdd=0;
      Serial.println("ok");
      q=1;
      rot=125;
      relay=27;
      myservo.attach(26);
      counter=0;
        delay3=0;
    }
  
 
    if(counter==4){
      lcdd=0;
      Serial.println("ok");
      q=1;
      rot=157;
      relay=29;
      myservo.attach(28);
      counter=0;
        delay3=0;
    }
  
  
    if(counter==5){
      lcdd=0;
      Serial.println("ok");
      q=1;
      rot=180;
      relay=31;
      myservo.attach(30);
      counter=0;
        delay3=0;
    }
  
 
    if(counter==6){
      lcdd=0;
      Serial.println("ok");
      q=1;
      rot=5;
      relay=33;
      myservo.attach(32);
      counter=0;
        delay3=0;
      
    }
  

 
    if(counter==7){
      lcdd=0;
      Serial.println("ok");
      q=1;
      rot=27;
      relay=35;
      myservo.attach(34);
      counter=0;
        delay3=0;
      
    }
  
 
    if(counter==8){
      lcdd=0;
      Serial.println("ok");
      q=1;
      rot=55;
      relay=37;
      myservo.attach(36);
      counter=0;
        delay3=0;
      
    }
        me=0;
        btnprs=0;
      }
      
    }
  
    lastButtonPress = millis();
  }
  if(counter>8){
    counter=8;
  }
  if (counter<1){
    counter=0;
  }
  

if(me==1){
    Serial.println(btnprs);
   
    lcd.setCursor(0,1);
    lcd.print(ro);
    lcd.print(" g");
    ro=counter2;
    if(counter2<0){
      counter2=0;
    }
 if(delay4>6){
   lcd.clear();
   delay4=0;
   }
  }
 
}
}
float get_units_kg()
{
  return(scale.get_units()*453.592);
}

void updateEncoder(){
  // Read the current state of CLK
  currentStateCLK = digitalRead(CdK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      if(me==0){
      counter --;
      }else{
        counter2 --;
      }
      currentDir ="CCW";
    } else {
      // Encoder is rotating CW so increment
      if(me==0){
      counter ++;
      }else{
        counter2 ++;
      }
      currentDir ="CW";
    }

    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | Counter: ");
    Serial.println(counter);
  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK;
}
