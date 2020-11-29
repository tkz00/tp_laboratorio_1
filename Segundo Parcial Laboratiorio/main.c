/**
 	 THEO KATZ
 	 1°B
 	 SEGUNDO PARCIAL
 	 TEMA 2
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Contestant.h"
#include "Menu.h"
#include "Common.h"

int main()
{
    setbuf(stdout, 0);

    LinkedList* ContestantList = ll_newLinkedList();

    MenuFunction(ContestantList);

    return 0;
}
