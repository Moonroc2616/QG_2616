#include <stdlib.h>
#include <malloc.h>
#include<stdio.h>
#include "LQueue.h"


void printNode(int q) {   //打印队列节点
    printf("%d ",q);  // 假设队列中存储的是整数
}


void creatQueue(LQueue* queue)//创建一个队列，便于直观检查错误
{
    if (queue != NULL) {
        Node* p = (Node*)malloc(sizeof(struct node));
        p->data = 1;
        p->next = NULL;

        queue->front = p;   // 设置队列头节点
        queue->rear = p;
        queue->length = 1;

        Node* curr = queue->front;  // 当前节点指针

        for (int n = 2; n < 6; n++) {
            p->next = (Node*)malloc(sizeof(struct node));  // 创建新节点并连接
            p = p->next;
            p->data = n;
            p->next = NULL;

            queue->rear = p;    // 更新队尾指针
            queue->length++;    // 更新队列长度
        }

        curr = queue->front;  // 恢复当前节点指针
        p = curr;
        /*for (int n = 0; n < 10; n++) {
            if (p != NULL) {
                printf("%d", p->data);
                p = p->next;
            }
            else {
                break;
            }
        }*/
    }
    else {
        printf("队列为空\n");
    }

}



int main() {
    LQueue* queue = (LQueue*)malloc(sizeof(LQueue));

    printf("1.现在开始测试InitLQueue\n");
    InitLQueue(queue);
    if (queue->length == 0) {
        printf("InitLQueue成功\n");
    }
    else {
        printf("InitLQueue失败\n");
    }


    printf("\n2.现在开始测试DestoryLQueue\n");
    DestoryLQueue(queue);
    if (queue->length == 0) {
        printf("InitLQueue成功\n");
    }
    else {
        printf("InitLQueue失败\n");
    }


    printf("\n3.现在开始测试IsEmptyLQueue\n");
    if (IsEmptyLQueue(queue) == TRUE) {
        printf("IsEmptyLQueue成功\n队列为空\n");
    }
    else {
        printf("IsEmptyLQueue成功\n队列不为空\n");
    }


    //现在创建一个队列并打印，便于直观检查错误
    creatQueue(queue);
    printf("测试用队列答应如下：");
    TraverseLQueue(queue, printNode);



    printf("\n4.现在开始测试GetHeadLQueue\n");
    int e = -1;
    if (GetHeadLQueue(queue, &e) == TRUE) {
        printf("GetHeadLQueue成功\n");
        printf("e=%d", e);
    }
    else {
        printf("GetHeadLQueue失败\n");
    }


    printf("\n\n5.现在开始测试 LengthLQueue\n");
    if (LengthLQueue(queue) == TRUE) {
        printf("LengthLQueue成功\n");
    }
    else {
        printf("LengthLQueue失败\n");
    }


    printf("\n6.现在开始测试EnLQueue\n");
    int EN = 99;
    EnLQueue(queue, EN);
    TraverseLQueue(queue, printNode);


    printf("\n\n7.现在开始测试DeLQueue\n");
    if (DeLQueue(queue) == TRUE) {
        printf("DeLQueue成功\n");
    }
    else {
        printf("DeLQueue失败\n");
    }
    TraverseLQueue(queue, printNode);


    printf("\n\n8.现在开始测试ClearLQueue\n");
    if (ClearLQueue(queue) == TRUE) {
        printf("ClearLQueue成功\n");
    }
    else {
        printf("ClearLQueue失败\n");
    }
    if (TraverseLQueue(queue, printNode) == FALSE) {
        printf("队列为空\n");
    }


    printf("\n\n9.1(队列为空)现在开始测试TraverseLQueue\n");
    if (TraverseLQueue(queue, printNode) == TRUE) {
        printf("TraverseLQueue成功\n");
    }
    else {
        printf("队列为空，TraverseLQueue失败\n");
    }


    creatQueue(queue);
    printf("\n\n9.2(队列不为空)现在开始测试TraverseLQueue\n");
    if (TraverseLQueue(queue, printNode) == TRUE) {
        printf("TraverseLQueue成功\n");
    }
    else {
        printf("队列为空，TraverseLQueue失败\n");
    }


    printf("\n\n10.(队列为空)现在开始测试LPrint\n");
    LPrint(queue);
    

	getchar();
	return 0;
}