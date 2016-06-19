#include <stdio.h>
#include <stdlib.h>

int main()
{

        char libelle;
        float prix;
        int rep,qte,cumul;


        printf("Voulez vous faire une facture ? o/n \n");
        rep=getch();
        printf("%d",rep);

        while (rep == 111 || rep == 79) {
            if (rep == 111 || rep == 79)
            {
                printf("libelle?\n");
                scanf("%s",&libelle);
                printf("prix?\n");
                scanf("%f",&prix);
                printf("Qte?\n");
                scanf("%d",&qte);
                cumul=qte*prix;
                printf("Cumul =%d",cumul);
                printf ("total=%f",qte*prix);
                printf("Voulez vous continuer ? o/n \n");
                rep=getch();
            }
            }

return 0;
}

