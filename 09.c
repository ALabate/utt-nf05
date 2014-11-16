/**
 * Auteur : Aurélien Labate
 * Date : 14/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Ecrire un programme qui résout une équation du second degrée.
 *
**/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{

	//Init des variables
	double a, b, c, delta;

    //Présentation
    printf("NF05 - TP3 - Exercice 9\n");
    printf("_______________________\n\n");

    //Entree utilisateur
    printf("Ce programme resoud les equations du type :\n");
    printf("a*(x^2) + b*x + c = 0\n");
    printf("avec un réel \na=");
	scanf("%lg", &a);
    printf("b=");
	scanf("%lg", &b);
    printf("c=");
	scanf("%lg", &c);
    printf("_______________________\n");

    //Resolution
    //degré 1 : b*x+c=0
    if(a == 0) {
	    printf("On cherche donc à résoudre :\n");
	    printf("%lg*x + %lg = 0\n",b,c);
	    printf("_______________________\n");

    	printf("L'équation est du premier degré et a une solution réelle :\n");
    	printf("x = %lg\n", -c/b);
    }
    //degré 2
    else {
	    printf("On cherche donc à résoudre :\n");
	    printf("%lg*(x^2) + %lg*x + %lg = 0\n",a,b,c);
	    printf("_______________________\n");

	    //Calcul du discriminant
	    delta = b*b-4*a*c;

	    //Affichage des solutions
	    if(delta > 0) {
	    	printf("L'équation a deux solutions réelles :\n");
	    	printf("x =   %lg   ou   %lg\n", (-b-sqrt(delta))/(2*a), (-b+sqrt(delta))/(2*a) );
	    }	
	    else if(delta == 0) {
			printf("L'équation a une solution réelle :\n");
	    	printf("x = %lg\n", (-b)/(2*a));
	    }
	    else if(delta < 0) {
			printf("L'équation a deux solutions complexes :\n");
	    	printf("x =   %lg+i*%lg   ou   %lg-i*%lg\n", -b/(2*a),sqrt(fabs(delta))/(2*a), -b/(2*a),sqrt(fabs(delta))/(2*a));
	    }
    }
    return 0;
}