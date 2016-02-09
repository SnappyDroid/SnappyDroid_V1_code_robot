#include <LiquidCrystal.h> //Carrega a biblioteca LiquidCrystal

//Define os pinos que serão utilizados para ligação ao display WH1602A
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void setup() 
{
  //Define o número de colunas e linhas do LCD:
  lcd.begin(16, 2);
  //Envia o texto entre aspas para o LCD :
  lcd.print("SnappyDroid teste lcd");
}

void loop()
{
  
}
