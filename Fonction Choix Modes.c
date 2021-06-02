#include <stdio.h>
#include <stdlib.h>

int modes(char* CHOIX, char* choix1,char* choix2,char* choix3);

int main() {
    int c=0,a=0,b=0;

    //test des 3 modes
    a = modes("Menu","Demarrer","Charger","Quitter");
    printf("test : %d",a);
    b = modes("Mode","Classique","Blind","Active");
    printf("test : %d",b);
    c = modes("Difficulte","Facile","Moyen","Difficile");
    printf("test : %d \n",c);
    return 0;
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
    char antibug;

    printf("%s - Choisir 1: %s 2: %s 3: %s \n",CHOIX,choix1,choix2,choix3);
    scanf("%c", &keymenu); // lecture du choix de l'utilisateur
    antibug = getchar(); // vidage du buffer
    menu = atoi(&keymenu); // conversion du caractère en entier

    /*fonction qui répète l'opération tant que le choix n'est pas 1, 2 ou 3*/
    if (menu < 1 || menu > 3) {
        do {
            printf("Ecrire 1 2 ou 3 : \n");
            printf("%s - Choisir 1: %s 2: %s 3: %s \n",CHOIX,choix1,choix2,choix3);
            scanf("%c", &keymenu); // lecture du choix de l'utilisateur
            antibug = getchar(); // vidage du buffer
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