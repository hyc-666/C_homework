#include<stdio.h>
#include<windows.h>
#include<math.h>
int getRank(int N);//��������
int isNar(int n){//�ж��Ƿ�Ϊˮ�ɻ�
	int s = 0;//����ÿ��λ�ϵ����ֵ��������Ժ�ԭ���ֱȽ�
	int t = 0;//��¼ÿ��λ�ϵ�����
	int x = n;//��ֵ���ڼ��㣬ʹԭֵ����󲻱��ƻ�
	while (x != 0){//ԭֵ�ᱻһֱ��10��ֱ��0������ѭ������
		t = x % 10;//�����Ǹ�λ����Ȼ���ǰ�λ��...
		x = x / 10;//ԭֵȥ����λ��10
		s += (int)pow(t, getRank(n));//����λ�ϵ�������
	}
	return (n == s);//ֱ�ӷ��������Ƿ����
	

	//int b = x / 100;//��λ�ϵ�����
	//int s = (x / 10) % 10;//ʮλ�ϵ�����
	//int g = x % 10;//��λ�ϵ�����
	//if (x == pow(b, 3) + pow(s, 3) + pow(g, 3)){
	//	return 1;
	//}
	//return 0;
}
int getRank(int N){//��������һ����λ��
	int count = 0;
	while (N){
		count++;
		N = N / 10;
	}
	return count;
}
int main(){
	//int m = 1;//ÿ�д�ӡ��*����
	//for (int i = 1; i <= 7; i++){//ǰ7��
	//	
	//	for (int j = 1; j <= m; j++){//ÿ�д�ӡ��*
	//		printf("*");
	//	}
	//	printf("  %d", m);
	//	m += 2;
	//	//printf("  %d",m);
	//	printf("\n");
	//}
	//m -= 4;
	//for (int i = 1; i <= 6; i++){//��6��
	//	for (int j = m; j >= 1; j--){
	//		printf("*");
	//	}
	//	printf("  %d", m);
	//	m -= 2;
	//	//printf("  %d", m);
	//	printf("\n");
	//}



	//int i = 1;//һ��13��
	//int n = 1;//ÿ�д�ӡ��*�Ǳ仯�ģ������������ȷ������
	//int m = 1;//ÿ�е�*��
	////m = m + n * 2;//ÿ�е�*�������ĵ�������
	//for (; i <= 13; i++){  //13�У�ѭ��13��
	//	if (i == 7){//��7���Ժ�ÿ�е�*�������ݼ�
	//		n = -n;//������ݼ�
	//	}
	//	for (int j = 1; j <= m; j++){//ÿ�д�ӡ��*��
	//		printf("*");
	//	}
	//	//printf("  %d", m);
	//	printf("\n");//��ӡ��һ�к��У�Ҳ������ѭ��һ�λ�һ��
	//	m += n * 2;//ÿ��*����������������
	//}


	int i = 0;
	for (; i <= 1000; i++){
		if (isNar(i)){//ֱ�ӵ���������ˮ�ɻ����ʹ�ӡ
			printf("%d  ", i);
		}
	}

	//�������� a + aa+aaa+aaaa+aaaaa,,,
	//int a = 0;//����
	//int sum = 0;//ǰn���
	//printf("Enter a = ");
	//scanf_s("%d",&a);//����a
	//int b = a;//����ļ���Ҫ�ں�߼�a��a��ֵҪ������������b����a����ѭ������
	//for (int i = 1; i <= 5; i++){//����ǰ5��
	//	sum += b;//ǰn���
	//	b = b * 10 + a;//������֮��Ĺ�ϵ
	//}
	//printf("sum = %d\n",sum);//������ 


	printf("\n");
	system("pause");
	return 0;
}