#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main(){
	//int arr_1[] = { 1, 2, 3, 4, 5 };//��������ʼ������1
	//int arr_2[] = { 6, 7, 8, 9, 10 };//��������ʼ������2
	//printf("arr_1:\n");//��ӡ����1������
	//for(int i = 0; i < 5; i++){
	//	printf("%d ", arr_1[i]);
	//}
	//printf("\narr_2:\n");//��ӡ����2������
	//for (int i = 0; i < 5; i++){
	//	printf("%d ", arr_2[i]);
	//}
	//for (int i = 0; i < 5; i++){//�����㷨
	//	int temp = arr_1[i];//��ʱ�������ڴ洢����Ҫ������Ԫ��
	//	arr_1[i] = arr_2[i];//�±�һ��
	//	arr_2[i] = temp;
	//}
	//printf("\nafter\narr_1:\n");//��������������1
	//for (int i = 0; i < 5; i++){
	//	printf("%d ", arr_1[i]);
	//}
	//printf("\narr_2:\n");//��������������2
	//for (int i = 0; i < 5; i++){
	//	printf("%d ", arr_2[i]);
	//}

	

	//float sum = 0.0;//�洢���
	//float n = 1.0;
	//float i = 1.0;//���ŵı仯
	//int m = 1;//���������Ǿ�ȷ�ģ����������ж��������п��ܼӲ���100����
	//				//	�����ж�
	//for (m = 1; m <= 100; m++){
	//	sum += i*(1 / n);//������ʽ
	//	i = -i;//����λ�ı仯������ȡ��
	//	n += 1;//����
	//}
	//printf("sum = %f\n", sum);

	int count = 0;//��¼9���ֵĴ���
	int i = 1;//ѭ������
	for(i = 1; i <= 100; i++){
		if (i / 10 == 9 || i % 10 == 9){//1/10 == 9��ʾʮλ�����ϵ�9��
										//i%10 == 9��ʾ��λ�����ϳ��ֵ�9��
									//���ظ�ͳ��
			//printf("%d ",i);	//Ҳ����ȫ���г���
			count++;
		}
	}
	printf("count = %d\n", count);


	printf("\n");
	system("pause");
	return 0;
}