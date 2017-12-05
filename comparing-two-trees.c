#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structs
typedef struct tno{
	int chave;
	struct tno *esq, *dir;
} no;

//Prototipe
int inserirArv(no **raiz, int numero);
int pertenceArv(int N, no *raiz);
void preArv(no *raiz);
void emArv(no *raiz);
void posArv(no *raiz);
int soma(no *raiz);
int pares(no *raiz);
int altura(no *raiz);
//int removerArv(no **raiz, int numero);

//Main
void main(void){
	no *raiz-um = NULL;
	no *raiz-dois = NULL;	
		
	int opcao, N, retorno;
	time_t entrada, saida;
	char resp;

	do{
		printf("  Menu de opcoes:\n\n");
		
		//Menu
		printf("   [1] Inserir um no na arvore um! \n");
		printf("   [2] Inserir um no na arvore dois! \n");
		printf("   [3] PRE ORDEM! \n");
		printf("   [4] EM  ORDEM! \n");
		printf("   [5] EM  ORDEM! \n");
		printf("   [0] Sair \n\n\n");
			
		//Digitar o que será feito!
		printf(" Digite uma opcao: ");
		scanf("%i", &opcao);
			
		switch(opcao){
			case 1:
				printf("[ ] Digite um valor para adicionar: ");
				scanf("%i", &N);

				retorno = inserirArv(&raiz-um, N);

				if(retorno == 1) printf("\n[ ] O registro: %d foi adicionado com sucesso!", N);
				else printf("Erro!");

			break;
			
			case 2:
				printf("[ ] Digite um valor para adicionar: ");
				scanf("%i", &N);

				retorno = inserirArv(&raiz-dois, N);

				if(retorno == 1) printf("\n[ ] O registro: %d foi adicionado com sucesso!", N);
				else printf("Erro!");

			break;
			
			case 3:
				
			break;
			
			case 4:
				
			break;
		
			case 5:
				
			break;
			
			}
			
			//Flag!
			printf("Digite algo para prosseguir: \n");
	        scanf("%s", &resp);

            system("cls");

		}while(opcao != 0);
}

//Functions
int inserirArv(no **raiz, int numero){
	//Está nulo?
	if((*raiz) == NULL){
		
		//Alocar espaço
		(*raiz) = (no*) malloc(sizeof(no));
		
		//Heap overflow?
		if((*raiz) == NULL) return (-1);
		
		//Colocar valores.
		(* raiz) -> chave;
		(* raiz) -> dir = (* raiz) -> esq = NULL;
		return (1);
		
	}else{
		
		//Número menor que a chave?
		if(numero < (*raiz)->chave){
			return(inserirArv(&(*raiz)->esq, numero));
		}
		
		//Número maior que a chave?
		if(numero > (*raiz)->chave){
			return(inserirArv(&(*raiz)->dir, numero));
		}
	}
	
}




