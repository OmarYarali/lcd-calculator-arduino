#include <LiquidCrystal.h>
#include <ctype.h>
#include <math.h>

LiquidCrystal lcd(13, 8, 9, 10, 11, 12);
double firstNum = 0;
double secondNum = 0;
char op;
double answer = 0;
String errorMsg = "Math Error";

void setup() {
 lcd.begin(16, 2);
 Serial.begin(9600);
 Serial.setTimeout(200);
}

void loop() {
// Handling First Number
  lcd.setCursor(0, 0);
  lcd.print("Enter 1st number");
  lcd.setCursor(0, 1);

  while(!Serial.available()){
     lcd.blink();}
  lcd.noBlink();

  firstNum = Serial.parseFloat();
  lcd.print(firstNum);
  delay(1000);
  lcd.clear();
  
 

// Handling Second Number
  lcd.print("Enter 2nd number");
  lcd.setCursor(0, 1);

  while(!Serial.available()){    
    lcd.blink();}
    lcd.noBlink();
  
  secondNum = Serial.parseFloat();
  lcd.print(secondNum);
  delay(1000);
  lcd.clear();


// Handling Arithmetic ops(+, -, *, /, ^)
  lcd.print("Enter operator");
  lcd.setCursor(0, 1);

  while(!Serial.available()){
        lcd.blink();}
  lcd.noBlink();

  op = Serial.read();
  lcd.print(op);
  delay(1000);
  lcd.clear();

 

// Operator checking( If the user enters an invalid character, the program will do nothing).

  if(op == '+')
  answer = firstNum + secondNum;

  else if(op == '-')
  answer = firstNum - secondNum;

    else if(op == '*')
  answer = firstNum * secondNum;
 
    else if(op == '/')
      if(secondNum == 0){ // ( Error handling for dividing with 0).
        lcd.clear();
      lcd.print(errorMsg);
      delay(2000);
      return; //(If the user tries to divide First Number with 0, the program will print the message and will start to loop again).
      }

      else
  answer = firstNum / secondNum;
  
      else if(op == '^')
  answer = pow(firstNum, secondNum);
  
 // After calculation formatting for Answer screen

  lcd.print(firstNum);
  lcd.print(op); 
  lcd.print(secondNum);
  
   
    lcd.setCursor(0, 1);
    lcd.print("Answer = ");
  
  lcd.print(answer);
    delay(3000);
  lcd.clear();

}
