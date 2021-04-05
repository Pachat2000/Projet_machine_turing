#include <stdlib.h>
struct element{ 
	int nb;
	struct element * previous;
	struct element * next;
};

typedef struct element element_t; // taille d'un élément 
typedef struct element * liste;


