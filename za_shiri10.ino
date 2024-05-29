#include<LiquidCrystal.h> //include the library code
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include"DHT.h" //include the library code
#define DHTTYPE DHT11
#define DHTPIN 8
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  dht.begin();
  Serial.begin(9600); //setup serial
  lcd.begin(16, 2);
}

void loop() {
  float Temp = dht.readTemperature();
  int Humidity = dht.readHumidity();
  //put your main code,to run repeatedly
  lcd.setCursor(0, 0); //character positioning
  lcd.print("Temp:"); //show Temp
  lcd.print(Temp); //show Temp
  lcd.print("*C"); //show Temp
  lcd.setCursor(0, 1); //character positioning
  lcd.print("Humidity:"); //show Humidity
  lcd.print(Humidity); //show Humidity
  lcd.print("%"); //show Humidity
  delay(1000); //waits for a second
  lcd.clear();
}
