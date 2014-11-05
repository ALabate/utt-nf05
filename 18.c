/**
 * Auteur : Aurélien Labate
 * Date : 05/11/2014
 * UV : NF05
 *
 * Enoncé :
 * - Ecrire une fonction booléenne qui détermine si une année est bissextile
 * - Ecrire une fonction qui calcule le nombre de jours écoulés depuis une 
 * année de référence sais par l'utilisateur (depuis le 1er janvier de cette année là)
**/


#include <stdio.h>
#include <stdlib.h>

#include <time.h>

/**
 * Test si une annee est bissextile
 * @param annee - Annee a tester
 * @return 1 si bissextile 0 sinon
 */
int estBissextile(int annee) 
{
    //soit divisibles par 4 mais non divisibles par 100 ;
    //soit divisibles par 400.
    return (annee%400==0 || (annee%4==0 && annee%100!=0));
}


/**
 * Donne le nombre de jours entre deux dates dates (dont la premiere est au 1er janvier)
 * @param annee1 - Annee de la premiere date
 * @param annee2 - Annee de la seconde date
 * @param mois2 - Mois de la seconde date (1=janvier, .. 12=decembre)
 * @param jour2 - Jour de la seconde date (la jour est compté comme terminé et donc dans la somme de jours)
 * @return nombre de jours entre les deux dates
 */
int joursDiffAnnees(int annee1, int annee2, int mois2, int jour2) 
{
    //Recuperation du nombre d'années bissextiles entre les deux dates
    int jours = 0, i;

    //Ajout du nombre d'annes au total de jours
    for (i = annee1; i < annee2; ++i)
    {
        if (estBissextile(i))
            jours+=366;
        else
            jours+=365;
    }

    //Ajout du nombre de mois au total de jours
    switch(mois2) {
        case 12: jours+=30;//Nombre de jours de novembre
        case 11: jours+=31;
        case 10: jours+=30;
        case 9: jours+=31;
        case 8: jours+=31;
        case 7: jours+=30;
        case 6: jours+=31;
        case 5: jours+=30;
        case 4: jours+=31;
        case 3:
            if(estBissextile(annee2))
                jours+=29;
            else
                jours+=28;
        case 2: jours+=31;//Nombre de jours de janvier
    }

    //Ajout du nombre de jours au total de jours
    jours+=jour2;

    return jours;
}



int main(int argc, char const *argv[])
{
    //Init des variables
    int anneeInput, actAnnee, actMois, actJour;


    //Présentation
    printf("NF05 - TP3 - Exercice 18\n");
    printf("_______________________\n\n");

    printf("Veuillez entrer l'année actuelle (>1):\n");
    scanf("%d", &actAnnee);
    printf("Veuillez entrer le mois actuelle (1 à 12) :\n");
    scanf("%d", &actMois);
    printf("Veuillez entrer le jour actuel actuelle (1 à 31) :\n");
    scanf("%d", &actJour);
    printf("Veuillez entrer l'année depuis laquelle vous souhaitez avoir le nombre de jours (>1 et dans le passé):\n");
    scanf("%d", &anneeInput);


    printf("Le nombre de jours entre le 01/01/%d et le %d/%d/%d est de :\n", anneeInput, actAnnee, actMois, actJour);
    printf("%d\n", joursDiffAnnees(anneeInput, actAnnee, actMois, actJour));
    return 0;
}