#include<stdio.h>
#include<windows.h>
/*1. 
дһ���������ز����������� 1 �ĸ���
���磺 15 0000 1111 4 �� 1
����ԭ�ͣ�
int count_one_bits(unsigned int value)
{
	// ���� 1��λ�� 
}*/
int count_one_bits(unsigned int value){
	int count = 0;
	while (value){
			count++;
		
		value = value&(value - 1);
	}
	return count;
}
/*2.��ȡһ�������������������е�ż��λ������λ�� 
�ֱ�������������С� 
*/
void get_bit(int x0){
	int x = x0;
	printf("����λ��");
	while (x0){
		printf("%d", x0 % 2);
		x0 = x0 >> 2;
	}
	printf("\nż��λ:");
		x >>= 1;
	while (x){
		printf("%d", x % 2);
		x >>= 2;
	}
	printf("\n");

}
/*3. ���һ��������ÿһλ�� */
void print_digit(int x){
	//ʮ���Ƶ�ÿһλ
	/*while (x){
		printf("%d", x % 10);
		x /= 10;
	}*/
	while (x){
		printf("%d", x % 2);
		x >>= 1;
	}
}
/*4.���ʵ�֣� 
����int��32λ������m��n�Ķ����Ʊ���У� 
�ж��ٸ�λ(bit)��ͬ�� 
��������: 
1999 2299 
�������:7 
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