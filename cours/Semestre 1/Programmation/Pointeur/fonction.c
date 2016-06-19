//

// fonctions.c

// ListeChaineSimple

//

// Created by Sébastien Gagneur on 30/10/2013.

// Copyright (c) 2013 Sébastien Gagneur. All rights reserved.

//

// IMPLEMENTATION DES FONCTIONS = CODE DES FONCTIONS

// Directives du préprocesseur pour gérer les inclusions multiples

#ifndef ListeChaineSimple_fonctions_c

#define ListeChaineSimple_fonctions_c

// Ce dont j'ai besoin ici !

#include "fonction.h"

#include <stdlib.h>

//implémentation des fonctions

//créer un produit

struct produit * creerProduit()

{

 // allocation dynamique qui permet d'allouer un nouvel emplacement pour chaque nouveau produit créé

 // si vous ne mettez pas l'allocation dynamique, le produit est une variable statique, et l'emplacement,

 // l'adresse du produit ne change jamais, si bien, que chaque produit créé remplace le précédent.

 // Dans ce cas les nouveaux produits créés ne remplacent pas les nprécédents, ils sont placés à des

 // adresses différentes.



 struct produit * unProduit = malloc(sizeof(struct produit));



 printf("Code produit ?:");

 scanf("%d",&unProduit->numProduit);

 printf("Libellé produit ?:");

 scanf("%s",&unProduit->libProduit);

 printf("Prix produit ?:");

 scanf("%f",&unProduit->priProduit);

 printf("Catégorie produit ?:");

 scanf("%d",&unProduit->catProduit);

 // Le procuit suivant n'est pas encore connu !

 unProduit->suivProduit = NULL;

 return unProduit;

}

// Afficher un produit

void affichProduit(struct produit * unProduit)

{

 printf("num : %d lib : %s prix : %f cat : %d \n",unProduit->numProduit, unProduit-> libProduit, unProduit-> priProduit,unProduit->catProduit);

}

// Insérer un produit

struct pointeurs * inserProduit(struct produit * unProduit, struct

produit * debut, struct produit * fin)

{

 // structure pour récupérer mes pointeurs, la fonction ne retournant pas mes modifications

 struct pointeurs mesPointeurs;

 // Si la liste ne contient pas de produit

 if ( debut == NULL)

 {

 // le seul est unique produit, constitue la début et la fin de la liste

 debut = unProduit;

 fin = unProduit;

 }

 else

 // La liste contient déjà au moins un produit, et donc cette fois il faut faire le chaînage

 {

 // le dernier produit de liste à pour suivant le nouveau produit

 fin->suivProduit = unProduit;

 // le dernier produit, constitue la nouvelle fin

 fin = unProduit;

 }

 // je mets à jour ma structure pour faire remonter dans le programme principal mes modifications sur

 // mes pointeurs

 mesPointeurs.debut = debut;

 mesPointeurs.fin = fin;

 return &mesPointeurs;

}

// Parcourir la liste

void listeProduit(struct produit * debut, struct produit * fin)

{

 // le pointeur sur le produit courant

 struct produit * courant;



 // le produit courant est le premier

 courant = debut;



 // tant que l'adresse du produit que je traite est différente de l'adresse du dernier produit je traite

 while (courant != fin)

 {

 // j'affiche le produit courant

 affichProduit(courant);

 // le nouveau produit courant, est le produit suivant du produit courant !

 courant = courant->suivProduit;

 }

 // Si vous voulez voir le dernier !

 affichProduit(courant);



}

#endif
