#ifndef _MACHINES_H
#define _MACHINES_H

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




void action_etat (liste l, transition_etat ** tab, int etat_actuel);

void add1 (liste l);

void addition (liste l, int nb);

void inverse (liste l);

void multiplieBy2 (liste l);

void soustract_1 (liste l);

void sous (liste l, int nb);




#endif /* "machines.h" included. */
