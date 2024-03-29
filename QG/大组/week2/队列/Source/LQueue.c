#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LQueue.h"

#ifndef LQUEUE_C_INCLUDED
#define LQUEUE_C_INCLUDED

void InitLQueue(LQueue* Q) {	//初始化队列
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}


Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->length==0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}


Status ClearLQueue(LQueue* Q) {
		if (Q == NULL) {
			return FALSE; // 如果队列指针为空，直接返回
		}

		Node* current = Q->front;
		while (current != NULL) {
			Node* temp = current;
			current = current->next;
			free(temp); // 释放当前结点的内存
		}

		Q->front = NULL;
		Q->rear = NULL;
		return TRUE;
}


Status TraverseLQueue(const LQueue* Q, void (*foo)(void*)) {
	if (Q == NULL || Q->front == NULL || foo == NULL) {
		return FALSE; // 如果队列为空或者函数指针为空，则返回错误状态
	}

	Node* current = Q->front; // 从队列头部开始遍历

	while (current != NULL) {
		foo(current->data); // 对当前节点的数据域执行指定操作
		current = current->next; // 移动到下一个节点
	}
	//printf("f:%d  sec:%d", current->data, current->next->data);

	return TRUE; // 遍历完成，返回正常状态
}



void DestoryLQueue(LQueue* Q) {
		if (Q == NULL) {
			return;
		}

		while (Q->front != NULL) {
			Node* temp = Q->front;
			Q->front = Q->front->next;
			free(temp);
		}


		Q->rear = NULL;	
}


Status GetHeadLQueue(LQueue* Q, int* e) {
	if (Q->length == 0) {
		printf("队列为空\n");
		return FALSE;
	}
	else {
		*e = Q->front->data;
		return TRUE;
	}
}


int LengthLQueue(LQueue* Q) {
	printf("Length=%d", Q->length);
	return TRUE;
}


Status EnLQueue(LQueue* Q, int data) {
	// 检查队列指针和数据指针是否有效
	if (Q == NULL) {
		return FALSE; // 队列指针或数据指针无效，返回失败状态
	}

	// 创建新的结点并将数据存入
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return FALSE; // 内存分配失败，返回失败状态
	}

	newNode->data = data;
	newNode->next = NULL;

	// 将新结点插入队尾
	if (Q->rear == NULL) {
		Q->front = newNode;
	}
	else {
		Q->rear->next = newNode;
	}
	Q->rear = newNode;

	return TRUE; // 返回成功状态
}


Status DeLQueue(LQueue* Q) {
	if (Q->length == 0) {
		return FALSE;
	}
	else {
		LQueue* curr = Q->front;
		Q->front = Q->front->next;
		free(curr);
		return TRUE;
	}
}


void LPrint(void* q) {
	LQueue* queue = (LQueue*)q;

	if (queue == NULL || queue->front == NULL) {
		printf("Queue空\n");
		return;
	}

	Node* current = queue->front;
	while (current != NULL) {
		// 假设元素是整数类型
		printf("%d", current->data);
		current = current->next;
	}
	
	printf("\n");
	printf("LPrint成功\n");
}



#endif