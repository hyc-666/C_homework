#include"chess.h"
int main(){
	srand((unsigned long)time(NULL));
	int quit = 0;
	do{
		menu();//չʾ�˵�������
		int select = 0;
		scanf_s("%d", &select);
		switch (select){
		case 1:
			play_triple();
			
			break;
		case 2:
			printf("��ӭ�´�ʹ�ã�\n");
			quit = 1;
			break;
		default:
			break;
		}
		
	} while (!quit);


	system("pause");
	return 0;
}