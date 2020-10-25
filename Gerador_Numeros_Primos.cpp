/*
Gerador de Numeros Primos
GPL
*/

#include<stdio.h>

int main()
{
  int Primo=0,aux=0,ind=0,resto=0;

 for(;;)
 {
 Primo++;
 ind = Primo;
 do{ 
 resto = Primo%ind;
 if(resto == 0)
 {
 aux++;
 }
 
 ind--;
   }while(ind != 0);
 
 if(aux == 2)
 {
 printf("Numero Primo: %d\n",Primo);
 }
 aux = 0;
 }
}
