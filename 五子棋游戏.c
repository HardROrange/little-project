#include<stdio.h>
#include<stdlib.h>

//空位置为0 黑棋为1 白棋为2 
void place(void);//棋盘 
int map[15][15]={};

void black(void);//黑棋选手 
int x1=0;
int y3=0;
void white(void);//白棋选手 
int x2=0;
int y2=0;
int whitefinish(void);//五子连珠
int blackfinish(void); 

int main (void)
{
	while(1)
	{
		place(); 
		white();
		if(whitefinish())
		{
			place();
			printf("白棋胜利！\n");
			return 0; 
		}
		place();
		black();
		if(blackfinish())
		{
			place();
			printf("黑棋胜利！\n");
			return 0; 
		}	
	}
}

void place(void)
{
	system("cls");
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(0==map[i][j])
			 {
				printf("* ");
			 }
			 if(1==map[i][j])
			 {
				printf("@ ");
			 }
			 if(2==map[i][j])
			 {
				printf("$ ");
			 }
		}
		printf("\n");
	}
}

void black(void)
{
	int flag = 1;
	printf("请黑棋落子\n");
	while(flag)
	{
		scanf("%d%d",&x1,&y3);//输入落子位置
		if(x1>15||y3>15||(2==map[x1-1][y3-1])||(3==map[x1-1][y3-1]))
		{
			printf("您落子的位置非法，请重新输入\n");
			flag = 1; 
		}
		else
		{
			map[x1-1][y3-1]=1;
			flag = 0;
		}
	}
}

void white(void)
{
	int flag = 1;
	printf("请白棋落子\n");
	while(flag)
	{
		scanf("%d%d",&x2,&y2);//输入落子位置
		if(x2>15||y2>15||(3==map[x2-1][y2-1])||(2==map[x2-1][y2-1]))
		{
			printf("您落子的位置非法，请重新输入\n");
			flag = 1; 
		}
		else
		{
			map[x2-1][y2-1]=2;
			flag = 0;
		}
	}
}

int whitefinish(void)
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<11;j++)//横着五子 
		{
			if(map[i][j]==map[i][j+1]&&map[i][j]==map[i][j+2]&&map[i][j]==map[i][j+3]&&map[i][j]==map[i][j+4]&&map[i][j]==2)
			{
				return 1; 
			}
		} 
	}
	for(int j=0;j<15;j++)
	{
		for(int i=0;i<11;i++)//竖着五子 
		{
			if( map[i][j]== map[i+1][j]&& map[i+1][j]== map[i+2][j]&& map[i+2][j]== map[i+3][j]&& map[i+3][j]== map[i+4][j]&&map[i][j]==2)
			{
				return 1;
			}
		}
    }
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)//右上斜着五子 
		{
			if( map[i][j]== map[i+1][j+1]&& map[i][j]== map[i+2][j+2]&& map[i][j]== map[i+3][j+3]&& map[i+4][j+4]== map[i][j]&&map[i][j]==2)
			{
				return 1;
			}
		}
	}
	for(int i=4;i<15;i++)
	{
		for(int j=4;j<15;j++)//右下斜着五子 
		{
			if( map[i][j]== map[i-1][j-1]&& map[i][j]== map[i-2][j-2]&& map[i][j]== map[i-3][j-3]&& map[i-4][j-4]== map[i][j]&&map[i][j]==2)
			{
				return 1;
			}
		}
	}
	for(int i=0;i<11;i++)
	{
		for(int j=4;j<15;j++)//左上斜着五子 
		{
			if( map[i][j]== map[i+1][j-1]&& map[i][j]== map[i+2][j-2]&& map[i][j]== map[i+3][j-3]&& map[i+4][j-4]== map[i][j]&&map[i][j]==2)
			{
				return 1;
			}
		}
	}
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<11;j++)//左下斜着五子 
		{
			if( map[i][j]== map[i+1][j-1]&& map[i][j]== map[i+2][j-2]&& map[i][j]== map[i+3][j-3]&& map[i][j]== map[i+4][j-4]&&map[i][j]==2)
			{
				return 1; 
			}
		} 
	}
	return 0;	 
}

int blackfinish(void)
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<11;j++)//横着五子 
		{
			if( map[i][j]== map[i][j+1]&& map[i][j]== map[i][j+2]&& map[i][j]== map[i][j+3]&& map[i][j]== map[i][j+4]&&map[i][j]==1)
			{
				return 1; 
			}
		} 
	}
	for(int j=0;j<15;j++)
	{
		for(int i=0;i<11;i++)//竖着五子 
		{
			if( map[i][j]== map[i+1][j]&& map[i+1][j]== map[i+2][j]&& map[i+2][j]== map[i+3][j]&& map[i+3][j]== map[i+4][j]&&map[i][j]==1)
			{
				return 1;
			}
		}
    }
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)//右上斜着五子 
		{
			if( map[i][j]== map[i+1][j+1]&& map[i][j]== map[i+2][j+2]&& map[i][j]== map[i+3][j+3]&& map[i+4][j+4]== map[i][j]&&map[i][j]==1)
			{
				return 1;
			}
		}
	}
	for(int i=4;i<15;i++)
	{
		for(int j=4;j<15;j++)//右下斜着五子 
		{
			if( map[i][j]== map[i-1][j-1]&& map[i][j]== map[i-2][j-2]&& map[i][j]== map[i-3][j-3]&& map[i-4][j-4]== map[i][j]&&map[i][j]==1)
			{
				return 1;
			}
		}
	}
	for(int i=0;i<11;i++)
	{
		for(int j=4;j<15;j++)//左上斜着五子 
		{
			if( map[i][j]== map[i+1][j-1]&& map[i][j]== map[i+2][j-2]&& map[i][j]== map[i+3][j-3]&& map[i+4][j-4]== map[i][j]&&map[i][j]==1)
			{
				return 1;
			}
		}
	}
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<11;j++)//左下斜着五子 
		{
			if( map[i][j]== map[i+1][j-1]&& map[i][j]== map[i+2][j-2]&& map[i][j]== map[i+3][j-3]&& map[i][j]== map[i+4][j-4]&&map[i][j]==1)
			{
				return 1; 
			}
		} 
	}
	return 0;	 
}









