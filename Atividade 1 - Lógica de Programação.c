#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
	
#define reajuste 1.075
#define abono 150
int contDesing, opcao, consultnovamente;
float salarioAtual, salarioAjustado, salarioComAbono;

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
	printf("SOFT ALT S/A\n");
	design2();
	printf("\nR.A.: 21062218-5  ||  Alef Wenderson Melgaço Gomes");
	design1();
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
int menuOpcoes() {
	printf("\nSelecione uma opção: ");
	printf("\n1 - Consultar salário.");
	printf("\n2 - Sair do sistema.");
	printf("\n");
	scanf ("%d", &opcao);	
	return(opcao);
}
void app() {
	system("cls");
	header();
	printf("\nDigite seu salário atual: ");
	scanf ("%f", &salarioAtual);
	
	salarioAjustado = salarioAtual * reajuste;
	
	if (salarioAjustado <= 1750.00) {
		salarioComAbono = salarioAjustado + abono;
		printf("\n");
		design2();
		printf("\nSeu salário com reajuste + abono é: %f", salarioComAbono);
		printf("\n");
		design2();
		printf("\n");
	} else {
		printf("\n");
		design2();
		printf("\nSeu salário com reajuste é: %f", salarioAjustado);
		printf("\n");
		design2();
		printf("\n");
	}
}
int main () {
	setlocale(LC_ALL, "Portuguese");
	opcao = 0;
	header();
	while (opcao <= 1) {
		menuOpcoes();
		switch (opcao){	
			case 1:	
				app();
			break;
			case 2:
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

