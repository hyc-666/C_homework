#include<stdio.h>
#include<windows.h>
#include<math.h>
#pragma warning(disable:4996)
int main()
{
	/*int a, b, temp;   //temp���м����
	printf("������a��b��");
	scanf("%d %d",&a,&b);
	printf("a = %d,b = %d   \n",a,b);
	temp = a;
	a = b;
	b = temp;

	printf("������\n");
	printf("a = %d,b = %d  \n",a,b);*/

	//û��ʹ����ʱ����
	/*int a;
	int b;
	printf("������a��b��\n");
	scanf("%d %d",&a,&b);
	printf("a = %d,b = %d\n",a,b);
	printf("������\n");
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a = %d,b = %d\n",a,b);
*/
	
	//ʹ�����������ɽ��� 
	/*
	int a;
	int b;
	printf("������a��b��\n");
	scanf("%d %d", &a, &b);
	printf("a = %d,b = %d\n", a, b);
	printf("������\n");
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d,b = %d\n", a, b);*/

	/*int arr[10];    //��������10����
	printf("������10��������\n");
	for (int i = 0; i < 10; i++)   //������10����
	{
		scanf("%d",&arr[i]);

	}
	int max = arr[0];   //ѡ��һ����Ҫ�����������
	for (int i = 0; i < 10; i++)
	{
		if (max <= arr[i])     ���max�Ⱥ�ߵ��������С������������ĺ�һ������
			max = arr[i];
	}
	printf("��������%d��\n",max);     //�����������*/    



	//int arr[3];
	//printf("��������������\n");
	//for (int i = 0; i < 3;i++){    //��������������Ȼ��������
	//	scanf("%d",&arr[i]);
	//}                    //����ð�������㷨
	//for (int i = 0; i < 3; i++){    //��һ�ֱȽ�
	//	for (int j = 0; j < 2 - i; j++){      //�ڶ��ֱȽ�
	//		if (arr[i] < arr[i + 1]){
	//			int temp = arr[i];       //�����㷨
	//			arr[i] = arr[i + 1];
	//			arr[i + 1] = temp;
	//		}

	//	}
	//}
	//printf("�Ӵ�С�������ǣ�\n");  //���������˳��
	//for (int i = 0; i < 3; i++)
	//	printf("%d  ",arr[i]);


	   //ʹ��շת��������������������Լ��
	   /*    շת������ֳ�Ϊŷ������㷨
	   ���ô�����С������¼������������Ϊ0�������Ϊ���Լ��
	   ��������Ϊ0���ó�������������¼������������Ϊ0��
	   ����һ�����������Լ��������Ϊ0�����ظ���������
	   ֱ������Ϊ0�������һ�����������Լ��
	   */

	 //�������£�

	//int a,b,m,n;
	//printf("�����������֣�\n");
	//scanf("%d %d",&a,&b);
	//m = a;
	//n = b;
	//if (m < n){      //��ȷ���ĸ��ǳ����ĸ��Ǳ�����
	//	int temp = m;   //����Ϊ��������С��Ϊ����
	//	m = n;        
	//	n = temp;
	//}
	//int r;        //r������¼����
	//do{
	//	r = m%n;     //������С���õ�����
	//	m = n;      //������Ϊ������
	//	n = r;       //��������Ϊ����
	//} while (r != 0);    //r������Ϊ0��ִ��ѭ������������
	//printf("%d��%d�����Լ���ǣ�%d \n",a,b,m);


	//����������������Լ��


	int a, b, m, n;
	printf("������������:\n");
	scanf("%d %d",&a,&b);
	m = a;
	n = b;
	       //���Ǵ�����С����mС��n�򽻻�ֵ
	/*if (m < n){
		int temp = m;
		m = n;
		n = temp;
	}*/
	////int r = 1; //����2Լ�֣���¼һ�����˼���2
	int s = 0; //����������Ĳ�
	//if(m % 2 == 0 && n % 2 == 0){
	//	m = m / 2;   //��2 Լ��
	//	n = n / 2;
	//	//r = r * 2;    //��2Լ�˼���
	//}
	//do
	//{
	//	s = m - n;        //m - n = s
	//	if(s > n)
	//		m = s;
	//	if(s < n){
	//		m = n;
	//		n = s;
	//	}
	//		/*else(s == n){
	//			r = r*s;
	//		}*/
	//}while (s != n);
	//printf("%d\n", s);


	
		while(m != n){
			if (m > n)
				m = m - n;
			else
				n = n - m;
		}
		s = m;


	
	printf("%d��%d����С�������ǣ�%d\n",a,b,s);
	system("pause");
	return 0;
}