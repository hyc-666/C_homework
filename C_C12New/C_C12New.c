#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

/*unsigned int reverse_bit(unsigned int value); 
��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ�� */
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

//.��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ�� 
int average(int a, int b){
	return (a >> 1) +( b >> 1);
}

/*һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
���ҳ�������֡���ʹ��λ���㣩 */
int find_only(int *arr, int len){//���������Ľ��
	int once = arr[0];
	for (int i = 1; i < len; i++){
		once ^= arr[i];
	}
	return once;
}

/*��һ���ַ����������Ϊ:"student a am i", 
���㽫��������ݸ�Ϊ"i am a student". */
void reverse(char *string,int len){//��ת�����ַ���
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

void true_string(char *str){//���ݿո񻮷ֵ��ʣ��ٰѵ�����ת
	int len = 0;//�ȼ����ַ����ĳ���
	char *left = str;
	while (*left){
		len++;
		left++;
	}
	reverse(str,len);//Ȼ����ת�����ַ���
	len = 0;//��ʱ��ʾ���ʵĳ���
	while (*str){
		if (*str != ' '){//�ǿո��򵥴ʳ���+1
			len++;
			str++;
			continue;
		}
		else{
			str++;//�����ո񣬴�ʱ��ָ���ո�֮��ĵ�һ������
			reverse(str-len-1, len);//�ѿո�֮ǰ���������ո񣩵����ַ�������һ�����ʣ���ת
			//��1�ǰѵ���֮��Ŀո񲻰���
			len = 0;//֮�󵥴ʳ��ȴ�0��ʼ���¼���
		}	
	}
	//����strָ��'\0'�ˣ����һ������û����ת�������ٵ�һ����ת����
	reverse(str - len, len);//��Ϊ���һ�����ʺ���û�пո����Բ���1
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