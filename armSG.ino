#include <Servo.h>
Servo servoBase; 
Servo servoEsquerda;
Servo servoDireita;
Servo servoGarra; 
#include <ResponsiveAnalogRead.h>
const int ANALOG_PIN_BASE = A0;
const int ANALOG_PIN_ESQUERDA = A1;
const int ANALOG_PIN_DIREITA = A4;
const int ANALOG_PIN_GARRA = A3;
ResponsiveAnalogRead analogBase(ANALOG_PIN_BASE, true);
ResponsiveAnalogRead analogEsquerda(ANALOG_PIN_ESQUERDA, true);
ResponsiveAnalogRead analogDireita(ANALOG_PIN_DIREITA, true);
ResponsiveAnalogRead analogGarra(ANALOG_PIN_GARRA, true);
// define the pin you want to use
void setup()
{
  // Anexa o Servo ao Pin5
  servoBase.attach(5); 
  servoEsquerda.attach(6); 
  servoDireita.attach(9); 
  servoGarra.attach(10); 
  Serial.begin(9600);
}
 
void loop()
{
  analogBase.update();
  analogEsquerda.update();
  analogDireita.update();
  analogGarra.update();
  // Lê o valor do Potenciometro
  int angleBase = analogRead(3); 
  //int angleBaseConvertido=map(angleBase, 0, 1023, 0, 180);
  
  //Angulos Servo Base
  int anguloFiltradoBase = analogBase.getValue();
  int angleBaseFiltradoConvertido=map(anguloFiltradoBase, 0, 1023, 0, 180);
  
  // Angulos Servo Esquerda
  int anguloFiltradoEsquerda = analogEsquerda.getValue();
  int angleEsquerdaFiltradoConvertido=map(anguloFiltradoEsquerda, 0, 1023, 0, 180);
  
  // Angulos Servo Direita
  int anguloFiltradoDireita = analogDireita.getValue();
  int angleDireitaFiltradoConvertido=map(anguloFiltradoDireita, 0, 1023, 0, 180);
  
  // Angulos Servo Garra
  int anguloFiltradoGarra = analogGarra.getValue();
  int angleGarraFiltradoConvertido=map(anguloFiltradoGarra, 0, 1023, 0, 180);
  //Serial.println(angleGarraFiltradoConvertido);
  // PLOTTER SERIAL PARA VER OS RUIDOS
  Serial.print(angleBase);
  Serial.print("\t");
  Serial.println(anguloFiltradoGarra);
  
  servoBase.write(angleBaseFiltradoConvertido); 
  servoEsquerda.write(angleEsquerdaFiltradoConvertido);
  servoDireita.write(angleDireitaFiltradoConvertido);
  servoGarra.write(angleGarraFiltradoConvertido);
  delay(60);
}
