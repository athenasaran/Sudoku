#include <stdio.h>
#include "sudoku.h"

int main() {
    int sudoku[9][9];

    int i, j;

    int nivel;

    FILE *arquivo;

    char *nome = NULL;

    nome = (char*)malloc(sizeof(20));

    printf("Esse sudoku possuiu 4 niveis de dificuldade\n");
    printf("Digite 1 para nivel super facil\n");
    printf("Digite 2 para  para nivel facil\n");
    printf("Digite 3 para nivel medio\n");
    printf("Digite 4 para nivel dificil\n");
    scanf("%d", &nivel);

    switch (nivel) {
        case 1:
            nome = "superfacil.txt";
            break;
        case 2:
            nome = "facil.txt";
            break;
        case 3:
            nome = "medio.txt";
            break;
        case 4:
            nome = "dificil.txt";
            break;
    }

    arquivo = fopen(nome, "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir arquivo\n");

    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            fscanf(arquivo, "%d ", &sudoku[i][j]);
        }
    }

    printf("\tSUDOKU SEM SOLUÇAO\n");

    for (i = 0; i < 9; i++) {
        printf("\n");
        if (i % 3 == 0) {
            printf("\n");
        }
        for (j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                printf("\t");
            }
            printf("%d ", sudoku[i][j]);
        }
    }

    printf("\nSUDOKU COM SOLUÇAO\n");

    if (resolver(sudoku, 0, 0)) {
        for (i = 0; i < 9; i++) {
            printf("\n");
            if (i % 3 == 0) {
                printf("\n");
            }
           for (j = 0; j < 9; j++) {
                if (j % 3 == 0) {
                    printf("\t");
                }
                printf("%d ", sudoku[i][j]);
            }
        }

    }
    else {
        printf("\nEsse SUDOKU não tem soluçao\n");
    }

    if (ANALISE == 0) {
        imprimir();
    }

    getchar();

    return 0;
}
