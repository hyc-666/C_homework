#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning(disable:4996)

void left_one(char arr[]){//左旋一个字符时的情况
	int len = strlen(arr);//字符串长度
	char tmp = arr[len - 1];//提出最后一个字符
	for (int i = len - 1; i >= 0; i--){
		arr[i] = arr[i-1];//整体右移
	}
	arr[0] = tmp;//再把最后一个写到第一个
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
	char *s = right - k+1;//后半部分拿出来作为一个子串
	str = strcat(s, left);
	while (k){
		*(right - k+1) = '\0';
		k--;
	}
	
	return str;


}
#endif

//比较是不是左旋后的字符串
int stringcmp(char str1[],char str2[]){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 - len2){//如果长度不等则肯定不是
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
	printf("请输入字符串:");
	scanf("%s", &str);
	int k = 0;
	printf("请输入k：");
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