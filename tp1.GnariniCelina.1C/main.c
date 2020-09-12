#include "tp1.Operaciones.h"


int main()
{
    float primerOperando;
    float segundoOperando;
    float suma;
    float resta;
    float multiplicacion;
    long int factorial;
    int opcionMenu;
    int banderaOpcionCalcular;
    int banderaPrimerOperando;
    int banderaSegundoOperando;
    float division;


    banderaOpcionCalcular=0;
    banderaPrimerOperando=0;
    banderaSegundoOperando=0;

    printf("CALCULADORA\n");//presentacion programa

    do
    {
        printf("\nMENU \n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n4. Informar resultados\n5.Salir\n");
        printf("Elija una opcion: ");
        scanf("%d",&opcionMenu);
        while(opcionMenu!=1&&opcionMenu!=2&&opcionMenu!=3&&opcionMenu!=4&&opcionMenu!=5)
        {
            printf("\nERROR!!! \n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n4. Informar resultados\n5.Salir\n");
            printf("Elija una opcion: ");
            scanf("%d",&opcionMenu);
        }

        switch(opcionMenu)
        {
            case 1:
                printf("\nIngrese primer operando (A=X): \n");//A
                scanf("%f", &primerOperando);
                banderaPrimerOperando=1;
                break;
            case 2:
                printf("\nIngrese segundo operando (B=Y): \n");//B
                scanf("%f", &segundoOperando);
                banderaSegundoOperando=1;
                break;
            case 3:
                if(banderaPrimerOperando==0)
                {
                    printf("\nERROR!!! \nSeleccione opcion 1 para ingresar primer operando");
                }
                else
                {
                    if(banderaSegundoOperando==0)
                    {
                        printf("\nERROR!!! \nSeleccione opcion 2 para ingresar segundo operando");
                    }
                    else
                    {
                        suma = SumarNumeros(primerOperando, segundoOperando);
                        resta = RestarNumeros(primerOperando, segundoOperando);
                        division = DividirNumeros(primerOperando, segundoOperando);
                        multiplicacion = MultiplicarNumeros(primerOperando, segundoOperando);
                        factorial = CalcularFactorial(primerOperando);
                        banderaOpcionCalcular=1;
                    }
                }
                break;
            case 4:

                if(banderaOpcionCalcular==0)
                {
                    printf("\nPrimero debe elegir la opcion 3.Calcular todas las operaciones");
                }
                else
                {
                    printf("\nEl resultado de (%.2f+%f) es: %.2f", primerOperando, segundoOperando, suma);
                    printf("\nEl resultado de (%.2f-%.2f) es: %.2f", primerOperando, segundoOperando, resta);
                    printf("\nEl resultado de (%.2f*%.2f) es: %.2f", primerOperando, segundoOperando,multiplicacion);
                    if(segundoOperando==0)
                    {
                        printf("\nNo se puede realizar la division por 0, reingrese el segundo operando\n");
                    }
                    else
                    {
                        printf("\nEl resultado de (%.2f/%.2f) es: %.2f\n", primerOperando, segundoOperando, division);
                    }
                    printf("\nEl factorial de (%.2f!) es: %d", primerOperando, factorial);
                }
                break;
            case 5:
                printf("Gracias por utilizar la CALCULADORA");
                break;
        }

    }while(opcionMenu!=5);

    return 0;
}
