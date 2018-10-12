#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#define ANALISE 0 //diferente de 0 ativado igual a 0 desativado

#include <stdlib.h>
#include <stdio.h>


int verificar(int sudoku[][9], int linha, int coluna, int num);
int resolver(int sudoku[][9], int linha, int coluna);
void imprimir();

#endif // SUDOKU_H_INCLUDED
