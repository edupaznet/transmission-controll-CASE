
#include "definition.h"

void setup()
 {

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
  flag1=flag2=flag3=flag4=0;
  prevValorNeutral= digitalRead(Neutral);

 }

void loop() 
  
  { 
  unsigned long currentMillis = millis();
  valorFwd = digitalRead(Fwd);    // cable Fordward de la palanca 
  valorRev = digitalRead(Rev);    // cable Reverse de la palanca
  valorC1 = digitalRead(wireC1);  // proviene del cable C de la palanca
  valorB1 = digitalRead(wireB1);  // proviene del cable B de la palanca
  valorNeutral = digitalRead(Neutral); // cable neutro de la palanca


if (valorNeutral != prevValorNeutral) {
                  shifterMoveMillis = currentMillis;
                  prevValorNeutral = valorNeutral;    
                  M6Ready = true;
                   }
  
  if (M6Ready) {
              digitalWrite(M6, LOW);
                       if ((unsigned long)(currentMillis - shifterMoveMillis) >= turnOnDelay) {
                                       digitalWrite(M6, HIGH);
                                       M6State = true;
                                       M6TurnedOnAt = currentMillis;
                                       M6Ready = false;
                            }
               }
  

  
 
  if (valorNeutral == 0 && valorFwd == 1 && valorRev == 1)
            {  
        
              fNeutral(valorB1,valorC1);
             
                       
            }
            else {
                  if (valorFwd == 0 ){

                           fFwd (valorB1, valorC1);
                            
                                    } else { 
                                              fRev (valorB1, valorC1);
                                                    
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
                                                                                      flag3=1;
                                                                                      delay(1000);
                                                                                      digitalWrite(M6,flag3);
                                                                                    }
                                                         }  
                     
                             }
   

}
            

//*************************************************************************************************  

       
