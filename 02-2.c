/**
 * Auteur : Aurélien Labate
 * Date : 01/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * - Ecrire un programme permettant de permuter les valeurs de
 * deux variables réelles.
 * - Réaliser un programme équivalent pour deux caractères. 
 * entiers non nuls, la différence, le produit, le quotient 
 * et le reste de la division euclidienne.
 *
**/

#include <stdio.h>

int main(int argc, char const *argv[])
{


    //Init des variables pour la partie 1
	float a, b, tmp;

    //Init des variables pour la partie 2
	char c, d, tmpc;


    //Présentation partie 1
    printf("NF05 - TP1 - Exercice 2 - Question 2 - Réels\n");
    printf("_______________________\n");

    //Demande des valeurs
	printf("%s\n", "Veuillez entrer un premier réel : a");
	scanf("%f", &a);
	printf("%s\n", "Veuillez entrer un second réel : b");
	scanf("%f", &b);
    printf("_______________________\n");

	//Affichage de a et b
	printf("%s%f\n", "a = ", a);
	printf("%s%f\n", "b = ", b);	

	//Permutation des variables
    printf("Permutation des réels\n");
	tmp = a;
	a = b;
	b = tmp;

	//Affichage de a et b
	printf("%s%f\n", "a = ", a);
	printf("%s%f\n", "b = ", b);


    //Presentation partie 2
    printf("\n\nF05 - TP1 - Exercice 2 - Question 2 - Caractères\n");
    printf("_______________________\n");

    //Demande des valeurs
	printf("%s\n", "Veuillez entrer un premier caractère : c");
	scanf(" %c", &c);
	printf("%s\n", "Veuillez entrer un second caractère : d");
	scanf(" %c", &d);
    printf("_______________________\n");


	//Affichage de c et d
	printf("%s%c\n", "c = ", c);
	printf("%s%c\n", "d = ", d);	

	//Permutation des variables
    printf("Permutation des caractères\n");
	tmpc = c;
	c = d;
	d = tmpc;

	//Affichage de a et b
	printf("%s%c\n", "c = ", c);
	printf("%s%c\n", "d = ", d);

    return 0;
}