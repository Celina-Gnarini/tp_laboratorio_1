#include "tp1.Operaciones.h"


float SumarNumeros(float primerOperando, float segundoOperando)//Parametros formales
{
    float suma;

    suma=primerOperando+segundoOperando;

    return suma;
}
float RestarNumeros(float primerOperando, float segundoOperando)
{
    float resta;

    resta=primerOperando-segundoOperando;


    return resta;
}
float MultiplicarNumeros(float primerOperando, float segundoOperando)
{
    float multiplicacion;

    multiplicacion=primerOperando*segundoOperando;


    return multiplicacion;
}
float DividirNumeros(float primerOperando, float segundoOperando)
{
    float division;


    division=(primerOperando/segundoOperando;


    return division;
}
long int CalcularFactorial(float primerOperando)
{
    long int factorial;

    if(primerOperando == 0)
    {
        factorial = 1;
    }
    else
    {
         factorial = primerOperando * CalcularFactorial(primerOperando - 1);
    }

    return factorial;

}
