/**
 * Auteur : Aurélien Labate
 * Date : 01/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Le volume d’un cône `V` est donnée par la formule `V=(1/3)*BH` ou `H`
 * est la hauteur du cône. `B` est donnée à son tour par la formule
 * `B=pi*π*R^2` avec `R` le rayon de la base.
 * - Déclarer deux variables entières `R` et `H`.
 * - Définir une constante `PI=3.1416` (utiliser `define`). Ecrire une 
 * instruction qui affiche sa valeur.
 * - Calculer et afficher le volume du cône pour `R=5`, `H=10`. Limiter
 * l'affichage à deux chiffres après la virgule.
 *
**/

#include <stdio.h>
#define PI 3.1416

int main(int argc, char const *argv[])
{

	//Init des variables
	int R = 5;
	int H = 10;
	float B, V;

	//Présentation
    printf("NF05 - TP1 - Exercice 4\n");
    printf("_______________________\n\n");


	//Calcul du volume
	B = PI * R * R;
	V = B * H / 3;

	//Sortie	
    printf("La valeur de pi est : %f\n", PI);
    printf("Le volume du cone est : %1.2f\n", V);

    return 0;
}