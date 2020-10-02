/**
    THEO KATZ

    Una empresa requiere un sistema para administrar su nómina de empleados.
    El sistema deberá tener el siguiente menú de opciones:
        1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
        de Id. El resto de los campos se le pedirá al usuario.
        2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
        o Salario o Sector
        3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
        4. INFORMAR:
            1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
            2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
    NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
    Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
    carga de algún empleado.
    Para la realización de este programa, se utilizará una biblioteca llamada “ArrayEmployees” que
    facilitará el manejo de la lista de empleados y su modificación. En la sección siguiente se
    detallan las funciones que esta biblioteca debe tener.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define LENGTH 6

///Declaration of structure "Employee".
typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

void hardcodeEmployeesArray(Employee* employeeList, int length);

int initializeEmployees(Employee* employeeList, int length);

void menuFunction(Employee* employeeList, int length);

int addEmployee(Employee* employeeList, int length, int id, char name[], char lastName[], float salary, int sector);

void newEmployee(Employee* employeeList, int length);

void ModifyEmployee(Employee* employeeList, int length);

int sortEmployees(Employee* employeeList, int length, int order);

void swapEmployees(Employee* employeeList, int firstPosition, int secondPosition);

int removeEmployee(Employee* employeeList, int length, int employeeId);

void deleteEmployee(Employee* employeeList, int length);

int findEmployeeIndexById(Employee* employeeList, int length, int id);

int getFirstEmptyIndex(Employee* employeeList, int length);

int getNewId(Employee* employeeList, int length);

void printEmployees(Employee* employeeList, int length);

int getNumber(char* text);

int getNumberBetween(char* text,int minimum, int maximum);

void inputString(char* text, char* input);

float getFloat(char* text);

void modifyEmployeeName(Employee* employeeList, int indexToModify);

void modifyEmployeeLastName(Employee* employeeList, int indexToModify);

void modifyEmployeeSalary(Employee* employeeList, int indexToModify);

void modifyEmployeeSector(Employee* employeeList, int indexToModify);

void showInformation(Employee* employeeList, int length);

void showSalaryInformation(Employee* employeeList, int length);

int getActiveEmployees(Employee* employeeList, int length);

float getTotalSalary(Employee* employeeList, int length);

float getDivision(float total, int quantity);

int getOverAvgCount(Employee* employeeList, int length, float avgSalary);
