#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{
    int anneeentree,year;

    year = 2015;
    anneeentree = 0;

    printf("Annee?\n");
    scanf ("%d",&anneeentree);
    year = year - anneeentree;
    printf("Vous avez : %d", year);

return 0;
    }





