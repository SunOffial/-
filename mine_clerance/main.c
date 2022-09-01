#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu() {
	printf("########################\n");
	printf("###��ӭ������������Ϸ###\n");
	printf("########################\n");
}

void game() {
	//��������
	char board[ROW][COL] = { 0 };

	//�������������
	srand((unsigned int)time(NULL));

	//����FLAG
	char flag = ' ';

	//��ʼ������
	creatBoard(board, ROW, COL);

	//��ӡ����
	printBoard(board, ROW, COL);


	while (1) {
		//����ƶ�
		flag=playerMove(board, ROW, COL);

		//��ӡ����
		printBoard(board, ROW, COL);

		if (flag != 'C') {
			break;
		}

		//�����ƶ�
		flag=computerMove(board, ROW, COL);

		//��ӡ����
		printBoard(board, ROW, COL);

		if (flag != 'C') {
			break;
		}

	}

	switch (flag) {
	case '*':
		printf("���ʤ��\n");
		break;
	case '#':
		printf("����ʤ��\n");
		break;
	case 'P':
		printf("ƽ��\n");
		break;
	}
}


void test() {
	do {
		int choose = 0;
		menu();
		printf("������(1 ��ʼ��Ϸ 2 �˳���Ϸ)>");
		scanf("%d", &choose);
		switch (choose) {
		case 1:
		{	
			//��ʼ��Ϸ
			game();
			break;
		}
		case 2:
			break;
		default:
			break;
		}
		
	} while (1);
}



int main() {
	test();

	return 0;
}