#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int idade;
    char diagnostico[100];
} Paciente;

void filtrarPaciente(Paciente p[], int index)
{
    if (index < 0)
    {
        printf("Lista de pacientes completa");
        return;
    }
    if (p[index].idade > 60)
    {
        printf("%s\n", p[index].nome);
        printf("%d\n", p[index].idade);
        printf("%s\n", p[index].diagnostico);
        printf("-------------------------------------------\n");
    }

    filtrarPaciente(p, index - 1);
}

int main()
{
    Paciente p[5] =
        {
            {"Joaquim", 76, "ta dodoi"},
            {"Rodrigo", 43, "quebrou o pé"},
            {"clarinha", 8, "fez birra"},
            {"Caio", 19, "dor de cabeça"},
            {"Edith", 70, "dor no ouvido"}};

    printf("-------------------------------------------\n");
    filtrarPaciente(p, 5);
}
