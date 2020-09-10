#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "functions.h"

int main()
{
    int menuOption;
    int input1;
    int input2;
    int input1Flag = 0;
    int input2Flag = 0;
    int results[5];
    float divisionResult;
    int divisionFlag = 0;
    int resultsFlag = 0;

    do{

        if(input1Flag == 0)
        {
            if(input2Flag == 0)
            {
                printf("\n\nSeleccione una opcion:\n\n1) Ingresar primer numero (A = null)\n2) Ingresar segundo numero (B = null)\n3) Calcular operaciones\n4) Informar resultados\n5) Salir\n\n");
            }
            else
            {
                printf("\n\nSeleccione una opcion:\n\n1) Ingresar primer numero (A = null)\n2) Ingresar segundo numero (B = %d)\n3) Calcular operaciones\n4) Informar resultados\n5) Salir\n\n", input2);
            }
        }else
        {
            if(input2Flag == 0)
            {
                printf("\n\nSeleccione una opcion:\n\n1) Ingresar primer numero (A = %d)\n2) Ingresar segundo numero (B = null)\n3) Calcular operaciones\n4) Informar resultados\n5) Salir\n\n", input1);
            }
            else
            {
                printf("\n\nSeleccione una opcion:\n\n1) Ingresar primer numero (A = %d)\n2) Ingresar segundo numero (B = %d)\n3) Calcular operaciones\n4) Informar resultados\n5) Salir\n\n", input1, input2);
            }
        }

        menuOption = getNumber();

        if(0 < menuOption && menuOption < 6)
        {
            switch(menuOption)
            {
                case 1:
                    printf("Ingrese el primer numero.\n");
                    input1 = getNumber();
                    input1Flag = 1;
                break;
                case 2:
                    printf("Ingrese el segundo numero.\n");
                    input2 = getNumber();
                    input2Flag = 1;
                break;
                case 3:
                    if(input1Flag == 1 && input2Flag == 1)
                    {
                        getResults(input1, input2, results);
                        if(input2 != 0)
                        {
                            divisionResult = division(input1, input2);
                            divisionFlag = 1;
                        }
                        else
                        {
                            divisionFlag = 0;
                        }
                        resultsFlag = 1;
                    }
                    else
                    {
                        printf("Por favor ingrese ambos operandos.");
                    }
                break;
                case 4:
                    if(resultsFlag == 1)
                    {
                        showResults(results, divisionResult, divisionFlag);
                    }
                    else
                    {
                        printf("Los resultados no fueron calculados.");
                    }
                break;
                default:
                break;
            }
        }
    }while(menuOption != 5);

    printf("Saliendo del programa.\n");
}
