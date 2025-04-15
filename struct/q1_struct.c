#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main()
{

    Pessoa p1;
    printf("\nDigite o seu Nome: ");
    scanf("%s", p1.nome);

    printf("\nDigite o sua Idade: ");
    scanf("%d", &p1.idade);

    printf("\nDigite o sua Altura: ");
    scanf("%f", &p1.altura);

    printf("Nome: %s\n", p1.nome);
    printf("Idade: %d\n", p1.idade);
    printf("Altura: %.2f\n", p1.altura);

    return 0;
}
