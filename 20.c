/**
 * Auteur : Aurélien Labate
 * Date : 12/11/2014
 * UV : NF05
 *
 * Enoncé :
 *
 * - Définir un premier type de structure permettant de définir un nombre complexe sous 
 * forme cartésienne (partie réelle et partie imaginaire). Définir un deuxième type de
 * structure permettant de définir un nombre complexe sous for me polaire (module et
 * argument). Définir un troisième type de structure (Cplx) permettant de représenter
 * un complexe quelle que soit sa forme.
 * - Ecrire une fonction/procédure qui permet d’obtenir la forme polaire à partir de la
 * forme cartésienne ainsi que la fonction inverse.
 * - Ecrire deux fonctions/procédures (SomeCplx, SousCplx) permettant de calculer la
 * somme, la soustraction de deux nombres complexes.
 * - Ecrire deux fonctions/procédures (MulCplx, DivCplx) permettant de calculer le 
 * produit et la division de deux nombres complexes.
 * - Ecrire un programme qui résout une équation de second degré à coefficients complexes.
**/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct CplxCart {
    double re;
    double im;
};
struct CplxPol {
    double mod;
    double arg;
};
struct Cplx {
    struct CplxCart cart;
    struct CplxPol pol;
    int isCart; //Booléen indiquant si on utilise la partie polaire ou cartésienne
};


/**
 * Prend un point en coordonées cartésienne et retourne un point en coordonée polaire
 * @param input - Nombre complexe (Cplx)
 * @return nombre complexe (Cplx) convertit
 */
struct Cplx cartToPol(struct Cplx in) {
    struct Cplx out;

    //Calcule du module
    out.pol.mod = sqrt(in.cart.re*in.cart.re + in.cart.im*in.cart.im);

    //Calcule de l'argument
    out.pol.arg = atanf(in.cart.im/in.cart.re);

    out.isCart = 0;
    return out;
}

/**
 * Prend un point en coordonées polaire et retourne un point en coordonée cartésienne
 * @param input - Nombre complexe (CplxPol)
 * @return nombre complexe (Cplx) convertit
 */
struct Cplx polToCart(struct Cplx in) {
    struct Cplx out;

    //Calcule du module
    out.cart.re = in.pol.mod*cosf(in.pol.arg);

    //Calcule de la partie imagine
    out.cart.im = in.pol.mod*sinf(in.pol.arg);

    out.isCart = 1;
    return out;
}

/**
 * Fait la somme entre deux valeurs cartésienne
 * @param a - Premier terme de la somme
 * @param b - Second terme de la somme
 * @return somme complexe (Cplx)
 */
struct Cplx SomeCplx(struct Cplx a, struct Cplx b) {
    struct Cplx out;

    //Convertit les valeurs en cartesien pour faciliter le calcul
    int wasCart = 1;
    if(a.isCart != 1) {
        a = polToCart(a);
        wasCart = 0;
    }
    if(b.isCart != 1) {
        b = polToCart(b);
    }

    //Somme
    out.cart.re = a.cart.re + b.cart.re;
    out.cart.im = a.cart.im + b.cart.im;

    //Sortie
    out.isCart = 1;
    //Si a était en polaire, il convertit en polaire
    if(!wasCart)
        out = cartToPol(out);

    return out;
}


/**
 * Fait la différence entre deux valeurs cartésienne (a-b)
 * @param a - Premier terme de la soustraction
 * @param b - Second terme de la soustraction
 * @return différence complexe (Cplx)
 */
struct Cplx SousCplx(struct Cplx a, struct Cplx b) {
    struct Cplx out;

    //Convertit les valeurs en cartesien pour faciliter le calcul
    int wasCart = 1;
    if(a.isCart != 1) {
        a = polToCart(a);
        wasCart = 0;
    }
    if(b.isCart != 1) {
        b = polToCart(b);
    }

    //Soustraction
    out.cart.re = a.cart.re - b.cart.re;
    out.cart.im = a.cart.im - b.cart.im;

    //Sortie
    out.isCart = 1;
    //Si a était en polaire, il convertit en polaire
    if(!wasCart)
        out = cartToPol(out);

    return out;
}

/**
 * Fait la multiplication entre deux valeurs cartésienne (a*b)
 * @param a - Premier terme de la multiplication
 * @param b - Second terme de la multiplication
 * @return produit complexe (Cplx)
 */
struct Cplx MulCplx(struct Cplx a, struct Cplx b) {
    struct Cplx out;

    //Convertit les valeurs en cartesien pour faciliter le calcul
    int wasCart = 1;
    if(a.isCart != 1) {
        a = polToCart(a);
        wasCart = 0;
    }
    if(b.isCart != 1) {
        b = polToCart(b);
    }

    //Multiplication (a+ib)*(c+id)=(ac-bd)+i(ad+bc)
    out.cart.re = (a.cart.re*b.cart.re) - (a.cart.im*b.cart.im);
    out.cart.im = (a.cart.re*b.cart.im) + (a.cart.im*b.cart.re);


    //Sortie
    out.isCart = 1;
    //Si a était en polaire, il convertit en polaire
    if(!wasCart)
        out = cartToPol(out);

    return out;
}


/**
 * Fait la division entre deux valeurs complexe cartésienne (a*b)
 * @param a - Premier terme de la division
 * @param b - Second terme de la division
 * @return produit complexe (Cplx)
 */
struct Cplx DivCplx(struct Cplx a, struct Cplx b) {
    struct Cplx out;

    //Convertit les valeurs en cartesien pour faciliter le calcul
    int wasCart = 1;
    if(a.isCart != 1) {
        a = polToCart(a);
        wasCart = 0;
    }
    if(b.isCart != 1) {
        b = polToCart(b);
    }

    //Division (a+ib)/(c+id)=(ac+bd)/(c²+d²) + i(-ad+bc)/(c²+d²)
    out.cart.re = (a.cart.re*b.cart.re+a.cart.im*b.cart.im)/(b.cart.re*b.cart.re+b.cart.im*b.cart.im);
   out.cart.im = (-a.cart.re*b.cart.im+a.cart.im*b.cart.re)/(b.cart.re*b.cart.re+b.cart.im*b.cart.im);

    //Sortie
    out.isCart = 1;
    //Si a était en polaire, il convertit en polaire
    if(!wasCart)
        out = cartToPol(out);

    return out;
}


/**
 * Fait le module d'un complexe cartésienne
 * @param a - nombre complexe dont on veut le module
 * @return le module réel
 */
double ModCplx(struct Cplx a) {
    double out;

    //Convertit les valeurs en cartesien pour faciliter le calcul
    if(a.isCart != 1) {
        a = polToCart(a);
    }

    //module
    out = sqrt(a.cart.re*a.cart.re+a.cart.im*a.cart.im);

    return out;
}



/**
 * Fait la racine carré d'un complexe cartésienne
 * @param a - variable de la racine
 * @return la racine complexe (Cplx)
 */
struct Cplx SqrtCplx(struct Cplx a) {
    struct Cplx out;

    //Convertit les valeurs en cartesien pour faciliter le calcul
    int wasCart = 1;
    if(a.isCart != 1) {
        a = polToCart(a);
        wasCart = 0;
    }

    //Racine : sqrt((|a|+a)/2) + i * (b/|b|)*sqrt((|a|-a)/2)
    out.cart.re = sqrtf((ModCplx(a)+a.cart.re)/2);
    out.cart.im = (a.cart.im/fabs(a.cart.im))*sqrtf((ModCplx(a)-a.cart.re)/2);

    //Sortie
    out.isCart = 1;
    //Si a était en polaire, il convertit en polaire
    if(!wasCart)
        out = cartToPol(out);

    return out;
}



/**
 * Résout une equation du second degré à coef complexe ax²+bx+c=0
 * @param a - Le a de ax²+bx+c=0
 * @param b - Le b de ax²+bx+c=0
 * @param c - Le c de ax²+bx+c=0
 */
void Eq2Cplx(struct Cplx a, struct Cplx b, struct Cplx c) {
    struct Cplx out;
    struct Cplx delta;
    struct Cplx tmp;
    struct Cplx tmp2;

    //Resolution
    //degré 1 : b*x+c=0
    if(a.cart.re == 0 && a.cart.im == 0) {
        printf("On cherche à résoudre :\n");
        printf("(%lg+%lgi)*x + (%lg+%lgi) = 0\n",b.cart.re,b.cart.im,c.cart.re,c.cart.im);
        printf("_______________________\n");

        //La solution est -c/b
        c.cart.re = -c.cart.re;
        c.cart.im = -c.cart.im;
        out = DivCplx(c, b);

        //Affichage
        printf("L'équation est du premier degré et a une solution :\n");
        printf("x = %lg+%lgi\n", out.cart.re, out.cart.im);
    }
    //degré 2
    else {
        printf("On cherche donc à résoudre :\n");
        printf("(%lg+%lgi)*(x^2) + (%lg+%lgi)*x + (%lg+%lgi) = 0\n",a.cart.re,a.cart.im,b.cart.re,b.cart.im,c.cart.re,c.cart.im);
        printf("_______________________\n");

        //Calcul du discriminant : delta^2 = b*b-4*a*c;
        delta = MulCplx(b, b);
        tmp.cart.re = 4;
        tmp.cart.im = 0;
        tmp.isCart = 1;
        tmp = MulCplx(tmp, a);
        tmp = MulCplx(tmp, c);
        delta = SousCplx(delta, tmp);
        delta = SqrtCplx(delta);

        //Affichage et Calcul des solutions (-b+delta)/2a ou (-b-delta)/2a
        tmp = b;
        tmp.cart.re = -tmp.cart.re;
        tmp.cart.im = -tmp.cart.im;
        out = SomeCplx(tmp, delta);
        tmp2 = a;
        tmp2.cart.re = 2*tmp2.cart.re;
        tmp2.cart.im = 2*tmp2.cart.im;
        out = DivCplx(out,tmp2);
        printf("x=%lg+%lgi\nou\n",out.cart.re,out.cart.im);
        out = SousCplx(tmp, delta);
        out = DivCplx(out,tmp2);
        printf("x=%lg+%lgi\n",out.cart.re,out.cart.im);


    }
}



int main(int argc, char const *argv[])
{
    //init
    struct Cplx cplx1, cplx2, cplx3;

    cplx1.isCart = 1;
    cplx1.cart.re = 10.1;
    cplx1.cart.im = 3.14;

    cplx2.isCart = 1;
    cplx2.cart.re = 2;
    cplx2.cart.im = 2;


    cplx3.isCart = 1;
    cplx3.cart.re = 9;
    cplx3.cart.im = 1;

    //Présentation
    printf("NF05 - TP3 - Exercice 19\n");
    printf("_______________________\n\n");

    
    printf("Nombre en coord cartésien : %lf+%lfi\n", cplx1.cart.re, cplx1.cart.im);
    cplx1 = cartToPol(cplx1);
    printf("Nombre convertit en coord polaire : %lf*e^(i*%lf)\n", cplx1.pol.mod, cplx1.pol.arg);
    cplx1 = polToCart(cplx1);
    printf("Nombre convertit en coord cartésien : %lf+%lfi\n\n\n", cplx1.cart.re, cplx1.cart.im);

    //Somme
    printf("(%lf+%lfi) + (%lf+%lfi) = ", cplx1.cart.re, cplx1.cart.im, cplx2.cart.re, cplx2.cart.im);
    cplx1 = SomeCplx(cplx1,cplx2);
    printf("%lf+%lfi\n", cplx1.cart.re, cplx1.cart.im);

    //Soustracton
    printf("(%lf+%lfi) - (%lf+%lfi) = ", cplx1.cart.re, cplx1.cart.im, cplx2.cart.re, cplx2.cart.im);
    cplx1 = SousCplx(cplx1,cplx2);
    printf("%lf+i%lf\n", cplx1.cart.re, cplx1.cart.im);

    //Multiplication
    printf("(%lf+%lfi) * (%lf+%lfi) = ", cplx1.cart.re, cplx1.cart.im, cplx2.cart.re, cplx2.cart.im);
    cplx1 = MulCplx(cplx1,cplx2);
    printf("%lf+%lfi\n", cplx1.cart.re, cplx1.cart.im);

    //Division
    printf("(%lf+%lfi) / (%lf+%lfi) = ", cplx1.cart.re, cplx1.cart.im, cplx2.cart.re, cplx2.cart.im);
    cplx1 = DivCplx(cplx1,cplx2);
    printf("%lf+%lfi\n", cplx1.cart.re, cplx1.cart.im);

    //Equation second degré
    Eq2Cplx(cplx1,cplx2,cplx3);

    return 0;
}