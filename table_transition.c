#include "table_transition.h"

transition_etat
creation_transition_etat (int etat_actuel, int lu, int etat_suivant,
			  int ecrit, int deplacement)
{
  transition_etat x;
  x.etat_actuel = etat_actuel;
  x.lu = lu;
  x.etat_suivant = etat_suivant;
  x.ecrit = ecrit;
  x.deplacement = deplacement;

  return x;
}
