#include <Servo.h>
Servo servoBase; 
 
void setup()
{
  // Anexa o Servo ao Pin5
  servoBase.attach(5); 
  Serial.begin(9600);
}
 
void loop()
{
  // Lê o valor do Potenciometro
  int angle = analogRead(0); 
  // Mapeia o valor de 0 a 180 graus
  angle=map(angle, 0, 1023, 0, 180);
  Serial.println(angle);
  // Repassa o angulo ao ServoWrite
  servoBase.write(angle); 
  // Delay de 15ms para o Servo alcançar a posição
  delay(15);
}
