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

int test(int taille, int abscisse, int ordonnee, char orientation, char matrice[10][10]);

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
        int choix = rand()%2;
        if (choix == 1){
            orientation = 'h';
        }else{
            orientation = 'v';
        }
        boat[nb].orientation = orientation;
        boat[nb].taille=taille;
        
        do{
            abscisse = rand()%10;  /* randomise ordonnée et abscisse */
            ordonnee = rand()%10;
            
            retour=test(taille, abscisse, ordonnee, orientation, matrice_test); /* attribue une valeur à retour pour savoir si la fonction retour est ok */
        }while(retour==1);
        
        boat[nb].abscisse=abscisse; /* attribue les valeur définitive d'un bateau */
        boat[nb].ordonnee=ordonnee;

        if (boat[nb].orientation =='h'){  /* Pose les bateaux sur la matrice test */
            for (int i=0; i < taille; i++){
                matrice_test[boat[nb].ordonnee][boat[nb].abscisse+i] = taille+'0';
            }

        }else{
            for (int i=0; i < taille; i++) {
                matrice_test[boat[nb].ordonnee+i][boat[nb].abscisse] = taille+'0';
            }
        }
        matrice_affich(matrice_test);
    }
/*___________________________________________________PARTIE POUR 2° be=ateau de 3______________________________________________________________________________________*/    
    
    taille = 3;
    int choix = rand()%2;
    if (choix == 1){
        orientation = 'h';
    }else{
        orientation = 'v';
    }
    boat[4].orientation = orientation;
    boat[4].taille=taille; 
    do{
            abscisse = rand()%10;  /* randomise ordonnée et abscisse */
            ordonnee = rand()%10;
            
            retour=test(taille, abscisse, ordonnee, orientation, matrice_test); /* attribue une valeur à retour pour savoir si la fonction retour est ok */
        }while(retour==1);
        
        boat[4].abscisse=abscisse; /* attribue les valeur définitive d'un bateau */
        boat[4].ordonnee=ordonnee;

        if (boat[4].orientation =='h'){  /* Pose les bateaux sur la matrice test */
            for (int i=0; i < taille; i++){
                matrice_test[boat[4].ordonnee][boat[4].abscisse+i] = taille+'0';
            }

        }else{
            for (int i=0; i < taille; i++) {
                matrice_test[boat[4].ordonnee+i][boat[4].abscisse] = taille+'0';
            }
        }
        matrice_affich(matrice_test);
/*______________________________________________________________________________________________________________________________________________________________________*/
    
    matrice_affich(matrice_test);
    return 0;
}

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