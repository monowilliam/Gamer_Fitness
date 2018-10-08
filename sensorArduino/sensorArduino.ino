#include <CapacitiveSensor.h>
 
//Crear e indicar pines del sensor
//4 -> Sender 3 -> Receiver
CapacitiveSensor   sensor = CapacitiveSensor(4,3);
 
void setup()                    
{
 Serial.begin(9600);
}
 
void loop()                    
{
    //Almacenar lectura del sensor en una variable
    long lectura =  sensor.capacitiveSensor(30);
 
    //Comparar lectura
    Serial.print(lectura);
    Serial.print("\n");
    /*
    if(lectura > 1)
      digitalWrite(12,HIGH);
     else
      digitalWrite(12,LOW); 
   */
    delay(10);                       
}
