#include <stdio.h>
#include <string.h>

int palindromo(char str[], int inicio, int fim)
{
    if (inicio >= fim)
    {
        return 1;
    }

    if (str[inicio] != str[fim])
    {
        return 0;
    }

    return palindromo(str, inicio + 1, fim - 1);
}

int main()
{
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int resultado = palindromo(palavra, 0, strlen(palavra) - 1);

    if (resultado)
    {
        printf("É um palíndromo!\n");
    }
    else
    {
        printf("Não é um palíndromo.\n");
    }

    return 0;
}