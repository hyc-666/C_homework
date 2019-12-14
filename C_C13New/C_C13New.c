#include<stdio.h>
#include<windows.h>
#define M 3
/*调整数组使奇数全部都位于偶数前面。 */
void sort(int arr[],int len){//把数组长度也带进来
	int i = 1;
	int j = len;
	int tmp;
	do{
		i--;
		if (arr[i] % 2 == 0){//检查第一个是不是偶数
			tmp = arr[i];
			arr[i] = arr[j-1];//是则把它与最后一个数互换
			arr[j-1] = tmp;
			i++;
			j--;//已经确定最后一个为偶数，下一轮跳过
			continue;//互换以后在判断第一个是不是偶数
		}
		else{
			i += 2;//如果不是偶数则判断第二个
		}
	} while (i < j);

}

/*有一个二维数组. 
数组的每行从左到右是递增的，每列从上到下是递增的. 
在这样的数组中查找一个数字是否存在。 
时间复杂度小于O(N); */
//找到返回1，未找到返回-1
//因为下标是两个，返回不了两个数，则只能通过改变外部已经定义好的某些变量
//通过将传进函数的参数改变
//可以定义数组或结构体等
//
int search(int array[][M],int i,int j,int x){//i，j是矩阵大小
	//类似折半查找，找中间元素将整个矩阵分为两半，其子矩阵跟原矩阵具有相同规律
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