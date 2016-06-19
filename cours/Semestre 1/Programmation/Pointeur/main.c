//

// main.c

// ListeChaineSimple

//

// Created by Sébastien Gagneur on 30/10/2013.

// Copyright (c) 2013 Sébastien Gagneur. All rights reserved.

//

#include <stdio.h>

#include <string.h>

#include "fonction.h"
#include "fonction.c"

// Programme principal

int main(int argc, const char * argv[])

{

 // les structures utilisées

 struct produit * unProduit;

 struct pointeurs * mesPointeurs;

 struct produit * debut = NULL;

 struct produit * fin = NULL;

 char reponse[4] = "oui";



 // Codes couleurs présentés dans le fichier d'interface

 printf ("\033[32;01mListe Chaine Simple\033[00m\n");



 // la boucle pour gérer n produit

 while (strcmp(reponse,"oui") == 0)

 {

 // création d'un produit

 unProduit = creerProduit();

 // insertion d'un produit

 mesPointeurs = inserProduit(unProduit, debut, fin);

 // mise à jour des pointeurs, pour avoir connaissance des nouvelles valeurs

 debut = mesPointeurs->debut;

 fin = mesPointeurs->fin;

 printf("Autre produit (oui/non) : ?");

 scanf("%s",&reponse);

 }

 // Affichage de la liste constituée

 listeProduit(debut,fin);

 return 0;

}
