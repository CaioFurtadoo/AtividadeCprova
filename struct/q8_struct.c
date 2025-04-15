#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float base;
    float altura;
} Retangulo;

float area(Retangulo r)
{
    return r.base * r.altura;
}

float perimetro(Retangulo r)
{
    return (r.base * 2) + (r.altura * 2);
}

int main()
{
    Retangulo r;

    printf("Insira o valor da base: ");
    scanf("%f", &r.base);

    printf("Insira o valor da altura: ");
    scanf("%f", &r.altura);

    printf("Area: %.2f\n", area(r));
    printf("Perimetro: %.2f\n", perimetro(r));
}
