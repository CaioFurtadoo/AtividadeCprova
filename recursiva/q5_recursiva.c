#include <stdio.h>
#include <stdlib.h>

void contagem(int n){
    if(n < 0){
        return;
    }
    printf("%d, ", n);
    contagem(n-1);
}

int main()
{
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    contagem(n);
    return 0;
}