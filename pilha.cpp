/* Algoritmo para ciração de Pilha*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node{
	int num;
	struct node *prox;
};

typedef struct node Node;
int tam;
int opt;
int menu(void);
void opcao(Node *pilha ,int Opt);
void push(Node *pilha);
void exibir(Node *pilha);
void excluir(Node *pilha);

int main(void){
	Node *pilha = (Node *)malloc(sizeof(Node));
	if(!pilha){
		printf("Nao Ha memoria");
	}
	else
		pilha->prox = NULL;
	do{
		opt = menu();
		opcao(pilha,opt);		
	}while(opt);
}

int menu(void){
	printf("\n \t\t 1. Para adcionar um elemento a pilha"
	       "\n \t\t 2. Para Ver elementos da Pilha"
		   "\n  \t\t 3. Para Exlcuir Ultimo elemento da Pilha"
		   "\n \t\t Escolha a Opcao: ");
	scanf("%d", &opt);
	return opt;
}

void opcao(Node * pilha, int Opt){
	switch(Opt){
		case 1:
			push(pilha);
			break;
		case 2:
			exibir(pilha);
			break;
		case 3:
			excluir(pilha);
			break;
			
	}
}

void push(Node *pilha){
	Node *novo = (Node *)malloc(sizeof(Node));
	if(!novo){
		printf("Nao Ha memoria");
	}
	novo->prox = NULL;
	system("cls");
	printf("\n\n Digite o Numero: ");
	scanf(" %d", &novo->num);
	printf("\n Numero Cadastrado Com Sucesso");
	Sleep(500);
	system("cls");
	if(pilha->prox == NULL){
		pilha->prox = novo;
		tam++;
	}	
	else{
		Node *tmp;
		tmp = pilha->prox;
		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}
		tmp->prox = novo;
		tam++;		
		}
	return;
}
	


void exibir(Node *pilha){
	if(pilha->prox == NULL){
		printf("Pilha Vazia");
	}
	else{
		Node *tmp;
		tmp = pilha->prox;
		while(tmp != NULL){
			printf("\n \t Valor: %d", tmp->num);
			tmp = tmp->prox;
		}
		printf("\n Elemento Na pilha: %d", tam);
	}
	return;
}

void excluir(Node *pilha){
	if(pilha->prox == NULL){
		printf("Sem Elemento na Pilha");
		return;
	}
	Node *ultimo, *penultimo;
	penultimo = pilha;
	ultimo = pilha->prox;
	while(ultimo->prox != NULL){
		penultimo = ultimo;
		ultimo = ultimo->prox;
	}
	free(ultimo);
	penultimo->prox =NULL;
	tam--;
	printf("Excluido com sucesso");
	Sleep(500);
	system("cls");
}
