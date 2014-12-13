/**
 * Auteur : Aurélien Labate
 * Date : 05/11/2014
 * UV : NF05
 *
 * Enoncé :
 * En utilisant des pointeurs et l’allocation dynamique de la mémoire :
 * 1. Ecrire une proc ́edure pour saisir un vecteur des éléments réels positifs de 
 * taille N (la valeur de N sera demandée à l’utilisateur)
 * 2. Ecrire trois fonctions pour calculer :
 * – La somme de deux vecteurs saisis par l’utilisateur
 * – La soustraction de ces deux vecteurs
 * – Le produit scalaire de ces vecteurs
 * 3. Afficher les résultats
**/


#include <stdio.h>
#include <stdlib.h>

/**
 * Permet de saisir un vecteur de réels positifs de taille n
 * @param n - taille du vecteur
 * @param vecteur - pointeur vide où sera retourné le pointeur
 */
void saisieVecteur(int n, double* vecteur[]) 
{
    int i;

    //Allocation dynamique
    *vecteur = malloc(n*sizeof(double));
    if(*vecteur == NULL) {
        printf("Impossible d'allouer de la mémoire");
        exit(0);
    }

    //Saisie
    for(i=0; i<n; i++)
    {
        printf("Veuillez entrer l'élément n°%d\n",(i+1));
        scanf("%lf",&(*vecteur)[i]);
    }
}



/**
 * Permet d'ecrire un vecteur sur la console
 * @param n - taille du vecteur
 * @param vecteur - le vecteur à écrire
 */
void printVecteur(int n, double vecteur[])
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("│%lf│\n", vecteur[i]);
    }
}


/**
 * Permet d'additionner deux vecteurs
 * @param n - taille du vecteur
 * @param A - le vecteur à additionner
 * @param B - le vecteur à additionner
 * @return La somme A+B
 */
double* sommeVecteur(int n, double* A , double* B ) 
{
    int i; 
    double* vecteur;

    //Allocation dynamique
    vecteur=malloc(n*sizeof(double));
    if(vecteur == NULL) {
        printf("Impossible d'allouer de la mémoire");
        exit(0);
    }

    //Calcul
    for(i=0;i < n; i++)
    {
        vecteur[i] = A[i] + B[i];
    }
    return vecteur;
}


/**
 * Permet de soustraire deux vecteurs (A-B)
 * @param n - taille du vecteur
 * @param A - le vecteur à soustraire
 * @param B - le vecteur à soustraire
 * @return La soustraction A-B
 */
double* soustraireVecteur(int n, double* A , double* B ) 
{
    int i; 
    double* vecteur;

    //Allocation dynamique
    vecteur=malloc(n*sizeof(double));
    if(vecteur == NULL) {
        printf("Impossible d'allouer de la mémoire");
        exit(0);
    }

    //Calcul
    for(i=0;i < n; i++)
    {
        vecteur[i] = A[i] - B[i];
    }
    return vecteur;
}

/**
 * Permet de calculer le produit scalaire
 * @param n - taille du vecteur
 * @param A - le premier vecteur du produit scalaire
 * @param B - le second vecteur du produit scalaire
 * @return Le produit scalaire A.B
 */
double prodScalVecteur(int n, double* A , double* B ) 
{
    int i; 
    double prod;

    //Calcul
    prod = 0;
    for(i=0;i < n; i++)
    {
        prod += A[i]*B[i];
    }
    return prod;
}


int main(int argc, char const *argv[])
{
    //Init des variables
    int n;
    double* A = NULL;
    double* B = NULL;
    double* C = NULL;

    //Présentation
    printf("NF05 - TP3 - Exercice 21\n");
    printf("_______________________\n\n");

    //Saisie
    printf("Veuillez entrer le nombre d'éléments des vecteurs\n");
    scanf("%d",&n);
    printf("Saisir le vecteur A\n");
    saisieVecteur(n, &A);
    printf("Saisir le vecteur B\n");
    saisieVecteur(n, &B);
    printf("_______________________\n\n");

    //Présentation de A et B
    printf("\nA=\n");
    printVecteur(n, A);
    printf("\nB=\n");
    printVecteur(n, B);

    //Somme
    printf("\nA+B=\n");
    C = sommeVecteur(n, A, B);
    printVecteur(n, C);
    free(C);

    //Soustraction
    printf("\nA-B=\n");
    C = soustraireVecteur(n, A, B);
    printVecteur(n, C);
    free(C);

    //Produit scalaire
    printf("\nA.B=%lf\n", prodScalVecteur(n, A, B));

    //Liberation de la mémoire
    free(A);
    free(B);
    return 0;
}