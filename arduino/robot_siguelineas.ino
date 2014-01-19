/* 
 * Renacuajobot sigue lineas
 *
 * http://zagales-hacklab.org
 *
 */

#define PIN_SENSOR_IZDA 2
#define PIN_SENSOR_DCHA 3
#define PIN_RUEDA_IZDA  4
#define PIN_RUEDA_DCHA  7


void setup() 
{
  pinMode(PIN_SENSOR_IZDA, INPUT);
  pinMode(PIN_SENSOR_DCHA, INPUT);
  pinMode(PIN_RUEDA_IZDA, OUTPUT);
  pinMode(PIN_RUEDA_DCHA, OUTPUT);
}

void loop() {
  if(sensorIzquierdo()) {
    giraDerecha();    
  } else if(sensorDerecho()) {
    giraIzquierda();
  } else {
    avanza();
  }  
}

void avanza() {
  ruedaIzdaAdelante();
  ruedaDchaAdelante();
}

void giraDerecha() {
  ruedaDchaAtras();
  ruedaIzdaAdelante();
}

void giraIzquierda() {
  ruedaIzdaAtras();
  ruedaDchaAdelante();
}


boolean sensorIzquierdo() {
  return digitalRead(PIN_SENSOR_IZDA) == HIGH;
}

boolean sensorDerecho() {
  return digitalRead(PIN_SENSOR_DCHA) == HIGH;
}

void ruedaIzdaAdelante() {
  giraRuedaDireccionHoraria(PIN_RUEDA_IZDA);
}

void ruedaIzdaAtras() {
  giraRuedaDireccionAntiHoraria(PIN_RUEDA_IZDA);
}  

void ruedaDchaAdelante() {
  giraRuedaDireccionAntiHoraria(PIN_RUEDA_DCHA);
}

void ruedaDchaAtras() {
  giraRuedaDireccionHoraria(PIN_RUEDA_DCHA);
}  

void giraRuedaDireccionHoraria(int pinNumber) {
  giraRueda(pinNumber, 1000);
}

void giraRuedaDireccionAntiHoraria(int pinNumber) {
  giraRueda(pinNumber, 2000);
}

void giraRueda(int pinNumber, int pulseWidth)
{
  long initialPulseTime = micros();
  digitalWrite(pinNumber, HIGH);

  while (micros() < pulseWidth + initialPulseTime) {}
  digitalWrite(pinNumber, LOW);
}
