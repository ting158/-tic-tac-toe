#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//设置棋盘尺寸
#define ROW 3
#define COL 3

void menu();
void Board(char coard, int row, int col);
void DisplayBoard(char board, int row, int col);
void PlayerMove(char board, int row, int col);
void ComputerMove(char board, int row, int col);
int Is_Win(char board, int row, int col);
int Is_Draw(char board, int row, int col);
