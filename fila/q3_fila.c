#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct
{
    char nome[30];
} Cliente;

typedef struct
{
    Cliente clientes[TAM];
    int inicio, fim, qtd;
} FilaBanco;

void inicializar(FilaBanco *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}

int enfileirar(FilaBanco *f, char nome[])
{
    if (f->qtd == TAM)
        return 0;

    strcpy(f->clientes[f->fim].nome, nome);
    f->fim = (f->fim + 1) % TAM;
    f->qtd++;
    return 1;
}

int atender(FilaBanco *f, Cliente *c)
{
    if (f->qtd == 0)
        return 0;

    *c = f->clientes[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    f->qtd--;
    return 1;
}

void mostrarFila(FilaBanco *f)
{
    printf("Fila: ");
    for (int i = 0, pos = f->inicio; i < f->qtd; i++, pos = (pos + 1) % TAM)
    {
        printf("%s ", f->clientes[pos].nome);
    }
    printf("\n");
}

int main()
{
    FilaBanco fila;
    Cliente atendido;
    inicializar(&fila);

    enfileirar(&fila, "Maria");
    enfileirar(&fila, "João");
    enfileirar(&fila, "Ana");

    mostrarFila(&fila);

    if (atender(&fila, &atendido))
        printf("Atendendo: %s\n", atendido.nome);

    mostrarFila(&fila);

    return 0;
}
