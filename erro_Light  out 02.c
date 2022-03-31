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
	for (column = 1; column < 7; column++)//检查最后一行是否全部熄灭
	{
		if ((press[5][column - 1] + press[5][column] + press[5][column + 1] + press[4][column]) % 2 != puzzle[5][column])//如果目标灯附近的按钮作用后最终结果与灯状态不相等，则灯会被点亮，会错误匹配返回0
		{
			return 0;
		}
	}

	return 1;
}
int main()
{
	int row, column, cases, c;//cases 为要解决的案例个数
	void enumerate(void);

	for (row = 1; row < 6; row++)
		for (column = 1; column < 7; column++)//获取输入，scanf会自动忽略回车，所以可以一行一行输入，注意加 ， 号
		{
			scanf("%d,", &puzzle[row][column]);
		}//此时puzzle已经赋值完毕
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