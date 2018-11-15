#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"
int menu(){
    int opcao;
    printf("Tarefa B: Obras na estrada\n");
    printf("Digite 1 para entrar com o arquivo");
    printf("Digite 2 para imprimir os caminhos possiveis\n");
    printf("Digite 0 para sair\n");
    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    int opcao;
    clock_t t_ini, t_fim;
    double tempo_segundos;
    char *nomearquivo;
    nomearquivo  = (char*)malloc(sizeof(20));

    opcao = menu();

    while(opcao!=0){
        switch (opcao) {
        case 1:
            printf("Digite o nome do arquivo: ");
            scanf("%s", nomearquivo);
            opcao = menu();
            break;
        case 2:
            if(DEBUG){
                t_ini = clock();
                caminhos(nomearquivo);
                t_fim = clock();
                tempo_segundos = (t_fim - t_ini)/ ((double) CLOCKS_PER_SEC *1000.0);

                printf("Debug: tempo total para achar os caminhos possiveis: %f ns\n", tempo_segundos);
            }
            else{
                caminhos(nomearquivo);
            }
            opcao = menu();
        default:
            printf("Opcao invalida");
        }
    }


    return 0;

}
