/**
 	 THEO KATZ
 	 1°B
 	 SEGUNDO PARCIAL
 	 TEMA 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Contestant.h"
#include "Common.h"

Contestant* contestant_new()
{
    Contestant* newContestant;
    newContestant = (Contestant*)malloc(sizeof(Contestant));

    return newContestant;
}

Contestant* contestant_newParametros(char* strId, char* strYearOfBirth, char* Name, char* strdni, char* PresentationDate, char* PresentationTheme, char* strFirstRoundScore)
{
    Contestant* newContestant;
    newContestant = contestant_new();

    int newId;
    int YearOfBirth;
    int FirstRoundScore;

    newId = atoi(strId);
    YearOfBirth = atoi(strYearOfBirth);
    FirstRoundScore = atoi(strFirstRoundScore);

    if(newContestant != NULL)
    {
        Contestant_setId(newContestant, newId);
        Contestant_setYearOfBirth(newContestant, YearOfBirth);
        Contestant_setName(newContestant, Name);
        Contestant_setDni(newContestant, strdni);
        Contestant_setPresentationDate(newContestant, PresentationDate);
        Contestant_setPresentationTheme(newContestant, PresentationTheme);
        Contestant_setFirstRoundScore(newContestant, FirstRoundScore);
        Contestant_setSecondRoundScore(newContestant, 0);
        Contestant_setAverageScore(newContestant, 0);
    }

    printf("%s\n", newContestant->Name);

//    printContestantFromPointer(newContestant);

    return newContestant;
}

int Contestant_setId(Contestant* this, int id)
{
    int retorno=0;
	if(id>0 && this!=NULL)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int Contestant_getId(Contestant* this, int* id)
{
    int retorno=0;
	if(id!=NULL && this!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

int Contestant_setYearOfBirth(Contestant* this, int yearOfBirth)
{
    int retorno=0;
	if(yearOfBirth>0 && this!=NULL)
	{
		this->YearOfBirth=yearOfBirth;
		retorno=1;
	}
	return retorno;
}
int Contestant_getYearOfBirth(Contestant* this, int* yearOfBirth)
{
    int retorno=0;
	if(yearOfBirth!=NULL && this!=NULL)
	{
		*yearOfBirth=this->YearOfBirth;
		retorno=1;
	}
	return retorno;
}

int Contestant_setName(Contestant* this, char* name)
{
    int returnValue = 0;
    if(name != NULL && this != NULL)
    {
        strcpy(this->Name, name);
        returnValue = 1;
    }
    return returnValue;
}
int Contestant_getName(Contestant* this, char* name)
{
    int returnValue = 0;
    if(name != NULL && this != NULL)
    {
        strcpy(name, this->Name);
//        printf("%s\n", name);
        returnValue = 1;
    }
    return returnValue;
}

int Contestant_setDni(Contestant* this, char* dni)
{
    int returnValue = 0;
    if(dni != NULL && this != NULL)
    {
        strncpy(this->Dni, dni, 50);
        returnValue = 1;
    }
    return returnValue;
}

int Contestant_getDni(Contestant* this, char* dni)
{
    int returnValue = 0;
    if(dni != NULL && this != NULL)
    {
        strcpy(dni, this->Dni);
        returnValue = 1;
    }
    return returnValue;
}

int Contestant_setPresentationDate(Contestant* this, char* presentationDate)
{
    int returnValue = 0;
    if(presentationDate != NULL && this != NULL)
    {
        strcpy(this->PresentationDate, presentationDate);
        returnValue = 1;
    }
    return returnValue;
}

int Contestant_getPresentationDate(Contestant* this, char* presentationDate)
{
    int returnValue = 0;
    if(presentationDate != NULL)
    {
        strcpy(presentationDate, this->PresentationDate);
        returnValue = 1;
    }
    return returnValue;
}

int Contestant_setPresentationTheme(Contestant* this, char* presentationTheme)
{
    int returnValue = 0;
    if(presentationTheme != NULL && this != NULL)
    {
        strncpy(this->PresentationTheme, presentationTheme, 50);
        returnValue = 1;
    }
    return returnValue;
}

int Contestant_getPresentationTheme(Contestant* this, char* presentationTheme)
{
    int returnValue = 0;
    if(presentationTheme != NULL && this != NULL)
    {
        strcpy(presentationTheme, this->PresentationTheme);
        returnValue = 1;
    }
    return returnValue;
}

int Contestant_setFirstRoundScore(Contestant* this, int firstRoundScore)
{
    int retorno=0;
	if(firstRoundScore>0 && this!=NULL)
	{
		this->FirstRoundScore=firstRoundScore;
		retorno=1;
	}
	return retorno;
}
int Contestant_getFirstRoundScore(Contestant* this, int* firstRoundScore)
{
    int retorno=0;
	if(firstRoundScore!=NULL && this!=NULL)
	{
		*firstRoundScore=this->FirstRoundScore;
		retorno=1;
	}
	return retorno;
}

int Contestant_setSecondRoundScore(Contestant* this, int secondRoundScore)
{
    int retorno=0;
	if(secondRoundScore>0 && this!=NULL)
	{
		this->SecondRoundScore=secondRoundScore;
		retorno=1;
	}
	return retorno;
}

int Contestant_getSecondRoundScore(Contestant* this, int* secondRoundScore)
{
    int retorno=0;
	if(secondRoundScore!=NULL && this!=NULL)
	{
		*secondRoundScore=this->SecondRoundScore;
		retorno=1;
	}
	return retorno;
}

int Contestant_setAverageScore(Contestant* this, float avgScore)
{
    int retorno=0;
	if(avgScore>0 && this!=NULL)
	{
		this->AverageScore=avgScore;
		retorno=1;
	}
	return retorno;
}

int Contestant_getAverageScore(Contestant* this, float* avgScore)
{
    int retorno=0;
	if(avgScore!=NULL && this!=NULL)
	{
		*avgScore=this->AverageScore;
		retorno=1;
	}
	return retorno;
}

void printContestantFromPointer(Contestant* this)
{
	int id;
	int YearOfBirth;
	char Name[50];
	char Dni[8];
	char PresentationDate[20];
	char PresentationTheme[30];
	int FirstRoundScore;

    Contestant_getId(this, &id);
    Contestant_getYearOfBirth(this, &YearOfBirth);
    Contestant_getName(this, Name);
    printf("%s\n", Name);
    Contestant_getDni(this, Dni);
    Contestant_getPresentationDate(this, PresentationDate);
    Contestant_getPresentationTheme(this, PresentationTheme);
    Contestant_getFirstRoundScore(this, &FirstRoundScore);

    printf("%4d ", id);
    printf("%8d ", YearOfBirth);
    printf("%16s ", Name);
	printf("%10s \n", Dni);
}

void SetScore(Contestant* this)
{
    int firstScore;
    int secondScore;
    float avgScore;

    srand(time(NULL));

    secondScore = rand() % 100;

    Contestant_setSecondRoundScore(this, secondScore);

    Contestant_getFirstRoundScore(this, &firstScore);

    avgScore = (float)firstScore / secondScore;

    Contestant_setAverageScore(this, avgScore);
}
