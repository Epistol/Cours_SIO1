//

// fonctions.h

// ListeChaineSimple

//

// Created by Sébastien Gagneur on 30/10/2013.

// Copyright (c) 2013 Sébastien Gagneur. All rights reserved.

//

// INTERFACE DES STRUCTURES = DEFINITION DES TYPES PERSONNALISES

// INTERFACE DES FONCTIONS = MODE D'EMPLOI

#ifndef ListeChaineSimple_fonctions_h

#define ListeChaineSimple_fonctions_h

// structure d'un produit

typedef struct produit

{

 int numProduit;

 char libProduit[256];

 float priProduit;

 int catProduit;

 struct produit * suivProduit;



};

// structure des pointeurs afin de faire du passage de paramètre qui fonctionne

typedef struct pointeurs

{

 struct produit * debut;

 struct produit * fin;

};



// interface des fonctions. Le mode d'emploi

// création d'un nouveau produit

struct produit * creerProduit();

// insertion du produit dans la liste

struct pointeurs * inserProduit(struct produit * unProduit, struct

produit * debut, struct produit * fin);

// affichage du produit courant

void afficProduit(struct produit * unProduit);

// affichage complet de la liste

void listeProduit();

// affichage du nombre de produit contenu dans la liste

#endif

// Séquence code couleur :

//http://en.wikipedia.org/wiki/ANSI_escape_code

// Exemple d'affichage des couleurs :

//http://www.developpez.net/forums/d1051487/c-cpp/c/debuter/printf-
