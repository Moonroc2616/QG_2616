<<<<<<< HEAD
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

//void Add(LinkedList current)
//{
//    current = (LinkedList)malloc(sizeof(LNode));
//    current->data = current->data + 1;
//}
void visit(ElemType e) {//����
    printf("%d ", e+1);
}

void printLink(struct LNode* L) {   //��ӡ�������ڼ��
    if (L == NULL)  //����Ϊ�յĴ�ӡ
    {
        printf("NULL\n");
        return;
    }
    
    printf("�������£�\n");//����ǿյĴ�ӡ
    LNode* p = L->next;
    while (p != NULL)
    {
        printf("%d->\t", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct LNode* createLinkedList(void) {
    LinkedList L = NULL;//struct LNode* L
    if (InitList(&L) != SUCCESS) {  // ��ʼ���������ʧ���򷵻ؿ�
        printf("ERROR");
        return NULL;
    }

    //����һ���̶����ȹ̶����ݵ�����
    int i = 0;
    LNode* p = L;
    LNode* newNode;
    while (i<5) {
         newNode = (LNode*)malloc(sizeof(LNode));
        if (!newNode) {
            printf("�ڴ����ʧ��\n");
            break;
        }

        newNode->data = i;
        newNode->next = NULL;

        p->next = newNode;
        p = p->next;
        i++;
    }

    printf("SUCCESS\n");
    printLink(L);
    return L;  // ���ش����õ�����
}

int main()
{
    struct LNode* L = NULL;
    struct LNode* p = NULL;    //����ʵ��InsertList�������ڵ�
    struct LNode* q = NULL;
    q = (struct LNode*)malloc(sizeof(LNode));
    int *e = (int*)malloc(2*sizeof(int));  //����ȷ��DeleteList�Ƿ�ɹ���ֵ

    printf("1.���濪ʼ����ͷ�ļ���InitList"); 
        L=createLinkedList();   //����������ʼ������ӡ
        if (L != NULL) {
            printf("InitList�ɹ�\n");
        }


    printf("\n2.���濪ʼ����ͷ�ļ���DestroyList\n");
        DestroyList(&L);    //�ݻ�������ӡȷ��
        printLink(L);   //��ӡ��֤�Ƿ����
        if (L == NULL) {
            printf("DestroyList�ɹ�\n");
        }


    printf("\n3.���濪ʼ����ͷ�ļ���InsertList");
        L=createLinkedList();   //����������ʼ������ӡ
        p = L->next;    //�Զ���p�ĵ�Ϊͷ����һλ
        q->data = 10;   //�Զ���q��ֵ����ʼ���ڵ�q��
        q->next = NULL;
        InsertList(p,q);
        printLink(L);   //��ӡ��֤�Ƿ����
        if (L->next->next->data == q->data) {
            printf("InsertList�ɹ�\n");
        }


    printf("\n4.���濪ʼ����ͷ�ļ���DeleteList\n");
        int flg = q->data;
        DeleteList(L->next, e);   //��q�ڵ�ɾȥ��֤DeleteList
        printLink(L);
        printf("e=%d", *e);
        if (*e == flg) {
            printf("\nDeleteList�ɹ�\n");
        }



    printf("\n5.���濪ʼ����ͷ�ļ���TraverseList\n");
        TraverseList(L, visit);


    printf("\n6.���濪ʼ����ͷ�ļ���SearchListt\n");
        printf("�����������1��99\n");
        if (SearchList(L, 1) == SUCCESS|| SearchList(L, 99)==ERROR) {
            printf("\nSearchListt�ɹ���\n");
        }

    
    //printf("\n7.���濪ʼ����ͷ�ļ���ReverseList\n");
    //if (ReverseList(&L) == SUCCESS) {
    //    printf("���óɹ�");
    //    printLink(L);
    //}
    //else {
    //    printf("����ʧ��");
    //}



   printf("\n8.���濪ʼ����ͷ�ļ���IsLoopList\n"); 
       if (IsLoopList(L) == ERROR) {
           printf("\n��ѭ��\n");
           printf("IsLoopList�ɹ�\n");
       }else {
           printf("\n��ѭ��\n");
           printf("IsLoopList�ɹ�\n");
   }

       
   /*printf("\n9.���濪ʼ����ͷ�ļ���ReverseEvenList\n");
        ReverseEvenList(&L);
        printLink(L);*/
   
   
       printf("\n10.���濪ʼ����ͷ�ļ���FindMidNode\n");
       printLink(L);
       struct LNode* temp = FindMidNode(&L);
       if (temp->data == 2) {
           printf("\nFindMidNode�ɹ�\n");
       }
   
   
   
   return 0;
}
=======
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

//void Add(LinkedList current)
//{
//    current = (LinkedList)malloc(sizeof(LNode));
//    current->data = current->data + 1;
//}
void visit(ElemType e) {//����
    printf("%d ", e+1);
}

void printLink(struct LNode* L) {   //��ӡ�������ڼ��
    if (L == NULL)  //����Ϊ�յĴ�ӡ
    {
        printf("NULL\n");
        return;
    }
    
    printf("�������£�\n");//����ǿյĴ�ӡ
    LNode* p = L->next;
    while (p != NULL)
    {
        printf("%d->\t", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct LNode* createLinkedList(void) {
    LinkedList L = NULL;//struct LNode* L
    if (InitList(&L) != SUCCESS) {  // ��ʼ���������ʧ���򷵻ؿ�
        printf("ERROR");
        return NULL;
    }

    //����һ���̶����ȹ̶����ݵ�����
    int i = 0;
    LNode* p = L;
    LNode* newNode;
    while (i<5) {
         newNode = (LNode*)malloc(sizeof(LNode));
        if (!newNode) {
            printf("�ڴ����ʧ��\n");
            break;
        }

        newNode->data = i;
        newNode->next = NULL;

        p->next = newNode;
        p = p->next;
        i++;
    }

    printf("SUCCESS\n");
    printLink(L);
    return L;  // ���ش����õ�����
}

int main()
{
    struct LNode* L = NULL;
    struct LNode* p = NULL;    //����ʵ��InsertList�������ڵ�
    struct LNode* q = NULL;
    q = (struct LNode*)malloc(sizeof(LNode));
    int *e = (int*)malloc(2*sizeof(int));  //����ȷ��DeleteList�Ƿ�ɹ���ֵ

    printf("1.���濪ʼ����ͷ�ļ���InitList"); 
        L=createLinkedList();   //����������ʼ������ӡ
        if (L != NULL) {
            printf("InitList�ɹ�\n");
        }


    printf("\n2.���濪ʼ����ͷ�ļ���DestroyList\n");
        DestroyList(&L);    //�ݻ�������ӡȷ��
        printLink(L);   //��ӡ��֤�Ƿ����
        if (L == NULL) {
            printf("DestroyList�ɹ�\n");
        }


    printf("\n3.���濪ʼ����ͷ�ļ���InsertList");
        L=createLinkedList();   //����������ʼ������ӡ
        p = L->next;    //�Զ���p�ĵ�Ϊͷ����һλ
        q->data = 10;   //�Զ���q��ֵ����ʼ���ڵ�q��
        q->next = NULL;
        InsertList(p,q);
        printLink(L);   //��ӡ��֤�Ƿ����
        if (L->next->next->data == q->data) {
            printf("InsertList�ɹ�\n");
        }


    printf("\n4.���濪ʼ����ͷ�ļ���DeleteList\n");
        int flg = q->data;
        DeleteList(L->next, e);   //��q�ڵ�ɾȥ��֤DeleteList
        printLink(L);
        printf("e=%d", *e);
        if (*e == flg) {
            printf("\nDeleteList�ɹ�\n");
        }



    printf("\n5.���濪ʼ����ͷ�ļ���TraverseList\n");
        TraverseList(L, visit);


    printf("\n6.���濪ʼ����ͷ�ļ���SearchListt\n");
        printf("�����������1��99\n");
        if (SearchList(L, 1) == SUCCESS|| SearchList(L, 99)==ERROR) {
            printf("\nSearchListt�ɹ���\n");
        }

    
    //printf("\n7.���濪ʼ����ͷ�ļ���ReverseList\n");
    //if (ReverseList(&L) == SUCCESS) {
    //    printf("���óɹ�");
    //    printLink(L);
    //}
    //else {
    //    printf("����ʧ��");
    //}



   printf("\n8.���濪ʼ����ͷ�ļ���IsLoopList\n"); 
       if (IsLoopList(L) == ERROR) {
           printf("\n��ѭ��\n");
           printf("IsLoopList�ɹ�\n");
       }else {
           printf("\n��ѭ��\n");
           printf("IsLoopList�ɹ�\n");
   }

       
   /*printf("\n9.���濪ʼ����ͷ�ļ���ReverseEvenList\n");
        ReverseEvenList(&L);
        printLink(L);*/
   
   
       printf("\n10.���濪ʼ����ͷ�ļ���FindMidNode\n");
       printLink(L);
       struct LNode* temp = FindMidNode(&L);
       if (temp->data == 2) {
           printf("\nFindMidNode�ɹ�\n");
       }
   
   
   
   return 0;
}
>>>>>>> 9cd57e0 (commit)
