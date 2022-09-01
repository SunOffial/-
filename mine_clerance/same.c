#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"

//�ж�����

//��
int left(char board[ROW][COL], char symbol, int x, int y) {
	int symbol_num = 0;
	if ((y-1)>=0 && board[x][y - 1] == symbol) {
		symbol_num++;
		symbol_num+=left(board,symbol,x,y-1);

	}
	return symbol_num;
}

//��
int right(char board[ROW][COL], char symbol, int x, int y) {
	int symbol_num = 0;
	if ((y + 1) < ROW && board[x][y + 1] == symbol) {
		symbol_num++;
		symbol_num += right(board, symbol, x, y + 1);

	}
	return symbol_num;
}

//��
int up(char board[ROW][COL], char symbol, int x, int y) {
	int symbol_num = 0;
	if ((x - 1) >= 0 && board[x-1][y] == symbol) {
		symbol_num++;
		symbol_num += up(board, symbol, x-1, y);

	}
	return symbol_num;
}

//��
int down(char board[ROW][COL], char symbol, int x, int y) {
	int symbol_num = 0;
	if ((x + 1) <ROW && board[x+1][y] == symbol) {
		symbol_num++;
		symbol_num += down(board, symbol, x+1, y);

	}
	return symbol_num;
}

//����
int leftUp(char board[ROW][COL], char symbol, int x, int y) {
	int symbol_num = 0;
	if ((y - 1) >= 0 && (x-1)>=0 && board[x-1][y - 1] == symbol) {
		symbol_num++;
		symbol_num += leftUp(board, symbol, x - 1, y - 1);

	}
	return symbol_num;
}

//����
int rightUp(char board[ROW][COL], char symbol, int x, int y) {
	int symbol_num = 0;
	if ((y + 1) < COL && (x - 1) >= 0 && board[x - 1][y + 1] == symbol) {
		symbol_num++;
		symbol_num += rightUp(board, symbol, x - 1, y + 1);

	}
	return symbol_num;
}

//����
int leftDown(char board[ROW][COL], char symbol, int x, int y) {
	int symbol_num = 0;
	if ((y - 1) >= 0 && (x + 1) < ROW && board[x + 1][y - 1] == symbol) {
		symbol_num++;
		symbol_num += leftDown(board, symbol, x + 1, y - 1);

	}
	return symbol_num;
}

//����
int rightDown(char board[ROW][COL], char symbol, int x, int y) {
	int symbol_num = 0;
	if ((y + 1) <COL && (x + 1) <ROW && board[x + 1][y + 1] == symbol) {
		symbol_num++;
		symbol_num += rightDown(board, symbol, x + 1, y + 1);

	}
	return symbol_num;
}

