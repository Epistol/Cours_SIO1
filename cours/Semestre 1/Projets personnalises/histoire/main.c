#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structure.h"

int main(int argc, char *argv[])
{
/*************/
/* VARIABLES*/
/*************/

    system("mode con codepage select=1252"); // acceptation des accents
    system("cls"); // vidage de la console

    FILE *foire = NULL; // creation du pointeur foire
    foire = fopen("foirederavsgalatjeu.txt", "r"); // ouverture du fichier foirederavsgalat
    char texte; // chaine de caractère
    char Paragraphe[309][5000]; // [nombre de paragraphe][nombre de caractere maximal environ pour 1 paragraphe]
    int i = 0;
    int j= 1;
    int k = 0;
    int choix = 308; // notre choix de paragraphe (commnce par le paragraphe 1)
    int choixPossible[20] = {0}; // nombre de choix possible
    int fin = 0;
    int lancerDes = 0;

    Joueur utilisateur;

    utilisateur.niveau = 1;
    utilisateur.experience = 0;
/***********************************************/
/* Stockage de tout les paragraphes du fichier */
/***********************************************/
{
    while (texte != '#') // tant que la variable texte ne contient pas le caractère '#'
    {
        texte = fgetc(foire); // On lit le caractère suivant
    }
    texte = fgetc(foire); // On lit le caractère suivant

    for (j=1; j<309; j++)
    {
        i=0;
        while (texte != '#') // Attend le prochain '#'
    {
        Paragraphe[j][i] = texte; // ajoute le caractere au paragraphe
        texte = fgetc(foire); // On lit le caractère suivant
        i++;
    }
        texte = fgetc(foire); // On lit le caractère suivant
    }

    fclose(foire); // liberation de la memoire en fermant le fichier texte
}
/**********************/
/*Debut de l'histoire*/
/*********************/
{
    printf("Nous sommes heureux de vous présenter notre programme éditer par Alexandre Rieu et Baptiste Romero.\nCe programme reprend l'histoire de La Foire de Ravsgalat, mais avec certaines modifications et quelques ajouts tels que le paragraphe de FIN.\n\nAmusez-vous bien : D\n\n");
    system("pause");
    system("cls");
    printf("nom du personnage : ");
    scanf("%s", utilisateur.nom);

    printf("Sexe (homme/autre) : ");
    scanf("%s", utilisateur.sexe);
    while (strcmp(utilisateur.sexe,"homme"))
    {
        if (!strcmp(utilisateur.sexe,"autre"))
        {
            printf("\n 'autre' n'est pas valide");
            printf("\nSexe (homme/autre) : ");
            scanf("%s", utilisateur.sexe);
        }
        else
        {
        printf("\nSexe (homme/autre) : ");
        scanf("%s", utilisateur.sexe);
        }
    }
}
/*******************/
/*FORTUNE DE DEPART*/
/*******************/
{
/*  system("cls");
    printf("\nFortune de départ :\n\n");
    printf("Pour connaître votre fortune de départ, il faut jouer a un jeu.\n Trouvez un chiffre entre 0 et 100\n");
    printf("Vous commencez avec 120PO, vous perdez 10PO par coups\n");
    printf("Arrivé à 20 PO, le jeu s'arrête et vous commencerez l'histoire avec 20 PO.\n\n");

    {
        utilisateur.pieceOr = 120;
        int continuer = 1;
        int nombreAlea = 0;
        int choixNombre = 0;
        srand(time(NULL));
        nombreAlea = (rand() % (100 - 0 + 1));
        printf("Votre nombre : ");
        scanf("%d", &choixNombre);
        while (continuer)
        {
            system("cls");
            printf("\nFortune de départ :\n\n");
            printf("Pour connaître votre fortune de départ, il faut jouer a un jeu.\n Trouvez un chiffre entre 0 et 100\n");
            printf("Vous commencez avec 120PO, vous perdez 10PO par coups\n");
            printf("Arrivé à 20 PO, le jeu s'arrête et vous commencerez l'histoire avec 20 PO.\n\n");

            if (utilisateur.pieceOr <= 20)
            {
                utilisateur.pieceOr = 20;
                printf("\nVous avez Perdu.");
                printf("\nvous commencez l'histoire avec %d PO\n\n", utilisateur.pieceOr);
                continuer = 0;
            }
            else if (choixNombre < nombreAlea)
            {
                printf("c'est plus");
                utilisateur.pieceOr -= 10;

                printf("\nPiece d'or restant : %d\n", utilisateur.pieceOr);
                printf("Votre nombre : ");
                scanf("%d", &choixNombre);
            }
            else if (choixNombre > nombreAlea)
            {
                printf("c'est moins");
                utilisateur.pieceOr -= 10;

                printf("\nPiece d'or restant : %d\n", utilisateur.pieceOr);
                printf("Votre nombre : ");
                scanf("%d", &choixNombre);
            }
            else if (choixNombre == nombreAlea)
            {
                printf("\nVous avez trouver.");
                printf("\nvous commencez l'histoire avec %d PO\n\n", utilisateur.pieceOr);
                continuer = 0;
            }

        }
    }
    system("pause"); */

}


while (fin == 0)
{

/*************************/
/*Affichage du paragraphe*/
/*************************/
{
    system("cls"); // vidage de la console
    printf("\t\t\t\t\t PARAGRAPHE %s", Paragraphe[choix]); // Affichage du paragraphe
    choix = 0;
}
/**************************************************/
/*Stockage des choix possible du paragraphe choisi*/
/**************************************************/
{
    i =0;
    j =1;
    k=0;

    for(i=0; Paragraphe[choix][i] != '\0' ; i++)    // temps que le paragraphe n'est pas a sa fin
    {
        j = 1;
        if (Paragraphe[choix][i] == '@') // si le caractere est '@'
        {
            k++;
            i++; // caractère suivant
            while (Paragraphe[choix][i] == '0' || Paragraphe[choix][i] == '1' || Paragraphe[choix][i] == '2' || Paragraphe[choix][i] == '3' || Paragraphe[choix][i] == '4' || Paragraphe[choix][i] == '5' || Paragraphe[choix][i] == '6' || Paragraphe[choix][i] == '7' || Paragraphe[choix][i] == '8' || Paragraphe[choix][i] == '9')
            {
                if (j != 1)
                {
                    choixPossible[k] *= 10; // concatenation en fonction du choix
                }
                if (Paragraphe[choix][i] == '0')
                {
                    choixPossible[k] += 0;
                    j++;
                }
                if (Paragraphe[choix][i] == '1')
                {
                    choixPossible[k] += 1;
                    j++;
                }
                if (Paragraphe[choix][i] == '2')
                {
                    choixPossible[k] += 2;
                    j++;
                }
                if (Paragraphe[choix][i] == '3')
                {
                    choixPossible[k] += 3;
                    j++;
                }
                if (Paragraphe[choix][i] == '4')
                {
                    choixPossible[k] += 4;
                    j++;
                }
                if (Paragraphe[choix][i] == '5')
                {
                    choixPossible[k] += 5;
                    j++;
                }
                if (Paragraphe[choix][i] == '6')
                {
                    choixPossible[k] += 6;
                    j++;
                }
                if (Paragraphe[choix][i] == '7')
                {
                    choixPossible[k] += 7;
                    j++;
                }
                if (Paragraphe[choix][i] == '8')
                {
                    choixPossible[k] += 8;
                    j++;
                }
                if (Paragraphe[choix][i] == '9')
                {
                    choixPossible[k] += 9;
                    j++;
                }

                i++;
            }
        }
    }
}
/***************/
/* XP DU JOUEUR*/
/***************/
{
        int experience = 0;
        for(i=0; Paragraphe[choix][i] != '\0' ; i++)    // temps que le paragraphe n'est pas a sa fin
        {
            j = 1;
            if (Paragraphe[choix][i] == ' ') // si le caractere est '@'
            {
                i++;
                if (Paragraphe[choix][i] == '.')
                {
                    Paragraphe[choix][i] = ' ';
                    i++; // caractère suivant
                    while (Paragraphe[choix][i] == '0' || Paragraphe[choix][i] == '1' || Paragraphe[choix][i] == '2' || Paragraphe[choix][i] == '3' || Paragraphe[choix][i] == '4' || Paragraphe[choix][i] == '5' || Paragraphe[choix][i] == '6' || Paragraphe[choix][i] == '7' || Paragraphe[choix][i] == '8' || Paragraphe[choix][i] == '9')
                    {
                        if (j != 1)
                        {
                            experience *= 10; // concatenation en fonction du choix
                        }
                        if (Paragraphe[choix][i] == '0')
                        {
                            experience += 0;
                            j++;
                        }
                        if (Paragraphe[choix][i] == '1')
                        {
                            experience += 1;
                            j++;
                        }
                        if (Paragraphe[choix][i] == '2')
                        {
                            experience += 2;
                            j++;
                        }
                        if (Paragraphe[choix][i] == '3')
                        {
                            experience += 3;
                            j++;
                        }
                        if (Paragraphe[choix][i] == '4')
                        {
                            experience += 4;
                            j++;
                        }
                        if (Paragraphe[choix][i] == '5')
                        {
                            experience += 5;
                            j++;
                        }
                        if (Paragraphe[choix][i] == '6')
                        {
                            experience += 6;
                            j++;
                        }
                        if (Paragraphe[choix][i] == '7')
                        {
                            experience += 7;
                            j++;
                        }
                        if (Paragraphe[choix][i] == '8')
                        {
                            experience += 8;
                            j++;
                        }
                        if (Paragraphe[choix][i] == '9')
                        {
                            experience += 9;
                            j++;
                        }

                        i++;
                    }
                }
            }
        }
        /***************/
        /*niveau joueur*/
        /***************/
        {
            if (utilisateur.experience < 10)
            {
                utilisateur.niveau = 1;
            }
            else if (utilisateur.experience < 15)
            {
            utilisateur.niveau = 2;
            }
            else if (utilisateur.experience < 25)
            {
            utilisateur.niveau = 3;
            }
            else if (utilisateur.experience < 40)
            {
            utilisateur.niveau = 4;
            }
            else if (utilisateur.experience < 60)
            {
            utilisateur.niveau = 5;
            }
            else if (utilisateur.experience < 85)
            {
            utilisateur.niveau = 6;
            }
            else if (utilisateur.experience < 115)
            {
            utilisateur.niveau = 7;
            }
            else if (utilisateur.experience < 150)
            {
            utilisateur.niveau = 8;
            }
            else if (utilisateur.experience < 190)
            {
            utilisateur.niveau = 9;
            }
            else if (utilisateur.experience < 235)
            {
            utilisateur.niveau = 10;
            }
            else if (utilisateur.experience < 285)
            {
            utilisateur.niveau = 11;
            }
            else if (utilisateur.experience >= 285)
            {
            utilisateur.niveau = 12;
            }
        }
        utilisateur.experience += experience;

        printf("\n\nVous avez gagner %d XP\n", experience);
        if (utilisateur.niveau == 12)
        {
            printf("Vous êtes DIEU avec %d XP\n\n", utilisateur.experience);
        }
        else
        {
            printf("Vous êtes niveau %d avec %d XP\n\n", utilisateur.niveau, utilisateur.experience);
        }
}
/************/
/*FIN DU JEU*/
/************/
{
    for(i=0; Paragraphe[choix][i] != '\0' ; i++)    // temps que le paragraphe n'est pas a sa fin
        {
            j = 1;
            if (Paragraphe[choix][i] == '$') // si le caractere est '@'
            {
                choix = 308;
            }
        }
}
/*****************/
/*choix du joueur*/
/*****************/
{
    if (choix != 308)
    {
        printf("\nChoisissez un paragraphe : ");
        scanf("%d", &choix);

        i = k;

        while (choix != choixPossible[k])
        {
            if (choix == 0)
            {
                printf("\nVotre choix n'est pas possible pour ce paragraphe !");
                printf("\nChoisissez un paragraphe");
                scanf("%d", &choix);
                k=i+1;
            }
            else if (k <= 0)
            {
                printf("\nVotre choix n'est pas possible pour ce paragraphe !");
                printf("\nChoisissez un paragraphe");
                scanf("%d", &choix);
                k=i+1;
            }
            k--;
        }
        k = i;
        while (k != 0)
        {
            choixPossible[k] = 0;
            k--;
        }
    }
    else
    {
        system("\npause");
    }
}
}
return 0;
}
