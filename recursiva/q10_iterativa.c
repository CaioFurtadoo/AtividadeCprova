#include <stdio.h>
#include <stdlib.h>

int sequenciaSoma(int n, int s)
{
    int soma = 0;
    for (int i = 0; i < s; i++)
    {
        soma += n;
    }
    return soma;
}

int main()
{
    int n, s;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("Digite a quantidade: ");
    scanf("%d", &s);

    printf("%d", sequenciaSoma(n, s));
    return 0;
}