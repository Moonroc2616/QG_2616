#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_C_INCLUDED
#define LINKEDLIST_C_INCLUDED

Status InitList(LinkedList* L) {
    printf("\n调用LinkedList中\n");
    LNode* curr = (LinkedList)malloc(sizeof(LNode));
    curr->next = NULL;

    *L = curr; // 分配头结点空间
    if ((*L) == NULL) {
        return ERROR;  // 内存分配失败
    }

    return SUCCESS;  // 初始化成功
}


void DestroyList(LinkedList* L) {
    printf("开始调用DestroyList\n");
    if ((*L) == NULL) {
        printf("\n链表自为空");  //链表为空的情况
        return;
    }

    LinkedList current = *L;  // 当前节点指针
    LinkedList currentNext=NULL;  // 下一个节点指针

    while (current != NULL) {
        currentNext = current->next;  // 保存下一个节点指针
        free(current);          // 释放当前节点内存
        current = currentNext;  // 移动到下一个节点
        
    }
    *L = NULL;  // 头指针置空
    printf("链表已销毁\n");
}

Status InsertList(LNode* p, LNode* q) {
    printf("开始调用InsertList");
    q->next = p->next;  //p连接q的后一位 
    p->next = q;    //再让p链接至q                   
}

//Status DeleteList(LNode* p, ElemType* e) {
//    printf("开始调用DeleteList");
//    LinkedList current = p;  // 当前节点指针
//    LinkedList currentNext=current->next;  // 下一个节点指针
//
//    e = currentNext->data;  //将p后一位的data赋值给e
//    current = currentNext->next;    //链接至p后第二位
//    free(currentNext);  //释放p后一位
//}
Status DeleteList(LNode* p, ElemType* e) {
    if (p == NULL || p->next == NULL) {
        return ERROR; // 节点为空或者p是最后一个节点，无法删除
    }
    LinkedList currentNext = p->next;  // 要删除的节点
    *e = currentNext->data;  // 将要删除节点的数据赋值给e
    printf("删去：%d\n", currentNext->data);
    p->next = currentNext->next;  // 删除节点，修改p的next指针
    free(currentNext);  // 释放删除的节点内存

    return SUCCESS;
}


void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    printf("开始调用TraverseList");
    LinkedList current = L->next;     //当前指针
    printf("\n");
    while (current!= NULL) {
        visit(current->data);   //调用函数
        current = current->next;    //继续遍历链表
    }
    printf("\nTraverseList成功\n");
}

Status SearchList(LinkedList L, ElemType e) {
    printf("开始调用SearchList");
    LinkedList current = L;     //当前指针

    while (current != NULL) {
        if (current->data == e) {           
            return SUCCESS;
        }
        current = current->next;    //继续遍历链表
    }
    return ERROR;
}

Status ReverseList(LinkedList* L) {
    printf("开始调用ReverseList");
    if (*L == NULL) {
        printf("\n链表为空\n");
        return SUCCESS;
    }

         LNode*  prev = *L;     //前一个节点
         LNode* current = (*L)->next;     //当前节点
        //current = (struct LNode*)malloc(sizeof(LNode));
         LNode* currentNext=(*L)->next->next;//下一个节点
       // currentNext = (struct LNode*)malloc(sizeof(LNode));

        while (current != NULL) {
            currentNext = current->next; // 保存当前节点的下一个节点
            current->next = prev; // 将当前节点指向前一个节点
            prev = current; // 更新前一个节点为当前节点
            current = currentNext; // 更新当前节点为下一个节点
        }

        *L = prev; // 更新链表头节点

        return SUCCESS;
    }

Status IsLoopList(LinkedList L) {
    printf("开始调用IsLoopList");
        if (L == NULL || L->next == NULL) {
            return ERROR; // 处理空链表或只有一个节点的情况，肯定不存在循环
        }

        LinkedList slow = L;
        LinkedList fast = L;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // 慢指针每次移动一个节点
            fast = fast->next->next;     // 快指针每次移动两个节点

            if (slow == fast) {
                return SUCCESS;  // 快慢指针相遇，存在循环
            }
        }

        return ERROR; // 快指针先到达链表尾部，不存在循环
    }

//LNode* ReverseEvenList(LinkedList* L) {
//    printf("开始调用ReverseEvenList");
//    
//    LinkedList current = *L->next;
//    current = (LinkedList)malloc(sizeof(LNode));
//    LinkedList prve = current->next;
//
//    while (current != NULL &&current->next!=NULL) {
//        prve = current;
//        current = current->next;
//
//        if (current->data % 2 == 0) {   //判断是否是偶数
//            prve->next=current->next;    //与前一位节点替换位置
//            current->next = prve;
//            prve = current;     //确保prve和curr在同一位置
//        }
//    }
//}


LNode* FindMidNode(LinkedList* L) {
    printf("开始调用FindMidNode");
    if ((*L) == NULL || (*L)->next == NULL) {
        return (*L); // 处理空链表或只有一个节点的情况
    }

    LNode* slow = (*L);
    LNode* fast = (*L);

    while (fast != NULL) {
        slow = slow->next;           // 慢指针每次移动一个节点
        fast = fast->next->next;     // 快指针每次移动两个节点
    }

    return slow;
}



#endif