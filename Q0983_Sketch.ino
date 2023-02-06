/*  
*  AUTOR:    BrincandoComIdeias
*  APRENDA:  https://cursodearduino.net/
*  SKETCH:   Controle Motor por LDR
*  DATA:     30/01/23
*/

// DEFINIÇÕES DE PINOS
#define pinLdr A0
#define pinAbrir 9
#define pinFechar 10

// DEFINIÇÕES
#define tempo 3000
#define luzAbrir 800
#define luzFechar 500

#define ABERTA true
#define FECHADA false

// VARIÁVEIS GLOBAIS
bool persiana = FECHADA;

void setup() {
  Serial.begin(9600);

  // CONFIGURAÇÃO DOS PINOS
  pinMode(pinLdr, INPUT);

  pinMode(pinAbrir, OUTPUT);
  pinMode(pinFechar, OUTPUT);

  // CONFIRMA O MOTOR PARADO
  digitalWrite(pinAbrir, LOW);
  digitalWrite(pinFechar, LOW);

  Serial.println("Fim do setup();");
}

void loop() {
  // LEITURA DO SENSOR
  int leitura = analogRead(pinLdr);

  // INVERTE A LÓGICA DO SENSOR ANALÓGICO 
  leitura = map(leitura, 0 , 1023, 1023, 0); 

  // EXIBE O VALOR DA LEITURA NO MONITOR SERIAL
  //Serial.println(leitura);

  if (persiana == FECHADA) {
    if (leitura > luzAbrir) {
      Serial.println("Abrindo");

      analogWrite(pinAbrir, 120);
      digitalWrite(pinFechar, LOW);
      delay(tempo);

      digitalWrite(pinAbrir, LOW);
      digitalWrite(pinFechar, LOW);
      delay(tempo);

      persiana = ABERTA;
    }
  }

  if (persiana == ABERTA) {
    if (leitura < luzFechar) {
      Serial.println("Fechando");

      digitalWrite(pinAbrir, LOW);
      analogWrite(pinFechar, 120);
      delay(tempo);

      digitalWrite(pinAbrir, LOW);
      digitalWrite(pinFechar, LOW);
      delay(tempo);

      persiana = FECHADA;
    }
  }
}