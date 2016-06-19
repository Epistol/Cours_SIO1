#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int anneeuser;
    int annee;
    int age;
    int tm_year;


    time_t t1;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Date: %d-%d-%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    printf("Votre annee de naissance? (aaaa)\n");
    scanf ("%d",&anneeuser);
    age = tm.tm_year+1900-anneeuser;
    printf ("Age=%d\n", age);
    return 0;
}
