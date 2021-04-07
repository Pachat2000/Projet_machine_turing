#ifndef _LISTE_H
#define _LISTE_H

struct element
{
  int nb;
  struct element *previous;
  struct element *next;
};

typedef struct element element_t;	// taille d'un élément 
typedef struct element *liste;


int estvide (liste l);

int estnonvide (liste l);

liste creation (int nb, liste l);

void append (int nb, liste l);

void append_vide_gauche (liste l);

void afficher (liste l);

liste aller_droite (liste l);

liste aller_gauche (liste l);

liste aller_debut (liste l);

void remplir_liste (liste l, int nb);

liste deplacement (liste l, int mouvement);



#endif /* "liste.h" included. */
