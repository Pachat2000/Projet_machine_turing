#include <stdio.h>


struct transition_etat{
	int etat_actuel; 
	int lu;
	int etat_suivant;
	int ecrit;
	int deplacement;
};
typedef struct transition_etat transition_etat;


transition_etat creation_transition_etat(int etat_actuel, int lu, int etat_suivant, int ecrit, int deplacement ){
	transition_etat x;

	x.etat_actuel = etat_actuel;
	x.lu= lu;
	x.etat_suivant = etat_suivant;
	x.ecrit = ecrit;
	x.deplacement = deplacement;

	return x;
}

/*etat_suite creation_etat_suite(int etat_suivant, int ecrit, int deplacement){
	etat_suite x;
	x.etat_suivant = etat_suivant;
	x.ecrit = ecrit;
	x.deplacement = deplacement;
	return x;
}*/

void aff(int *vec, int size){
	int i;
	for(i = 0; i<size;i++){
	printf("%d",vec[i]);
	}
	printf("\n");
}

void remplirvec(int * vec, int nb){
    switch(nb){
    case 0:
	vec[0]= 2;
	vec[1]= 1;
	vec[2]= 1;
	vec[3]= 1;
	vec[4]= 1;
	vec[5] = 2;
	break;
    case 1:
	vec[0]= 2;
	vec[1]= 1;
	vec[2]= 0;
	vec[3]= 1;
	vec[4]= 0;
	vec[5] = 1;
	vec[6] = 1;
	vec[7] = 2;
	break;
    case 2:
	vec[0]= 2;
	vec[1]= 1;
	vec[2]= 0;
	vec[3]= 1;
	vec[4]= 2;
	break;
    default:
	vec[0]= 2;
	vec[1]= 1;
	vec[2]= 2;
	break;
	
    }
}


int action_etat(int etat, transition_etat zero, transition_etat un, transition_etat deux, int *vec, int position){ //pour un etat donné, on exécute tant qu'on reste dedans
//on reste dans la boucle tant que l'on reste dans le même état 
	int etat_actuel = etat;
	while(etat_actuel == etat){
		if(vec[position] == zero.lu){
			etat_actuel = zero.etat_suivant; // l'état actuel vaut sont nouvel état (de nxt)
			vec[position] = zero.ecrit; // vecteur à la position "position" prend la valeur de écrit de nxt
			position += zero.deplacement;
		}
		if(vec[position] == un.lu && etat_actuel == etat){ // le and pour vérifier si etat_actuel n'a pas déjà changer
			etat_actuel = un.etat_suivant;
			vec[position] = un.ecrit;
			position += un.deplacement;
		}
		if(vec[position] == deux.lu && etat_actuel == etat){
			etat_actuel = deux.etat_suivant;
			vec[position] = deux.ecrit;
			position += deux.deplacement;
		}	
	}
	return position;
}

void execution(int *vec){
//_________________________________________________________________
//etat_suite creation_etat_suite(int etat_suivant, int ecrit, int deplacement){

	transition_etat e1_2_lect = creation_transition_etat(1,2,2,2,1);
//_________________________________________________________________

	transition_etat e2_0_lect = creation_transition_etat(2,0,2,0,1);

	transition_etat e2_1_lect = creation_transition_etat(2,1, 2,1,1);

	transition_etat e2_2_lect = creation_transition_etat(2,2, 3,2,-1);

//_________________________________________________________________
//int action_etat(int etat, transition_etat zero, transition_etat un, transition_etat deux, int *vec, int position){ /
	transition_etat e3_0_lect = creation_transition_etat(3,0, 4,1,-1);

	transition_etat e3_1_lect = creation_transition_etat(3,1, 3,0,-1);

	transition_etat e3_2_lect = creation_transition_etat(3,2,4,1,-1);

//_________________________________________________________________
	int position = 0;
	position = action_etat(1, e1_2_lect, e1_2_lect, e1_2_lect, vec, position);
	
	position = action_etat(2, e2_0_lect,e2_1_lect, e2_2_lect, vec, position);
	action_etat(3, e3_0_lect,e3_1_lect, e3_2_lect, vec, position);
}
/*void inverse(int * vec){ 
	
	etat_suite e2_0 = creation_etat_suite(2,1,1);
	transition_etat e2_0_lect = creation_transition_etat(2,0, &e2_0);

	etat_suite e2_1 = creation_etat_suite(2,0,1);
	transition_etat e2_1_lect = creation_transition_etat(2,1, &e2_1);

	etat_suite e2_2 =  creation_etat_suite(3,2,-1);
	transition_etat e2_2_lect = creation_transition_etat(2,2, &e2_2);

	int position = 0;
	position = action_etat(1, e1_2_lect, e1_2_lect, e1_2_lect, vec, position);
	
	position = action_etat(2, e2_0_lect,e2_1_lect, e2_2_lect, vec, position);
	
}
*/
int main() {
/*struct transition_etat {
	int etat; 
	int lu;
	struct etat_suite * nxt; 
};
struct etat_suite{
	int etat_suivant;
	int ecrit;
	int deplacement;
};*/

	// 1 = droite , -1 = gauche
//transition_etat creation_transition_etat(int etat, int lu, etat_suite * nxt){

	int vec[6];
	remplirvec(vec,1);
	aff(vec,6);
	execution(vec);
	printf("Voici le vecteur avec plus 1 : \n");
	aff(vec, 6);
	int vec2[8];
	remplirvec(vec2, 1);
	aff(vec2,8);
	execution(vec2);
	printf("Voici le vecteur avec plus 1 : \n");
	aff(vec2, 8);
	/*printf("Voici le vecteur inverser: \n");
	inverse(vec2);
	aff(vec2,8);*/
}


