#include <stdio.h>
#include <stdlib.h>

int modes(char* CHOIX, char* choix1,char* choix2,char* choix3);

int main() {
    int c=0,a=0,b=0;

    a = modes("Menu","Demarrer","Charger","Quitter");
    printf("test : %d",a);
    b = modes("Mode","Classique","Blind","Active");
    printf("test : %d",b);
    c = modes("Difficulte","Facile","Moyen","Difficile");
    printf("test : %d \n",c);
    return 0;
}

/*
 * Fonction qui prend la valeur du menu, du mode et de la difficulté et qui renvoit la valeur de l'adition des 3 entrée
 * @param
 * @return a integer - la sommes des entrées "smodes"
 */
int modes(char* CHOIX,char* choix1,char* choix2,char* choix3) {
    int menu = 0;
    char keymenu;
    char antibug;

    printf("%s - Choisir 1: %s 2: %s 3: %s \n",CHOIX,choix1,choix2,choix3);
    scanf("%c", &keymenu);
    antibug = getchar();
    menu = atoi(&keymenu);
    if (menu < 1 || menu > 3) {
        do {
            printf("Ecrire 1 2 ou 3 : \n");
            printf("%s - Choisir 1: %s 2: %s 3: %s \n",CHOIX,choix1,choix2,choix3);
            scanf("%c", &keymenu);
            antibug = getchar();
            menu = atoi(&keymenu);
        } while (menu < 1 || menu > 3);
    }

    switch (menu) {
        case 1:printf("%s - Vous avez choisis : %s \n \n",CHOIX, choix1);
            break;
        case 2:printf("%s - Vous avez choisis : %s \n \n",CHOIX, choix2);
            break;
        case 3:printf("%s - Vous avez choisis : %s \n \n",CHOIX, choix3);
            break;
        default:printf("Erreur : cela ne dervait jamais arriver \n \n" );
            break;
    }
    
    return menu;
}