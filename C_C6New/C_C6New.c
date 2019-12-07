#include<stdio.h>
#include<windows.h>
#include<math.h>
//�˷��ھ���
void multiplication_table(int n){
	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= i; j++){
			printf("%2d * %2d = %2d ", j, i, j*i);
		}
		printf("\n");
	}
}
//ʵ���������Ľ���
void swap(int *p1,int *p2){
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//�ж��Ƿ�Ϊ����
int isLeapYear(int year){
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		//����һ���Ұ��겻����İ���һ��
		printf("%d is a leap year!\n", year);
		return 1;
	}
	printf("%d not a leap year!\n", year);
	return 0;
}
	//��ʼ������
void init(int array[],int num,int n){
	for (int i = 0; i < num; i++){
		array[i] = n;
	}
}
//�������
void empty(int array[], int num){
	/*for (int i = 0; i < num; i++){
		array[i] = ' ';
	}*/
	init(array, num, 0);
}
//���������
void reserve(int array[], int num){
	int left = 0, right = num - 1;
	while (left <= right){
		swap(&array[left], &array[right]);
		left++;
		right--;
	}
}
//�ж�����
int isPrime(int x){
	for (int i = 2; i <= sqrt(x); i++){
		if (x % i == 0){
			printf("%d not a prime number!\n",x);
			return 0;
		}
	}
	printf("%d is a prime number!\n", x);
	return 1;
}
int main(){
	int line = 0;//����
	printf("Enter  line of multiplication table:");
	scanf_s("%d",&line);
	multiplication_table(line);//���ó˷��ھ���

	int a = 0, b = 0;//����ʵ�ֽ���
	printf("Enter two inter number:(a,b):");
	scanf_s("%d %d", &a, &b);
	printf("before swap:a = %d,b = %d\n", a, b);
	swap(&a, &b);
	printf("after swap:a = %d,b = %d\n", a, b);


	int year = 0;
	printf("Enter a number of year to judge:");
	scanf_s("%d", &year);
	isLeapYear(year);//�ж�����

	int arr[20];//��������
	int num = sizeof(arr) / sizeof(arr[0]);
	int initial_value = ' ';

	/*printf("before init:\n");
	for (int i = 0; i < num; i++){
		printf("%d ", arr[i]);
	}*/
	printf("���������Ԫ�ؽ��ᱻ��ʼ��Ϊ��");
	scanf_s("%d", &initial_value);
	printf("\nafter init:\n");
	init(arr, num, initial_value);//��ʼ��Ϊĳ���ض�ֵ
	for (int i = 0; i < num; i++){
		printf("%d ", arr[i]);
	}

	printf("\nafter empty:\n");//���ȫ����ASCIIΪ0
	empty(arr, num);
	for (int i = 0; i < num; i++){
		printf("%c ", arr[i]);
	}


	int arr_1[] = { 45, 87, 456, 7, 6, 78, 156, 978, 135 };//һ����������
	int num_1 = sizeof(arr_1) / sizeof(arr_1[0]);
	printf("\nbefore reserve:\n");//����ǰ
	for (int i = 0; i < num_1; i++){
		printf("%d ", arr_1[i]);
	}
	reserve(arr_1, num_1);
	printf("\nafter reserve:\n");//���ú�
	for (int i = 0; i < num_1; i++){
		printf("%d ", arr_1[i]);
	}


	int inter_number = 2; 
	printf("\nEnter a inter number to judge if prime number:");
	scanf_s("%d", &inter_number);
	isPrime(inter_number);
	printf("\n");
	system("pause");
	return 0;
}
