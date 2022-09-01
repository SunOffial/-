#pragma once
#include"game.h"
int left(char board[ROW][COL], char symbol, int x, int y);
int right(char board[ROW][COL], char symbol, int x, int y);
int up(char board[ROW][COL], char symbol, int x, int y);
int down(char board[ROW][COL], char symbol, int x, int y);
int leftUp(char board[ROW][COL], char symbol, int x, int y);
int rightUp(char board[ROW][COL], char symbol, int x, int y);
int leftDown(char board[ROW][COL], char symbol, int x, int y);
int rightDown(char board[ROW][COL], char symbol, int x, int y);