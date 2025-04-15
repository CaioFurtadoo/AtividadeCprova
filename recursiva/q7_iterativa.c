#include <stdio.h>
#include <stdlib.h>

void contagem(int n)
{
    int contador = n;
    for (int i = 0; i <= n; i++)
    {
        printf("%d, ", contador);
        contador--;
    }
}

int main()
{
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    contagem(n);
    return 0;
}