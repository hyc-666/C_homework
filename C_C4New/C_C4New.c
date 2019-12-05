#include<stdio.h>
#include<windows.h>
#include<math.h>
int getRank(int N);//函数声明
int isNar(int n){//判断是否为水仙花
	int s = 0;//计算每个位上的数字的立方和以和原数字比较
	int t = 0;//记录每个位上的数字
	int x = n;//传值用于计算，使原值计算后不被破坏
	while (x != 0){//原值会被一直除10，直到0，这是循环条件
		t = x % 10;//依次是个位数，然后是百位数...
		x = x / 10;//原值去掉个位除10
		s += (int)pow(t, getRank(n));//各个位上的立方和
	}
	return (n == s);//直接返回两数是否相等
	

	//int b = x / 100;//百位上的数字
	//int s = (x / 10) % 10;//十位上的数字
	//int g = x % 10;//个位上的数字
	//if (x == pow(b, 3) + pow(s, 3) + pow(g, 3)){
	//	return 1;
	//}
	//return 0;
}
int getRank(int N){//计算这是一个几位数
	int count = 0;
	while (N){
		count++;
		N = N / 10;
	}
	return count;
}
int main(){
	//int m = 1;//每行打印的*数量
	//for (int i = 1; i <= 7; i++){//前7行
	//	
	//	for (int j = 1; j <= m; j++){//每行打印的*
	//		printf("*");
	//	}
	//	printf("  %d", m);
	//	m += 2;
	//	//printf("  %d",m);
	//	printf("\n");
	//}
	//m -= 4;
	//for (int i = 1; i <= 6; i++){//后6行
	//	for (int j = m; j >= 1; j--){
	//		printf("*");
	//	}
	//	printf("  %d", m);
	//	m -= 2;
	//	//printf("  %d", m);
	//	printf("\n");
	//}



	//int i = 1;//一共13行
	//int n = 1;//每行打印的*是变化的，且先增后减，确定增减
	//int m = 1;//每行的*数
	////m = m + n * 2;//每行的*的数量的递增规律
	//for (; i <= 13; i++){  //13行，循环13次
	//	if (i == 7){//第7行以后每行的*的数量递减
	//		n = -n;//递增变递减
	//	}
	//	for (int j = 1; j <= m; j++){//每行打印的*数
	//		printf("*");
	//	}
	//	//printf("  %d", m);
	//	printf("\n");//打印完一行后换行，也就是外循环一次换一行
	//	m += n * 2;//每行*的数量的增长规律
	//}


	int i = 0;
	for (; i <= 1000; i++){
		if (isNar(i)){//直接调函数，是水仙花数就打印
			printf("%d  ", i);
		}
	}

	//计算形如 a + aa+aaa+aaaa+aaaaa,,,
	//int a = 0;//首项
	//int sum = 0;//前n项和
	//printf("Enter a = ");
	//scanf_s("%d",&a);//输入a
	//int b = a;//后面的计算要在后边加a，a的值要保存起来，用b代替a参与循环计算
	//for (int i = 1; i <= 5; i++){//计算前5项
	//	sum += b;//前n项和
	//	b = b * 10 + a;//项与项之间的关系
	//}
	//printf("sum = %d\n",sum);//输出结果 


	printf("\n");
	system("pause");
	return 0;
}