#include<stdio.h>
#include<windows.h>
/*1. 
写一个函数返回参数二进制中 1 的个数
比如： 15 0000 1111 4 个 1
程序原型：
int count_one_bits(unsigned int value)
{
	// 返回 1的位数 
}*/
int count_one_bits(unsigned int value){
	int count = 0;
	while (value){
			count++;
		
		value = value&(value - 1);
	}
	return count;
}
/*2.获取一个数二进制序列中所有的偶数位和奇数位， 
分别输出二进制序列。 
*/
void get_bit(int x0){
	int x = x0;
	printf("奇数位：");
	while (x0){
		printf("%d", x0 % 2);
		x0 = x0 >> 2;
	}
	printf("\n偶数位:");
		x >>= 1;
	while (x){
		printf("%d", x % 2);
		x >>= 2;
	}
	printf("\n");

}
/*3. 输出一个整数的每一位。 */
void print_digit(int x){
	//十进制的每一位
	/*while (x){
		printf("%d", x % 10);
		x /= 10;
	}*/
	while (x){
		printf("%d", x % 2);
		x >>= 1;
	}
}
/*4.编程实现： 
两个int（32位）整数m和n的二进制表达中， 
有多少个位(bit)不同？ 
输入例子: 
1999 2299 
输出例子:7 
*/
int dislike(int x, int y){
	int z = x^y;
	return count_one_bits(z);
}
int main(){
	int a = 15;
	/*printf("%d", count_one_bits(a));
	get_bit(15);*/
	//print_digit(a);
	printf("%d", dislike(1999, 2299));
	printf("\n");
	system("pause");
	return 0;
}