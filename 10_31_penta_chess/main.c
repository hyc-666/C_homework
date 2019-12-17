#include "penta_chess.h"
int main(){
	srand((unsigned long)time(NULL));
	int quit = 0;
	int select = 0;
	
	while (!quit){
		menu();
		scanf_s("%d", &select);
		switch (select){
		case 2:
			quit = 1;
			printf("ллʹ�ã�\n");
			break;
		case 1:
			play_penta();
			
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}