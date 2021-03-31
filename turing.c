#include <stdio.h>
#include "liste.h"
#include "struct.h"
liste deplacement(liste l, int mouvement){
	if(mouvement ==  1){
		return l -> next;	
	} else {
		return l -> previous;
	}
}
void action_etat(liste l, int position, transition_etat ** tab, int etat_actuel){
	int fin = -1;
	int i = 0;
	/*if( (liste == NULL) || (tab == NULL)){
	return;
	}*/
	while(etat_actuel != fin){
	if(i == 3){
		i = 0;
	}
	if (l->nb == tab[etat_actuel][i].lu){
		l -> nb = tab[etat_actuel][i].ecrit;
		l = deplacement(l, tab[etat_actuel][i].deplacement);
						
		etat_actuel = tab[etat_actuel][i].etat_suivant;
	}
	i++;
	}
}

void add1(liste l){
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
//int action_etat(int etat, transition_etat zero, transition_etat un, transition_etat deux, int *liste, int position){ /
	transition_etat e3_0_lect = creation_transition_etat(2,0, -1,1,-1);
	e2[0] = e3_0_lect;

	transition_etat e3_1_lect = creation_transition_etat(2,1, 2,0,-1);
	e2[1] = e3_1_lect;

	transition_etat e3_2_lect = creation_transition_etat(2,2,-1,1,-1);
	e2[2] = e3_2_lect;

	table[0] = e0;
	table[1] = e1;
	table[2] = e2;

	action_etat(l, 0, table, 0);
}

void addition(liste l, int nb){
	for(int i = 0; i < nb; i++){
	add1(l);
	}
}

void inverse(liste l){
	
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

	action_etat(l, 0, table, 0);
}

void multiplieBy2 (liste l){
	   
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

	action_etat(l, 0, table, 0);
}

void soustract_1(liste l){

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

	action_etat(l, 0, table, 0);
}

void sous(liste l, int nb){
	for(int i = 0 ; i <nb ; i++){
		soustract_1(l);
	}
}

int main() {
 // 1 = droite , -1 = gauche
//transition_etat creation_transition_etat(int etat, etat_suite * nxt){
	liste l;
	l = creation(2, l);
	remplir_liste(l, 1);
	afficher(l);
	add1(l);
	printf("Voici le liste al plus 1 : \n");
	afficher(l);
	inverse(l);
	printf("Voici le liste inverser : \n");
	afficher(l);
	addition(l, 3);
	printf("voici le nouveau liste : \n");
	afficher(l);
	soustract_1(l);
	printf("voici le nouveau liste al moin 1: \n");
	afficher(l);
	sous(l, 4);
	printf("voici le nouveau liste soustrait : \n");
	afficher(l);
	multiplieBy2 (l);
	printf("voici le nouveau liste multiplier par 2 : \n");
	afficher(l);
}


