#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
#include"same.h"


//��ʼ������
void creatBoard(char board[ROW][COL],int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] =' ';
		}
	}
}

//��ӡ����
void printBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j != col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i != row - 1) {
			for (int j = 0; j < col; j++) {
				printf("---");
				if (j != col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//����ƶ�
char playerMove(char board[ROW][COL], int row, int col) {

	int x = 1;
	int y = 1;

	while (1)
	{
		printf("����ƶ�>\n");
		printf("����������:");
		scanf("%d,%d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			if (board[x-1][y-1] == ' ') {
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("�������ظ���λ������\n");
				continue;
			}
		}
	}

	return judgeGame(board, '*',x - 1, y - 1);

}

//�����ƶ�
char computerMove(char board[ROW][COL],int row,int col){

	int x = 1;
	int y = 1;

	while (1) {
		int randX = rand() % row;
		int randY = rand() % row;
		x = randX;
		y = randY;
		if (board[randX][randY] == ' ') {
			board[randX][randY] = '#';
			break;
		}
	}

	return judgeGame(board, '#',x, y);

}

//�ж�ƽ��
char isFull(char board[ROW][COL], int row, int col) {
	//�ж�ƽ��
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 'C';
			}
		}
	}
	return 'P';

}

//�ж�ʤ��
int isWin(char board[ROW][COL], char symbol, int x, int y) {
	int cnt1, cnt2, cnt3, cnt4;
	cnt1 = cnt2 = cnt3 = cnt4 = 1;
	cnt1+=left(board, symbol, x, y);
	cnt1+=right(board, symbol, x, y);
	cnt2 += up(board, symbol, x, y);
	cnt2 += down(board, symbol, x, y);
	cnt3+=leftUp(board, symbol, x, y);
	cnt3+=rightDown(board, symbol, x, y);
	cnt4+=rightUp(board, symbol, x, y);
	cnt4+=leftDown(board, symbol, x, y);

	if ((cnt1 == NUMBER) || (cnt2 == NUMBER) || (cnt3 == NUMBER) || (cnt4 == NUMBER)) {
		return 1;
	}

	return 0;

}

//�ж�ʤ��
char judgeGame(char board[ROW][COL], char symbol,int x, int y) {

	//�ж�ƽ��
	char flag = isFull(board, ROW, COL);

	if (flag == 'P') {
		return flag;
	}

	//�ж�ʤ��
	int result=isWin(board, symbol, x, y);

	if (result == 1) {
		return symbol;
	}
	else
	{
		//����
		return 'C';
	}
}