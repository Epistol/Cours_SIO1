#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct Joueur Joueur;
struct Joueur
{
    char nom[30];
    char sexe[10];
    char origine[40];

    int courage;
    int intelligence;
    int charisme;
    int adresse;
    int force;

    int niveau;
    int experience;

    int pieceOr;
    int pieceArgent;
};

/*************************************************************/

typedef struct equipement equipement;
struct equipement
{
    int sac;
};

/*************************************************************/

typedef struct Combat Combat;
struct Combat
{
    int attaque;
    int parade;
    int degat;
    int protection;
};


#endif // STRUCTURE_H_INCLUDED
