#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct{
	char orientation;
	int taille;
	int ligne;
	int colonne;
}bateau
;

int test(int taille, int ligne, int colonne, char orientation);

int test(int taille, int ligne, int colonne, char orientation){
	int retour;
	char matrice[10][10];
	for(int i; i==taille; i++){
		if (orientation=='v'){
			if(colonne+i<11 && matrice[colonne+i][ligne]=='\0'){
				matrice[colonne+i][ligne]=taille;
			}else{
				retour=1;
			}
		}	
		else if (orientation=='h'){
			if(ligne+i<11 && matrice[colonne][ligne+i]=='\0'){
				matrice[colonne][ligne+i]=taille;
			}else{	
				retour=1;
			}
		}else{
			retour=1;
			
		}		
	}	
}
int main(){
	srand(time(0));

	int taille, ligne, colonne, retour;
	char orientation;
	bateau boat[5];
	for(int nb; nb<4; nb++){
		taille = nb+1;
		orientation = 'h';
		boat[nb].orientation='h';
		boat[nb].taille=taille;
		do{
			ligne = rand()%10;
			colonne = rand()%10;
			retour=test(taille, ligne, colonne, orientation);
		}while(retour==1);
		boat[nb].ligne=ligne;
		boat[nb].colonne=colonne;
		printf("bateau n:%c, %d, %d, %d\n",orientation, nb, boat[nb].colonne, boat[nb].ligne);
	}
}

		
	