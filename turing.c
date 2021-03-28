#include <stdio.h>


struct etat_lect{
	int etat_actuel;
        int lu;
	int etat_suivant;
	int ecrit;
	int deplacement;
};
typedef struct etat_lect etat_lect;


etat_lect creation_etat_lect(int etat_actuel, int etat_suivant, int ecrit, int deplacement ){
	etat_lect x;

	x.etat_actuel = etat_actuel;
	x.etat_suivant = etat_suivant;
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


int action_etat(int etat, etat_lect *tab, int *vec, int position){ //pour un etat donné, on exécute tant qu'on reste dedans
//on reste dans la boucle tant que l'on reste dans le même état 
	int etat_actuel = etat;
	while(etat_actuel == etat){
		if(vec[position] == 0 && tab->lu ==0 ){
			etat_actuel = zero.etat_suivant; // l'état actuel vaut sont nouvel état (de nxt)
			vec[position] = zero.ecrit; // vecteur à la position "position" prend la valeur de écrit de nxt
			position += zero.deplacement;
		}
		if(vec[position] == 1  && etat_actuel == etat){ // le and pour vérifier si etat_actuel n'a pas déjà changer
			etat_actuel = un.etat_suivant;
			vec[position] = un.ecrit;
			position += un.deplacement;
		}
		if(vec[position] == 2 && etat_actuel == etat){
			etat_actuel = deux.etat_suivant;
			vec[position] = deux.ecrit;
			position += deux.deplacement;
		}	
	}
	return position;
}

etat_lect execution(int *vec){
//_________________________________________________________________
//etat_suite creation_etat_suite(int etat_suivant, int ecrit, int deplacement){
    etat_lect table[2];
    etat_lect e0[0];
    etat_lect e1[2];
    etat_lect e2[2];
    
	etat_lect e1_2_lect = creation_etat_lect(1,2,2,2,1);
	e0[0] = e1_2_lect;
//_________________________________________________________________

	etat_lect e2_0_lect = creation_etat_lect(2,0,2,0,1);
	e1[0] = e2_0_lect;

	etat_lect e2_1_lect = creation_etat_lect(2,1, 2,1,1);
	e1[1] = e2_1_lect;

	etat_lect e2_2_lect = creation_etat_lect(2,2, 3,2,-1);
	e1[2] = e2_2_lect;

//_________________________________________________________________
//int action_etat(int etat, etat_lect zero, etat_lect un, etat_lect deux, int *vec, int position){ /
	etat_lect e3_0_lect = creation_etat_lect(3,0, 4,1,-1);
	e2[0] = e3_0_lect;

	etat_lect e3_1_lect = creation_etat_lect(3,1, 3,0,-1);
	e2[1] = e3_0_lect;

	etat_lect e3_2_lect = creation_etat_lect(3,2,4,1,-1);
	e2[3] = e3_0_lect;

	table[0] = e0;
	table[1] = e1;
	table[2] = e2;

	return table;

}
void inverse(int * vec){ 
	
	etat_suite e2_0 = creation_etat_suite(2,1,1);
	etat_lect e2_0_lect = creation_etat_lect(2,0, &e2_0);

	etat_suite e2_1 = creation_etat_suite(2,0,1);
	etat_lect e2_1_lect = creation_etat_lect(2,1, &e2_1);

	etat_suite e2_2 =  creation_etat_suite(3,2,-1);
	etat_lect e2_2_lect = creation_etat_lect(2,2, &e2_2);

	int position = 0;
	position = action_etat(1, e1_2_lect, e1_2_lect, e1_2_lect, vec, position);
	
	position = action_etat(2, e2_0_lect,e2_1_lect, e2_2_lect, vec, position);
	
}

int main() {


 // 1 = droite , -1 = gauche
//etat_lect creation_etat_lect(int etat, etat_suite * nxt){

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


