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


