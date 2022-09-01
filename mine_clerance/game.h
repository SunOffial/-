#pragma once
#include<stdio.h>
#define ROW  5
#define COL  5
#define NUMBER  3

void creatBoard(char board[ROW][COL],int row, int col);
void printBoard(char board[ROW][COL], int row, int col);
char playerMove(char board[ROW][COL], int row, int col);
char computerMove(char board[ROW][COL], int row, int col);
char judgeGame(char board[ROW][COL], int row,int col);