#include "mine_clear.h"

void menu(){
	printf("##########################\n");
	printf("##   ��ӭ����ɨ����Ϸ   ##\n");
	printf("##   1.��ʼ��Ϸ         ##\n");
	printf("##   2.�˳�             ##\n");
	printf("##########################\n");
	printf("��ѡ��");
}

void game_start(){
	char mine_table[ROW][COL];//�洢�׵���Ϣ
	char show_table[ROW][COL];//����ҿ���

	int first = 1;//��һ��ɨ��
	char count;//һ��������Χ�׵ĸ���
	int success;//ͨ�ر�־
	memset(mine_table, '0', sizeof(mine_table));//��ʼ�����ű�
	memset(show_table, '*', sizeof(show_table));
	set_mine(mine_table, ROW, COL);//����
	do{
		
		system("cls");//����
		show(show_table, ROW, COL);//չʾ����ҿ�
		show(mine_table, ROW, COL);//Ϊ�˷�����ԣ����׵����ű�Ҳ�������
		
		int x = 0;//������������
		int y = 0;
		printf("�뿪ʼɨ��<x,y>:");
		scanf_s("%d %d", &x, &y);
		if (x<1 || x>ROW-2 || y<1 || y>COL-2){
			printf("����������귶Χ��������������<x,y>:");
			continue;
		}
		if (show_table[x][y] != '*'){
			printf("��λ���ѱ��ų�������������<x,y>:");
			continue;
		}
		if (mine_table[x][y] == '1'&& first ){//��һ������ȵ���
			no_min(mine_table,x,y);//���������һ��û�׵�λ���滻�������û�׵�λ��Ҳ������ҵ�
			show_table[x][y] = count_mine(mine_table, x, y);//ͳ����Χ��Ϣ
			first = 0;//��ʱ���Ѿ����ǵ�һ����
			
		}
		if (mine_table[x][y] == '1'){

			printf("ɨ��ʧ�ܣ���Ϸ������\n");
			show(mine_table, ROW, COL);
			break;
		}
		if (mine_table[x][y] == '0'){

			first = 0;//��һ��ֻҪû�ȵ�����ô��һ��ɨ��˳�����Ͳ���Ҫ��һ��ɨ�ױ���
			count = count_mine(mine_table, x, y);//��Χ�׵ĸ���
			show_table[x][y] = count;//����Χ�׵ĸ���д��
			
			open(mine_table, show_table, x, y);//�ݹ�չ��
		}

		success = win(show_table, ROW, COL);//���ʣ��*������
	} while (success>MINE_NUM);//*������Ϊ�׵�����ʱ��Ϸʤ��
	if (success<=MINE_NUM){//���*��������Ϊ�׵������������߲��������
		printf("��ϲͨ�أ�\n");
	}
}
void set_mine(char mine_table[][COL], int row, int col){//����
	int i = 0;
	while (i < MINE_NUM){
		do{
			int x = rand() % (ROW-2) + 1;//�׵�λ������ֲ�
			int y = rand() % (COL-2) + 1;
			if (mine_table[x][y] == '0'){//����ĵط������ظ�����
				mine_table[x][y] = '1';
				break;
			}
		} while (1);
		i++;
	}
}
void show(char show_table[][COL], int row, int col){//չʾ���ű�������ͬ��չʾ�ı�ͬ
	
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

char count_mine(char mine_table[][COL], int x, int y){//����������������һ���ַ�
	return mine_table[x - 1][y - 1] + mine_table[x - 1][y] + mine_table[x - 1][y + 1] + 
		mine_table[x][y - 1] + mine_table[x][y + 1] + mine_table[x + 1][y - 1] + 
		mine_table[x + 1][y] + mine_table[x + 1][y + 1] - (7 * '0');
}
void open(char mine_table[][COL], char show_table[][COL],int x, int y){//�ݹ�չ��
	char count = count_mine(mine_table, x, y);
	if (count == '0'){
		show_table[x][y] = ' ';
		if (show_table[x - 1][y - 1] == '*'){//����
			open(mine_table, show_table, x - 1, y - 1);
		}
		if (show_table[x - 1][y] == '*'){//��
			open(mine_table, show_table, x - 1, y);
		}
		if (show_table[x - 1][y + 1] == '*'){//����
			open(mine_table, show_table, x - 1, y + 1);
		}
		if (show_table[x][y - 1] == '*'){//��
			open(mine_table, show_table, x, y - 1);
		}
		if (show_table[x][y + 1] == '*'){//��
			open(mine_table, show_table, x, y + 1);
		}
		if (show_table[x+1][y - 1] == '*'){//����
			open(mine_table, show_table, x+1, y - 1);
		}
		if (show_table[x][y + 1] == '*'){//��
			open(mine_table, show_table, x, y + 1);
		}
		if (show_table[x+1][y + 1] == '*'){//����
			open(mine_table, show_table, x+1, y + 1);
		}
	}
	if (count > '0'){
		show_table[x][y] = count;
	}
}
void no_min(char mine_table[][COL],int x0, int y0){//��û���׵�һ����
	do{
		int x = rand() % (ROW-2) + 1;
		int y = rand() % (COL-2) + 1;//�����Ҳ������ҵ�
		if (mine_table[x][y] == '0'){//�ҵ����滻��
			mine_table[x][y] = '1';
			mine_table[x0][y0] = '0';
			break;
		}
	} while (1);
}
int win(char show_table[][COL], int row, int col){//����ͳ��*�ĸ�����Ҫ��*�����������Ƿ���Ϸʤ��
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