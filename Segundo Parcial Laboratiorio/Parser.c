/**
 	 THEO KATZ
 	 1°B
 	 SEGUNDO PARCIAL
 	 TEMA 2
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Contestant.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListContestants LinkedList*
 * \return int
 *
 */
int parser_ContestantFromText(FILE* pFile , LinkedList* pArrayListContestants)
{
	Contestant* pContestant;

	int returnValue;
    char id[50];
    char YearOfBirth[50];
    char Name[50];
    char dni[9];
    char PresentationDate[50];
    char PresentationTheme[30];
    char FirstRoundScore[50];

	if(pFile != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, YearOfBirth, Name, dni, PresentationDate, PresentationTheme, FirstRoundScore);

		do{
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, YearOfBirth, Name, dni, PresentationDate, PresentationTheme, FirstRoundScore);
//            printf("%s\n", PresentationDate);
			pContestant = contestant_newParametros(id, YearOfBirth, Name, dni, PresentationDate, PresentationTheme, FirstRoundScore);

//			printContestantFromPointer(pContestant);

            //printf("Parser\n");
			if(pContestant != NULL)
			{
				ll_add(pArrayListContestants, pContestant);
				returnValue = 1;
			}
		}while(!feof(pFile));
	}


    return returnValue;
}
