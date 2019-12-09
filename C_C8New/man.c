#include"chess.h"
int main(){
	srand((unsigned long)time(NULL));
	int quit = 0;
	do{
		menu();//展示菜单主界面
		int select = 0;
		scanf_s("%d", &select);
		switch (select){
		case 1:
			play_triple();
			
			break;
		case 2:
			printf("欢迎下次使用！\n");
			quit = 1;
			break;
		default:
			break;
		}
		
	} while (!quit);


	system("pause");
	return 0;
}