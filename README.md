# Projet Machine de Turing 
| Nom             | Prénom          |
|---              |---              |
| Elsegahy        | Rayan           |
| Javaid          | Mohammad-Habib  |

## Compiler 

Voici la ligne à entrer dans le terminal :
```gcc turing.c liste.c machines.c table_transition.c -o ./turing.out```

## Créer sa machine de Turing

La création de la machine se passe dans le fichier machine.c.

On commence par déclarer notre fonction, prenant en argument la liste doublement chainée sur laquelle va agir notre table de transition : 
```c
void nom_de_la_fonction(liste l) 
```
Ensuite on passe à l'initialisation de notre table de transition, ainsi que ses états, par exemple :

```c
    transition_etat *table[3];
    transition_etat e0[3];
    transition_etat e1[3];
    transition_etat e2[3];
    transition_etat eX[3];
```

e0, e1, e2, etc, correspondent aux états, ils seront contenus dans `table` qui est notre table de transition.
Les `eX` contiennent 3 car la on peut lire seulement 3 valeurs sur la bande : 
- 0
- 1
- 2 (case vide)

Ensuite, il faut définir les transitions d'état de nos états, pouvant avoir 3 valeurs possible, par exemple pour e1, l'état 1: 

```c
  e1[ZERO] = creation_transition_etat ( 1, ZERO, DROITE);
  e1[ONE] = creation_transition_etat ( 1, ONE, DROITE);
  e1[EMPTY] =  creation_transition_etat ( 2, EMPTY, GAUCHE);

```

`creation_transition_etat` contient 3 argument :
`creation_transition_etat ( État suivant, Élément écrit, Déplacement);`

Il faut faire cette opération sur chaque état.

Après cela, il faut ajouter les états dans `table`, notre table de transition qui est actuellement vide: 
```c 
  table[0] = e0;
  table[1] = e1;
  table[2] = e2;
  table[X] = eX, 
```

Puis il faut ajouter l'appel à la fonction `action_etat`, permettant d'exécuter notre table de transition : 
  
  ```c
  action_etat (l, table, ETAT_INITIAL);
  ```

Enfin, il ne faut pas non plus oublier de mettre le prototype de notre fonction dans `machines.h`.


À noté que notre main se trouve dans le fichier `turing.c`, c'est là-bas  qu'il faut utiliser les machines.

## Impression de trace d'exécution


```
    Voilà notre liste : 
    210102
    
    Voici la liste avec plus 1 : 
    210112
    
    Voici la liste inverser : 
    201002
    
    voici la liste additionnée avec le nombre : 3 : 
    201112
    
    voici la liste soustraite par  1: 
    201102
    
    voici la liste soustraite par 4 : 
    200102
    
    voici la liste multipliée par 2 : 
    2001002
    
    voici la liste multipliée par 2 : 
    20010002
```


  
