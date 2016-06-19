#include <stdio.h>
#include <stdlib.h>

int main()
{

    int table;
    int compteur;
    int resultat;

    compteur = 0;
    resultat = 0;
    table = 1;




    while (table <= 10)
{
    printf("Resultat pour la table %d \n", table);

    while (compteur <=10) {

    resultat = table*compteur;

    printf("%d", table);
    printf(" x %d", compteur);
    printf(" =  %d\n", resultat);
    resultat = 0;
    compteur++;


    }

    compteur = 0;
    table++;
    printf("\n");
    }

    return 0;
}
