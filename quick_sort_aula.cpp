#include<stdio.h>
#include<stdlib.h>

typedef struct Quick_Sort{
	int elemento;
	struct Quick_Sort *prox, *ant;
}quick_sort;


int opt;
bool Verifica_Left;
bool Verifica_Right;
int menu(void);
void opcao(int Opt, quick_sort *inicio);
void Novo_Bloco(quick_sort *inicio);
void Mostrar_Lista(quick_sort *inicio);
void Organize_Quick_Sort(quick_sort *inicio);
void Organize_Left(quick_sort *inicio, quick_sort *Pivot);
void Organize_Right(quick_sort *inicio, quick_sort * Pivot);

int main(void){
	quick_sort *inicio = (quick_sort *)malloc(sizeof(quick_sort));
	if(!inicio){
		printf("Não Há Memoria Disponível");
	}
	else{
		inicio->prox = NULL;
		inicio->ant = NULL;
	}
	do{
		 opt = menu();
		 opcao(opt,inicio);
	}while(opt);
}

int menu (void){
	printf("\n\n Para Adicionar Numeros Pressione 1"
		   "\n Para Ver a Lista Pressione 2."
		   "\n Para Organizar por Selection Sort Pressione 3"
		   "\n Opcao: ");
	scanf("%d", &opt);
	return opt;
}

void opcao(int Opt, quick_sort * inicio){
	switch(Opt){
		case 1:
			Novo_Bloco(inicio);
			break;
		case 2:
			Mostrar_Lista(inicio);
			break;
		case 3:
			Organize_Quick_Sort(inicio);
			break;
	}
}
void Novo_Bloco(quick_sort*inicio){
	int m,k;
for(m=0;m<=30;m++){
	quick_sort *tmp;
	quick_sort *novo = (selection_sort *)malloc(sizeof(selection_sort));
	if(!novo){
		printf("\n Nao Ha Memoria Disponivel");
		return;
	}
	if(inicio->prox == NULL){
		inicio->prox = novo;
		novo->ant = inicio;
		novo->prox = NULL;
	}
	else{
		tmp = inicio->prox;
		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}
		novo->prox = NULL;
		tmp->prox = novo;
		novo->ant = tmp;
	}
	novo->elemento = rand()%300;
}
	return;
}

void Mostrar_Lista(quick_sort *inicio){
	quick_sort *tmp;
	if(inicio->prox == NULL){
		printf("\n Lista Vazia");	
	}
	else{
		tmp = inicio->prox;
		while(tmp!=NULL){
			printf("\n Numero: %d", tmp->elemento);
			tmp=tmp->prox;
		}
	}
	return;
}

void Organize_Quick_Sort(quick_sort *inicio){
	quick_sort *pivot;
	pivot = inicio->prox;
	int i, j=1;
	for(i=0;i<=j;i++){
		Organize_Left(inicio, pivot);
		void Organize_Right(inicio,pivot);
		
	}
}

void Organize_Left(quick_sort *inicio, quick_sort *Pivot){
	quick_sort *tmp1, *tmp2,  *tmp_percorrer, *menor;
	maior = Pivot;
	if(Pivot->ant == inicio){
		break;
	}
	else{
		tmp_percorrer = Pivot->ant;	
	}
	while(tmp_percorrer != inicio){
		if(maior->elemento >= tmp_percorrer->elemento){
			tmp_percorrer = tmp_percorrer->ant;
			Verifica_Left = false;
		}
		else{
			maior = tmp_percorrer;
			tmp_percorrer = tmp_percorrer->ant;
			Verifica_Left = true;
		}
	}
	if(Verifica_Left == true){
		tmp2= maior->ant;
		if(Pivot->ant == maior){
			Pivot->prox->ant = maior;
			maior->prox = Pivot->prox;
			Pivot->prox = maior;
			maior->ant = Pivot
			tmp2->prox = Pivot;
			Pivot->ant = tmp2;
		}
		tmp1 = maior->prox;
		Pivot->ant->prox = maior;
		Pivot->prox->ant = maior;
		maior->prox = Pivot->prox;
		maior->ant = Pivot->ant;
		Pivot->prox = tmp1;
		tmp1->ant = Pivot;
		Pivot->ant = tmp2;
		tmp2->prox = Pivot;
		break;				
	}
	if(Verifica_Left == false){
		break;
	}
}
void Organize_Right(quick_sort *inicio, quick_sort *Pivot){
	quick_sort *tmp1, *tmp2,  *tmp_percorrer, *menor;
	menor = Pivot;
	if(Pivot->prox == NULL){
		break;
	}
	else{
		tmp_percorrer = Pivot->prox;
	}
	While(tmp_percorrer != NULL){
		if(menor->elemento < tmp_percorrer->elemento){
			tmp_percorrer = tmp_percorrer->prox;
			Verifica_Right = false;
		}
		else{
			menor = tmp_percorrer;
			tmp_percorrer = tmp_percorrer->prox;
			Verifica_Right = true;
		}
	}
	if(Verifica_Right == true){
		if(menor->ant == Pivot){
			tmp1 = menor->prox;
			Pivot->ant->prox = menor;
			menor->ant = Pivot->ant;
			menor->prox = Pivot;
			Pivot->ant = menor;
			Pivot->prox = tmp1;
			tmp1->ant = Pivot;
			break;
		}
		else{
			if(maior->prox != NULL){
				tmp1 = menor->prox;
				tmp2 = menor->ant;
				Pivot->ant->prox = menor;
				Pivot->ant->prox = menor;
				menor->prox = Pivot->prox;
				menor->ant = Pivot->ant;
				tmp2->prox = Pivot;
				Pivot->ant = tmp2;
				Pivot->prox = tmp1;
				tmp1->ant = Pivot;
				break;
			}
			if(maior->prox == NULL){
				tmp2 = menor->ant;
				Pivot->ant->prox = menor;
				Pivot->prox->ant = menor;
				menor->ant = Pivot->ant;
				menor->prox = Pivot->prox;
				tmp2->prox = Pivot;
				Pivot->ant = tmp2;
				Pivot->prox == NULL;
				break;
			}
		}
	
	}
	if(Verifica_Right == false){
		break;
	}
}


