#include <LiquidCrystal.h> //Inclui a biblioteca do LCD
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Configura os pinos do Arduino para se comunicar com o LCD
 
//int temp; //Inicia uma variável inteira(temp), para escrever no LCD a contagem do tempo
//int reg = 4248000; //Segundos atá Janeiro de 2016
String  tx  = "O melhor suporte";
String  tx1 = "    Do Brasil   ";
String  tx2 = "SnappyDroid.com ";
void setup()
{

lcd.begin(16, 2); //Inicia o LCD com dimensões 16x2(Colunas x Linhas)

lcd.setCursor(0, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
lcd.print("HostGator Brasil"); //Escreve no LCD 
 
}
 
void loop()
{
  
  delay(1000);
  lcd.setCursor(0, 2); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
  lcd.print(tx); //Escreve no LCD 
  delay(2000);
  lcd.setCursor(0, 2); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
  lcd.print(tx1); //Escreve no LCD 
  delay(1000);
  lcd.setCursor(0, 2); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
  lcd.print("                "); //Escreve no LCD 
  delay(1000);
  lcd.setCursor(0, 2); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
  lcd.print(tx2); //Escreve no LCD 
  
}
