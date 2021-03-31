#include <stdlib.h>
struct element{ 
	int nb;
	struct element * previous;
	struct element * next;
};

typedef struct element element_t; // taille d'un élément 
typedef struct element * liste;

int estvide (liste l) {
  if (l == (liste) 0) {
    return 1;
  }
  return 0;
}
int estnonvide (liste l) {
  if (l == (liste) 0) {
    return 0;
  }
  return 1;
}



liste creation(int nb, liste l){
	liste new;
	new = (liste) malloc (sizeof(element_t));
	(*new).nb = nb;
	(*new).next = NULL;
	(*new).previous = l;
	return new;
}

void append(int nb, liste l){
	liste nouveau = creation(nb, l);
	l -> next = nouveau;
}

void afficher (liste l ) {
	if (estnonvide(l)){
		printf("%d\n", l -> nb);
		l = l -> next;
		afficher(l);
	}
}

liste aller_droite(liste l){
	if (estnonvide(l -> next)){
		l = l -> next;
		return l;
	} else {
		append(2, l);
		l = l -> next;
		return l;
	}
}
liste aller_gauche(liste l){
	if (estnonvide(l -> previous)){
		l = l -> previous;
		return l;
	}
}

liste aller_debut(liste l){
	while(estnonvide(l  -> previous)){
		l = l-> previous;
	}	
	return l;
}
void remplir_liste(liste l, int nb){
	switch(nb){
		case 0:

			append(1, l);
			l = aller_droite(l);

			append(1, l);
			l = aller_droite(l);

			append(1, l);
			l = aller_droite(l);

			append(1, l);
			l = aller_droite(l);

			append(2, l);
			l = aller_droite(l);

			printf("voilà la liste l : \n"); 
			l = aller_debut(l);
			afficher(l);
			break;
		case 1:
			append(1, l);
			l = aller_droite(l);			

			append(0, l);	
			l = aller_droite(l);	

			append(1, l);
			l = aller_droite(l);

			append(0, l);	
			l = aller_droite(l);

			append(2, l);
			l = aller_droite(l);

			for(int i = 0; i < 6; i++){
				l = aller_gauche(l);	
			}
	
			break;
		case 2:
	
			append(1, l);
			l = aller_droite(l);			

			append(0, l);	
			l = aller_droite(l);	

			append(1, l);
			l = aller_droite(l);

			append(2, l);
			l = aller_droite(l);
			
			for(int i = 0; i < 5; i++){
		 		l = aller_gauche(l);	
			}



			break;
	default:
	
		append(1, l);
		l = aller_droite(l);			

		append(2, l);	
		l = aller_droite(l);	

		for(int i = 0; i < 3; i++){
			l = aller_gauche(l);	
		}

		break;
		
	}
}
