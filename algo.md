

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
        

## Structures :

### structure grid

char noms [9][9] ={ ‘‘----------’’, ‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’,‘‘----------’’};

int largeur = 10

int longueur = 10

### structure boat

char orientation

int btaille [2;5]

int bligne [1;10]

int bcolonne[1;10]

### structure inventory

int martillerie

int msimple

int mtactique


