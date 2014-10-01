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
    printf("NF05 - TP1 - Exercice 1\n"); //printf sert à afficher du texte
    printf("_______________________\n\n"); //Les \n permettent de faire des retour à la ligne

    //Affichage des taille des types en octets
    printf("Taille int : %d\n", sizeof(int)); //sizeof donne la valeur dans un int
    printf("Taille short : %d\n", sizeof(short)); //Et printf l'affiche à l'emplacement où %d est mis
    printf("Taille char : %d\n", sizeof(char)); //%d indique que la valeur est un entier
    printf("Taille float : %d\n", sizeof(float));
    printf("Taille double : %d\n", sizeof(double));
    printf("Taille long double : %d\n", sizeof(long double));

    printf("_______________________\n\n");


  
    a=3.4;
    ptr=&a; // Assigne l'adresse de a au pointeur
    //La valeur sera la même que a car ptr pointe vers &a
    printf("la valeur contenue dans l’adresse est %1.2f \n", *ptr); //%1.2f indique que la valeur est un réel qui sera arrondie à deux chiffres après la virgule
    //les deux adresses seront donc les mêmes
    printf("l’adresse est %d \n", ptr) ;
    printf("l’adresse de a est %d \n", &a) ;

    //Si on change la valeur via le pointeur, ça changera l'adresse de a aussi
    *ptr=a+1;
    //La valeur a changée
    printf("la valeur contenue dans l’adresse est %1.2f \n", *ptr);
    //Les adresses n'ont pas changé
    printf("l’adresse est %d \n", ptr) ;
    printf("l’adresse de a est %d \n", &a) ;
    //La valeur a changée
    printf("la valeur de a est %1.2f \n", a) ;
    
    return 0;
}