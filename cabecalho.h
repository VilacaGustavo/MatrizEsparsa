#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct celula{
	int linha;
	int coluna;
	int info;
	struct celula *proxLinha;
	struct celula *proxColuna;
}Celula;

//iniciar a lista
void iniciarLista(Celula **lista){   
	(*lista)= NULL;
	system("cls");
	printf("Cardapio iniciado com sucesso! \n");
	
}
//Verificar se esta vazia
int listaVazia(Celula **lista){
	if ((*lista)==NULL) {
		return 1;
	}
	
	return 0;
}
// criar celula
Celula *criarCelula (){
	Celula *nova = (Celula *) malloc (sizeof(Celula));
	return nova;
	system("cls");
	printf("celula criada\n");
}
// printa posição e valor
void printar(Celula **lista){
	printf("Coluna: %d Linha: %d Valor: %d\n", (*lista)->coluna, (*lista)->linha, (*lista)->info);
}
// inserir no lugar desejado
int inserirLugar(Celula **lista,int linha, int Coluna, int info) {
	Celula *novaCelula = criarCelula();
	Celula *auxiliar;
	int colAux, linAux, i=1, k;
	
	if(linha < 1 || Coluna < 1){
		printf("Possicao invalida as possicoes da matriz tem que ter numeros positivos\n");
		return 0;
	}
	
	if(listaVazia(lista)){
		novaCelula->coluna = 1;
		novaCelula->linha = 1;
		novaCelula->info = 0;
		novaCelula->proxColuna = novaCelula;
		novaCelula->proxLinha = novaCelula;
		(*lista) = novaCelula;
	}
	
	if(linha == 1 && Coluna == 1){
		(*lista)->info = info;
		return 1;
	}
	
	auxiliar = (*lista);
	while(i < Coluna){
		if(auxiliar->proxColuna->coluna <= auxiliar->coluna){
			novaCelula = criarCelula();
			if(novaCelula == NULL) {
				system("cls");
				printf("erro-memoria cheia.\n");
				return 0;
			}
			novaCelula->coluna = i+1;
			novaCelula->linha = 1;
			novaCelula->info = 0;
			novaCelula->proxLinha = novaCelula;
			novaCelula->proxColuna = auxiliar->proxColuna;
			auxiliar->proxColuna = novaCelula;
			auxiliar = novaCelula;
		}else{
			auxiliar = auxiliar->proxColuna;
		}
		i++;
	}
	i = 1;
	while(i < linha){
		if(auxiliar->proxLinha->linha <= auxiliar->linha){
			novaCelula = criarCelula();
			if(novaCelula == NULL) {
				system("cls");
				printf("erro-memoria cheia.\n");
				return 0;
			}
			novaCelula->coluna = Coluna;
			novaCelula->linha = i+1;
			novaCelula->info = 0;
			novaCelula->proxColuna = novaCelula;
			novaCelula->proxLinha = auxiliar->proxLinha;
			auxiliar->proxLinha = novaCelula;
			auxiliar = novaCelula;
		}else{
			auxiliar = auxiliar->proxLinha;
		}
		i++;
	}
	
	auxiliar->info = info;
	
	return 1;
}

// remover element desejado
int remover(Celula **lista, int linha, int coluna) {
	Celula *removida;
	Celula *aux;
	int i = 1;
	if (listaVazia(lista)){
		printf("erro - lista vazia\n");
		return 0;
	}

	if(linha < 1 || coluna < 1){
		printf("Possicao invalida as possicoes da matriz tem que ter numeros positivos");
		return 0;
	}
	
	removida = (*lista);
	
	while(i < coluna){
		if(removida->proxColuna == (*lista)){
			printf("Coluna invalida");
			return 0;
		}else{
			removida = removida->proxColuna;
		}
		i++;
	}
	aux = removida;
	i = 1;
	while(i < linha){
		if(removida->proxLinha == aux){
			printf("Linha invalida");
			return 0;
		}else{
			removida = removida->proxLinha;
		}
		i++;
	}
	
	removida->info = 0;
	printf("Posicao removida recebeu o valor 0\n");
	return 0;
}
// Recebe posicao e altera elemento
int alterarElemento(Celula **lista,int linha, int coluna, int info){
	Celula *altera;
	Celula *aux;
	int i =1;
	if (listaVazia(lista)){
		printf("erro - lista vazia\n");
		return 0;
	}

	if(linha < 0 || coluna < 0){
		printf("Possicao invalida as possicoes da matriz tem que ter numeros positivos");
		return 0;
	}
	
	altera = (*lista);
	
	while(i < coluna){
		if(altera->proxColuna == (*lista)){
			printf("Coluna invalida");
			return 0;
		}else{
			altera = altera->proxColuna;
		}
		i++;
	}
	aux = altera;
	i = 1;
	while(i < linha){
		if(altera->proxLinha == aux){
			printf("Linha invalida");
			return 0;
		}else{
			altera = altera->proxLinha;
		}
		i++;
	}
	
	altera->info = info;
	printf("Posicao alterada para: ");
	printar(&altera);
	return 1;
}
// Imprime toda a matriz
int listar(Celula **lista){
	Celula *coluna;
	Celula *linha;
	
	if (listaVazia(lista)){
		printf("erro - lista vazia\n");
		return 0;
	}
	
	coluna = (*lista);
	
	do{
		linha = coluna;
		do{
			printar(&linha);
			linha = linha->proxLinha;
		}while(linha->linha>1);
		coluna = coluna->proxColuna;
	}while(coluna->coluna > 1);
	
	return 1;
}
// Recebe a linha  soma ou multiplica
int alteraLinha(Celula **lista, int Linha, int op,int valor){
	Celula *coluna;
	Celula *linha;
	
	if (listaVazia(lista)){
		printf("erro - lista vazia\n");
		return 0;
	}
	
	coluna = (*lista);
	
	do{
		linha = coluna;
		do{
			if(linha->linha == Linha){
				if(op == 1){
					linha->info = linha->info+valor;
				}
				if(op== 2){
					linha->info = linha->info*valor;
				}
			}
			linha = linha->proxLinha;
		}while(linha->linha>1);
		coluna = coluna->proxColuna;
	}while(coluna->coluna > 1);
	
	return 1;
}

// recebe a coluna soma ou multiplica
int alteraColuna(Celula **lista, int Coluna, int op,int valor){
	Celula *coluna;
	Celula *linha;
	
	if (listaVazia(lista)){
		printf("erro - lista vazia\n");
		return 0;
	}
	
	coluna = (*lista);
	
	do{
		linha = coluna;
		do{
			if(linha->coluna == Coluna){
				if(op == 1){
					linha->info = linha->info+valor;
				}
				if(op== 2){
					linha->info = linha->info*valor;
				}
			}
			linha = linha->proxLinha;
		}while(linha->linha>1);
		coluna = coluna->proxColuna;
	}while(coluna->coluna > 1);
	
	return 1;
}
