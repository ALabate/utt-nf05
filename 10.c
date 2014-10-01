/**
 * Auteur : Aurélien Labate
 * Date : 01/10/2014
 * UV : NF05
 *
 * Enoncé : 
 * Analyser le programme qui teste si un entier est premier. Afficher 
 * tous les entiers premiers inférieurs à 50 
 * (cours – Fonctions & procédures).
 *
**/

#include <stdio.h>

/**
 * Teste si un nombre est premier ou non (donnée dans le cours)
 * @param	n Nombre à tester
 * @return	1 si le nombre est premier, 0 sinon
 */
int premier( int n )
{
	if (n ==2) return 1;
	else
	{
		int k =2; int z =1;
		while (k < n)
		{
			while(( premier(k) == 0) && ( k < n-1 )) {k++;};
			if (n%k==0) {z =0; k++;} 
			else k++;
		};
		return z ;
	};
}


int main(int argc, char const *argv[])
{
	//init
	int i;
	//Cherche un par un si tous les nombres sont premiers
	printf("2\n");
	for (i =3; i <=50; i+=2)
	{
		if(premier(i))
		{
			printf("%d\n", i);
		}
	}
}