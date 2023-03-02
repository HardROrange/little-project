#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<conio.h>

/*数据分析
	1、定义一个4*4的int类型的二维数组 全局变量 
	2、定义一个记录得分的变量 全局变量 
业务分析：
	while(1)
	for(;;)
	{
		1、随机位置产生一个2
		void rand_two(void);
		2、显示界面
		void show_view(void)
		---------------------
		---------------------
		---------------------
		---------------------
		---------------------
		3、获取方向键并对应处理（移动、合并、加分）
		void up(void);
		4、判断是否游戏结束
		是：结束程序 return 0;
		bool is_die(void);
	*/ 
	
//函数声明 
	void rand_two(void);
	void show_view(void);
	void up(void);
	void down(void);
	void left(void);
	void right(void);
	bool is_die(void); 
	bool is_full(void);//判断二维数组是否还有空位置 
	
//定义一个4*4的int类型的二维数组 全局变量 
int view[4][4]={};
//定义一个记录得分的变量 全局变量 
int score=0;
//3、记录是否发生移动或合并的标志变量
bool is_move_merge = true; 

int flag =0;

int main(){
	for(;;){
		rand_two();
		/*system("cls");*/
		show_view();
		int dir = getch();
		is_move_merge=false;
		if(72 == dir){
			up();
		}
		else if(80 == dir) {
			down();
		}
		else if(75 == dir){
			left();
		}
		else if(77 == dir){
			right();
		}
		if(is_die()){
			show_view();
			printf("你输了！");
			return 0;
		}
		if(flag){
			show_view();
			printf("巨肥赢了！");
			return 0;
			
		}
		
	}
}
	
void rand_two(void)
{
	srand(time(NULL));
 if(is_full())	return;
 for(;is_move_merge;)
 {
 	int x = rand()%4;
	int y = rand()%4;
	if(0==view[x][y]){
		if(1==rand()%10){
			view[x][y]=4;
			return; 
		}
		else{
		view[x][y]=2;
		return;
		}
		
	}
 }
}
 
	
	
	/*for(int i=0;i<flag;i++){
		if(view[x][y]==0){
	view[x][y] = 2;
	}
	else {
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(view[i][j]!=0){
					f2++;
				}
			}
		}
		flag++;
	if(f2<16)
	{
		f2=0;
	}
	
	if(f2==16){
			break;
		}	
	}
	}*/
	
void show_view(void)
{
	system("cls");
	for(int i=0;i<4;i++){
		printf("---------------------\n");
		for(int j=0;j<4;j++){
			if(view[i][j]){
				printf("|%4d",view[i][j]);
			}
			else{
				printf("|    ");
			}
		}
		printf("|\n");
	}
	printf("---------------------\n");
	printf("SCORE:%d\n",score);
	/*for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				printf("%d ",view[i][j]);
	}
	printf("\n");	
		}*/
}
void up(void)
{
		
	for(int j=0;j<4;j++)
	{
		int end = 0;
		for(int i=1;i<4;i++){
				for(int a=i;a>end;a--){
			if(view[a][j]==view[a-1][j]&&(view[a][j]!=0)){
				view[a-1][j]=2*view[a-1][j];
				view[a][j]=0;
				end=a;
				score+=view[a-1][j];
				if(view[a-1][j]==2048){
					flag=1;
				}
				is_move_merge=true;
		}
			else if((view[a-1][j]==0)&&(view[a][j]!=0)){
			view[a-1][j]=view[a][j];
			view[a][j]=0;	
			is_move_merge=true;
			}
		}
		
	}
}
	
}

void down(void)
{
	for(int j=0;j<4;j++)
	{
		int end = 3;
		for(int i=2;i>=0;i--){
				for(int a=i;a<end;a++){
			if(view[a][j]==view[a+1][j]&&(view[a][j]!=0)){
				view[a+1][j]=2*view[a+1][j];
				view[a][j]=0;
				end=a;
				is_move_merge=true;
				if(view[a+1][j]==2048){
					flag=1;
				}
				score+=view[a+1][j];
		}
			else if((view[a+1][j]==0)&&(view[a][j]!=0)){
			view[a+1][j]=view[a][j];
			view[a][j]=0;	
			is_move_merge=true;
			}
		}
		
	}
}
}
void left(void)
{
		for(int i=0;i<4;i++)
	{
		int end = 0;
		for(int j=1;j<4;j++){
				for(int a=j;a>end;a--){
			if(view[i][a]==view[i][a-1]&&(view[i][a-1]!=0)){
				view[i][a-1]=2*view[i][a-1];
				view[i][a]=0;
				end=a;
				score+=view[i][a-1];
				if(view[i][a-1]==2048){
					flag=1;
				}
				is_move_merge=true;
		}
			else if((view[i][a-1]==0)&&(view[i][a]!=0)){
			view[i][a-1]=view[i][a];
			view[i][a]=0;	
			is_move_merge=true;
			}
		}
		
	}
}
}

void right(void)
{
	for(int j=0;j<4;j++)
	{
		int end = 3;
		for(int i=2;i>=0;i--){
				for(int a=i;a<end;a++){
			if(view[j][a]==view[j][a+1]&&(view[j][a]!=0)){
				view[j][a+1]=2*view[j][a+1];
				view[j][a]=0;
				end=a;
				is_move_merge=true;
					if(view[j][a+1]==2048){
					flag=1;
				}
				score+=view[j][a+1];
		}
			else if((view[j][a+1]==0)&&(view[j][a]!=0)){
			view[j][a+1]=view[j][a];
			view[j][a]=0;	
			is_move_merge=true;
			}
		}
		
	}
}
}

bool is_die()
{
	if(!is_full())
	{
		return false;
	}
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(view[i][j]==view[i][j+1])
			{
				return false;
			}
		
			
		}
	}
		for(int j=0;j<4;j++)
	{
		for(int i=0;i<3;i++)
		{
			if(view[i][j]==view[i+1][j])
			{
				return false;
			}
		}
	}
	return true;
}
bool is_full(void)
{
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++){
			if(0 == view[i][j]){
				return false;
			}
		}
	}
	return true;
}

		 	




