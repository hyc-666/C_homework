#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main(){
	//int arr_1[] = { 1, 2, 3, 4, 5 };//创建并初始化数组1
	//int arr_2[] = { 6, 7, 8, 9, 10 };//创建并初始化数组2
	//printf("arr_1:\n");//打印数组1的内容
	//for(int i = 0; i < 5; i++){
	//	printf("%d ", arr_1[i]);
	//}
	//printf("\narr_2:\n");//打印数组2的内容
	//for (int i = 0; i < 5; i++){
	//	printf("%d ", arr_2[i]);
	//}
	//for (int i = 0; i < 5; i++){//交换算法
	//	int temp = arr_1[i];//临时变量用于存储即将要交换的元素
	//	arr_1[i] = arr_2[i];//下标一致
	//	arr_2[i] = temp;
	//}
	//printf("\nafter\narr_1:\n");//输出交换后的数组1
	//for (int i = 0; i < 5; i++){
	//	printf("%d ", arr_1[i]);
	//}
	//printf("\narr_2:\n");//输出交换后的数组2
	//for (int i = 0; i < 5; i++){
	//	printf("%d ", arr_2[i]);
	//}

	

	//float sum = 0.0;//存储结果
	//float n = 1.0;
	//float i = 1.0;//符号的变化
	//int m = 1;//浮点数不是精确的，不能用于判定条件，有可能加不到100，用
	//				//	整数判定
	//for (m = 1; m <= 100; m++){
	//	sum += i*(1 / n);//计算表达式
	//	i = -i;//符号位的变化，正负取反
	//	n += 1;//递增
	//}
	//printf("sum = %f\n", sum);

	int count = 0;//记录9出现的次数
	int i = 1;//循环变量
	for(i = 1; i <= 100; i++){
		if (i / 10 == 9 || i % 10 == 9){//1/10 == 9表示十位数字上的9，
										//i%10 == 9表示个位数字上出现的9，
									//不重复统计
			//printf("%d ",i);	//也可以全部列出来
			count++;
		}
	}
	printf("count = %d\n", count);


	printf("\n");
	system("pause");
	return 0;
}