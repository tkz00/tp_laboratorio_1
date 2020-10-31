/**
 	 THEO KATZ
 	 1°B
 	 TP3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Common.h"

Employee* employee_new()
{
    Employee* newEmployee;
    newEmployee = (Employee*)malloc(sizeof(Employee));

    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee;
    newEmployee = employee_new();

    int id;
    int workedHours;
    float salary;

    id = atoi(idStr);
    workedHours = atoi(horasTrabajadasStr);
    salary = atoi(sueldoStr);

    if(newEmployee != NULL)
    {
        employee_setId(newEmployee, id);
        employee_setNombre(newEmployee, nombreStr);
        employee_setHorasTrabajadas(newEmployee, workedHours);
        employee_setSueldo(newEmployee, salary);
    }

    return newEmployee;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this, int id)
{
	//this->id=id; //version simple
	int retorno=0;
	if(id>0 && this!=NULL)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int employee_getId(Employee* this, int* id){

	int retorno=0;
	if(id!=NULL && this!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int returnValue = 0;
    if(nombre != NULL && this != NULL)
    {
        strncpy(this->nombre, nombre, 50);
        returnValue = 1;
    }
    return returnValue;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int returnValue = 0;
    if(nombre != NULL && this != NULL)
    {
        strcpy(nombre, this->nombre);
        returnValue = 1;
    }
    return returnValue;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int returnValue = 0;
    if(horasTrabajadas > 0 && this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        returnValue = 1;
    }
    return returnValue;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int returnValue = 0;
    if(horasTrabajadas != NULL && this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        returnValue = 1;
    }
    return returnValue;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int returnValue = 0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        returnValue = 1;
    }
    return returnValue;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
    int returnValue = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        returnValue = 1;
    }
    return returnValue;
}

///Return 0 for equals, > 0 for e1 higher than e2, < 0 for e1 lower than e2
int employee_CompareById(Employee* e1, Employee* e2)
{
    int returnValue;
    returnValue = e1->id - e2->id;
    return returnValue;
}

///0 for equals, > 0 for e1 before e2, < 0 for e2 before e1
int employee_CompareByName(void* e1, void* e2)
{
	int returnValue;
	char firstEmployeeName[50];
	char secondEmployeeName[50];
	employee_getNombre(e1, firstEmployeeName);
	employee_getNombre(e2, secondEmployeeName);
	returnValue = strcmp(firstEmployeeName, secondEmployeeName);
	return returnValue;
}

int employee_CompareByWorkedHours(void* e1, void* e2)
{
	int returnValue;
	returnValue = 1;
	int firstEmployeeHours;
	int secondEmployeeHours;
	employee_getHorasTrabajadas(e1, &firstEmployeeHours);
	employee_getHorasTrabajadas(e2, &secondEmployeeHours);

	if(firstEmployeeHours > secondEmployeeHours)
	{
		returnValue = -1;
	}
	else if(firstEmployeeHours == secondEmployeeHours)
	{
		returnValue = 0;
	}

	return returnValue;
}

int employee_CompareBySalary(void* e1, void* e2)
{
	int returnValue;
	returnValue = 1;
	int firstEmployeeSalary;
	int secondEmployeeSalary;
	employee_getSueldo(e1, &firstEmployeeSalary);
	employee_getSueldo(e2, &secondEmployeeSalary);

	if(firstEmployeeSalary > secondEmployeeSalary)
	{
		returnValue = -1;
	}
	else if(firstEmployeeSalary == secondEmployeeSalary)
	{
		returnValue = 0;
	}

	return returnValue;
}

void printEmployeeFromPointer(Employee* this)
{
	int id;
	char Name[50];
	int WorkedHours;
	int Salary;

	employee_getId(this, &id);
	employee_getNombre(this, Name);
	employee_getHorasTrabajadas(this, &WorkedHours);
	employee_getSueldo(this, &Salary);

	printf("%4d %16s %16d %8d\n", id, Name, WorkedHours, Salary);
}

void ModifyEmployee(Employee* this)
{
	int modifyOption;
	modifyOption = getNumberBetween("Ingrese el dato que desea modificar\n1 - Modificar nombre\n2 - Modificar horas trabajadas\n3 - Modificar sueldo\n", 1, 3);

	switch(modifyOption)
	{
		case 1:
			ModifyName(this);
			break;
		case 2:
			ModifyWorkedHours(this);
			break;
		case 3:
			ModifySalary(this);
			break;
	}
}

void ModifyName(Employee* this)
{
	char newName[50];
	inputString("Ingrese el nuevo nombre del empleado.\n", newName);
	employee_setNombre(this, newName);
}

void ModifyWorkedHours(Employee* this)
{
	int newHours;
	newHours = getPositiveNumber("Ingrese la nueva cantidad de horas trabajadas del empleado.\n");
	employee_setHorasTrabajadas(this, newHours);
}

void ModifySalary(Employee* this)
{
	int newSalary;
	newSalary = getPositiveNumber("Ingrese el nuevo sueldo del empleado.\n");
	employee_setHorasTrabajadas(this, newSalary);
}
