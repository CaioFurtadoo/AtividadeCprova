#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTAS 100

typedef struct
{
    char nome[50];
    int numero;
    float saldo;
} Conta;

void criarConta(Conta contas[], int *total)
{
    if (*total >= MAX_CONTAS)
    {
        printf("Limite máximo de contas atingido.\n");
        return;
    }

    printf("\n--- Criar nova conta ---\n");
    printf("Nome: ");
    scanf(" %[^\n]", contas[*total].nome);
    printf("Número da conta: ");
    scanf("%d", &contas[*total].numero);
    contas[*total].saldo = 0;
    (*total)++;

    printf("Conta criada com sucesso!\n");
}

Conta *buscarConta(Conta contas[], int total, int numero)
{
    for (int i = 0; i < total; i++)
    {
        if (contas[i].numero == numero)
        {
            return &contas[i];
        }
    }
    return NULL;
}

void depositarSaldo(Conta *c, float valor)
{
    c->saldo += valor;
    printf("Valor depositado com sucesso!\n");
}

void sacarSaldo(Conta *c, float valor)
{
    if (c->saldo < valor)
    {
        printf("Saldo insuficiente!\n");
    }
    else
    {
        c->saldo -= valor;
        printf("Saque realizado com sucesso!\n");
    }
}

void exibirSaldo(Conta *c)
{
    printf("Saldo de %s (conta %d): R$ %.2f\n", c->nome, c->numero, c->saldo);
}

void listarContas(Conta contas[], int total)
{
    printf("\n--- Lista de Contas ---\n");
    for (int i = 0; i < total; i++)
    {
        printf("%d - %s | Conta: %d | Saldo: R$ %.2f\n", i + 1, contas[i].nome, contas[i].numero, contas[i].saldo);
    }
    printf("-----------------------\n");
}

int main()
{
    Conta contas[MAX_CONTAS];
    int totalContas = 0;
    int opcao;

    do
    {
        printf("\n==== MENU ====\n");
        printf("1. Criar conta\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Ver saldo\n");
        printf("5. Listar contas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        int numeroConta;
        float valor;
        Conta *c;

        switch (opcao)
        {
        case 1:
            criarConta(contas, &totalContas);
            break;

        case 2:
            printf("Número da conta: ");
            scanf("%d", &numeroConta);
            c = buscarConta(contas, totalContas, numeroConta);
            if (c != NULL)
            {
                printf("Valor para depositar: ");
                scanf("%f", &valor);
                depositarSaldo(c, valor);
            }
            else
            {
                printf("Conta não encontrada.\n");
            }
            break;

        case 3:
            printf("Número da conta: ");
            scanf("%d", &numeroConta);
            c = buscarConta(contas, totalContas, numeroConta);
            if (c != NULL)
            {
                printf("Valor para sacar: ");
                scanf("%f", &valor);
                sacarSaldo(c, valor);
            }
            else
            {
                printf("Conta não encontrada.\n");
            }
            break;

        case 4:
            printf("Número da conta: ");
            scanf("%d", &numeroConta);
            c = buscarConta(contas, totalContas, numeroConta);
            if (c != NULL)
            {
                exibirSaldo(c);
            }
            else
            {
                printf("Conta não encontrada.\n");
            }
            break;

        case 5:
            listarContas(contas, totalContas);
            break;

        case 0:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
