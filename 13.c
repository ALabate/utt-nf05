/**
 * Auteur : Aurélien Labate
 * Date : 14/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Ecrire un programme qui calcule la moyenne et la variance de N réels saisis 
 * au clavier (sans utiliser de tableau).
 *
**/


#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{

	//Init des variables
    int nbr_valeurs, i;
    double valeur = 0;
    double variance = 0;
    double moyenne = 0;

    //Présentation
    printf("NF05 - TP3 - Exercice 13\n");
    printf("_______________________\n\n");

    //Saisie
    printf("Combien de valeurs voullez vous saisir ?\n");
    scanf("%d", &nbr_valeurs);

    //Saisie et pre-calcul
    for (i = 1; i <= nbr_valeurs; ++i)
    {
        printf("---\nVeuillez entrer la valeur réel %d/%d\n", i, nbr_valeurs);
        scanf("%lf", &valeur);
        variance += valeur*valeur;
        moyenne += valeur;
    }

    //Calcul final
    moyenne = moyenne/nbr_valeurs;
    variance = (variance/nbr_valeurs) - (moyenne*moyenne);

    //Sortie
    printf("moyenne : %lf\n", moyenne);
    printf("Variance : %lf\n", variance);

    return 0;
}