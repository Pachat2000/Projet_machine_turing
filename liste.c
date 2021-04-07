#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int
estvide (liste l)
{
  if (l == (liste) 0)
    {
      return 1;
    }
  return 0;
}

int
estnonvide (liste l)
{
  if (l == (liste) 0)
    {
      return 0;
    }
  return 1;
}



liste
creation (int nb, liste l)
{
  liste new;
  new = (liste) malloc (sizeof (element_t));

  new -> nb = nb;
  new -> next = NULL;
  new -> previous = l;

  return new;
}

void
append (int nb, liste l)
{
  liste nouveau = creation (nb, l);
  l->next = nouveau;
}

void
append_vide_gauche (liste l)
{
  liste nouveau = creation (2, NULL);
  nouveau->next = l;
  l->previous = nouveau;
}

void
afficher (liste l)
{
  if (estnonvide (l))
    {
      printf ("%d\n", l->nb);
      l = l->next;
      afficher (l);
    }
}

liste
aller_droite (liste l)
{
  if (estnonvide (l->next))
    {
      l = l->next;
      return l;
    }
  else
    {
      append (2, l);
      l = l->next;
      return l;
    }
}

liste
aller_gauche (liste l)
{
  if (estnonvide (l->previous))
    {
      l = l->previous;
      return l;
    }
  else
    {
      append_vide_gauche (l);
      l = l->next;
      return l;
    }
}

liste
aller_debut (liste l)
{
  while (estnonvide (l->previous))
    {
      l = l->previous;
    }
  return l;
}

void
remplir_liste (liste l, int nb)
{
  switch (nb)
    {
    case 0:

      append (1, l);
      l = aller_droite (l);

      append (1, l);
      l = aller_droite (l);

      append (1, l);
      l = aller_droite (l);

      append (1, l);
      l = aller_droite (l);

      append (2, l);
      l = aller_droite (l);

      printf ("voilà la liste l : \n");
      l = aller_debut (l);
      afficher (l);
      break;
    case 1:
      append (1, l);
      l = aller_droite (l);

      append (0, l);
      l = aller_droite (l);

      append (1, l);
      l = aller_droite (l);

      append (0, l);
      l = aller_droite (l);

      append (2, l);
      l = aller_droite (l);

      l = aller_debut (l);

      break;
    case 2:

      append (1, l);
      l = aller_droite (l);

      append (0, l);
      l = aller_droite (l);

      append (1, l);
      l = aller_droite (l);

      append (2, l);
      l = aller_droite (l);

      l = aller_debut (l);



      break;
    default:

      append (1, l);
      l = aller_droite (l);

      append (2, l);
      l = aller_droite (l);

      l = aller_debut (l);

      break;

    }
}


liste
deplacement (liste l, int mouvement)
{
  if (mouvement == 1)
    {
      if (l->next == NULL)
		{
			append (2, l);
		}
      return l->next;
    }
  else
    {
      if (l->previous == NULL)
		{
	  		append_vide_gauche (l);
		}

      return l->previous;
    }
}
