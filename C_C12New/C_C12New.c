#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

/*unsigned int reverse_bit(unsigned int value); 
这个函数的返回值是value的二进制位模式从左到右翻转后的值。 */
unsigned int reverse_bit(unsigned int value){
	unsigned int ret = 0;
	int bit = 0;
	int i = 0;
	for (i = 0; i < 32; i++){
		ret <<= 1;
		bit = value & 1;
		ret = bit | ret;
		value >>= 1;
	}
	return ret;
}

//.不使用（a+b）/2这种方式，求两个数的平均值。 
int average(int a, int b){
	return (a >> 1) +( b >> 1);
}

/*一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
请找出这个数字。（使用位运算） */
int find_only(int *arr, int len){//依次求异或的结果
	int once = arr[0];
	for (int i = 1; i < len; i++){
		once ^= arr[i];
	}
	return once;
}

/*有一个字符数组的内容为:"student a am i", 
请你将数组的内容改为"i am a student". */
void reverse(char *string,int len){//逆转整个字符串
	/*if (len == 1){
		return;
	}*/
	int i = 0;
	char tmp;
	while (i < len){
		tmp = string[i];
		string[i] = string[len - 1];
		string[len - 1] = tmp;
		i++;
		len--;
	}
}

void true_string(char *str){//依据空格划分单词，再把单词逆转
	int len = 0;//先计算字符串的长度
	char *left = str;
	while (*left){
		len++;
		left++;
	}
	reverse(str,len);//然后逆转整个字符串
	len = 0;//此时表示单词的长度
	while (*str){
		if (*str != ' '){//非空格则单词长度+1
			len++;
			str++;
			continue;
		}
		else{
			str++;//跳过空格，此时是指到空格之后的第一个单词
			reverse(str-len-1, len);//把空格之前（不包括空格）的子字符串（即一个单词）逆转
			//减1是把单词之后的空格不包括
			len = 0;//之后单词长度从0开始重新计算
		}	
	}
	//由于str指到'\0'了，最后一个单词没有逆转，这里再调一次逆转函数
	reverse(str - len, len);//因为最后一个单词后面没有空格，所以不减1
}

int main(){
	//printf("%u", reverse_bit(25));

	//printf("%d", average(15, 30));

	/*int array[] = { 12, 23, 21, 23, 14, 21, 14,12,34 };
	int num = sizeof(array) / sizeof(array[0]);*/
	//printf("%d", find_only(array, num));

	char str[100];
	gets(str);
	true_string(str);
	printf(str);
	printf("\n");
	system("pause");
	return 0;
}