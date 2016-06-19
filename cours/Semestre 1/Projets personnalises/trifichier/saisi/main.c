#include <stdio.h>
#include <stdlib.h>

typedef struct
    {
        int num_produit;
        char libelle[30];
        float prix;
    }produit;
    produit unProduit;

int main()
{
    FILE *fichier; /* pointeur sur FILE */
  char nomFichier[30];
  int  i;
  int nombreEnregistrement;

  /* Créer et remplir le fichier */
  printf("Entrez le nom du fichier à créer : ");
  scanf("%s", nomFichier);
  fichier = fopen(nomFichier, "w");  /* write */
  printf("Nombre d'enregistrements à créer : ");
  scanf("%d", &nombreEnregistrement);
  i = 0;
  while (i<nombreEnregistrement)
     {
      printf("Entrez le numero de produit : ");
      scanf("%d", &unProduit.num_produit);
      printf("Entrez le libelle de produit : ");
      scanf("%s", unProduit.libelle);
      printf("Entrez le prix de produit : ");
      scanf("%f", &unProduit.prix);
      fwrite(&unProduit,sizeof(produit),1, fichier);
      i++;
     }
  fclose(fichier);
}
