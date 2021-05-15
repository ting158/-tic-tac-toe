#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"



//游戏的整个算法实现
void game()
{
	int win = 0;
	//存放棋盘信息
	char board[ROW][COL] = { '0' };
	//初始化棋盘
	Board(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		win = Is_Win(board, ROW, COL);
		if (win == 1)
		{
			printf("你赢了\n");
			break;
		}
		else if (win == 2)
		{
			printf("平局\n");
			break;
		}
		

		//电脑下
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		win = Is_Win(board, ROW, COL);
		if (win == 0)
		{
			printf("你输了\n");
			break;
		}
		else if (win == 2)
		{
			printf("平局\n");
			break;
		}

	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
		}
	} 	while (input);
	
}

int main()
{
	test();
	return 0;
}
