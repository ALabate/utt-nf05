/**
 * Auteur : Aurélien Labate
 * Date : 01/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Ecrire un programme qui calcule la somme de deux caractères 
 * ainsi que leur différence. Interpréter les résultats de
 * votre programme.
 *
**/

#include <stdio.h>

int main(int argc, char const *argv[])
{

    //Init des variables
	char a, b;

    //Présentation
    printf("\n\nF05 - TP1 - Exercice 2 - Question 3\n");
    printf("_______________________\n");

    //Demande des valeurs
	printf("%s\n", "Veuillez entrer un premier caractère : a");
	scanf(" %c", &a);
	printf("%s\n", "Veuillez entrer un second caractère : b");
	scanf(" %c", &b);
    printf("_______________________\n");

	//Affichage de a et b
	printf("%s%c\n", "a = ", a);
	printf("%s%c\n", "b = ", b);

	//Calcul de la somme et de la différence
	printf("%s%c\n", "a + b = ", a + b);
	printf("%s%c\n", "a - b = ", a - b);

	//Interprétation des résultats
	printf("%s%c%s%i\n", "La valeur numérique de '", a, "' est ", a);
	printf("%s%c%s%i\n", "La valeur numérique de '", b, "' est ", b);
	printf("%s%c%s%i\n", "La valeur numérique de '", (a + b), "' est ", (a + b));
	printf("%s%c%s%i\n", "La valeur numérique de '", (a - b), "' est ", (a - b));
	printf("%s\n", "La sommes ou la différence de deux caractères est juste celles des valeurs entières associées. Se référer à la table ASCII afin de savoir les caractères associés aux codes.");

    return 0;
}