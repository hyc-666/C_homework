#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#pragma warning(disable:4996)
#define M 860
#define PSD "helloword"//默认的初始化密码
int main(){

	//猜数字游戏

	//srand((unsigned long)time(NULL));//生成随机数种子
	//int x = rand() % 100 + 1;  //生成一个一到一百的随机整数
	//int guess = 0;//初始化开始猜的数字
	//printf("please guess a magic number between 0 and 100 ->:");//提示输入
	//scanf("%d", &guess);//接受输入的数字
	//do{
	//	//判断是否输对
	//	if (guess > x){//如果输入比随机数大
	//		printf("your guess is too big,try again:");//提示猜大了，再输一次
	//		scanf("%d", &guess);
	//	}
	//	else if (guess < x){//如果输入比随机数小
	//		printf("your guess is too small,try again:");//提示猜小了，再输一次
	//		scanf("%d", &guess);
	//	}
	//	else{
	//		printf("your right!\n");//否则证明猜对了
	//		break;//然后不再执行循环，一次游戏结束
	//	}
	//} while (1);


	//二分查找

	//int arr[] = {3,23,65,78,99,156,265,321,456,852,966,1027,1889,1997,2019};//假设此数列即为即将要进行操作的数列
	////int arr_1[] = {6249,5612,3669,2148,2019,1997,1657,1209,1008,721,680,511,321,150,79,20,12};
	//int num = sizeof(arr) / sizeof(arr[0]);  //数列元素个数
	////int num_1 = sizeof(arr_1) / sizeof(arr_1[0]);
	//int i = -1;//返回下标值
	//int left = 0, right = num - 1;//左右下标
	//int mid = 0;//中间下标
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

	//模拟输入密码

	//int count = 3;//最大输入次数
	//char inPSD[16];//存储用户输入
	//while (count > 0){//还有输入次数时
	//	count--;	//进入循环先减一次
	//	printf("please enter password:");//提示输入
	//	scanf("%s",inPSD);
	//	for (int i = 3; i > 0; i--){//假设验证密码需要时间
	//		printf("waiting... %d\r",i);
	//		Sleep(500);
	//	}
	//	if (strcmp(inPSD,PSD) == 0){//验证密码正确性
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
	//	printf("Exit                                                   \n");//补空格覆盖掉上面的输出，不让倒计时一直停留
	//}



	//大小写互转，数字不输出

	//int ch;
	//while ((ch = getchar()) != EOF){
	//
	//	if (ch >= 'a'&&ch <= 'z'){//注意与ASCII码表的对应关系
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