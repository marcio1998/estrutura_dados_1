#include<stdio.h>
#include<stdlib.h>

typedef struct cadastro{
	int codigo; //variavel para receber um valor do tipo int.
	char NomeAluno[50];
	float NotaParcial,NotaExame,media;
	struct cadastro *esquerda, *direita;// ponteiros da arvores, os ponteiros da esquerda e da direita
};

//criando as fun��es.
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	                                     /*
	                                     	nesta fun��o sera usado as fun��es malloc e sizeof para aloca��o dinamica da memoria pra um novo no da arvore.
	                                     	1� fazer um if para verificar se o novo no foi criado.
	                                     	2� fazer os printf e scanf para atribuir valores nas variaveis contidas na struct cadastro.
	                                     	3� difinir os ponteiras direita e esquerda como NULL
	                                     	4� retornanr o novoNo para que o programa continue tendo execu��o.
										 */
										 
struct cadastro *novoNo(int cod){//fun��o que aloca um novo n� na memoria.
printf("teste 4");
	struct cadastro *novo = (cadastro *)malloc(sizeof(cadastro));//linha de codigo que aloca a memoria do tamanho da struct.
	if(!novo){// if, caso a nova "caixa" n�o seja criada.
		printf("Memoria Cheia");
	}
	else{//caso a nova "caixa", seja criado, ou o novo n� da raiz.
	
		// popular a struct..
		printf("\t\t\t Digite O nome do aluno: ");
		scanf(" %s",novo->NomeAluno);// adicionando o nome do aluno.
		printf("\t\t\t Digite A nota Parcial do aluno: ");
		scanf(" %f", & novo->NotaParcial);//adicionando a nota parcial do aluno
		printf("\t\t\t Digite A nota Exame do aluno: ");
		scanf(" %f", & novo->NotaExame);//adicionando a nota exame do aluno
		novo->media = ((novo->NotaParcial *0.4 )+ (novo->NotaExame * 0.6));//calculo da media do aluno.
		novo->codigo = cod;
		system("cls");
		
		//estabelecendo valores para os pondeitos esquerda e direita.
		novo -> esquerda = novo -> direita = NULL;// estabelecendo NULL para os ponteiros esquerda e direita do novo no ou "caixa".
		return novo;	// retornanar o n� criado.
		printf("teste 3");
	}
} 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

										/* Todo a fun��o de imprimir segue um padr�o com a recursividade OBS: sempre passar raiz com parametro.
										   1� um if para sabr se a arvore � diferente de NULL
										   2� chama a fun��o co recursividade sendo agora como parametro raiz-> esquerda.
										   3� ter um printf das variaveis que esta dentro da struct.
										   4� chama a fun��o com recursividade agora como parametro  raiz -> direita.. 
										   OBS: s� ira imprimir em ordem se na fun��o abaixo inserir for inserido em ordem.
	                                   */
			

void imprimirEmOrdem(struct cadastro *raiz){// fun��o para imprimir em ordem os valores que est�o na �rvore.
	if(raiz != NULL){// caso, raiz seja diferente de NULL o codigo executa.
			imprimirEmOrdem(raiz->esquerda);// chamada recursiva a esquerda da arvore.
			printf("\n\t Nome Do Alunoo: %s", raiz->NomeAluno);
			printf("\n\t Codigo do Aluno: %d", raiz->codigo);
			printf("\n\t Nota Parcial: %.2f", raiz->NotaParcial);
			printf("\n\t Nota Exame: %.2f", raiz->NotaExame);
			printf("\n\t Media: %.2f \n", raiz->media);
			imprimirEmOrdem(raiz->direita);	// chamada recursiva a direita da arovore.
	}
	
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                                        /* toda a fun��o de inserir tambem segue um padr�o quando se usa a recursividade. Passar com parametro raiz e um valor a ser analisado
										   1� deve-se primeiro verizicar se raiz � igual a null , pois, se for ja alocaremos o primeiro no como sendo raiz, quando raiz for null
										   faz uma chamada  da fun��o novoNo escrita acima, onde � alocada memoria com as fun��es malloc e sizeof e ir� atribuir valores as variaveis
										   da struct.
										   2� caso raiz seja diferrente de null ent�o vai come�ar as chamadas recursivas.
										   3� ver se o valor do parametro passado � menor que o valor para qual no aponta e ent�o fazer uma chamada recursiva de no->esquerda
										    chama a recursividade da fun��o inserir como parametro no->esquerda e o valor a ser analisado novamente. 
										   4� ver se o valor do parametro passado � maior que o valor para qual no aponta e ent�o fazer uma chamada recursiva de no->direita
										    chama a recursividade da fun��o inserir como parametro no->direita e o valor a ser analisado novamente. 
										*/

struct cadastro* inserir(struct cadastro* no, int cod){//fun��o criada para inserir o novo no na arvore em ordem]
	if(no == NULL) return novoNo(cod);// se o no ver que esta vazio e aloca o n�
	if(cod <= no->codigo)//avalia se o valor do codigo de temp � menor do que o no para saber se vai para a subarvores esquerda ou direita
	no->esquerda = inserir(no->esquerda,cod);// cahamada recursiva
	if(cod >= no->codigo);// avalia se o valor do codigo de tempo � maior que o no para saber se vai para a subarvore direita ou esquerda
	no->direita = inserir(no->direita,cod);// chamada recursiva.
	return no;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
                                        /*
                                        	Em termos de pesquisa dentro de um arvore tambem se segue alguns padr�es. no paramaetro da fun��o passa-se um ponteiro raiz e
                                        	o numero que se deseja pesquisar.
                                        	1� faz uma analise se raiz for igual a null ou raiz->codigo for igual ao numero deigitado ent�o faz-se os printf dos dados da struct
                                        	que se deseja.
                                        	2� usa-se duas recursividae a primeira caso raiz->codigo for menor que que o umero  ent�o a recursividade sera na subarvore direita
                                        	caso nao seja ent�o a recursividade sera na subarvore da esquerda ou seja raiz->esquerda.
										 */
                                        

struct cadastro* pesquisa(struct cadastro *raiz, int num) 
{ 
    // hora que o numero for achado. 
    if (raiz == NULL || raiz->codigo == num) {
    		printf("\n\t Nome Do Alunoo: %s", raiz->NomeAluno);
			printf("\n\t Codigo do Aluno: %d", raiz->codigo);
			printf("\n\t Nota Parcial: %.2f", raiz->NotaParcial);
			printf("\n\t Nota Exame: %.2f", raiz->NotaExame);
			printf("\n\t Media: %.2f \n", raiz->media);
			return raiz;
			
			printf("teste 4");	
	} 
     
    // caso o numero da raiz seja menor que o codigo pesquisado, o elemento esta na subarvore direita. 
    if (raiz->codigo < num) 
      return pesquisa(raiz->direita, num); 
  
    // caso o numero da raiz seja maior que o codigo pesquisado, o elemento esta na subarvore esquerda.
     return pesquisa(raiz->esquerda, num); 
} 

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

															/*
																Esta fun��o � criada para achar qual o menor valor dentro da arvore. ela sera utilizada quando tivermos
																que deletar um no e esse possuir dois filhos.
															*/
struct cadastro * valorMinimo(struct cadastro* temp) 
{ 
    struct cadastro* atual = temp; 
  
    // loop para achar o menor numero.
    while (atual->esquerda != NULL) 
        atual = atual->esquerda; 
  
    return atual; 
} 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

														/*
															Para deletar um no temos tres op��es, caso seja uma folha o numero que sera deletado basta deletar a folha.
															caso tenha um filho, copie a crian�a e delete o no.
															caso tenha dois filhos, ache o sucessor do no, copie os sucessores e delete o no.
															como parametro da fun��o tem-se o raiz e o numero de pesquisa para deletar o no.
														*/
struct cadastro* deletarNo(struct cadastro* raiz, int num) 
{ 
    // caso base.
    if (raiz == NULL) return raiz; 
  
    // caso o numero seja menor que a raiz, buscaremos na subarvore esquerda
    if (num < raiz->codigo) 
        raiz->esquerda = deletarNo(raiz->esquerda, num); // chamada recursiva a esquerda de raiz.
  
    // caso o numero seja maior que raiz, buscaremos na subarvore direita.
    else if (num > raiz->codigo) 
        raiz->direita = deletarNo(raiz->direita, num); // chamada recursiva a direita da raiz;
  
    else
    { 
        // no com um filho ou sem filhos
        if (raiz->esquerda == NULL) 
        { 
            struct cadastro *temp = raiz->direita; 
            free(raiz); 
            return temp; 
        } 
        else if (raiz->direita == NULL) 
        { 
            struct cadastro *temp = raiz->esquerda; 
            free(raiz); 
            return temp; 
        } 
  
        // no com duas crianc�as pegue o menor a direita. 
        struct cadastro* temp = valorMinimo(raiz->direita); 
  
        // copie o conteudo do sucessor para o no
        raiz->codigo = temp->codigo; 
  
        // delete o sucessor.
        raiz->direita = deletarNo(raiz->direita, temp->codigo); 
    } 
    return raiz; 
} 

int opt; // variavel criada para um menu.
int codigo;

int main (void){
	struct cadastro *raiz = NULL;
	do{
		printf(" \t\t\t Para Cadastrar um Aluno digite 1."
		   "\n \t\t\t Para Ver os Alunos cadastrador digite 2."
		   "\n \t\t\t Para pesquisa um Aluno  digite 3."
		   "\n \t\t\t Para Excluir Um aluno digite 4."
		   "\n \t\t\t Digite sua Opcao: ");
		scanf("%d", & opt);
		switch(opt){
				case 1:
					if(raiz !=  NULL){
						printf("teste 1");
						printf("\n \t\t\t Digite Codigo do Aluno: ");
						scanf(" %d", & codigo);
						inserir(raiz,codigo);
						break;
					}
					if(raiz == NULL){
						printf("teste 2");
						printf("\n \t\t\t Digite Codigo do Aluno: ");
						scanf(" %d", & codigo);
						raiz = inserir(raiz,codigo);
						break;
					}
				case 2:
					imprimirEmOrdem(raiz); 
					break;	
				
				case 3:
					printf("Digite o Codigo do Aluno que se deseja Pesquisar: ");
					scanf(" %d", & codigo);
					pesquisa(raiz,codigo);	
					break;
					
				case 4:
					printf("Digite o Codigo do Aluno que se deseja Deletar: ");
					scanf(" %d", & codigo);
					deletarNo(raiz,codigo);
					break;
					
		}
	}while(opt);
}
