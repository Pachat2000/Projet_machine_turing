#ifndef _TABLE_TRANSITION_H
#define _TABLE_TRANSITION_H

struct transition_etat
{
  int etat_suivant;
  int ecrit;
  int deplacement;
};
typedef struct transition_etat transition_etat;

transition_etat
creation_transition_etat (int etat_suivant,
              int ecrit, int deplacement);

#endif /* "table_transition.h" included. */

