/*
Desligar Computador Automatico - hora programada
GPL
*/
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
 /*Funções*/
int main();
int presents();
char insert();
 /*Variaveis Globais*/
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[20],Horas[5];
  int ind;
int presents()
{
    printf("***************************************************\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*      DESLIGAR COMPUTADOR AUTOMATICO             *\n");
    printf("*                                                 *\n");
    printf("*      Cannabis Corporation                       *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("***************************************************\n");
    printf("Pressione qualquer teclar para continuar...");
    getch();
    system("cls");
}
char insert()
{
    printf("***************************************************\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*      DESLIGAR COMPUTADOR AUTOMATICO             *\n");
    printf("*                                                 *\n");
    printf("*      Cannabis Corporation                       *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("*                                                 *\n");
    printf("***************************************************\n");
    printf("Insira as Horas: ");
    gets(Horas);
    ind = strlen(Horas);
    do{
        if(ind == 3) ind--;
        if((Horas[ind] == 'a')||(Horas[ind] == 'A')||(Horas[ind] == 'b')||(Horas[ind] == 'B')||(Horas[ind] == 'c')||(Horas[ind] == 'C')||(Horas[ind] == 'd')||(Horas[ind] == 'D')||(Horas[ind] == 'e')||(Horas[ind] == 'E')||(Horas[ind] == 'f')||(Horas[ind] == 'F')||(Horas[ind] == 'g')||(Horas[ind] == 'G')||(Horas[ind] == 'h')||(Horas[ind] == 'H')||(Horas[ind] == 'i')||(Horas[ind] == 'I')||(Horas[ind] == 'j')||(Horas[ind] == 'J')||(Horas[ind] == 'l')||(Horas[ind] == 'L')||(Horas[ind] == 'm')||(Horas[ind] == 'M')||(Horas[ind] == 'n')||(Horas[ind] == 'N')||(Horas[ind] == 'o')||(Horas[ind] == 'O')||(Horas[ind] == 'p')||(Horas[ind] == 'P')||(Horas[ind] == 'q')||(Horas[ind] == 'Q')||(Horas[ind] == 'r')||(Horas[ind] == 'R')||(Horas[ind] == 's')||(Horas[ind] == 'S')||(Horas[ind] == 't')||(Horas[ind] == 'T')||(Horas[ind] == 'u')||(Horas[ind] == 'U')||(Horas[ind] == 'v')||(Horas[ind] == 'V')||(Horas[ind] == 'x')||(Horas[ind] == 'X')||(Horas[ind] == 'z')||(Horas[ind] == 'Z')||(Horas[ind] == 'y')||(Horas[ind] == 'Y')||(Horas[ind] == 'w')||(Horas[ind] == 'W')||(Horas[ind] == 'k')||(Horas[ind] == 'K')||(Horas[ind] == '!')||(Horas[ind] == '@')||(Horas[ind] == '#')||(Horas[ind] == '$')||(Horas[ind] == '%')||(Horas[ind] == '¨')||(Horas[ind] == '&')||(Horas[ind] == '*')||(Horas[ind] == '(')||(Horas[ind] == ')')||(Horas[ind] == '-')||(Horas[ind] == '_')||(Horas[ind] == '+')||(Horas[ind] == '=')||(Horas[ind] == '§'))
        {
                       printf("XXX- xx --ERRO-- xx Caracateres Invalidos-XXX");
                       getch();
                       system("cls");
                       insert();
        }
        ind--;
       }while(ind != -1);
}
int main ()
{
    presents();
    insert();
    puts(Horas);
for(;;)
{
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  strftime (buffer,20,"%H:%M",timeinfo);
  puts(buffer);
  system("cls");
  if((buffer[0]==Horas[0])&&(buffer[1]==Horas[1])&&(buffer[2]==Horas[2])&&(buffer[3]==Horas[3])&&(buffer[4]==Horas[4]))
  {
   system("shutdown -s -t 20 -c Ate Mais!!! ");
   break;
  }
}
  return 0;
}
