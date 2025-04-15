#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char titulo[50];
    char autor[50];
    int ano;
} Livro;

void filtroAno(Livro livros[], int ano, int index)
{
    if (index < 0)
    {
        printf("Todos os livros foram filtrados.\n");
        return;
    }

    if (livros[index].ano > ano)
    {
        printf("Nome do livro: %s\n", livros[index].titulo);
        printf("Autor do livro: %s\n", livros[index].autor);
        printf("Ano do livro: %d\n", livros[index].ano);
        printf("-------------------------\n");
    }

    filtroAno(livros, ano, index - 1);
}

int main()
{
    Livro livros[5] = {
        {"Dom Casmurro", "Machado de Assis", 1899},
        {"Capitães da Areia", "Jorge Amado", 1937},
        {"A Hora da Estrela", "Clarice Lispector", 1977},
        {"O Alquimista", "Paulo Coelho", 1988},
        {"Torto Arado", "Itamar Vieira Junior", 2019}};

    int anoFiltro;
    printf("Digite o ano limite: ");
    scanf("%d", &anoFiltro);

    printf("\nLivros lançados após %d:\n", anoFiltro);
    printf("-------------------------\n");

    filtroAno(livros, anoFiltro, 4);

    return 0;
}
