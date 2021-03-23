#include <stdio.h>


struct etat_lect {
	int etat; 
	int lu;
	struct etat_suite * nxt; 
};
struct etat_suite{
	int nouvel_etat;
	int ecrit;
	int deplacement;
};
typedef struct etat_lect etat_lect;
typedef struct etat_suite etat_suite;


etat_lect creation_etat_lect(int etat, int lu, etat_suite * nxt){
	etat_lect x;
	x.etat = etat;
	x.lu= lu;
	x.nxt = nxt;
	return x;
}

etat_suite creation_etat_suite(int nouvel_etat, int ecrit, int deplacement){
	etat_suite x;
	x.nouvel_etat = nouvel_etat;
	x.ecrit = ecrit;
	x.deplacement = deplacement;
	return x;
}

void aff(int *vec, int size){
	int i;
	for(i = 0; i<size;i++){
	printf("%d",vec[i]);
	}
	printf("\n");
}
void remplirvec(int * vec){
	vec[0]= 2;
	vec[1]= 1;
	vec[2]= 1;
	vec[3]= 1;
	vec[4]= 1;
	vec[5] = 2;
}


int action_etat(int etat, etat_lect zero, etat_lect un, etat_lect deux, int *vec, int position){ //pour un etat donné, on exécute tant qu'on reste dedans
//on reste dans la boucle tant que l'on reste dans le même état 
	int etat_actuel = etat;
	while(etat_actuel == etat){
		if(vec[position] == zero.lu){
			etat_actuel = (zero.nxt) -> nouvel_etat; // l'état actuel vaut sont nouvel état (de nxt)
			vec[position] = (zero.nxt) -> ecrit; // vecteur à la position "position" prend la valeur de écrit de nxt
			position += (zero.nxt) -> deplacement;
		}
		if(vec[position] == un.lu && etat_actuel == etat){ // le and pour vérifier si etat_actuel n'a pas déjà changer
			etat_actuel = (un.nxt) -> nouvel_etat;
			vec[position] = (un.nxt) -> ecrit;
			position += (un.nxt) -> deplacement;
		}
		if(vec[position] == deux.lu && etat_actuel == etat){
			etat_actuel = (deux.nxt) -> nouvel_etat;
			vec[position] = (deux.nxt) -> ecrit;
			position += (deux.nxt) -> deplacement;
		}	
	}
	return etat_actuel;
} 

int main() {
/*struct etat_lect {
	int etat; 
	int lu;
	struct etat_suite * nxt; 
};
struct etat_suite{
	int nouvel_etat;
	int ecrit;
	int deplacement;
};*/

	// 1 = droite , -1 = gauche
//etat_lect creation_etat_lect(int etat, int lu, etat_suite * nxt){

	int vec[6];
	remplirvec(vec);
	aff(vec,6);
//_________________________________________________________________
//etat_suite creation_etat_suite(int nouvel_etat, int ecrit, int deplacement){


	etat_suite e1_2 = creation_etat_suite(2,2,1);
	etat_lect e1_2_lect = creation_etat_lect(1,2, &e1_2);

//_________________________________________________________________

	etat_suite e2_0 = creation_etat_suite(2,0,1);
	etat_lect e2_0_lect = creation_etat_lect(2,0, &e2_0);

	etat_suite e2_1 = creation_etat_suite(2,1,1);
	etat_lect e2_1_lect = creation_etat_lect(2,1, &e2_1);

	etat_suite e2_2 =  creation_etat_suite(3,2,-1);
	etat_lect e2_2_lect = creation_etat_lect(2,2, &e2_2);

//_________________________________________________________________

	etat_suite e3_0 = creation_etat_suite(4,1,-1);
	etat_lect e3_0_lect = creation_etat_lect(3,0, &e2_0);

	etat_suite e3_1 = creation_etat_suite(3,0,-1);
	etat_lect e3_1_lect = creation_etat_lect(3,1, &e2_1);

	etat_suite e3_2 = creation_etat_suite(4,1,-1);
	etat_lect e3_2_lect = creation_etat_lect(3,2, &e2_2);

//_________________________________________________________________

	int nouvel_etat = action_etat(1, e1_2_lect, e1_2_lect, e1_2_lect, vec, 0);  
	
	printf("la valeur de nouvel etat: %d \n", nouvel_etat);
	
}

