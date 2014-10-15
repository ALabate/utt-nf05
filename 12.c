/**
 * Auteur : Aurélien Labate
 * Date : 14/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Soit f la fonction définie sur l'intervalle [0.1,10] par f(x)=exp(-x)/x^3.
 * Calculer son intégrale à 10^-2 près en utilisant la méthode des rectangles.
 *
**/


#include <stdio.h>
#include <math.h>

#define DIVISIONS 5300000
#define FX(x) (exp(-x)/(x*x*x))
#define FX_BORNE_INF 0.1
#define FX_BORNE_SUP 10
#define THEORIQUE 41.62914576

#define PAS (FX_BORNE_SUP-FX_BORNE_INF)/DIVISIONS

int main(int argc, char const *argv[])
{

	//Init des variables
    int i;
    double integral = 0;
    double x;

    //Présentation
    printf("NF05 - TP3 - Exercice 12\n");
    printf("_______________________\n\n");

    //Somme de l'aire des n rectangles
    for (i = 0; i < DIVISIONS; ++i)
    {
        //Largeur du rectangle
        x = ((double)i)*PAS + FX_BORNE_INF;
        //Aire du rectangle
        integral += FX(x)*PAS;
    }

    //Sortie
    printf("Intégral calculé : %lf\n", integral);
    printf("Valeur théorique : %lf\n", THEORIQUE);

    return 0;
}