#include <stdio.h>
#include <stdlib.h>

int sequenciaSoma(int n, int s)
{
    if(s == 0){
        return 0;
    }

    return n + sequenciaSoma(n, s-1);
}

int main()
{
    int n, s;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("Digite a quantidade: ");
    scanf("%d", &s);

    printf("%d", sequenciaSoma(n,s));
    return 0;
}