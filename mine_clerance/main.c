#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu() {
	printf("########################\n");
	printf("###欢迎来到三子棋游戏###\n");
	printf("########################\n");
}

void game() {
	//生成棋盘
	char board[ROW][COL] = { 0 };

	//生成随机数种子
	srand((unsigned int)time(NULL));

	//创建FLAG
	char flag = ' ';

	//初始化棋盘
	creatBoard(board, ROW, COL);

	//打印棋盘
	printBoard(board, ROW, COL);


	while (1) {
		//玩家移动
		flag=playerMove(board, ROW, COL);

		//打印棋盘
		printBoard(board, ROW, COL);

		if (flag != 'C') {
			break;
		}

		//电脑移动
		flag=computerMove(board, ROW, COL);

		//打印棋盘
		printBoard(board, ROW, COL);

		if (flag != 'C') {
			break;
		}

	}

	switch (flag) {
	case '*':
		printf("玩家胜利\n");
		break;
	case '#':
		printf("电脑胜利\n");
		break;
	case 'P':
		printf("平局\n");
		break;
	}
}


void test() {
	do {
		int choose = 0;
		menu();
		printf("请输入(1 开始游戏 2 退出游戏)>");
		scanf("%d", &choose);
		switch (choose) {
		case 1:
		{	
			//开始游戏
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