#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

#define MAX 100		//限定随机数的最大最小值以及数组大小
#define MIN 1
#define SIZE 10


void printArr(int* a,int n) {	//用于打印随机数数组
	if (n != 0) {
		printf("[");
		for (int m = 0; m < n; m++) {
			printf("%d", a[m]);
			if (m < n - 1)
				printf(",");
		}
		printf("]");
	}
	else {
		printf("\n链表为空\n");
	}
}


void generateArr(int* a) {	//用于生成随机数数组
	printf("生成随机数组:\n");
	srand(time(NULL)); // 使用当前时间作为随机数种子
	for (int i = 0; i < SIZE; i++) {
		a[i] = rand() % (MAX - MIN + 1) + MIN; // 生成 min 到 max 之间的随机数
	}
}

void generateArr_Color(int* a) {	//用于生成随机数数组
	printf("生成随机数组:\n");
	srand(time(NULL)); // 使用当前时间作为随机数种子
	for (int i = 0; i < SIZE; i++) {
		a[i] = rand() % (2 - 0 + 1) + 0; // 生成 min 到 max 之间的随机数
	}
}

void makeSrue(int* a,int n) {	//检验数组是否排序完成
	for (int m = 0; m < n-1; m++) {
		if (a[m] > a[m + 1]) {
			printf("\n数组排序有误！\n");
			return;
		}
	}
	printf("\n排序成功\n");
}

int main() {

	int arr[SIZE] = { 0 };
	int length = sizeof(arr) / sizeof(arr[0]);
	generateArr(arr);
	printArr(arr,length);


	printf("\n\n下面开始测试insertSort:\n");
	insertSort(arr,length);
	printf("排序后:\n");
	printArr(arr, length);
	makeSrue(arr, length);



	printf("\n下面开始测试MergeSort:\n");
	generateArr(arr);
	printArr(arr, length);
	printf("\n排序后:\n");
	int temp[SIZE] = {0};
	int begin = 0;
	int end = length - 1;
	MergeSort(arr,begin,end,temp);
	printArr(arr, length);
	makeSrue(arr, length);


	printf("\n下面开始测试QuickSort_Recursion:\n");
	generateArr(arr);
	printArr(arr, length);
	printf("\n排序后:\n");
	begin = 0;
	end = length - 1;
	QuickSort_Recursion(arr, begin, end);
	printArr(arr, length);
	makeSrue(arr, length);


	printf("\n下面开始测试QuickSort:\n");
	generateArr(arr);
	printArr(arr, length);
	printf("\n排序后:\n");
	QuickSort(arr,length);
	printArr(arr, length);
	makeSrue(arr, length);


	printf("\n下面开始测试Partition\n");
	generateArr(arr);
	printArr(arr, length);
	printf("\n排序后:\n");
	begin = 0;
	end = length - 1;
	QuickSort_P(arr, begin, end);
	printArr(arr, length);
	makeSrue(arr, length);


	printf("\n下面开始测试CountSort\n");
	generateArr(arr);
	printArr(arr, length);
	printf("\n排序后:\n");
	CountSort(arr, SIZE, MAX);
	printArr(arr, length);
	makeSrue(arr, length);


	printf("\n下面开始测试RadixCountSort\n");
	generateArr(arr);
	printArr(arr, length);
	printf("\n排序后:\n");
	RadixCountSort(arr, SIZE);
	printArr(arr, length);
	makeSrue(arr, length);


	printf("\n下面开始测试ColorSort\n");
	generateArr_Color(arr);
	printArr(arr, length);
	printf("\n排序后:\n");
	ColorSort(arr,SIZE );
	printArr(arr, length);
	makeSrue(arr, length);


	printf("\n下面开始测试findKth\n");
	generateArr(arr);
	printArr(arr, length);
	int k = 2; // 第K小的数
	int kth = findKth(arr,SIZE , k);
	if (kth != -1) {
		printf("第%d小的数是：%d\n", k, kth);
	}
	else {
		printf("找不到第%d小的数\n", k);
	}



	getchar();
	return 0;
}