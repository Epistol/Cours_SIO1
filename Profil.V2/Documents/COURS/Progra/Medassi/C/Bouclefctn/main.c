#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x;
    int compteur;
    int resultat;

    compteur = 0;
    resultat = 0;
    x = 0;


    printf("Resultat pour la fonction 3x+2 \n");

    while (compteur <= 100)
{
    resultat = x*3;
    resultat = resultat+2;
    printf("x = %d", compteur);
    printf("  /  F(x) =  %d\n", resultat);
    x++;
    compteur++;

}

    return 0;
}
