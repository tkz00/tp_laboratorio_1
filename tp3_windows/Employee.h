/**
 	 THEO KATZ
 	 1°B
 	 TP3
 */

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
/// PORQUE ESTA FUNCION ES CON CHAR??
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_CompareById(Employee* e1, Employee* e2);
int employee_CompareByName(void* e1, void* e2);
int employee_CompareByWorkedHours(void* e1, void* e2);
int employee_CompareBySalary(void* e1, void* e2);

void printEmployeeFromPointer(Employee* this);

void ModifyEmployee(Employee* this);

void DeleteEmployee(Employee* this);

void ModifyName(Employee* this);

void ModifyWorkedHours(Employee* this);

void ModifySalary(Employee* this);

#endif // employee_H_INCLUDED
