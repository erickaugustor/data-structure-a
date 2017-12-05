/*
 *	ÁRVORE BINÁRIA.
 *
 *	ÁRVORES: São um tipo especial de grafo. 
 *  Grafos: Qualquer parte do vértice está conectado apenas a uma aresta.
 *  Grafo conexo, sempre terá um caminho. 
 *  É Acíclico. 
 *  
 *  VÉRTICE SÃO OS NÓS. 
 *  ARESTAS É A CONEXÃO DOS VÉRTICES.
 *
 *  Pai é o antecessor de um vértie. Filho é o sucessor. Raiz é quem não possuí pai. Folhas, nó sem filhos.
 *  Grau do vértice, quantas sub-arvores.
 *  Altura é o comprimento mais alto até a folha.
 *
 */

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
	no *raiz = NULL;
		
	int opcao, N, retorno;
	time_t entrada, saida;
	char resp;

	do{
		printf("  Menu de opcoes:\n\n");
		
		//Menu
		printf("   [1] Inserir um no! \n");
		printf("   [2] Consulta na arvore! \n");
		printf("   [3] PRE ORDEM! \n");
		printf("   [4] EM  ORDEM! \n");
		printf("   [5] POS ORDEM! \n");
		printf("   [6] Soma dos valores! \n");
		printf("   [7] Valores pares! \n");
		printf("   [8] Altura da arvore! \n");
		printf("   [0] Sair \n\n\n");
			
		//Digitar o que será feito!
		printf(" Digite uma opcao: ");
		scanf("%i", &opcao);
			
		switch(opcao){
			case 1:
				printf("[ ] Digite um valor para adicionar: ");
				scanf("%i", &N);

				retorno = inserirArv(&raiz, N);

				if(retorno == 1) printf("\n[ ] O registro: %d foi adicionado com sucesso!", N);
				else printf("Erro!");

			break;
			
			case 2:
				printf("[ ] Digite um valor para procurar: ");
				scanf("%i", &N);

				retorno = pertenceArv(N, raiz);

				if(retorno == 1) printf("\n[ ] O registro: %d foi encontrado com sucesso!", N);
				else printf("Erro!");
			break;
			
			case 3:
				preArv(raiz);
			break;
			
			case 4:
				emArv(raiz);
			break;
		
			case 5:
				posArv(raiz);
			break;
			
			case 6:
				retorno = soma(raiz);
				printf("\n[ ] A soma é: %d foi encontrado com sucesso!", retorno);
			break;
			
			case 7:
				retorno = pares(raiz);
				printf("\n[ ] O número de pares eh: %d!", retorno);
			break;
			
			case 8:
				retorno = altura(raiz);
				printf("\n[ ] A altura eh: %d!", retorno);
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


int pertenceArv(int N, no *raiz){
	if(raiz == NULL) return (0);
	if(N == (raiz -> chave)) return (1);
	
	//Se N for menor que a raiz, provavelmente estará nolado esquerdo.
	if(N < (raiz->chave)){
		return(pertenceArv(N, raiz -> esq));
	}
	
	//Ou provavelmente estará no lado direito.
	return(pertenceArv(N, raiz -> dir));
}


preArv(no *raiz){
	if(raiz){
		//CHAVE, ESQ, DIR.
		printf("%d ", raiz -> chave);
		preArv(raiz -> esq);
		preArv(raiz -> dir);
	}
	
}


emArv(no *raiz){
	//ESQ, CHAVE, DIR
	emArv(raiz -> esq);
	printf("%d ", raiz -> chave);
	preArv(raiz -> dir);
}


posArv(no *raiz){
	//ESQ, DIR, CHAVE
	preArv(raiz -> esq);
	preArv(raiz -> dir);
	printf("%d ", raiz -> chave);
}


int soma(no *raiz){
	//Fila está vazia?
	if((*raiz) == NULL) return (0);
	else return(1 + soma(raiz -> esq) + soma(raiz -> dir));
}


int pares(no *raiz){
	if(raiz == NULL) return 0;
	else return( (raiz->chave%2)? 1+pares(raiz->esq)+pares(raiz->dir) : pares(raiz->esq)+pares(raiz->dir) );
}


int altura(no *raiz){
	if(raiz == NULL) return 0;
	int E = altura(raiz->esq);
	int D = altura(raiz->dir);
	return(E>D ? 1 + E : 1 + D);
}

/*
int removerArv(no **raiz, int numero){
	
	if(numero < (*raiz)->chave)
		return(removerArv(&(*raiz)->esq, numero));
	
	
	if(numero > (*raiz)->chave)
		return(removerArv(&(*raiz)->dir, numero));
	
	
	if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
		
		no *aux = (*raiz);
		if((*raiz)->esq == NULL)
			(*raiz) = (*raiz) -> dir;
		else
			*raiz = (*raiz) -> esq;
			
		free(aux);	
		
	}else{
	
		no *aux = NULL;
		aux
		(*raiz)->valor = aux->valor;
		removerArv(&(*raiz)->dir, (*raiz)->chave);
		
	}
}

*/

