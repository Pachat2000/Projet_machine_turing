#include "machines.h"
#include "liste.h"
#include "table_transition.h"
#define ETAT_INITIAL 0
#define ETAT_FINAL -1
enum symbol {
	     ZERO = 0,
	     ONE = 1,
	     EMPTY = 2,
};
enum deplacement {
		  GAUCHE = -1,
		  DROITE = 1,
};

void
action_etat (liste l, transition_etat ** tab, int etat_actuel)
{
  int fin = ETAT_FINAL;
  while (etat_actuel != fin)
    {
	l->nb = tab[etat_actuel][l->nb].ecrit;
	l = deplacement (l, tab[etat_actuel][l->nb].deplacement);
	etat_actuel = tab[etat_actuel][l->nb].etat_suivant;

    }
}




void
add1 (liste l)
{				// permet d'ajouter 1 à la bande
//_________________________________________________________________
//transition_etat eX_Y_lect = creation_transition_etat(int etat actuel, int lu, int nouvelle_etat, int écrit, int deplacement)
    transition_etat table[3][3];


  table[0][ZERO] = creation_transition_etat (ETAT_INITIAL, ZERO, ONE, ZERO, ZERO);
  table[0][ONE] = creation_transition_etat (ETAT_INITIAL, ONE, ONE, ONE, ZERO);
  table[0][2] = creation_transition_etat (ETAT_INITIAL, EMPTY, ONE, EMPTY, DROITE);

  table[1][ZERO] = creation_transition_etat (ONE, ZERO, ONE, ZERO, DROITE);
  table[1][ONE] = creation_transition_etat (ONE, ONE, ONE, ONE, DROITE);
  table[1][2] =  creation_transition_etat (ONE, EMPTY, 2, EMPTY, GAUCHE);

  table[2][ZERO] = creation_transition_etat (2, ZERO, ETAT_FINAL, ONE, GAUCHE);
  table[2][ONE] =  creation_transition_etat (2, ONE, 2, ZERO, GAUCHE);
  table[2][2] = creation_transition_etat (2, EMPTY, ETAT_FINAL, ONE, DROITE);

  action_etat (l, table, 0);
}

void
addition (liste l, int nb)
{				// permet d'ajouter nb à la bande 
  for (int i = 0; i < nb; i++)
    {
      add1 (l);
    }
}

void
inverse (liste l)
{				// permet d'inverser les valeurs de la bande

  transition_etat *table[2][3];

  table[0][ZERO] = creation_transition_etat (ETAT_INITIAL, ZERO, ONE, ZERO, ZERO);
  table[0][ONE] = creation_transition_etat (ETAT_INITIAL, ONE, ONE, ONE, ZERO);
  table[0][EMPTY] = creation_transition_etat (ETAT_INITIAL, EMPTY, ONE, EMPTY, DROITE);

  table[1][ZERO] = creation_transition_etat (ONE, ZERO, ONE, ONE, DROITE);
  table[1][ONE] = creation_transition_etat (ONE, ONE, ONE, ZERO, DROITE);
  table[1][2] = creation_transition_etat (ONE, EMPTY, ETAT_FINAL, EMPTY, GAUCHE);


  action_etat (l, table, ETAT_INITIAL);
}

void
multiplieBy2 (liste l)
{				//permet de multiplier la valeur de la bande par 2

  transition_etat *table[2][3];

  table[0][ZERO] = creation_transition_etat (ETAT_INITIAL, ZERO, ONE, ZERO, ZERO);
  table[0][ONE] = creation_transition_etat (ETAT_INITIAL, ONE, ONE, ONE, ZERO);
  table[0][EMPTY] = creation_transition_etat (ETAT_INITIAL, EMPTY, ONE, EMPTY, DROITE);

  table[1][ZERO] = creation_transition_etat (ONE, ZERO, ONE, ZERO, DROITE);
  table[1][ONE] = creation_transition_etat (ONE, ONE, ONE, ONE, DROITE);
  table[1][2] = creation_transition_etat (ONE, EMPTY, ETAT_FINAL, ZERO, DROITE);

  action_etat (l, table, ETAT_INITIAL);
}

void
soustract_1 (liste l)
{				// permet d'enlever 1 à la bande

  transition_etat *table[3][3];

  table[0][ZERO] = creation_transition_etat (ETAT_INITIAL, ZERO, ONE, ZERO, ZERO);
  table[0][ONE] = creation_transition_etat (ETAT_INITIAL, ONE, ONE, ONE, ZERO);
  table[0][EMPTY] = creation_transition_etat (ETAT_INITIAL, EMPTY, ONE, EMPTY, DROITE);

  table[1][ZERO] = creation_transition_etat (ONE, ZERO, ONE, ZERO, DROITE);
  table[1][ONE] = creation_transition_etat (ONE, ONE, ONE, ONE, DROITE);
  table[1][2] = creation_transition_etat (ONE, EMPTY, 2, EMPTY, GAUCHE);

  table[2][ZERO] =creation_transition_etat (2, ZERO, 2, ONE, GAUCHE);
  table[2][ONE] = creation_transition_etat (2, ONE, ETAT_FINAL, ZERO, GAUCHE);
  table[2][2] = creation_transition_etat (2, EMPTY, ETAT_FINAL, EMPTY, GAUCHE);

  table[ZERO] = e0;
  table[ONE] = e1;
  table[2] = e2;

  action_etat (l, table, ETAT_INITIAL);
}

void
sous (liste l, int nb)
{				// permet d'enlever nb à la bande
  for (int i = 0; i < nb; i++)
    {
      soustract_1 (l);
    }
}
