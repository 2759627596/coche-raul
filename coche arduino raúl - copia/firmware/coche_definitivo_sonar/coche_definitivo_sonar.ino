#include <NewPing.h>
NewPing sonar(3,4); 
int distancia;
char dato;
int elegir;

void setup() {
  //DIRECCIONES RUEDA DERECHA
 pinMode(12,OUTPUT);
 pinMode(7,OUTPUT);
  //DIRECCIONES RUEDA IZQUIERDA
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);

 Serial.begin(9600);
}

void loop() {
 if (Serial.available()>0){
  dato=Serial.read();
  Serial.print(dato);
  switch(dato){
    case('W'):{
      elegir=0;
      break;
    }
    case('w'):{
      elegir=1;
      break;
    }
  }
  if(elegir==0){//programa evitaobstaculos
     distancia=sonar.ping_cm();
  Serial.println(distancia);
      if(sonar.ping_cm()>=30){
        analogWrite(10,250);
        digitalWrite(7,1);
        digitalWrite(12,0);  
        //MOTOR 2 
        analogWrite(11,250);
        digitalWrite(8,0);
        digitalWrite(9,1);
        delay(20);
        Serial.println(sonar.ping_cm());
       
   }
       if(sonar.ping_cm()<30){
        analogWrite(10,255);
        digitalWrite(7,1);
        digitalWrite(12,0);  
        //MOTOR 2 
        analogWrite(11,250);
        digitalWrite(8,1);
        digitalWrite(9,0);
        delay(400);
         Serial.println(sonar.ping_cm());
   }
    
  }
  if(elegir==1){
  
   switch(dato){

    case('S'):{ //COCHE PARADO
     //motor derecha
     analogWrite(10,0);
     digitalWrite(7,0);
     digitalWrite(12,0);
    //motor izquierda
     analogWrite(11,0); 
     digitalWrite(8,0);
     digitalWrite(9,0);
      break;
    }
 
   case('F'): { //MOV.ADELANTE
    //motor derecha 
     analogWrite(10,255);
     digitalWrite(7,1);
     digitalWrite(12,0);
    //motor izquierda
     analogWrite(11,255);
     digitalWrite(8,0);
     digitalWrite(9,1);
     break;
   }
   
 
   case('I'): { //MOV.ADELANTE IZQUIERDA
    //motor derecha 
     analogWrite(10,255);
     digitalWrite(7,1);
     digitalWrite(12,0);
    //motor izquierda
     analogWrite(11,170);
     digitalWrite(8,0);
     digitalWrite(9,1);
     break;
   }
   
   case('G'): { //MOV.ADELANTE DERECHA
    //motor derecha 
     analogWrite(10,170);
     digitalWrite(7,1);
     digitalWrite(12,0);
    //motor izquierda
     analogWrite(11,255);
     digitalWrite(8,0);
     digitalWrite(9,1);
     break;
   }

   case('B'): { //MOV.ATRAS 
    //motor derecha 
     analogWrite(10,255);
     digitalWrite(7,0);
     digitalWrite(12,1);
    //motor izquierda 
     analogWrite(11,255);
     digitalWrite(8,1);
     digitalWrite(9,0);
     break;
   }
   
   case('J'): { //MOV.ATRAS IZQUIERDA
    //motor derecha 
     analogWrite(10,255);
     digitalWrite(7,0);
     digitalWrite(12,1);
    //motor izquierda 
     analogWrite(11,170);
     digitalWrite(8,1);
     digitalWrite(9,0);
     break;
   }

   case('H'): { //MOV.ATRAS DERECHA
    //motor derecha 
     analogWrite(10,170);
     digitalWrite(7,0);
     digitalWrite(12,1);
    //motor izquierda 
     analogWrite(11,255);
     digitalWrite(8,1);
     digitalWrite(9,0);
     break;
   }

   case('R'):{ //MOV.IZQUIERDA
    //motor derecha
     analogWrite(10,210);
     digitalWrite(7,1);
     digitalWrite(12,0); 
    //motor izquierda
     analogWrite(11,100);
     digitalWrite(8,0);
     digitalWrite(9,0);
     break;
   }

    case('L'):{ //MOV.DERECHA
     //motor derecha 
      analogWrite(10,100);
      digitalWrite(7,0);
      digitalWrite(12,0);
     //motor izquierda
      analogWrite(11,210); 
      digitalWrite(8,0);
      digitalWrite(9,1);
      break;
    }  
   
   }
 }
 }
}

