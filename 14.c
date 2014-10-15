/**
 * Auteur : Aurélien Labate
 * Date : 14/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Ecrire un programme pour saisir une chaˆıne de caractères de taille maximale `taillemax`
 * - les fonctions gets et puts
 * - les fonctions getchar et putchar
 *
**/


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{

	//Init des variables
    int taillemax = 3, i;
    char *input = NULL;
    input = malloc(sizeof(char)*taillemax);

    //Présentation
    printf("NF05 - TP3 - Exercice 14\n");
    printf("_______________________\n\n");

    //gets et puts
    printf("Entre une chaine de %d caractères ou moins : ",taillemax);
    gets(input);
    printf("Chaine entrée :");
    puts(input);

    //getchar et putchar
    printf("Entre une chaine de %d caractères ou moins : ",taillemax);
    for (i = 0; i < taillemax; ++i)
    {
        //Getchar récupère un seul caractère, on fait donc une boucle du nombre de caractère
        input[i] = getchar();
        //Et on arrete s'il y a un retour à la ligne
        if(input[i] == '\n') {
            //On ajoute un 0 à la fin de la chaine pour indiquer la fin
            input[i] = 0;
            break;
        }
    }
    printf("Chaine entrée :");
    //On affiche caractère par caractère avec putchar
    for (i = 0; i < taillemax; ++i)
    {
        //Si un caractère vaut 0, c'est que c'est la fin
        if(input[i] == 0)
            break;
        else
            putchar(input[i]);
    }
    putchar('\n');
    free(input);

    return 0;
}