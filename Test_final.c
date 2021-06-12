#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//intialisation de toutes les fonctions utilisés
int modes(char* CHOIX, char* choix1,char* choix2,char* choix3);
struct grid debut_grille();
void show_grid();
int Choix_cible();
int Choix_missile();
void clean_stdin();
struct cible Enregistrement();
struct grid fire_simple();
struct grid fire_tactique();
int test(int taille, int abscisse, int ordonnee, char orientation, char matrice[10][10]);
void matrice_affich();
struct grid fire_artillerie();
struct grid fire_bombe();
int is_alive();

/* structure type pour des bateaux*/
typedef struct{ //structure des cases génératices des bateaux
    char orientation;
    int taille;
    int abscisse;
    int ordonnee;
}bateau;

struct cible{ //Structure du missile tiré (Coordonées et type de missiles)
    int cibley;
    int ciblex;
    int missile;
};

struct grid{ //structure de la grille
    char grille[12][12];
    int largeur;
    int longeur
};

struct bcomplet{ //Ensembles de toutes les cases de chaque bateaux
    int boatx;
    int boaty;
    int touche;
    int nboat;
};

struct inventory_s{ //inventaire des missiles
    int msimple;
    int mtactique;
    int martillerie;
    int mbombe;
};

int main(int argc, char const *argv[]) {
    //initialisation des structures utilisés
    struct grid grille;
    struct bcomplet boat_complet[17];
    struct inventory_s inventory;
    struct cible coup;

    int nbcoup =0; //nombre de coups tirés

    int Menu=0, Mode=0,Difficulte=0;

    //test des 3 modes
    Menu = modes("Menu","Demarrer","Charger","Quitter");
    if (Menu == 1){ //si menu = Demarrer

        /*______________________________________________________________________________________________________________________________________________________________________*/
        //Placement des 5 bateaux et enregistrement dans la structure test
        //1ere Partie :
        srand(time(0)); //initialisation de l'aléatoire

        int taille, abscisse, ordonnee, retour;  /* Init des Variables */
        char orientation;
        char matrice_test[10][10]={0};
        int localint =1;

        bateau boat[5];  /* 5 Unit Bateau générateur*/

        for(int nb=0; nb<4; nb++){  /* Bateau 2, 3, 4, 5 */
            taille = nb+2;//initialisation de la taille
            boat[nb].taille=taille;

            //initialisation de la posotion aléatoire de l'orientation
            int choix = rand()%2; //random entre 0 et 1
            if (choix == 1){
                orientation = 'h';
            }else{
                orientation = 'v';
            }
            boat[nb].orientation = orientation;

            //initialisation des coordonées générateurs entre 0 et 9 tant que le test des positions n'est pas nul
            do{
                abscisse = rand()%10;  /* randomise ordonnée et abscisse */
                ordonnee = rand()%10;

                retour=test(taille, abscisse, ordonnee, orientation, matrice_test); /* attribue une valeur à retour pour savoir si la fonction retour est ok */
            }while(retour==1);

            boat[nb].abscisse=abscisse; /* attribue les valeur définitive d'un bateau à la structure des cases génératrise*/
            boat[nb].ordonnee=ordonnee;

            if (boat[nb].orientation =='h'){
                for (int i=0; i < taille; i++){
                    //Pose les bateaux sur la matrice test d'affichage
                    matrice_test[boat[nb].ordonnee][boat[nb].abscisse+i] = taille+'0';

                    //Enregistrement des valeurs de chaque cases dans la structure bcomplet
                    boat_complet[localint].boaty = ordonnee+1;
                    boat_complet[localint].boatx = abscisse+i+1;
                    boat_complet[localint].nboat = taille;
                    boat_complet[localint].touche = 0;
                    localint = localint+1;
                }

            }else{
                for (int i=0; i < taille; i++) {
                    //Pose les bateaux sur la matrice test d'affichage
                    matrice_test[boat[nb].ordonnee+i][boat[nb].abscisse] = taille+'0';

                    //Enregistrement des valeurs de chaque cases dans la structure bcomplet
                    boat_complet[localint].boaty = ordonnee+i+1;
                    boat_complet[localint].boatx = abscisse+1;
                    boat_complet[localint].nboat = taille;
                    boat_complet[localint].touche = 0;
                    localint = localint+1;
                }
            }
        }
        /*___________________________________________________PARTIE POUR 2'eme bateau de 3______________________________________________________________________________________*/

        taille = 3; //initialisation de la taille
        boat[4].taille=taille;

        //initialisation de la posotion aléatoire de l'orientation
        int choix = rand()%2; //random entre 0 et 1
        if (choix == 1){
            orientation = 'h';
        }else{
            orientation = 'v';
        }
        boat[4].orientation = orientation;

        //initialisation des coordonées générateurs entre 0 et 9 tant que le test des positions n'est pas nul
        do{
            abscisse = rand()%10;  /* randomise ordonnée et abscisse */
            ordonnee = rand()%10;

            retour=test(taille, abscisse, ordonnee, orientation, matrice_test); /* attribue une valeur à retour pour savoir si la fonction retour est ok */
        }while(retour==1);

        boat[4].abscisse=abscisse; /* attribue les valeur définitive d'un bateau */
        boat[4].ordonnee=ordonnee;

        if (boat[4].orientation =='h'){
            for (int i=0; i < taille; i++){
                /* Pose les bateaux sur la matrice test */
                matrice_test[boat[4].ordonnee][boat[4].abscisse+i] = taille+'0';

                //Enregistrement des valeurs de chaque cases dans la structure bcomplet
                boat_complet[localint].boaty = ordonnee+1;
                boat_complet[localint].boatx = abscisse+i+1;
                boat_complet[localint].nboat = taille;
                boat_complet[localint].touche = 0;
                localint = localint+1;
            }

        }else{
            for (int i=0; i < taille; i++) {
                /* Pose les bateaux sur la matrice test */
                matrice_test[boat[4].ordonnee+i][boat[4].abscisse] = taille+'0';

                //Enregistrement des valeurs de chaque cases dans la structure bcomplet
                boat_complet[localint].boaty = ordonnee+1+i;
                boat_complet[localint].boatx = abscisse+1;
                boat_complet[localint].nboat = taille;
                boat_complet[localint].touche = 0;
                localint = localint+1;
            }
        }
        //afichage des position des bateaux sur une grille
        //matrice_affich(matrice_test);
        /*______________________________________________________________________________________________________________________________________________________________________*/


        // Choix du mode et de la dificulté
        Mode = modes("Mode","Classique","Blind","Active");
        Difficulte = modes("Difficulte","Facile","Moyen","Difficile");

        grille = debut_grille();

        //initialisation des inventaires en fonction de la difficulté choisis
        if (Difficulte==1){
            inventory.msimple = 10;
            inventory.martillerie = 10;
            inventory.mtactique = 10;
            inventory.mbombe = 10;
        }
        if (Difficulte==2){
            inventory.msimple = 10;
            inventory.martillerie = 3;
            inventory.mtactique = 5;
            inventory.mbombe = 5;
        }
        if (Difficulte==3){
            inventory.msimple = 15;
            inventory.martillerie = 1;
            inventory.mtactique = 4;
            inventory.mbombe = 2;
        }
        // initialisation du nombre de coups
        nbcoup = 0;

        int test_a =1;
        do {
            int check_alive;

            printf("Inventory : \n missile simple = %d \n missile tactique = %d \n bombe = %d \n missile d'artillerie = %d \n",inventory.msimple,inventory.mtactique,inventory.mbombe,inventory.martillerie);

            nbcoup = nbcoup+1;
            coup = Enregistrement(nbcoup);

            if (coup.missile == 1){
                inventory.msimple=inventory.msimple-1;
                grille=fire_simple(coup,grille,boat_complet);
                if (Mode ==1 ||Mode==3){
                    show_grid(grille);
                }
            }
            if (coup.missile == 2){
                inventory.mtactique=inventory.mtactique-1;
                grille=fire_artillerie(coup,grille,boat_complet);
                if (Mode ==1 ||Mode==3){
                    show_grid(grille);
                }
            }
            if (coup.missile == 3){
                inventory.mbombe=inventory.mbombe-1;
                grille=fire_bombe(coup,grille,boat_complet);
                if (Mode ==1 ||Mode==3){
                    show_grid(grille);
                }
            }
            if (coup.missile == 4){
                inventory.martillerie=inventory.martillerie-1;
                grille=fire_artillerie(coup,grille,boat_complet);
                if (Mode ==1 ||Mode==3){
                    show_grid(grille);
                }
            }

            check_alive = is_alive(grille);

            if(check_alive == 0){
                printf("Vous avez aneanti tous les bateaux. Felicitation !");
                return 0;
            }

            if((inventory.martillerie!=0) && (inventory.mbombe!=0) && (inventory.mtactique!=0) && (inventory.msimple!=0)){
                test_a = 0;
            }else{
                test_a =1;
            }

        }while (test_a == 1);

        printf("Vous avez epuise le stock de missiles. Retentez votre chance");

    }

    if(Menu == 2){
        int test_a =1;
        do {
            int check_alive;

            printf("Inventory : \n missile simple = %d \n missile tactique = %d \n bombe = %d \n missile d'artillerie = %d \n",inventory.msimple,inventory.mtactique,inventory.mbombe,inventory.martillerie);

            nbcoup = nbcoup+1;
            coup = Enregistrement(nbcoup);

            if (coup.missile == 1){
                inventory.msimple=inventory.msimple-1;
                grille=fire_simple(coup,grille,boat_complet);
                if (Mode ==1 ||Mode==3){
                    show_grid(grille);
                }
            }
            if (coup.missile == 2){
                inventory.mtactique=inventory.mtactique-1;
                grille=fire_artillerie(coup,grille,boat_complet);
                if (Mode ==1 ||Mode==3){
                    show_grid(grille);
                }
            }
            if (coup.missile == 3){
                inventory.mbombe=inventory.mbombe-1;
                grille=fire_bombe(coup,grille,boat_complet);
                if (Mode ==1 ||Mode==3){
                    show_grid(grille);
                }
            }
            if (coup.missile == 4){
                inventory.martillerie=inventory.martillerie-1;
                grille=fire_artillerie(coup,grille,boat_complet);
                if (Mode ==1 ||Mode==3){
                    show_grid(grille);
                }
            }

            check_alive = is_alive(grille);

            if(check_alive == 0){
                printf("Vous avez aneanti tous les bateaux. Felicitation !");
                return 0;
            }

            if((inventory.martillerie!=0) && (inventory.mbombe!=0) && (inventory.mtactique!=0) && (inventory.msimple!=0)){
                test_a = 0;
            }else{
                test_a =1;
            }

        }while (test_a == 1);

        printf("Vous avez epuise le stock de missiles. Retentez votre chance");

    }

    return 0;
}


/*
 * Fonction qui réinitialise la structure grid
 * @param
 * @return struct grid debut_grille - structure de la grille
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
 * @param struct grid grille0 - structure de la grille
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
 * Fonction qui va tester si valeur du bateau peut être contenu dans toute la grille sans se chevaucher
 * @param a integer - la taille
 * @param a integer - l'abscisse
 * @param a integer - l'ordonee
 * @param a char - l'orientattion
 * @param a char - la matrice test
 * @return a integer - le test 0 ou 1
 */
int test(int taille, int abscisse, int ordonnee, char orientation, char matrice[10][10]){  /* vérifie possibibilité poser bateau */
    int retour=0;
    for (int i = 0; i < taille; i++){
        if (orientation=='v'){
            if (ordonnee+i<10 && matrice[ordonnee+i][abscisse]==0){
            }else{
                retour=1;
            }
        }
        else if (orientation=='h'){
            if(abscisse+i<10 && matrice[ordonnee][abscisse+i]==0){
            }else{
                retour=1;
            }
        }else{
            retour=1;
        }
    }
    return retour;
}

/*
 * Fonction qui affiche la matrice test en une grille 10*10 (dev)
 * @param a char - la matrice test
 * @return
 */
void matrice_affich(char matrice[10][10]){
    printf("\nTEST PRINT GRID\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrice[i][j]==0){
                printf("x ");
            }else{
                printf("%c ",matrice[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
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
 * Fonction qui tire un missile simple
 * @param struct cible msimple - structure de la cible
 * @param struct grid grille1 - structure de la grille
 * @param struct bcomplet boat_completms[17] - structure des 17 cases des bateaux
 * @return struct grid grille1 - structure de la grille
 */
struct grid fire_simple(struct cible msimple,struct grid grille1,struct bcomplet boat_completms[17]){

    for (int i = 1; i < 18; i++)
    {
        if (msimple.ciblex == boat_completms[i].boatx && msimple.cibley == boat_completms[i].boaty){
            grille1.grille[boat_completms[i].boaty][boat_completms[i].boatx] = 'X';
        } else{
            if(grille1.grille[msimple.cibley][msimple.ciblex] != 'X'){
                grille1.grille[msimple.cibley][msimple.ciblex] = 'O';
            }
        }
    }
    return grille1;
}

/*
 * Fonction qui tire un missile tactique
 * @param struct cible mtactique - structure de la cible
 * @param struct grid grille2 - structure de la grille
 * @param struct bcomplet boat_completmt[17] - structure des 17 cases des bateaux
 * @return struct grid grille2 - structure de la grille
 */
struct grid fire_tactique(struct cible mtactique,struct grid grille2,struct bcomplet boat_completmt[17]){

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
            if(grille2.grille[mtactique.cibley][mtactique.ciblex] != 'X'){
                grille2.grille[mtactique.cibley][mtactique.ciblex] = 'O';
            }
        }
        coupfatal =0;
    }
    return grille2;
}

/*
 * Fonction qui tire un missile d'artillerie
 * @param struct cible martillerie - structure de la cible
 * @param struct grid grille3 - structure de la grille
 * @param struct bcomplet boat_completma[17] - structure des 17 cases des bateaux
 * @return struct grid grille3 - structure de la grille
 */
struct grid fire_artillerie(struct cible martillerie,struct grid grille3,struct bcomplet boat_completma[17]){

    int test =0;

    for (int i = 1; i < 18; i++)
    {
        for (int j = 1; j < 11; j++) {
            if (j == boat_completma[i].boatx && martillerie.cibley == boat_completma[i].boaty) {
                grille3.grille[boat_completma[i].boaty][j] = 'X';
                test =1;
            } else if (martillerie.ciblex == boat_completma[i].boatx && j == boat_completma[i].boaty) {
                grille3.grille[i][boat_completma[j].boatx] = 'X';
                test = 1;
            } else {
                if (grille3.grille[j][martillerie.ciblex] != 'X'){
                    grille3.grille[j][martillerie.ciblex] = 'O';
                }
                if (grille3.grille[martillerie.cibley][j] != 'X'){
                    grille3.grille[martillerie.cibley][j] = 'O';
                }
            }
        }

    }
    return grille3;
}

/*
 * Fonction qui tire un missile bombe
 * @param struct cible mbombe - structure de la cible
 * @param struct grid grille4 - structure de la grille
 * @param struct bcomplet boat_completmb[17] - structure des 17 cases des bateaux
 * @return struct grid grille4 - structure de la grille
 */
struct grid fire_bombe(struct cible mbombe,struct grid grille4,struct bcomplet boat_completmb[17]){


    for (int i = 1; i < 18; i++)
    {
        if (mbombe.ciblex == boat_completmb[i].boatx && mbombe.cibley == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty][boat_completmb[i].boatx] = 'X';
        } else{
            grille4.grille[mbombe.cibley][mbombe.ciblex] = 'O';
        }
        if (mbombe.ciblex == boat_completmb[i].boatx && mbombe.cibley -2 == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty-2][boat_completmb[i].boatx] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley-2][mbombe.ciblex] != 'X'){
                grille4.grille[mbombe.cibley-2][mbombe.ciblex] = 'O';
            }
        }

        if (mbombe.ciblex-1 == boat_completmb[i].boatx && mbombe.cibley-1 == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty-1][boat_completmb[i].boatx-1] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley-1][mbombe.ciblex-1] != 'X'){
                grille4.grille[mbombe.cibley-1][mbombe.ciblex-1] = 'O';
            }
        }

        if (mbombe.ciblex == boat_completmb[i].boatx && mbombe.cibley -1 == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty-1][boat_completmb[i].boatx] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley-1][mbombe.ciblex] != 'X'){
                grille4.grille[mbombe.cibley-1][mbombe.ciblex] = 'O';
            }
        }

        if (mbombe.ciblex+1 == boat_completmb[i].boatx && mbombe.cibley-1 == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty-1][boat_completmb[i].boatx+1] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley-1][mbombe.ciblex+1] != 'X'){
                grille4.grille[mbombe.cibley-1][mbombe.ciblex+1] = 'O';
            }
        }

        if (mbombe.ciblex-2 == boat_completmb[i].boatx && mbombe.cibley == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty][boat_completmb[i].boatx-2] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley][mbombe.ciblex-2] != 'X'){
                grille4.grille[mbombe.cibley][mbombe.ciblex-2] = 'O';
            }
        }

        if (mbombe.ciblex-1 == boat_completmb[i].boatx && mbombe.cibley == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty][boat_completmb[i].boatx-1] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley][mbombe.ciblex-1] != 'X'){
                grille4.grille[mbombe.cibley][mbombe.ciblex-1] = 'O';
            }
        }

        if (mbombe.ciblex+1 == boat_completmb[i].boatx && mbombe.cibley == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty][boat_completmb[i].boatx+1] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley][mbombe.ciblex+1] != 'X'){
                grille4.grille[mbombe.cibley][mbombe.ciblex+1] = 'O';
            }
        }

        if (mbombe.ciblex+2 == boat_completmb[i].boatx && mbombe.cibley == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty][boat_completmb[i].boatx+2] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley][mbombe.ciblex+2] != 'X'){
                grille4.grille[mbombe.cibley][mbombe.ciblex+2] = 'O';
            }
        }

        if (mbombe.ciblex-1 == boat_completmb[i].boatx && mbombe.cibley+1 == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty+1][boat_completmb[i].boatx-1] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley+1][mbombe.ciblex-1] != 'X'){
                grille4.grille[mbombe.cibley+1][mbombe.ciblex-1] = 'O';
            }
        }

        if (mbombe.ciblex+1 == boat_completmb[i].boatx && mbombe.cibley+1 == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty+1][boat_completmb[i].boatx+1] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley+1][mbombe.ciblex+1] != 'X'){
                grille4.grille[mbombe.cibley+1][mbombe.ciblex+1] = 'O';
            }
        }

        if (mbombe.ciblex == boat_completmb[i].boatx && mbombe.cibley+1 == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty+1][boat_completmb[i].boatx] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley+1][mbombe.ciblex] != 'X'){
                grille4.grille[mbombe.cibley+1][mbombe.ciblex] = 'O';
            }
        }

        if (mbombe.ciblex == boat_completmb[i].boatx && mbombe.cibley+2 == boat_completmb[i].boaty){
            grille4.grille[boat_completmb[i].boaty+2][boat_completmb[i].boatx] = 'X';
        } else{
            if(grille4.grille[mbombe.cibley+2][mbombe.ciblex] != 'X'){
                grille4.grille[mbombe.cibley+2][mbombe.ciblex] = 'O';
            }
        }
    }
    return grille4;
}

/*
 * Fonction qui check si un bateau a été touché ou non et donne le nombre de cases qu'il reste à toucher
 * @param struct grid grille5 - structure de la grille
 * @return an integer - check : le nombre de cases de bateaux qu'il reste a anéantir
 */
int is_alive (struct grid grille5){

    int test_local=0,check=17;
    for (int i = 1; i < 18; i++)
    {
        for (int j = 1; j < 18; j++)
        {
            if (grille5.grille[i][j] == 'X'){
                test_local=test_local+1;
            }
        }
    }
    check = 17-test_local;
    return check;
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