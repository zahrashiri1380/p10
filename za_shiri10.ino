#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include"DHT.h"
#define DHTTYPE DHT11
#define DHTPIN 8
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  dht.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  float Temp = dht.readTemperature();
  int Humidity = dht.readHumidity();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(Temp);
  lcd.print("*C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.print(Humidity);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}
