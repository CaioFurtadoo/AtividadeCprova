#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Carro {
    char modelo[31];
    int ano;
    float preco;
};

int main() {
    struct Carro *meuCarro = (struct Carro *) malloc(sizeof(struct Carro));

    if (meuCarro == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    strcpy(meuCarro->modelo, "Toyota Corolla");
    meuCarro->ano = 2020;
    meuCarro->preco = 85000.50;

    printf("Informações do Carro:\n");
    printf("Modelo: %s\n", meuCarro->modelo);
    printf("Ano: %d\n", meuCarro->ano);
    printf("Preco: R$ %.2f\n", meuCarro->preco);

    free(meuCarro);

    return 0;
}
