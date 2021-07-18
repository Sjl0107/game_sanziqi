#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game() {
	char ret = 0;
	//printf("game start");
	char board[ROW][COL] = { 0 };//数组应该初始化为空格
	InitBoard(board, ROW, COL);//初始化棋盘
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//分析：
	//1、玩家赢 * 2、电脑赢 # 3、平局 Q 4、继续 C
	//要判断输赢
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		
	}
	if (ret == '*') {
		printf("玩家赢\n");
	}
	else if(ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

void menu() {
	printf("##########################\n");
	printf("######### 1、play ########\n");
	printf("######### 0、exit ########\n");
	printf("##########################\n");
}

int main() {
	int input = 0;
	srand((unsigned int)time(NULL));//生成随机数
	do {
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//三子棋游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);
}