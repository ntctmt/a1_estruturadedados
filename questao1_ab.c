#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de nó
struct Aluno {
    int matricula;
    float notaA1;
    float notaA2;
    float notaA3;
    float media;
    struct Aluno* proximo;
};

// Função para inserir um aluno na lista de forma ordenada decrescente pela média
void inserirAlunoOrdenado(struct Aluno** lista, struct Aluno* novoAluno) {
    if (*lista == NULL || novoAluno->media >= (*lista)->media) {
        novoAluno->proximo = *lista;
        *lista = novoAluno;
    } else {
        struct Aluno* atual = *lista;
        while (atual->proximo != NULL && atual->proximo->media > novoAluno->media) {
            atual = atual->proximo;
        }
        novoAluno->proximo = atual->proximo;
        atual->proximo = novoAluno;
    }
}

int main() {
    int numTurmas, numAlunos;

    printf("Digite o número de turmas: ");
    scanf("%d", &numTurmas);

    struct Aluno* listaAlunos = NULL;
    int alunosAprovados = 0;
    int alunosReprovados = 0;

    for (int turma = 1; turma <= numTurmas; turma++) {
        printf("Turma %d\n", turma);
        printf("Digite o número de alunos na turma: ");
        scanf("%d", &numAlunos);

        for (int aluno = 1; aluno <= numAlunos; aluno++) {
            struct Aluno* novoAluno = (struct Aluno*)malloc(sizeof(struct Aluno));
            if (novoAluno == NULL) {
                printf("Erro na alocação de memória.\n");
                return 1;
            }

            printf("Digite a matrícula do aluno %d: ", aluno);
            scanf("%d", &novoAluno->matricula);
            printf("Digite as notas A1, A2 e A3 do aluno %d (separadas por espaços): ", aluno);
            scanf("%f %f %f", &novoAluno->notaA1, &novoAluno->notaA2, &novoAluno->notaA3);

            // Calcular a média do aluno
            novoAluno->media = (novoAluno->notaA1 + novoAluno->notaA2 + novoAluno->notaA3) / 3.0;

            // Inserir o aluno na lista ordenada
            inserirAlunoOrdenado(&listaAlunos, novoAluno);

            // Verificar se o aluno está aprovado ou reprovado
            if (novoAluno->media >= 7.0) {
                alunosAprovados++;
            } else {
                alunosReprovados++;
            }
        }
    }

    // Imprimir os 3 alunos com média superior a 7
    printf("\nAlunos aprovados (Média > 7.0):\n");
    struct Aluno* atual = listaAlunos;
    int aprovadosExibidos = 0;
    while (atual != NULL && aprovadosExibidos < 3) {
        if (atual->media > 7.0) {
            printf("Matrícula: %d, Média: %.2f\n", atual->matricula, atual->media);
            aprovadosExibidos++;
        }
        atual = atual->proximo;
    }

    // Imprimir os 3 primeiros alunos com nota inferior a 7 e a mensagem de reprovação
    printf("\nAlunos reprovados (Média <= 7.0):\n");
    atual = listaAlunos;
    int reprovadosExibidos = 0;
    while (atual != NULL && reprovadosExibidos < 3) {
        if (atual->media <= 7.0) {
            printf("Matrícula: %d, Média: %.2f - Você está reprovado.\n", atual->matricula, atual->media);
            reprovadosExibidos++;
        }
        atual = atual->proximo;
    }

    // Liberar a memória alocada para os alunos
    while (listaAlunos != NULL) {
        struct Aluno* temp = listaAlunos;
        listaAlunos = listaAlunos->proximo;
        free(temp);
    }

    printf("\nTotal de alunos aprovados: %d\n", alunosAprovados);
    printf("Total de alunos reprovados: %d\n", alunosReprovados);

    return 0;
}
