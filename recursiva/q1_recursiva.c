#include <stdio.h>
#include <stdlib.h>

int digitos(int n)
{
    if (n < 1)
    {
        return 0;
    }
    
    return  digitos(n / 10) + 1;
}

int main()
{
    int digito;
    printf("Digite um numero: ");
    scanf("%d", &digito);
    printf("%d", digitos(digito));
    return 0;
}