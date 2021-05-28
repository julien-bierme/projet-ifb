

### Main

    char *menu* = 0; 
    char *mode* = 0;
    char *difficulte* = 0;
    
    fonction modes
    
    

### modes

    char *mode* = 0;
    char *difficulte*;
    char *menu* = 0; 
    
    faire {
        écrire : Menu a démarer  b charger ou c quitter
        lire : *menu*
        écrire : écrire a b ou c } tant que (*menu* != a,b ou c)
    
    écrire : Vous avez choisis *menu*
    
    si *menu* == a ou b {
    faire {
        écrire : Menu a classique  b blind ou c Active
    
        lire : *mode*
    
        écrire : écrire a b ou c  } tant que (*mode* != a,b ou c)
    
    faire {
        écrire : Difficulté a facile  b moyen ou c difficile
    
        lire : *mode*
    
        écrire : écrire a b ou c  } tant que (*mode* != a,b ou c)
        } sinon {return 0;}
    
    sortir mode, difficulte, menu
        
### fonction random bateau debut de la partie
    struct bateau boat[5];
    pour i de 1 à 4 par pallier de 1:
        int xorientation = rand() %2
        si xorientation = 0 
            strcpy(position[i].orientation, "V")
        sinon 
            strcpy(position[i].orientation, "H")
        fin si 
        
        position[i].btaille = i +1
        
        faire:
            position[i].bligne = rand() %10 +1
        tant que : (position[i].bligne=position[1].bligne || position[i].bligne=position[2].bligne || position[i].bligne=position[3].bligne || position[i].bligne=position[4].bligne)
        faire:
            position[i].bcolonne = rand() %10 +1
        tant que : (position[i].bcolonne=position[1].bcolonne || position[i].bcolonne=position[2].bcolonne || position[i].bcolonne=position[3].bcolonne || position[i].bcolonne=position[4].bcolonne)
    
    fin pour
    
    int xorientation = rand() %2
        si xorientation = 0 
            strcpy(position[5].orientation, "V")
        sinon 
            strcpy(position[5].orientation, "H")
        fin si 
        position[5].btaille = 3
        faire:
            position[5].bligne = rand() %10 +1
        tant que : (position[5].bligne=position[1].bligne || position[5].bligne=position[2].bligne || position[5].bligne=position[3].bligne || position[5].bligne=position[4].bligne)
        faire:
            position[5].bcolonne = rand() %10 +1
        tant que : (position[5].bcolonne=position[1].bcolonne || position[5].bcolonne=position[2].bcolonne || position[5].bcolonne=position[3].bcolonne || position[5].bcolonne=position[4].bcolonne)
    
    struct bcomplet boat_complet[17];
    int j = 5
    Pour i de 1 à 5 pas de 1 :
        boat_complet[i].bligne=boat[i].bligne
        boat_complet[i].bcolonne=boat[i].bcolonne
        
        si boat_complet[i].orientation = "V"
            pour k de 1 à boat[i].btaille pas de 1:
                j = j+1
                boat_complet[j].bligne = boat[i].bligne
                boat_complet[j].bcolonne = boat[i].bcolonne+k
            fin pour
        fin si
        
        si boat_complet[i].orientation = "H"
            pour k de 1 à boat[i].btaille pas de 1:
                j = j+1
                boat_complet[j].bcolonne = boat[i].bcolonne
                boat_complet[j].bligne = boat[i].bligne+k
            fin pour
        fin si
    fin pour
    Renvoi : struct bcomplet boat_complet[17];
        
### fonction show grid
    struct grid;
    écrire("Grille:", grid.grille)
    
### fonction choix cible
    int ciblel, ciblec;
    struct cible;
    écrire : "Donner la coordonées ligne de la cible :"
    lire : ciblel
    écrire : "Donner la coordonées colonne de la cible :"
    lire : ciblec
    écrire : "Vous avez choisis la cible de coordonnées (%d , %d )", ciblel, ciblec;
    cible.cibleligne = ciblel
    cible.ciblecolonne = ciblec
    
### fonction msimple
    Prendre : ciblel
    Prendre : ciblec
    Prendre : struct bcomplet boat_complet[17]
    struct grid;
    struct bcomplet
    int test = 0;
    Pour i de 1 à 17 pas de 1 :
        if ciblel= boat_complet[i]
            test = test +1
            bcomplet[i].touche = 1
        fin si
    fin pour
    si test != 0 :
        grid.grille[ciblec][ciblel] = "X"
    else : grid.grille[ciblec][ciblel] = "O"

## Structures :

### structure grid

char grille [10][10] ={ ‘‘----------’’, ‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’};

int largeur = 10
 
int longueur = 10

### structure bateau

char orientation

int btaille [2;5]

int bligne [1;10]

int bcolonne[1;10]

### structure bcomplet

int bligne [1;10]

int bcolonne[1;10]

int touche = 0;

### structure inventory

int martillerie

int msimple

int mtactique

int mbombe

### structure cible
int cibleligne;
int ciblecolonne;
