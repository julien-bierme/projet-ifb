
### Main
	char *menu* = 0; 
	
	faire {
		écrire : Menu a démarer  b chargé ou c quitter
		lire : *menu*
		écrire : écrire a b ou c } tant que (*menu* != a,b ou c)
		
	écrire : Vous avez choisis *menu*
	
	si *menu* == a ou b {
		**fonction jeu** (**menu**)
		} sinon {fin}

### Jeu
	char *mode* = 0; 
	
	faire {
		écrire : Menu a classique  b blind ou c Active
		
		lire : *mode*
		
		écrire : écrire a b ou c  } tant que (*mode* != a,b ou c)
		
		if 
	
