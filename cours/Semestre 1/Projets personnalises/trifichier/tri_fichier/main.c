#include <stdio.h>
#include <stdlib.h>

typedef struct
    {
        int num_produit;
        char libelle[30];
        float prix;
    }produit;
    produit unProduit;

void echange(produit *tabproduit, int i)
{
    int num;
    char lib[30];
    int prix;

    num = tabproduit[i].num_produit;
    strcpy(lib, tabproduit[i].libelle);
    prix = tabproduit[i].prix;

    tabproduit[i].num_produit = tabproduit[i+1].num_produit;
    strcpy(tabproduit[i].libelle, tabproduit[i+1].libelle);
    tabproduit[i].prix = tabproduit[i+1].prix;

    tabproduit[i+1].num_produit = num;
    strcpy(tabproduit[i+1].libelle, lib);
    tabproduit[i+1].prix = prix;
}

void triFichier(produit *tabProduit, int sens, int j)
{
    int permut;
    permut = 1;
    int i;

    while (permut ==1)
    {
        permut = 0;
        for(i =0; i<j-1;i++)
        {
            if(sens==1)
            {
                if(tabProduit[i].num_produit > tabProduit[i+1].num_produit)
                {

                    echange(tabProduit, i);
                    permut = 1;
                }
            }
            else if (sens == 2)
            {
                if(tabProduit[i].num_produit < tabProduit[i+1].num_produit)
                {
                    echange(tabProduit, i);
                    permut = 1;
                }
            }
        }
    }
}

int main()
{
    system("mode con codepage select=1252"); // acceptation des accents
    system("cls"); // vidage de la console

    FILE*fichProduit;
    produit tabProduit[100];
    int i;
    int sens = 1;
    int j;
    int type;

    fichProduit = fopen("Produit","r");

    printf("Tri Croissant(1) ou décroissant(2) ? : ");
    scanf("%d", &sens);
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
    triFichier(tabProduit, sens,j);
    remove(fichProduit);
    fichProduit = fopen("Produit","w");

    for (i=0;i<j;i++)
    {
        printf("num_produit : %d \n libelle : %s \n prix : %f \n\n",tabProduit[i].num_produit, tabProduit[i].libelle, tabProduit[i].prix);
        unProduit.num_produit = tabProduit[i].num_produit;
        strcpy(unProduit.libelle , tabProduit[i].libelle);
        unProduit.prix = tabProduit[i].prix;
        fwrite(&unProduit,sizeof(unProduit),1, fichProduit);
    }
    fclose(fichProduit);
}
