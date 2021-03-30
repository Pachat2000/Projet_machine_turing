#include <stdio.h>
#include "vec.h"
#include "struct.h"
void action_etat(int *vec, int position, transition_etat ** tab, int etat_actuel){
    int fin = -1;
    int i = 0;
    if( (vec == NULL) || (tab == NULL)){
	return;
    }
    while(etat_actuel != fin){
	if(i == 3){
	    i = 0;
	}
	if (vec[position] == tab[etat_actuel][i].lu){
	    vec[position] = tab[etat_actuel][i].ecrit;
	    position += tab[etat_actuel][i].deplacement;
	    etat_actuel = tab[etat_actuel][i].etat_suivant;
	}
	i++;
    }
}

void add1(int *vec){
//_________________________________________________________________
//etat_suite creation_etat_suite(int etat_suivant, int ecrit, int deplacement){
	transition_etat * table[3];
	transition_etat e0[3];
	transition_etat e1[3];
	transition_etat e2[3];
    
	transition_etat e1_2_lect = creation_transition_etat(0,2,1,2,1);
	e0[0] = e1_2_lect;

	transition_etat e1_0_lect = creation_transition_etat(0,0,1,0,0);
	e0[1] =  e1_0_lect;
	    
	transition_etat e1_1_lect = creation_transition_etat(0,1,1,1,0);
	e0[2] = e1_1_lect;
//_________________________________________________________________

	transition_etat e2_0_lect = creation_transition_etat(1,0,1,0,1);
	e1[0] = e2_0_lect;

	transition_etat e2_1_lect = creation_transition_etat(1,1, 1,1,1);
	e1[1] = e2_1_lect;

	transition_etat e2_2_lect = creation_transition_etat(1,2, 2,2,-1);
	e1[2] = e2_2_lect;

//_________________________________________________________________
//int action_etat(int etat, transition_etat zero, transition_etat un, transition_etat deux, int *vec, int position){ /
	transition_etat e3_0_lect = creation_transition_etat(2,0, -1,1,-1);
	e2[0] = e3_0_lect;

	transition_etat e3_1_lect = creation_transition_etat(2,1, 2,0,-1);
	e2[1] = e3_1_lect;

	transition_etat e3_2_lect = creation_transition_etat(2,2,-1,1,-1);
	e2[2] = e3_2_lect;

	table[0] = e0;
	table[1] = e1;
	table[2] = e2;

	action_etat(vec, 0, table, 0);
}

void addition(int *vec, int nb){
    for(int i = 0; i < nb; i++){
	add1(vec);
    }
}

void inverse(int * vec){
    
    	transition_etat * table[2];
	transition_etat e0[1];
	transition_etat e1[3];

	transition_etat e1_2_lect = creation_transition_etat(0,2,1,2,1);
	e0[0] = e1_2_lect;
	
	transition_etat e2_0_lect = creation_transition_etat(1,0,1,1,1);
	e1[0] = e2_0_lect;

	transition_etat e2_1_lect = creation_transition_etat(1,1, 1,0,1);
	e1[1] = e2_1_lect;

	transition_etat e2_2_lect = creation_transition_etat(1,2, -1, 2,-1);
	e1[2] = e2_2_lect;

	table[0] = e0;
	table[1] = e1;

	action_etat(vec, 0, table, 0);
}

void multiplieBy2 (int *vec){
       
    	transition_etat * table[2];
	transition_etat e0[1];
	transition_etat e1[3];

	transition_etat e1_2_lect = creation_transition_etat(0,2,1,2,1);
	e0[0] = e1_2_lect;
	
	transition_etat e2_0_lect = creation_transition_etat(1,0,1,0,1);
	e1[0] = e2_0_lect;

	transition_etat e2_1_lect = creation_transition_etat(1,1, 1,1,1);
	e1[1] = e2_1_lect;

	transition_etat e2_2_lect = creation_transition_etat(1,2, -1, 0,-1);
	e1[2] = e2_2_lect;

	table[0] = e0;
	table[1] = e1;

	action_etat(vec, 0, table, 0);
}

void soustract_1(int *vec){

	transition_etat * table[3];
	transition_etat e0[3];
	transition_etat e1[3];
	transition_etat e2[3];
    
	transition_etat e1_2_lect = creation_transition_etat(0,2,1,2,1);
	e0[0] = e1_2_lect;

	transition_etat e1_0_lect = creation_transition_etat(0,0,1,0,0);
	e0[1] =  e1_0_lect;
	    
	transition_etat e1_1_lect = creation_transition_etat(0,1,1,1,0);
	e0[2] = e1_1_lect;

	transition_etat e2_0_lect = creation_transition_etat(1,0,1,0,1);
	e1[0] = e2_0_lect;

	transition_etat e2_1_lect = creation_transition_etat(1,1, 1,1,1);
	e1[1] = e2_1_lect;

	transition_etat e2_2_lect = creation_transition_etat(1,2, 2,2,-1);
	e1[2] = e2_2_lect;

	transition_etat e3_0_lect = creation_transition_etat(2,0, 2,1,-1);
	e2[0] = e3_0_lect;

	transition_etat e3_1_lect = creation_transition_etat(2,1,-1, 0,-1);
	e2[1] = e3_1_lect;

	transition_etat e3_2_lect = creation_transition_etat(2,2,-1,2,-1);
	e2[2] = e3_2_lect;

	table[0] = e0;
	table[1] = e1;
	table[2] = e2;

	action_etat(vec, 0, table, 0);
}

void sous(int *vec, int nb){
    for(int i = 0 ; i <nb ; i++){
	soustract_1(vec);
    }
}

int main() {
 // 1 = droite , -1 = gauche
//transition_etat creation_transition_etat(int etat, etat_suite * nxt){
	int vec[8];
	remplirvec(vec,1);
	aff(vec,8);
	add1(vec);
	printf("Voici le vecteur avec plus 1 : \n");
	aff(vec, 8);
	inverse(vec);
	printf("Voici le vecteur inverser : \n");
	aff(vec, 8);
	addition(vec, 3);
	printf("voici le nouveau vecteur : \n");
	aff(vec, 8);
	soustract_1(vec);
	printf("voici le nouveau vecteur avec moin 1: \n");
	aff(vec, 8);
	sous(vec, 4);
	printf("voici le nouveau vecteur soustrait : \n");
	aff(vec, 8);
	multiplieBy2 (vec);
	printf("voici le nouveau vecteur multiplier par 2 : \n");
	aff(vec, 8);
}


