#include <stdio.h>
#include <stdlib.h>

int Choix_cible();
int Choix_missile();
void clean_stdin();
struct cible Enregistrement();

struct cible{
    int cibley;
    int ciblex;
    int missile;
};

int main(int argc, char const *argv[]) {
    int a=0;
    int nbcoup= 1;

    struct cible coup;
    coup = Enregistrement(nbcoup);

    a = coup.ciblex;
    printf("test : %d\n",a);
    a = coup.cibley;
    printf("test : %d\n",a);
    a = coup.missile;
    printf("test : %d\n",a);

    return 0;
}

/*
 * Fonction qui prend la valeur du nombre de coup et qui renvoit la valeur de la coordonée de la cible
 * @param a integer - le nombre de coup
 * @return a integer - la coordonnée de la cible
 */
int Choix_cible(int nbcoup, char* message) {
    int cible = 0;
    char keycible;
    char antibug;


    printf("Nous allons proceder au largage du projectile numero : %d. Quels sont les ordres ?\n", nbcoup);

    printf("%s \n",message);
    scanf("%c", &keycible);
    clean_stdin();
    cible = atoi(&keycible);
    if (cible < 1 || cible > 10) {
        do {
            printf("Ecrire un entier entre 1 et 10 \n");
            printf("%s \n",message);
            scanf("%c", &keycible);
            clean_stdin();
            cible = atoi(&keycible);
        } while (cible < 1 || cible > 10);
    }
    printf("Vous avez choisis : %d\n \n",cible);
    return cible;
}

/*
 * Fonction qui renvoit la valeur de la coordonée du missile
 * @param
 * @return a integer - la coordonnée du missile
 */
int Choix_missile(){
    char keycible;
    char antibug;
    int missile = 0;

    printf("Choisir le type de missile: \n");
    printf("1 : missile simple\n");
    printf("2 : missile tactique\n");
    printf("3 : bombe\n");
    printf("4 : missile de croisiere\n");
    scanf("%c", &keycible);
    clean_stdin();
    missile = atoi(&keycible);
    if (missile < 1 || missile > 4) {
        do {
            printf("Ecrire 1 2  3 ou 4 : \n");
            printf("Choisir le type de missile: \n");
            scanf("%c", &keycible);
            clean_stdin();
            missile = atoi(&keycible);
        } while (missile < 1 || missile > 4);
    }


    /*fonction qui donne l'information du bon choix de l'utilisateur*/
    switch (missile) {
        case 1:printf("Vous avez choisis : missile simple \n \n");
            break;
        case 2:printf("Vous avez choisis : missile tactique \n \n");
            break;
        case 3:printf("Vous avez choisis : bombe \n \n");
            break;
        case 4:printf("Vous avez choisis : missile de croisiere \n \n");
            break;
        default:printf("Erreur : cela ne devrait jamais arriver \n \n" );
            break;
    }
    return missile;
}

/*
 * Fonction qui rempli la structure cible avec les fonctions Choix_cible et Choix_missile
 * @param
 * @return a struct - structure cible locale
 */
struct cible Enregistrement(int nbcoup){

    struct cible local; // variable local;

    //remplissage de la structure cible locale avec les fonctions Choix_cible et Choix_missile
    local.cibley = Choix_cible(nbcoup,"Ordonnée - Choisir l'ordonnee de la cible entre 1 et 10");
    local.ciblex = Choix_cible(nbcoup,"Abscisse - Choisir l'abscisse de la cible entre 1 et 10");
    local.missile = Choix_missile();

    return local; //retourner une copie de la structure cible locale
}

/*
 * Fonction qui vide le buffer après une lecture de variable
 * @param
 * @return
 */
void clean_stdin(void)
{
    int c;

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}