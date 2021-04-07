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
  printf("Voilà notre liste : ");
  l = creation (2, l);
  remplir_liste (l, 1);
  afficher (l);
  add1 (l);
  printf ("Voici la liste avec plus 1 : \n");
  afficher (l);
  inverse (l);
  printf ("Voici la liste inverser : \n");
  afficher (l);
  addition (l, 3);
  printf ("voici la liste additionnée avec le nombre : %d : \n",3);
  afficher (l);
  soustract_1 (l);
  printf ("voici la liste soustraite par  1: \n");
  afficher (l);
  sous (l, 4);
  printf ("voici la liste soustraite par %d : \n", 4);
  afficher (l);
  multiplieBy2 (l);
  printf ("voici la liste multipliée par 2 : \n");
  afficher (l);
  multiplieBy2 (l);
  printf ("voici la liste multipliée par 2 : \n");
  afficher (l);

}
