#include <stdio.h>
#include <stdlib.h>

struct Selection_Sort{
	int numero;
	struct Insertion_Sort *prox, *ant;
};

typedef struct Selection_Sort ordenacao;
int menu(void);
int opt;
void opcao(ordenacao *inicio, int opt);
void Novo_Bloco(ordenacao *inicio);
void mostar(ordenacao*inicio);
void selection_sort(ordenacao *inicio);
bool checar(ordenacao *inicio);

int main(void){
	ordenacao *inicio = (ordenacao *)malloc(sizeof(ordenacao));
	if(!inicio){
		printf("Não Ha Memoria");
	}
	else{
		inicio->prox = NULL;
		inicio->ant = NULL;
	}
	do{
		opt=menu();
		opcao(inicio,opt);
	}while(opt);
}
int menu(void){
	printf("\n \t Para adicionar Numeros Pressione: 1"
		   "\n \t Para Ver os Numeros Pressione: 2"
		   "\n \t Para Organizar com Slection Sort Pressione: 3"
		   "\n \t Digite Sua Opcao: ");
	scanf("%d", &opt);
	return opt;
}

void opcao(ordenacao *inicio, int opt){
	switch(opt){
		case 1:
			Novo_Bloco(inicio);
			break;
		case 2:
			 mostar(inicio);
			 break;
		case 3:
			selection_sort(inicio);
			break;
			
			
	}
}

void Novo_Bloco(ordenacao *inicio){
	int m,k=10;
for(m=0;m<k;m++){
	ordenacao *novo = (ordenacao *)malloc(sizeof(ordenacao));
	if(!novo){
		printf("Nao Ha Memoria");
	}
	if(inicio->prox == NULL){
		inicio->prox = novo;
		novo->ant = inicio;
		novo->prox = NULL;
	}
	else{
		novo->prox = inicio->prox;
		novo->ant = inicio;
		inicio->prox->ant = novo;
		inicio->prox = novo;	
	}
	system("cls");
	novo->numero = rand()%600;
}
	return;
}


void mostar(ordenacao*inicio){
	ordenacao *tmp1;
	if(inicio->prox == NULL){
		printf("Fila Vazia");
	}
	tmp1 = inicio->prox;
	while(tmp1 != NULL){
		printf("\n \t\t Numer: %d", tmp1->numero);
		tmp1= tmp1->prox;
	}
	return;
		
}

void slection_sort(ordenacao *inicio){
	ordenacao *tmp0,*tmp1,*tmp2,*tmp3,*ref,*menor;
	int i,j;
	for(i=0;i<=j;i++){
		tmp1= inicio;
		ref= tmp1->prox;
		menor = ref->prox;
		tmp0=tmp2;
		tmp2=menor->prox;
		tmp3=tmp2->prox;
		while(tmp1==inicio){
			if(menor->numero <= tmp0->numero{
				tmp0 = tmp0->prox;
			if(menor->numero >= tmp0->numero){
					if(tmp0->prox == NULL){
						if(ref->numero<=tmp0->numero){
							ref=menor;
							tmp1=tmp1->prox;
							menor=ref->prox;
							tmp2=menor->prox;
							tmp0=tmp2;
							if(tmp2->prox == NULL){
								tmp3=NULL
								break;
							}
							else{
								tmp3=tmp2->prox;
								break;
							}
						}
						if(ref->numero>=tmp0->numero){
							tmp3->prox = ref;
							ref->ant = tmp3;
							tmp1->prox = tmp0;
							tmp0->ant = tmp1;
							tmp0->prox menor;
							ref=menor;
							tmp1=tmp1->prox;
							menor=ref->prox;
							tmp2=menor->prox;
							tmp0=tmp2;
							if(tmp2->prox == NULL){
								tmp3=NULL
								break;
							}
							else{
								tmp3=tmp2->prox;
								break;
							}	
						}			

					}
					if(tmp0->prox!=NULL){
						if(ref->numero<=menor){
							ref=menor;
							tmp1=tmp1->prox;
							menor=ref->prox;
							tmp2=menor->prox;
							tmp0=tmp2;
							if(tmp2->prox == NULL){
								tmp3=NULL
								break;
							}
							else{
								tmp3=tmp2->prox;
								break;
							}
						
						}
						if(ref->numero >= tmp0->numero){
							tmp2->prox = ref;
							ref->ant = tmp2;
							ref->prox = tmp3->prox;
							tmp1->prox = tmp0;
							tmp0->ant = tmp1;
							tmp0->prox = menor
							ref=menor;
							tmp1=tmp1->prox;
							menor=ref->prox;
							tmp2=menor->prox;
							tmp0=tmp2;
							if(tmp2->prox == NULL){
								tmp3=NULL
								break;
							}
							else{
								tmp3=tmp2->prox;
								break;
							}
						}
					}
				}
			}					
		}
	}
}
