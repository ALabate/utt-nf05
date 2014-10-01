/**
 * Auteur : Aurélien Labate
 * Date : 01/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Ecrire un programme qui permet de calculer la somme de deux 
 * entiers non nuls, la différence, le produit, le quotient et
 * le reste de la division euclidienne.
 *
**/
 
#include <stdio.h>

int main(int argc, char const *argv[])
{

	//Init des variables
	int a, b, res;

	//Présentation
    printf("NF05 - TP1 - Exercice 2 - Question 1\n");
    printf("_______________________\n\n");

    //Demande des valeurs
	printf("%s\n", "Veuillez entrer un premier entier : a");
	scanf("%i", &a);
	printf("%s\n", "Veuillez entrer un second entier : b");
	scanf("%i", &b);
    printf("_______________________\n");

	//Affichage de a et b
	printf("%s%i\n", "a = ", a);
	printf("%s%i\n", "b = ", b);	

	//Somme
	res = a + b;
	printf("%s%i\n", "a + b = ", res);

	//Différence
	res = a - b;
	printf("%s%i\n", "a - b = ", res);

	//Produit
	res = a * b;
	printf("%s%i\n", "a * b = ", res);

	//Quotient
	res = a / b;
	printf("%s%i\n", "a / b = ", res);

	//Reste
	res = a % b;
	printf("%s%i\n", "a % b = ", res);

    return 0;
}