#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#pragma warning(disable:4996)
#define M 860
#define PSD "helloword"//Ĭ�ϵĳ�ʼ������
int main(){

	//��������Ϸ

	//srand((unsigned long)time(NULL));//�������������
	//int x = rand() % 100 + 1;  //����һ��һ��һ�ٵ��������
	//int guess = 0;//��ʼ����ʼ�µ�����
	//printf("please guess a magic number between 0 and 100 ->:");//��ʾ����
	//scanf("%d", &guess);//�������������
	//do{
	//	//�ж��Ƿ����
	//	if (guess > x){//���������������
	//		printf("your guess is too big,try again:");//��ʾ�´��ˣ�����һ��
	//		scanf("%d", &guess);
	//	}
	//	else if (guess < x){//�������������С
	//		printf("your guess is too small,try again:");//��ʾ��С�ˣ�����һ��
	//		scanf("%d", &guess);
	//	}
	//	else{
	//		printf("your right!\n");//����֤���¶���
	//		break;//Ȼ����ִ��ѭ����һ����Ϸ����
	//	}
	//} while (1);


	//���ֲ���

	//int arr[] = {3,23,65,78,99,156,265,321,456,852,966,1027,1889,1997,2019};//��������м�Ϊ����Ҫ���в���������
	////int arr_1[] = {6249,5612,3669,2148,2019,1997,1657,1209,1008,721,680,511,321,150,79,20,12};
	//int num = sizeof(arr) / sizeof(arr[0]);  //����Ԫ�ظ���
	////int num_1 = sizeof(arr_1) / sizeof(arr_1[0]);
	//int i = -1;//�����±�ֵ
	//int left = 0, right = num - 1;//�����±�
	//int mid = 0;//�м��±�
	//while (left <= right){
	//	mid = (left + right) / 2;
	//	if (M < arr[mid]){
	//		right = mid - 1;
	//	}
	//	else if (M > arr[mid]){
	//		left = mid +1;
	//	}
	//	else {
	//		printf("found it\n");
	//		i = mid;
	//		break;
	//	}
	//	if (left > right){
	//		printf("not found\n");
	//		break;
	//	}
	//}
	//printf("%d\n", i);

	//ģ����������

	//int count = 3;//����������
	//char inPSD[16];//�洢�û�����
	//while (count > 0){//�����������ʱ
	//	count--;	//����ѭ���ȼ�һ��
	//	printf("please enter password:");//��ʾ����
	//	scanf("%s",inPSD);
	//	for (int i = 3; i > 0; i--){//������֤������Ҫʱ��
	//		printf("waiting... %d\r",i);
	//		Sleep(500);
	//	}
	//	if (strcmp(inPSD,PSD) == 0){//��֤������ȷ��
	//		//printf("login success!\n");
	//		break;
	//	}
	//	else{
	//		if (count <= 0)
	//			break;
	//		printf("password error!try again:\tyou have %d times!\n", count);
	//	}
	//}
	//if (count > 0){
	//	printf("login success!\n");
	//}
	//else{
	//	printf("password error!\n");
	//	for (int i = 5; i > 0;i--){
	//	
	//		printf("login failed! pragma will exit in %d seconds !\r",i);
	//		Sleep(1000);
	//	}
	//	printf("Exit                                                   \n");//���ո񸲸ǵ��������������õ���ʱһֱͣ��
	//}



	//��Сд��ת�����ֲ����

	//int ch;
	//while ((ch = getchar()) != EOF){
	//
	//	if (ch >= 'a'&&ch <= 'z'){//ע����ASCII���Ķ�Ӧ��ϵ
	//		ch -= 32;
	//	}
	//	else if (ch >= 'A'&&ch <= 'Z'){
	//		ch += 32;
	//	}
	//	else if (ch >= '0'&&ch <= '9'){
	//		continue;
	//	}
	//	putchar(ch);
	//} 
	char s1[] = "fhweirFHQEfhwerfhHEEfiwefwHFWEU";
	char s2[] = "*******************************";
	int left = 0, right = strlen(s1) - 1;
	while (left <= right){
		s1[left] = s2[left]; 
		s1[right] = s2[right];
		printf("%s\r", s2);
		printf("%s\r",s1);
		Sleep(1000);
		left++;
		right--;
	}
	printf("\n");
	system("pause");
	return 0;
}