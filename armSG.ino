#include <Servo.h>
Servo servoBase; 
#include <ResponsiveAnalogRead.h>
const int ANALOG_PIN_BASE = A0;
ResponsiveAnalogRead analogbase(ANALOG_PIN_BASE, true);
// define the pin you want to use
void setup()
{
  // Anexa o Servo ao Pin5
  servoBase.attach(5); 
  Serial.begin(9600);
}
 
void loop()
{
  analogbase.update();
  // Lê o valor do Potenciometro
  //int angleBase = analogRead(0); 
  //int angleBaseConvertido=map(angleBase, 0, 1023, 0, 180);
  int anguloFiltrado = analogbase.getValue();
  int angleBaseFiltradoConvertido=map(anguloFiltrado, 0, 1023, 0, 180);
  
//  Serial.print(angleBase);
 // Serial.print("\t");
  //Serial.println(anguloFiltrado);
  servoBase.write(angleBaseFiltradoConvertido); 
  delay(60);
}
