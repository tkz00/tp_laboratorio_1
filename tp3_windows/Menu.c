/**
 	 THEO KATZ
 	 1°B
 	 TP3
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"
#include "Common.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

void MenuFunction(LinkedList* EmployeeList)
{
	int MenuOption;
	int status;

	do{
		MenuOption = getNumberBetween("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n0. Salir\n", 0, 9);

		switch(MenuOption)
		{
			case 1:
				status = controller_loadFromText("data.csv", EmployeeList);
				if(status == 1)
				{
					printf("Se ha cargado el archivo correctamente.\n");
				}
				else
				{
					printf("Ha habido un error, no se ha cargado el archivo.\n");
				}
				break;
			case 2:
				status = controller_loadFromBinary("data.bin", EmployeeList);
				if(status == 1)
				{
					printf("Se ha cargado el archivo correctamente.\n");
				}
				else
				{
					printf("Ha habido un error, no se ha cargado el archivo.\n");
				}
				break;
			case 3:
				status = controller_addEmployee(EmployeeList);
				if(status == 1)
				{
					printf("Se ha cargado el nuevo empleado correctamente.\n");
				}
				else
				{
					printf("Ha habido un error, no se ha podido cargar el nuevo empleado.\n");
				}
				break;
			case 4:
				status = controller_editEmployee(EmployeeList);
				switch(status)
				{
					case 1:
						printf("Se ha editado el empleado correctamente.\n");
						break;
					case 2:
						printf("No existe un empleado con el id ingresado.\n");
						break;
					case 3:
						printf("No hay empleados cargados, cargue al menos un empleado para modificar.\n");
						break;
					default:
						printf("Ha habido un error, no se ha podido editar el empleado.\n");
						break;
				}
				break;
			case 5:
				status = controller_removeEmployee(EmployeeList);
				switch (status)
				{
					case 1:
						printf("Se ha eliminado el empleado correctamente.\n");
						break;
					case 2:
						printf("No existe un empleado con el id ingresado.\n");
						break;
					case 3:
						printf("No hay empleados cargados, cargue al menos un empleado para borrar.\n");
						break;
					default:
						printf("Ha habido un error, no se ha podido eliminar el empleado.\n");
						break;
				}
				break;
			case 6:
				status = controller_ListEmployee(EmployeeList);
				if(status == 0)
				{
					printf("Ha habido un error, no se han podido listar los empleados.\n");
				}
				else if(status == 2)
				{
					printf("No hay empleados cargados, cargue al menos un empleado para poder listar.\n");
				}
				break;
			case 7:
				status = controller_sortEmployee(EmployeeList);
				switch (status)
				{
					case 1:
						printf("Se han ordenado los empleados correctamente.\n");
						break;
					case 2:
						printf("No hay empleados cargados, debe haber al menos un empleado para ordenar.\n");
						break;
					default:
						printf("Ha habido un error, no se han podido ordenar los empleados.\n");
						break;
				}
				break;
			case 8:
				status = controller_saveAsText("data.csv", EmployeeList);
				if(status == 1)
				{
					printf("Se han guardado los empleados en el archivo data.csv correctamente.\n");
				}
				else
				{
					printf("Ha habido un error, no se han guardado los empleados correctamente.\n");
				}
				break;
			case 9:
				status = controller_saveAsBinary("data.bin", EmployeeList);
				if(status == 1)
				{
					printf("Se han guardado los empleados en el archivo data.bin correctamente.\n");
				}
				else
				{
					printf("Ha habido un error, no se han guardado los empleados correctamente.\n");
				}
				break;
			case 0:
				ll_deleteLinkedList(EmployeeList);
				break;
		}

	}while(MenuOption > 0);
}

void SortMenu(LinkedList* EmployeeList)
{
	int MenuOption;
	int order;

	MenuOption = getNumberBetween("Ingrese el parametro por el cual ordenar la lista\n1 - Ordenar alfabeticamente por nombre\n2 - Ordenar por horas trabajadas\n3 - Ordenar por sueldo\n", 1, 3);

	order = getNumberBetween("Ingrese 0 para ordenar de menor a mayor o 1 para ordenar de mayor a menor\n", 0, 1);

	switch(MenuOption)
	{
		case 1:
			ll_sort(EmployeeList, employee_CompareByName, order);
			break;
		case 2:
			ll_sort(EmployeeList, employee_CompareByWorkedHours, order);
			break;
		case 3:
			ll_sort(EmployeeList, employee_CompareBySalary, order);
			break;
	}
}
