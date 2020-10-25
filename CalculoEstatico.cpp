#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
/*
Author: Micael Pinto
NameProgram: CalculosEstatistico
Create: 02/11/2011
*/
int main()
{
    int QtDados=0,Indice=0;
    printf("XXX ------ Variancia Amostral ------ XXX\n\n");
    printf("Insira a Quantidade de Dados: ");
    scanf("%d",&QtDados);
    system("cls");
    Indice = 0;
    float *Dados;
    Dados = (float*)(malloc(QtDados*sizeof(float)));
    do{
        printf("------------------------------------------------\n");
        printf("Favor Inserir %d° Dado: ",Indice);
        scanf("%f",&Dados[Indice]);
        Indice++;
       }while(Indice != QtDados);
    Indice = 0;
    float Somatoria=0;
    do{
        Somatoria += Dados[Indice];
        Indice++;
      }while(Indice != QtDados);
    float MediaAritimetica;
    MediaAritimetica = Somatoria/QtDados;
    printf("\n\n");
    printf("------------------------------------------------\n");
    printf("Media Aritimetica: %.2f \n",MediaAritimetica);
    printf("------------------------------------------------\n");
    printf("\n\n");
    float *SomatoriaVariancia;
    SomatoriaVariancia = (float*)(malloc(QtDados*sizeof(float)));
    Indice = 0;
    do{
        SomatoriaVariancia[Indice] = (Dados[Indice] - MediaAritimetica);
        printf("Soma %d:| %.2f - %.2f = %.2f",Indice,Dados[Indice],MediaAritimetica,SomatoriaVariancia[Indice]);
        SomatoriaVariancia[Indice] = pow(SomatoriaVariancia[Indice],2);
        printf("= %.2f \n",SomatoriaVariancia[Indice]);
        Indice++;
      }while(Indice != QtDados);
    Indice = 0;
    float SomatoriaVarianciaFinal=0;
    do{
        SomatoriaVarianciaFinal += SomatoriaVariancia[Indice];
        Indice++;
      }while(Indice != QtDados);
    printf("------------------------------------------------\n");
    printf("Somatoria Variancia Final:%.2f \n",SomatoriaVarianciaFinal);
    printf("------------------------------------------------\n");
    float VarianciaAmostral = (SomatoriaVarianciaFinal)/(QtDados-1);
    printf("------------------------------------------------\n");
    printf("Variancia Amostral: %.2f \n",VarianciaAmostral);
    printf("------------------------------------------------\n");
    float DesvioPadraoAmostral;
    DesvioPadraoAmostral = sqrt(VarianciaAmostral);
    printf("------------------------------------------------\n");
    printf("Desvio Padrao: %.2f \n",DesvioPadraoAmostral);
    printf("------------------------------------------------\n");
    float ErroPadraoMedia;
    ErroPadraoMedia = DesvioPadraoAmostral/(sqrt(QtDados));
    printf("------------------------------------------------\n");
    printf("Erro Padrao Media: %.2f \n",ErroPadraoMedia);
    printf("------------------------------------------------\n");
    float CoeficienteVariacao;
    CoeficienteVariacao = (DesvioPadraoAmostral/MediaAritimetica)*100;
    printf("------------------------------------------------\n");
    printf("Coeficiente de Variacao: %.2f \n",CoeficienteVariacao);
    printf("------------------------------------------------\n");
    free(Dados);
    free(SomatoriaVariancia);
    return 0;
}
