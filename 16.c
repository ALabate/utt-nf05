/**
 * Auteur : Aurélien Labate
 * Date : 05/11/2014
 * UV : NF05
 *
 * Enoncé :
 * Ecrire une fonction qui trie un tableau (selon la méthode itérative classique) 
 * et qui donne le nombre d'opérations d'échange lors du tri
**/


#include <stdio.h>
#include <stdlib.h>


/**
 * Permet de trier le tableau
 * @param liste - tableau de float
 * @param nbr - nombre d'elements du tableau
 * @return nombre d'opérations d'échanges
 */
int tri(float *liste, int nbr) 
{
    int i, j, temp, operations=0; 
    //Parcours la liste
    for(i=0;i<nbr-1;i++)
    {
        //Pour chaque element de la liste 
        //parcours le reste de la liste pour trouver le plus petit restant
        for(j=i+1;j<nbr;j++)
        { 
            if(liste[i]>liste[j])
            {
                temp=liste[i];
                liste[i]=liste[j];
                liste[j]=temp; 
                operations++;
            } 
        }
    }

    return operations;
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

#define NBRCASE 6

int main(int argc, char const *argv[])
{
    //Init des variables
    float liste[NBRCASE] = { 13, 23, 1, 34, 9, 10 };
    int nbrOp = 0;

    //Présentation
    printf("NF05 - TP3 - Exercice 16\n");
    printf("_______________________\n\n");

    nbrOp = tri(liste, NBRCASE);

    //Manipulation des tableaux
    afficher(liste, NBRCASE);
    printf("Le nombre d'operations est : %d\n", nbrOp);


    return 0;
}