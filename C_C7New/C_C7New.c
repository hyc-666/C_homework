#include<stdio.h>
#include<windows.h>
#include<math.h>
#include<string.h>

//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//쳲����������������ģ�ǰ2����1��
//��һ����ǰ����ĺͣ����磺1 1 2 3 5 8 13 21 34 55 89...
int Fib_rec(int n){//�ݹ�ʵ��
	if (n <= 2){
		return 1;
	}
	return Fib_rec(n - 1) + Fib_rec(n - 2);//�ݹ��㷨����һ����ǰ����ĺ�
}
int Fib_cir(int n){//�ǵݹ飨ѭ����ʵ��
	int fn = 0;//��¼��n��
	int f1 = 1;//��¼��1��
	int f2 = 1;//��¼��2��
	if (n <= 2){//ǰ2��ֱ�ӷ���1
		return 1;
	}
	for (int i = 3; i <= n; i++){
		fn = f1 + f2;//��һ�����ǰ����֮��
		f1 = f2;//ǰ�����ǰһ��
		f2 = fn;//ǰһ��䵱ǰ��
	}
	return fn;
}
//2.ʹ�õݹ�ʵ��n^k��pow(n,k)
int repow(int n, int k){
	if (0 == k){//�κ�����0���ݵ���1
		return 1;
	}
	/*if (k == 1){
		return n;
	}*/
	return n*repow(n, k - 1);//�ݹ��㷨
}
//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ� 
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
int DigitSum(int n){
	if (n < 9){
		return n;
	}
	return n%10 + DigitSum(n / 10);//��Ȼʵ���ˣ������Ǵӵ�λ�ӵ���λ��
	//��1729�ļ��������9+2+7+1
}
/*4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣� 
ʵ�֣��������ַ����е��ַ��������С� 
Ҫ�󣺲���ʹ��C�������е��ַ������������� 
*/
//int get_strlen(char  *str){//�õ��ַ�������
//	int len = 0;
//	while (*str); {
//		len++;
//		str++;
//	}
//	return len;
//}
//char* reverse_string(char *string){
//	int len = 0;//�ַ�������
//	char temp;
//	char *str;//str��Ϊ���ķ���ֵ��string�ڼ��㳤��ʱ������
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
	char *left = string;//���㵱ǰ�ַ����ĳ���
	while (*string != '\0'){
		len++;
		string++;
	}
	char *right = left + len - 1;//�ұ߽��±�
	if (len > 1){//ֻҪ�ַ������ȴ���1��ִ�еݹ�
		char temp = *left;//������ߵ�һ���ַ�
		*left = *right;//���һ���ַ��ᵽ��ͷ
		*right = '\0';//���һ���ַ��ÿ�
		reverse_string(left + 1);//�ݹ飬���ﲻ��д��left++
		*right = temp;//�������ߵ�һ���ַ��ŵ����
	}
}
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
int my_strlen_cir(char *str){//�ǵݹ�ʵ��
	int len = 0;
	while (*str){//�ַ���0
		len++;
		str++;
	}
	return len;
}
int my_strlen_rec(char *str){//�ݹ�ʵ��
	if (*str == '\0'){
		return 0;
	}

	return 1 + my_strlen_rec(str+1);//ͬ���ģ�Ҳ����д��str++
}
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
int fact_cir(int n){//ѭ��ʵ��
	int result = 1;//������
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
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
//ѭ���ķ�ʽ�ǽ���һ�����飬������ȡ��λ�����������У����ʱ�������
//Ҳ���Ե��Ŵ洢��˳�����
//����ݹ�ͱ�ѭ������
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