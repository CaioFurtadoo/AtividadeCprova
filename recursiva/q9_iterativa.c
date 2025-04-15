#include <stdio.h>
#include <stdlib.h>

int soma_digitos(int n)
{
    int soma = 0;
    while (n >= 1)
    {
        soma += n % 10;
        n /= 10;
    }
    return soma;
}

int main()
{
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    int resultado = soma_digitos(numero);
    printf("A soma dos dígitos de %d é: %d\n", numero, resultado);

    return 0;
}