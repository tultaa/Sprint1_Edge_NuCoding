#include <LiquidCrystal.h>
#include <DHT.h>

// Definição de pinos
#define DHTPIN 6
#define DHTTYPE DHT22 

// Configuração dos pinos do LCD (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

DHT dht(DHTPIN, DHTTYPE);

int lightSensor = A0;
int blueLED = 4;
int greenLED = 3;
int redLED = 2;
int buzzer = 5;

unsigned long previousMillis = 0;
const long interval = 5000;
bool showTemperatureAndHumidity = true;
bool anyProblem = false;

unsigned long buzzerStartMillis = 0;
unsigned long serialDisplayMillis = 0; // Variável para controlar o cooldown da exibição no Serial Monitor

void setup() {
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  dht.begin();
  
  Serial.begin(9600); // Inicia a comunicação serial

  // Mostrar o nome da equipe e "Formula E" de forma dinâmica
  animateText("Nu Coding", 0);
  animateText("Formula E", 1);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    showTemperatureAndHumidity = !showTemperatureAndHumidity;
    lcd.clear();
  }

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int lightLevel = analogRead(lightSensor);
  float voltage = lightLevel * (5.0 / 1023.0);
  float resistance = (5.0 - voltage) * 10000 / voltage;
  float lux = 500 / (resistance / 1000);

  // Exibir todos os resultados captados no Serial Monitor
  if (currentMillis - serialDisplayMillis >= 2000) {
    Serial.println("---------------");
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println(" C");
    Serial.print("Umidade: ");
    Serial.print(humidity);
    Serial.println(" %");
    Serial.print("Luz: ");
    Serial.print(lux);
    Serial.println(" Lux");
    Serial.println("---------------");
    serialDisplayMillis = currentMillis;
  }

  anyProblem = false; // Reset anyProblem flag

  if (showTemperatureAndHumidity) {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");
    
    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(humidity);
    lcd.print(" %");
    
    if (temperature > 30) {
      digitalWrite(redLED, HIGH);
      anyProblem = true;
    } else {
      digitalWrite(redLED, LOW);
    }

    if (humidity > 60) {
      digitalWrite(greenLED, HIGH);
      anyProblem = true;
    } else {
      digitalWrite(greenLED, LOW);
    }
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Luz: ");
    lcd.print(lux);
    lcd.print(" Lux");

    lcd.setCursor(0, 1);
    if (lux > 100) {
      lcd.print("Luminosidade Alta");
      digitalWrite(blueLED, HIGH);
      anyProblem = true;
    } else {
      lcd.print("Luminosidade OK  ");
      digitalWrite(blueLED, LOW);
    }
  }

  // Controle do buzzer
  if (anyProblem) {
    if (currentMillis - buzzerStartMillis >= 5000) {
      buzzerStartMillis = currentMillis;
    }
    if (currentMillis - buzzerStartMillis < 3000) {
      tone(buzzer, 1000); // Toca o buzzer com frequência de 1000 Hz
    } else {
      noTone(buzzer); // Para o buzzer
    }
  } else {
    noTone(buzzer); // Para o buzzer
    buzzerStartMillis = currentMillis;
  }

  delay(200);
}

// Função para exibir texto de forma animada no LCD
void animateText(String text, int row) {
  for (int i = 0; i < text.length(); i++) {
    lcd.setCursor(i, row);
    lcd.print(text[i]);
    delay(300);
  }
  delay(1500);
  lcd.clear();
}