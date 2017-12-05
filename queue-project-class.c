	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	typedef struct tno{
    	int chave;
    	time_t entrada, saida;
    	struct tno *prox;
	} no;

	int insere_inicio(int N, no **inicio, time_t *entrada);

	void imprime(no *inicio);

	void soma(no *inicio);

	void imprime_recursivo(no *inicio);

	void imprime_recursivo_inverso(no *inicio);

	void remover(no **inicio, time_t *saida);

	void main(void){
		int opcao, N, retorno;
		no *inicio = NULL;
		time_t entrada, saida;
		char resp;

		do{
			printf("  Menu de opcoes:\n\n");
			printf("   1.Inserir um no! \n   2.Imprimir um no! \n   3.Soma dos valores do ponteiro! \n   4.Imprimindo com recursividade! \n   5. Imprimindo ao contrario com recursividade! \n   6. Removendo o no! \n   0.Sair \n\n\n");
			printf(" Digite uma opcao: ");
			scanf("%i", &opcao);
			switch(opcao){
				case 1:
					printf("Digite um valor para adicionar: ");
					scanf("%i", &N);

					retorno = (insere_inicio(N, &inicio, &entrada));

					if(retorno == 1) printf("O registro: %d foi adicionado com sucesso no endereco %d! \n\n", N, (* inicio));
					else printf("Erro!");

					break;
				case 2:
					imprime(inicio);
					break;
				case 3:
					soma(inicio);
					break;
				case 4:
					imprime_recursivo(inicio);
					break;
				case 5:
					imprime_recursivo_inverso(inicio);
					break;
                case 6:
                    remover(&inicio, &saida);
                    break;
			}

			printf("Digite algo para prosseguir: \n");
	        scanf("%s", &resp);

            system("cls");

		}while(opcao != 0);
	}

	int insere_inicio(int N, no **inicio, time_t *entrada){
		no *novo;
		novo = (no *) malloc(sizeof(no));

		if(novo == NULL) return(-1);

		novo -> chave = N;
		novo -> entrada = time(&entrada);
		novo -> prox = (* inicio);

		(* inicio) = novo;
		return(1);
	}

	void imprime(no *inicio){
		while(inicio != NULL){
			printf("%d. %d.", inicio -> chave, (int) (inicio -> entrada));
			inicio = inicio -> prox;
		}
	}

	void soma(no *inicio){
		int acc = 0;
		while(inicio != NULL){
			acc = acc + (inicio -> chave);
			inicio = inicio -> prox;
		}
		printf("O resultado da soma dos ponteiros eh: %d", acc);
	}

	void imprime_recursivo(no *inicio){
		if(inicio != NULL){
			printf("%d. ", inicio -> chave);
			imprime(inicio -> prox);
		}
	}

	void imprime_recursivo_inverso(no *inicio){
		if(inicio != NULL){
			imprime(inicio -> prox);
			printf("%d. ", inicio -> chave);
		}
	}

	void remover(no **inicio, time_t *saida){
        if((*inicio) == NULL) printf("ERROR");
        no *aux = (*inicio);
        int N = aux -> chave;
        (*inicio) -> saida = time(&saida);

        printf("O index passou %d segundos na fila! \n", (int) difftime(((*inicio) -> saida),  ((*inicio) -> entrada)));

        (*inicio) = (*inicio) -> prox;
        free(aux);
        printf("O index excluido foi: %d! \n", N);
	}
