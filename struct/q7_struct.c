#include <stdlib.h>
#include <stdio.h>
#include <string.h> // <- necessário para strcmp

typedef struct
{
    char nome[50];
    char telefone[15];
} Contato;

void filtrarContato(Contato contatos[], char nome[50], int index)
{
    if (index < 0)
    {
        printf("Contato não encontrado.\n");
        return;
    }

    if (strcmp(nome, contatos[index].nome) == 0)
    {
        printf("Nome: %s\n", contatos[index].nome);
        printf("Telefone: %s\n", contatos[index].telefone);
        return;
    }

    filtrarContato(contatos, nome, index - 1);
}

void imprimirLista(Contato contatos[], int index)
{

    if (index < 0)
    {
        return;
    }
    printf("Nome: %s\n", contatos[index].nome);
    printf("Telefone: %s\n", contatos[index].telefone);
    printf("------------------------------------\n");
    imprimirLista(contatos, index - 1);
}

int main()
{
    Contato contatos[3] = {
        {"Caio", "99999-1234"},
        {"Maria", "98888-5678"},
        {"João", "97777-4321"}};

    char nomeBusca[50];
    printf("------------------------------------\n");
    imprimirLista(contatos, 2);
    printf("Digite o nome do contato que deseja buscar: ");
    scanf("%s", nomeBusca);

    filtrarContato(contatos, nomeBusca, 2);

    return 0;
}
