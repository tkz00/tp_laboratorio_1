/**
 	 THEO KATZ
 	 1°B
 	 SEGUNDO PARCIAL
 	 TEMA 2
 */

int controller_loadFromText(LinkedList* pArrayListContestant, char* path);

int controller_ListContestants(LinkedList* pArrayListContestant);

int controller_JuryFunction(LinkedList* pArrayListContestant, char* path);

int controller_FilterContestants(LinkedList* pArrayListContestant);

int controller_FilterFinalists(LinkedList* pArrayListContestant);

int controller_FilterThirdScoreFinalists(LinkedList* pArrayListContestant);

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

float getHighestAverageScore(LinkedList* pArrayListContestant);

int hasHighestAverageScore(void* this, float highestAverageScore);

void SaveContestantsMultipleFiles(LinkedList* pArrayListContestant);

int hasEqualOrHigherFirstScore(void* this, int highestFirstScore);

int hasEqualOrHigherThirdScore(void* this, int highestThirdScore);
