#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int LDR_PIN = A0;
const int GREEN_LED_PIN = 2;
const int YELLOW_LED_PIN = 3;
const int RED_LED_PIN = 4;
const int BUZZER_PIN = 8;
const int TEMP_SENSOR_PIN = A1;
const int PinoSensorUmidade = A3;

double tempC = 0;
double tempF = 0;
int RawValue = 0;
int humiditysensorOutput = 0;

unsigned long previousTime = 0;
int buzzerState = LOW;

void setup() {
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PinoSensorUmidade, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Configuração para alerta de luminosidade
  int lightValue = analogRead(LDR_PIN);

  if (lightValue >= 750 && lightValue <= 1020) {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
  } else if (lightValue <= 750 && lightValue >= 600) {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
  } else if (lightValue < 600) {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(3000);
    digitalWrite(BUZZER_PIN, LOW);
  }
//configuração para regular temperatura
  RawValue = analogRead(TEMP_SENSOR_PIN);
  double voltage = (RawValue / 1023.0) * 5000;
  tempC = (voltage - 500) / 10.0;
  tempF = (tempC * 1.8) + 32;
  Serial.print("\t Temperature in C = ");
  Serial.print(tempC, 1);
  Serial.print("\t Temperature in F = ");
  Serial.println(tempF, 1);
  Serial.print("Luminosidade: ");
  Serial.println(lightValue);

  //Configuração para o display LCD ligar e fornecer dados 
  LiquidCrystal_I2C lcd(34, 16, 2);

  humiditysensorOutput = analogRead(PinoSensorUmidade);
  int humidityPercentage = map(humiditysensorOutput, 0, 876, 0, 100);

  if (humidityPercentage <= 50) {
    
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Umidade Baixa");
    lcd.setCursor(0, 1);
    

    delay(2000);
  }

  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1);
  lcd.print("C / ");
  lcd.setCursor(0, 1);

  lcd.print("Umid Solo: ");
  lcd.print(humidityPercentage);
  lcd.print("%");
  lcd.print("");

  Serial.print("Umidade do Solo: ");
  Serial.print(humidityPercentage);
  Serial.println("%");
  delay(1000);
}
