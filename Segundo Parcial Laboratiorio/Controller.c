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
#include "Controller.h"

/** \brief Carga los datos de los concursantes desde el archivo .csv (modo texto).
 *
 * \param pArrayListContestant LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListContestant, char* path)
{
	int returnValue;
	returnValue = -1;
	FILE* pFile;

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

int controller_JuryFunction(LinkedList* pArrayListContestant, char* path)
{
    int returnValue;
	char resultPath[50];
	int length;
	int i;
	Contestant* pContestant;
	int auxId;
	int auxSecondScore;
	float auxAvgScore;
	returnValue = -1;
	length = ll_len(pArrayListContestant);
	FILE* pFile;

	if(path[0] != '\0')
    {
        if(length > 0)
        {
            strcpy(resultPath, "resultado");
            strcat(resultPath, path);

            if(resultPath != NULL)
            {
                pFile = fopen(resultPath, "w");

                if(pFile != NULL)
                {
                    fprintf(pFile, "id,puntajeSegundaRonda,puntajePromedio\n");

                    ll_map(pArrayListContestant, SetScore);

                    for(i = 0;i < length;i++)
                    {
                        pContestant = ll_get(pArrayListContestant, i);
                        Contestant_getId(pContestant, &auxId);
                        Contestant_getSecondRoundScore(pContestant, &auxSecondScore);
                        Contestant_getAverageScore(pContestant, &auxAvgScore);
                        fprintf(pFile, "%d,%d,%.2f\n", auxId, auxSecondScore, auxAvgScore);

                        printf("%4s %8s %16s %10s %20s %20s %22s %22s %18s %22s\n", "Id", "Anio", "Nombre", "DNI", "Fecha Presentacion", "Tema Presentacion", "Puntaje Primera Ronda", "Puntaje Segunda Ronda", "Puntaje Promedio", "Puntaje Tercera Ronda");
                        printContestantFromPointerWithScores(pContestant);
                    }
                    fclose(pFile);


                    returnValue = 1;
                }
                else
                {
                    returnValue = 0;
                }
            }
        }
        else
        {
            returnValue = -2;
        }
    }
    else
    {
        returnValue = -1;
    }

    return returnValue;
}

int controller_FilterContestants(LinkedList* pArrayListContestant)
{
    int returnValue = 0;
    LinkedList* filteredContestants = NULL;
    float highestAverageScore;

    highestAverageScore = getHighestAverageScore(pArrayListContestant);

    filteredContestants = ll_filter(pArrayListContestant, highestAverageScore, hasHighestAverageScore);

    returnValue = 1;

    if(!ll_isEmpty(filteredContestants))
    {
        printContestantsWithScores(filteredContestants);

        SaveContestantsMultipleFiles(filteredContestants);
    }
    else
    {
        printf("No hay concursantes.\n");
    }

    return returnValue;
}

int controller_FilterFinalists(LinkedList* pArrayListContestant)
{
    int returnValue = 0;
    LinkedList* filteredContestants = NULL;
    int thirdHighestFirstScore;
    Contestant* pContestant;

    ll_sort(pArrayListContestant, Contestant_CompareByFirstScore, 1);

    pContestant = ll_get(pArrayListContestant, 2);

    Contestant_getFirstRoundScore(pContestant, &thirdHighestFirstScore);

//    printf("%d\n", thirdHighestFirstScore);

    filteredContestants = ll_filterV2(pArrayListContestant, thirdHighestFirstScore, hasEqualOrHigherFirstScore);

    returnValue = 1;

    if(!ll_isEmpty(filteredContestants))
    {
        printContestants(filteredContestants);

        SaveContestantsMultipleFiles(filteredContestants);
    }
    else
    {
        printf("No hay concursantes.\n");
    }

    return returnValue;
}

int controller_FilterThirdScoreFinalists(LinkedList* pArrayListContestant)
{
    int returnValue = 0;
    LinkedList* filteredContestants = NULL;
    int thirdHighestThirdScore;
    Contestant* pContestant;

    ll_sort(pArrayListContestant, Contestant_CompareByThirdScore, 1);

    pContestant = ll_get(pArrayListContestant, 2);

    Contestant_getThirdRoundScore(pContestant, &thirdHighestThirdScore);

//    printf("%d\n", thirdHighestThirdScore);

    filteredContestants = ll_filterV2(pArrayListContestant, thirdHighestThirdScore, hasEqualOrHigherThirdScore);

    returnValue = 1;

    if(!ll_isEmpty(filteredContestants))
    {
        printContestantsWithScores(filteredContestants);

        SaveContestantsMultipleFiles(filteredContestants);
    }
    else
    {
        printf("No hay concursantes.\n");
    }

    return returnValue;
}

void SaveContestantsMultipleFiles(LinkedList* pArrayListContestant)
{
    char path[50];
    FILE* pFile;
    int i;
    int length;
    length = ll_len(pArrayListContestant);
    Contestant* pContestant;
    int auxId;
    int auxYearOfBirth;
    char auxName[50];
    char auxDni[10];
    char auxPresentationDate[12];
    char auxPresentationTheme[30];
    int auxFirstRoundScore;
    int auxSecondRoundScore;
    float auxAverageScore;

    for(i = 0; i < length; i++)
    {
        pContestant = ll_get(pArrayListContestant, i);
        Contestant_getDni(pContestant, auxDni);
        strcpy(path, auxDni);
        strcat(path, ".csv");

        if(path != NULL)
        {
            pFile = fopen(path, "w");

            if(pFile != NULL)
            {
                fprintf(pFile,"numeroConcursante,anio,nombre,dni,fechaPresentacion,temaPresentacion,puntajePrimeraRonda,puntajeSegundaRonda,puntajePromedio\n");

                Contestant_getId(pContestant, &auxId);
                Contestant_getYearOfBirth(pContestant, &auxYearOfBirth);
                Contestant_getName(pContestant, auxName);
                Contestant_getPresentationDate(pContestant, auxPresentationDate);
                Contestant_getPresentationTheme(pContestant, auxPresentationTheme);
                Contestant_getFirstRoundScore(pContestant, &auxFirstRoundScore);
                Contestant_getSecondRoundScore(pContestant, &auxSecondRoundScore);
                Contestant_getAverageScore(pContestant, &auxAverageScore);

                fprintf(pFile,"%d,%d,%s,%s,%s,%s,%d,%d,%f", auxId, auxYearOfBirth, auxName, auxDni, auxPresentationDate, auxPresentationTheme, auxFirstRoundScore, auxSecondRoundScore, auxAverageScore);
            }
        }

        fclose(pFile);
    }
}

float getHighestAverageScore(LinkedList* pArrayListContestant)
{
    int i;
    Contestant* pContestant;
    int length = ll_len(pArrayListContestant);
    float auxScore;
    float highestScore;

    for(i = 0;i < length; i++)
    {
        pContestant = ll_get(pArrayListContestant, i);
        Contestant_getAverageScore(pContestant, &auxScore);
        if(i == 0 || auxScore > highestScore)
        {
            highestScore = auxScore;
        }
    }
    return highestScore;
}

int hasHighestAverageScore(void* this, float highestAverageScore)
{
    Contestant* auxContestant;
    int returnValue = 0;
    float auxAverageScore;

    if(this != NULL)
    {
        auxContestant = (Contestant*)this;

        Contestant_getAverageScore(auxContestant, &auxAverageScore);

        if(auxAverageScore == highestAverageScore)
        {
            returnValue = 1;
        }
    }
    return returnValue;
}

int hasEqualOrHigherFirstScore(void* this, int highestFirstScore)
{
    Contestant* auxContestant;
    int returnValue = 0;
    int auxFirstScore;

    if(this != NULL)
    {
        auxContestant = (Contestant*)this;

        Contestant_getFirstRoundScore(auxContestant, &auxFirstScore);

        if(auxFirstScore >= highestFirstScore)
        {
            returnValue = 1;
        }
    }
    return returnValue;
}

int hasEqualOrHigherThirdScore(void* this, int highestThirdScore)
{
    Contestant* auxContestant;
    int returnValue = 0;
    int auxThirdScore;

    if(this != NULL)
    {
        auxContestant = (Contestant*)this;

        Contestant_getThirdRoundScore(auxContestant, &auxThirdScore);

        if(auxThirdScore >= highestThirdScore)
        {
            returnValue = 1;
        }
    }
    return returnValue;
}
