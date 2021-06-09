#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/* structure type pour des bateaux*/
typedef struct{
    char orientation;
    int taille;
    int abscisse;
    int ordonnee;
}bateau
;

int test(int taille, int abscisse, int ordonnee, char orientation);

void matrice_affich(char matrice[10][10]);

/* main gérant l'attribution des valeur aux bateaux */
int main(){
    srand(time(0));

    int taille, abscisse, ordonnee, retour;  /* Init des Variables */
    char orientation;
    char matrice_test[10][10]={0};

    bateau boat[5];  /* 5 Unit Bateau */
    
    for(int nb=0; nb<4; nb++){  /* Bateau 2, 3, 4, 5 */
        taille = nb+2;
        orientation = 'h';
        boat[nb].orientation ='h';
        boat[nb].taille=taille;
        
        do{
            abscisse = rand()%10;  /* randomise ordonnée et abscisse */
            ordonnee = rand()%10;
            
            retour=test(taille, abscisse, ordonnee, orientation); /* attribue une valeur à retour pour savoir si la fonction retour est ok */
        }while(retour==1);
        
        boat[nb].abscisse=abscisse; /* attribue les valeur définitive d'un bateau */
        boat[nb].ordonnee=ordonnee;

        if (boat[nb].orientation =='h'){  /* Pose les bateaux sur la matrice test */
            for (int i=0; i < taille; i++){
                matrice_test[boat[nb].ordonnee][boat[nb].abscisse+i] = taille+'0';
            }

        }else{
            for (int i=0; i < taille-1; i++) {
                matrice_test[boat[nb].ordonnee+i][boat[nb].abscisse] = taille+'0';
            }
        }

        printf("bateau n:%d, %c, %d, %d\n", nb, orientation, boat[nb].ordonnee, boat[nb].abscisse); /* Print les infos du bateau */
    }
    
    matrice_affich(matrice_test);
    return 0;
}

int test(int taille, int abscisse, int ordonnee, char orientation){  /* vérifie possibibilité poser bateau */
    int retour=0;
    char matrice[10][10]={0};
    for (int i = 0; i < taille; i++){
        if (orientation=='v'){
            if (ordonnee+i<11 && matrice[ordonnee+i][abscisse]==0){
                matrice[ordonnee+i][abscisse]=taille;
            }else{
                retour=1;
            }
        }
        else if (orientation=='h'){
            if(abscisse+i<11 && matrice[ordonnee][abscisse+i]==0){
                matrice[ordonnee][abscisse+i]=taille;
            }else{
                retour=1;
            }
        }else{
            retour=1;

        }
    }
    return retour;
}

void matrice_affich(char matrice[10][10]){
    printf("test\n");
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
}