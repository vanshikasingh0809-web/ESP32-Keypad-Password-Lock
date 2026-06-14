#include <Keypad.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#include<Wire.h>
#define buzzer 15
#define button 19
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define YELLOW 2
#define RED 5
#define BLUE 18
#define time 5
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire);
char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[4] = {13, 12, 14, 27};
byte colPins[4] = {26, 25, 33, 32};

Keypad keypad = Keypad(
  makeKeymap(keys),
  rowPins,
  colPins,
  4,
  4
);

String pass = "";
int no_ofchar = 0;
char key ;
void setup() {
  Serial.begin(115200);

  pinMode(2, OUTPUT);  
  pinMode(buzzer,OUTPUT); // ESP32 onboard LED
  digitalWrite(2, LOW);
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.clearDisplay();
  display.display();
  pinMode(button,INPUT_PULLUP);
}
int no_oftry=0;
int i=1,t=0;
void loop() {

  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  


  

  if(t==0){
  
    if (key= keypad.getKey()) {

    Serial.print("Pressed: ");
    Serial.println(key);
    display.setCursor(5,5);
   display.print("PRESSED: ");
   display.println(key);
   
    pass = pass + key;   // add only when key pressed
    
    display.print("String is: ");
    display.println(pass);
    display.display();
   display.clearDisplay();
  }
    if(digitalRead(button)==HIGH)
    {
      Serial.print("String is: ");
      Serial.println(pass);
      
       no_oftry++;
      if(pass == "1234A")
      {
        display.setCursor(5,5);
        display.println("Correct Password");
        Serial.println("Correct Password");
        display.display();
        digitalWrite(RED, LOW);
        digitalWrite(YELLOW, HIGH);

        tone(buzzer,1000);
        delay(200);
        tone(buzzer,1500);
        delay(200);
        tone(buzzer,2000);
        delay(200);

       noTone(buzzer);

       delay(5000);

        digitalWrite(YELLOW, LOW);
        digitalWrite(RED, HIGH);

        

        digitalWrite(2, HIGH);
        delay(1000);
        digitalWrite(2, LOW);
        no_oftry=0;
      }
      else
      {
        if(no_oftry==5)
       {
        t=1;
        digitalWrite(buzzer,HIGH);
       // delay(5000);
        digitalWrite(buzzer,LOW);
        display.setCursor(5,5);
        Serial.println("MAX TRY LIMIT EXCEEDED");
        display.println("MAX TRY LIMIT EXCEEDED");
        display.println("TRIES LEFT: 0");
        display.display();
        
        
      }
        else
      {
       
        display.setCursor(5,2);
        display.println("WRONG Password");
        display.println("TRY AGAIN");
        display.print("TRIES LEFT: ");
        display.println(5-no_oftry);
        
        display.display();
        delay(1000);
        Serial.println("Wrong Password");
        
      }

      
       }
      pass = "";
      no_ofchar = 0;
      
    } 
  }
  else if(t==1)
  {
    if(no_oftry==5)
  {
    if(i<=5)
   {
    display.setCursor(5,5);
    display.println("WAIT FOR 5sec");
    display.print("TIME LEFT: ");
    delay(1000*i);
    display.println(time-i);
    display.display();
    i++;
    }
    else{
    
    t=0;
    no_oftry=0;i=1;
     display.setCursor(5,5);
    display.println("TRY AGAIN");
    
    
    display.display();
    }



  }
  }
   display.clearDisplay();
}
