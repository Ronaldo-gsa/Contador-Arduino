int trig = 7;
int echo = 6;
int buzzer = 8;

int tempo = 0;
int distancia = 0;

int pessoas = 0; 
int tempo_ant=0;

bool fechada=true;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(10);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  tempo = pulseIn(echo, HIGH);
  distancia = tempo/58.2;
  if (distancia < 0)
     distancia = 0;

  if (distancia < 20){
    digitalWrite(buzzer, HIGH);

    if (fechada){
      fechada = false;
      pessoas++;
    }
  }else{
    digitalWrite(buzzer, LOW);
    if (!fechada){
      fechada = true;
    }
  }
  delay(100);
  


// if (distancia < 10){
//   tempo_ant = millis();
// }
  //Serial.println(millis());
  //Serial.println(tempo_ant);
  Serial.print("Pessoas: ");
  Serial.println(pessoas);
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  Serial.println("-----------");

  // Serial.print("Tempo: ");
  // Serial.print(tempo);
  // Serial.println(" s");
  // Serial.print(distancia);
  // Serial.println(" cm");
  // Serial.println("--------------");

}
