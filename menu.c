#include "cabecalho.h"

void menu() {
	
	Celula *lista;
	int op=1;
	int pos, coluna, linha, info,escolher;
	int ret, opera;
	iniciarLista(&lista);
	system("cls");
	while (escolher != 0) {
	system("cls");
	printf ("\n\tM E N U\n");
	printf("\n               Escolha uma opcao:\n\n");
	printf("\t1- Inserir na matriz\n");
	printf("\t2- Remover na matriz\n");
	printf("\t3- Alterar elemento na matriz\n");
	printf("\t4- Listar matriz\n");
	printf("\t5- Somar em todos os elementos de uma Linha ou Coluna por um valor:\n");
	printf("\t6- Multiplicar em todos os elementos de uma Linha ou Coluna por um valor:\n");
	printf("\t0- SAIR DO PROGRAMA EXIT ->\n");
	scanf("%d",&escolher);
	
	switch (escolher) {
		case 1:{
			system("cls");
			printf("Digite o numero da coluna:\n");
			scanf("%d",&coluna);
			printf("Digite o numero da linha:\n");
			scanf("%d",&linha);
			printf("Digite o valor:\n");
			scanf("%d",&info);
			system("cls");
			
			ret = inserirLugar(&lista,linha,coluna,info);
			system("pause");
			break;
		}
		case 2:{
			system("cls");
			printf("Digite o numero da coluna:\n");
			scanf("%d",&coluna);
			printf("Digite o numero da linha:\n");
			scanf("%d",&linha);
			system("cls");
			
			ret = remover(&lista,linha,coluna);
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			printf("Digite o numero da coluna:\n");
			scanf("%d",&coluna);
			printf("Digite o numero da linha:\n");
			scanf("%d",&linha);
			printf("Digite o valor:\n");
			scanf("%d",&info);
			system("cls");
			
			ret = alterarElemento(&lista,linha,coluna,info);
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			ret = listar(&lista);
			system("pause");
			break;
			
		}
		case 5: {
			system("cls");
			printf("Deseja alterar coluna ou linha:\n");
			printf("Linha 1:\tColuna: 2\n");
			scanf("%d",&opera);
			if(opera == 1){
				printf("Digite a Linha:\n");
				scanf("%d",&linha);
				printf("Digite o valor:\n");
				scanf("%d",&info);
				system("cls");
				ret = alteraLinha(&lista,linha,1,info);
			}else{
				if(opera == 2){
					printf("Digite a Coluna:\n");
					scanf("%d",&linha);
					printf("Digite o valor:\n");
					scanf("%d",&info);
					system("cls");
					ret = alteraColuna(&lista,linha,1,info);	
				}else{
					printf("Opcao Invalida \n");
				}
			}
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			system("cls");
			printf("Deseja alterar coluna ou linha:\n");
			printf("Linha 1:\tColuna: 2\n");
			scanf("%d",&opera);
			if(opera == 1){
				printf("Digite a Linha:\n");
				scanf("%d",&linha);
				printf("Digite o valor:\n");
				scanf("%d",&info);
				system("cls");
				ret = alteraLinha(&lista,linha,2,info);
			}else{
				if(opera == 2){
					printf("Digite a Coluna:\n");
					scanf("%d",&linha);
					printf("Digite o valor:\n");
					scanf("%d",&info);
					system("cls");
					ret = alteraColuna(&lista,linha,2,info);	
				}else{
					printf("Opcao Invalida \n");
				}
			}
			system("pause");
			system("cls");
			break;
		}
		case 0:{
			system("cls");
			printf("Sair");
			break;
		}
		default: {
			system("cls");
			printf("Apenas numeros que estao no MENU\n\n Tente Novamente\n");
			break;
		}
	}
}
}

int main () {
	
	menu();
	
	return 0;
}
