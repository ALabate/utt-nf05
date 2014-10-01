/**
 * Auteur : Aurélien Labate
 * Date : 01/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * L'aire `A` d'un triangle est donnée par la formule `A=(1/2)*B*H` 
 * avec `B` la base et `H` la hauteur correspondante.
 * - Déclarer deux variables entières `B` et `H`. Quelles sont les 
 * valeurs de ces variables?
 * - Déclarer une variable réelle `A` et affecter à `A` sa valeur 
 * selon l’expression ci-dessus.
 * - Calculer et afficher l’aire `A` d’un triangle de base `B=7` et 
 * de hauteur `H=9`
 * Commentez le résultat.
 *
**/

#include <stdio.h>

int main(int argc, char const *argv[])
{

	//Init des variables
	int B = 7;
	int H = 9;
	float A;

	//Présentation
    printf("NF05 - TP1 - Exercice 3\n");
    printf("_______________________\n\n");


	//Calcul de l'aire
	A=B*H/2;

	//Sortie	
    printf("L'aire du triangle est : %f\n", A);
    printf("Commentaire : La valeur est affichée avec beaucoup de 0 inutilement\n");

    return 0;
}