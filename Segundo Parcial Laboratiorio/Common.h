/**
 	 THEO KATZ
 	 1°B
 	 SEGUNDO PARCIAL
 	 TEMA 2
 */

#include "LinkedList.h"

/** \brief
 *      Prints parameter text and asks for int input from user.
 * \param text char*
 *      Text to print.
 * \return int
 *      Return value input by the user.
 */
int getNumber(char* text);

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
int getNumberBetween(char* text,int minimum, int maximum);

/** \brief
 *      Prints parameter text and asks por char input from user
 * \param text char*
 *      Text to print
 * \return char
 *      Return value input by the user.
 */
char getChar(char* text);

/** \brief
 *      Prints parameter text and gets string from user.
 * \param text char*
 *      Message to print.
 * \param input char*
 *      Pointer to variable where to save input.
 * \return void
 *
 */
void inputString(char* text, char* input);

/** \brief validate if string has only letters
 *
 * \param str[] char
 * \return int return 1(true) - 0(false)
 *
 */
int isOnlyLetters(char str[]);

/** \brief Validate if string has only numbers
 *
 * \param str[] char
 * \return int return 1(true) - 0(false)
 *
 */
int isANumber(char str[]);

int getPositiveNumber(char* text);

int getNewId(LinkedList* pArrayListEmployee);

int getEmployeeIndexById(LinkedList* pArrayListEmployee, int id);
