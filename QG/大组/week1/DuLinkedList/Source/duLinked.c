#include "duLinked.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_C_INCLUDED
#define LINKEDLIST_C_INCLUDED

Status InitList_DuL(DuLinkedList* L) {
	//创建链表（带头结点）
	(*L) = (DuLNode*)malloc(sizeof(DuLNode));
	if (!(*L)) {
		return ERROR;
	}

	(*L)->next = (*L);
	(*L)->prior = (*L);
	return SUCCESS;
}


void DestroyList_DuL(DuLinkedList* L){
	//删除链表:从头的下一位开始，利用tmp临时节点删去节点直至只剩头结点,最后再删去头结点即可
	if (!(*L)) {
		printf("链表为空\n");
		return SUCCESS;
	}
	DuLNode* curr = (*L)->next;
	while (curr != *(L)&&curr->next!=NULL) {
		DuLNode* tmp = curr->next;
		free(curr);
		curr = tmp;
	}

	free(*L);
	return SUCCESS;
}


Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	if (p == NULL || q == NULL) {
		return ERROR; // 返回错误状态，如果节点 p 或节点 q 为空
	}

	DuLNode* prior_node = p->prior; // 获取节点 p 的前一个节点
	q->next = p;
	q->prior = prior_node;
	p->prior = q;
	prior_node->next = q;

	return SUCCESS; // 返回成功状态
}


Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	//插入数据：q插于p后
	if (p == NULL || q == NULL) {
		return ERROR; // 返回错误状态，如果节点 p 或节点 q 为空
	}

	DuLNode* Next_node = p->next; // 获取节点 p 的前一个节点

	if (Next_node != NULL) {
		Next_node->prior = q;
	}

	q->next = Next_node;
	q->prior = p;
	p->next = q;

	return SUCCESS; // 返回成功状态
}


Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	//删除节点：删去p后第一个节点并把它的值赋给e
	if (p == NULL || p->next == NULL) {
		return ERROR; // 返回错误状态，如果节点 p 或节点 p 的后一个节点为空
	}

	DuLNode* Next_node = p->next; 
	//e = (DuLNode*)malloc(sizeof(DuLNode));
	*e = Next_node->data;

	p->next = Next_node->next;//实现删除
	Next_node->prior = NULL;
	Next_node->next->prior = p;
	Next_node->next = NULL;
	free(Next_node);

}


void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	//便利链表并对每一个节点数据使用函数visit()
	DuLinkedList curr = L->next;
	while (curr->next != NULL) {
		visit(curr->data);
		 curr=curr->next;
	}


}


#endif