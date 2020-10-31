/**
 	 THEO KATZ
 	 1°B
 	 TP3
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Common.h"
#include "Menu.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int returnValue;
	returnValue = 0;
	FILE* pFile;

	if(path != NULL)
	{
		pFile = fopen(path, "r");

		if(pFile != NULL)
		{
			ll_clear(pArrayListEmployee);

			parser_EmployeeFromText(pFile, pArrayListEmployee);

			returnValue = 1;
		}
	}

    return returnValue;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int returnValue;
	returnValue = 0;
	FILE* pFile;

	if(path != NULL)
	{
		pFile = fopen(path, "rb");

		if(pFile != NULL)
		{
			ll_clear(pArrayListEmployee);

			parser_EmployeeFromBinary(pFile, pArrayListEmployee);

			returnValue = 1;
		}
	}
    return returnValue;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int length;
	int status;
	status = 0;
	int id;
	char sId[4];
	char name[50];
	int workedHours;
	char sWorkedHours[4];
	int salary;
	char sSalary[8];

	if(pArrayListEmployee != NULL)
	{
		length = ll_len(pArrayListEmployee);

		if(length < 1)
		{
			id = 1;
		}
		else
		{
			id = getNewId(pArrayListEmployee);
		}

		inputString("Ingrese el nombre del nuevo empleado.\n", name);

		workedHours = getNumber("Ingrese las horas trabajadas del nuevo empleado.\n");

		salary = getNumber("Ingrese el sueldo del nuevo empleado.\n");

		itoa(id, sId, 10);
		itoa(workedHours, sWorkedHours, 10);
		itoa(salary, sSalary, 10);

		pEmployee = employee_newParametros(sId, name, sWorkedHours, sSalary);

		ll_add(pArrayListEmployee, pEmployee);

		status = 1;
	}

    return status;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int returnValue;
	returnValue = 0;
	int length;
	int idToModify;
	int indexToModify;

	if(pArrayListEmployee != NULL)
	{
		//PORQUE ME TIRA WARNING ESTO?
		controller_ListEmployee(pArrayListEmployee);

		length = ll_len(pArrayListEmployee);

		if(length > 0)
		{
			idToModify = getNumber("Ingrese el ID del empleado que desea modificar.\n");
			indexToModify = getEmployeeIndexById(pArrayListEmployee, idToModify);

			if(indexToModify > -1)
			{
				pEmployee = ll_get(pArrayListEmployee, indexToModify);

				ModifyEmployee(pEmployee);

				returnValue = 1;
			}
			else
			{
				returnValue = 2;
			}
		}
		else
		{
			returnValue = 3;
		}
	}

    return returnValue;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int returnValue;
	returnValue = 0;
	int status;
	int length;
	int idToDelete;
	int indexToDelete;

	if(pArrayListEmployee != NULL)
	{
		//PORQUE ME TIRA WARNING ESTO?
		controller_ListEmployee(pArrayListEmployee);

		length = ll_len(pArrayListEmployee);

		if(length > 0)
		{
			idToDelete = getNumber("Ingrese el ID del empleado a borrar.\n");
			indexToDelete = getEmployeeIndexById(pArrayListEmployee, idToDelete);

			if(indexToDelete > -1)
			{
				pEmployee = ll_get(pArrayListEmployee, indexToDelete);
				printEmployeeFromPointer(pEmployee);

				status = getNumberBetween("¿Esta seguro de querer eliminar a este empleado?\nIngrese 0 para NO, 1 para SI.\n", 0, 1);

				if(status == 1)
				{
					status = ll_remove(pArrayListEmployee, indexToDelete);
					returnValue = 1;
				}

//				printf("estado %d", returnValue);
			}
			else
			{
				returnValue = 2;
			}
		}
		else
		{
			returnValue = 3;
		}
	}

    return returnValue;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int returnValue;
	returnValue = 0;
	int length;
	Employee* pEmployee;
	length = ll_len(pArrayListEmployee);

	if(length > 0)
	{
		printf("%4s %16s %16s %8s\n", "id", "Nombre", "Horas Trabajadas", "Sueldo");
		for(i=0;i<length;i++)
		{
			pEmployee = ll_get(pArrayListEmployee, i);
			printEmployeeFromPointer(pEmployee);
		}

		returnValue = 1;
	}
	else
	{
		returnValue = 2;
	}

    return returnValue;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int returnValue;
	returnValue = 0;
	int length;
	length = ll_len(pArrayListEmployee);

	if(length > 0)
	{
		SortMenu(pArrayListEmployee);

		returnValue = 1;
	}
	else
	{
		returnValue = 2;
	}

    return returnValue;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int i;
	int returnValue;
	returnValue = 0;
	int length;
	length = ll_len(pArrayListEmployee);
	Employee* pEmployee;
	int auxId;
	char auxName[50];
	int auxHours;
	int auxSalary;

	if(path != NULL)
	{
		pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
			for(i=0;i<length;i++)
			{
				pEmployee = ll_get(pArrayListEmployee, i);
				employee_getId(pEmployee, &auxId);
				employee_getNombre(pEmployee, auxName);
				employee_getHorasTrabajadas(pEmployee, &auxHours);
				employee_getSueldo(pEmployee, &auxSalary);
				fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxName, auxHours, auxSalary);
			}
		}

		fclose(pFile);
		returnValue = 1;
	}

    return returnValue;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int i;
	int returnValue;
	returnValue = 0;
	int length;
	length = ll_len(pArrayListEmployee);
	Employee* pEmployee;
	int auxId;
	char auxName[50];
	int auxHours;
	int auxSalary;

	if(path != NULL)
	{
		pFile = fopen(path, "wb");

		if(pFile != NULL)
		{
			for(i=0;i<length;i++)
			{
				pEmployee = ll_get(pArrayListEmployee, i);
				employee_getId(pEmployee, &auxId);
				employee_getNombre(pEmployee, auxName);
				employee_getHorasTrabajadas(pEmployee, &auxHours);
				employee_getSueldo(pEmployee, &auxSalary);
				fwrite(pEmployee, sizeof(Employee), 1, pFile);
			}

			returnValue = 1;
		}

		fclose(pFile);
	}

    return returnValue;
}

