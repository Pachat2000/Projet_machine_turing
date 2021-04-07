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
  int fin = -1;
  int i = 0;
  while (etat_actuel != fin)
    {
      if (i == 3)
		{
	  		i = 0;
		}
      if (l->nb == tab[etat_actuel][i].lu)
		{
	  		l->nb = tab[etat_actuel][i].ecrit;
	  		l = deplacement (l, tab[etat_actuel][i].deplacement);

	  		etat_actuel = tab[etat_actuel][i].etat_suivant;
		}
      i++;
    }
}




void
add1 (liste l)
{				// permet d'ajouter 1 à la bande
//_________________________________________________________________
//transition_etat eX_Y_lect = creation_transition_etat(int etat actuel, int lu, int nouvelle_etat, int écrit, int deplacement)
  transition_etat *table[3];
  transition_etat e0[3];
  transition_etat e1[3];
  transition_etat e2[3];

  transition_etat e1_2_lect = creation_transition_etat (ETAT_INITIAL, EMPTY, ONE, EMPTY, DROITE);
  e0[0] = e1_2_lect;

  transition_etat e1_0_lect = creation_transition_etat (ETAT_INITIAL, ZERO, ONE, ZERO, ZERO);
  e0[1] = e1_0_lect;

  transition_etat e1_1_lect = creation_transition_etat (ETAT_INITIAL, ONE, ONE, ONE, ZERO);
  e0[2] = e1_1_lect;

  transition_etat e2_0_lect = creation_transition_etat (ONE, ZERO, ONE, ZERO, DROITE);
  e1[0] = e2_0_lect;

  transition_etat e2_1_lect = creation_transition_etat (ONE, ONE, ONE, ONE, DROITE);
  e1[1] = e2_1_lect;

  transition_etat e2_2_lect = creation_transition_etat (ONE, EMPTY, 2, EMPTY, GAUCHE);
  e1[2] = e2_2_lect;

  transition_etat e3_0_lect = creation_transition_etat (2, ZERO, ETAT_FINAL, ONE, GAUCHE);
  e2[0] = e3_0_lect;

  transition_etat e3_1_lect = creation_transition_etat (2, ONE, 2, ZERO, GAUCHE);
  e2[1] = e3_1_lect;

  transition_etat e3_2_lect = creation_transition_etat (2, EMPTY, ETAT_FINAL, ONE, DROITE);
  e2[2] = e3_2_lect;

  table[0] = e0;
  table[1] = e1;
  table[2] = e2;

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

  transition_etat *table[2];
  transition_etat e0[1];
  transition_etat e1[3];

  transition_etat e1_2_lect = creation_transition_etat (ETAT_INITIAL, EMPTY, ONE, EMPTY, DROITE);
  e0[0] = e1_2_lect;

  transition_etat e2_0_lect = creation_transition_etat (ONE, ZERO, ONE, ONE, DROITE);
  e1[0] = e2_0_lect;

  transition_etat e2_1_lect = creation_transition_etat (ONE, ONE, ONE, ZERO, DROITE);
  e1[1] = e2_1_lect;

  transition_etat e2_2_lect = creation_transition_etat (ONE, EMPTY, ETAT_FINAL, EMPTY, GAUCHE);
  e1[2] = e2_2_lect;

  table[0] = e0;
  table[1] = e1;

  action_etat (l, table, 0);
}

void
multiplieBy2 (liste l)
{				//permet de multiplier la valeur de la bande par 2

  transition_etat *table[2];
  transition_etat e0[1];
  transition_etat e1[3];

  transition_etat e1_2_lect = creation_transition_etat (ETAT_INITIAL, EMPTY, ONE, EMPTY, DROITE);
  e0[0] = e1_2_lect;

  transition_etat e2_0_lect = creation_transition_etat (ONE, ZERO, ONE, ZERO, DROITE);
  e1[0] = e2_0_lect;

  transition_etat e2_1_lect = creation_transition_etat (ONE, ONE, ONE, ONE, DROITE);
  e1[1] = e2_1_lect;

  transition_etat e2_2_lect = creation_transition_etat (ONE, EMPTY, ETAT_FINAL, ZERO, DROITE);
  e1[2] = e2_2_lect;

  table[0] = e0;
  table[1] = e1;

  action_etat (l, table, 0);
}

void
soustract_1 (liste l)
{				// permet d'enlever 1 à la bande

  transition_etat *table[3];
  transition_etat e0[3];
  transition_etat e1[3];
  transition_etat e2[3];

  transition_etat e1_2_lect = creation_transition_etat (ETAT_INITIAL, EMPTY, ONE, EMPTY, DROITE);
  e0[0] = e1_2_lect;

  transition_etat e1_0_lect = creation_transition_etat (ETAT_INITIAL, ZERO, ONE, ZERO, ZERO);
  e0[1] = e1_0_lect;

  transition_etat e1_1_lect = creation_transition_etat (ETAT_INITIAL, ONE, ONE, ONE, ZERO);
  e0[2] = e1_1_lect;

  transition_etat e2_0_lect = creation_transition_etat (ONE, ZERO, ONE, ZERO, DROITE);
  e1[0] = e2_0_lect;

  transition_etat e2_1_lect = creation_transition_etat (ONE, ONE, ONE, ONE, DROITE);
  e1[1] = e2_1_lect;

  transition_etat e2_2_lect = creation_transition_etat (ONE, EMPTY, 2, EMPTY, GAUCHE);
  e1[2] = e2_2_lect;

  transition_etat e3_0_lect = creation_transition_etat (2, ZERO, 2, ONE, GAUCHE);
  e2[0] = e3_0_lect;

  transition_etat e3_1_lect = creation_transition_etat (2, ONE, ETAT_FINAL, ZERO, GAUCHE);
  e2[1] = e3_1_lect;

  transition_etat e3_2_lect = creation_transition_etat (2, EMPTY, ETAT_FINAL, EMPTY, GAUCHE);
  e2[2] = e3_2_lect;

  table[0] = e0;
  table[1] = e1;
  table[2] = e2;

  action_etat (l, table, 0);
}

void
sous (liste l, int nb)
{				// permet d'enlever nb à la bande
  for (int i = 0; i < nb; i++)
    {
      soustract_1 (l);
    }
}
