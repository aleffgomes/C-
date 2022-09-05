#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 200

void design1();
void design2();
void design3();
void header();
int menuOpcoes();
void nExiste();
int cadastrar();

struct projeto {
	int codigo;
	char titulo[50];
	char descricao[100];
	int ano;
	char status[20];
	char responsavel[50];
	int prazo;
	char setor[30];
	char empresa[30];
};

int contDesing, opcao, consultnovamente, qtdProjetos;
struct projeto ficha[MAX];

void design1() {	
	contDesing = 0;
	printf("\n");
	while (contDesing < 60) {
		printf("~");
		contDesing++;
	}
	printf("\n");
}
void design2() {	
	contDesing = 0;
	while (contDesing < 60) {
		printf("-");
		contDesing++;
	}
}
void design3() {	
	contDesing = 0;
	while (contDesing < 60) {
		printf("=");
		contDesing++;
	}
}
void header() {
	design1();
	printf("MAPA ALP II --- CADASTRO DE PROJETOS\n");
	design2();
	printf("\nR.A.: 21062218-5  ||  Alef Wenderson Melgaço Gomes");
	design1();
}
int menuOpcoes() {
	system("cls");
	header();
	printf("\nSelecione uma opção: ");
	printf("\n1 - Cadastrar projeto");
	printf("\n2 - Visualizar projeto");
	printf("\n3 - Visualizar todos os projetos");
	printf("\n4 - Finalizar sistema");
	printf("\n");
	scanf ("%d", &opcao);	
	return(opcao);
}
void nExiste() {
	system("cls");
	header();
	printf("\n");
	design3();
	printf("\nERRO: Você selecionou uma opção que não existe!\n");
	design3();	
	printf("\n");
}
int cadastrar(inicio) {	
int i,qtd,codigo,cadNov;
qtd = inicio + 1;
if (inicio < 10) {
	for (i=inicio; (i<qtd && i<10); i++) {
		system("cls");
		header();
		codigo = i+1;
		printf("\nO código do produto é: %d", codigo);
		ficha[i].codigo = i;
		printf("\nDeseja cadastrar mais um produto?");
		printf("\n1 - Sim");
		printf("\n2 - Não");
		printf("\n");
		scanf ("%d", &cadNov);
		switch (cadNov) {
		case 1:
			qtd++;
			qtdProjetos = i + 1;
			break;
		case 2:
			qtdProjetos = i + 1;
			break;		
		default:  
			nExiste();
			qtdProjetos = i + 1;
			break;
		}
	}
	printf("\n");
} else {
	printf("\nVocê já cadastrou o limite máximo de 200 projetos!\n");
}
	
}
int main () {
setlocale(LC_ALL, "Portuguese");
opcao = 0;
		while (opcao <= 1) {
		menuOpcoes();
		switch (opcao){	
			case 1:
			if (qtdProjetos == 0) {
				cadastrar(0);
			} else {
				cadastrar(qtdProjetos);
			}
			break;
			case 4:
				design3();
				printf("\nFinalizando sistema...\n");
				design3(); 
			break;
			default:  
				nExiste();
				opcao = 0;
			break;
		}
	}	
}
