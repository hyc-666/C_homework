#include "mine_clear.h"
int main(){
	srand((unsigned long)time(NULL));
	int quit = 0;
	int select = 0;
	while (!quit){
		menu();
		scanf_s("%d", &select);
		switch (select){
		case 1:
			game_start();
			printf("还要继续吗？  0：退出  1：继续\n");
			int go = 0;
			scanf_s("%d", &go);
			switch (go){
			case 0:
				quit = 1;
				break;
			case 1:
				break;
			default:
				break;
			}
			break;
		case 2:
			quit = 1;
			break;
		default:
			break;

		}
		
	}
	printf("欢迎下次再玩！\n");
	system("pause");
	return 0;
}