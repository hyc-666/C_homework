#include<stdio.h>
#include<windows.h>
#define M 3
/*��������ʹ����ȫ����λ��ż��ǰ�档 */
void sort(int arr[],int len){//�����鳤��Ҳ������
	int i = 1;
	int j = len;
	int tmp;
	do{
		i--;
		if (arr[i] % 2 == 0){//����һ���ǲ���ż��
			tmp = arr[i];
			arr[i] = arr[j-1];//������������һ��������
			arr[j-1] = tmp;
			i++;
			j--;//�Ѿ�ȷ�����һ��Ϊż������һ������
			continue;//�����Ժ����жϵ�һ���ǲ���ż��
		}
		else{
			i += 2;//�������ż�����жϵڶ���
		}
	} while (i < j);

}

/*��һ����ά����. 
�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����. 
�������������в���һ�������Ƿ���ڡ� 
ʱ�临�Ӷ�С��O(N); */
//�ҵ�����1��δ�ҵ�����-1
//��Ϊ�±������������ز�������������ֻ��ͨ���ı��ⲿ�Ѿ�����õ�ĳЩ����
//ͨ�������������Ĳ����ı�
//���Զ��������ṹ���
//
int search(int array[][M],int i,int j,int x){//i��j�Ǿ����С
	//�����۰���ң����м�Ԫ�ؽ����������Ϊ���룬���Ӿ����ԭ���������ͬ����
	int mid_row = i >> 1;
	int mid_col = j >> 1;
	while (mid_row >= 0 && mid_row < i&&mid_col >= 0 && mid_col<j){
		if (x > array[mid_row][mid_col]){
			mid_row = (mid_row+1 + i) >> 1;
			mid_col = (mid_col+1 + j) >> 1;
			
		}
		else if (x < array[mid_row][mid_col]){
			mid_row = (mid_row - 1) >> 1;
			mid_col = (mid_col - 1) >> 1;;
		}
		else if (x == array[mid_row][mid_col]){
			return 1;
		}
	}
	return 0;


}

int main(){

#if 0
	int a[] = { 1, 2, 12,3, 4, 5,17,15, 6, 7, 8, 9, 0,45 };
	int num = (sizeof(a) / sizeof(a[0]));

	sort(a, num);
	for (int i = 0; i < num; i++){
		printf("%d ", a[i]);
	}
#endif

	int arr[][M] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };

	int x = 3;
	int x2 = 6;
	int ret = search(arr, 3, M, x);
	printf("%d ", ret);
	ret = search(arr, 3, M, x2);

	printf("%d ", ret);


	printf("\n");
	system("pause");
	return 0;

}