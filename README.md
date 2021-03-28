# Projet Machine de Turing 
| Nom             | Prénom |
|---              |---     |
| Elsegahy        | Rayan  |
| Javaid-Mohammad | Habib  |

## La mise en place de la structure de notre machine de Turing:

**En résumé**: ça se présente sous la forme (etat, lu) -> (nouvel_etat, ecrit, déplacement)

**En détail**:
   Le début de notre code est séparer de deux structure :
   - `etat_lect` contenant l'état dans lequel on est (un int), également un entier `lu` comme second argument qui sera l'élement lu pour cet etat (il peut prendre la valeur 0, 1 qui représente les valeurs binaire, et 2 qui représente une case vide), et enfin un pointeur vers un struct `etat_suite`.
   - `etat_suite` qui contient le nouvelle etat (lorsque `lu` est lu dans le vecteur), le nombre à ecrire à la place de l'endroit lu, ainsi que le deplacement qui doit effectuer( 1 = deplacement vers la droite, -1 vers la gauche).
   Nous avons par la suite écrit deux type def afin de raccourcir notre code.

Chaque état possède 3 etat_lect, pour les différents élément qu'il est possible de lire (0, 1 et 2). 
(Pour notre programme qui ajoute 1, on a pas fait 3 etat_lect pour le 1er état, ce n'était pas nécessaire)

## Les fonctions 

La fonction `creation_etat_lect` permet de créer un struct etat_lect, ça renvoie un `etat_lect`, `creation_etat_suit` permet de créer un struct etat_suite

La fonction `affiche` permet d'affiche le vecteur qui sera utiliser pou nos futur transaction avec notre programme.

La fonction `remplirvec` permet juste de remplir un vecteur a une certaine taille fixe.

la fonction `action_etat` (nom a redéfinir plus tard car elle n'est pas très explicite)  permet d'exécuter un état donné, jusqu'à qu'on atteigne l'état suivant. Elle renvoie la position à la fin de `l'exécution de l'état`.


La fonction `execute` permet d'exécuter le tableau de transaction de notre machine de turing.

## A faire dans le futur 

- paufiner notre code;
- Rajouter d'autre fonction qu'un machine de turing pourrait faire;
- Pouvoir faire la meme chose mais avec un vecteur de taille variable;
- Creer une fonction qui deplace tous les element d'un vecteur d'un cran;
- creer une fonction qui calcule la taille d'un vecteur (ez ca);
- Pouvoir faire la meme chose mais avec une liste chaine;

**MAIS SURTOUT ATTENDRE LA VALIDATION DE LA MACHINE DE TURING ACTUELLE PAR LES PROFS**

## Explication globale du code
Tout d'abord, il faut savoir que la bande peut ne contenir que 3 valeurs différentes :
- 0 et 1, correspondant aux valeurs binaire
- 2, correspondant à une case vide

La machine de turing que nous simulons permet d'ajouter 1 au nombre binaire écrit dans la bande.

La machine possède 3 états:
```
______________________________________________________________
|état actuel|élément lu|élément écrit|déplacement|état suivant|
|=============================================================|
|  état 1   |     2    |      2      |   droite  |   état 2   |
|=============================================================|
|  état 2   |     0    |      0      |   droite  |   état 2   |
|-------------------------------------------------------------|
|  état 2   |     1    |      1      |   droite  |   état 2   |
|-------------------------------------------------------------|
|  état 2   |     2    |      2      |   gauche  |   état 3   |
|=============================================================|
|  état 3   |     0    |      1      |   gauche  | état final |
|-------------------------------------------------------------|
|  état 3   |     1    |      0      |   gauche  |   état 3   |
|-------------------------------------------------------------|
|  état 3   |     2    |      1      |   gauche  | état final |
|=============================================================|
```
Le ruban est créer a partir d'un vecteur déjà prédeterminer, que l'on peut choisir selon le nombre que tu a mis entre 0, 1 et 2.
le sens de lecture ce fait de gauche à droite de la bande.
