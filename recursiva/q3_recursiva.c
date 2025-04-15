#include <stdio.h>
#include <stdlib.h>

int soma_digitos(int n)
{
    if (n < 1)
        return 0;

    return (n % 10) + soma_digitos(n / 10);
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