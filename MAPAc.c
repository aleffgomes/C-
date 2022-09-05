#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int num;
    struct no *next;
}pilha;

//Prototipos bases
void empilha(pilha *topo[], int num);
void desempilha(pilha *topo[]);
void imprime(pilha *topo);
void menu();
char return_color(int color);

int main() {
    pilha *topo = NULL;
    int op;
    menu();
    scanf("%1d", &op);
    while (op != 0 && op < 10) {
        switch (op){
            case 1:
                if (topo == NULL) {            
                    printf("\nEmpilhando: \n");
                    empilha(&topo, 1);
                    empilha(&topo, 2);
                    empilha(&topo, 3);
                    empilha(&topo, 4);
                    empilha(&topo, 5);
                    break;
                } else {
                    printf("\nPilha ja esta cheia!\n");
                    break;
                }
            case 2:
                printf("\nDesempilhando: ");
                while (1)
                {
                    if (topo == NULL)
                    {
                        printf("\nPilha vazia!\n");
                        break;
                    }
                    imprime(topo);
                    desempilha(&topo);
                }
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        menu();
        scanf("%d", &op);
    };
    return 0;
}

void empilha(pilha *topo[], int num)
{
    pilha *novo = (pilha *)malloc(sizeof(pilha));
    novo->num = num;
    novo->next = *topo;
    *topo = novo;
    printf("\n%d", num);
    return_color(num);
}

void desempilha(pilha *topo[])
{
    pilha *aux = *topo;
    *topo = (*topo)->next;
    printf("\nRetirando");
    return_color(aux->num);
    printf("\n");
    free(aux);
}

void imprime(pilha *topo)
{
    pilha *aux = topo;
    printf("\nLista atual: ");
    while (aux != NULL)
    {
        printf("\n%d", aux->num);
        return_color(aux->num);
        aux = aux->next;
    }
    printf("\n");
}

void menu(){
    printf("\n\nEscolha uma opcao:\n");
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("0 - Sair\n");
}

char return_color(int num) {
    char color[10];
    switch (num) {
        case 1:
            strcpy(color, "vermelho");
            break;
        case 2:
            strcpy(color, "verde");
            break;
        case 3:
            strcpy(color, "azul");
            break;
        case 4:
            strcpy(color, "branco");
            break;
        case 5:
            strcpy(color, "laranja");
            break;
        default:
            break;
    }
    printf(" -> %s", color);
}

