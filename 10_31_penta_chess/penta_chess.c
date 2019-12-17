#include "penta_chess.h"
void menu(){
	int select = 0;
	printf("***********************\n");
	printf("*****   ��ӭʹ��  *****\n");
	printf("***********************\n");
	printf("*****   1.��ʼ    *****\n");
	printf("*****   2.�˳�    *****\n");
	printf("***********************\n");
	printf("��ѡ��->");
	
}
void play_penta(){
	char table[ROW][COL];
	int player_xy[2] = { ROW / 2, COL / 2 };
	int pc_xy[2] = { ROW / 2, ROW / 2 };
	init_table(table, ROW, COL);
	int first = one_step();
	char who_win = NEXT;
	//show_table(table, ROW, COL);
	//int player_five = 0;//��ҵ���������
	//int pc_five = 0;//���Ե���������
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
			printf("��ϲ��һ�ʤ��\n");
			goon = 1;
			break;
		case COMPUTER:
			show_table(table, ROW, COL);
			printf("���ź������Ի�ʤ��\n");
			goon = 1;
			break;
		case NEXT:
			break;
		case FULL:
			printf("����\n");
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
#if 0//�̶����̵����
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
	//����Ӧ���̴�С
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
	printf(" *1.�����   *2.������   *3.����\n");
	printf("��ѡ���Ⱥ�\n");
	scanf_s("%d", &first);
	switch (first){
	case 1:
		return 1;
		break;
	case 2:
		return 0;
		break;
	case 3:
		printf("���Ƚ����");
		int result = rand() % 2;
		if (result){
			printf("�����\n");
		}
		else
			printf("������\n");
		return result;
	default:
		break;
	}
	return first;
}
void to_player(char table[][COL], int row, int col,int xy[2]){
	printf("�ֵ�������壬���������꣺");
#if 1
	do{
		int x = 0;
		int y = 0;
		scanf_s("%d %d", &x, &y);
		if (x <= 0 || x > 15 || y <= 0 || y > 15 || table[x-1][y-1] != ' '){
			printf("������������������������룺");
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

#if 0  //Ϊ�˲��Է���Ϳ�һ�㣬������������������
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
	int noloop = 0;//Ϊ�˷�ֹ���Գ�����ѭ�������һ��ѭ��������
	//ѭ��һ���������һ����ѭ����������ʱ����Ϊ��ʱ������ѭ������ʱ�������»ص�����·�
	//��Ϊ�˱����ں������ڶ��壬�´�����ʱ��Ȼ�����������·��������Ҳ�����¼���
	printf("����˼����...\n");//���Լ�װ˼����һ��
	Sleep(500);
#if 0//���Ե�����·�
	do{
		int x = rand() % 15;
		int y = rand() % 15;
		if (table[x][y] == ' '){
			table[x][y] = COMPUTER;
			xy[0] = x;
			xy[1] = y;
			printf("���Ե�����λ��Ϊ��%d %d\n", x + 1, y + 1);
			break;
		}
	} while (1);
#endif
	//���Ե������·�
	int x = xy[0];
	int y = xy[1];
	int i = x, j = y;
	if (table[i][j] == ' '){//���������м���Ǹ��㣬����������߾���������
		table[i][j] = COMPUTER;
		
	}
	else{//��Ȼ�������������Χ��8��������һ������
		//ÿ�����嶼������һ���������Χ8��������һ����
		i = x - 1;
		j = y - 1;
		do{
			i = x-1 + rand() % 3;
			j = y-1 + rand() % 3;
			noloop++;
			if (noloop > 0xfffffff)//���ֵҪ���õĺܴ�
			{
				do{//�������
					 i = rand() % row;
					 j = rand() % col;
					if (table[i][j] == ' '){
						table[i][j] = COMPUTER;
						xy[0] = i;
						xy[1] = j;
						//printf("���Ե�����λ��Ϊ��%d %d\n", x + 1, y + 1);
						break;
					}
				} while (1);
				break;
			}
			if (i < 0 || i >= row || j < 0 || j >= col){//��֤�������Χ����Խ��
				//��������㷨��������һ���������
				//����һ�����߽߱ǽǵĵط���Χ8���ո�ռ����������ѭ��
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
	printf("���Ե�����λ��Ϊ��%d %d\n", i+1, j+1);
}
char judge(char table[][COL], int row, int col, int xy[2]) {//����Ǻ��ĵ�
	int x = xy[0];//���ϴ�����λ���ý���
	int y = xy[1];	
	int i = x;//�������Ϊ����
	int j = y;
	int count = 0;
	for (j = y-4; j <= y+4; j++){//�����������
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
	for (i = x-4; i <= x+4; i++){//����
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
	for (i = x - 4,j=y-4; i <= x + 4 && j<=y+4; i++,j++){//���ϵ�����
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
	for (i = x - 4, j = y + 4; i<=x + 4 && j>=y - 4; i++, j--){//���ϵ�����
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
	for (i = 0; i < row; i++){//����δ������
		for (j = 0; j < col; j++){
			if (table[i][j] == ' '){
				return NEXT;
			}
		}
	}
	return FULL;
}

