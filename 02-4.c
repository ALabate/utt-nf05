/**
 * Auteur : Aurélien Labate
 * Date : 01/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Ecrire un programme qui calcule le maximum et le minimum de deux 
 * valeurs. On affecte le maximum (respectivement le minimum) à la 
 * variable `max` (respectivement à `min`).
 *
**/

#include <stdio.h>

int main(int argc, char const *argv[])
{

    //Init des variables
	int a, b, max, min;

	//Présentation
    printf("\n\nF05 - TP1 - Exercice 2 - Question 4\n");
    printf("_______________________\n");

    //Demande des valeurs
	printf("%s\n", "Veuillez entrer un premier entier : a");
	scanf("%i", &a);
	printf("%s\n", "Veuillez entrer un second entier : b");
	scanf("%i", &b);
    printf("_______________________\n");

	//Affichage de a et b
	printf("%s%i\n", "a = ", a);
	printf("%s%i\n", "b = ", b);

	//Calcul du max et du min
	if(a < b) {
		max = b;
		min = a;
	}
	else {
		max = a;
		min = b;
	}

	//Calcul de la somme et de la différence
	printf("%s%i\n", "Maximum : ", max);
	printf("%s%i\n", "Minimum : ", min);

    return 0;
}