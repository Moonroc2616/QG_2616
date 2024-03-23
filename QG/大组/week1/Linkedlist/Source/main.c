<<<<<<< HEAD
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
void visit(ElemType e) {//测试
    printf("%d ", e+1);
}

void printLink(struct LNode* L) {   //打印链表，便于检查
    if (L == NULL)  //链表为空的打印
    {
        printf("NULL\n");
        return;
    }
    
    printf("链表如下：\n");//链表非空的打印
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
    if (InitList(&L) != SUCCESS) {  // 初始化链表，如果失败则返回空
        printf("ERROR");
        return NULL;
    }

    //创建一个固定长度固定数据的链表
    int i = 0;
    LNode* p = L;
    LNode* newNode;
    while (i<5) {
         newNode = (LNode*)malloc(sizeof(LNode));
        if (!newNode) {
            printf("内存分配失败\n");
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
    return L;  // 返回创建好的链表
}

int main()
{
    struct LNode* L = NULL;
    struct LNode* p = NULL;    //用于实现InsertList的两个节点
    struct LNode* q = NULL;
    q = (struct LNode*)malloc(sizeof(LNode));
    int *e = (int*)malloc(2*sizeof(int));  //用于确认DeleteList是否成功赋值

    printf("1.下面开始测试头文件的InitList"); 
        L=createLinkedList();   //建立链表并初始化并打印
        if (L != NULL) {
            printf("InitList成功\n");
        }


    printf("\n2.下面开始测试头文件的DestroyList\n");
        DestroyList(&L);    //摧毁链表并打印确认
        printLink(L);   //打印验证是否插入
        if (L == NULL) {
            printf("DestroyList成功\n");
        }


    printf("\n3.下面开始测试头文件的InsertList");
        L=createLinkedList();   //建立链表并初始化并打印
        p = L->next;    //自定义p的点为头结点后一位
        q->data = 10;   //自定义q的值（初始化节点q）
        q->next = NULL;
        InsertList(p,q);
        printLink(L);   //打印验证是否插入
        if (L->next->next->data == q->data) {
            printf("InsertList成功\n");
        }


    printf("\n4.下面开始测试头文件的DeleteList\n");
        int flg = q->data;
        DeleteList(L->next, e);   //将q节点删去验证DeleteList
        printLink(L);
        printf("e=%d", *e);
        if (*e == flg) {
            printf("\nDeleteList成功\n");
        }



    printf("\n5.下面开始测试头文件的TraverseList\n");
        TraverseList(L, visit);


    printf("\n6.下面开始测试头文件的SearchListt\n");
        printf("假设查找数字1和99\n");
        if (SearchList(L, 1) == SUCCESS|| SearchList(L, 99)==ERROR) {
            printf("\nSearchListt成功！\n");
        }

    
    //printf("\n7.下面开始测试头文件的ReverseList\n");
    //if (ReverseList(&L) == SUCCESS) {
    //    printf("逆置成功");
    //    printLink(L);
    //}
    //else {
    //    printf("逆置失败");
    //}



   printf("\n8.下面开始测试头文件的IsLoopList\n"); 
       if (IsLoopList(L) == ERROR) {
           printf("\n无循环\n");
           printf("IsLoopList成功\n");
       }else {
           printf("\n有循环\n");
           printf("IsLoopList成功\n");
   }

       
   /*printf("\n9.下面开始测试头文件的ReverseEvenList\n");
        ReverseEvenList(&L);
        printLink(L);*/
   
   
       printf("\n10.下面开始测试头文件的FindMidNode\n");
       printLink(L);
       struct LNode* temp = FindMidNode(&L);
       if (temp->data == 2) {
           printf("\nFindMidNode成功\n");
       }
   
   
   
   return 0;
}
=======
#define  _CRT_SECURE_NO_WARNINGS
=======
锘�#define  _CRT_SECURE_NO_WARNINGS
>>>>>>> 580d798 (homework 3.23new)
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

//void Add(LinkedList current)
//{
//    current = (LinkedList)malloc(sizeof(LNode));
//    current->data = current->data + 1;
//}
void visit(ElemType e) {//娴嬭瘯
    printf("%d ", e+1);
}

void printLink(struct LNode* L) {   //鎵撳嵃閾捐〃锛屼究浜庢鏌�
    if (L == NULL)  //閾捐〃涓虹┖鐨勬墦鍗�
    {
        printf("NULL\n");
        return;
    }
    
    printf("閾捐〃濡備笅锛歕n");//閾捐〃闈炵┖鐨勬墦鍗�
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
    if (InitList(&L) != SUCCESS) {  // 鍒濆鍖栭摼琛紝濡傛灉澶辫触鍒欒繑鍥炵┖
        printf("ERROR");
        return NULL;
    }

    //鍒涘缓涓�涓浐瀹氶暱搴﹀浐瀹氭暟鎹殑閾捐〃
    int i = 0;
    LNode* p = L;
    LNode* newNode;
    while (i<5) {
         newNode = (LNode*)malloc(sizeof(LNode));
        if (!newNode) {
            printf("鍐呭瓨鍒嗛厤澶辫触\n");
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
    return L;  // 杩斿洖鍒涘缓濂界殑閾捐〃
}

int main()
{
    struct LNode* L = NULL;
    struct LNode* p = NULL;    //鐢ㄤ簬瀹炵幇InsertList鐨勪袱涓妭鐐�
    struct LNode* q = NULL;
    q = (struct LNode*)malloc(sizeof(LNode));
    int *e = (int*)malloc(2*sizeof(int));  //鐢ㄤ簬纭DeleteList鏄惁鎴愬姛璧嬪��

    printf("1.涓嬮潰寮�濮嬫祴璇曞ご鏂囦欢鐨処nitList"); 
        L=createLinkedList();   //寤虹珛閾捐〃骞跺垵濮嬪寲骞舵墦鍗�
        if (L != NULL) {
            printf("InitList鎴愬姛\n");
        }


    printf("\n2.涓嬮潰寮�濮嬫祴璇曞ご鏂囦欢鐨凞estroyList\n");
        DestroyList(&L);    //鎽ф瘉閾捐〃骞舵墦鍗扮‘璁�
        printLink(L);   //鎵撳嵃楠岃瘉鏄惁鎻掑叆
        if (L == NULL) {
            printf("DestroyList鎴愬姛\n");
        }


    printf("\n3.涓嬮潰寮�濮嬫祴璇曞ご鏂囦欢鐨処nsertList");
        L=createLinkedList();   //寤虹珛閾捐〃骞跺垵濮嬪寲骞舵墦鍗�
        p = L->next;    //鑷畾涔塸鐨勭偣涓哄ご缁撶偣鍚庝竴浣�
        q->data = 10;   //鑷畾涔塹鐨勫�硷紙鍒濆鍖栬妭鐐筿锛�
        q->next = NULL;
        InsertList(p,q);
        printLink(L);   //鎵撳嵃楠岃瘉鏄惁鎻掑叆
        if (L->next->next->data == q->data) {
            printf("InsertList鎴愬姛\n");
        }


    printf("\n4.涓嬮潰寮�濮嬫祴璇曞ご鏂囦欢鐨凞eleteList\n");
        int flg = q->data;
        DeleteList(L->next, e);   //灏唓鑺傜偣鍒犲幓楠岃瘉DeleteList
        printLink(L);
        printf("e=%d", *e);
        if (*e == flg) {
            printf("\nDeleteList鎴愬姛\n");
        }



    printf("\n5.涓嬮潰寮�濮嬫祴璇曞ご鏂囦欢鐨凾raverseList\n");
        TraverseList(L, visit);


    printf("\n6.涓嬮潰寮�濮嬫祴璇曞ご鏂囦欢鐨凷earchListt\n");
        printf("鍋囪鏌ユ壘鏁板瓧1鍜�99\n");
        if (SearchList(L, 1) == SUCCESS|| SearchList(L, 99)==ERROR) {
            printf("\nSearchListt鎴愬姛锛乗n");
        }

    
    //printf("\n7.涓嬮潰寮�濮嬫祴璇曞ご鏂囦欢鐨凴everseList\n");
    //if (ReverseList(&L) == SUCCESS) {
    //    printf("閫嗙疆鎴愬姛");
    //    printLink(L);
    //}
    //else {
    //    printf("閫嗙疆澶辫触");
    //}



   printf("\n8.涓嬮潰寮�濮嬫祴璇曞ご鏂囦欢鐨処sLoopList\n"); 
       if (IsLoopList(L) == ERROR) {
           printf("\n鏃犲惊鐜痋n");
           printf("IsLoopList鎴愬姛\n");
       }else {
           printf("\n鏈夊惊鐜痋n");
           printf("IsLoopList鎴愬姛\n");
   }

       
   /*printf("\n9.涓嬮潰寮�濮嬫祴璇曞ご鏂囦欢鐨凴everseEvenList\n");
        ReverseEvenList(&L);
        printLink(L);*/
   
   
       printf("\n10.涓嬮潰寮�濮嬫祴璇曞ご鏂囦欢鐨凢indMidNode\n");
       printLink(L);
       struct LNode* temp = FindMidNode(&L);
       if (temp->data == 2) {
           printf("\nFindMidNode鎴愬姛\n");
       }
   
   
       getchar();
   return 0;
}
>>>>>>> 9cd57e0 (commit)
