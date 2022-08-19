/*
  LiquidCrystal

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 */

// include the library code:
#include <Servo.h>
#include <LiquidCrystal.h>
#include <IRremote.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int RECV_PIN = 7;  //ir sensor to pin 7
IRrecv irrecv(RECV_PIN);
decode_results results;

const int red = 6;
const int green = 8;
const int buzzPin = 13;
Servo myservo;

void setup()
{
 Serial.begin(9600);
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 lcd.begin(16, 2);
 irrecv.enableIRIn();
 // Print a message to the LCD.
 pinMode(red, OUTPUT);      // sets the digital pin as output
 pinMode(green, OUTPUT);      // sets the digital pin as output
 pinMode(buzzPin, OUTPUT);
}

void loop() 
{
  // set the cursor to column 0, lllllline 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.     
{     
   Serial.println(results.value, HEX);
   irrecv.resume(); // Receive the next value
  }
  delay(100);

  switch(results.value)  
  {
   // do something different depending on the range value:
  case 0xFFA25D :  // power button
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("PIN required");
      delay(1000);
      break;
      }
      case 0xFF629D :  
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
    case 0xFF22DD :  
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
      case 0xFF02FD :  
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
      case 0xFFC23D :  
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
      case 0xFFE01F :  
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
      case 0xFFA857 :  
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
      case 0xFF906F :  
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
    case 0xFF30CF :  // button number 1
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Requires 3 pins");
      delay(1000);
      break;
      }
    case 0xFF18E7 :  // button number 2
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Requires 2 pins");
      delay(1000);
      break;
     }
    case 0xFF7A85 :  // button number 3
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Requires 1 pin");
      delay(1000);
      break;
     }
    case 0xFF10EF :  // button number 4
    {
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Password Granted");
      delay(1000);
      myservo.write(0);
      delay(15);
      break;
    }
    case 0xFF38C7 :  // button number 5
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
      case 0xFF5AA5 :  // button number 6
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
      case 0xFF42BD :  // button number 7
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
      case 0xFF4AB5 :  // button number 8
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
      case 0xFF52AD :  // button number 9
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Incorrect PIN");
      delay(1000);
      break;
      }
    case 0xFFE21D :  // button number func/stop
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      myservo.write(180);
      delay(15);
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("Locked");
      delay(1000);
      break;
     }
  case 0xFF6897 :  // button number 0
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Reset Password?");
      delay(1000);
      break;
     }
  case 0xFF9867 :  // button eq
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Are you sure?");
      delay(1000);
      break;
     }
   case 0xFFB04F :  // button st/rept
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, HIGH);
      delay(1000);
      digitalWrite(buzzPin, LOW);
      delay(1000);
      myservo.write(90);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Password Reset");
      delay(1000);
      break;
      } 
  }
}       
