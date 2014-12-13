/**
 * Auteur : Aurélien Labate
 * Date : 03/12/2014
 * UV : NF05
 *
 * Enoncé :
 * 1. Ecrire une procédure/fonction permettant de stocker M vecteurs réels de taille N (M
 * et N seront saisis par l’utilisateur) dans un fichier avec un nom donné par l’utilisateur.
 * 2. Ecrire une procédure/fonction qui permet de lire le contenu d’un fichier avec un nom
 * donné par l’utilisateur. Afficher le contenu du fichier s’il existe.
 * 3. Ecrire une troisi`eme procédure/fonction permettant de calculer la somme de deux
 * vecteurs quelconques dans le fichier précédent et ajouter ce résultat de calcul dans
 * ce fichier
**/


#include <stdio.h>
#include <stdlib.h>


/**
 * Permet d'enregister une liste de vecteur saisis par l'utilisateur dans un fichier
 * @param nom - chaine donnant le nom du fichier
 */
void sauverVecteurs(char* nom) 
{
    int taille, nbr, i, j;
    double tmp;
    FILE *file;

    //Input
    printf("Veuillez enter la taille des vecteurs que vous souhaitez enregister : ");
    scanf("%d", &taille);
    printf("Veuillez enter le nombre de vecteurs que vous souhaitez enter : ");
    scanf("%d", &nbr);

    //Ouverture du fichier
    file = fopen(nom, "w");

    //Ecriture de la taille des vecteurs
    fwrite(&taille, sizeof(int), 1, file);


    //Saisie et enregistrement des vecteurs
    for (i = 0; i < nbr; ++i)
    {
        printf("Saisie du vecteur %d/%d : \n", i+1, nbr);
        //Saisie de chaque element du vecteur
        for (j = 0; j < taille; ++j)
        {
            scanf("%lf", &tmp);
            fwrite(&tmp, sizeof(double), 1, file);
        }
    }

    fclose(file);
}


/**
 * Permet d'afficher les vecteurs d'un fichier
 * @param nom - chaine donnant le nom du fichier
 */
void lireVecteurs(char* nom) 
{
    int taille, i, j;
    double tmp;
    FILE *file;

    //Ouverture du fichier
    file = fopen(nom, "r");
    if(file == NULL)
    {
        printf("Le fichier ne peut pas être ouvert\n");
        return ;
    }


    //lecture de la taille des vecteurs
    fread(&taille, sizeof(int), 1, file);


    //Saisie et enregistrement des vecteurs
    i = 1;
    while(1)
    {
        //Saisie de chaque element du vecteur
        for (j = 0; j < taille; ++j)
        {
            //Lecture
            if(fread(&tmp, sizeof(double), 1, file) != 1)
            {
                printf("Fin du fichier (ou erreur de lecture)\n");
                return ;
            }
            //Affichage du debut de chaque vecteurs
            if(j == 0) 
            {
                printf("Vecteur %d\n", i);
            }
            //Affichage d'une valeur
            printf("%lf\n", tmp);
        }
        i++;
    }

    fclose(file);
}


/**
 * Permet de faire la somme de deux vecteurs d'un fichier et de l'ajouter à la fin du fichier
 * @param nom - chaine donnant le nom du fichier
 * @param vecteur1 - Numéro du premier vecteur de la somme
 * @param vecteur2 - Numéro du second vecteur de la somme
 */
void sommeVecteurs(char* nom, int vecteur1, int vecteur2) 
{
    int taille, j;
    double tmp1, tmp2;
    FILE *file;

    //Ouverture du fichier
    file = fopen(nom, "r+");
    if(file == NULL)
    {
        printf("Le fichier ne peut pas être ouvert\n");
        return ;
    }

    //lecture de la taille des vecteurs
    fread(&taille, sizeof(int), 1, file);

    //Ajout de chaque élément de la somme des deux vecteurs
    for (j = 0; j < taille; ++j)
    {
        //Lecture du premier terme de la somme
        fseek(file, sizeof(int)+(vecteur1-1)*taille*sizeof(double) + j*sizeof(double), SEEK_SET); //Position du curseur
        //sizeof(int) : taille en octets de l'indication de taille de vecteur
        //taille*sizeof(double) : Taille en octets d'un vecteur
        //sizeof(int)+(vecteur1-1)*taille*sizeof(double) : La position de début du vecteur 1
        if(fread(&tmp1, sizeof(double), 1, file) != 1)
        {
            printf("Erreur de lecture\n");
            return ;
        }

        //Lecture du second terme de la somme
        fseek(file, sizeof(int)+(vecteur2-1)*taille*sizeof(double) + j*sizeof(double), SEEK_SET); //Position du curseur
        if(fread(&tmp2, sizeof(double), 1, file) != 1)
        {
            printf("Erreur de lecture\n");
            return ;
        }

        //Ecriture du resultat
        tmp1 = tmp1+tmp2;
       fseek(file, 0, SEEK_END); //Position du curseur
        fwrite(&tmp1, sizeof(double), 1, file);
    }

    fclose(file);
}



int main(int argc, char const *argv[])
{
    //Init des variables
    struct Etudiant* etu;
    int nbrEtu, vecteur1, vecteur2;
    char nom[100];


    //Présentation
    printf("NF05 - TP7 - Exercice 23\n");
    printf("_______________________\n\n");


    //Input
    printf("Veuillez enter le nom du fichier de sauvegarde (max 100 caractères) : ");
    scanf("%s", &nom);
    printf("-----Saisie-----\n");
    sauverVecteurs(nom);


    printf("-----Lecture-----\n");
    lireVecteurs(nom);

    printf("-----Somme-----\n");
    printf("Veuillez enter le numéro du premier vecteur de la somme : ");
    scanf("%d", &vecteur1);
    printf("Veuillez enter le numéro du second vecteur de la somme : ");
    scanf("%d", &vecteur2);
    sommeVecteurs(nom, vecteur1, vecteur2);
    printf("-----Lecture-----\n");
    lireVecteurs(nom);

    return 0;
}