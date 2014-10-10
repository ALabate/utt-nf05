/**
 * Auteur : Aurélien Labate
 * Date : 01/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Ecrire un programme permettant de convertir un entier de la base
 * décimale à la base octale.
 *
**/

#include <stdio.h>
#include <math.h>
#include <string.h>


void decToOct(int entree, char* sortie) {

	char temp[32];
	int chiffre, i, longueur;


	i = 0;
	while(entree > 0) {
		//Récupération du chiffre de poid le plus faible
		chiffre = entree % 8;

		//Retire le chiffre de poid le plus faible
		entree = entree / 8;

		//Ajout du chiffre au string (mais en inversé il faudra réinversé ensuite)
		temp[i] = '0' + chiffre;

		i++;
	}
	longueur = i - 1;

	//Inversion afin d'avoir le nombre dans le bon sens
	for(i = 0; i<=longueur; i++) {
		sortie[i] = temp[longueur-i];
	}

	//Ajout du caractère 0 pour montrer que la chaine est terminée
	sortie[longueur + 1] = 0;
}

int main(int argc, char const *argv[])
{

	//Init des variables
	char sortie[32];
	long entree = 0;

	//Presentation
    printf("NF05 - TP2 - Exercice 6\n");
    printf("_______________________\n\n");

    //Demande des valeurs
	printf("%s\n", "Veuillez entrer la valeur décimale à convertir en octale (inférieur à 32 bits) :");
	scanf("%d", &entree);

	//Récupération du résultat
	decToOct(entree, sortie);

	//Affichage
	printf("%s%s\n", "La valeur en octale est : ", sortie);


    return 0;
}