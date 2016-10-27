#include <stdio.h>

int count = 0;

int notDanger(int row, int col, char (*chese)[8])
{
	
	//printf("not danger,row:%d, col:%d\n",row,col);
	int i,j;
	
	// 判断列
	for(i = 0; i < row; i++)
	{
		if(*(*(chese + i) +col) == 1)
		{
			//printf("danger1,row:%d, col:%d\n",row,col);
			return 0;
		}
	}
	
	// 左上方
	for(i = row - 1,j = col - 1; i >= 0 && j >= 0; i--,j--)
	{
		if(*(*(chese + i) +j) == 1)
		{
			//printf("danger2,row:%d, col:%d\n",row,col);
			return 0;
		}
	}
	
	for(i = row - 1,j = col + 1; i >= 0 && j < 8; i--,j++)
	{
		if(*(*(chese + i) +j) == 1)
		{
			//printf("danger3,row:%d, col:%d\n",row,col);
			return 0;
		}
	}
	//printf("not danger,row:%d, col:%d\n",row,col);
	return 1;
}

void eightqueue(int row, int col, char (*chese)[8])
{
	int i,j;
	char cheseTmp[8][8];
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			cheseTmp[i][j] = *(*(chese+i)+j);
		}
	}
	
	if(row == 8)
	{
		//printf("第%d种\n",++count);
		count++;
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < col; j++)
			{
		//		printf("%d ",cheseTmp[i][j]);
			}
		//	printf("\n");
		}
		//printf("\n");
	}
	else
	{
		for(i = 0; i < col; i++)
		{
			if (notDanger(row,i,cheseTmp))
			{
				for(j = 0; j < 8; j++)
				{
					cheseTmp[row][j] = 0;
				}
				//printf("row = %d, col= %d\n",row,i);
				cheseTmp[row][i] = 1;
				
				eightqueue(row+1,col,cheseTmp);
				
			}
		}
	}
}

int main(int argc, char *argv[])
{
	char chese[8][8];
	int i,j;
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			chese[i][j] = 0;
		}
	}
	eightqueue(0,8,chese);
	
	printf("共%d种\n",count);
	
	sleep(10);
	
	return 0;
}