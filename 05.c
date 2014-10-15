/**
 * Auteur : Aurélien Labate
 * Date : 08/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Ecrire un programme qui permet de convertir un nombre de base binaire à 
 * la base décimale. Réaliser un autre programme qui effectue l'opération
 * inverse.
 *
**/

#include <stdio.h>
#include <math.h>
#include <string.h>

int binToDec(char* entree) {

	//Init des variables
	long result = 0;
	int longueur, i, poid;

	//Recup de la longueur de la chaine
	longueur = strlen(entree) - 1;

	//Parcour tous les caractères en partant de la fin (i etant le numéro de caractère dans la chaine en partant de 0)
	poid = 0;
	result = 0;
	for (i = longueur; i >= 0 ; --i)
	{	
		//Ajout du chiffre binaire au resultat finale décimal
		if(entree[i] == '1') {
			result += ((int)pow(2, poid));
		}
		//Gestion d'erreur
		else if(entree[i] != '0') {
			printf("Ce caractère n'est pas binaire : '%c'\n", entree[i]);
			return 1;
		}
		poid++;
	}

	return result;
}

void decToBin(int entree, char* sortie) {

	char temp[32];
	int chiffre, i, longueur;


	i = 0;
	while(entree > 0) {
		//Récupération du chiffre de poid le plus faible
		chiffre = entree & 1;

		//Retire le chiffre de poid le plus faible
		entree = entree >> 1;

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
	char entree[32], sortie2[32];
	long sortie = 0, entree2;

	//Presentation
    printf("NF05 - TP2 - Exercice 5\n");
    printf("_______________________\n\n");

    //Demande des valeurs
	printf("%s\n", "Veuillez entrer la valeur binaire à convertir en décimale (inférieur à 32 bits) :");
	scanf(" %s", entree);

	//Récupération du résultat
	sortie = binToDec(entree);

	//Affichage
	printf("%s%d\n", "La valeur en decimal est : ", sortie);

	//----Partie 2----

    //Demande des valeurs
	printf("%s\n", "Veuillez entrer la valeur décimal à convertir en binaire (inférieur à 32 bits) :");
	scanf("%d", &entree2);

	//Récupération du résultat
	decToBin(entree2, sortie2);

	//Affichage
	printf("%s%s\n", "La valeur en binaire est : ", sortie2);

    return 0;
}
