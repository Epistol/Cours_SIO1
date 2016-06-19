//

// fonctions.c

// ListeChaineSimple

//

// Created by S�bastien Gagneur on 30/10/2013.

// Copyright (c) 2013 S�bastien Gagneur. All rights reserved.

//

// IMPLEMENTATION DES FONCTIONS = CODE DES FONCTIONS

// Directives du pr�processeur pour g�rer les inclusions multiples

#ifndef ListeChaineSimple_fonctions_c

#define ListeChaineSimple_fonctions_c

// Ce dont j'ai besoin ici !

#include "fonction.h"

#include <stdlib.h>

//impl�mentation des fonctions

//cr�er un produit

struct produit * creerProduit()

{

 // allocation dynamique qui permet d'allouer un nouvel emplacement pour chaque nouveau produit cr��

 // si vous ne mettez pas l'allocation dynamique, le produit est une variable statique, et l'emplacement,

 // l'adresse du produit ne change jamais, si bien, que chaque produit cr�� remplace le pr�c�dent.

 // Dans ce cas les nouveaux produits cr��s ne remplacent pas les npr�c�dents, ils sont plac�s � des

 // adresses diff�rentes.



 struct produit * unProduit = malloc(sizeof(struct produit));



 printf("Code produit ?:");

 scanf("%d",&unProduit->numProduit);

 printf("Libell� produit ?:");

 scanf("%s",&unProduit->libProduit);

 printf("Prix produit ?:");

 scanf("%f",&unProduit->priProduit);

 printf("Cat�gorie produit ?:");

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

// Ins�rer un produit

struct pointeurs * inserProduit(struct produit * unProduit, struct

produit * debut, struct produit * fin)

{

 // structure pour r�cup�rer mes pointeurs, la fonction ne retournant pas mes modifications

 struct pointeurs mesPointeurs;

 // Si la liste ne contient pas de produit

 if ( debut == NULL)

 {

 // le seul est unique produit, constitue la d�but et la fin de la liste

 debut = unProduit;

 fin = unProduit;

 }

 else

 // La liste contient d�j� au moins un produit, et donc cette fois il faut faire le cha�nage

 {

 // le dernier produit de liste � pour suivant le nouveau produit

 fin->suivProduit = unProduit;

 // le dernier produit, constitue la nouvelle fin

 fin = unProduit;

 }

 // je mets � jour ma structure pour faire remonter dans le programme principal mes modifications sur

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



 // tant que l'adresse du produit que je traite est diff�rente de l'adresse du dernier produit je traite

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
