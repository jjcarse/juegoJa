#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatenarCharACadena(char c, char *cadena);
int main()
{
    char frase[60],rep[100],temporal[100],nombreJugador[50],resultadoJuego[50],letrasIngresadas[30] = {0};
    char pal;
    int longitud,i,k,inicial,acertado=0,temp=0,intentos=9;
    int repetido=0,gano=0;
    printf("\n\n*************************************************************************************************************");
    printf("  \n\n                                       ##  JUEGO DEL AHORCADO  [0_0] ##");
    printf("\n\n*************************************************************************************************************");
              printf(" \n\n                       Dispondras de 8 intentos para tratar de adivinar la frase ");
               printf("    \n\n                                              !! Mucha suerte !!  ");
               printf("    \n\n            [ 0  0 ]                                                         [ 0  0 ]  \n\n" );
    printf("  Introduzca la palabra a adivinar: ");
    gets(frase);
    system("cls");
    longitud = 0;
    inicial = 0;
    k = 0;
    rep[0] = ' ';
    rep[1] = '\0';
    system("cls");
    printf("Ingrese el nombre del jugador \n");
	scanf("%s",nombreJugador);
    do
    {
		system("cls");
        temp=0;
        if(inicial == 0)
        {
            for(i=0;i<strlen(frase);i++)
            {
                if(frase[i] == ' ')
                {
                    temporal[i] = ' ';
                    longitud++;
                }
                else
                {
                    temporal[i] = '_';
                    longitud++;
                }
            }
        }
        inicial = 1;
        temporal[longitud] = '\0';
        for(i=0;i<strlen(rep);i++)
        {
            if(rep[i] == pal)
            {
                repetido = 1;
                break;
            }
            else
           {
               repetido = 0;
           }
        }
        if(repetido == 0)
        {
            for(i=0;i<strlen(frase);i++)
            {
                if(frase[i] == pal)
                {
                	if(temporal[i] == '_'){
                		acertado++;
					}
				temporal[i] = pal;
                temp=1;
                }
            }
            if(temp == 0)
            {
                intentos = intentos - 1;
            }
        }
        else
        {
            printf("  Ya se ha introducido este caracter");
            printf("\n\n");
        }
        printf("\n");
        for(i=0;i<strlen(temporal);i++)
        {
            printf(" %c ",temporal[i]);
        }
        printf("\n");
        if(strcmp(frase,temporal) == 0)
        {
            gano = 1;
            break;
        }
        printf("\n  Letras Acertadas: %d",acertado);
        printf("\n  Oportunidades Restantes: %d",intentos);
        printf("\n  Letras ingresadas: %s",letrasIngresadas);
        printf("\n");
        rep[k] = pal;
        k++;
        if (intentos==0)
        {
           break;
        }
        printf("  Introduzca una letra:");
        scanf("\n%c",&pal);
       concatenarCharACadena(pal, letrasIngresadas); 
	   	concatenarCharACadena('-', letrasIngresadas); 
    }
    while(intentos != 0);
    if(gano)
    {
    	strcpy(resultadoJuego, "Gano");
    	printf("\n\n*********************************************************************************************************");
        printf("\n\n                                Felicitaciones, has ganado.");
        printf("\n\n                                           %s",nombreJugador);
        printf("\n\n                                Eres bueno en esto  [0 - 0] .");
        printf("\n\n*********************************************************************************************************");
    }
    else
    {
    	strcpy(resultadoJuego, "Perdio");
    	printf("\n\n*********************************************************************************************************");
        printf("\n\n                                     Has perdido   [0 = 0].");
        printf("\n\n                                           %s",nombreJugador);
        printf("\n\n                               [0 = 0] Lo lograras la proxima vez.");
        printf("\n\n*********************************************************************************************************");
    }
    printf("\n\n");
    system("PAUSE");
    FILE *F = fopen("Historico.txt","a");
    fprintf(F,"RESULTADO JUEGO \nNombre del jugador: %s, Resultado del juego: %s, Palabra oculta: %s, Numero de intentos %d \n",nombreJugador,resultadoJuego,frase,(8-intentos));
	fclose(F);
    return 0;
}
void concatenarCharACadena(char c, char *cadena)
{
    char cadenaTemporal[2];
    cadenaTemporal[0] = c;
    cadenaTemporal[1] = '\0';
    strcat(cadena, cadenaTemporal);
}
