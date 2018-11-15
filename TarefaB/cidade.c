#include "cidade.h"

int caminhos(char *nomearquivo){
    FILE *arquivo;

    int linha, coluna, inicialX, inicialY, finalX, finalY;
    int obraX, obraY;
    char direcao;

    int obras[30][30] = {};
    long cidade[30][30] = {};

    int i,j;

    arquivo = fopen(nomearquivo,"r");

    if(arquivo == NULL){
        printf("Erro ao ler o arquivo\n");
        return 0;
    }
    //linhas e colunas
    fscanf(arquivo, "%d %d", &linha, &coluna);
    //coordenadas x e y do ponto inicial
    fscanf(arquivo,"%d %d", &inicialX, &inicialY);
    //coordenadas x e y do ponto final
    fscanf(arquivo,"%d %d", &finalX, &finalY);


    while(fscanf(arquivo, "%d %d %c", &obraX, &obraY, &direcao)!= EOF){
        direcao = toupper(direcao);
        switch(direcao){
        case 'N': //norte
            obras[obraX][obraY] = 1;
            break;
        case 'S': //sul
            obras[obraX][obraY] = 2;
            break;
        case 'L': //leste
            obras[obraX][obraY] = 3;
            break;
        case 'O': //oeste
            obras[obraX][obraY] = 4;
            break;
        default:
            break;
        }
    }
    cidade[linha][coluna] = 1;

    for(i=linha; i>=1;i--){//tras para frente
        for(j=coluna;j>=1;j--){
            if(i<linha && (obras[i][j] != 1)){//diferente de norte
                cidade[i][j] = cidade[i][j] + cidade[i+1][j];
            }
            if(j<coluna && (obras[i][j] != 3)){//diferente de leste
                cidade[i][j] = cidade[i][j] + cidade[i][j+1];
            }
        }
    }

    for(i=1;i<=linha;i++){
        printf("\n");
        for(j=1;j<=coluna;j++){
            printf("\t%ld", cidade[i][j]);
        }
    }

    printf("\nNumero de caminhos possiveis e: %ld\n", cidade[inicialX][inicialY]);

    return 0;

}
