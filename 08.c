/**
 * Auteur : Aurélien Labate
 * Date : 01/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Etant donnée deux entier `A` et `B` de type *unsigned short* 
 * et un réel `C` de type *float* avec `A=104` et `C=6.5`.
 * Compléter (...) et commenter les instructions suivantes :
 * - A += (...)C;
 * - A = ~A;
 * - B = A^(A+2);
 * - C = (...)(A<<B);
 * - A = A&(...)C;
 *
**/

#include <stdio.h>

int main(int argc, char const *argv[])
{

	//Init des variables
	unsigned short A = 104, B;
	float C = 6.5;

    //Présentation
    printf("NF05 - TP1 - Exercice 8\n");
    printf("_______________________\n\n");


    // Ajout de la valeur 16bit non signé de C (ici 6 => A=110)
	A += (unsigned short)C;
	printf("%i\n", A);

	// Negation binaire de A 
	// ici negation de 110 en decimal ou 1101110 en binaire 
	// soit 1111 1111 1001 0001 en binaire donc A=65425 en unsigned short
	A = ~A;
	printf("%i\n", A);

	// XOR de A et de A+2
	// ici XOR de 65425 et 65427 en decimal c-à-d 1111111110010001 et 1111111110010011 en binaire 
	// soit 0000010 en binaire donc B=2 en decimal
	B = A^(A+2);
	printf("%i\n", B);

	// Decale A de B bits sur la gauche
	// ici decale 65425 (ou 1111111110010001) de 2 bits sur la gauche
	// donc C=111111111001000100 donc 261700 en float
	C = (int)(A<<B);
	printf("%f\n", C);

	// Fait le ET logique entre A et C
	// ici (65425 et 261700) ou (1111111110010001 et 111111111001000100)
	// donc 1111111000000000 ou A=65024
	A = A&(int)C;
	printf("%i\n", A);


	printf("%s\n", "Oui, les résultats changeraient si A et B en int car c'est signé et fait 32bit au lieu de 16 (sur un OS 32bits)");

    return 0;
}