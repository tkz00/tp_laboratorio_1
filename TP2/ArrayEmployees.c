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

#include "ArrayEmployees.h"
#define LIBRE 0
#define OCUPADO 1

/** \brief
 *      Assigns the values states below to the employeeList.
 * \param employeeList Employee*
 *      List of employees where to add the values
 * \param length int
 *      Length of the employee list.
 * \return void
 *
 */
void hardcodeEmployeesArray(Employee* employeeList, int length)
{
    int idArray[LENGTH]={100,101,102,103,104,105};
    char nameArray[LENGTH][51]={"Ale","Franco","Franco","Zeta","Theo","Felix"};
    char lastNameArray[LENGTH][51]={"Maler","DeLocca","LoGuzzo","Zsaselsky","Zsaselsky","Zsaselsky"};
    float salaryArray[LENGTH]={1050.50,2000.00,3777.32,789.12,1020.33,1020.33};
    int sectorArray[LENGTH]={688,484,121,688,999,888};
    int i;
    for(i=0;i<LENGTH;i++)
    {
        employeeList[i].id=idArray[i];
        strcpy(employeeList[i].name,nameArray[i]);
        strcpy(employeeList[i].lastName,lastNameArray[i]);
        employeeList[i].salary = salaryArray[i];
        employeeList[i].sector = sectorArray[i];
        employeeList[i].isEmpty = OCUPADO;
    }
}

/** \brief
 *      Goes through the employee list changing all 'isEmpty' values to LIBRE
 * \param employeeList Employee*
 *      List of employees to change the 'isEmpty' values.
 * \param length int
 *      Length of the employees array.
 * \return int
 *      When getting to the last position of the array it sets the returnValue to 0, indicating no errors, if that condition in not reached -1 is returned, indicating an error.
 */
int initializeEmployees(Employee* employeeList, int length)
{
    int i;
    int returnValue;
    returnValue = -1;
    for(i=0;i<length;i++)
    {
        employeeList[i].isEmpty = LIBRE;
        if(i + 1 == length)
        {
            returnValue = 0;
        }
    }
    return returnValue;
}

/** \brief
 *      Recives all the parameters for a new employee, goes through the employee list, until one position with 'isEmpty' value set to LIBRE, and adds the parameters received at that position.
 * \param employeeList Employee*
 *      List of employees to add the values received to.
 * \param length int
 *      Length of the array of employees.
 * \param id int
 *      id of the new employee to be added to the employee list.
 * \param name[] char
 *      name of the new employee to be added to the employee list.
 * \param lastName[] char
 *      lastName of the new employee to be added to the employee list.
 * \param salary float
 *      salary of the new employee to be added to the employee list.
 * \param sector int
 *      sector of the new employee to be added to the employee list.
 * \return int
 *      After finishing to add every received parameter to the position of the list 'returnValue' is set to 0 indicating a correct execution, if that state is not reached 'returnValue' will be -1,
 *      indicating an error.
 */
int addEmployee(Employee* employeeList, int length, int id, char name[], char lastName[], float salary, int sector)
{
    int i;
    int returnValue;
    returnValue = -1;
    for(i=0;i<length;i++)
    {
        if(employeeList[i].isEmpty == LIBRE)
        {
            employeeList[i].id = id;
            strcpy(employeeList[i].name, name);
            strcpy(employeeList[i].lastName, lastName);
            employeeList[i].salary = salary;
            employeeList[i].sector = sector;
            employeeList[i].isEmpty = OCUPADO;
            returnValue = 0;
            break;
        }
    }
    return returnValue;
}

/** \brief
 *      Cycles through employee array searching for position where id is equal to the id passed as parameter and where 'isEmpty' property is OCUPADO.
 * \param employeeList Employee*
 *      List of employees where to search for id.
 * \param length int
 *      Length of the employee array.
 * \param id int
 *      id to search for in the employee list.
 * \return int
 *      when id is found returnValue is set to the index where the id was found, if the condition is never fulfilled returnValue stays its original value, -1, indicating no employee has the desired id
 */
int findEmployeeIndexById(Employee* employeeList, int length, int id)
{
    int i;
    int returnValue;
    returnValue = -1;
    for(i=0;i<length;i++)
    {
        if(employeeList[i].id == id && employeeList[i].isEmpty == OCUPADO)
        {
            returnValue = i;
        }
    }
    return returnValue;
}


/** \brief
 *      Cycles through the list twice, comparing lastName & sector, sorting the list asending or descending based on the third parameter.
 * \param employeeList Employee*
 *      List of employees to sort.
 * \param length int
 *      Length of the array of employees.
 * \param order int
 *      Integer value specifying whether the sorting must be made descending (0) or asending (1).
 * \return int
 *      Return -1 for error or 0 in every other case.
 */
int sortEmployees(Employee* employeeList, int length, int order)
{
    int i;
    int j;
    if(order == 0)
    {
        for(i=0;i<length-1;i++)
        {
            for(j=i+1;j<length;j++)
            {
                if(employeeList[i].isEmpty == OCUPADO && employeeList[j].isEmpty == OCUPADO)
                {
                    int modify;
                    modify = strcasecmp(employeeList[i].lastName, employeeList[j].lastName);

                    if((modify < 0) || (modify == 0 && employeeList[i].sector < employeeList[j].sector))
                    {
                        swapEmployees(employeeList, i, j);
                    }
                }
            }
        }
        return 0;
    }
    else if(order == 1)
    {
        for(i=0;i<length-1;i++)
        {
            for(j=i+1;j<length;j++)
            {
                if(employeeList[i].isEmpty == OCUPADO && employeeList[j].isEmpty == OCUPADO)
                {
                    int modify;
                    modify = strcasecmp(employeeList[i].lastName, employeeList[j].lastName);

                    if((modify > 0) || (modify == 0 && employeeList[i].sector > employeeList[j].sector))
                    {
                        swapEmployees(employeeList, i, j);
                    }
                }
            }
        }
        return 0;
    }
    return -1;
}

/** \brief
 *      Swaps the elements from the list of the specified positions.
 * \param employeeList Employee*
 *      List of employees where the swap is going to take place
 * \param firstPosition int
 *      first element of the list to be swapped.
 * \param secondPosition int
 *      second element of the list to be swapped.
 * \return void
 *
 */
void swapEmployees(Employee* employeeList, int firstPosition, int secondPosition)
{
    Employee aux;

    aux = employeeList[firstPosition];
    employeeList[firstPosition] = employeeList[secondPosition];
    employeeList[secondPosition] = aux;
}

/** \brief
 *      Cycles through employee array checking for the entry with id equal to employeeId and changes that position's isEmpty property to LIBRE, returns 0 if OK, or -1 for error.
 * \param employeeList Employee*
 *      Array of employees
 * \param length int
 *      length of the array of employees
 * \param employeeId int
 *      id to search for in the list
 * \return int
 *      Return 0 for OK or -1 for error
 *
 */
int removeEmployee(Employee* employeeList, int length, int employeeId)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(employeeList[i].id == employeeId)
        {
            employeeList[i].isEmpty = LIBRE;
            return 0;
        }
    }
    return -1;
}

/** \brief
 *      Prints employee array in columns.
 * \param employeeList Employee*
 *      Employee array
 * \param length int
 *      length of the employee array.
 * \return void
 *
 */
void printEmployees(Employee* employeeList, int length)
{
    int i;
    printf("\n%3s %10.10s %10.10s %9s %6s","Id", "Nombre","Apellido","Sueldo","Sector\n");
    printf("-------------------------------------------------------------------------------\n");
    for(i=0;i<length;i++)
    {
        if(employeeList[i].isEmpty == OCUPADO)
        {
            printf("%3d %10.10s %10.10s $%7.2f %5d\n",employeeList[i].id,employeeList[i].name,employeeList[i].lastName,employeeList[i].salary,employeeList[i].sector);
        }
    }
}

/** \brief
 *      Menu function, prints details of menu options and gets user input, executes required branch of code, exits when input is 0.
 * \param employeeList Employee*
 *      Array of employees for functions.
 * \param length int
 *      Length of employee array.
 * \return void
 *
 */
void menuFunction(Employee* employeeList, int length)
{
    int menuOption;

    do{
        menuOption = getNumberBetween("Ingrese una opcion\n1 - Ingresar un nuevo empleado\n2 - Modificar un empleado por Id\n3 - Eliminar un empleado del sistema por Id\n4 - Informacion empleados y salarios\n0 - Salir del sistema\n",0,4);

        switch(menuOption)
        {
            case 1:
                newEmployee(employeeList, length);
                break;
            case 2:
                ModifyEmployee(employeeList, length);
                break;
            case 3:
                deleteEmployee(employeeList, length);
                break;
            case 4:
                showInformation(employeeList, length);
                break;
            default:
                break;
        }
    }while(menuOption!=0);
}

/** \brief
 *      Prints parameter text, then calls 'getNumber' function, verifies input is between minimum and maximum parameters, if not, asks for input again.
 * \param text char*
 *      Text to print
 * \param minimum int
 *      Minimum number to input
 * \param maximum int
 *      Maximum number to input
 * \return int
 *      Return value input by the user, after being validated.
 */
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

/** \brief
 *      Prints parameter text and asks for int input from user.
 * \param text char*
 *      Text to print.
 * \return int
 *      Return value input by the user.
 */
int getNumber(char* text)
{
    int input;
    printf("%s",text);
    scanf("%d",&input);
    return input;
}

/** \brief
 *      Method gets first empty position in employee list, if at least one is available, it gets user input for new employee attributes, after that passes those to 'addEmployee' method,
 * \param employeeList Employee*
 *      List of employees to insert a new record to.
 * \param length int
 *      Length of the employee list.
 * \return void
 *
 */
void newEmployee(Employee* employeeList, int length)
{
    int emptyIndex;
    emptyIndex = getFirstEmptyIndex(employeeList, length);

    if(emptyIndex > -1)
    {
        int id;
        char name[51];
        char lastName[51];
        float salary;
        int sector;

        id = getNewId(employeeList, length);
        inputString("Ingrese el nombre del nuevo empleado\n", name);
        inputString("Ingrese el apellido del nuevo empleado\n", lastName);
        salary = getFloat("Ingrese el salario del nuevo empleado\n");
        sector = getNumber("Ingrese el numero de sector del nuevo empleado\n");
        addEmployee(employeeList, length, id, name, lastName, salary, sector);
    }
    else
    {
        printf("No hay vacantes para empleados, por favor elimine uno para poder ingresar empleados nuevos.\n");
    }
}

/** \brief
 *      gets the first occurrence of isEmpty == LIBRE in the employee array, returns said index, returns -1 if none position is empty.
 * \param employeeList Employee*
 *      Employee array
 * \param length int
 *      Length of employee array
 * \return int
 *      Returns the position of the first empty element, if no element matches the condition -1 is returned.
 */
int getFirstEmptyIndex(Employee* employeeList, int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(employeeList[i].isEmpty == LIBRE)
        {
            return i;
        }
    }
    return -1;
}

/** \brief
 *      Prints parameter text and gets string from user.
 * \param text char*
 *      Message to print.
 * \param input char*
 *      Pointer to variable where to save input.
 * \return void
 *
 */
void inputString(char* text, char* input){
    printf("%s",text);
    fflush(stdin);
    scanf("%[^\n]",input);
}

/** \brief
 *      Prints parameter text and asks for float input from user.
 * \param text char*
 *      Text to print.
 * \return float
 *
 */
float getFloat(char* text)
{
    float input;
    printf("%s",text);
    scanf("%f",&input);
    return input;
}

/** \brief
 *      Cycles through employee array, searching for highest id in the list, then returns that value plus 1.
 * \param employeeList Employee*
 *      Employee array.
 * \param length int
 *      length of employee array
 * \return int
 *      Returns the id for a new record in the employee list.
 */
int getNewId(Employee* employeeList, int length)
{
    int i;
    int maxId;
    maxId = 0;
    for(i=0;i<length;i++)
    {
        if((i == 0 || employeeList[i].id > maxId) && employeeList[i].isEmpty == OCUPADO)
        {
            maxId = employeeList[i].id;
        }
    }
    return maxId + 1;
}

/** \brief
 *      Gets id to remove from user input, calls 'removeEmployee' function which returns if the function was successful, if not asks for id again because there is no employee with that id,
 *      user can enter -1 to exit functiin without removing any employees.
 * \param employeeList Employee*
 * \param length int
 * \return void
 *
 */
void deleteEmployee(Employee* employeeList, int length)
{
    int activeEmployees;
    activeEmployees = getActiveEmployees(employeeList, length);

    if(activeEmployees>0)
    {
        int idToDelete;
        int exists;

        idToDelete = getNumber("Ingrese el ID que desea eliminar, si desea salir ingrese -1\n");
        exists = removeEmployee(employeeList, length, idToDelete);

        while(exists == -1 && idToDelete != -1)
        {
            printf("No existe un empleado con el ID ingresado.\n");
            idToDelete = getNumber("Ingrese el ID que desea eliminar, si desea salir ingrese -1\n");
            exists = removeEmployee(employeeList, length, idToDelete);
        }

        if(exists == 0 && idToDelete != -1)
        {
            printf("Empleado con ID %d borrado.\n",idToDelete);
        }
    }
    else
    {
        printf("No hay empleados ingresados para borrar, por favor ingrese al menos un empleado para poder borrar.\n");
    }
}

/** \brief
 *      Method verifies at least one record in employee list is OCUPADO, then proceeds to get the id of the employee to modfify and from there its position in the array,
 *      if no employee with inputed id exists, id is asked again, when position is found, user is asked to input which attribute is going to be modified, and calls respective function.
 *      -1 can be inputed to exit the process without making modifications.
 * \param employeeList Employee*
 *      List of employees to moidify one record
 * \param length int
 *      Length of employees array.
 * \return void
 *
 */
void ModifyEmployee(Employee* employeeList, int length)
{
    int activeEmployees;
    activeEmployees = getActiveEmployees(employeeList, length);

    if(activeEmployees>0)
    {
        int idToModify;
        int indexToModify;
        int modifyMenuOption;

        idToModify = getNumber("Ingrese el ID que desea modificar, si desea salir ingrese -1.\n");
        indexToModify = findEmployeeIndexById(employeeList, length, idToModify);

        while(indexToModify == -1 && idToModify != -1)
        {
            printf("No existe un empleado con el ID ingresado.\n");
            idToModify = getNumber("Ingrese el ID que desea modificar, si desea salir ingrese -1.\n");
            indexToModify = findEmployeeIndexById(employeeList, length, idToModify);
        }

        if(indexToModify > -1 && idToModify != -1)
        {
            modifyMenuOption = getNumberBetween("Ingrese el dato que desea modificar\n1 - Modificar el Nombre\n2 - Modificar el apellido\n3 - Modificar el salario\n4 - Modificar el sector.\n0 - Para salir\n",0,4);

            switch(modifyMenuOption)
            {
                case 1:
                    modifyEmployeeName(employeeList, indexToModify);
                    break;
                case 2:
                    modifyEmployeeLastName(employeeList, indexToModify);
                    break;
                case 3:
                    modifyEmployeeSalary(employeeList, indexToModify);
                    break;
                case 4:
                    modifyEmployeeSector(employeeList, indexToModify);
                    break;
            }
        }
    }
    else
    {
        printf("No hay empleados cargados para modificar, por favor ingrese al menos un empleado para modificar.\n");
    }
}

/** \brief
 *      Gets newName from user and saves it to the position received as parameter in the employees array.
 * \param employeeList Employee*
 *      Employee array where the entry to modify is.
 * \param indexToModify int
 *      Position of employee list to change the name to.
 * \return void
 *
 */
void modifyEmployeeName(Employee* employeeList, int indexToModify)
{
    char newName[51];
    inputString("Ingrese el nuevo nombre del empleado\n",newName);
    strcpy(employeeList[indexToModify].name, newName);
}

/** \brief
 *      gets newLastName from user and saves it to the position received as ´parameter in the employees array.
 * \param employeeList Employee*
 *      Employee array where the entry to modify is.
 * \param indexToModify int
 *      Position of employee list to change the lastName to.
 * \return void
 *
 */
void modifyEmployeeLastName(Employee* employeeList, int indexToModify)
{
    char newLastName[51];
    inputString("Ingrese el nuevo apellido del empleado\n",newLastName);
    strcpy(employeeList[indexToModify].lastName,newLastName);
}

/** \brief
 *      gets newSalary from user and saves it to the position received as ´parameter in the employees array.
 * \param employeeList Employee*
 *      Employee array where the entry to modify is.
 * \param indexToModify int
 *      Position of employee list to change the salary to.
 * \return void
 *
 */
void modifyEmployeeSalary(Employee* employeeList, int indexToModify)
{
    float newSalary;
    newSalary = getFloat("Ingrese el nuevo sueldo del empleado\n");
    employeeList[indexToModify].salary = newSalary;
}

/** \brief
 *      gets newSector from user and saves it to the position received as ´parameter in the employees array.
 * \param employeeList Employee*
 *      Employee array where the entry to modify is.
 * \param indexToModify int
 *      Position of employee list to change the sector to.
 * \return void
 *
 */
void modifyEmployeeSector(Employee* employeeList, int indexToModify)
{
    int newSector;
    newSector = getFloat("Ingrese el nuevo sector del empleado\n");
    employeeList[indexToModify].sector = newSector;
}


/** \brief
 *      Gets the count of active employees in employee list, if there are none it is informed and the method is exited, if there is at least one, the list of employees is sorted and printed, also
 *      'showSalaryInformation' method in called.
 * \param employeeList Employee*
 *      Employee list to sort and print information.
 * \param length int
 *      Length of the employee list.
 * \return void
 *
 */
void showInformation(Employee* employeeList, int length)
{
    int activeEmployees;
    activeEmployees = getActiveEmployees(employeeList, length);

    if(activeEmployees>0)
    {
        sortEmployees(employeeList, length, 1);

        printEmployees(employeeList, length);

        showSalaryInformation(employeeList, length);
    }
    else
    {
        printf("No hay empleados cargados, cargue al menos un empleado antes de tratar de hacer esta operacion.\n");
    }
}


/** \brief
 *      Calculates the sum of all the salaries of active employees, also the average salary between all active employees and prints that information.
 * \param employeeList Employee*
 *      Employee List to make calculations in.
 * \param length int
 *      Length of the employees list
 * \return void
 *
 */
void showSalaryInformation(Employee* employeeList, int length)
{
    int activeEmployees;
    float totalSalary;
    float avgSalary;
    int overAvgCount;
    overAvgCount = 0;

    activeEmployees = getActiveEmployees(employeeList, length);

    if(activeEmployees>0)
    {
        totalSalary = getTotalSalary(employeeList, length);
        avgSalary = getDivision(totalSalary, activeEmployees);
        overAvgCount = getOverAvgCount(employeeList, length, avgSalary);
        printf("\nEl total de los salarios es de $%.2f, y el promedio de los salarios es de $%.2f, la cantidad de empleados que superan el promedio de salario es de %d.\n\n",totalSalary,avgSalary,overAvgCount);
    }
    else
    {
        printf("No hay empleados cargados, cargue al menos un empleado antes de tratar de hacer esta operacion.\n");
    }
}


/** \brief
 *      Calculates the sum of the salaries of all active employees.
 * \param employeeList Employee*
 * \param length int
 * \return float
 *
 */
float getTotalSalary(Employee* employeeList, int length)
{
    int i;
    float result;
    result = 0;

    for(i=0;i<length;i++)
    {
        if(employeeList[i].isEmpty == OCUPADO)
        {
            result += employeeList[i].salary;
        }
    }
    return result;
}


/** \brief
 *      Gets the quantity of employees that have 'isEmpty' value set to OCUPADO
 * \param employeeList Employee*
 * \param length int
 * \return int
 *
 */
int getActiveEmployees(Employee* employeeList, int length)
{
    int i;
    int result;
    result = 0;

    for(i=0;i<length;i++)
    {
        if(employeeList[i].isEmpty == OCUPADO)
        {
            result++;
        }
    }
    return result;
}


/** \brief
 *      Gets the result of the division of the first parameter over the second parameter.
 * \param total float
 * \param quantity int
 * \return float
 *
 */
float getDivision(float total, int quantity)
{
    float result;
    if(quantity != 0)
    {
        result = total/quantity;
    }
    return result;
}


/** \brief
 *      Gets quantity of employees that have a salary higher than average.
 * \param employeeList Employee*
 * \param length int
 * \param avgSalary float
 * \return int
 *
 */
int getOverAvgCount(Employee* employeeList, int length, float avgSalary)
{
    int i;
    int result;
    result = 0;
    for(i=0;i<length;i++)
    {
        if(employeeList[i].isEmpty == OCUPADO && employeeList[i].salary>avgSalary)
        {
            result++;
        }
    }
    return result;
}
