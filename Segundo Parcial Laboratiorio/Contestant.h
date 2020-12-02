/**
 	 THEO KATZ
 	 1°B
 	 SEGUNDO PARCIAL
 	 TEMA 2
 */

typedef struct{
    int id;
    int YearOfBirth;
    char Name[50];
    char Dni[10];
    char PresentationDate[12];
    char PresentationTheme[30];
    int FirstRoundScore;
    int SecondRoundScore;
    float AverageScore;
    int ThirdRoundScore;
}Contestant;

Contestant* contestant_new();
Contestant* contestant_newParametros(char* strId, char* strYearOfBirth, char* Name, char* strdni, char* strPresentationDate, char* PresentationTheme, char* strFirstRoundScore);

int Contestant_setId(Contestant* this, int id);
int Contestant_getId(Contestant* this, int* id);

int Contestant_setYearOfBirth(Contestant* this, int yearOfBirth);
int Contestant_getYearOfBirth(Contestant* this, int* yearOfBirth);

int Contestant_setName(Contestant* this, char* name);
int Contestant_getName(Contestant* this, char* name);

int Contestant_setDni(Contestant* this, char* dni);
int Contestant_getDni(Contestant* this, char* dni);

int Contestant_setPresentationDate(Contestant* this, char* presentationDate);
int Contestant_getPresentationDate(Contestant* this, char* presentationDate);

int Contestant_setPresentationTheme(Contestant* this, char* presentationTheme);
int Contestant_getPresentationTheme(Contestant* this, char* presentationTheme);

int Contestant_setFirstRoundScore(Contestant* this, int firstRoundScore);
int Contestant_getFirstRoundScore(Contestant* this, int* firstRoundScore);

int Contestant_setSecondRoundScore(Contestant* this, int secondRoundScore);
int Contestant_getSecondRoundScore(Contestant* this, int* secondRoundScore);

int Contestant_setAverageScore(Contestant* this, float avgScore);
int Contestant_getAverageScore(Contestant* this, float* avgScore);

int Contestant_setThirdRoundScore(Contestant* this, int thirdRoundScore);
int Contestant_getThirdRoundScore(Contestant* this, int* thirdRoundScore);

int Contestant_CompareByFirstScore(void* c1, void* c2);

int Contestant_CompareByThirdScore(void* c1, void* c2);

void printContestantFromPointer(Contestant* this);

void printContestantFromPointerWithScores(Contestant* this);

void printContestants(LinkedList* pArrayListContestants);

void printContestantsWithScores(LinkedList* pArrayListContestants);

void* SetScore(void* this);
