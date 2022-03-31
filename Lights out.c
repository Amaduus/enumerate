#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

const int N = 6;
char arr[6][6],brr[6][6];
int dx[] = { -1,1,0,0,0 }, dy[] = { 0,0,-1,1,0 };

int min(int a, int b)
{
	return a > b ? b : a;
}
void black_out(int x,int y,char arr[][6])
{
	for (int i = 0; i < 5; i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a >= 5|| b < 0 || b >= 5) continue;

		arr[a][b] ^= 1;   //异或，不同的时候就变成相反的数	}
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	 while (n--)
	{
		for (int i = 0; i < 5;i++)
		{
			scanf("%s", arr[i]);
		}
		printf("\n");
		int res = 10;
		for (int j = 0; j < 32; j++)
		{
			
			int step=0;

			memcpy(brr, arr, sizeof(arr));
			for (int o = 0; o < 5; o++)
			{
				if (j >> o & 1)
				{
					step++;
					black_out(0,o,arr);
				}
			}//枚举第一行
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (arr[i][j] == '0') { black_out(i + 1, j, arr); step++; }
					
				}
			}
			bool dark = false;
			for (int j = 0; j < 5; j++)
			{
				if (arr[4][j]=='0')
				{
					dark = true;
					break;
				}
			}
			if (!dark)  res = min(res, step);
			memcpy(arr, brr, sizeof(arr));
		}
		if (res > 6) res = -1;
		printf("%d", res);
	}
	

	return 0;
}
