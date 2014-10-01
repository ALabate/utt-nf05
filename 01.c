/**
 * Auteur : Aurélien Labate
 * Date : 01/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Reprendre les exemples préliminaires du cours (cours – Types de base) :
 * – l’affichage de la taille en octets des types *int*, *short*, *char*, *float* et *double*
 * - l'exemple sur le pointeur
 *
**/
 
#include <stdio.h>

int main(int argc, char const *argv[])
{

    //Init des variables
    float *ptr;
    float a;

    //Présentation
    printf("NF05 - TP1 - Exercice 1\n");
    printf("_______________________\n\n");

    printf("Taille int : %d\n", sizeof(int));
    printf("Taille short : %d\n", sizeof(short));
    printf("Taille char : %d\n", sizeof(char));
    printf("Taille float : %d\n", sizeof(float));
    printf("Taille double : %d\n", sizeof(double));

    printf("_______________________\n\n");

    a=3.4;
    ptr=&a ;
    printf("la valeur contenue dans l’adresse est %1.2f \n", *ptr);
    printf("l’adresse est %d \n", ptr) ;
    printf("l’adresse de a est %d \n", &a) ;
    *ptr=a+1;
    printf("la valeur contenue dans l’adresse est %1.2f \n", *ptr);
    printf("l’adresse est %d \n", ptr) ;
    printf("l’adresse de a est %d \n", &a) ;
    printf("la valeur de a est %1.2f \n", a) ;
    
    return 0;
}