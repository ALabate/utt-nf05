/**
 * Auteur : Aurélien Labate
 * Date : 05/11/2014
 * UV : NF05
 *
 * Enoncé :
 * Ecrire une fonction qui calcule le pgcd (plus grand commun diviseur)
 * et qui donne le nombre d'opérations d'échange lors du tri
**/


#include <stdio.h>
#include <stdlib.h>


/**
 * Calcul du pgcd entre a et b
 * @param a
 * @param b
 * @return pgcd calculé
 */
int pgcd(int a, int b) 
{
    long reste;
  
    while (b > 0) {
        reste = a % b;
        a = b;
        b = reste;
    }

    return a;
}

int main(int argc, char const *argv[])
{
    //Init des variables
    int a, b;
    a = 99;
    b = 12;
    int nbrOp = 0;

    //Présentation
    printf("NF05 - TP3 - Exercice 17\n");
    printf("_______________________\n\n");
    printf("PGCD(%d,%d)=%d\n",a,b,pgcd(a,b));


    return 0;
}