#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_C_INCLUDED
#define LINKEDLIST_C_INCLUDED

Status InitList(LinkedList* L) {
    printf("\n����LinkedList��\n");
    LNode* curr = (LinkedList)malloc(sizeof(LNode));
    curr->next = NULL;

    *L = curr; // ����ͷ���ռ�
    if ((*L) == NULL) {
        return ERROR;  // �ڴ����ʧ��
    }

    return SUCCESS;  // ��ʼ���ɹ�
}


void DestroyList(LinkedList* L) {
    printf("��ʼ����DestroyList\n");
    if ((*L) == NULL) {
        printf("\n������Ϊ��");  //����Ϊ�յ����
        return;
    }

    LinkedList current = *L;  // ��ǰ�ڵ�ָ��
    LinkedList currentNext=NULL;  // ��һ���ڵ�ָ��

    while (current != NULL) {
        currentNext = current->next;  // ������һ���ڵ�ָ��
        free(current);          // �ͷŵ�ǰ�ڵ��ڴ�
        current = currentNext;  // �ƶ�����һ���ڵ�
        
    }
    *L = NULL;  // ͷָ���ÿ�
    printf("����������\n");
}

Status InsertList(LNode* p, LNode* q) {
    printf("��ʼ����InsertList");
    q->next = p->next;  //p����q�ĺ�һλ 
    p->next = q;    //����p������q                   
}

//Status DeleteList(LNode* p, ElemType* e) {
//    printf("��ʼ����DeleteList");
//    LinkedList current = p;  // ��ǰ�ڵ�ָ��
//    LinkedList currentNext=current->next;  // ��һ���ڵ�ָ��
//
//    e = currentNext->data;  //��p��һλ��data��ֵ��e
//    current = currentNext->next;    //������p��ڶ�λ
//    free(currentNext);  //�ͷ�p��һλ
//}
Status DeleteList(LNode* p, ElemType* e) {
    if (p == NULL || p->next == NULL) {
        return ERROR; // �ڵ�Ϊ�ջ���p�����һ���ڵ㣬�޷�ɾ��
    }
    LinkedList currentNext = p->next;  // Ҫɾ���Ľڵ�
    *e = currentNext->data;  // ��Ҫɾ���ڵ�����ݸ�ֵ��e
    printf("ɾȥ��%d\n", currentNext->data);
    p->next = currentNext->next;  // ɾ���ڵ㣬�޸�p��nextָ��
    free(currentNext);  // �ͷ�ɾ���Ľڵ��ڴ�

    return SUCCESS;
}


void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    printf("��ʼ����TraverseList");
    LinkedList current = L->next;     //��ǰָ��
    printf("\n");
    while (current!= NULL) {
        visit(current->data);   //���ú���
        current = current->next;    //������������
    }
    printf("\nTraverseList�ɹ�\n");
}

Status SearchList(LinkedList L, ElemType e) {
    printf("��ʼ����SearchList");
    LinkedList current = L;     //��ǰָ��

    while (current != NULL) {
        if (current->data == e) {           
            return SUCCESS;
        }
        current = current->next;    //������������
    }
    return ERROR;
}

Status ReverseList(LinkedList* L) {
    printf("��ʼ����ReverseList");
    if (*L == NULL) {
        printf("\n����Ϊ��\n");
        return SUCCESS;
    }

         LNode*  prev = *L;     //ǰһ���ڵ�
         LNode* current = (*L)->next;     //��ǰ�ڵ�
        //current = (struct LNode*)malloc(sizeof(LNode));
         LNode* currentNext=(*L)->next->next;//��һ���ڵ�
       // currentNext = (struct LNode*)malloc(sizeof(LNode));

        while (current != NULL) {
            currentNext = current->next; // ���浱ǰ�ڵ����һ���ڵ�
            current->next = prev; // ����ǰ�ڵ�ָ��ǰһ���ڵ�
            prev = current; // ����ǰһ���ڵ�Ϊ��ǰ�ڵ�
            current = currentNext; // ���µ�ǰ�ڵ�Ϊ��һ���ڵ�
        }

        *L = prev; // ��������ͷ�ڵ�

        return SUCCESS;
    }

Status IsLoopList(LinkedList L) {
    printf("��ʼ����IsLoopList");
        if (L == NULL || L->next == NULL) {
            return ERROR; // ����������ֻ��һ���ڵ��������϶�������ѭ��
        }

        LinkedList slow = L;
        LinkedList fast = L;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // ��ָ��ÿ���ƶ�һ���ڵ�
            fast = fast->next->next;     // ��ָ��ÿ���ƶ������ڵ�

            if (slow == fast) {
                return SUCCESS;  // ����ָ������������ѭ��
            }
        }

        return ERROR; // ��ָ���ȵ�������β����������ѭ��
    }

LNode* ReverseEvenList(LinkedList* L) {
    printf("��ʼ����ReverseEvenList");
    
    LinkedList current = *L)->next;
    current = (LinkedList)malloc(sizeof(LNode));
    LinkedList prve = current->next;

    while (current != NULL &&current->next!=NULL) {
        prve = current;
        current = current->next;

        if (current->data % 2 == 0) {   //�ж��Ƿ���ż��
            prve->next=current->next;    //��ǰһλ�ڵ��滻λ��
            current->next = prve;
            prve = current;     //ȷ��prve��curr��ͬһλ��
        }
    }
}


LNode* FindMidNode(LinkedList* L) {
    printf("��ʼ����FindMidNode");
    if ((*L) == NULL || (*L)->next == NULL) {
        return (*L); // ����������ֻ��һ���ڵ�����
    }

    LNode* slow = (*L);
    LNode* fast = (*L);

    while (fast != NULL) {
        slow = slow->next;           // ��ָ��ÿ���ƶ�һ���ڵ�
        fast = fast->next->next;     // ��ָ��ÿ���ƶ������ڵ�
    }

    return slow;
}



#endif