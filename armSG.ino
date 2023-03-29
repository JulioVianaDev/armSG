#include <Servo.h>
Servo servoBase; 
#include <ResponsiveAnalogRead.h>
const int ANALOG_PIN = A0;
ResponsiveAnalogRead analog(ANALOG_PIN, true);
// define the pin you want to use
void setup()
{
  // Anexa o Servo ao Pin5
  servoBase.attach(5); 
  Serial.begin(9600);
}
 
void loop()
{
  analog.update();
  // Lê o valor do Potenciometro
  int angleBase = analogRead(0); 
  int angleBaseConvertido=map(angleBase, 0, 1023, 0, 180);
  int anguloFiltrado = analog.getValue();
  int angleBaseFiltradoConvertido=map(angleBase, 0, 1023, 0, 180);
  
  Serial.print(anguloFiltrado);
  Serial.print("\t");
  Serial.println(angleBase);
  servoBase.write(angleBaseFiltradoConvertido); 
  delay(100);
}
