#include <CapacitiveSensor.h>
#include <Keyboard.h>

//Crear e indicar pines del sensor
//4 -> Sender 3 -> Receiver
int led1 = 13;
int led2 = 10;
int led3 = 8;
CapacitiveSensor   sensor1 = CapacitiveSensor(0,1);
CapacitiveSensor   sensor2 = CapacitiveSensor(2,3);
CapacitiveSensor   sensor3 = CapacitiveSensor(6,7);
/*CapacitiveSensor   sensor4 = CapacitiveSensor(2,6);
CapacitiveSensor   sensor5 = CapacitiveSensor(2,7);
CapacitiveSensor   sensor6 = CapacitiveSensor(2,8);
CapacitiveSensor   sensor7 = CapacitiveSensor(2,9);
CapacitiveSensor   sensor8 = CapacitiveSensor(2,10);
CapacitiveSensor   sensor9 = CapacitiveSensor(2,11);
*/
void setup()                    
{
  Keyboard.begin();  
  Serial.begin(9600);
  pinMode(led1,OUTPUT); //LED
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop()                    
{
    //Almacenar lectura del sensor en una variable
    long lectura1 =  sensor1.capacitiveSensor(30);
    long lectura2 =  sensor2.capacitiveSensor(30);  
    long lectura3 =  sensor3.capacitiveSensor(30);
    /*long lectura4 =  sensor4.capacitiveSensor(30);
    long lectura5 =  sensor5.capacitiveSensor(30);
    long lectura6 =  sensor6.capacitiveSensor(30);
    long lectura7 =  sensor7.capacitiveSensor(30);
    long lectura8 =  sensor8.capacitiveSensor(30);
    long lectura9 =  sensor9.capacitiveSensor(30);
    */
    //Serial.print(lectura3);
    //Serial.print("\n");

    
    if(lectura1 > 100){
      Keyboard.press(49);
      //delay(100);
      digitalWrite(led1,HIGH);
    }else{
      Keyboard.releaseAll();
      digitalWrite(led1,LOW);
    }
    if(lectura2 > 100){
      Keyboard.press(50);
      //delay(100);
      digitalWrite(led2,HIGH);
    }else{
      Keyboard.releaseAll();
      digitalWrite(led2,LOW);
    }

    if(lectura3 > 200){
      Keyboard.press(51);
      //delay(100);
      digitalWrite(led3,HIGH);
    }else{
      Keyboard.releaseAll();
      digitalWrite(led3,LOW);
    }
    /*
    if(lectura4 > 40){
      Keyboard.press(52);
      delay(100);
    }else{
      Keyboard.releaseAll();
    }

    if(lectura5 > 40){
      Keyboard.press(53);
      delay(100);
    }else{
      Keyboard.releaseAll();
    }
    
    if(lectura6 > 40){
      Keyboard.press(54);
      delay(100);
    }else{
      Keyboard.releaseAll();
    }

    if(lectura7 > 40){
      Keyboard.press(55);
      delay(100);
    }else{
      Keyboard.releaseAll();
    }

    if(lectura8 > 40){
      Keyboard.press(56);
      delay(100);
    }else{
      Keyboard.releaseAll();
    }

    if(lectura9 > 40){
      Keyboard.press(57);
      delay(100);
    }else{
      Keyboard.releaseAll();
    }
    */
    delay(10);                       
}
