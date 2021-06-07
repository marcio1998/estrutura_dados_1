#include<stdio.h>
#include<stdlib.h>

typedef struct Quick_Sort{
	int elemento;
	struct Quick_Sort *prox, *ant;
}quick_sort;
int opt;
int menu(void);
void opcao(int Opt, quick_sort *inicio);
void Novo_Bloco(quick_sort *inicio);
void Mostrar_Lista(quick_sort *inicio);
void organizar(quick_sort *inicio);
void organizar_left(quick_sort *inicio, quick_sort *Pivot);
void organizar_right(quick_sort *inicio, quick_sort *Pivot);

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
		   "\n Para Organizar por Quick Pressione 3"
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
			organizar(inicio);
			break;
	}
}

void Novo_Bloco(quick_sort*inicio){
	int m,k;
	for(m=0;m<=50;m++){
		quick_sort *tmp;
		quick_sort *novo = (quick_sort *)malloc(sizeof(quick_sort));
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
void organizar(quick_sort *inicio){
	quick_sort *pivot, *tmp1, *tmp2, *q, *ref, *tmp3, *tmp4;
	pivot = inicio->prox;
	q = pivot->prox;
	while(q->prox != NULL){
		if(pivot->elemento > q->elemento){
			if(q->ant == pivot){
				q->prox->ant = pivot;
				pivot->prox = q->prox;
				inicio->prox = q;
				q->ant = inicio;
				q->prox = pivot;
				q = pivot->prox;
			}
			if(q->ant != pivot && q->prox !=NULL){
				tmp1 = q->ant;
				tmp2 = q->prox;
				inicio->prox->ant = q;
				q->prox = inicio->prox;
				q->ant = inicio;
				inicio->prox = q;
				tmp1->prox = tmp2;
				tmp2->ant = tmp1;
				q = pivot->prox;
			}
			if(q->prox == NULL){
				tmp1 = q->ant;
				tmp1->prox = NULL;
				inicio->prox->ant = q;
				q->prox = inicio->prox;
				q->ant = inicio;
				inicio->prox = q;
				q = pivot->prox;
			}
		}
		else{
			q = q->prox;
			if(pivot->elemento > q->elemento){
				if(q->prox == NULL){
					tmp1 = q->ant;
					tmp1->prox = NULL;
					inicio->prox->ant = q;
					q->prox = inicio->prox;
					q->ant = inicio;
					inicio->prox = q;
					q = pivot->prox;
				}		
			}	
		}
	}
organizar_left(inicio, pivot);
organizar_right(inicio,pivot);
return;	
}

void organizar_left(quick_sort *inicio, quick_sort *Pivot){
	quick_sort *ref, *tmp1;
		int i;
	int j = 3;
	for(i=0;i<=j;i++){
		ref = inicio->prox;
		tmp1 = ref->prox;
		while(tmp1->prox != Pivot){
			if(ref->elemento >= tmp1->elemento){
				tmp1->prox->ant = ref;
				ref->prox = tmp1->prox;
				ref->ant->prox = tmp1;
				tmp1->ant = ref->ant;
				tmp1->prox = ref;
				ref->ant = tmp1;
				ref = ref->prox;
				if(ref->prox != Pivot){
					tmp1 = ref->prox;
					j++;
					if(tmp1->prox == Pivot){
					if(ref->elemento >= tmp1->elemento){
						ref->ant->prox = tmp1;
						tmp1->ant = ref->ant;
						tmp1->prox = ref;
						ref->prox = Pivot;
						Pivot->ant = ref;
						ref->ant = tmp1;
						break;	
					}
				}	
				}
				else{
					break;
				}
			}
			if(ref->elemento <= tmp1->elemento){
				ref= ref->prox;
				j++;
				if(ref->prox == Pivot){
					break;
				}
				else{
					tmp1 = ref->prox;
					j++;
				}
			}
			
		}
	}
return;	
}
void organizar_right(quick_sort *inicio, quick_sort *Pivot){
	quick_sort *ref, *tmp1,*tmp3,*tmp4;
	int i;
	int j = 5;
	for(i=0;i<=j;i++){
		ref = Pivot->prox;
		tmp1 = ref->prox;
		while(tmp1->prox != NULL){
			if(ref->elemento >= tmp1->elemento){
				tmp1->prox->ant = ref;
				ref->prox = tmp1->prox;
				ref->ant->prox = tmp1;
				tmp1->ant = ref->ant;
				tmp1->prox = ref;
				ref->ant = tmp1;
				ref = ref->prox;
				if(tmp1->prox == NULL){
					if(ref->elemento >= tmp1->elemento){
						ref->ant = tmp1;
						tmp1->prox = ref;
						ref->prox = NULL;
						ref->ant = tmp1;
						break;	
					}
				}
				if(ref->prox != NULL){
					
					tmp1 = ref->prox;
					j++;
					if(tmp1->prox == NULL){
					if(ref->elemento >= tmp1->elemento){
						ref->ant->prox = tmp1;
						tmp1->ant = ref->ant;
						ref->ant = tmp1;
						tmp1->prox = ref;
						ref->prox = NULL;
						break;	
					}
				}
				}
				else{
					break;
				}
			}
			if(ref->elemento <= tmp1->elemento){
				ref= ref->prox;
				if(ref->prox == NULL){
					break;
				}
				else{
					tmp1 = ref->prox;
					j++;
				}
			}
			
		}
	}
return;	
	
}

