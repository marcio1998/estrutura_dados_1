#include<stdio.h>
#include<stdlib.h>

typedef struct Selection_Sort{
	int elemento;
	struct Selection_Sort *prox, *ant;
}selection_sort;
int opt;
int num[6] = {45,52,19,17,73,34};
int v =0;
bool verificar;
int menu(void);
void opcao(int Opt, selection_sort *inicio);
void Novo_Bloco(selection_sort *inicio);
void Mostrar_Lista(selection_sort *inicio);
void organizar(selection_sort *inicio);
bool checar(selection_sort *inicio);

int main(void){
	selection_sort *inicio = (selection_sort *)malloc(sizeof(selection_sort));
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

void opcao(int Opt, selection_sort * inicio){
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
void Novo_Bloco(selection_sort*inicio){
	int m,k;
for(m=0;m<=30;m++){
	selection_sort *tmp;
	selection_sort *novo = (selection_sort *)malloc(sizeof(selection_sort));
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

void Mostrar_Lista(selection_sort *inicio){
	selection_sort *tmp;
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
void organizar(selection_sort *inicio){
	selection_sort *p, *q, *menor, *tmp1, *tmp2, *tmp3, *tmp4,*tmp5,*tmp6;
	int i;
	int j =1;
	p = inicio->prox;
	for(i =0; i<=j; i++){
		printf("\n FOR");
		q = p->prox;
		menor=p;
		printf("\nQ: %d", q->elemento);
		printf("\nP: %d", p->elemento);
		printf("\ni: %d", i);
		printf("\nj: %d", j);
		Mostrar_Lista(inicio);
		while(menor->prox != NULL){
			if(q->elemento >= menor->elemento){
				q = q->prox;
				if(q->prox == NULL){
					p = p->prox;
					j++;
					break;
				}
				printf("\n q > menor");
				printf("\nQ: %d", q->elemento);
				printf("\nP: %d", p->elemento);
			}
			if(q->elemento < menor->elemento){
				printf("\n q < menor");
				menor = q;
				if(p->prox == menor){
					tmp1 = p->ant;
					if(menor->prox == NULL){
						tmp1->prox = menor;
						menor->ant = tmp1;
						menor->prox = p;
						p->ant = menor;
						p->prox = NULL;
						p = inicio->prox;
						j++;
						printf("\n p = menor");
						break;
					}
					else{
						tmp2 = menor->prox;
						tmp1->prox = menor;
						menor->ant = tmp1;
						menor->prox = p;
						p->ant = menor;
						p->prox = tmp2;
						tmp2->ant = p;
						p = inicio->prox;
						j++;
						printf("\n P: %d", p->elemento);
						printf("\n q: %d", q->elemento);
						printf("\n p != menor");
						break;
					}
				}
				if(menor->prox == NULL){
					tmp1 = p->ant;
					tmp2 = p->prox;
					if(menor->ant != tmp2){
						tmp3 = menor->ant;
						tmp1->prox = menor;
						menor->ant = tmp1;
						menor->prox = tmp2;
						tmp2->ant = menor;
						tmp3->prox = p;
						p->ant = tmp3;
						p->prox = NULL;
						p = inicio->prox;
						menor = p;
						j++;
						printf("\n menor = NULL");
						break;
					}
					if(menor->ant == tmp2){
						tmp1->prox = menor;
						menor->ant = tmp1;
						menor->prox = tmp2;
						tmp2->ant = menor;
						tmp2->prox = p;
						p->ant = tmp2;
						p->prox = NULL;
						p = inicio->prox;
						j++;
						printf("\n menor = tmp2");
						break;
					}
				}
				tmp1 = p->ant;
				tmp2 = p->prox;
				if(menor->ant == tmp2){
					tmp3 = menor->prox;
					tmp1->prox = menor;
					menor->ant = tmp1;
					menor->prox = tmp2;
					tmp2->ant = menor;
					tmp2->prox = p;
					p->ant=tmp2;
					p->prox = tmp3;
					tmp3->ant = p;
					p = inicio->prox;
					j++;
					printf("\n ant ==tmp2");
					break;
				}
				tmp3 = menor->ant;
				tmp4 = menor->prox;
				tmp1->prox = menor;
				menor->ant = tmp1;
				menor->prox = tmp2;
				tmp2->ant = menor;
				tmp3->prox = p;
				p->ant = tmp3;
				p->prox = tmp4;
				tmp4->ant = p;
				p = inicio->prox;
				printf("\n else");
				Mostrar_Lista(inicio);
				j++;
				break;
			}
			if(q->elemento == menor->elemento){
				j++;
			}
			
		}
		/*verificar = checar(inicio);
		if(verificar == true){
			break;
			printf("\n checar true");
			printf("\n i: %d", i);
		}*/

}
return;
}
	

bool checar(selection_sort *inicio){
	selection_sort *tmp1, *tmp2;
	tmp1 = inicio->prox;
	tmp2 = tmp1->prox;
	while(tmp1->prox !=NULL){
		if(tmp1->elemento <= tmp2->elemento){
			tmp1= tmp2;
			tmp2 = tmp2->prox;
		}
		if(tmp1->elemento >= tmp2->elemento){
			return false;
			break;
		}
	}
	return true;
}

