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
	printf("Veuillez entrer un premier entier :\n");
	scanf("%i", &a);
	printf("Veuillez entrer un second entier :\n");
	scanf("%i", &b);
    printf("_______________________\n");

	//Affichage de a et b
	printf("a = %i\n", a);
	printf("b = %i\n", b);	

	//Somme
	res = a + b;
	printf("a + b = %i\n", res);

	//Différence
	res = a - b;
	printf("a - b = %i\n", res);

	//Produit
	res = a * b;
	printf("a * b = %i\n", res);

	//Quotient
	res = a / b;
	printf("a / b = %i\n", res);

	//Reste
	res = a % b;
	printf("a %% b = %i\n", res);

	//Observations
	printf("\nOn remarque que le resultat sera toujours un entier lors d'une opération entre deux entiers. Le resultats de la division est donc uniquement la partie entière\n");
}

void question2() {
	//Init des variables
	float a, b, tmp;
	char c, d, tmpc;


    //Présentation partie 1
    printf("\n\nNF05 - TP1 - Exercice 2 - Question 2 - Réels\n"); //printf sert à afficher du texte
    printf("_______________________\n"); //Les \n permettent de faire des retour à la ligne

    //Demande des valeurs
	printf("Veuillez entrer un premier réel :\n");
	scanf("%f", &a); //scanf permet de saisir une valeur dans la console; %f indique que la valeur sera un réel
	printf("Veuillez entrer un second réel :\n");
	scanf("%f", &b);
    printf("_______________________\n");

	//Affichage de a et b
	printf("a = %f\n", a);
	printf("b = %f\n", b);	

	//Permutation des variables. Elle implique forcément une variable temporaire supplémentaire.
    printf("Permutation des réels\n");
	tmp = a;
	a = b;
	b = tmp;

	//Affichage de a et b
	printf("a = %f\n", a);
	printf("b = %f\n", b);


    //Presentation partie 2
    printf("\n\nF05 - TP1 - Exercice 2 - Question 2 - Caractères\n");
    printf("_______________________\n");

    //Demande des valeurs
	printf("Veuillez entrer un premier caractère :\n");
	scanf(" %c", &c); //On demande à l'utilisateur d'entrer un caractère symbolisé par le %c. L'espace avant le %c permet d'enlever un eventuel retour à la ligne qui serait resté dans la mémoire d'entrée
	printf("Veuillez entrer un second caractère :\n");
	scanf(" %c", &d);
    printf("_______________________\n");


	//Affichage de c et d
	printf("c = %c\n", c);
	printf("d = %c\n", d);	

	//Permutation des variables
    printf("Permutation des caractères\n");
	tmpc = c;
	c = d;
	d = tmpc;

	//Affichage de c et d
	printf("c = %c\n", c);
	printf("d = %c\n", d);
}

void question3() {

    //Init des variables
	char a, b;

    //Présentation
    printf("\n\nF05 - TP1 - Exercice 2 - Question 3\n");
    printf("_______________________\n");

    //Demande des valeurs
	printf("Veuillez entrer un premier caractère :\n");
	scanf(" %c", &a);
	printf("Veuillez entrer un second caractère :\n");
	scanf(" %c", &b);
    printf("_______________________\n");

	//Affichage de a et b
	printf("a = %c\n", a);
	printf("b = %c\n", b);

	//Calcul de la somme et de la différence
	printf("a + b = '%c'\n", a + b);
	printf("a - b = '%c'\n", a - b);

	//Interprétation des résultats
	printf("La valeur numérique de '%c' est %i\n", a, a);
	printf("La valeur numérique de '%c' est %i\n", b, b);
	printf("La valeur numérique de '%c' est %i\n", (a + b), (a + b));
	printf("La valeur numérique de '%c' est %i\n", (a - b), (a - b));
	printf("La sommes ou la différence de deux caractères est juste celles des valeurs entières associées. Se référer à la table ASCII afin de savoir les caractères associés aux codes.\n");

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