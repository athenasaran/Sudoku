//
// Created by athena on 09/10/18.
//

#include "sudoku.h"

int substituicoes = 0;
int tentativas = 0;

int verificar(int sudoku[][9], int linha, int coluna, int num)
{

    int linhaQuadrante = (linha / 3) * 3;
    int colunaQuadrante = (coluna / 3) * 3;
    int i;

    for (i = 0; i < 9; i++)
    {
        if (sudoku[linha][i] == num)
        {
            return 0;
        }
        if (sudoku[i][coluna] == num)
        {
            return 0;
        }

        if (sudoku[linhaQuadrante + (i % 3)][colunaQuadrante + (i / 3)] == num)
        {
            return 0;
        }

    }
    return 1;

}

int resolver(int sudoku[][9], int linha, int coluna)
{
    int i;

    if (linha < 9 && coluna < 9)
    {

        if (sudoku[linha][coluna] != 0)
        {

            if ((coluna + 1) < 9)
            {

                return resolver(sudoku, linha, coluna + 1);

            }
            else if ((linha + 1) < 9)
            {

                return resolver(sudoku, linha + 1, 0);

            }
            else
            {
                return 1;
            }
        }
        else
        {

            for (i = 0; i < 9; i++)
            {

                if (verificar(sudoku, linha, coluna, i + 1))
                {
                    sudoku[linha][coluna] = i + 1;
                    tentativas++;

                    if ((coluna + 1) < 9)
                    {

                        if (resolver(sudoku, linha, coluna + 1))
                        {
                            return 1; //ocorre substituiçao pelo palpite
                        }
                        else
                        {
                            sudoku[linha][coluna] = 0;
                            substituicoes++;
                        }

                    }
                    else if ((linha + 1) < 9)
                    {
                        if (resolver(sudoku, linha + 1, 0))
                        {
                            return 1; //ocorre substituiçao pelo palpite

                        }
                        else
                        {
                            sudoku[linha][coluna] = 0;
                            substituicoes++;

                        }
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
        }

        return  0;//continua a resolver
    }
    else
    {
        return 1;//jogo resolvido

    }

}

void imprimir()
{

    printf("\nModo Análise Ativado\n");
    printf("Total de Tentativas: %d\n",tentativas);
    printf("Total de Substituições: %d\n",substituicoes);
    printf("Total de chamadas recursivas: %d\n",tentativas + substituicoes);
}
