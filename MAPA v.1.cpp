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
void cadastrar();

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

int contDesing, opcao, consultnovamente;

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
void cadastrar() {

}
int main () {
	setlocale(LC_ALL, "Portuguese");
	opcao = 0;
	header();
		while (opcao <= 1) {
		menuOpcoes();
		switch (opcao){	
			case 1:	
				cadastrar();
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
