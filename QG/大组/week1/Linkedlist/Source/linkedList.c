<<<<<<< HEAD
<<<<<<< HEAD
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_C_INCLUDED
#define LINKEDLIST_C_INCLUDED

Status InitList(LinkedList* L) {
    printf("\nµ÷ÓÃLinkedListÖÐ\n");
    LNode* curr = (LinkedList)malloc(sizeof(LNode));
    curr->next = NULL;

    *L = curr; // ·ÖÅäÍ·½áµã¿Õ¼ä
    if ((*L) == NULL) {
        return ERROR;  // ÄÚ´æ·ÖÅäÊ§°Ü
    }

    return SUCCESS;  // ³õÊ¼»¯³É¹¦
}


void DestroyList(LinkedList* L) {
    printf("¿ªÊ¼µ÷ÓÃDestroyList\n");
    if ((*L) == NULL) {
        printf("\nÁ´±í×ÔÎª¿Õ");  //Á´±íÎª¿ÕµÄÇé¿ö
        return;
    }

    LinkedList current = *L;  // µ±Ç°½ÚµãÖ¸Õë
    LinkedList currentNext=NULL;  // ÏÂÒ»¸ö½ÚµãÖ¸Õë

    while (current != NULL) {
        currentNext = current->next;  // ±£´æÏÂÒ»¸ö½ÚµãÖ¸Õë
        free(current);          // ÊÍ·Åµ±Ç°½ÚµãÄÚ´æ
        current = currentNext;  // ÒÆ¶¯µ½ÏÂÒ»¸ö½Úµã
        
    }
    *L = NULL;  // Í·Ö¸ÕëÖÃ¿Õ
    printf("Á´±íÒÑÏú»Ù\n");
}

Status InsertList(LNode* p, LNode* q) {
    printf("¿ªÊ¼µ÷ÓÃInsertList");
    q->next = p->next;  //pÁ¬½ÓqµÄºóÒ»Î» 
    p->next = q;    //ÔÙÈÃpÁ´½ÓÖÁq                   
}

//Status DeleteList(LNode* p, ElemType* e) {
//    printf("¿ªÊ¼µ÷ÓÃDeleteList");
//    LinkedList current = p;  // µ±Ç°½ÚµãÖ¸Õë
//    LinkedList currentNext=current->next;  // ÏÂÒ»¸ö½ÚµãÖ¸Õë
//
//    e = currentNext->data;  //½«pºóÒ»Î»µÄdata¸³Öµ¸øe
//    current = currentNext->next;    //Á´½ÓÖÁpºóµÚ¶þÎ»
//    free(currentNext);  //ÊÍ·ÅpºóÒ»Î»
//}
Status DeleteList(LNode* p, ElemType* e) {
    if (p == NULL || p->next == NULL) {
        return ERROR; // ½ÚµãÎª¿Õ»òÕßpÊÇ×îºóÒ»¸ö½Úµã£¬ÎÞ·¨É¾³ý
    }
    LinkedList currentNext = p->next;  // ÒªÉ¾³ýµÄ½Úµã
    *e = currentNext->data;  // ½«ÒªÉ¾³ý½ÚµãµÄÊý¾Ý¸³Öµ¸øe
    printf("É¾È¥£º%d\n", currentNext->data);
    p->next = currentNext->next;  // É¾³ý½Úµã£¬ÐÞ¸ÄpµÄnextÖ¸Õë
    free(currentNext);  // ÊÍ·ÅÉ¾³ýµÄ½ÚµãÄÚ´æ

    return SUCCESS;
}


void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    printf("¿ªÊ¼µ÷ÓÃTraverseList");
    LinkedList current = L->next;     //µ±Ç°Ö¸Õë
    printf("\n");
    while (current!= NULL) {
        visit(current->data);   //µ÷ÓÃº¯Êý
        current = current->next;    //¼ÌÐø±éÀúÁ´±í
    }
    printf("\nTraverseList³É¹¦\n");
}

Status SearchList(LinkedList L, ElemType e) {
    printf("¿ªÊ¼µ÷ÓÃSearchList");
    LinkedList current = L;     //µ±Ç°Ö¸Õë

    while (current != NULL) {
        if (current->data == e) {           
            return SUCCESS;
        }
        current = current->next;    //¼ÌÐø±éÀúÁ´±í
    }
    return ERROR;
}

Status ReverseList(LinkedList* L) {
    printf("¿ªÊ¼µ÷ÓÃReverseList");
    if (*L == NULL) {
        printf("\nÁ´±íÎª¿Õ\n");
        return SUCCESS;
    }

         LNode*  prev = *L;     //Ç°Ò»¸ö½Úµã
         LNode* current = (*L)->next;     //µ±Ç°½Úµã
        //current = (struct LNode*)malloc(sizeof(LNode));
         LNode* currentNext=(*L)->next->next;//ÏÂÒ»¸ö½Úµã
       // currentNext = (struct LNode*)malloc(sizeof(LNode));

        while (current != NULL) {
            currentNext = current->next; // ±£´æµ±Ç°½ÚµãµÄÏÂÒ»¸ö½Úµã
            current->next = prev; // ½«µ±Ç°½ÚµãÖ¸ÏòÇ°Ò»¸ö½Úµã
            prev = current; // ¸üÐÂÇ°Ò»¸ö½ÚµãÎªµ±Ç°½Úµã
            current = currentNext; // ¸üÐÂµ±Ç°½ÚµãÎªÏÂÒ»¸ö½Úµã
        }

        *L = prev; // ¸üÐÂÁ´±íÍ·½Úµã

        return SUCCESS;
    }

Status IsLoopList(LinkedList L) {
    printf("¿ªÊ¼µ÷ÓÃIsLoopList");
        if (L == NULL || L->next == NULL) {
            return ERROR; // ´¦Àí¿ÕÁ´±í»òÖ»ÓÐÒ»¸ö½ÚµãµÄÇé¿ö£¬¿Ï¶¨²»´æÔÚÑ­»·
        }

        LinkedList slow = L;
        LinkedList fast = L;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // ÂýÖ¸ÕëÃ¿´ÎÒÆ¶¯Ò»¸ö½Úµã
            fast = fast->next->next;     // ¿ìÖ¸ÕëÃ¿´ÎÒÆ¶¯Á½¸ö½Úµã

            if (slow == fast) {
                return SUCCESS;  // ¿ìÂýÖ¸ÕëÏàÓö£¬´æÔÚÑ­»·
            }
        }

        return ERROR; // ¿ìÖ¸ÕëÏÈµ½´ïÁ´±íÎ²²¿£¬²»´æÔÚÑ­»·
    }

LNode* ReverseEvenList(LinkedList* L) {
    printf("¿ªÊ¼µ÷ÓÃReverseEvenList");
    
    LinkedList current = *L)->next;
    current = (LinkedList)malloc(sizeof(LNode));
    LinkedList prve = current->next;

    while (current != NULL &&current->next!=NULL) {
        prve = current;
        current = current->next;

        if (current->data % 2 == 0) {   //ÅÐ¶ÏÊÇ·ñÊÇÅ¼Êý
            prve->next=current->next;    //ÓëÇ°Ò»Î»½ÚµãÌæ»»Î»ÖÃ
            current->next = prve;
            prve = current;     //È·±£prveºÍcurrÔÚÍ¬Ò»Î»ÖÃ
        }
    }
}


LNode* FindMidNode(LinkedList* L) {
    printf("¿ªÊ¼µ÷ÓÃFindMidNode");
    if ((*L) == NULL || (*L)->next == NULL) {
        return (*L); // ´¦Àí¿ÕÁ´±í»òÖ»ÓÐÒ»¸ö½ÚµãµÄÇé¿ö
    }

    LNode* slow = (*L);
    LNode* fast = (*L);

    while (fast != NULL) {
        slow = slow->next;           // ÂýÖ¸ÕëÃ¿´ÎÒÆ¶¯Ò»¸ö½Úµã
        fast = fast->next->next;     // ¿ìÖ¸ÕëÃ¿´ÎÒÆ¶¯Á½¸ö½Úµã
    }

    return slow;
}



=======
#include "linkedList.h"
=======
ï»¿#include "linkedList.h"
>>>>>>> 580d798 (homework 3.23new)
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_C_INCLUDED
#define LINKEDLIST_C_INCLUDED

Status InitList(LinkedList* L) {
    printf("\nè°ƒç”¨LinkedListä¸­\n");
    LNode* curr = (LinkedList)malloc(sizeof(LNode));
    curr->next = NULL;

    *L = curr; // åˆ†é…å¤´ç»“ç‚¹ç©ºé—´
    if ((*L) == NULL) {
        return ERROR;  // å†…å­˜åˆ†é…å¤±è´¥
    }

    return SUCCESS;  // åˆå§‹åŒ–æˆåŠŸ
}


void DestroyList(LinkedList* L) {
    printf("å¼€å§‹è°ƒç”¨DestroyList\n");
    if ((*L) == NULL) {
        printf("\né“¾è¡¨è‡ªä¸ºç©º");  //é“¾è¡¨ä¸ºç©ºçš„æƒ…å†µ
        return;
    }

    LinkedList current = *L;  // å½“å‰èŠ‚ç‚¹æŒ‡é’ˆ
    LinkedList currentNext=NULL;  // ä¸‹ä¸€ä¸ªèŠ‚ç‚¹æŒ‡é’ˆ

    while (current != NULL) {
        currentNext = current->next;  // ä¿å­˜ä¸‹ä¸€ä¸ªèŠ‚ç‚¹æŒ‡é’ˆ
        free(current);          // é‡Šæ”¾å½“å‰èŠ‚ç‚¹å†…å­˜
        current = currentNext;  // ç§»åŠ¨åˆ°ä¸‹ä¸€ä¸ªèŠ‚ç‚¹
        
    }
    *L = NULL;  // å¤´æŒ‡é’ˆç½®ç©º
    printf("é“¾è¡¨å·²é”€æ¯\n");
}

Status InsertList(LNode* p, LNode* q) {
    printf("å¼€å§‹è°ƒç”¨InsertList");
    q->next = p->next;  //pè¿žæŽ¥qçš„åŽä¸€ä½ 
    p->next = q;    //å†è®©pé“¾æŽ¥è‡³q                   
}

//Status DeleteList(LNode* p, ElemType* e) {
//    printf("å¼€å§‹è°ƒç”¨DeleteList");
//    LinkedList current = p;  // å½“å‰èŠ‚ç‚¹æŒ‡é’ˆ
//    LinkedList currentNext=current->next;  // ä¸‹ä¸€ä¸ªèŠ‚ç‚¹æŒ‡é’ˆ
//
//    e = currentNext->data;  //å°†påŽä¸€ä½çš„dataèµ‹å€¼ç»™e
//    current = currentNext->next;    //é“¾æŽ¥è‡³påŽç¬¬äºŒä½
//    free(currentNext);  //é‡Šæ”¾påŽä¸€ä½
//}
Status DeleteList(LNode* p, ElemType* e) {
    if (p == NULL || p->next == NULL) {
        return ERROR; // èŠ‚ç‚¹ä¸ºç©ºæˆ–è€…pæ˜¯æœ€åŽä¸€ä¸ªèŠ‚ç‚¹ï¼Œæ— æ³•åˆ é™¤
    }
    LinkedList currentNext = p->next;  // è¦åˆ é™¤çš„èŠ‚ç‚¹
    *e = currentNext->data;  // å°†è¦åˆ é™¤èŠ‚ç‚¹çš„æ•°æ®èµ‹å€¼ç»™e
    printf("åˆ åŽ»ï¼š%d\n", currentNext->data);
    p->next = currentNext->next;  // åˆ é™¤èŠ‚ç‚¹ï¼Œä¿®æ”¹pçš„nextæŒ‡é’ˆ
    free(currentNext);  // é‡Šæ”¾åˆ é™¤çš„èŠ‚ç‚¹å†…å­˜

    return SUCCESS;
}


void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    printf("å¼€å§‹è°ƒç”¨TraverseList");
    LinkedList current = L->next;     //å½“å‰æŒ‡é’ˆ
    printf("\n");
    while (current!= NULL) {
        visit(current->data);   //è°ƒç”¨å‡½æ•°
        current = current->next;    //ç»§ç»­éåŽ†é“¾è¡¨
    }
    printf("\nTraverseListæˆåŠŸ\n");
}

Status SearchList(LinkedList L, ElemType e) {
    printf("å¼€å§‹è°ƒç”¨SearchList");
    LinkedList current = L;     //å½“å‰æŒ‡é’ˆ

    while (current != NULL) {
        if (current->data == e) {           
            return SUCCESS;
        }
        current = current->next;    //ç»§ç»­éåŽ†é“¾è¡¨
    }
    return ERROR;
}

Status ReverseList(LinkedList* L) {
    printf("å¼€å§‹è°ƒç”¨ReverseList");
    if (*L == NULL) {
        printf("\né“¾è¡¨ä¸ºç©º\n");
        return SUCCESS;
    }

         LNode*  prev = *L;     //å‰ä¸€ä¸ªèŠ‚ç‚¹
         LNode* current = (*L)->next;     //å½“å‰èŠ‚ç‚¹
        //current = (struct LNode*)malloc(sizeof(LNode));
         LNode* currentNext=(*L)->next->next;//ä¸‹ä¸€ä¸ªèŠ‚ç‚¹
       // currentNext = (struct LNode*)malloc(sizeof(LNode));

        while (current != NULL) {
            currentNext = current->next; // ä¿å­˜å½“å‰èŠ‚ç‚¹çš„ä¸‹ä¸€ä¸ªèŠ‚ç‚¹
            current->next = prev; // å°†å½“å‰èŠ‚ç‚¹æŒ‡å‘å‰ä¸€ä¸ªèŠ‚ç‚¹
            prev = current; // æ›´æ–°å‰ä¸€ä¸ªèŠ‚ç‚¹ä¸ºå½“å‰èŠ‚ç‚¹
            current = currentNext; // æ›´æ–°å½“å‰èŠ‚ç‚¹ä¸ºä¸‹ä¸€ä¸ªèŠ‚ç‚¹
        }

        *L = prev; // æ›´æ–°é“¾è¡¨å¤´èŠ‚ç‚¹

        return SUCCESS;
    }

Status IsLoopList(LinkedList L) {
    printf("å¼€å§‹è°ƒç”¨IsLoopList");
        if (L == NULL || L->next == NULL) {
            return ERROR; // å¤„ç†ç©ºé“¾è¡¨æˆ–åªæœ‰ä¸€ä¸ªèŠ‚ç‚¹çš„æƒ…å†µï¼Œè‚¯å®šä¸å­˜åœ¨å¾ªçŽ¯
        }

        LinkedList slow = L;
        LinkedList fast = L;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // æ…¢æŒ‡é’ˆæ¯æ¬¡ç§»åŠ¨ä¸€ä¸ªèŠ‚ç‚¹
            fast = fast->next->next;     // å¿«æŒ‡é’ˆæ¯æ¬¡ç§»åŠ¨ä¸¤ä¸ªèŠ‚ç‚¹

            if (slow == fast) {
                return SUCCESS;  // å¿«æ…¢æŒ‡é’ˆç›¸é‡ï¼Œå­˜åœ¨å¾ªçŽ¯
            }
        }

        return ERROR; // å¿«æŒ‡é’ˆå…ˆåˆ°è¾¾é“¾è¡¨å°¾éƒ¨ï¼Œä¸å­˜åœ¨å¾ªçŽ¯
    }

//LNode* ReverseEvenList(LinkedList* L) {
//    printf("å¼€å§‹è°ƒç”¨ReverseEvenList");
//    
//    LinkedList current = *L->next;
//    current = (LinkedList)malloc(sizeof(LNode));
//    LinkedList prve = current->next;
//
//    while (current != NULL &&current->next!=NULL) {
//        prve = current;
//        current = current->next;
//
//        if (current->data % 2 == 0) {   //åˆ¤æ–­æ˜¯å¦æ˜¯å¶æ•°
//            prve->next=current->next;    //ä¸Žå‰ä¸€ä½èŠ‚ç‚¹æ›¿æ¢ä½ç½®
//            current->next = prve;
//            prve = current;     //ç¡®ä¿prveå’Œcurråœ¨åŒä¸€ä½ç½®
//        }
//    }
//}


LNode* FindMidNode(LinkedList* L) {
    printf("å¼€å§‹è°ƒç”¨FindMidNode");
    if ((*L) == NULL || (*L)->next == NULL) {
        return (*L); // å¤„ç†ç©ºé“¾è¡¨æˆ–åªæœ‰ä¸€ä¸ªèŠ‚ç‚¹çš„æƒ…å†µ
    }

    LNode* slow = (*L);
    LNode* fast = (*L);

    while (fast != NULL) {
        slow = slow->next;           // æ…¢æŒ‡é’ˆæ¯æ¬¡ç§»åŠ¨ä¸€ä¸ªèŠ‚ç‚¹
        fast = fast->next->next;     // å¿«æŒ‡é’ˆæ¯æ¬¡ç§»åŠ¨ä¸¤ä¸ªèŠ‚ç‚¹
    }

    return slow;
}



>>>>>>> 9cd57e0 (commit)
#endif