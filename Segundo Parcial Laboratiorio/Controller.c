/**
 	 THEO KATZ
 	 1°B
 	 SEGUNDO PARCIAL
 	 TEMA 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Contestant.h"
#include "parser.h"
#include "Common.h"
#include "Menu.h"

/** \brief Carga los datos de los concursantes desde el archivo .csv (modo texto).
 *
 * \param pArrayListContestant LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListContestant)
{
	int returnValue;
	char path[50];
	returnValue = -1;
	FILE* pFile;

	inputString("Ingrese el nombre del archivo del que leer a los concursantes (sin '.csv').\n", path);

	strcat(path, ".csv");

	if(path != NULL)
	{
		pFile = fopen(path, "r");

		if(pFile != NULL)
		{
			ll_clear(pArrayListContestant);

			parser_ContestantFromText(pFile, pArrayListContestant);

			returnValue = 1;
		}
		else
        {
            returnValue = 0;
        }
	}

    return returnValue;
}

/** \brief Listar concursantes
 *
 * \param path char*
 * \param pArrayListContestant LinkedList*
 * \return int
 *
 */
int controller_ListContestants(LinkedList* pArrayListContestant)
{
	int i;
	int returnValue;
	returnValue = 0;
	int length;
	Contestant* pContestant;
	length = ll_len(pArrayListContestant);

	if(length > 0)
	{
		printf("%4s %8s %16s %10s %20s %20s %22s\n", "Id", "Anio", "Nombre", "DNI", "Fecha Presentacion", "Tema Presentacion", "Puntaje Primera Ronda");
		for(i=0;i<length;i++)
		{
			pContestant = ll_get(pArrayListContestant, i);
			printContestantFromPointer(pContestant);
		}

		returnValue = 1;
	}
	else
	{
		returnValue = 2;
	}

    return returnValue;
}
