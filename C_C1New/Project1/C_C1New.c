#include<stdio.h>
#include<windows.h>
#include<math.h>

/*1. 打印100~200之间的素数*/
int isPrime(int n){
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0){
			return 0;
		}
	}
	return 1;
}

/*2. 输出乘法口诀表*/
void mutal_table(int n){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			printf("%2d *%2d = %2d  ", j,i, j*i);
		}
		printf("\n");
	}
}

/*3. 判断1000年-- - 2000年之间的闰年*/
int isLeapyear(int year){//四年一润且百年不润，四百年一润
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		return 1;
	}
	return 0;
}
int main(){

	for (int i = 100; i <= 200; i++){
		if (isPrime(i)){
			printf("%d ",i);
		}
	}

	printf("\n");
	mutal_table(9);
	printf("\n");
	for (int i = 1000; i <= 2000; i++){
		if (isLeapyear(i)){
			printf("%d ", i);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}






