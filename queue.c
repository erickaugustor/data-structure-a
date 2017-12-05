#include <stdio.h>
#include <stdlib.h>

//Structs
typedef struct tno{
	int chave;
	struct tno *prox;
} no;

//Protótipos
int insere_inicio(int N, no **inicio, no **fim);


void main(void){
	no *inicio = NULL;
	no *fim = NULL;
	
	int opcao, N, retorno;

	do{
		printf("  Menu de opcoes:\n\n");
		printf("  1.Inserir um no!\n\n\n");
		
		printf(" Digite uma opcao: ");
			scanf("%i", &opcao);
			
			switch(opcao){
				case 1:
					printf("Digite um valor para adicionar: ");
					scanf("%i", &N);

					retorno = (insere_inicio(N, &inicio, &fim));

					if(retorno == 1) printf("O registro: %d foi adicionado com sucesso no endereco %d! \n\n", N, (* inicio));
					else printf("Erro!");

					break;
			}

			printf("Digite algo para prosseguir: \n");
	        scanf("%s", &resp);

            system("cls");

		}while(opcao != 0);
}


int insere_inicio(int N, no **inicio, no **fim){
	no *novo = (no *) malloc(sizeof(no));
	if(novo == NULL) return(-1);

	novo -> chave = N;
	novo -> prox = (* inicio);
	
	if((*inicio)==NULL){
		(*inicio) = (*fim) = novo;
	}else{
		(*fim) -> prox = novo;
		(*fim) = novo;
	}

	return(1);
}

int remove (no **inicio){
	if((*inicio) == NULL) return (-1);
	no *aux = (*inicio);
	int N = aux -> chave;
	(*inicio) = (*incio) -> prox;
	free(aux);
	return(N);
}
