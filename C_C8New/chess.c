#include"chess.h"
void menu(){
	printf("***********************\n");
	printf("*****   欢迎使用  *****\n");
	printf("***********************\n");
	printf("*****   1.开始    *****\n");
	printf("*****   2.退出    *****\n");
	printf("***********************\n");
	printf("请选择：->");
}
void init_board(char board[][COL], int row, int col){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			board[j][i] = ' ';//初始棋盘全部置空（空格）
		}
	}
}
void play_triple(){
	char board[ROW][COL];//棋盘
	int first = one_step();
	init_board(board, ROW, COL);//清空棋盘
	char who_win = NEXT;//胜负标志
	do{
		system("cls");
		show_board(board, ROW, COL);//显示棋盘
		switch (first){
		case 1:
			to_player1(board, ROW, COL);//玩家走棋
				//show_board(board, ROW, COL);//显示棋盘
				//who_win = judge(board, ROW, COL);//判断
			first = 0;
				break;
		case 0:
			to_computer(board, ROW, COL);//电脑走棋
				//show_board(board, ROW, COL);//显示棋盘
				//who_win = judge(board, ROW, COL);//判断
			first = 1;
			break;
		default:
			break;
		}
		show_board(board, ROW, COL);//显示棋盘
		who_win = judge(board, ROW, COL);//判断
		if (who_win == PLAYER1){
			printf("恭喜你获胜！\n");
			break;
		}
		if (who_win == COMPUTER){
			printf("很遗憾，你输了！\n");
			break;
		}
		if (who_win == FULL){
			printf("和棋!\n");
			break;
		}

	} while (1);
}
void show_board(char board[][COL], int row, int col){
	
	printf("     1 | 2 | 3 \n");
	printf("----------------\n");
	for (int i = 1; i <= row; i++){
		printf(" %d | ", i);
		for (int j = 0; j < col; j++){
			printf("%c | ", board[i-1][j]);
		}
		printf("\n----------------\n");

	}
}
void to_player1(char board[][COL], int row, int col){
	printf("轮到玩家走棋（输入坐标）#：");
	int x = 0;
	int y = 0;
	do{
		scanf_s("%d %d", &x, &y);
		if (x <= 0 || x > 3 || y <= 0 || y > 3||board[x-1][y-1] !=' '){
			printf("坐标输入有误，请重新输入#：");
			continue;
		}
		else{
			board[x - 1][y - 1] = PLAYER1;
			break;
		}
			
	} while (1);
}
void to_computer(char board[][COL], int row, int col){
	
	printf("电脑思考中...\n");
	Sleep(1200);
	if (board[1][1] == ' '){
		board[1][1] = COMPUTER;
	}
	else{
		while (1){
			int x = rand() % 3;
			int y = rand() % 3;
			if (board[x][y] == ' '){
				board[x][y] = COMPUTER;
				break;
			}
		}
	}
}
char judge(char board[][COL],int row,int col){
	for (int i = 0; i < row; i++){
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][2] == board[i][1]){
			return board[i][1];
		}	
	}
	for (int i = 0; i < col; i++){
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			return board[1][i];
		}
	}
	if ((board[1][1] != ' ' && board[1][1] == board[0][0] && \
		board[1][1] == board[2][2]) || \
		(board[1][1] != ' '&& board[1][1] == board[0][2] && \
		board[1][1] == board[2][0])){
			return board[1][1];
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (board[i][j] == ' '){
				return NEXT;
			}
		}
	}
	return FULL;
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
}