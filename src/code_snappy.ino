<<<<<<< HEAD
/*
##################################################################
# Author       : Sinesio Bittencourt
# Email        : contato@sinesio.com.br or contact@sinesio.com.br
# Info         :
# Version      : 1.0 ( beta )
# Project      : http://git.sinesio.com.br
##################################################################
*/

#include <Wire.h>
=======
#include <Wire.h>  
>>>>>>> origin/master
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
//#include "Ultrasonic.h"

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distanceCm;

//Inicializa o sensor nos pinos definidos acima
//Ultrasonic ultrasonic(pino_trigger, pino_echo);


#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif
#define DHTTYPE DHT11
#define DHT11PIN 2

DHT dht(DHT11PIN, DHTTYPE);

uint8_t bell[8]  = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};
uint8_t note[8]  = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0};
uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
uint8_t duck[8]  = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};
uint8_t check[8] = {0x0, 0x1, 0x3, 0x16, 0x1c, 0x8, 0x0};
uint8_t cross[8] = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0};
uint8_t retarrow[8] = {  0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4};
byte grau[8] = { B00001100,
                 B00010010,
                 B00010010,
                 B00001100,
                 B00000000,
                 B00000000,
                 B00000000,
                 B00000000
               };

void setup()
{
// Screen
lcd.begin(20,4); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display

//Ultrason
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
//fim - Ultrason

  dht.begin();
  for (int i = 0; i < 3; i++)
  {
    lcd.backlight();
    //delay(250);
    delay(2000);
    lcd.noBacklight();

  }
  lcd.backlight(); //Ativa a luz de fundo
  lcd.setCursor(0, 0); //seta o cursor na coluna 0 linha 1
  delay(2000);


}


void VerificaDisplay(int AContador) {
  if (AContador == 20000) {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    lcd.clear();
    lcd.home ();
    lcd.setCursor(2, 0);
    lcd.print(t);
    lcd.printByte(8);
    lcd.print(" H:");
    lcd.print(h);
    lcd.print("%");
      lcd.setCursor(0, 1);
      lcd.print(" Tem uma sugestao?");
      lcd.setCursor(0, 2);
      lcd.print("Participe do projeto  ");
      lcd.setCursor(0, 3);
      lcd.print("  SnappyDroid.com");

    }
    if (distanceCm <= 20){
      lcd.setCursor(0, 3);
      lcd.print("  Distance: "); // Prints string "Distance" on the LCD
      lcd.print(distanceCm); // Prints the distance value from the sensor
      lcd.print(" cm");
      lcd.setCursor(0, 1);
      lcd.print("Hi my name is Snappy");
      lcd.setCursor(0, 2);
      lcd.print(" What's your name?  ");
        }
  }

void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
VerificaDisplay(20000);
delay(2000);


}
