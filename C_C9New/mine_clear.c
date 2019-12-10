#include "mine_clear.h"

void menu(){
	printf("##########################\n");
	printf("##   欢迎来到扫雷游戏   ##\n");
	printf("##   1.开始游戏         ##\n");
	printf("##   2.退出             ##\n");
	printf("##########################\n");
	printf("请选择：");
}

void game_start(){
	char mine_table[ROW][COL];//存储雷的信息
	char show_table[ROW][COL];//给玩家看的

	int first = 1;//第一次扫雷
	char count;//一个坐标周围雷的个数
	int success;//通关标志
	memset(mine_table, '0', sizeof(mine_table));//初始化两张表
	memset(show_table, '*', sizeof(show_table));
	set_mine(mine_table, ROW, COL);//埋雷
	do{
		
		system("cls");//清屏
		show(show_table, ROW, COL);//展示给玩家看
		show(mine_table, ROW, COL);//为了方便测试，把雷的那张表也打出来了
		
		int x = 0;//玩家输入的坐标
		int y = 0;
		printf("请开始扫雷<x,y>:");
		scanf_s("%d %d", &x, &y);
		if (x<1 || x>ROW-2 || y<1 || y>COL-2){
			printf("你输入的坐标范围有误，请重新输入<x,y>:");
			continue;
		}
		if (show_table[x][y] != '*'){
			printf("此位置已被排除，请重新输入<x,y>:");
			continue;
		}
		if (mine_table[x][y] == '1'&& first ){//第一次如果踩到雷
			no_min(mine_table,x,y);//把这个雷找一个没雷的位置替换掉，这个没雷的位置也是随机找的
			show_table[x][y] = count_mine(mine_table, x, y);//统计周围信息
			first = 0;//这时候已经不是第一次了
			
		}
		if (mine_table[x][y] == '1'){

			printf("扫雷失败，游戏结束！\n");
			show(mine_table, ROW, COL);
			break;
		}
		if (mine_table[x][y] == '0'){

			first = 0;//第一次只要没踩到，那么第一次扫雷顺利，就不需要第一次扫雷保护
			count = count_mine(mine_table, x, y);//周围雷的个数
			show_table[x][y] = count;//把周围雷的个数写上
			
			open(mine_table, show_table, x, y);//递归展开
		}

		success = win(show_table, ROW, COL);//检测剩余*的数量
	} while (success>MINE_NUM);//*的数量为雷的数量时游戏胜利
	if (success<=MINE_NUM){//如果*的数量不为雷的数量程序是走不到这里的
		printf("恭喜通关！\n");
	}
}
void set_mine(char mine_table[][COL], int row, int col){//埋雷
	int i = 0;
	while (i < MINE_NUM){
		do{
			int x = rand() % (ROW-2) + 1;//雷的位置随机分布
			int y = rand() % (COL-2) + 1;
			if (mine_table[x][y] == '0'){//已埋的地方不再重复计算
				mine_table[x][y] = '1';
				break;
			}
		} while (1);
		i++;
	}
}
void show(char show_table[][COL], int row, int col){//展示两张表，参数不同，展示的表不同
	
	printf("   |");
	for (int i = 1; i <= ROW-2; i++){
		printf("%2d |",i);
	}
	printf("\n----");
	for (int i = 1; i <= ROW - 2; i++){
		printf("----");
	}
	printf("\n");
	for (int i = 1; i <= ROW-2; i++){
		printf("%2d |", i);
		for (int j = 1; j <= COL-2; j++){
			printf(" %c |", show_table[i][j]);
		}
		
		printf("\n");
		for (int j = 0; j <= ROW - 2; j++){
			printf("----");
		}
		printf("\n");

	}
	printf("\n");

}

char count_mine(char mine_table[][COL], int x, int y){//这个函数算出来的是一个字符
	return mine_table[x - 1][y - 1] + mine_table[x - 1][y] + mine_table[x - 1][y + 1] + 
		mine_table[x][y - 1] + mine_table[x][y + 1] + mine_table[x + 1][y - 1] + 
		mine_table[x + 1][y] + mine_table[x + 1][y + 1] - (7 * '0');
}
void open(char mine_table[][COL], char show_table[][COL],int x, int y){//递归展开
	char count = count_mine(mine_table, x, y);
	if (count == '0'){
		show_table[x][y] = ' ';
		if (show_table[x - 1][y - 1] == '*'){//左上
			open(mine_table, show_table, x - 1, y - 1);
		}
		if (show_table[x - 1][y] == '*'){//上
			open(mine_table, show_table, x - 1, y);
		}
		if (show_table[x - 1][y + 1] == '*'){//右上
			open(mine_table, show_table, x - 1, y + 1);
		}
		if (show_table[x][y - 1] == '*'){//左
			open(mine_table, show_table, x, y - 1);
		}
		if (show_table[x][y + 1] == '*'){//右
			open(mine_table, show_table, x, y + 1);
		}
		if (show_table[x+1][y - 1] == '*'){//左下
			open(mine_table, show_table, x+1, y - 1);
		}
		if (show_table[x][y + 1] == '*'){//下
			open(mine_table, show_table, x, y + 1);
		}
		if (show_table[x+1][y + 1] == '*'){//右下
			open(mine_table, show_table, x+1, y + 1);
		}
	}
	if (count > '0'){
		show_table[x][y] = count;
	}
}
void no_min(char mine_table[][COL],int x0, int y0){//找没有雷的一个点
	do{
		int x = rand() % (ROW-2) + 1;
		int y = rand() % (COL-2) + 1;//这个点也是随机找的
		if (mine_table[x][y] == '0'){//找到后替换掉
			mine_table[x][y] = '1';
			mine_table[x0][y0] = '0';
			break;
		}
	} while (1);
}
int win(char show_table[][COL], int row, int col){//用来统计*的个数，要用*的数量来看是否游戏胜利
	int win = 0;
	for (int i = 1; i < row - 1; i++){
		for (int j = 1; j < col - 1; j++){
			if (show_table[i][j] == '*'){
				win++;
			}
		}
	}
	return win;
}