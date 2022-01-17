[16.00, 17/1/2022] TI C Salma: #include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo myservo1; 
Servo myservo2;

int pos = 0;

const int pinBuzzer = 12;
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(2, DHT11);
int isObstaclePin = 7;
int isObstacle = HIGH;

void setup(){
 Serial.begin(9600);
 dht.begin();
 lcd.begin();
pinMode(pinBuzzer, OUTPUT); 
//pinMode(LED, OUTPUT);
pinMode(isObstaclePin, INPUT);
myservo1.attach(9); //deklarasi servo pada pin 9
myservo2.attach(8);
}

void loop(){
 float suhu = dht.readTemperature();
 isObstacle = digitalRead(isObstaclePin);
 

 if (isObstacle == LOW) {   
 digitalWrite(pinBuzzer, HIGH);    
 delay(200);       
 digitalWrite(pinBuzzer, LOW);     
 delay(1000);         
 Serial.println("Hand sanitizer ready!!");
 //digitalWrite(LED, HIGH);
 for(pos = 0; pos < 180; pos+= 1) // perulangan untuk posisi 0 sampai 180 derajat

  { 

   myservo1.write(pos); // memerintahkan servo ke posisi derajat sesuai nilai variabel pos

   delay(1);

  }

  for(pos = 180; pos>=1; pos-=1) // perulangan untuk posisi 180 sampai 0 derajat

  {

   myservo1.write(pos); // memerintahkan servo ke posisi derajat sesuai nilai variabel pos
   delay(0); 
   
 } 
  for(pos = 0; pos < 180; pos+= 1) // perulangan untuk posisi 0 sampai 180 derajat

  { 

   myservo2.write(pos); // memerintahkan servo ke posisi derajat sesuai nilai variabel pos

   delay(1);

  }

  for(pos = 180; pos>=1; pos-=1) // perulangan untuk posisi 180 sampai 0 derajat

  {

   myservo2.write(pos); // memerintahkan servo ke posisi derajat sesuai nilai variabel pos
   delay(0); 
  }}else {
 Serial.println("Hand sanitizer done!!");
 //lcd.println("Hand sanitizer done!!"); 
 //digitalWrite(LED, LOW);
 }
  
 delay(200); 
  lcd.clear();
 Serial.print("suhu: ");
 Serial.print(suhu);
 lcd.setCursor(0,0);
  lcd.print("suhu : ");
  lcd.setCursor(0,1);
  lcd.print(suhu);
   lcd.print("'C");
                         

}
