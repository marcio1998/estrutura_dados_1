#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>

struct Insertion_Sort{
	int numero;
	struct Insertion_Sort *prox, *ant;
};

typedef struct Insertion_Sort ordenacao;
time_t t_inicial,t_final;
float tempo;
int menu(void);
int opt;
void opcao(ordenacao *inicio, int opt);
void Novo_Bloco(ordenacao *inicio);
void mostar(ordenacao*inicio);
void insertion_sort(ordenacao *inicio);
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
		   "\n \t Para Organizar com Insertion Sort Pressione: 3"
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
			insertion_sort(inicio);
			break;
			
			
	}
}

void Novo_Bloco(ordenacao *inicio){
	int m,k=100;
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
   // printf("\n Digite Um Numero: ");
	//scanf("%d", &novo->numero);
	//printf("Numero Cadastrado com Sucesso");
	//Sleep(500);
	system("cls");
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

void insertion_sort(ordenacao *inicio){
	t_inicial = time(NULL);
	int i,j=1;
	ordenacao *key,*tmp1,*tmp2,*tmp3,*tmp4;
	for(i=0;i<j;i++){
	tmp1 = inicio;
	tmp2 = tmp1->prox;
	key = tmp2->prox;
	tmp3 = key->prox;
		printf("0,0,0");
		while(tmp1==inicio){
			printf("0,0");
			if(tmp2->numero >= key->numero){
				printf("\n1,0");
				printf("\n KEY: %d", key->numero);
				tmp1->prox = key;
				key->ant=tmp1;
				key->prox = tmp2;
				tmp2->prox = tmp3;
				tmp2->ant = key;
				tmp3->ant=tmp2;
				tmp1=tmp1->prox;
				tmp2= tmp1->prox;
				key=tmp2->prox;
				printf("\n KEY: %d", key->numero);
				if(key->prox==NULL){
					tmp3 = NULL;
					printf("\n1,1");	
				}
				else{
					tmp3= key->prox;
					printf("\n1,2");	
				}
			}
			if(tmp2->numero <= key->numero){
				printf("\n1,3");
				tmp1=tmp1->prox;
				tmp2=tmp1->prox;
				key = tmp2->prox;
				printf("\n KEY: %d", key->numero);
				if(key->prox == NULL){
					break;
					printf("\n1,4");	
				}
				else{
					tmp3 = key->prox;
					printf("\n1,5");	
				}
			}
		}
		while(key!= NULL){
			printf("\n2,0");
			printf("\n KEY: %d",key->numero);
			if(tmp2->numero >= key->numero){
				if(key->prox==NULL){
					tmp1->prox = key;
					key->ant = tmp1;
					key->prox = tmp2;
					tmp2->ant = key;
					tmp2->prox = NULL;
					printf("\n2,1");
				}
				else{
					tmp1->prox = key;
					key->ant = tmp1;
					key->prox = tmp2;
					tmp2->ant = key;
					tmp2->prox = tmp3;
					tmp3->ant=tmp2;
					printf("\n2,2");
				}
				printf("\n2,2,1");
				tmp1=tmp1->prox;
				tmp2 = tmp1->prox;
				key = tmp2->prox;
				printf("\n KEY: %d", key->numero);
				if(key->prox == NULL){
					if(tmp2->numero >= key->numero){
					tmp1->prox = key;
					key->ant = tmp1;
					key->prox = tmp2;
					tmp2->ant = key;
					tmp2->prox = NULL;
					break;
					printf("\n2,1");
					}
					else{
						printf("\n2,3");
						break;
					}
				}
				
					tmp3 = key->prox;
					printf("\n2,4");
				

			}
			if(tmp2->numero <= key->numero){
				tmp1= tmp1->prox;
				tmp2 = tmp1->prox;
				key = tmp2->prox;
				printf("\n KEY: %d", key->numero);
				printf("\n2,5");
				if(key->prox == NULL){
					break;
					printf("\n2,6");
			}
				else{
					tmp3=key->prox;
					printf("\n2,7");
				}
					
			}
		}
		checar(inicio);
		printf("\n3,0");
		if(checar(inicio)==true){
		printf("\n3,1");
			break;	
		}
printf("\n3,2");
tmp4=inicio->prox;
while(tmp4!=NULL){
	printf("\t\t\t\t \n Num: %d \n", tmp4->numero);
	tmp4=tmp4->prox;
}
j++;
printf("3,3");
}
	t_final = time(NULL);
	tempo = t_final - t_inicial;
	printf("\n \t\t Tempo de execução: %f", tempo);
	return;
}

bool checar(ordenacao *inicio){
	printf("\n4,0");
	ordenacao *tmp1,*tmp2;
	tmp1 = inicio->prox;
	tmp2 = tmp1->prox;
	while(tmp2 != NULL){
		printf("\n4,1");
		if(tmp1->numero <= tmp2->numero){
			printf("\n4,1,1");
			tmp1 = tmp2;
			tmp2= tmp2->prox;
			printf("\n4,1,2");
			if(tmp2->prox == NULL){
				printf("\n4,2");
				return true;
				break;	
			} 
		}
		if(tmp1->numero > tmp2->numero){
			printf("\n4,3");
			return false;
			break;
		}
	}
}

