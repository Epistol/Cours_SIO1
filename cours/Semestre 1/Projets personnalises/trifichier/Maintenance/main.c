#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
    {
        int num_produit;
        char libelle[30];
        float prix;
    }produit;
    produit unProduit;

int menu()
{
    int type;
    printf("* Gestion des produits *\n\n1 : Création\n2 : Modification\n3 : Suppression\n4 : Visualisation\n5 : Fermer le programme\n\nchoix : ");
    scanf("%d",&type);
    system("cls");
    return type;
}

void creation(produit *tabProduit, int k)
{
    int i=0;
    int j=0;
    int nombre = 0;
    FILE*fichier;

    printf("nombre de valeur à ajouter :");
    scanf("%d", &nombre);
    fichier = fopen("Produit", "a");

    while (i<nombre)
    {
        printf("Entrez le numéro de produit : ");
        scanf("%d", &unProduit.num_produit);

        int modif = 0;
        for(j=0;j<k;j++)
        {
            if (unProduit.num_produit == tabProduit[j].num_produit)
            {
                unProduit.num_produit =  unProduit.num_produit + 1;
                j=1;
                modif = 1;
            }
        }
        if (modif == 1)
        {
            printf("votre numéro de produit est déjà existant, il a été remplacé par : %d\n\n", unProduit.num_produit);
        }
        printf("Entrez le libellé du produit : ");
        scanf("%s", unProduit.libelle);
        printf("Entrez le prix du produit : ");
        scanf("%f", &unProduit.prix);
        fwrite(&unProduit,sizeof(produit),1, fichier);
        i++;
        k++;
     }
     fclose(fichier);
}

void modification(produit *tabProduit,int k)
{
    FILE*fichProduit;
    int i=0;
    char libelle[30];
    int resultat;
    printf("libellé produit à modifier : ");
    scanf("%s", libelle);
    int il_y_a = 0;
    for (i=0;i<k;i++)
    {
        resultat = strcmp(tabProduit[i].libelle, libelle);
        if (resultat == 0)
        {
            printf("nouveau libellé du produit : ");
            scanf("%s", tabProduit[i].libelle);
            printf("nouveau prix du produit : ");
            scanf("%f", &tabProduit[i].prix);
            il_y_a = 1;
        }
    }
    if (il_y_a == 0)
    {
        printf("\n * Votre produit n'existe pas, veuillez le créer avant modification * \n");
    }
    fichProduit = fopen("Produit","w");

    for (i=0;i<k;i++)
    {
        unProduit.num_produit = tabProduit[i].num_produit;
        strcpy(unProduit.libelle , tabProduit[i].libelle);
        unProduit.prix = tabProduit[i].prix;
        fwrite(&unProduit,sizeof(unProduit),1, fichProduit);
    }
    fclose(fichProduit);

}

void suppresion(produit *tabProduit, int k)
{
    FILE*fichProduit;
    int i=0;
    int plusUn = 0;
    char libelle[30];
    int resultat;
    printf("libellé produit à supprimer : ");
    scanf("%s", libelle);
    for (i=0;i<k;i++)
    {
        resultat = strcmp(tabProduit[i].libelle, libelle);
        if (resultat != 0)
        {
            tabProduit[plusUn].num_produit = tabProduit[i].num_produit;
            strcpy(tabProduit[plusUn].libelle, tabProduit[i].libelle);
            tabProduit[plusUn].prix = tabProduit[i].prix;
            plusUn++;
        }
        else
        {
            printf("Fichier supprimé");
        }
    }
    fclose(fichProduit);
    remove(fichProduit);
    fichProduit = fopen("Produit","w");

    for (i=0;i<k-1;i++)
    {
        unProduit.num_produit = tabProduit[i].num_produit;
        strcpy(unProduit.libelle , tabProduit[i].libelle);
        unProduit.prix = tabProduit[i].prix;
        printf("\n%s", unProduit.libelle);
        fwrite(&unProduit,sizeof(unProduit),1, fichProduit);
    }
    fclose(fichProduit);
}

void visualisation(produit *tabProduit, int j)
{
        int i;
        for (i=0;i<j;i++)
        {
            printf("num_produit : %d \n libellé : %s \n prix : %f \n\n",tabProduit[i].num_produit, tabProduit[i].libelle, tabProduit[i].prix);
        }
}

int main()
{
    system("mode con codepage select=1252"); // acceptation des accents
    system("cls"); // vidage de la console
    int continuer = 1;
    while(continuer)
    {
        FILE*fichProduit;
        produit tabProduit[100];
        int choix;
        int i;
        int j;

        fichProduit = fopen("Produit","r");

        fread(&unProduit,sizeof(produit),1,fichProduit);
        i=0;
        while(!feof(fichProduit))
        {
            tabProduit[i].num_produit = unProduit.num_produit;
            strcpy(tabProduit[i].libelle, unProduit.libelle);
            tabProduit[i].prix = unProduit.prix;
            i++;

            fread(&unProduit,sizeof(produit),1,fichProduit);
        }
            j = i;
        fclose(fichProduit);

    // choix
        choix = menu();

        if(choix == 1)
        {
            printf("%d",j);
            creation(tabProduit,j);
            system("pause");
        }
        else if (choix == 2)
        {
            modification(tabProduit, j);
            system("pause");
        }
        else if (choix == 3)
        {
            suppresion(tabProduit, j);
            system("pause");
        }
        else if (choix == 4)
        {
            visualisation(tabProduit, j);
            system("pause");
        }
        else
        {
            continuer = 0;
        }
        system("cls");
    }
    return 0;
}
