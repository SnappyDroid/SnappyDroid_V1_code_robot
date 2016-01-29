//Programa : Menu com encoder e LCD 20x4
//Autor : Arduino e Cia

//Carrega biblioteca LCD e encoder
#include <LiquidCrystal.h>
#include <RotaryEncoder.h>

//Inicializa o LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Pinos de ligacao do encoder
RotaryEncoder encoder(A2, A3);

int contador = 1;
int contador_anterior = 1;
int valor = 0;


byte Bloco_Cheio[8]  = {0b11111, 0b11111, 0b11111, 0b11111,
                        0b11111, 0b11111, 0b11111, 0b11111
                       };
byte Um_invertido[8] = {0b11011, 0b10011, 0b11011, 0b11011,
                        0b11011, 0b11011, 0b10001, 0b11111
                       };
byte Dois_invertido[8] = {0b10001, 0b01110, 0b11110, 0b11101,
                          0b11011, 0b10111, 0b00000, 0b11111
                         };
byte Tres_invertido[8] =  {0b00000, 0b11101, 0b11011, 0b11101,
                           0b11110, 0b01110, 0b10001, 0b11111
                          };
byte Quatro_invertido[8] = {0b11101, 0b11001, 0b10101, 0b01101,
                            0b00000, 0b11101, 0b11101, 0b11111
                           };
byte Cinco_invertido[8] = {0b00000, 0b01111, 0b00001, 0b11110,
                           0b11110, 0b01110, 0b10001, 0b11111
                          };
byte Seis_invertido[8] = {0b11001, 0b10111, 0b01111, 0b00001,
                          0b01110, 0b01110, 0b10001, 0b11111
                         };

static int pos = 1;
int newPos = 0;
int selecionado = 0;

void setup()
{
  Serial.begin(9600);
  //Inicializa o botao do encoder no pino 7
  pinMode(7, INPUT);
  //Define o LCD com 20 colunas e 4 linhas
  lcd.begin(20, 4);
  //Cria os caracteres customizados
  lcd.createChar(0, Bloco_Cheio);
  lcd.createChar(1, Um_invertido);
  lcd.createChar(2, Dois_invertido);
  lcd.createChar(3, Tres_invertido);
  lcd.createChar(4, Quatro_invertido);
  lcd.createChar(5, Cinco_invertido);
  lcd.createChar(6, Seis_invertido);

  //Informacoes iniciais
  lcd.setCursor(0, 0);
  lcd.print("  1  2  3  4  5  6");
  lcd.setCursor(1, 2);
  lcd.print("Valor atual: 0");
  lcd.setCursor(1, 3);
  lcd.print("Selecionado: -");
}

void loop()
{
  //Verifica se o botao do encoder foi pressionado
  valor = digitalRead(7);
  Serial.println(valor);
  if (valor != 1)
  {
    Serial.println("Botao pressionado");
    lcd.setCursor(14, 3);
    selecionado = newPos;
    lcd.print(selecionado);
    //while (digitalRead(7) == 1)
    //  delay(10);
  }

  //Le as informacoes do encoder
  encoder.tick();
  newPos = encoder.getPosition();
  if (pos != newPos)
  {
    //Limite maximo menu
    if (newPos > 6)
    {
      encoder.setPosition(6);
      newPos = 6;
    }
    //Limite minimo menu
    if (newPos < 1)
    {
      encoder.setPosition(1);
      newPos = 1;
    }
    Serial.print("Posicao: ");
    Serial.println(newPos);
    //Atualiza o menu no display
    destaque_selecionado(newPos);
    pos = newPos;
  }
}

void destaque_selecionado(int conta)
{
  //Define posicao inicial
  int posicao = (conta * 3) - 1;
  //Apaga selecao anterior
  if (conta > pos)
  {
    lcd.setCursor(posicao - 4, 0);
    lcd.print(" ");
    lcd.print(conta - 1);
    lcd.print(" ");
  }
  //Apaga selecao posterior
  if (conta < pos)
  {
    lcd.setCursor(posicao + 2, 0);
    lcd.print(" ");
    lcd.print(conta + 1);
    lcd.print(" ");
  }

  //Imprime blocos cheios
  lcd.setCursor(posicao - 1, 0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)0);

  //imprime valor
  lcd.setCursor(posicao, 0);
  lcd.write((uint8_t)(conta));

  //Imprime Opcao atual
  lcd.setCursor(14, 2);
  lcd.print(conta);
}
