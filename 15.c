/**
 * Auteur : Aurélien Labate
 * Date : 05/11/2014
 * UV : NF05
 *
 * Enoncé : 
 * - Ecrire une procédure permettant de saisir le nombre d'éléments d'un tableau et 
 * les valeurs de ses éléments.
 * - Ecrire une deuxieme procédure qui affiche les éléments de ce tableau
 * - Ecrire une fonction qui permet de calculer la moyenne et la variance du tableau
 * - Ecrire une deuxieme fonction qui determine le minimum du tableau ainsi que sa position
**/


#include <stdio.h>
#include <stdlib.h>


/**
 * Permet de saisir le nombre d'éléments et le contenu du tableau
 * @param liste - pointeur vers tableau de float 
 * @return nombre d'éléments du tableau
 */
int saisie(float *liste[])
{
    //init
    int nbr, i;

    //Demande du nombre de cases
    printf("Veuillez entrer le nombre d'éléments que vous souhaitez saisir :\n");
    scanf("%d", &nbr);

    //init du tableau
    *liste = malloc(sizeof(float)*nbr);

    //saisie
    for (i = 0; i < nbr; ++i)
    {
        printf("Veuillez entrer la valeur n°%d sur %d:\n",(i+1), nbr);
        scanf("%f", &(*liste)[i]);
    }

    return nbr;
}

/**
 * Permet d'afficher le contenu du tableau
 * @param liste - tableau de float
 * @param nbr - nombre d'elements du tableau
 */
void afficher(float liste[], int nbr)
{
    //init
    int i;

    //Affichage
    printf("Le tableau contient %d éléments :\n---\n", nbr);
    for (i = 0; i < nbr; ++i)
    {
        printf("Valeur n°%d sur %d : ",(i+1), nbr);
        printf("%f\n", liste[i]);
    }
}

/**
 * Permet de calculer la variance et la moyenne
 * @param liste - tableau de float
 * @param nbr - nombre d'elements du tableau
 * @param variance - pointeur vers un float qui sera le retour de la variance
 * @param moyenne - pointeur vers un float qui sera le retour de la moyenne
 */
void stats(float liste[], int nbr, float *variance, float *moyenne)
{
    //init
    int i;
    *moyenne = 0;
    *variance = 0;

    //pre-calcul
    for (i = 0; i < nbr; ++i)
    {
        *variance += liste[i]*liste[i];
        *moyenne += liste[i];
    }

    //Calcul final
    *moyenne = *moyenne/(float)nbr;
    *variance = (*variance/(float)nbr) - (*moyenne*(*moyenne));
}


/**
 * Permet de trouver le minimum et sa position
 * @param liste - tableau de float
 * @param nbr - nombre d'elements du tableau
 * @param min - pointeur vers un int qui sera le retour de la valeur minimum
 * @param pos - pointeur vers un int qui sera le retour de la position du minimum
 */
void minimum(float liste[], int nbr, int *min, int *pos)
{
    //init
    int i;

    *pos = 0;
    *min = liste[0];
    //Parcour le tableau sauf la case n°0 qui est déjà faite
    for (i = 1; i < nbr; ++i)
    {
        if(*min > liste[i]) {
            *pos = i;
            *min = liste[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    //Init des variables
    float *liste;
    float variance, moyenne;
    int nbr, posMin, min;

    //Présentation
    printf("NF05 - TP3 - Exercice 15\n");
    printf("_______________________\n\n");

    //Manipulation des tableaux
    nbr = saisie(&liste);
    afficher(liste, nbr);
    stats(liste, nbr, &variance, &moyenne);
    minimum(liste, nbr, &min, &posMin);

    
    printf("La moyenne est : %f\n", moyenne);
    printf("La variance est : %f\n", variance);
    printf("La minimum est : %d\n", min);
    printf("La position du minimum est : %d\n", posMin+1);


    free(liste);

    return 0;
}