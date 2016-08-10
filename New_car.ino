
//Constantes Gerais
#define TEMPO 1000  //constante do tempo de espera - 1000 = 1 segundo
#define SLOW 100 //constante para andar devegar (PWM baixo)
#define FAST 170 // constante para Andar Rápido (PWM Alto)
#define POT 250 //Potencia dos Motores - Média 254 PWM = 100%


// pinos da Pnte H
#define IA1  5
#define IB1  6
#define IA2  11
#define IB2  10

int i = 0;
int time = 1000;

//piscar LED inicio
void piscarLED(void) {
  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  delay(300);
  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  delay(300);
  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  delay(300);
}

// Movimento para Frente
void andarFrente()
{
  analogWrite( IA1, POT ); // POT = speed => normal
  digitalWrite( IB1, LOW); // 10 = forward
  analogWrite( IA2, POT ); // POT = speed => normal
  digitalWrite( IB2, LOW); // 10 = forward
}

// Movimento para Tras
void andarTras()
{
  digitalWrite( IA1, LOW ); // 01 = direction => Backward
  analogWrite( IB1, POT);   // PWM speed => normal
  digitalWrite( IA2, LOW ); // 01 = direction => Backward
  analogWrite( IB2, POT);   // PWM speed => normal
}

// Movimento para Direita
void andarDireita()
{
  analogWrite( IA1, POT );  // POT = speed => normal
  digitalWrite( IB1, LOW);  // 10 = forward
  digitalWrite( IA2, SLOW); // POT = speed => devagar
  analogWrite( IB2, LOW);   // 10 = forward
}

// Movimento para Esquerda
void andarEsquerda()
{
  analogWrite( IA1, SLOW );  // POT = speed => devagar
  digitalWrite( IB1, LOW);   // 10 = forward
  digitalWrite( IA2, POT);   // POT = speed => normal
  analogWrite( IB2, LOW);    // 10 = forward
}


// Gira para Direita
void girarDireita()
{
  analogWrite( IA1, POT );  // POT = speed => normal
  digitalWrite( IB1, LOW);  // 10 = forward
  digitalWrite( IA2, LOW ); // 01 = direction => Backward
  analogWrite( IB2, POT);   // PWM speed => normal
}

// Gira para Esquerda
void girarEsquerda()
{
  digitalWrite( IA1, LOW ); // 01 = direction => Backward
  analogWrite( IB1, POT);   // PWM speed = normal
  analogWrite( IA2, POT );  // PWM speed = normal
  digitalWrite( IB2, LOW);  // 10 = forward
}


void parar()
{
  digitalWrite(IA1, LOW);
  digitalWrite(IB1, LOW);
  digitalWrite(IA2, LOW);
  digitalWrite(IB2, LOW);
}


void setup() {
  //inicia Comunicação Serial para Comunicar via Serial Monitor ou outra ferramenta
  Serial.begin(9600);

  //led
  pinMode(13, OUTPUT);

  // MOTORES - Configurar e Comecar desligado
  pinMode(IA1, OUTPUT);
  pinMode(IB1, OUTPUT);
  pinMode(IA2, OUTPUT);
  pinMode(IB2, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  digitalWrite(IA1, LOW);
  digitalWrite(IB1, LOW);
  digitalWrite(IA2, LOW);
  digitalWrite(IB2, LOW);
  i = 0;
}

void loop() {

  int ComandoFrente = analogRead(A0);
  int ComandoTras = analogRead(A1);
  int ComandoDireita = analogRead(A2);
  int ComandoEsquerda = analogRead(A3);

  Serial.println(ComandoFrente);
  Serial.print("  ");
  //Serial.print(ComandoTras); 
  //Serial.print("  ");
  delay(100);

  if (ComandoFrente >= 1000) {
     andarFrente();
  }else{

    if (ComandoTras >= 1000) {
      andarTras();
    }else{
      if (ComandoDireita >= 1000) {
        girarDireita();
      }else{
        if (ComandoEsquerda >= 1000) {
          girarEsquerda();
        }else {
          parar();
        }
      }
    }
  }




  ComandoFrente = 0;
  ComandoTras = 0;
  ComandoDireita = 0;
  ComandoEsquerda = 0;



  while (Serial.available() > 0) {
    int Comando = Serial.parseInt();
    Serial.print(Comando);
    if (Comando == 1) {
      andarFrente();
      delay(time);
      parar();
    }

    if (Comando == 2) {
      andarTras();
      delay(time);
      parar();
    }

    if (Comando == 3) {
      girarEsquerda();
      delay(time);
      parar();
    }


    if (Comando == 4) {
      girarDireita();
      delay(time);
      parar();
    }

 
  }

  /*
    if (i==0){

    Serial.println("Inicio");
    piscarLED();
    Serial.println("Frente");
    andarFrente();
    delay(TEMPO);
    Serial.println("Girar Esquerda");
    girarEsquerda();
    delay(TEMPO);
    Serial.println("Frente");
    andarFrente();
    delay(TEMPO);
    Serial.println("Girar Esquerda");
    girarEsquerda();
    delay(TEMPO);
    Serial.println("Frente");
    andarFrente();
    delay(TEMPO);
    Serial.println("Girar Esquerda");
    girarEsquerda();
    delay(TEMPO);
    Serial.println("Frente");
    andarFrente();
    delay(TEMPO);
    parar();
    i = 1;
    }
  */
}
