/**
 	 THEO KATZ
 	 1°B
 	 TP3
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;

	int returnValue;
	char id[50];
	char name[50];
	char workedHours[50];
	char salary[50];

	if(pFile != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, name, workedHours, salary);

		do{
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, name, workedHours, salary);
			pEmployee = employee_newParametros(id, name, workedHours, salary);

			if(pEmployee != NULL)
			{
				ll_add(pArrayListEmployee, pEmployee);
				returnValue = 1;
			}
		}while(!feof(pFile));
	}

    return returnValue;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
//	int returnValue;

	if(pFile != NULL)
	{
		do{
			pEmployee = employee_new();
			if(pEmployee != NULL)
			{
				fread(pEmployee, sizeof(Employee), 1, pFile);

				if(feof(pFile))
				{
					break;
				}

				ll_add(pArrayListEmployee, pEmployee);
			}
		}while(!feof(pFile));
	}
    return 1;
}
