#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MQUnifiedsensor.h>

// Configuração do GPS
static const int RXPin = 4;  // Pino RX para o módulo GPS
static const uint32_t GPSBaud = 9600;
SoftwareSerial ss(RXPin, -1);  // Configura o SoftwareSerial para apenas RX

// Configuração do display OLED
#define SCREEN_WIDTH 128 // Largura do display em pixels
#define SCREEN_HEIGHT 64 // Altura do display em pixels
#define OLED_RESET -1
#define OLED_ADDR 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Configuração do sensor MQ-7
#define Board ("Arduino UNO")
#define Pin A0 
#define Type ("MQ-7")
#define Voltage_Resolution 5
#define ADC_Bit_Resolution 10
#define RatioMQ7CleanAir 27.0
MQUnifiedsensor MQ7(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);

void setup() {
  // Inicialização das interfaces seriais
  Serial.begin(9600);
  ss.begin(GPSBaud);

  // Inicialização do display OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("Falha na inicialização do display SSD1306!"));
    for(;;);
  }
  display.clearDisplay();
  display.display();

  // Inicialização do sensor MQ-7
  MQ7.init();
  MQ7.setRegressionMethod(1); // Método de regressão exponencial
  MQ7.setA(99.042); MQ7.setB(-1.518); // Configuração da curva para CO
}

void loop() {
  // Atualização do sensor MQ-7 e leitura da concentração de CO
  MQ7.update(); 
  float CO = MQ7.readSensor();

  // Atualização do display OLED com as informações do sensor
  display.clearDisplay();
  display.setTextSize(1);      
  display.setTextColor(WHITE); 
  display.setCursor(0,0);
  display.println("Concentracao de CO:");
  display.print(CO);
  display.println(" ppm");
  
  // Leitura dos dados do GPS e exibição no monitor serial
  if (ss.available() > 0) {
    char c = ss.read();
    Serial.write(c);
    display.setCursor(0, 20); // Ajuste de cursor para exibir os dados do GPS
    display.print(c);
  }

  display.display();

  // Pequeno delay para estabilidade
  delay(1000);
}
