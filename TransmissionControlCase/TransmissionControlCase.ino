
#include "definition.h"

/*//*******************************************************
// Pin declarations
//********************************************************
const byte Neutral = 12;
const byte Fwd = 11;
const byte Rev = 10;
const byte M6 = 9;
const byte M5 = 8;
const byte M4 = 13;
const byte M3 = 6;
const byte M2 = 5;
const byte M1 = 4;
const byte wireC1 = 3;
const byte wireB1 = 2;

//*****************************************************
// Global Variables
//*****************************************************
int valorNeutral,valorFwd, valorRev, valorC1,valorB1;
bool flag1,flag2,flag3,flag4;
//unsigned long delayTime = 1000; // Interval in M6 delay
//unsigned long startTime ;
//************************************************************  
*/
void setup()
 {

  //startTime=millis();
  pinMode(Neutral,INPUT);
  pinMode(Fwd,INPUT);
  pinMode(Rev,INPUT);
  pinMode(wireC1,INPUT);
  pinMode(wireB1,INPUT);
  pinMode(M1,OUTPUT);    //
  pinMode(M2,OUTPUT);    //
  pinMode(M3,OUTPUT);    //
  pinMode(M4,OUTPUT);    //   SOLENOIDES M1-M5 gears (marchas)
  pinMode(M5,OUTPUT);    //   M6 embrague
  pinMode(M6,OUTPUT);    //
  Serial.begin(9600);
  flag1=flag2=flag3=flag4=0;

 }

void loop() 
  
  { 
  valorFwd = digitalRead(Fwd);    // cable Fordward de la palanca 
  valorRev = digitalRead(Rev);    // cable Reverse de la palanca
  valorC1 = digitalRead(wireC1);  // proviene del cable C de la palanca
  valorB1 = digitalRead(wireB1);  // proviene del cable B de la palanca
  valorNeutral = digitalRead(Neutral); // cable neutro de la palanca
 
  if (valorNeutral == 0 && valorFwd == 1 && valorRev == 1)
       {  
        
              fNeutral(valorB1,valorC1);
               // Serial.println("Neutral----");

                       
            }
            else {
                  if (valorFwd == 0 ){

                           fFwd (valorB1, valorC1);
                           //Serial.println("Fwd-->>");
                                    } else { 
                                              fRev (valorB1, valorC1);
                                               //  Serial.println("Rev<<--");
                                           }
                } 

  }
//**************************************************************************************************
//   funcion Neutral
//**************************************************************************************************

   void fNeutral (int bitMSB, int bitLSB) 
{
     if (bitLSB == LOW ){ 
  
         if (bitMSB == HIGH ){

       
                               digitalWrite(M1,LOW);
                               digitalWrite(M2,LOW);
                               digitalWrite(M3,LOW);
                               digitalWrite(M4,LOW);
                               digitalWrite(M5,LOW);
                               digitalWrite(M2,HIGH);   // detecta que esta puesta la 1°
                               digitalWrite(M4,HIGH);
                               flag2=flag3=flag4=0;
                               if (flag1== 0){
                                              digitalWrite(M6,LOW);
                                              Serial.print(flag1);
                                              Serial.println("1°Gear");
                                              flag1=1;
                                              delay(1000);
                                              digitalWrite(M6,flag1);
                                             } 
                               
                              } else
                                     {
                                          
                                         digitalWrite(M1,LOW);
                                         digitalWrite(M2,LOW);
                                         digitalWrite(M3,LOW);    // detecta que esta puesta la 4°
                                         digitalWrite(M4,LOW);
                                         digitalWrite(M5,LOW);
                                         flag2=flag3=flag1=0;
                                         if(flag4==0){ 
                                                       digitalWrite(M6,LOW);
                                                       Serial.print(flag4);
                                                       Serial.println("4°Gear");
                                                       flag4=1;
                                                       delay(1000);
                                                       digitalWrite(M6,flag4);
                                                      
                                                     }
                                     
                                      }
                       }else {   
                               if (bitMSB == HIGH){
                                                   
                                                    
                                                    digitalWrite(M1,LOW);
                                                    digitalWrite(M2,LOW);
                                                    digitalWrite(M3,LOW);    // detecta que esta puesta la 2°
                                                    digitalWrite(M4,LOW);
                                                    digitalWrite(M5,LOW);
                                                    digitalWrite(M4,HIGH);
                                                    flag4=flag3=flag1=0;
                                                    if(flag2==0){ 
                                                                  digitalWrite(M6,LOW); 
                                                                  Serial.print(flag2);
                                                                  Serial.println("2°Gear");
                                                                  flag2=1;
                                                                  delay(1000);
                                                                  digitalWrite(M6,flag2);
                                                                 
                                                                }                                                    
                
                                                 }else {
                                                           
                                                           digitalWrite(M1,LOW);
                                                           digitalWrite(M2,LOW);
                                                           digitalWrite(M3,LOW);    // detecta que esta puesta la 3°
                                                           digitalWrite(M4,LOW);
                                                           digitalWrite(M5,LOW);
                                                           flag2=flag4=flag1=0;
                                                           if(flag3==0){
                                                                          digitalWrite(M6,LOW);
                                                                          Serial.print(flag3);
                                                                          Serial.println("3°Gear");
                                                                          flag3=1;
                                                                          delay(1000);
                                                                          digitalWrite(M6,flag3);
                                                                       }
                                                           
                                                       }
                            }
   

}
            

//*************************************************************************************************    
//   Funcion Forward
//*************************************************************************************************

   void fFwd (int bitMSB, int bitLSB) 

{
     if (bitLSB == LOW ){ 

          if (bitMSB == HIGH ){

                                   digitalWrite(M1,LOW);
                                   digitalWrite(M2,LOW);
                                   digitalWrite(M3,LOW);
                                   digitalWrite(M4,LOW);
                                   digitalWrite(M5,LOW);
                                   digitalWrite(M2,HIGH);   // detecta que esta puesta la 1°
                                   digitalWrite(M3,HIGH);
                                   digitalWrite(M4,HIGH);
                                   flag2=flag3=flag4=0;
                                   if (flag1== 0){
                                                   digitalWrite(M6,LOW);
                                                   Serial.print(flag1);
                                                   Serial.println("1°Gear");
                                                   flag1=1;
                                                   delay(1000);
                                                   digitalWrite(M6,flag1);
                                                } 
                                 
                              }else{
                                         digitalWrite(M1,LOW);
                                         digitalWrite(M2,LOW);
                                         digitalWrite(M3,LOW);    // detecta que esta puesta la 4°
                                         digitalWrite(M4,LOW);
                                         digitalWrite(M5,HIGH);
                                         flag2=flag3=flag1=0;
                                              if(flag4==0){ 
                                                            digitalWrite(M6,LOW);
                                                            Serial.print(flag4);
                                                            Serial.println("4°Gear");
                                                            flag4=1;
                                                            delay(1000);
                                                            digitalWrite(M6,flag4);
                                                         }
                                     }                     
                        }else{   
                                 if (bitMSB == HIGH){
                                                      digitalWrite(M1,LOW);
                                                      digitalWrite(M2,LOW);
                                                      digitalWrite(M3,LOW);    // detecta que esta puesta la 2°
                                                      digitalWrite(M4,LOW);
                                                      digitalWrite(M5,LOW);
                                                      digitalWrite(M3,HIGH);
                                                      digitalWrite(M4,HIGH);
                                                      flag4=flag3=flag1=0;
                                                      if(flag2==0){ 
                                                                    digitalWrite(M6,LOW); 
                                                                    Serial.print(flag2);
                                                                    Serial.println("2°Gear");
                                                                    flag2=1;
                                                                    delay(1000);
                                                                    digitalWrite(M6,flag2);
                                                                 }                            
                
                                                   }else {
                                                            digitalWrite(M1,LOW);
                                                            digitalWrite(M2,LOW);
                                                            digitalWrite(M3,LOW);    // detecta que esta puesta la 3°
                                                            digitalWrite(M4,LOW);
                                                            digitalWrite(M5,LOW);
                                                            digitalWrite(M3,HIGH);
                                                            flag2=flag4=flag1=0;
                                                                  if(flag3==0){
                                                                                digitalWrite(M6,LOW);
                                                                                Serial.print(flag3);
                                                                                Serial.println("3°Gear");
                                                                                flag3=1;
                                                                                delay(1000);
                                                                                digitalWrite(M6,flag3);
                                                                              }
                                                         
                                                        }
                     
                              }
   

  
  }
            

//*************************************************************************************************         
// Funcion Reverse
//*************************************************************************************************

   void fRev (int bitMSB, int bitLSB) 
{
     if (bitLSB == LOW ){ 
  
         if (bitMSB == HIGH ){
                               digitalWrite(M1,LOW);
                               digitalWrite(M2,LOW);
                               digitalWrite(M3,LOW);
                               digitalWrite(M4,LOW);
                               digitalWrite(M5,LOW);
                               digitalWrite(M1,HIGH);
                               digitalWrite(M3,HIGH);   // detecta que esta puesta la 1°
                               digitalWrite(M4,HIGH);
                               flag2=flag3=flag4=0;
                                      if (flag1== 0){
                                              digitalWrite(M6,LOW);
                                              Serial.print(flag1);
                                              Serial.println("1°Gear");
                                              flag1=1;
                                              delay(1000);
                                              digitalWrite(M6,flag1);
                                                    } 
                             

                            }else
                                  {
                                      digitalWrite(M1,LOW);
                                      digitalWrite(M2,LOW);
                                      digitalWrite(M3,LOW);    // detecta que esta puesta la 4°
                                      digitalWrite(M4,LOW);
                                      digitalWrite(M5,LOW);
                                      digitalWrite(M1,HIGH);
                                      flag2=flag3=flag1=0;
                                           if(flag4==0){ 
                                                       digitalWrite(M6,LOW);
                                                       Serial.print(flag4);
                                                       Serial.println("4°Gear");
                                                       flag4=1;
                                                       delay(1000);
                                                       digitalWrite(M6,flag4);
                                                       }
                                  }                      
                       }else {   
                               if (bitMSB == HIGH){
                                                     digitalWrite(M1,LOW);
                                                     digitalWrite(M2,LOW);
                                                     digitalWrite(M3,LOW);    // detecta que esta puesta la 2°
                                                     digitalWrite(M4,LOW);
                                                     digitalWrite(M5,LOW);
                                                     digitalWrite(M1,HIGH);
                                                     digitalWrite(M4,HIGH);
                                                     flag4=flag3=flag1=0;
                                                         if(flag2==0){ 
                                                                       digitalWrite(M6,LOW); 
                                                                       Serial.print(flag2);
                                                                       Serial.println("2°Gear");
                                                                       flag2=1;
                                                                       delay(1000);
                                                                       digitalWrite(M6,flag2);
                                                                     }                            
                
                                                  }else {
                                                            digitalWrite(M1,LOW);
                                                            digitalWrite(M2,LOW);
                                                            digitalWrite(M3,LOW);    // detecta que esta puesta la 3°
                                                            digitalWrite(M4,LOW);
                                                            digitalWrite(M5,LOW);
                                                            digitalWrite(M1,HIGH);
                                                            flag2=flag4=flag1=0;
                                                                        if(flag3==0){
                                                                                      digitalWrite(M6,LOW);
                                                                                      Serial.print(flag3);
                                                                                      Serial.println("3°Gear");
                                                                                      flag3=1;
                                                                                      delay(1000);
                                                                                      digitalWrite(M6,flag3);
                                                                                    }
                                                         }  
                     
                             }
   

}
            

//*************************************************************************************************  

//************************************************************************************************
// Funcion delayM6()
//************************************************************************************************
//void delayM6(){
//  if (( millis()- startTime ) >= delayTime ){
//           startTime= millis();
//           digitalWrite(M6,HIGH);
//           Serial.println("delayM6...");
//               }
//  }
       
