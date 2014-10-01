/**
 * Auteur : Aurélien Labate
 * Date : 01/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * 1) Ecrire un programme qui permet de calculer la somme de deux 
 * entiers non nuls, la différence, le produit, le quotient et
 * le reste de la division euclidienne.
 * 2) Ecrire un programme permettant de permuter les valeurs de
 * deux variables réelles. Réaliser un programme équivalent pour 
 * deux caractères entiers non nuls, la différence, le produit,
 * le quotient et le reste de la division euclidienne.
 * 3) Ecrire un programme qui calcule la somme de deux caractères 
 * ainsi que leur différence. Interpréter les résultats de
 * votre programme.
 * 4) Ecrire un programme qui calcule le maximum et le minimum de 
 * deux valeurs. On affecte le maximum (respectivement le minimum)  
 * à la variable `max` (respectivement à `min`).
 *
**/
 
#include <stdio.h>

 void question1() {

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

	//Observations
	printf("%s\n", "\nOn remarque que le resultat sera toujours un entier lors d'une opération entre deux entiers. Le resultats de la division est donc uniquement la partie entière");
}

void question2() {
	//Init des variables
	float a, b, tmp;
	char c, d, tmpc;


    //Présentation partie 1
    printf("\n\nNF05 - TP1 - Exercice 2 - Question 2 - Réels\n");
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
}

void question3() {

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

}

void question4() {

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
}
int main(int argc, char const *argv[])
{
	question1();
	question2();
	question3();
	question4();

    return 0;
}