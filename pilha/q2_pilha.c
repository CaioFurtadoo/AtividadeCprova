#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    char dado;
    struct No *prox;
} No;

No *push(No *topo, char valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = topo;
    return novo;
}

No *pop(No *topo)
{
    if (!topo)
        return NULL;
    No *temp = topo;
    topo = topo->prox;
    free(temp);
    return topo;
}

int verificarExpressao(const char *expressao)
{
    No *pilha = NULL;

    for (int i = 0; expressao[i] != '\0'; i++)
    {
        if (expressao[i] == '(')
        {
            pilha = push(pilha, '(');
        }
        else if (expressao[i] == ')')
        {
            if (!pilha)
            {
                return 0;
            }
            pilha = pop(pilha);
        }
    }

    int valido = (pilha == NULL);

    while (pilha)
    {
        pilha = pop(pilha);
    }

    return valido;
}

int main()
{
    const char *expressao1 = "(())()";
    const char *expressao2 = "(()";

    printf("Expressão: %s → %s\n", expressao1, verificarExpressao(expressao1) ? "Válido" : "Inválido");
    printf("Expressão: %s → %s\n", expressao2, verificarExpressao(expressao2) ? "Válido" : "Inválido");

    return 0;
}
