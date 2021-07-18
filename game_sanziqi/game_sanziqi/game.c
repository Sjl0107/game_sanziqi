#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row;  i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {//���д�ӡ
		//��ӡ����
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
			
		}
		printf("\n");//��ӡ�����ݻ���
		//��ӡ�ָ���
		//if(i<row-1)
		//	printf("---|---|---\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
				
			}
		}
		printf("\n");//��ӡ��ָ��߻���
	}
}

void PlayerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("����ߣ�\n");
	
	while (1)
	{
		printf("���������꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';//����
				break;
			}
			else
			{
				printf("�������Ա�ռ�ã�����������\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col) {
	printf("�����ߣ� \n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';//��������
			break;
		}
	}
}

static int IsFull(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row;  i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;//�п�
			}
		}
	}
	return 1;//����
}

char CheckWin(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	int count = 0;
	//���Ƿ����
	//for (i = 0; i < row; i++) {
	//	if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
	//		return board[i][0];
	//	}
	//}
	for (i = 0; i < row; i++) {
		count = 0;
		for (j = 0; j < col - 1; j++) {
			if (board[i][j] == board[i][j + 1] && board[i][j] != ' ') {
				count++;
			}
			else
			{
				break;
			}
			//if (count == col - 1) {
			//	return board[i][0];
			//}
		}
		if (count == col - 1) {
			return board[i][0];
		}
	}

	//��
	//for (i = 0; i < col; i++) {
	//	if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
	//		return board[0][i];
	//	}
	//}
	for (i = 0; i < col; i++) {
		count = 0;
		for (j = 0; j < row - 1; j++) {
			if (board[j][i] == board[j+1][i] && board[j][i] != ' ') {
				count++;
			}
			else
			{
				break;
			}
			//if (count == row - 1) {
			//	return board[0][i];
			//}
		}
		if (count == row - 1) {
			return board[0][i];
		}
	}
	 
	//�Խ���
	//if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
	//	return board[0][0];
	//}
	//if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ') {
	//	return board[1][1];
	//}
	
	//�ֱ��ж������Խ���
	int count1 = 0;
	for (i = 0; i < row-1; i++) {
		//count = 0;
		if ((board[i][i] == board[i + 1][i + 1])&&(board[0][0]!=' ')) {//ѭ���жϵ�һ���Խ��� �����ͬ�������ۼ� ����ͬ������ѭ��
			count1++;
		}
		else
		{
			break;
		}
		//if (count1 == row - 1) {//����ʱ ��һ���Խ���������Ԫ����ͬ ��Ϸ���� ����ʤ������ count�ﲻ��row-1����
		//	return board[0][0];
		//}
	}
	if (count1 == row - 1) {//����ʱ ��Ҫ������жϣ��� ��һ���Խ���������Ԫ����ͬ ��Ϸ���� ����ʤ������
		return board[0][0];
	}
	int count2 = 0;
	for (i = 0; i < row - 1; i++) {
		//count = 0;
		if (board[i][row-1-i] == board[i + 1][row-2-i] && board[row-1-i][0] != ' ') {
			count2++;
		}
		else
		{
			break;
		}
		//if (count2 == row - 1) {
		//	return board[row-1][0];
		//}
	}
	if (count2 == row - 1) {
		return board[row - 1][0];
	}
	//�ж�ƽ�� �����Ƿ����� �Ƿ��пո�
	if (IsFull(board,ROW,COL)==1) {
		return 'Q';
	}
	//����ƽ��
	return 'C';
}