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

int main(int argc, char const *argv[])
{

	//Init des variables
	int oct;
	int poid = 0;
	int chiffre;
	int result = 0;

	//Presentation
    printf("NF05 - TP1 - Exercice 6\n");
    printf("_______________________\n\n");

    //Demande des valeurs
	printf("%s\n", "Veuillez entrer la valeur octale à convertir :");
	scanf("%i", &oct);

	while(oct > 0) {
		//Recuperation du chiffre octale de poid le plus faible
		chiffre = oct % 10;

		//Gestion d'erreur
		if(chiffre > 7) {
			printf("%s\n", "Ce nombre n'est pas octale");
			return 1;
		}


		//Suppression du chiffre octale de poid le plus petit
		oct = (oct - chiffre) / 10;

		//Ajout de la valeur du chiffre ne decimal
		result += chiffre * ((int)pow(8, poid));

		poid++;
	}

	printf("%s%i\n", "La valeur en decimal est : ", result);


    return 0;
}