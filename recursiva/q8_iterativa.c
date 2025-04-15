#include <stdio.h>

int maiorElemento(int n[], int tamanho)
{
    int maior = n[0];
    for(int i = 1; i<=tamanho; i++){
        if(n[i]>maior){
            maior = n[i];
        }
    }
    return maior;
}

int main()
{
    int n[5] = {5, 10, 1, 3, 2};
    int tamanho = sizeof(n) / sizeof(n[0]);

    printf("O número maior é: %d\n", maiorElemento(n, tamanho - 1));

    return 0;
}
