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

void action_etat(int *vec, int position, transition_etat * tab, int etat_actuel){
  if ((etat_actuel == -1) || (vec == NULL) || (tab == NULL) ){
  } else {
     for(int i = 0; i < 2; i ++){
       if (vec[position] == tab[etat_actuel][i].lu){

         etat_actuel = tab[etat_actuel][i].etat_suivant;
         vec[position] = tab[etat_actuel][i].ecrit;
         position += tab[etat_actuel][i].deplacement;

         action_etat(vec, position, tab, etat_actuel);
     }
   }   
}
}

transition_etat execution(int *vec){
//_________________________________________________________________
//etat_suite creation_etat_suite(int etat_suivant, int ecrit, int deplacement){
	transition_etat table[2];
	transition_etat e0[0];
	transition_etat e1[2];
	transition_etat e2[2];
    
	transition_etat e1_2_lect = creation_transition_etat(1,2,2,2,1);
	e0[0] = e1_2_lect;
//_________________________________________________________________

	transition_etat e2_0_lect = creation_transition_etat(2,0,2,0,1);
	e1[0] = e2_0_lect;

	transition_etat e2_1_lect = creation_transition_etat(2,1, 2,1,1);
	e1[1] = e2_1_lect;

	transition_etat e2_2_lect = creation_transition_etat(2,2, 3,2,-1);
	e1[2] = e2_2_lect;

//_________________________________________________________________
//int action_etat(int etat, transition_etat zero, transition_etat un, transition_etat deux, int *vec, int position){ /
	transition_etat e3_0_lect = creation_transition_etat(3,0, 4,1,-1);
	e2[0] = e3_0_lect;

	transition_etat e3_1_lect = creation_transition_etat(3,1, 3,0,-1);
	e2[1] = e3_0_lect;

	transition_etat e3_2_lect = creation_transition_etat(3,2,4,1,-1);
	e2[3] = e3_0_lect;

	table[0] = e0;
	table[1] = e1;
	table[2] = e2;

	action_etat(vec, 0, table, 0);
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
 // 1 = droite , -1 = gauche
//transition_etat creation_transition_etat(int etat, etat_suite * nxt){
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


