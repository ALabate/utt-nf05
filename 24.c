/**
 * Auteur : Aurélien Labate
 * Date : 26/11/2014
 * UV : NF05
 *
 * Enoncé :
 * Le responsable d’une petite bibliothèque souhaite informatiser la gestion du prˆet des
 * livres. Chaque livre est identifié par une cˆote de 8 caract`eres, un titre, le nom de l’auteur
 * principal, le nom de l’éditeur, l’année de publication. A ces informations il faut ajouter
 * l’indication du prˆet (livre en prˆet ou en rayon) et la date de prˆet s’il y a lieu.
 * Voici une proposition pour la structure BibLivres
 *      typedef struct { char auteur [20] ; char titre [100] ; char cote [9] ; int annee;
 *      char editeur [10] ; char EnPret [5] ; date DateDePret ; }
 *      BibLivres ;
 * 1. Ecrire une procédure/fonction pour saisir les informations d’un livre.
 * 2. Ecrire une procédure/fonction permettant de saisir N livres (N sera donné par l’utili-
 * sateur) et de les enregistrer dans un fichier dont le nom du fichier est saisi par l’utili-
 * sateur. La première ligne du fichier contient le nombre de livres stockés. Chaque type
 * d’information d’un livre est stocké dans une ligne.
 * 3. Ecrire une procédure qui permet de lire le contenu dans un fichier de biblioth`eque en
 * utilisant un pointeur type BibLivres et l’allocation dynamique de la mémoire
 * 4. Ecrire une fonction qui permet de chercher les informations d’un livre. Le nom du
 * livre cherché sera donné par l’utilisateur. Si le livre demandé est trouvé, afficher ses
 * informations.
 * 5. Ecrire une procédure permettant de modifier certaines informations d’un livre de-
 * mandé (par exemple si un livre est rendu `a la biblioth`eque, il faut modifier EnPret,
 * DateDePret,...). Enregistrer ces informations sur le mˆeme fichier de source.
**/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Date {
    int jour;
    int mois;
    int annee;
};

struct BibLivres {
    char* titre;
    char* auteur;
    char* cote;
    int annee;
    char* editeur;
    int enPret;
    struct Date datePret;
};


void saisiePhrase(char* chaine[], int tailleMax, int canBeEmpty);
void saisiePhraseDefaut(char **chaine, int tailleMax, char* defaut);

struct BibLivres saisieLivre();
void afficherLivre(struct BibLivres livre);

int saisieBaseLivre(struct BibLivres* liste[]);
void afficherBaseLivre(struct BibLivres* liste, int nbrLivres);
void sauverBaseLivre(char* base, struct BibLivres* liste, int nbrLivres);
int lireBaseLivre(char* base, struct BibLivres* liste[]);

int trouverLivre(struct BibLivres* liste, int nbrLivres, char* titre);
void modifierLivre(struct BibLivres* livre);



int main(int argc, char const *argv[])
{
    struct BibLivres* liste = NULL;
    int nbrLivres, idLivre;
    char *base, *titre;
    char c;
    FILE *f;

    printf("NF05 - TP7 - Exercice 24\n");
    printf("_______________________\n\n");

    //Saisie
    printf("=== Saisie de la base de livre ===\n");
    nbrLivres = saisieBaseLivre(&liste);
    afficherBaseLivre(liste, nbrLivres);

    //Sauvegarde
    printf("=== Sauvegarde de la base de livre ===\n");
    printf("Veuillez entrer le nom du fichier de la base : \n");
    saisiePhrase(&base, 30, 0);
    sauverBaseLivre(base, liste, nbrLivres);

    //Lecture du fichier de sauvegarde
    printf("--------- Contenu du fichier de sauvegarde -----------\n");
    f = fopen(base, "r");
    c = 0;
    while(c != EOF)
    {
        if(c != 0)
            printf("%c", c);
        c = fgetc(f);
    }
    fclose(f);
    printf("------------------------------------------------------\n");

    //Reset des variables
    free(liste);
    nbrLivres = 0;

    //Lecture du fichier    
    printf("=== Lecture du fichier de la base de livre ===\n");
    nbrLivres = lireBaseLivre(base, &liste);

    afficherBaseLivre(liste, nbrLivres);

    //Recherche d'un livre
    printf("=== Recherche d'un livre ===\n");
    printf("Veuillez entrer le nom du livre que vous souhaitez trouver : \n");
    saisiePhrase(&titre, 100, 0);
    idLivre = trouverLivre(liste, nbrLivres, titre);
    printf("=========================\n");
    if(idLivre < 0)
    {
        printf("Aucun livre trouvé\n");
    }
    else
    {
        afficherLivre(liste[idLivre]);
        printf("=========================\n");
    }

    //Modification d'un livre
    printf("=== Modfication d'un livre ===\n");
    printf("Veuillez entrer le nom du livre que vous souhaitez modifier : \n");
    saisiePhrase(&titre, 100, 0);
    idLivre = trouverLivre(liste, nbrLivres, titre);
    if(idLivre < 0)
    {
        printf("Aucun livre trouvé\n");
    }
    else
    {
        modifierLivre(&liste[idLivre]);        
    }
    //Sauvegarde
    printf("=== Sauvegarde de la base de livre ===\n");
   sauverBaseLivre(base, liste, nbrLivres); 


    //Lecture du fichier de sauvegarde
    printf("--------- Contenu du fichier de sauvegarde -----------\n");
    f = fopen(base, "r");
    c = 0;
    while(c != EOF)
    {
        if(c != 0)
            printf("%c", c);
        c = fgetc(f);
    }
    fclose(f);
    printf("------------------------------------------------------\n");

    return 0;
}


/**
 * Permet de saisir une phrase de taille maximal tailleMax
 * @param chaine - pointeur vide où sera retourné la chaine de caractères
 * @param tailleMax - taille maximale de la chaine
 * @param canBeEmpty - 0 si ne peut pas être vide, 1 sinon
 */
void saisiePhrase(char* chaine[], int tailleMax, int canBeEmpty)
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
        c = fgetc(stdin);
        //Ignore si l'utilisateur ne rentre rien
        if(canBeEmpty || c != '\n' || n != 0)
        {
            chaineTmp[n] = c;
            n++;            
        }
        else
        {
            c = 0;
        }
    }while(c != '\n' &&  n < tailleMax);

    //ajout du caractère de fin
    n--;
    chaineTmp[n] = 0;

    //Allocation de la chaine finale
    *chaine = malloc(n*sizeof(char));
    if(*chaine == NULL) {
        printf("Impossible d'allouer de la mémoire");
        exit(0);
    }

    //Copie dans la chaine finale et suppression de la chaine temporaire
    strcpy(*chaine, chaineTmp);
    free(chaineTmp);
}


void saisiePhraseDefaut(char **chaine, int tailleMax, char* defaut)
{
    char* tmp = NULL;
    saisiePhrase(&tmp, tailleMax, 1);
    if(strlen(tmp) < 1)
    {
        free(tmp);
        *chaine = malloc(sizeof(char) * strlen(defaut));
        strcpy(*chaine, defaut);
    }
    else
    {
        *chaine = tmp;
    }
}


/**
 * Permet de saisir un élément de la bibliotheque
 * @return l'element BibLivre saisie
 */
struct BibLivres saisieLivre()
{
    struct BibLivres out;

    //Titre
    printf("Veuillez entrer le titre du livre : \n");
    saisiePhrase(&out.titre, 100, 0);

    //Auteur
    printf("Veuillez entrer l'auteur du livre : \n");
    saisiePhrase(&out.auteur, 20, 0);

    //Cote
    printf("Veuillez entrer la cote du livre : \n");
    saisiePhrase(&out.cote, 9, 0);

    //Annee
    printf("Veuillez entrer l'annee du livre : \n");
    scanf("%d", &out.annee);

    //Editeur
    printf("Veuillez entrer l'editeur du livre : \n");
    saisiePhrase(&out.editeur, 10, 0);

    //en pret
    printf("Veuillez dire si le livre est en pret (1 pour oui, 0 pour non) : \n");
    scanf("%d", &out.enPret);

    if(out.enPret)
    {
        printf("Veuillez entrer le jour de pret :\n");
        scanf("%d", &out.datePret.jour);
        printf("Veuillez entrer le mois de pret :\n");
        scanf("%d", &out.datePret.mois);
        printf("Veuillez entrer l'année de pret :\n");
        scanf("%d", &out.datePret.annee);
    }
    else
    {
       out.datePret.jour = 0;
       out.datePret.mois = 0;
       out.datePret.annee = 0;
    }

    return out;
}


/**
 * Permet d'afficher un livre dans la console
 * @param livre - l'element BibLivre à affichier
 */
void afficherLivre(struct BibLivres livre)
{
    printf("Titre : %s\n", livre.titre);
    printf("Auteur : %s\n", livre.auteur);
    printf("Cote : %s\n", livre.cote);
    printf("Annee : %d\n", livre.annee);
    printf("Editeur : %s\n", livre.editeur);
    if(livre.enPret) 
    {        
        printf("En pret : oui\n");
        printf("Date du pret : %d.%d.%d\n", livre.datePret.jour, livre.datePret.mois, livre.datePret.annee);
    }
    else
    {
        printf("En pret : non\n");
    }

}


/**
 * Permet de saisir ue liste de livres
 * @param liste - Un pointeur vers l'adresse du tableau
 * @return le nombre de livres saisis
 */
int saisieBaseLivre(struct BibLivres* liste[])
{

    int nbrLivres, i;

    printf("Veuillez entrer le nombre de livres à saisir : \n");
    scanf("%d", &nbrLivres);

    *liste = malloc(nbrLivres*sizeof(struct BibLivres));
    if(*liste == NULL) {
        printf("Impossible d'allouer de la mémoire");
        exit(0);
    }

    //Saisie
    for (i = 0; i < nbrLivres; ++i)
    {
        (*liste)[i] = saisieLivre();
    }

    return nbrLivres;
}


/**
 * Permet d'afficher une liste de livres
 * @param liste - La liste de livre
 * @param nbrLivres - le nombre de livres à afficher
 */
void afficherBaseLivre(struct BibLivres* liste, int nbrLivres)
{
    int i;
    //Affichage
    printf("=========================\n");
    for (i = 0; i < nbrLivres; ++i)
    {
        if(i != 0)
            printf("--------------\n");
        afficherLivre(liste[i]);
    }
    printf("=========================\n");
}



/**
 * Permet de créer fichier de base de donnée de livres a partir d'une liste de livres
 * @param base - Le nom du fichier de sauvegarde
 * @param liste - la liste de livre à sauvegarder
 * @param nbrLivres - Le nombre de livre dans la liste
 */
void sauverBaseLivre(char* base, struct BibLivres* liste, int nbrLivres)
{
    FILE *f;
    f = fopen(base, "w");
    int i;

    //Ecriture du nombre de livres
    fprintf(f, "%d\n", nbrLivres);

    for (i = 0; i < nbrLivres; ++i)
    {
        //Ecriture des données du livre
        fprintf(f, "%s\n", liste[i].titre);
        fprintf(f, "%s\n", liste[i].auteur);
        fprintf(f, "%s\n", liste[i].cote);
        fprintf(f, "%d\n", liste[i].annee);
        fprintf(f, "%s\n", liste[i].editeur);
        fprintf(f, "%d\n", liste[i].enPret);
        fprintf(f, "%d\n", liste[i].datePret.jour);
        fprintf(f, "%d\n", liste[i].datePret.mois);
        fprintf(f, "%d\n", liste[i].datePret.annee);
    }
    fclose(f);
}


/**
 * Permet de lire fichier de base de donnée de livres
 * @param liste - pointeur vide vers la liste qui sera remplie
 * @param base - Le nom du fichier de sauvegarde
 * @return Le nombre de livres
 */
int lireBaseLivre(char* base, struct BibLivres* liste[])
{
    FILE *f;
    f = fopen(base, "r");
    int i, nbrLivres;
    char buffer[100];

    //Lecture du nombre de livres
    fscanf(f, "%d\n", &nbrLivres);
    printf("Nombre de livres : %d\n", nbrLivres);

    //Allocation de la base
    *liste = malloc(nbrLivres*sizeof(struct BibLivres));
    if(*liste == NULL) {
        printf("Impossible d'allouer de la mémoire");
        exit(0);
    }

    for (i = 0; i < nbrLivres; ++i)
    {
        //Lecture Titre
        fgets(buffer, sizeof(buffer), f);
        buffer[strlen(buffer)-1] = 0; //Remove \n at the end
        (*liste)[i].titre = malloc(strlen(buffer)*sizeof(char));
        strcpy((*liste)[i].titre, buffer);

        //Lecture Auteur
        fgets(buffer, sizeof(buffer), f);
        buffer[strlen(buffer)-1] = 0;
        (*liste)[i].auteur = malloc(strlen(buffer)*sizeof(char));
        strcpy((*liste)[i].auteur, buffer);

        //Lecture Cote
        fgets(buffer, sizeof(buffer), f);
        buffer[strlen(buffer)-1] = 0;
        (*liste)[i].cote = malloc(strlen(buffer)*sizeof(char));
        strcpy((*liste)[i].cote, buffer);

        //Année
        fscanf(f, "%d\n", &(*liste)[i].annee);

        //Lecture editeur
        fgets(buffer, sizeof(buffer), f);
        buffer[strlen(buffer)-1] = 0;
        (*liste)[i].editeur = malloc(strlen(buffer)*sizeof(char));
        strcpy((*liste)[i].editeur, buffer);

        //En pret
        fscanf(f, "%d\n", &(*liste)[i].enPret);

        //Date pret
        fscanf(f, "%d\n", &(*liste)[i].datePret.jour);
        fscanf(f, "%d\n", &(*liste)[i].datePret.mois);
        fscanf(f, "%d\n", &(*liste)[i].datePret.annee);

    }
    fclose(f);

    return nbrLivres;
}


/**
 * Permet de lire fichier de base de donnée de livres
 * @param liste - La liste de livres
 * @param nbrLivres - Le nombre de livres
 * @param titre - Le titre du livre à trouver
 * @return L'id du livre trouvé ou -1 si non trouvé
 */
int trouverLivre(struct BibLivres* liste, int nbrLivres, char* titre)
{
    int i, tmp;
    for (i = 0; i < nbrLivres; ++i)
    {
        if(strcmp(titre, liste[i].titre) == 0)
            return i;
    }
    return -1;
}

/**
 * Modifie un livre en proposant les valeurs originals par defaut
 * @param livre - le livre 
 */
void modifierLivre(struct BibLivres *livre)
{
    char *input = NULL;
    char defaut[100];
    int tmp;

    printf("Veuillez entrer le nouveau titre du livre [Defaut:%s]\n", livre->titre);
    saisiePhraseDefaut(&livre->titre, 100, livre->titre);

    printf("Veuillez entrer le nouvel auteur du livre [Defaut:%s]\n", livre->auteur);
    saisiePhraseDefaut(&livre->auteur, 20, livre->auteur);

    printf("Veuillez entrer la nouvelle cote du livre [Defaut:%s]\n", livre->cote);
    saisiePhraseDefaut(&livre->cote, 9, livre->cote);

    sprintf(defaut, "%d", livre->annee);
    printf("Veuillez entrer la nouvelle annee du livre [Defaut:%d]\n", livre->annee);
    saisiePhraseDefaut(&input, 5, defaut);
    if(strlen(input) > 1)
        sscanf(input, "%d", &livre->annee);
    free(input);

    printf("Veuillez entrer le nouvel editeur du livre [Defaut:%s]\n", livre->editeur);
    saisiePhraseDefaut(&livre->editeur, 10, livre->editeur);

    printf("Veuillez dire si le livre est en pret (1 pour oui, 0 pour non) [Defaut:%d] : \n", livre->enPret);
    sprintf(defaut, "%d", livre->enPret);
    saisiePhraseDefaut(&input, 2, defaut);
    if(input[0] == '1') {
        livre->enPret = 1;
    }
    else if(input[0] == '0') 
    {
        livre->enPret = 0;
        livre->datePret.jour = 0;
        livre->datePret.mois = 0;
        livre->datePret.annee = 0;
    }
    free(input);

    if(livre->enPret == 1)
    {

        sprintf(defaut, "%d", livre->datePret.jour);
        printf("Veuillez entrer le nouveau jour de pret du livre [Defaut:%d]\n", livre->datePret.jour);
        saisiePhraseDefaut(&input, 5, defaut);
        if(strlen(input) > 1)
            sscanf(input, "%d", &livre->datePret.jour);
        free(input);

        sprintf(defaut, "%d", livre->datePret.mois);
        printf("Veuillez entrer le nouveau mois de pret du livre [Defaut:%d]\n", livre->datePret.mois);
        saisiePhraseDefaut(&input, 5, defaut);
        if(strlen(input) > 1)
            sscanf(input, "%d", &livre->datePret.mois);
        free(input);

        sprintf(defaut, "%d", livre->datePret.annee);
        printf("Veuillez entrer la nouvelle annee du pret du livre [Defaut:%d]\n", livre->datePret.annee);
        saisiePhraseDefaut(&input, 5, defaut);
        if(strlen(input) > 1)
            sscanf(input, "%d", &livre->datePret.annee);
        free(input);

    }
}