#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    char cargo[50];
    float salario;
} Func;

int main()
{
    int N;
    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &N);

    Func funcionarios[N];

    for (int i = 0; i < N; i++)
    {
        printf("\nFuncionário %d:\n", i + 1);
        printf("Digite o Nome: ");
        scanf("%s", funcionarios[i].nome);

        printf("Digite o Cargo: ");
        scanf("%s", funcionarios[i].cargo);

        printf("Digite o Salário: ");
        scanf("%f", &funcionarios[i].salario);
    }

    printf("\n--- Lista de Funcionários ---\n");
    for (int i = 0; i < N; i++)
    {
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Salário: %.2f\n", funcionarios[i].salario);
        printf("-----------------------------\n");
    }

    return 0;
}
