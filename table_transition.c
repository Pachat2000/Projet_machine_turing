#include "table_transition.h"

transition_etat
creation_transition_etat (int etat_suivant, int ecrit, int deplacement)
{
  transition_etat x;
  x.etat_suivant = etat_suivant;
  x.ecrit = ecrit;
  x.deplacement = deplacement;

  return x;
}

