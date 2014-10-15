/**
 * Auteur : Aurélien Labate
 * Date : 14/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Calculer la somme S de la série dont le n(ème) terme est (1/n^2) à 
 * epsilon=10^(-3) près : Si S* est la valeur de la somme infinie et S la 
 * valeur de la somme des n premiers termes alors S*-S<epsilon.
 * Trouver la condition d’arrèt sur le dernier terme en fonction de la 
 * valeur d’epsilon.
 *
**/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define S_ETOILE PI*PI/6

int main(int argc, char const *argv[])
{

	//Init des variables
	double epsilon = 0.001; //10^(-3)
	double S = 0; //Somme Sn des terme de la suite (U_n)
	double terme; //terme Un
	int n = 0;

    //Présentation
    printf("NF05 - TP3 - Exercice 11\n");
    printf("_______________________\n\n");

    //Condition d'arret : 
    // On compare la valeur de S actuelle tronquée a 10^-3 et la valeur de S*, elle aussi tronquée
    while ( (int)(S/epsilon)-(int)(S_ETOILE/epsilon) != 0)
    {
    	//On calcule le terme suivant et on l'ajoute à la somme
    	n++;
    	terme = 1/((double)(n*n));
    	S += terme;
    }
    //Sortie
	printf("S_%d=%lf\n", n, S, n, terme);
	printf("S*=%lf\n", S_ETOILE);
    return 0;
}