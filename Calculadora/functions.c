#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "functions.h"

int getNumber()
{
    int input;
    //printf("Ingrese un numero:");
    scanf("%d",&input);
    return input;
}

void getResults(int a, int b, int results[5])
{
    results[0] = sum(a, b);

    results[1] = subtraction(a, b);

    results[2] = multiplication(a, b);

//    results[3] = division(a, b);

    results[3] = factorial(a);

    results[4] = factorial(b);

    printf("Resultados calculados. \n\n");
}

int sum(int firstVal, int secondVal)
{
    int result;
    result = firstVal + secondVal;
    return result;
}

int subtraction(int firstVal, int secondVal)
{
    int result;
    result = firstVal - secondVal;
    return result;
}

int multiplication(int firstVal, int secondVal)
{
    int result;
    result = firstVal * secondVal;
    return result;
}

float division(int firstVal, int secondVal)
{
    float result;
    if(secondVal != 0)
    {
        result = (float)firstVal / secondVal;
    }
    return result;
}

int factorial(int val)
{
    int result;
    if(val < 0)
    {
        result = -1;
    }
    else if(val == 0 || val == 1)
    {
        result = 1;
    }
    else
    {
        result = val * factorial(val - 1);
    }
    return result;
}

void showResults(int results[5], float divisionResult, int divisionFlag)
{
    printf("El resultado de la suma es: %d \n", results[0]);

    printf("El resultado de la resta es: %d \n", results[1]);

    printf("El resultado de la multiplicacion es: %d \n", results[2]);

//    printf("El resultado de la division es: %d \n", results[3]);

    if(divisionFlag == 1)
    {
        printf("El resultado de la division es: %f \n", divisionResult);
    }
    else
    {
        printf("No es posible dividir por cero.\n");
    }

    //VERIFICATION FOR FACTORIAL VALUES TO NOT OVERFLOW DOESN´T WORK
    if(results[3] < 0)
    {
        printf("No se puede calcular el factorial del primer numero ya que es un numero negativo. \n");
    }
    else
    {
        printf("El resultado del primer factorial es: %d \n", results[3]);
    }

    if(results[4] < 0)
    {
        printf("No se puede calcular el factorial del segundo numero ya que es un numero negativo. \n");
    }
    else
    {
        printf("El resultado del segundo factorial es: %d \n\n", results[4]);
    }
}
