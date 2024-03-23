<<<<<<< HEAD
<<<<<<< HEAD
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

LNode* ReverseEvenList(LinkedList* L) {
    printf("开始调用ReverseEvenList");
    
    LinkedList current = *L)->next;
    current = (LinkedList)malloc(sizeof(LNode));
    LinkedList prve = current->next;

    while (current != NULL &&current->next!=NULL) {
        prve = current;
        current = current->next;

        if (current->data % 2 == 0) {   //判断是否是偶数
            prve->next=current->next;    //与前一位节点替换位置
            current->next = prve;
            prve = current;     //确保prve和curr在同一位置
        }
    }
}


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



=======
#include "linkedList.h"
=======
锘�#include "linkedList.h"
>>>>>>> 580d798 (homework 3.23new)
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_C_INCLUDED
#define LINKEDLIST_C_INCLUDED

Status InitList(LinkedList* L) {
    printf("\n璋冪敤LinkedList涓璡n");
    LNode* curr = (LinkedList)malloc(sizeof(LNode));
    curr->next = NULL;

    *L = curr; // 鍒嗛厤澶寸粨鐐圭┖闂�
    if ((*L) == NULL) {
        return ERROR;  // 鍐呭瓨鍒嗛厤澶辫触
    }

    return SUCCESS;  // 鍒濆鍖栨垚鍔�
}


void DestroyList(LinkedList* L) {
    printf("寮�濮嬭皟鐢―estroyList\n");
    if ((*L) == NULL) {
        printf("\n閾捐〃鑷负绌�");  //閾捐〃涓虹┖鐨勬儏鍐�
        return;
    }

    LinkedList current = *L;  // 褰撳墠鑺傜偣鎸囬拡
    LinkedList currentNext=NULL;  // 涓嬩竴涓妭鐐规寚閽�

    while (current != NULL) {
        currentNext = current->next;  // 淇濆瓨涓嬩竴涓妭鐐规寚閽�
        free(current);          // 閲婃斁褰撳墠鑺傜偣鍐呭瓨
        current = currentNext;  // 绉诲姩鍒颁笅涓�涓妭鐐�
        
    }
    *L = NULL;  // 澶存寚閽堢疆绌�
    printf("閾捐〃宸查攢姣乗n");
}

Status InsertList(LNode* p, LNode* q) {
    printf("寮�濮嬭皟鐢↖nsertList");
    q->next = p->next;  //p杩炴帴q鐨勫悗涓�浣� 
    p->next = q;    //鍐嶈p閾炬帴鑷硄                   
}

//Status DeleteList(LNode* p, ElemType* e) {
//    printf("寮�濮嬭皟鐢―eleteList");
//    LinkedList current = p;  // 褰撳墠鑺傜偣鎸囬拡
//    LinkedList currentNext=current->next;  // 涓嬩竴涓妭鐐规寚閽�
//
//    e = currentNext->data;  //灏唒鍚庝竴浣嶇殑data璧嬪�肩粰e
//    current = currentNext->next;    //閾炬帴鑷硃鍚庣浜屼綅
//    free(currentNext);  //閲婃斁p鍚庝竴浣�
//}
Status DeleteList(LNode* p, ElemType* e) {
    if (p == NULL || p->next == NULL) {
        return ERROR; // 鑺傜偣涓虹┖鎴栬�卲鏄渶鍚庝竴涓妭鐐癸紝鏃犳硶鍒犻櫎
    }
    LinkedList currentNext = p->next;  // 瑕佸垹闄ょ殑鑺傜偣
    *e = currentNext->data;  // 灏嗚鍒犻櫎鑺傜偣鐨勬暟鎹祴鍊肩粰e
    printf("鍒犲幓锛�%d\n", currentNext->data);
    p->next = currentNext->next;  // 鍒犻櫎鑺傜偣锛屼慨鏀筽鐨刵ext鎸囬拡
    free(currentNext);  // 閲婃斁鍒犻櫎鐨勮妭鐐瑰唴瀛�

    return SUCCESS;
}


void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    printf("寮�濮嬭皟鐢═raverseList");
    LinkedList current = L->next;     //褰撳墠鎸囬拡
    printf("\n");
    while (current!= NULL) {
        visit(current->data);   //璋冪敤鍑芥暟
        current = current->next;    //缁х画閬嶅巻閾捐〃
    }
    printf("\nTraverseList鎴愬姛\n");
}

Status SearchList(LinkedList L, ElemType e) {
    printf("寮�濮嬭皟鐢⊿earchList");
    LinkedList current = L;     //褰撳墠鎸囬拡

    while (current != NULL) {
        if (current->data == e) {           
            return SUCCESS;
        }
        current = current->next;    //缁х画閬嶅巻閾捐〃
    }
    return ERROR;
}

Status ReverseList(LinkedList* L) {
    printf("寮�濮嬭皟鐢≧everseList");
    if (*L == NULL) {
        printf("\n閾捐〃涓虹┖\n");
        return SUCCESS;
    }

         LNode*  prev = *L;     //鍓嶄竴涓妭鐐�
         LNode* current = (*L)->next;     //褰撳墠鑺傜偣
        //current = (struct LNode*)malloc(sizeof(LNode));
         LNode* currentNext=(*L)->next->next;//涓嬩竴涓妭鐐�
       // currentNext = (struct LNode*)malloc(sizeof(LNode));

        while (current != NULL) {
            currentNext = current->next; // 淇濆瓨褰撳墠鑺傜偣鐨勪笅涓�涓妭鐐�
            current->next = prev; // 灏嗗綋鍓嶈妭鐐规寚鍚戝墠涓�涓妭鐐�
            prev = current; // 鏇存柊鍓嶄竴涓妭鐐逛负褰撳墠鑺傜偣
            current = currentNext; // 鏇存柊褰撳墠鑺傜偣涓轰笅涓�涓妭鐐�
        }

        *L = prev; // 鏇存柊閾捐〃澶磋妭鐐�

        return SUCCESS;
    }

Status IsLoopList(LinkedList L) {
    printf("寮�濮嬭皟鐢↖sLoopList");
        if (L == NULL || L->next == NULL) {
            return ERROR; // 澶勭悊绌洪摼琛ㄦ垨鍙湁涓�涓妭鐐圭殑鎯呭喌锛岃偗瀹氫笉瀛樺湪寰幆
        }

        LinkedList slow = L;
        LinkedList fast = L;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // 鎱㈡寚閽堟瘡娆＄Щ鍔ㄤ竴涓妭鐐�
            fast = fast->next->next;     // 蹇寚閽堟瘡娆＄Щ鍔ㄤ袱涓妭鐐�

            if (slow == fast) {
                return SUCCESS;  // 蹇參鎸囬拡鐩搁亣锛屽瓨鍦ㄥ惊鐜�
            }
        }

        return ERROR; // 蹇寚閽堝厛鍒拌揪閾捐〃灏鹃儴锛屼笉瀛樺湪寰幆
    }

//LNode* ReverseEvenList(LinkedList* L) {
//    printf("寮�濮嬭皟鐢≧everseEvenList");
//    
//    LinkedList current = *L->next;
//    current = (LinkedList)malloc(sizeof(LNode));
//    LinkedList prve = current->next;
//
//    while (current != NULL &&current->next!=NULL) {
//        prve = current;
//        current = current->next;
//
//        if (current->data % 2 == 0) {   //鍒ゆ柇鏄惁鏄伓鏁�
//            prve->next=current->next;    //涓庡墠涓�浣嶈妭鐐规浛鎹綅缃�
//            current->next = prve;
//            prve = current;     //纭繚prve鍜宑urr鍦ㄥ悓涓�浣嶇疆
//        }
//    }
//}


LNode* FindMidNode(LinkedList* L) {
    printf("寮�濮嬭皟鐢‵indMidNode");
    if ((*L) == NULL || (*L)->next == NULL) {
        return (*L); // 澶勭悊绌洪摼琛ㄦ垨鍙湁涓�涓妭鐐圭殑鎯呭喌
    }

    LNode* slow = (*L);
    LNode* fast = (*L);

    while (fast != NULL) {
        slow = slow->next;           // 鎱㈡寚閽堟瘡娆＄Щ鍔ㄤ竴涓妭鐐�
        fast = fast->next->next;     // 蹇寚閽堟瘡娆＄Щ鍔ㄤ袱涓妭鐐�
    }

    return slow;
}



>>>>>>> 9cd57e0 (commit)
#endif