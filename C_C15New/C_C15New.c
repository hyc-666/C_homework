#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<assert.h>
/*һ��������ֻ�����������ǳ���һ�Σ� 
�����������ֶ����������Ρ� 
�ҳ�������ֻ����һ�ε����֣�*/
void search_two(int arr[],int len){
	int ret = 0;
	for (int i = 0; i < len; i++){
		ret ^= arr[i];
	}
	int pos = 0;
	for (int i = 0; i < 32; i++){
		if ((ret >> i) & 1){
			pos = i;
			break;
		}
	}
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < len; i++){
		if ((arr[i] >> pos) & 1){
			num1 ^= arr[i];
		}
		else{
			num2 ^= arr[i];
		}
	}
	printf("first num is:%d second num is:%d\n", num1, num2);
}

/*
2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
��20Ԫ�����Ժȶ�����ˮ��
���ʵ��*/
int bottle(int money){
	int suda = money;//�ܺȵ�����ˮ=Ǯ
	int bottle = suda;//��ƿ=�ȵ�����ˮ
	int ret = 0;//����
	while (suda){//�����ܺȵ���ˮ��ʱ��

		ret = ret + suda;
		suda = bottle / 2 ;//������ƿ=1ƿ��ˮ
		if (bottle % 2 == 0){//�����ƿ��˫��
			bottle = suda;//��ƿ=�Ѻ���ˮ
		}
		else{
			bottle = suda + 1;//�������ƿ���һ��
		}
		
	}
	return ret;
}

/*3.ģ��ʵ��strcpy*/
void my_strcpy(char *str1,const char *str2){
	assert(str1 || str2);
	while (*str1&&*str2){
		*str1 = *str2;
		str1++;
		str2++;
	}
}
/*4.ģ��ʵ��strcat*/
void my_strcat(char *str1, const char *str2){//���ַ���2������׷�����ӵ��ַ���2�ĺ���
	assert(str1 || str2);
	str1 += strlen(str1);
	while (*str2){
		*str1 = *str2;
		str1++;
		str2++;
	}
}
int main(){
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 7, 7, 8, 8, 9, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	search_two(arr, size);
	printf("%d\n", bottle(20));
	
	char string1[40] = "hello ";
	char string2[] = "world!";

	
	/*my_strcpy(string1, string2);
	printf(string1);*/

	printf(string1);
	my_strcat(string1, string2);
	printf("\n");
	printf(string1);

	printf("\n");
	system("pause");
	return 0;
}