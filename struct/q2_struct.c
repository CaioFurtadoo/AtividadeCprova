#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int matricula;
    float nota;
} Aluno;

float media(Aluno Alunos[], int tamanho){
    float media = 0;
    for(int i = 0; i<tamanho; i++){
        media += Alunos[i].nota;
    }
    return media/tamanho;
}

int main() {
    int tamanho = 5;
    Aluno Alunos[5];
    
    for(int i = 0; i<tamanho; i++){
        printf("\nDigite o seu Nome: ");
        scanf("%s", Alunos[i].nome);
        
        printf("\nDigite a sua matricula: ");
        scanf("%d", &Alunos[i].matricula);
        
        printf("\nDigite o sua Nota: ");
        scanf("%f", &Alunos[i].nota);
    }
    
    float mediaNotas = media(Alunos, tamanho);
    printf("\nA media dos alunos é: %.00f", mediaNotas);

    return 0;
}
