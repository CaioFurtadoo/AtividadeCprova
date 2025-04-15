#include <stdio.h>

int maiorElemento(int n[], int index)
{
    if (index == 0)
    {
        return n[0];
    }

    int maiorDoResto = maiorElemento(n, index - 1);

    return (n[index] > maiorDoResto) ? n[index] : maiorDoResto;
}

int main()
{
    int n[5] = {5, 10, 1, 3, 2};
    int tamanho = sizeof(n) / sizeof(n[0]);

    printf("O número maior é: %d\n", maiorElemento(n, tamanho - 1));

    return 0;
}
