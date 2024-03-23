#include "duLinked.h"
#include <stdio.h>
#include <stdlib.h>

void printList(DuLNode* head) {
	//打印链表便于检查
	printf("下面是双向链表:\n");
	//if (head == NULL || head->next == NULL) {
	//	printf("链表为空\n");
	//	return;
	//}
	DuLNode* current = head->next; // 从头结点的下一个节点开始遍历
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("结束\n");
}

void valuesToDuLinkedList(DuLNode* head) {
	DuLNode* current = head;

	// 为链表节点赋值
	for (int i = 0; i < 5; i++) {
		DuLNode* newNode = (DuLNode*)malloc(sizeof(DuLNode));
		newNode->data = (i+1);
		newNode->prior = current;
		newNode->next = NULL;
		current->next = newNode;
		current = newNode;
	}

	// 设置最后一个节点的前驱指针
	current->next = NULL;
}

void visit(int n) {
	printf(" %d",n);
}

int main() 
{
	DuLNode* L = NULL;//头结点
	DuLNode* q = (DuLNode * )malloc(sizeof(DuLNode));//用于测试前插入功能的节点
	q->data = 2616;
	q->next = NULL;
	q->prior = NULL;

	DuLNode* p = (DuLNode*)malloc(sizeof(DuLNode));//用于测试后插入功能的节点
	p->data = 2518;
	p->next = NULL;
	p->prior = NULL;
	
	int e=-1;
	
	printf("1.测试初始化双向链表InitList_DuL\n");
	if (InitList_DuL(&L) == SUCCESS) {
		printf("InitList_DuL成功\n");
	}
	else {
		printf("失败\n");
	}


	valuesToDuLinkedList(L);
	printList(L);


	printf("\n2.测试删除双向链表DestroyList_DuL\n");
	DestroyList_DuL(&L);
	if (L) {
		printf("DestroyList_DuL成功\n"); 
	}
	else {
		printf("失败\n");
	}


	printf("\n3.测试插入双向链表InsertBeforeList_DuL\n");
	InitList_DuL(&L);	//删除链表后重新创建链表并赋值
	valuesToDuLinkedList(L);	
	printList(L);

	InsertBeforeList_DuL(L->next->next, q);
	if (L) {
		printf("InsertBeforeList_DuL成功\n");
		printList(L);
	}
	else {
		printf("失败\n");
	}


	printf("\n4.测试插入双向链表InsertAfterList_DuL\n");
	InsertAfterList_DuL(L->next->next, p);
	if (L->next) {
		printf("InsertAfterList_DuL成功\n");
		printList(L);
	}
	else {
		printf("失败\n");
	}


	printf("\n5.测试删除双向链表节点DeleteList_DuLL\n");
	DeleteList_DuL(L,&e);
	if (e!=-1) {
		printf("DeleteList_DuLL成功\n");
		printList(L);
		printf("e=%d\n", e);
	}
	else {
		printf("失败\n");
	}


	printf("\n5.测试删除双向链表节点TraverseList_DuL\n");
	TraverseList_DuL(L, visit);
	printList(L);

	getchar();
	return 0;
}