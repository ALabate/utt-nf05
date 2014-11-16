/**
 * Auteur : Aurélien Labate
 * Date : 12/11/2014
 * UV : NF05
 *
 * Enoncé :
 * Etant donné un carré ABCD de coté 1 et le quart de cercle de centre A et de rayon 1
 * (inscrit dans le carré), écrire un programme qui donne une approximation de pi en 
 * utilisant la méthode de Monte Carlo qui peut être décrite comme suit : 
 * Un joueur tire aléatoirement n fléchettes dans le carré et comptabilise le nombre
 * de fois p où l’impact est dans le quart de cercle. La ration p/n donne une 
 * approximation de pi/4 (la probabilité pour que l’impact soit dans le quart de cercle
 * est égale à l’aire du quart du cercle / aire du carré). La précision dépend de n. 
 * Pour simuler ce jeu, il suffit de tirer n fois de suite et aléatoirement deux réel
 * x, y dans [0, 1] (M de coordonnées (x, y) est le point d’impact) et comptabiliser
 * le nombre de fois où M est dans le quart de cercle.
 * - Définir un type de structure permettant de définir un point M .
 * - Ecrire une fonction booléenne qui détermine si un essai peut être comptabilisé.
 * - Ecrire une fonction qui donne l’approximation de π selon le nombre n.
 * - Donner approximativement le nombre d’essais n nécessaire pour avoir une précision
 * a 10 −3 .
**/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415

struct Point {
    double x;
    double y;
};


/**
 * Prend le point donné et teste si, sur un carré de 1 par 1, la position est dans le cart de cercle de rayon 1 qui a pour centre x=0,y=0
 * @param pnt - Point à tester
 * @return 1 si l'essai est dans le cercle (contour inclus)
 */
int essai(struct Point pnt) {
    return (sqrt(pnt.y*pnt.y+pnt.x*pnt.x)) <= 1;
}

/**
 * Approxime pi par utilisation successive de la fonction essai avec deux valeurs aléatoires
 * @param n - Nombre de point à tester
 * @return l'approximation de pi trouvée
 */
double approxPi(int n) {

    //Init des vars
    struct Point pnt;
    int i;
    double pi = 0;

    // initialisation de rand
    srand(time(NULL)); 
    
    for (i = 0; i < n; ++i)
    {

        //Generation de la position aléatoire
        pnt.x = ((double)rand()/(double)RAND_MAX);
        pnt.y = ((double)rand()/(double)RAND_MAX);

        //Essai
        pi += essai(pnt);
    }
    pi = (pi/(double)n)*4;

    return pi;
}

/**
 * Approxime pi à une precsision de 10^-3 par utilisation successive de la fonction essai avec deux valeurs aléatoires
 * @return le nombre d'essai nécéssaire
 */
int approxPiPrec() {

    //Init des vars
    struct Point pnt;
    unsigned long i = 0;
    double pi = 0;

    // initialisation de rand
    srand(time(NULL)); 
    
    while((int)(PI*1000)-(int)((pi*4/(double)i)*1000) != 0)
    {
        //Generation de la position aléatoire
        pnt.x = ((double)rand()/(double)RAND_MAX);
        pnt.y = ((double)rand()/(double)RAND_MAX);

        //Essai
        pi += essai(pnt);
        i++;

        //printf("%d : %lf\n", i, (pi/(double)i)*4);

    }
    pi = (pi/(double)i)*4;

    return i;
}


int main(int argc, char const *argv[])
{

    //Présentation
    printf("NF05 - TP3 - Exercice 19\n");
    printf("_______________________\n\n");

    //Calcul
    printf("Approximaiton de pi pour %d essais : %lf\n", 1000, approxPi(1000));
    printf("Approximaiton de pi pour %d essais : %lf\n", 10000, approxPi(10000));
    printf("Approximaiton de pi pour %d essais : %lf\n", 100000, approxPi(100000));
    printf("Approximaiton de pi pour %d essais : %lf\n", 1000000, approxPi(1000000));


    printf("\nNombre d'approximation nécéssaire pour atteindre pi à 10^-3 : %d\n\n\n", approxPiPrec());


    printf("Note : En fait il atteint assez rapidement la précision de 10^-3, mais il la perd à nouveau quand on fait beaucoup d'essais, ce qui fait que la précision à 10000 tours est souvent moins élevés que 10^-3\n");



    return 0;
}