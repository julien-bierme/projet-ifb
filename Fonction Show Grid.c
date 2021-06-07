
#include <stdlib.h>
#include <stdio.h>

struct grid {
    char grille[12][12];
    int largeur;
    int longeur
};

void debut_grille();
void show_grid();

int main(){
    debut_grille();
    show_grid();
    return 0;
}

void debut_grille(void){
    struct grid grille;

    char glocal[12][12] = {" ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"," ~~~~~~~~~~"};

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            grille.grille[i][j]=glocal[i][j];
        }
    }

}

void show_grid(void){
    struct grid grille;

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
            printf("%c",grille.grille[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
