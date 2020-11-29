/**
 	 THEO KATZ
 	 1°B
 	 SEGUNDO PARCIAL
 	 TEMA 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Menu.h"
#include "Common.h"

void MenuFunction(LinkedList* ContestantList)
{
	int MenuOption;
	int status;

	do{
		MenuOption = getNumberBetween("1. Cargar los datos de los concursantes desde el archivo .csv (modo texto).\n2. Mostrar los concursantes.\n3. Alta de empleado\n0. Salir\n", 0, 3);

		switch(MenuOption)
		{
            case 1:
                status = controller_loadFromText(ContestantList);
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
					printf("No hay concursantes cargados, cargue al menos un empleado para poder listar.\n");
				}
                break;
            case 3:
                break;
		}

	}while(MenuOption > 0);
}
