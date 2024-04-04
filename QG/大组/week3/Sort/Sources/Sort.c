#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#pragma once
#ifndef SORT_C_INCLUDED
#define SORT_C_INCLUDED

void insertSort(int* a, int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        // 将比 key 大的元素都向后移动一位
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}


void MergeArray(int* a, int begin, int mid, int end, int* temp) {
    int i = begin;      // 左数组的起始
    int j = mid + 1;    // 右数组的起始
    int k = 0;          // 临时数组的起始索引

    // 合并两个子数组直到其中一个子数组遍历完毕
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++]; // 将左子数组当前元素复制到临时数组
        }
        else {
            temp[k++] = a[j++]; // 将右子数组当前元素复制到临时数组
        }
    }

    // 处理剩余的元素:直接复制进入temp数组
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= end) {
        temp[k++] = a[j++];
    }

    // 将临时数组的内容复制回原数组
    for (int t = 0; t < k; ++t) {
        a[begin + t] = temp[t];
    }
}


void MergeSort(int* a, int begin, int end, int* temp) {
    if (begin >= end) { // 当子数组中只有一个元素时，已经有序，无需排序
        return;
    }

    int mid = (begin + end) / 2; // 计算子数组的中间索引

    MergeSort(a, begin, mid, temp);     // 对左半部分进行归并排序
    MergeSort(a, mid + 1, end, temp);   // 对右半部分进行归并排序

    MergeArray(a, begin, mid, end, temp); // 合并左右两部分有序数组
}


void QuickSort_Recursion(int* a, int begin, int end) {
    if (begin >= end) { // 如果子数组只有一个元素或者为空，则已经有序，无需排序
        return;
    }

    int flg = a[begin]; // 选取第一个元素作为基准值
    int left = begin + 1; // 左指针从基准值的下一个位置开始
    int right = end;      // 右指针从数组末尾开始

    while (left <= right) { // 当左指针小于等于右指针时进行循环
        while (left <= right && a[left] <= flg) { // 从左到右找到第一个大于基准值的元素
            left++;
        }
        while (left <= right && a[right] > flg) { // 从右到左找到第一个小于等于基准值的元素
            right--;
        }
        if (left < right) { // 交换左右指针所指向的元素
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }

    // 将基准值放到正确的位置上
    int temp = a[begin];
    a[begin] = a[right];
    a[right] = temp;

    // 递归调用对基准值左右两边的子数组进行排序
    QuickSort_Recursion(a, begin, right - 1);
    QuickSort_Recursion(a, right + 1, end);
}


void QuickSort(int* a, int size) {
    if (size <= 1) { // 如果数组长度小于等于1，无需排序
        return;
    }

    int* stack = (int*)malloc(size * sizeof(int));  // 创建一个栈用于存放子数组的起始和结束索引
    int top = -1;   // 栈顶指针初始化为-1

    stack[++top] = 0;        // 初始时将整个数组的起始索引入栈
    stack[++top] = size - 1; // 初始时将整个数组的结束索引入栈

    while (top >= 0) { // 当栈不为空时循环执行以下操作
        int end = stack[top--]; // 出栈得到当前子数组的结束
        int begin = stack[top--]; // 出栈得到当前子数组的起始

        int pivot = a[begin]; // 选取当前子数组的第一个元素作为基准值
        int left = begin + 1; // 左指针从基准值的下一个位置开始
        int right = end;      // 右指针从数组末尾开始


        // 以下是当左指针小于等于右指针时进行循环--》进行一次快排
        while (left <= right) { 
            while (left <= right && a[left] <= pivot) { // 从左到右找到第一个大于基准值的元素
                left++;
            }
            while (left <= right && a[right] > pivot) { // 从右到左找到第一个小于等于基准值的元素
                right--;
            }
            if (left < right) { // 交换左右指针所指向的元素
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
            }
        }
        // 将基准值放到正确的位置上
        int temp = a[begin];
        a[begin] = a[right];
        a[right] = temp;


        // 将左右子数组的起始和结束索引入栈
        // 因为进行了一次快排，right=left的这个位置的值已经在正确的位置，于是创造两个子数组
        //一个begin--right-1，另一个right--end，对两个数组再次进行快排，然后再次分组；直到剩下一个元素，此时不必再排序，故不用再入栈
        if (begin < right - 1) { // 如果左子数组长度大于1，则入栈
            stack[++top] = begin;
            stack[++top] = right - 1;
        }
        if (right + 1 < end) { // 如果右子数组长度大于1，则入栈
            stack[++top] = right + 1;
            stack[++top] = end;
        }
    }

    free(stack); // 释放栈内存
}



int Partition(int* a, int begin, int end) {
    int pivot = a[begin]; // 选取第一个元素作为基准值
    int left = begin + 1; // 左指针从基准值的下一个位置开始
    int right = end;      // 右指针从数组末尾开始

    while (left <= right) { // 当左指针小于等于右指针时进行循环
        while (left <= right && a[left] <= pivot) { // 从左到右找到第一个大于基准值的元素
            left++;
        }
        while (left <= right && a[right] > pivot) { // 从右到左找到第一个小于等于基准值的元素
            right--;
        }
        if (left < right) { // 交换左右指针所指向的元素
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }

    // 将基准值放到正确的位置上
    int temp = a[begin];
    a[begin] = a[right];
    a[right] = temp;

    return right; // 返回枢轴的索引
}
// 快速排序（枢轴存放）实现
void QuickSort_P(int* a, int begin, int end) {
    if (begin >= end) { // 如果起始索引大于等于结束索引，直接返回
        return;
    }

    int pivotIndex = Partition(a, begin, end); // 获取枢轴的索引

    // 对枢轴左边的子数组进行快速排序
    QuickSort_P(a, begin, pivotIndex - 1);
    // 对枢轴右边的子数组进行快速排序
    QuickSort_P(a, pivotIndex + 1, end);
}


void CountSort(int* a, int size, int max) {
    // 计算计数数组的长度
    int range = max + 1;

    // 创建并初始化计数数组
    int* count = (int*)calloc(range, sizeof(int));
    if (count == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // 统计每个元素的出现次数
    for (int i = 0; i < size; ++i) {
        count[a[i]]++;
    }

    // 根据计数数组中的统计信息，重新排列原数组
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i] > 0) {
            a[index++] = i;
            count[i]--;
        }
    }

    // 释放动态分配的内存
    free(count);
}


int getMax(int* a, int size) {
    int max = a[0];
    for (int i = 1; i < size; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void RadixCountSort(int* a, int size) {
    // 获取数组中的最大值
    int max = getMax(a, size);

    // 获取最大值的位数
    int exp = 1;
    while (max / exp > 0) {
        // 10个计数器，用于统计每个位上的数字出现的次数
        int count[10] = { 0 };

        // 统计当前位上每个数字的出现次数
        for (int i = 0; i < size; ++i) {
            count[(a[i] / exp) % 10]++;
        }

        // 更新count，count[i]表示小于等于i的数字的数量
        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }

        // 临时数组，用于存放排序后的结果
        int* temp = (int*)malloc(size * sizeof(int));

        // 从后向前遍历数组，根据当前位上的数字将元素放入临时数组中
        for (int i = size - 1; i >= 0; --i) {
            temp[--count[(a[i] / exp) % 10]] = a[i];
        }

        // 将临时数组中的结果复制回原数组
        for (int i = 0; i < size; ++i) {
            a[i] = temp[i];
        }

        // 释放临时数组
        free(temp);

        // 更新exp，移至下一位
        exp *= 10;
    }
}


void ColorSort(int* a, int size) {
    int low = 0, mid = 0, high = size - 1;
    while (mid <= high) {
        switch (a[mid]) {
        case 0:
            // 交换a[low]和a[mid]，并将low和mid都向右移动
            a[low] ^= a[mid];
            a[mid] ^= a[low];
            a[low] ^= a[mid];
            low++;
            mid++;
            break;
        case 1:
            // 只将mid向右移动
            mid++;
            break;
        case 2:
            // 交换a[mid]和a[high]，并将high向左移动
            a[mid] ^= a[high];
            a[high] ^= a[mid];
            a[mid] ^= a[high];
            high--;
            break;
        }
    }
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief 分割函数，将数组分割为两部分，左侧元素大于基准值，右侧元素小于基准值
 *
 * @param arr 数组指针
 * @param low 左边界
 * @param high 右边界
 * @return int 分割位置
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/**
 * @brief 在一个无序序列中找到第K大/小的数
 *
 * @param a 数组指针
 * @param size 数组长度
 * @param k 第K大/小的数
 * @return int 第K大/小的数
 */
int findKth(int a[], int size, int k) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int pivotIndex = partition(a, low, high);
        if (pivotIndex == k - 1) {
            return a[pivotIndex];
        }
        else if (pivotIndex < k - 1) {
            low = pivotIndex + 1;
        }
        else {
            high = pivotIndex - 1;
        }
    }
    return -1; // 如果找不到第K大/小的数，返回-1
}





#endif // QUEUE_H_INCLUDED
