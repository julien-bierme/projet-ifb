#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct{
    char orientation;
    int taille;
    int abscisse;
    int ordonnee;
}bateau
;

int test(int taille, int abscisse, int ordonnee, char orientation);
void matrice_test(char matrice_test[10][10]);


int main(){
    srand(time(0));

    int taille, abscisse, ordonnee, retour;
    char orientation;
    char matrice_test[10][10];

    bateau boat[5];
    for(int nb; nb<4; nb++){
        taille = nb+1;
        orientation = 'h';
        boat[nb].orientation ='h';
        boat[nb].taille=taille;
        do{
            abscisse = rand()%10;
            ordonnee = rand()%10;
            retour=test(taille, abscisse, ordonnee, orientation);
        }while(retour==1);
        boat[nb].abscisse=abscisse;
        boat[nb].ordonnee=ordonnee;

        
        if (boat[nb].orientation =='h'){
            for (int i; i==taille-1; i++){
                matrice_test[boat[nb].ordonnee+i][boat[nb].abscisse]=taille;
            }

        }else{
            for (int i; i==taille-1; i++) {
                matrice_test[boat[nb].ordonnee][boat[nb].abscisse + i] = taille;
            }
        }

        printf("bateau n:%c, %d, %d, %d\n",orientation, nb, boat[nb].ordonnee, boat[nb].abscisse);
    }
    void matrice_test(matrice_test[10][10]);
    return 0;
}

int test(int taille, int abscisse, int ordonnee, char orientation){
    int retour;
    char matrice[10][10];
    for (int i; i==taille; i++){
        if (orientation=='v'){
            if (ordonnee+i<11 && matrice[ordonnee+i][abscisse]=='\0'){
                matrice[ordonnee+i][abscisse]=taille;
            }else{
                retour=1;
            }
        }
        else if (orientation=='h'){
            if(abscisse+i<11 && matrice[ordonnee][abscisse+i]=='\0'){
                matrice[ordonnee][abscisse+i]=taille;
            }else{
                retour=1;
            }
        }else{
            retour=1;

        }
    }
}

void matrice_test(char matrice_test[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", matrice_test[i][j]);
        }
        printf("/n");
    }
}
