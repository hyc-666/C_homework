#include "penta_chess.h"
void menu(){
	int select = 0;
	printf("***********************\n");
	printf("*****   欢迎使用  *****\n");
	printf("***********************\n");
	printf("*****   1.开始    *****\n");
	printf("*****   2.退出    *****\n");
	printf("***********************\n");
	printf("请选择：->");
	
}
void play_penta(){
	char table[ROW][COL];
	int player_xy[2] = { ROW / 2, COL / 2 };
	int pc_xy[2] = { ROW / 2, ROW / 2 };
	init_table(table, ROW, COL);
	int first = one_step();
	char who_win = NEXT;
	//show_table(table, ROW, COL);
	//int player_five = 0;//玩家的五子连珠
	//int pc_five = 0;//电脑的五子连珠
	int goon = 0;
	while (!goon){
		switch (first){
		case 1:
			system("cls");
			show_table(table, ROW, COL);
			to_player(table, ROW, COL, player_xy);
			who_win = judge(table, ROW, COL, player_xy);
			first = 0;
			break;
		case 0:
			to_computer(table, ROW, COL, pc_xy);
			who_win = judge(table, ROW, COL, pc_xy);
			first=1;
			break;
		default:
			break;
		}
		
		switch (who_win){
		case PLAYER:
			show_table(table, ROW, COL);
			printf("恭喜玩家获胜！\n");
			goon = 1;
			break;
		case COMPUTER:
			show_table(table, ROW, COL);
			printf("很遗憾，电脑获胜！\n");
			goon = 1;
			break;
		case NEXT:
			break;
		case FULL:
			printf("和棋\n");
			goon = 1;
			break;
		default:
			break;

		}
	}

}
void init_table(char table[][COL], int row, int col){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			table[i][j] = ' ';
		}
	}
}
void show_table(char table[][COL], int row, int col){
#if 0//固定棋盘的输出
	printf("     1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15|\n");
	printf("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
	for (int i = 1; i <= row; i++){
		printf("%2d | ",i);
		for (int j = 0; j < col; j++){
			printf("%c | ", table[i - 1][j]);
		}
		printf("\n");
		printf("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
	}
#endif
	//自适应棋盘大小
	printf("    ");
	for (int i = 1; i <= row; i++){
		printf("%2d |", i);
	}
	printf("\n");
	for (int i = 0; i < row; i++){
		printf("----");
		for (int j = 0; j < col; j++){
			printf("----");
		}
		printf("\n");
		printf("%2d |", i+1);
		for (int j = 0; j < col;j++){
			printf(" %c |", table[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < row; i++){
		printf("----");
	}
	printf("----\n");
}
int one_step(){
	int first = 0;
	printf(" *1.玩家先   *2.电脑先   *3.猜先\n");
	printf("请选择先后：\n");
	scanf_s("%d", &first);
	switch (first){
	case 1:
		return 1;
		break;
	case 2:
		return 0;
		break;
	case 3:
		printf("猜先结果：");
		int result = rand() % 2;
		if (result){
			printf("玩家先\n");
		}
		else
			printf("电脑先\n");
		return result;
	default:
		break;
	}
	return first;
}
void to_player(char table[][COL], int row, int col,int xy[2]){
	printf("轮到玩家走棋，请输入坐标：");
#if 1
	do{
		int x = 0;
		int y = 0;
		scanf_s("%d %d", &x, &y);
		if (x <= 0 || x > 15 || y <= 0 || y > 15 || table[x-1][y-1] != ' '){
			printf("你输入的坐标有误！请重新输入：");
			continue;
		}
		else{
			table[x - 1][y - 1] = PLAYER;
			xy[0] = x - 1;
			xy[1] = y - 1;
			
			break;
		}
	} while (1);
#endif

#if 0  //为了测试方便和快一点，可以先让两个电脑下
	do{
		int x = rand() % row;
		int y = rand() % col;
		if (table[x][y] == ' '){
			table[x][y] = PLAYER;
			xy[0] = x;
			xy[1] = y;
			printf("%d %d\n", x+1, y+1);
			break;
		}
	} while (1);
#endif

#if 0
	int x = xy[0];
	int y = xy[1];
	int i = x, j = y;
	if (table[i][j] == ' '){
		table[i][j] = PLAYER;
	}
	else{
		i = x - 1;
		j = y - 1;
		do{
			i = x-1 + rand() % 3;
			j = y-1 + rand() % 3;
			if (i < 0 || i >= row || j < 0 || j >= col){
				continue;
			}
			if (table[i][j] == ' '){
				table[i][j] = PLAYER;
				xy[0] = i;
				xy[1] = j;
				break;
			}
		} while (1);
	}
#endif
}
void to_computer(char table[][COL], int row, int col,int xy[2]){
	int noloop = 0;//为了防止电脑出现死循环，标记一个循环次数，
	//循环一次这个数加一，当循环次数过多时则认为此时陷入死循环，这时让它重新回到随机下法
	//因为此变量在函数体内定义，下次走棋时依然会优先智障下法，这个量也会重新计数
	printf("电脑思考中...\n");//电脑假装思考了一下
	Sleep(500);
#if 0//电脑的随机下法
	do{
		int x = rand() % 15;
		int y = rand() % 15;
		if (table[x][y] == ' '){
			table[x][y] = COMPUTER;
			xy[0] = x;
			xy[1] = y;
			printf("电脑的落子位置为：%d %d\n", x + 1, y + 1);
			break;
		}
	} while (1);
#endif
	//电脑的智障下法
	int x = xy[0];
	int y = xy[1];
	int i = x, j = y;
	if (table[i][j] == ' '){//这是棋盘中间的那个点，如果电脑先走就走在这里
		table[i][j] = COMPUTER;
		
	}
	else{//不然就走在这个点周围的8个点的随机一个点上
		//每次走棋都走在上一次走棋的周围8个点的随机一个上
		i = x - 1;
		j = y - 1;
		do{
			i = x-1 + rand() % 3;
			j = y-1 + rand() % 3;
			noloop++;
			if (noloop > 0xfffffff)//这个值要设置的很大
			{
				do{//找随机点
					 i = rand() % row;
					 j = rand() % col;
					if (table[i][j] == ' '){
						table[i][j] = COMPUTER;
						xy[0] = i;
						xy[1] = j;
						//printf("电脑的落子位置为：%d %d\n", x + 1, y + 1);
						break;
					}
				} while (1);
				break;
			}
			if (i < 0 || i >= row || j < 0 || j >= col){//保证这个点周围不会越界
				//但是这个算法很容易向一个方向辐射
				//而且一旦到边边角角的地方周围8个空格被占满则会产生死循环
				continue;
			}
			if (table[i][j] == ' '){
				table[i][j] = COMPUTER;
				xy[0] = i;
				xy[1] = j;
				break;
			}
		} while (1);
		
	}
	printf("电脑的落子位置为：%d %d\n", i+1, j+1);
}
char judge(char table[][COL], int row, int col, int xy[2]) {//这块是核心点
	int x = xy[0];//把上次落子位置拿进来
	int y = xy[1];	
	int i = x;//以这个点为中心
	int j = y;
	int count = 0;
	for (j = y-4; j <= y+4; j++){//从左到右行五个
		if (j<0){
			continue;
		}
		if (j>=col){
			break;
		}
		if (table[i][j] == table[x][y]){
			count++;
			if (count >= 5){
				return table[x][y];
			}
		}
		else{
			count = 0;
			continue;
		}
	}
	i = x;
	j = y;
	count = 0;
	for (i = x-4; i <= x+4; i++){//纵向
		if (i<0){
			continue;
		}
		if (i>=row){
			break;
		}
		if (table[i][j] == table[x][y]){
			count++;
		}
		else{
			count = 0;
			continue;
		}
		if (count >= 5){
			return table[x][y];
		}
	}
	i = x;
	j = y;
	count = 0;
	for (i = x - 4,j=y-4; i <= x + 4 && j<=y+4; i++,j++){//左上到右下
		if (i < 0 || j < 0){
			continue;
		}
		if (i >= row || j>=col){
			break;
		}
		if (table[i][j] == table[x][y]){
			count++;
		}
		else{
			count = 0;
			continue;
		}
		if (count >= 5){
			return table[x][y];
		}
	}
	i = x;
	j = y;
	count = 0;
	for (i = x - 4, j = y + 4; i<=x + 4 && j>=y - 4; i++, j--){//右上到左下
		if (i < 0 || j >= col){
			continue;
		}
		if (i >= row || j < 0){
			break;
		}
		if (table[i][j] == table[x][y]){
			count++;
		}
		else{
			count = 0;
			continue;
		}
		if (count >= 5){
			return table[x][y];
		}
	}
	for (i = 0; i < row; i++){//棋盘未满继续
		for (j = 0; j < col; j++){
			if (table[i][j] == ' '){
				return NEXT;
			}
		}
	}
	return FULL;
}

