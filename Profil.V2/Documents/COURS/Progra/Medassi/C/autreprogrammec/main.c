#include <stdio.h>
#include <stdlib.h>

int main()
{

    char valide = "z";

        char libelle [255];
        float prix;
        int qte;
do {


        printf("libelle?\n");
        scanf ("%s",&libelle);
        printf ("prix?\n");
        scanf ("%f",&prix);
        printf ("Qte?\n");
        scanf ("%d",&qte);
        printf ("total=%f",qte*prix);
        printf("\n Continuer (o/n) ?\n");
        scanf ("%s ",&valide);
        } while (valide = "o");









return 0;
}
