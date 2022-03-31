#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int  press[6][8], puzzle[6][8];

void enumerate()
{
	int guess(void);
	int row, column;
	for (row = 0; row < 6; row++)
	{
		press[row][0] = 0;
		press[row][7] = 0;
	}
	for (column = 1; column < 7; column++)
	{
		press[0][column] = 0;
		press[1][column] = 0;
	}
	while (guess() == 0)
	{
		press[1][1]++;
		column = 1;
		while (press[1][column] > 1)
		{
			press[1][column] = 0;
			column++;
			press[1][column]++;

		}
	}

}
int guess()
{
	int row, column;
	for (row = 1; row < 5; row++)
	{
		for (column = 1; column <= 6; column++)
		{
			press[row + 1][column] =( puzzle[row][column] + press[row][column] + press[row - 1][column] +  press[row][column - 1] + press[row][column + 1])%2;
		}
	}
	for (column = 1; column < 7; column++)//������һ���Ƿ�ȫ��Ϩ��
	{
		if ((press[5][column - 1] + press[5][column] + press[5][column + 1] + press[4][column]) % 2 != puzzle[5][column])//���Ŀ��Ƹ����İ�ť���ú����ս�����״̬����ȣ���ƻᱻ�����������ƥ�䷵��0
		{
			return 0;
		}
	}

	return 1;
}
int main()
{
	int row, column, cases, c;//cases ΪҪ����İ�������
	void enumerate(void);

	for (row = 1; row < 6; row++)
		for (column = 1; column < 7; column++)//��ȡ���룬scanf���Զ����Իس������Կ���һ��һ�����룬ע��� �� ��
		{
			scanf("%d,", &puzzle[row][column]);
		}//��ʱpuzzle�Ѿ���ֵ���
	printf("\n");
	enumerate();
	//for (row = 1; row < 6; row++) {
	//	for (column = 1; column < 7; column++) {
	//		printf("%d ", puzzle[row][column]);
	//	}
	//}
		for (row = 1; row < 6; row++) {
			for (column = 1; column < 7; column++) {
				printf("%d ", press[row][column]);
			}	printf("\n");

		}
	return 0;
}