#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char libelle [255], encore;
    float prix,stock1,stock2;
    int qte;

    stock1 = 0;
    stock2 = 0;
    encore = 'O';


    while (encore == 'O') {
        printf("libelle?\n");
        scanf ("%s",&libelle);
        printf ("prix?\n");
        scanf ("%f",&prix);
        printf ("Qte?\n");
        scanf ("%d",&qte);
        stock1 = qte*prix;
        stock2 = stock2 + stock1;
        printf ("\n Stock=%f",stock2);
        printf ("\n Total=%f",qte*prix);
        printf ("Voulez-vous recommencer (O/N)?\n");
        scanf ("%s",&encore);

    }



return 0;
}
