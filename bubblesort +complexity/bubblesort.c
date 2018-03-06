#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bubble(int v[]){
  int i, j, aux;
  
  for(i=0; i<(MAX-1); i++){
	  	for(j=(MAX-2); j>=i; j++){
	  		
			    if(v[j] > v[j+1]){
			      aux = v[j];
			      v[j] = v[j+1];
			      v[j+i] = aux;
			    }
			    
		}
  }

}

void main(void){
	int v[MAX], i;

	/*
	
	for(i=0, i<=N; i++){
		v[i] = i;
	}
	
	for(i=N, i>=N; i--){
		v[i] = i;
	}
	
	*/
	
	for(i=0; i<=MAX; i++){
		v[i] = i;
	}
	
	bubble(v);
	
	printf("\n{");
	for(i=0; i<=MAX; i++){
		printf("%d, ", v[i]);
	}
	printf("}\n");
}

