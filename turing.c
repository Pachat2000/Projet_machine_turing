#include <stdio.h>
#include "table_transition.h"
#include "liste.h"
#include "machines.h"


int
main (void)
{
  // 1 = droite , -1 = gauche
//transition_etat creation_transition_etat(int etat, etat_suite * nxt){
  liste l = NULL;
  l = creation (2, l);
  remplir_liste (l, 1);
  afficher (l);
  add1 (l);
  printf ("Voici le liste al plus 1 : \n");
  afficher (l);
  inverse (l);
  printf ("Voici le liste inverser : \n");
  afficher (l);
  addition (l, 3);
  printf ("voici le nouveau liste : \n");
  afficher (l);
  soustract_1 (l);
  printf ("voici le nouveau liste al moin 1: \n");
  afficher (l);
  sous (l, 4);
  printf ("voici le nouveau liste soustrait : \n");
  afficher (l);
  multiplieBy2 (l);
  printf ("voici le nouveau liste multiplier par 2 : \n");
  afficher (l);
  multiplieBy2 (l);
  printf ("voici le nouveau liste multiplier par 2 : \n");
  afficher (l);

}
