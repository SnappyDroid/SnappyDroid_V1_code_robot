#include <LiquidCrystal.h> //Inclui a biblioteca do LCD
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Configura os pinos do Arduino para se comunicar com o LCD
 
//int temp; //Inicia uma variável inteira(temp), para escrever no LCD a contagem do tempo
//int reg = 4248000; //Segundos atá Janeiro de 2016
String  tx  = "Participe do projeto";
String  tx1 = " para me aprimorar. ";
//String  tx2 = "SnappyDroid - GitHub";
void setup()
{

lcd.begin(20, 4); //Inicia o LCD com dimensões 16x2(Colunas x Linhas)

lcd.setCursor(0, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
lcd.print("Gosta do meu visual?"); //Escreve no LCD 
lcd.setCursor(0, 3); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
lcd.print("SnappyDroid - GitHub"); //Escreve no LCD

 
}
 
void loop()
{
  
  delay(1000);
  lcd.setCursor(0, 1); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
  lcd.print(tx); //Escreve no LCD 
  delay(2000);
  lcd.setCursor(0, 2); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
  lcd.print(tx1); //Escreve no LCD 
  delay(1000);
  lcd.setCursor(0, 1); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
  lcd.print("                    "); //Escreve no LCD 
  lcd.setCursor(0, 2); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
  lcd.print("                   "); //Escreve no LCD 
  delay(1000);
  //lcd.setCursor(0, 2); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
  //lcd.print(tx2); //Escreve no LCD 
  
}
