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
void visit(ElemType e) {//²âÊÔ
    printf("%d ", e+1);
}

void printLink(struct LNode* L) {   //´òÓ¡Á´±í£¬±ãÓÚ¼ì²é
    if (L == NULL)  //Á´±íÎª¿ÕµÄ´òÓ¡
    {
        printf("NULL\n");
        return;
    }
    
    printf("Á´±íÈçÏÂ£º\n");//Á´±í·Ç¿ÕµÄ´òÓ¡
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
    if (InitList(&L) != SUCCESS) {  // ³õÊ¼»¯Á´±í£¬Èç¹ûÊ§°ÜÔò·µ»Ø¿Õ
        printf("ERROR");
        return NULL;
    }

    //´´½¨Ò»¸ö¹Ì¶¨³¤¶È¹Ì¶¨Êı¾İµÄÁ´±í
    int i = 0;
    LNode* p = L;
    LNode* newNode;
    while (i<5) {
         newNode = (LNode*)malloc(sizeof(LNode));
        if (!newNode) {
            printf("ÄÚ´æ·ÖÅäÊ§°Ü\n");
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
    return L;  // ·µ»Ø´´½¨ºÃµÄÁ´±í
}

int main()
{
    struct LNode* L = NULL;
    struct LNode* p = NULL;    //ÓÃÓÚÊµÏÖInsertListµÄÁ½¸ö½Úµã
    struct LNode* q = NULL;
    q = (struct LNode*)malloc(sizeof(LNode));
    int *e = (int*)malloc(2*sizeof(int));  //ÓÃÓÚÈ·ÈÏDeleteListÊÇ·ñ³É¹¦¸³Öµ

    printf("1.ÏÂÃæ¿ªÊ¼²âÊÔÍ·ÎÄ¼şµÄInitList"); 
        L=createLinkedList();   //½¨Á¢Á´±í²¢³õÊ¼»¯²¢´òÓ¡
        if (L != NULL) {
            printf("InitList³É¹¦\n");
        }


    printf("\n2.ÏÂÃæ¿ªÊ¼²âÊÔÍ·ÎÄ¼şµÄDestroyList\n");
        DestroyList(&L);    //´İ»ÙÁ´±í²¢´òÓ¡È·ÈÏ
        printLink(L);   //´òÓ¡ÑéÖ¤ÊÇ·ñ²åÈë
        if (L == NULL) {
            printf("DestroyList³É¹¦\n");
        }


    printf("\n3.ÏÂÃæ¿ªÊ¼²âÊÔÍ·ÎÄ¼şµÄInsertList");
        L=createLinkedList();   //½¨Á¢Á´±í²¢³õÊ¼»¯²¢´òÓ¡
        p = L->next;    //×Ô¶¨ÒåpµÄµãÎªÍ·½áµãºóÒ»Î»
        q->data = 10;   //×Ô¶¨ÒåqµÄÖµ£¨³õÊ¼»¯½Úµãq£©
        q->next = NULL;
        InsertList(p,q);
        printLink(L);   //´òÓ¡ÑéÖ¤ÊÇ·ñ²åÈë
        if (L->next->next->data == q->data) {
            printf("InsertList³É¹¦\n");
        }


    printf("\n4.ÏÂÃæ¿ªÊ¼²âÊÔÍ·ÎÄ¼şµÄDeleteList\n");
        int flg = q->data;
        DeleteList(L->next, e);   //½«q½ÚµãÉ¾È¥ÑéÖ¤DeleteList
        printLink(L);
        printf("e=%d", *e);
        if (*e == flg) {
            printf("\nDeleteList³É¹¦\n");
        }



    printf("\n5.ÏÂÃæ¿ªÊ¼²âÊÔÍ·ÎÄ¼şµÄTraverseList\n");
        TraverseList(L, visit);


    printf("\n6.ÏÂÃæ¿ªÊ¼²âÊÔÍ·ÎÄ¼şµÄSearchListt\n");
        printf("¼ÙÉè²éÕÒÊı×Ö1ºÍ99\n");
        if (SearchList(L, 1) == SUCCESS|| SearchList(L, 99)==ERROR) {
            printf("\nSearchListt³É¹¦£¡\n");
        }

    
    //printf("\n7.ÏÂÃæ¿ªÊ¼²âÊÔÍ·ÎÄ¼şµÄReverseList\n");
    //if (ReverseList(&L) == SUCCESS) {
    //    printf("ÄæÖÃ³É¹¦");
    //    printLink(L);
    //}
    //else {
    //    printf("ÄæÖÃÊ§°Ü");
    //}



   printf("\n8.ÏÂÃæ¿ªÊ¼²âÊÔÍ·ÎÄ¼şµÄIsLoopList\n"); 
       if (IsLoopList(L) == ERROR) {
           printf("\nÎŞÑ­»·\n");
           printf("IsLoopList³É¹¦\n");
       }else {
           printf("\nÓĞÑ­»·\n");
           printf("IsLoopList³É¹¦\n");
   }

       
   /*printf("\n9.ÏÂÃæ¿ªÊ¼²âÊÔÍ·ÎÄ¼şµÄReverseEvenList\n");
        ReverseEvenList(&L);
        printLink(L);*/
   
   
       printf("\n10.ÏÂÃæ¿ªÊ¼²âÊÔÍ·ÎÄ¼şµÄFindMidNode\n");
       printLink(L);
       struct LNode* temp = FindMidNode(&L);
       if (temp->data == 2) {
           printf("\nFindMidNode³É¹¦\n");
       }
   
   
   
   return 0;
}
=======
#define  _CRT_SECURE_NO_WARNINGS
=======
ï»¿#define  _CRT_SECURE_NO_WARNINGS
>>>>>>> 580d798 (homework 3.23new)
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

//void Add(LinkedList current)
//{
//    current = (LinkedList)malloc(sizeof(LNode));
//    current->data = current->data + 1;
//}
void visit(ElemType e) {//æµ‹è¯•
    printf("%d ", e+1);
}

void printLink(struct LNode* L) {   //æ‰“å°é“¾è¡¨ï¼Œä¾¿äºæ£€æŸ¥
    if (L == NULL)  //é“¾è¡¨ä¸ºç©ºçš„æ‰“å°
    {
        printf("NULL\n");
        return;
    }
    
    printf("é“¾è¡¨å¦‚ä¸‹ï¼š\n");//é“¾è¡¨éç©ºçš„æ‰“å°
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
    if (InitList(&L) != SUCCESS) {  // åˆå§‹åŒ–é“¾è¡¨ï¼Œå¦‚æœå¤±è´¥åˆ™è¿”å›ç©º
        printf("ERROR");
        return NULL;
    }

    //åˆ›å»ºä¸€ä¸ªå›ºå®šé•¿åº¦å›ºå®šæ•°æ®çš„é“¾è¡¨
    int i = 0;
    LNode* p = L;
    LNode* newNode;
    while (i<5) {
         newNode = (LNode*)malloc(sizeof(LNode));
        if (!newNode) {
            printf("å†…å­˜åˆ†é…å¤±è´¥\n");
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
    return L;  // è¿”å›åˆ›å»ºå¥½çš„é“¾è¡¨
}

int main()
{
    struct LNode* L = NULL;
    struct LNode* p = NULL;    //ç”¨äºå®ç°InsertListçš„ä¸¤ä¸ªèŠ‚ç‚¹
    struct LNode* q = NULL;
    q = (struct LNode*)malloc(sizeof(LNode));
    int *e = (int*)malloc(2*sizeof(int));  //ç”¨äºç¡®è®¤DeleteListæ˜¯å¦æˆåŠŸèµ‹å€¼

    printf("1.ä¸‹é¢å¼€å§‹æµ‹è¯•å¤´æ–‡ä»¶çš„InitList"); 
        L=createLinkedList();   //å»ºç«‹é“¾è¡¨å¹¶åˆå§‹åŒ–å¹¶æ‰“å°
        if (L != NULL) {
            printf("InitListæˆåŠŸ\n");
        }


    printf("\n2.ä¸‹é¢å¼€å§‹æµ‹è¯•å¤´æ–‡ä»¶çš„DestroyList\n");
        DestroyList(&L);    //æ‘§æ¯é“¾è¡¨å¹¶æ‰“å°ç¡®è®¤
        printLink(L);   //æ‰“å°éªŒè¯æ˜¯å¦æ’å…¥
        if (L == NULL) {
            printf("DestroyListæˆåŠŸ\n");
        }


    printf("\n3.ä¸‹é¢å¼€å§‹æµ‹è¯•å¤´æ–‡ä»¶çš„InsertList");
        L=createLinkedList();   //å»ºç«‹é“¾è¡¨å¹¶åˆå§‹åŒ–å¹¶æ‰“å°
        p = L->next;    //è‡ªå®šä¹‰pçš„ç‚¹ä¸ºå¤´ç»“ç‚¹åä¸€ä½
        q->data = 10;   //è‡ªå®šä¹‰qçš„å€¼ï¼ˆåˆå§‹åŒ–èŠ‚ç‚¹qï¼‰
        q->next = NULL;
        InsertList(p,q);
        printLink(L);   //æ‰“å°éªŒè¯æ˜¯å¦æ’å…¥
        if (L->next->next->data == q->data) {
            printf("InsertListæˆåŠŸ\n");
        }


    printf("\n4.ä¸‹é¢å¼€å§‹æµ‹è¯•å¤´æ–‡ä»¶çš„DeleteList\n");
        int flg = q->data;
        DeleteList(L->next, e);   //å°†qèŠ‚ç‚¹åˆ å»éªŒè¯DeleteList
        printLink(L);
        printf("e=%d", *e);
        if (*e == flg) {
            printf("\nDeleteListæˆåŠŸ\n");
        }



    printf("\n5.ä¸‹é¢å¼€å§‹æµ‹è¯•å¤´æ–‡ä»¶çš„TraverseList\n");
        TraverseList(L, visit);


    printf("\n6.ä¸‹é¢å¼€å§‹æµ‹è¯•å¤´æ–‡ä»¶çš„SearchListt\n");
        printf("å‡è®¾æŸ¥æ‰¾æ•°å­—1å’Œ99\n");
        if (SearchList(L, 1) == SUCCESS|| SearchList(L, 99)==ERROR) {
            printf("\nSearchListtæˆåŠŸï¼\n");
        }

    
    //printf("\n7.ä¸‹é¢å¼€å§‹æµ‹è¯•å¤´æ–‡ä»¶çš„ReverseList\n");
    //if (ReverseList(&L) == SUCCESS) {
    //    printf("é€†ç½®æˆåŠŸ");
    //    printLink(L);
    //}
    //else {
    //    printf("é€†ç½®å¤±è´¥");
    //}



   printf("\n8.ä¸‹é¢å¼€å§‹æµ‹è¯•å¤´æ–‡ä»¶çš„IsLoopList\n"); 
       if (IsLoopList(L) == ERROR) {
           printf("\næ— å¾ªç¯\n");
           printf("IsLoopListæˆåŠŸ\n");
       }else {
           printf("\næœ‰å¾ªç¯\n");
           printf("IsLoopListæˆåŠŸ\n");
   }

       
   /*printf("\n9.ä¸‹é¢å¼€å§‹æµ‹è¯•å¤´æ–‡ä»¶çš„ReverseEvenList\n");
        ReverseEvenList(&L);
        printLink(L);*/
   
   
       printf("\n10.ä¸‹é¢å¼€å§‹æµ‹è¯•å¤´æ–‡ä»¶çš„FindMidNode\n");
       printLink(L);
       struct LNode* temp = FindMidNode(&L);
       if (temp->data == 2) {
           printf("\nFindMidNodeæˆåŠŸ\n");
       }
   
   
       getchar();
   return 0;
}
>>>>>>> 9cd57e0 (commit)
