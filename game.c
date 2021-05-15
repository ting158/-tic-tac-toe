#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"

//游戏菜单（初始界面）
void menu()
{
	printf("*********************\n");
	printf("***1.play   0.exit***\n");
	printf("*********************\n");
}



//初始化棋盘
void Board(char board[ROW][COL], int row, int col)
{
	int i = 0;//行
	int j = 0;//列
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
		
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;//行
	int j = 0;//列
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}			
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col - 1;j++)
			{
				if (j < col - 1)
				{
					printf("---|");
				}
			}
			printf("---\n");
		}
	}
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("玩家开始\n");
	while (1)
	{
		printf("请输入坐标: > ");
		scanf("%d%d", &i, &j);
		//判断坐标合法性
		if (i >= 1 && j >= 1 && i <= row && j <= col)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标不存在，请重新输入\n");
		}
	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("电脑走\n");
	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}

//判断平局
int Is_Draw(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	for (x = 0;x < row;x++)
	{
		for (y = 0;y < col;y++)
		{
			if (board[x][y] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//判断输赢
//1 玩家赢
//0 电脑赢
//2 平局
//3 继续
int Is_Win(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	//判断行
	for (x = 0;x < row;x++)
	{
		if (board[x][0] == board[x][1] && board[x][0] == board[x][2] && board[x][0] == '*')
		{
			return 1;
		}
		if (board[x][0] == board[x][1] && board[x][0] == board[x][2] && board[x][0] == '#')
		{
			return 0;
		}
	}
	//判断列
	for (y = 0;y < row;y++)
	{
		if (board[0][y] == board[1][y] && board[0][y] == board[2][y] && board[0][y] == '*')
		{
			return 1;
		}
		if (board[0][y] == board[1][y] && board[0][y] == board[2][y] && board[0][y] == '#')
		{
			return 0;
		}
	}
	//判断斜的情况
	if (board[0][0] == board[1][1] && board[0][0] == board[3][3] && board[0][0] == '*')
	{
		return 1;
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == '#')
	{
		return 0;
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == '*')
	{
		return 1;
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == '#')
	{
		return 0;
	}
	//判断平局
	if (1 == Is_Draw(board, ROW, COL))
	{
		return 2;
	}
	return 3;
}

