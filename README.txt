******************** Projet Machine de Turing ************************
| Nom             | Prénom |
|-----------------|--------|
| Elsegahy        | Rayan  |
| Javaid-Mohammad | Habib  |

La mise en place de la structure de notre machine de Turing:

Le début de notre code est séparer de deux structure : - "etat_lect" qui est l'état de base de la machine au tous debut avec un "lu" comme second arguement qui sera 
						         donc l'element lu de cette etat et enfin un pointeur vers une autre strut.
						       - "etat_suite" qui se trouve est la suite de "etat_lect" qui contient le nouvelle etat, le nombre qu'il doit ecrire 
						         puis le deplacement qui doit effectuer( 1 = deplacement vers la droite et -1 vers la gauche).
Nous avons par la suite initer deux type def afin de raccourcir notre code.

//-------------------- Les fonctions --------------------\\

La fonction "creation_etat_lect" remplie une struture (initialise donc notre premiere ligne de notre tableau de Turing) puis renvoie un "etat_lect",
"creation_etat_suit" une la continuation de la précédante elle permet de construire la suite de la de nos etats déjà fabriquer précédament.

La fonction "aff" permet d'affiche le vecteur qui sera utiliser pou nos futur transaction avec notre programme.

La fonction "remplirvec" permet juste de remplir un vecteur a une certaine taille fixe.

la fonction "action_etat"(nom a redifinr plus tard car elle n'est pas tres explicite) 
permet de rajouter 1 dans notre bande (vecteur) remplie de 0 et de 1 (et de 2 mais eux représente le NULL dans notre code).
Selon le nombre actuel de la bande, on redefinie un nouvel etat pour ensuite réecrire la bande selon la suite de cette etat 
et enfin un deplacement de la bande de la gauche ou vers la droite selon ou en ai la fonction.
Enfi la fonction s'arrete dès qu'on atteint l'etat 4.

La fonction "execute" permet "d'initier" le tableau de transaction de notre machine de turing.
Elle est initialiser avant la fonction "action_etat" car cette dernier ne peut pas le faire sans cette derniere.

//-------------------- A faire dans le futur --------------------\\

-paufiner notre code;
-Rajouter d'autre fonction qu'un machine de turing pourrait faire;
-Pouvoir faire la meme chose mais avec un vecteur de taille variable;
	-Creer une fonction qui deplace tous les element d'un vecteur d'un cran;
	-creer une fonction qui calcule la taille d'un vecteur (ez ca);
-Pouvoir faire la meme chose mais avec une liste chaine;

***** MAIS SURTOUT ATTENDRE LA VALIDATION DE LA MANIERE QU'ON VIEN DE FAIRE PAR LES PROF *****
