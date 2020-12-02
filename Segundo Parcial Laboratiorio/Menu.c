/**
 	 THEO KATZ
 	 1°B
 	 SEGUNDO PARCIAL
 	 TEMA 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Menu.h"
#include "Common.h"

void MenuFunction(LinkedList* ContestantList)
{
	int MenuOption;
	int status;
	char filePath[50];

	do{
		MenuOption = getNumberBetween("1. Cargar los datos de los concursantes desde el archivo .csv (modo texto).\n2. Mostrar los concursantes.\n3. El jurado evalua.\n4. Filtrar por mayor promedio.\n5. Filtrar los 3 mejores primeros puntajes.\n6. Filtrar los 3 mejores terceros puntajes.\n0. Salir\n", 0, 6);

		switch(MenuOption)
		{
            case 1:
                inputString("Ingrese el nombre del archivo del que leer a los concursantes (sin '.csv').\n", filePath);
                strcat(filePath, ".csv");

                status = controller_loadFromText(ContestantList, filePath);
				if(status == 1)
				{
					printf("Se ha cargado el archivo correctamente.\n");
				}
				else if(status == 0)
                {
                    printf("No existe el nombre de archivo ingresado.\n");
                }
				else
				{
					printf("Ha habido un error, no se ha cargado el archivo.\n");
				}
                break;
            case 2:
                status = controller_ListContestants(ContestantList);
                if(status == 0)
				{
					printf("Ha habido un error, no se han podido listar los concursantes.\n");
				}
				else if(status == 2)
				{
					printf("No hay concursantes cargados, cargue al menos un concursante para poder listar.\n");
				}
                break;
            case 3:
                status = controller_JuryFunction(ContestantList, filePath);
                if(status == 0)
                {
                    printf("Ha habido un error, no se han podido calcular los puntajes.\n");
                }
                else if(status == 1)
                {
                    printf("Los puntajes han sido calculados correctamente.\n");
                }
                else if(status == -1)
                {
                    printf("No se han cargado los concursantes.\n");
                }
                else if(status == -2)
                {
                    printf("No hay concursantes en la lista, agregue al menos un concursante para que el jurado evalue.\n");
                }
                break;
            case 4:
                status = controller_FilterContestants(ContestantList);
                if(status == 1)
                {
//                    printf("Se han filtrado los concursantes correctamente.\n");
                }
                else
                {
                    printf("Ha habído un error filtrando los concursantes.");
                }
                break;
            case 5:
                status = controller_FilterFinalists(ContestantList);
                if(status == 1)
                {
//                    printf("Se han filtrado los concursantes correctamente.\n");
                }
                else
                {
                    printf("Ha habído un error filtrando los concursantes.");
                }
                break;
            case 6:
                status = controller_FilterThirdScoreFinalists(ContestantList);
                if(status == 1)
                {
//                    printf("Se han filtrado los concursantes correctamente.\n");
                }
                else
                {
                    printf("Ha habído un error filtrando los concursantes.");
                }
                break;
		}

	}while(MenuOption > 0);
}
