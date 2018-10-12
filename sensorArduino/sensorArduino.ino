#include <CapacitiveSensor.h>
#include <Keyboard.h>

//Crear e indicar pines del sensor
//4 -> Sender 3 -> Receiver
//int led1 = 13;
//int led2 = 10;
//int led3 = 8;
CapacitiveSensor   sensor1 = CapacitiveSensor(1,0);
CapacitiveSensor   sensor2 = CapacitiveSensor(3,2);
CapacitiveSensor   sensor3 = CapacitiveSensor(5,4);
CapacitiveSensor   sensor4 = CapacitiveSensor(7,6);
CapacitiveSensor   sensor5 = CapacitiveSensor(9,8);
CapacitiveSensor   sensor6 = CapacitiveSensor(11,10);
CapacitiveSensor   sensor7 = CapacitiveSensor(13,12);
/*CapacitiveSensor   sensor8 = CapacitiveSensor(2,0);
CapacitiveSensor   sensor9 = CapacitiveSensor(2,11);
*/
void setup()                    
{
  Keyboard.begin();  
  Serial.begin(9600);
  //pinMode(led1,OUTPUT); //LED
  //pinMode(led2,OUTPUT);
  //pinMode(led3,OUTPUT);
}

void loop()                    
{
    //Almacenar lectura del sensor en una variable
    long lectura1 =  sensor1.capacitiveSensor(30);
    long lectura2 =  sensor2.capacitiveSensor(30);  
    long lectura3 =  sensor3.capacitiveSensor(30);
    long lectura4 =  sensor4.capacitiveSensor(30);
    long lectura5 =  sensor5.capacitiveSensor(30);
    long lectura6 =  sensor6.capacitiveSensor(30);
    long lectura7 =  sensor7.capacitiveSensor(30);
    /*long lectura8 =  sensor8.capacitiveSensor(30);
    long lectura9 =  sensor9.capacitiveSensor(30);
    */
    Serial.print(lectura1);
    Serial.print("\n");

    
    if(lectura1 > 30){
      Keyboard.press(49);
      //digitalWrite(led1,HIGH);
    }else{
      Keyboard.releaseAll();
      //digitalWrite(led1,LOW);
    }

    
    if(lectura2 > 30){
      Keyboard.press(50);
    }else{
      Keyboard.releaseAll();
    }

    
    if(lectura3 > 30){
      Keyboard.press(51);
    }else{
      Keyboard.releaseAll();
    }

    
    if(lectura4 > 100){
      Keyboard.press(52);
    }else{
      Keyboard.releaseAll();
    }

    
    if(lectura5 > 30){
      Keyboard.press(53);
    }else{
      Keyboard.releaseAll();
    }

    
    if(lectura6 > 70){
      Keyboard.press(54);
    }else{
      Keyboard.releaseAll();
    }


    if(lectura7 > 30){
      Keyboard.press(55);
    }else{
      Keyboard.releaseAll();
    }

/*
    if(lectura8 > 100){
      Keyboard.press(56);
      delay(100);
    }else{
      Keyboard.releaseAll();
    }


    if(lectura9 > 100){
      Keyboard.press(57);
      delay(100);
    }else{
      Keyboard.releaseAll();
    }
    */

    delay(10);                       
}
