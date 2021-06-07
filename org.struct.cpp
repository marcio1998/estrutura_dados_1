/*Algoritmo criado para organizar uma estrutura de dados chamado, fila duplamente encadeada em ordem crescente atrav�s do 
do algoritmo bubble Sort.*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct valores {
	int valor;
	struct valores *prox, *ant;// ponteiros que conectam as estruturas.
}; // struct criada para a estrutura de dados..

/* Fun��es*/
typedef struct valores ordenacao;// typedef struct me diz que os us�arios v�o enserir o valor, ordenacao ser� importante pois quando me referir a struct ser� como ordenacao.
int menu (void);// fun��o utilizada para cria��o de um menu com as op��es do que o software realiza. ela � do tipo int pois retornar� um valor.
void opcao (ordenacao *inicio, int op);/*Fun�ao do tipo void que n�o retorna nada, pois, so ativa o switch case e seleciona a op��o e a fun��o que aquela op��o usar� o paramentro 
ordenacao *inicio � muito importante toda fun��o que trabalha com estrutura de dados dinamicas o seu parametro deve ser sempre o primeiro elemento criado*/
void novoBloco(ordenacao *inicio);//cria uma nova caixa na estrutura de dados
void mostrar (ordenacao *inicio);// mostra todos os elementos na estrutura de dados
void bubbleSort (ordenacao *inicio);//ordena pelo modo bubble sort..
bool checar(ordenacao *inicio);// fun��o do tipo bool= boolena que retorna true ou false dado um comando
/*Vari�veis*/
int opt;


int main(void){
	ordenacao *inicio = (ordenacao *) malloc(sizeof(ordenacao));// comanda criado para iniciar minha estrutura de dados..
	if(!inicio){
		printf("Nao Ha Memoria");// linha utilizada para avisar caso n�o haja memoria no computador disponivel.
	}
	else{
		inicio ->prox = NULL;// toda estrutura criada nova sua variavel prox deve apontar para NULL, para n�o haver erros no seu programa ou ela aponta para lixo de memoria .
		inicio ->ant= NULL;// a variav�l ant tamb�m deve apontar para NULL.
	}
	do{
		opt = menu();// a variavel opt recebe o valor que a fun��o menu ir� retornar.
		opcao(inicio, opt);	/* a fun�ao opcao ira ativar o switch case, para isso foi necess�rio para os parametros, o int opt que foi a opcao 
		escolhida pelo usuario na opcao menu e a mais importante a inicio que � o principa para poder avaliar todos as demais estruturas de dados*/
		}while(opt);
}

int menu(void){
	printf("\n Para adcionar numeros digite 1. \n Para ver os numeros aperte 2. Para ordenar aperte 3.");
	printf ("\n Digite sua opcao:");
	scanf("%d", &opt);
	return opt;
}

void opcao (ordenacao *inicio, int op){ /* fun�ao que ativa o switch case e tambem chama as fun��es que ser�o utilizadas e passa como paramentro para as fun��s
a primeira estrutura criada*/
	switch(op){
		case 1:
			novoBloco(inicio);// chama a fun��o que criara novas estruturas.
			break;
			
	   case 2:
	   		mostrar(inicio);
	   		break;
	   		
	   	case 3:
	   		bubbleSort(inicio);
	   		break;
	}
	
}

void novoBloco(ordenacao *inicio){
int k=20;// variaveis para o for
int m = 0;// para controlar o for 
for(m;m<=k;m++){
	ordenacao *novo = (ordenacao *) malloc(sizeof(ordenacao));// cria uma nova estrutura de dados.
	if(!novo){
		printf("Nao Ha Meoria Disponivel");//alerta caso n�o haja memoria.
	}
	if(inicio->prox == NULL){/* caso a fila esteja vaizia este ser� o novo passo. apontar os ponteiros corretemente muito importante esta parte
	pois, se apontar um poneteiro errado seu programa ter� grande falhas de execu��o*/
		inicio->prox = novo;
		novo->ant = inicio;
		novo->prox = NULL;
	}
	else{/* Caso a fila n�o esteja vazia esta parte ir� apontar os ponteiros corretamente.*/
		novo->prox = inicio->prox;
		novo->ant = inicio;
		inicio->prox->ant = novo;
		inicio->prox = novo;
	}
	novo->valor = rand() % 3000;/* Os valores que ir�o dentro da estruct ser�o feitos aleatorimante como o comando rand e etr� seu resto de 0 a 499*/
}
return;	
}
	



void mostrar(ordenacao *inicio){
	if(inicio -> prox == NULL){
		printf("Lista Vazia");
		return;
	}
	ordenacao *tmp;
	tmp = inicio;
	while(tmp->prox != NULL){
		tmp = tmp->prox;
		printf("\n Numero: %d ", tmp->valor);
	}
	return;
}


void bubbleSort (ordenacao *inicio){	
int i;
int j = 1;
float tempo;
time_t t_ini, t_fim; // time de variaveis que medem o tempo por segundos.
t_ini = time(NULL);
if (inicio -> prox == NULL){
	printf("Lista vAzia");
	return;
}
ordenacao *tmp1, *tmp2, *tmp3;// variaveis criadas para os ponnteiros poderem serem apontados corretamentes ap�s a ordena��o.
ordenacao *ref;// o ponteiro que ser� analisado com os outros..
for(i=0;i<=j;i++){/* For utlizado para podermos organizar todos os numeros cada vez feito o processo 1 vez o j se auto encrementa*/
	printf("Ordenando...");
	tmp1 = inicio;// variavel que come�ara no inicio para podermos comparar
	ref = tmp1 -> prox;// variavel de compara��o.
	tmp2 = ref->prox;//sempre teremos uma variavel a frente da ref para compararmos.
	tmp3 = tmp2->prox;// sempre tem-se um variavel a frente da tmp2 para modificarmos os ponteiros corretamente.
	while(tmp1 == inicio){/*Enquanto tmp permanecer em inico teremos uma organiza��o diferente de ponteiros..*/
		if(ref->valor >= tmp2->valor){
			ref->prox = tmp2->prox;
			tmp3->ant = ref;
			tmp1->prox = tmp2;
			tmp2->ant = tmp1;
			tmp2->prox = ref;
			ref->ant = tmp2;
			ref = tmp2->prox;
			tmp1 = ref->ant;
			tmp2 = ref->prox;		
			if(tmp2->prox == NULL){/* Esta linha checa se tmp2 aponta para NULL, pois, se apontar o tmp3 deixa de existir pois estamos no final da fila*/
				tmp3->prox = NULL;
				tmp3->ant = NULL;
			}
			else{
			   tmp3 = tmp2->prox;
			}
		}	
		if(ref->valor <= tmp2->valor){/*Caso a referencia seja menor que o valor o valor em sua frente*/
			ref = ref->prox;// o numero de refrencia ser� o que esta em sua frente..
			tmp1= tmp1->prox;
			tmp2 = ref->prox;
			if(ref->prox == NULL){
				break;// se ref � um numero maior e ja aponta para null deve-se recome�ao o algoritmo
			}
			if(tmp2->prox == NULL){
				tmp3->prox = NULL;
				tmp3->ant = NULL;
			}
			else{
				tmp3 = tmp2->prox;
			}
		}
	}

	while(ref->prox != NULL){
		if(ref->valor >= tmp2->valor){
			if(tmp2->prox == NULL){// antes de trocar com tmp2 2 devo ver se ela aponta para null.
				tmp1->prox = tmp2;
				tmp2->ant = tmp1;
				tmp2->prox = ref;
				ref->ant = tmp2;
				ref->prox = NULL;
			}
			else{
				ref->prox = tmp2->prox;
				tmp3->ant = ref;
				tmp1->prox = tmp2;
				tmp2->ant = tmp1;
				tmp2->prox = ref;
				ref->ant = tmp2;
			}
			if(ref->prox == NULL)// se referencia ja aponta para NULL deve encerrar aqui.
				break;
			else{
				ref = tmp2->prox;
				tmp1 = ref->ant;
				tmp2 = ref->prox;
				if(tmp2->prox == NULL){// checar se tmp 2 nao aponta para NULL
					tmp3 = NULL;
					tmp3 = NULL;
				}
				else{
					tmp3 = tmp2->prox;
				}		
			}
		}
		if(ref->valor <= tmp2->valor){
			ref = ref->prox;
			tmp1=tmp1->prox;
			tmp2 = ref->prox;
			if(ref->prox == NULL){/*sempre checar se referencia aponta para null*/
				break;
			}
			if(tmp2->prox == NULL){// checar se tmp2 aponta pra nulo..
				tmp3 = NULL;
				tmp3 = NULL;
			}
			else{
				tmp3 = tmp2->prox;
			}		
		}
	}
	checar(inicio);// chama esta fun��o para checar se esta organizado a estrutura pois se estiver ela quebra o loop de repeti��o do for
	if(checar(inicio) == true){
		break;
	}
	j++;
}
system("cls");
t_fim = time(NULL);
tempo = t_fim-t_ini;// variaveis criadas para vereficiar o tempo de execu��o.
if(tempo >60){
	tempo = tempo/60;
}
printf("\n\n\n \t\t\t Tempo de execucao: %.2f", tempo); 
return;
}
bool checar(ordenacao *inicio){/*fun��o do tipo booleana para retornar se esta verdadeiro ou falso o que mando ela checar*/
	ordenacao *tmp5, *tmp6;
	tmp5 = inicio->prox;
	tmp6 = tmp5->prox;
	while(tmp5->prox != NULL){
		if(tmp5->valor <= tmp6->valor){
			tmp5 = tmp6;
			tmp6 = tmp6->prox;
			if(tmp6->prox == NULL){
				return true;
				break;
			}
		}
		if(tmp5->valor >tmp6->valor){
			return false;
			break;
		}
    }
}
	


