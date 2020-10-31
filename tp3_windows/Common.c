/**
 	 THEO KATZ
 	 1°B
 	 TP3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "Employee.h"

int getNumber(char* text)
{
	int returnValue;
    char input[25];
    printf("%s",text);
    fflush(stdin);
    scanf(" %s", input);
    while(isANumber(input) == 0)
    {
    	printf("Error, por favor ingrese un numero valido.\n");
    	printf("%s",text);
		fflush(stdin);
		scanf(" %s", input);
    }
    returnValue = atoi(input);
    return returnValue;
}

int getNumberBetween(char* text,int minimum, int maximum)
{
    int input;
    input = getNumber(text);
    while(input < minimum || input > maximum)
    {
        printf("Error, por favor ingrese una opcion valida.\n");
        input = getNumber(text);
    }
    return input;
}

int getPositiveNumber(char* text)
{
	int input;
	input = getNumber(text);

	while(input < 1)
	{
		printf("Error, por favor ingrese una opcion valida.\n");
		input = getNumber(text);
	}
	return input;
}

char getChar(char* text)
{
    char input;
    printf("%s",text);
    fflush(stdin);
    scanf(" %c", &input);
    return input;
}

void inputString(char* text, char* input){
    printf("%s",text);
    fflush(stdin);
    scanf("%[^\n]",input);
}

int isOnlyLetters(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
}

int isANumber(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
        return 0;
        i++;
    }
    return 1;
}

int getNewId(LinkedList* pArrayListEmployee)
{
	int i;
	int auxId;
	int maxId;
	maxId = 0;
	int length;
	length = ll_len(pArrayListEmployee);
	Employee* pEmployee;
	for(i=0;i<length;i++)
	{
		pEmployee = ll_get(pArrayListEmployee, i);
		employee_getId(pEmployee, &auxId);
		if(i == 0 || auxId > maxId)
		{
			maxId = auxId;
		}
	}
	return maxId + 1;
}

int getEmployeeIndexById(LinkedList* pArrayListEmployee, int id)
{
	Employee* pEmployee;
	int i;
	int length;
	length = ll_len(pArrayListEmployee);
	int auxId;

//	printf("Length: %d", length);

	for(i=0;i<length;i++)
	{
		pEmployee = ll_get(pArrayListEmployee, i);
		employee_getId(pEmployee, &auxId);
		if(auxId == id)
		{
			return i;
		}
	}
	return -1;
}
