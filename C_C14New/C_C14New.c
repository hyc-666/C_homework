#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning(disable:4996)

void left_one(char arr[]){//����һ���ַ�ʱ�����
	int len = strlen(arr);//�ַ�������
	char tmp = arr[len - 1];//������һ���ַ�
	for (int i = len - 1; i >= 0; i--){
		arr[i] = arr[i-1];//��������
	}
	arr[0] = tmp;//�ٰ����һ��д����һ��
}

void Left(char string[],int k){
	while (k){
		left_one(string);
		k--;
	}
}
#if 0
char* move(char *str,int k){
	char *left = str;
	char *right = str + strlen(str)-1;
	char *s = right - k+1;//��벿���ó�����Ϊһ���Ӵ�
	str = strcat(s, left);
	while (k){
		*(right - k+1) = '\0';
		k--;
	}
	
	return str;


}
#endif

//�Ƚ��ǲ�����������ַ���
int stringcmp(char str1[],char str2[]){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 - len2){//������Ȳ�����϶�����
		return 0;
	}
	for (int i = 0; i <= len1; i++){
		
		if (strcmp(str1, str2) == 0){
			return 1;
		}
		left_one(str1);
	}
	return 0;
}

int main(){

	/*char str[40];
	printf("�������ַ���:");
	scanf("%s", &str);
	int k = 0;
	printf("������k��");
	scanf_s("%d", &k);
	Left(str,k);
	printf(str);*/
	char s1[] = "ABCD";
	move(s1,1);
	char s2[] = "BCDA";
	printf("%d", stringcmp(s1, s2));

	printf("\n");
	system("pause");
	return 0;

}