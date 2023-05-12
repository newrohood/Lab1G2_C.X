#include <xc.h>
#pragma config WDT=OFF
#pragma config FOSC=INTOSC_EC
//Fosc>=100KHz
unsigned char Conversion(void);
void main(void){
  unsigned char a;
  TRISA0=1;
  ADCON0=0b00000001;
  ADCON1=0b00001110;
  ADCON2=0b00001000;
  while(1){
    a=Conversion();  
  }  
}
unsigned char Conversion(void){
  GO=1;
  while(GO==1);
  return ADRESH;  
}