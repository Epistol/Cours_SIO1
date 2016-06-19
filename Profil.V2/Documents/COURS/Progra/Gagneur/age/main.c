#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{
    int anneeentree,year;

    year = 2015;
    anneeentree = 0;

    printf("Quel est votre annee de naissance?\n");
    scanf ("%d",&anneeentree);
    year = year - anneeentree;
    printf("Votre age : %d", year);

return 0;
    }





