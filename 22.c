/**
 * Auteur : Aurélien Labate
 * Date : 05/11/2014
 * UV : NF05
 *
 * Enoncé :
 * 1. Donner la déclaration de la structure suivante :
 * etudiant
 * – le nom et le prénom
 * – la note du médian
 * – la note du final
 * – la note moyenne
 * 2. Ecrire une procédure/fonction pour saisir une phrase (avec l’espace) `a partir de clavier
 * 3. En utilisant un tableau dynamique type “etudiant”, écrire un programme pour sai-
 * sir une liste de N étudiants (la valeur de N sera saisie par l’utilisateur). La note
 * moyenne est donnée par en pondérant par 0.4 et 0.6 les notes du médian et du final,
 * respectivement.
 * 4. Ecrire une procédure/fonction permettant de trier cette liste d’étudiants par ordre
 * croissant selon le champ nom et prénom
 * 5. Trier selon la note moyenne
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Etudiant {
    char* nom;
    char* prenom;
    float median;
    float final;
    float moy;
};

/**
 * Permet de saisir une phrase de taille maximal tailleMax
 * @param chaine - pointeur vide où sera retourné la chaine de caractères
 * @param tailleMax - taille maximale de la chaine
 */
void saisiePhrase(char* chaine[], int tailleMax) 
{

    char *chaineTmp = NULL;
    char c;
    int n = 0;

    //Allocation dynamique du tableau temporaire
    chaineTmp = malloc(tailleMax*sizeof(char));
    if(chaineTmp == NULL) {
        printf("Impossible d'allouer de la mémoire");
        exit(0);
    }


    //Saisie
    do{
        scanf("%c", &c);
        //Ignore si l'utilisateur ne rentre rien
        if(c != '\n' || n != 0)
        {
            chaineTmp[n] = c;
            n++;            
        }
        else
        {
            c = 0;
        }
    }while(c != '\n' && n < tailleMax);

    //ajout du caractère de fin
    n--;
    chaineTmp[n] = 0;

    //Allication de la chaine finale
    *chaine = malloc(n*sizeof(char));
    if(*chaine == NULL) {
        printf("Impossible d'allouer de la mémoire");
        exit(0);
    }

    //Copie dans la chaine finale et suppression de la chaine temporaire
    strcpy(*chaine, chaineTmp);
    free(chaineTmp);
}




/**
 * Permet de saisir un nouvel etudiant
 * @return les données de l'étudiant dans une structure Etudiant
 */
struct Etudiant saisieEtudiant() 
{
    struct Etudiant etu;

    //Saisie du nom
    printf("Veuillez entrer le prénom de l'étudiant :\n");
    saisiePhrase(&etu.prenom, 255);

    //Saisie du prénom
    printf("Veuillez entrer le nom de famille de l'étudiant :\n");
    saisiePhrase(&etu.nom, 255);

    //Saisie du prénom
    printf("Veuillez entrer la note du médian de l'élève :\n");
    scanf("%f", &etu.median);

    //Saisie du prénom
    printf("Veuillez entrer la note du final de l'élève :\n");
    scanf("%f", &etu.final);

    //Calcul de la moyenne
    etu.moy = 0.4*etu.median + 0.6*etu.final;
    printf("La moyenne de l'élève est de : %f\n", etu.moy);

    return etu;
}


/**
 * Permet de saisir une liste des etudiants
 * @param etu - la liste des étudiants
 * @return Nombre d'étudiants dans la liste
 */
int saisieListeEtudiant(struct Etudiant* etu[]) 
{
    int i, nbrEtu;

    //Saisie du nombre d'étudiants
    printf("Veuillez entrer le nombre d'étudiants à saisir :\n");
    scanf("%d", &nbrEtu);

    //Alocation dynamique de la liste d'étudiants
    *etu = malloc(nbrEtu * sizeof(struct Etudiant));
    if(*etu == NULL) {
        printf("Impossible d'allouer de la mémoire");
        exit(0);
    }

    //Saisie des étudiants
    for (i = 0; i < nbrEtu; ++i)
    { 
        printf("------ Saisie de l'étudiant %d/%d ------\n", i+1, nbrEtu);
        (*etu)[i] = saisieEtudiant();
    }

    return nbrEtu;
}

/**
 * Permet de trier une liste des etudiants par nom puis prénom (Attention : la casse compte)
 * @param etu - la liste des étudiants
 * @param nbr - Nombre d'etudiants dans la liste
 */
void trierParNomListeEtudiant(struct Etudiant* etu[], int nbrEtu) 
{
    struct Etudiant temp;
    int i, j, cmp;

    //Parcours la liste
    for(i=0;i<nbrEtu-1;i++)
    {
        //Pour chaque element de la liste 
        //parcours le reste de la liste pour trouver le plus petit restant
        for(j=i+1;j<nbrEtu;j++)
        {
            ///Comparaison des noms
            cmp = strcmp((*etu)[i].nom, (*etu)[j].nom);
            //Si les noms sont identiques, comparaison des prénoms
            if(cmp == 0)
            {
                cmp = strcmp((*etu)[i].prenom, (*etu)[j].prenom);
            }

            if(cmp > 0)
            {
                temp=(*etu)[i];
                (*etu)[i]=(*etu)[j];
                (*etu)[j]=temp; 
            } 
        }
    }
}


/**
 * Permet de trier une liste des etudiants par la note moyenne
 * @param etu - la liste des étudiants
 * @param nbr - Nombre d'etudiants dans la liste
 */
void trierParMoyListeEtudiant(struct Etudiant* etu[], int nbrEtu) 
{
    struct Etudiant temp;
    int i, j;

    //Parcours la liste
    for(i=0;i<nbrEtu-1;i++)
    {
        //Pour chaque element de la liste 
        //parcours le reste de la liste pour trouver le plus petit restant
        for(j=i+1;j<nbrEtu;j++)
        {
            if((*etu)[i].moy > (*etu)[j].moy)
            {
                temp=(*etu)[i];
                (*etu)[i]=(*etu)[j];
                (*etu)[j]=temp; 
            } 
        }
    }
}


/**
 * Permet d'Afficher une liste d'élève
 * @param etu - la liste des étudiants
 * @param nbr - Nombre d'etudiants dans la liste
 */
void afficherListeEtudiant(struct Etudiant* etu[], int nbrEtu) 
{

    int i;
    //Parcours la liste
        printf("Nom Prénom | Median Final | Moyenne\n" );
    for(i=0;i<nbrEtu;i++)
    {
        printf("%s %s | %f %f | %f\n", (*etu)[i].nom, (*etu)[i].prenom, (*etu)[i].median, (*etu)[i].final, (*etu)[i].moy);
    }
}


int main(int argc, char const *argv[])
{
    //Init des variables
    struct Etudiant* etu;
    int nbrEtu;


    //Présentation
    printf("NF05 - TP3 - Exercice 22\n");
    printf("_______________________\n\n");


    nbrEtu = saisieListeEtudiant(&etu);
    printf("------------------------\n");
    printf("----- Liste saisie -----\n");
    afficherListeEtudiant(&etu, nbrEtu);


    printf("----- Liste triée par nom -----\n");
    trierParNomListeEtudiant(&etu, nbrEtu);
    afficherListeEtudiant(&etu, nbrEtu);

    printf("----- Liste triée par moyenne (croissant) -----\n");
    trierParMoyListeEtudiant(&etu, nbrEtu);
    afficherListeEtudiant(&etu, nbrEtu);

    return 0;
}