#include <stdio.h>
#include <stdlib.h>

int modes(char* CHOIX, char* choix1,char* choix2,char* choix3);
struct grid debut_grille();
void show_grid();
int Choix_cible();
int Choix_missile();
void clean_stdin();
struct cible Enregistrement();
struct grid msimple();
struct grid mtactique();

struct cible{
    int cibley;
    int ciblex;
    int missile;
};

struct grid{
    char grille[12][12];
    int largeur;
    int longeur
};

struct bcomplet{
    int boatx;
    int boaty;
    int touche;
    int nboat;
};

int main(int argc, char const *argv[]) {
    struct grid grille;
    grille = debut_grille();
    show_grid(grille);

    //

    int c=0,a=0,b=0;

    //test des 3 modes
    a = modes("Menu","Demarrer","Charger","Quitter");
    printf("test : %d",a);
    b = modes("Mode","Classique","Blind","Active");
    printf("test : %d",b);
    c = modes("Difficulte","Facile","Moyen","Difficile");
    printf("test : %d \n",c);

    //

    int g=0;
    int nbcoup= 1;

    struct cible coup;
    coup = Enregistrement(nbcoup);

    g = coup.ciblex;
    printf("test : %d\n",coup.ciblex);
    g = coup.cibley;
    printf("test : %d\n",coup.cibley);
    g = coup.missile;
    printf("test : %d\n",coup.missile);

    struct bcomplet boat_complet[17];

    if (coup.missile == 1){
        grille=msimple(coup,grille,boat_complet);
        show_grid(grille);
    }

    return 0;
}


/*
 * Fonction qui réinitialise la structure grid
 * @param
 * @return
 */
struct grid debut_grille(void){
    struct grid grille1;

    char glocal[12][12] = {" ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"};

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            grille1.grille[i][j]=glocal[i][j];
        }
    }
    return grille1;
}

/*
 * Fonction qui affiche la grille avec la structure grid
 * @param
 * @return
 */
void show_grid(struct grid grille0){


    printf(" ");
    for (int i = 1; i < 11; i++)
    {
        printf(" ");
        printf("%d",i);
    }
    printf("\n");
    for (int i = 1; i < 11; i++)
    {
        printf("%d",i);
        for (int j = 1; j < 11; j++)
        {
            if(j==1 && i!=10){
                printf(" ");
            }
            printf("%c ",grille0.grille[i][j]);
        }
        printf("\n");
    }
}


/*
 * Fonction qui prend le type de choix , la valeurs des 3 choix possible et renvoit ce qu'a choisi l'utilisateur
 * @param a char* - le type de choix
 * @param a char* - le premier choix possible
 * @param a char* - le second choix possible
 * @param a char* - le troisième choix possible
 * @return an integer - la sortie du choix de l'utilisateur
 */
int modes(char* CHOIX,char* choix1,char* choix2,char* choix3) {
    int menu = 0;
    char keymenu;

    printf("%s - Choisir 1: %s 2: %s 3: %s \n",CHOIX,choix1,choix2,choix3);
    scanf("%c", &keymenu); // lecture du choix de l'utilisateur
    clean_stdin();// vidage du buffer
    menu = atoi(&keymenu); // conversion du caractère en entier

    /*fonction qui répète l'opération tant que le choix n'est pas 1, 2 ou 3*/
    if (menu < 1 || menu > 3) {
        do {
            printf("Ecrire 1 2 ou 3 : \n");
            printf("%s - Choisir 1: %s 2: %s 3: %s \n",CHOIX,choix1,choix2,choix3);
            scanf("%c", &keymenu); // lecture du choix de l'utilisateur
            clean_stdin();// vidage du buffer
            menu = atoi(&keymenu); // conversion du caractère en entier
        } while (menu < 1 || menu > 3);
    }

    /*fonction qui donne l'information du bon choix de l'utilisateur*/
    switch (menu) {
        case 1:printf("%s - Vous avez choisis : %s \n \n",CHOIX, choix1);
            break;
        case 2:printf("%s - Vous avez choisis : %s \n \n",CHOIX, choix2);
            break;
        case 3:printf("%s - Vous avez choisis : %s \n \n",CHOIX, choix3);
            break;
        default:printf("Erreur : cela ne devrait jamais arriver \n \n" );
            break;
    }

    return menu;
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
    local.cibley = Choix_cible(nbcoup,"Ordonnee - Choisir l'ordonnee de la cible entre 1 et 10");
    local.ciblex = Choix_cible(nbcoup,"Abscisse - Choisir l'abscisse de la cible entre 1 et 10");
    local.missile = Choix_missile();

    return local; //retourner une copie de la structure cible locale
}

/*
 * Fonction qui tire un missile simple en appelant la fonction Enregistrement
 * @param nbcoup-nombre de coups
 * @return
 */
struct grid msimple(struct cible msimple,struct grid grille1,struct bcomplet boat_completms[17]){

    for (int i = 1; i < 18; i++)
    {
        if (msimple.ciblex == boat_completms[i].boatx && msimple.cibley == boat_completms[i].boaty){
            grille1.grille[boat_completms[i].boaty][boat_completms[i].boatx] = 'X';
        } else{
            grille1.grille[msimple.cibley][msimple.ciblex] = 'O';
        }
    }
    return grille1;
}

/*
 * Fonction qui tire un missile tactique en appelant la fonction Enregistrement
 * @param nbcoup-nombre de coups
 * @return
 */
struct grid mtactique(struct cible mtactique,struct grid grille2,struct bcomplet boat_completmt[17]){

    int coupfatal=0;

    for (int i = 1; i < 18; i++)
    {
        if (mtactique.ciblex == boat_completmt[i].boatx && mtactique.cibley == boat_completmt[i].boaty){
            grille2.grille[boat_completmt[i].boaty][boat_completmt[i].boatx] = 'X';
            coupfatal = coupfatal +1;

            for (int j = 1; j < 18; j++){
                if (coupfatal != 0 && boat_completmt[j].nboat == boat_completmt[i].nboat){
                    grille2.grille[boat_completmt[j].boaty][boat_completmt[j].boatx] = 'X';
                }
            }

        } else{
            grille2.grille[mtactique.cibley][mtactique.ciblex] = 'O';
        }
    }
    return grille2;
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