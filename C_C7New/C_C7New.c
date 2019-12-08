#include<stdio.h>
#include<windows.h>
#include<math.h>
#include<string.h>

//1.递归和非递归分别实现求第n个斐波那契数
//斐波那契数列是这样的：前2项是1，
//后一项是前两项的和，比如：1 1 2 3 5 8 13 21 34 55 89...
int Fib_rec(int n){//递归实现
	if (n <= 2){
		return 1;
	}
	return Fib_rec(n - 1) + Fib_rec(n - 2);//递归算法，后一项是前两项的和
}
int Fib_cir(int n){//非递归（循环）实现
	int fn = 0;//记录第n项
	int f1 = 1;//记录第1项
	int f2 = 1;//记录第2项
	if (n <= 2){//前2项直接返回1
		return 1;
	}
	for (int i = 3; i <= n; i++){
		fn = f1 + f2;//后一项等于前两项之和
		f1 = f2;//前两项变前一项
		f2 = fn;//前一项变当前项
	}
	return fn;
}
//2.使用递归实现n^k即pow(n,k)
int repow(int n, int k){
	if (0 == k){//任何数的0次幂等于1
		return 1;
	}
	/*if (k == 1){
		return n;
	}*/
	return n*repow(n, k - 1);//递归算法
}
//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和， 
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
int DigitSum(int n){
	if (n < 9){
		return n;
	}
	return n%10 + DigitSum(n / 10);//虽然实现了，但是是从低位加到高位的
	//如1729的计算过程是9+2+7+1
}
/*4. 编写一个函数 reverse_string(char * string)（递归实现） 
实现：将参数字符串中的字符反向排列。 
要求：不能使用C函数库中的字符串操作函数。 
*/
//int get_strlen(char  *str){//得到字符串长度
//	int len = 0;
//	while (*str); {
//		len++;
//		str++;
//	}
//	return len;
//}
//char* reverse_string(char *string){
//	int len = 0;//字符串长度
//	char temp;
//	char *str;//str作为最后的返回值，string在计算长度时被更改
//	char *left = string;
//	char *right = string + len - 1;
//	if (*string){
//		temp = *left;
//		*left = *right;
//		*right = '\0';
//		reverse_string(string++);
//		*right = temp;
//	}
//	return string;
//}
void reverse_string(char *string){
	int len = 0;
	char *left = string;//计算当前字符串的长度
	while (*string != '\0'){
		len++;
		string++;
	}
	char *right = left + len - 1;//右边界下标
	if (len > 1){//只要字符串长度大于1则执行递归
		char temp = *left;//保存左边第一个字符
		*left = *right;//最后一个字符提到开头
		*right = '\0';//最后一个字符置空
		reverse_string(left + 1);//递归，这里不能写成left++
		*right = temp;//保存的左边第一个字符放到最后
	}
}
//5.递归和非递归分别实现strlen
int my_strlen_cir(char *str){//非递归实现
	int len = 0;
	while (*str){//字符非0
		len++;
		str++;
	}
	return len;
}
int my_strlen_rec(char *str){//递归实现
	if (*str == '\0'){
		return 0;
	}

	return 1 + my_strlen_rec(str+1);//同样的，也不能写成str++
}
//6.递归和非递归分别实现求n的阶乘
int fact_cir(int n){//循环实现
	int result = 1;//保存结果
	for (int i = n; i > 1; i--){
		result *= i;
	}
	return result;
}
int fact_rec(int n){
	if (n < 2){
		return 1;
	}
	return n*fact_rec(n - 1);
}
//7.递归方式实现打印一个整数的每一位 
//循环的方式是建立一个数组，依次提取各位保存在数组中，输出时倒着输出
//也可以倒着存储，顺着输出
//这里递归就比循环方便
void print_Int(int n){
	if (n > 9){
		print_Int(n / 10);
	}
	printf("%d ", n % 10);
}
int main(){

	//printf("%d\n",Fib_rec(11));
	/*int ret = DigitSum(123);
	printf("ret:%d\n",ret);*/


	char str[40] = "abcdefghijklmn";
	/*reverse_string(str);
	printf("%s\n",str);*/


	/*int length = my_strlen_cir(str);
	printf("length:%d\n",length);
	int length_rec = my_strlen_rec(str);
	printf("length_rec:%d\n", length_rec);*/

	/*printf("%d\n", fact_cir(6));
	printf("%d\n", fact_rec(6));*/

	print_Int(4651234);
	printf("\n");
	system("pause");
	return 0;
}