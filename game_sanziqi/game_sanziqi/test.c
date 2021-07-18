#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game() {
	char ret = 0;
	//printf("game start");
	char board[ROW][COL] = { 0 };//����Ӧ�ó�ʼ��Ϊ�ո�
	InitBoard(board, ROW, COL);//��ʼ������
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//������
	//1�����Ӯ * 2������Ӯ # 3��ƽ�� Q 4������ C
	//Ҫ�ж���Ӯ
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		
	}
	if (ret == '*') {
		printf("���Ӯ\n");
	}
	else if(ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

void menu() {
	printf("##########################\n");
	printf("######### 1��play ########\n");
	printf("######### 0��exit ########\n");
	printf("##########################\n");
}

int main() {
	int input = 0;
	srand((unsigned int)time(NULL));//���������
	do {
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��������Ϸ
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (input);
}