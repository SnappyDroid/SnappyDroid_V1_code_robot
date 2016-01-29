#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() 
{
  //Serial.begin(9600); 
  lcd.begin(20,4); -
  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); //Ativa a luz de fundo
  lcd.setCursor(0, 0); //seta o cursor na coluna 0 linha 1
  lcd.print("Linha zero 123456789"); // escreve
    lcd.setCursor(0, 1); //seta o cursor na coluna 0 linha 2
  lcd.print("Linha um   123456789");
    lcd.setCursor(0, 2);//seta o cursor na coluna 0 linha 3
  lcd.print("Linha dois 123456789");
    lcd.setCursor(0, 3); //seta o cursor na coluna 0 linha 4
  lcd.print("Linha tres 123456789");  
 
}


void loop()   
{


}
