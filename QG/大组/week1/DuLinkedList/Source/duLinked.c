#include "duLinked.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_C_INCLUDED
#define LINKEDLIST_C_INCLUDED

Status InitList_DuL(DuLinkedList* L) {
	//����������ͷ��㣩
	(*L) = (DuLNode*)malloc(sizeof(DuLNode));
	if (!(*L)) {
		return ERROR;
	}

	(*L)->next = (*L);
	(*L)->prior = (*L);
	return SUCCESS;
}


void DestroyList_DuL(DuLinkedList* L){
	//ɾ������:��ͷ����һλ��ʼ������tmp��ʱ�ڵ�ɾȥ�ڵ�ֱ��ֻʣͷ���,�����ɾȥͷ��㼴��
	if (!(*L)) {
		printf("����Ϊ��\n");
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
		return ERROR; // ���ش���״̬������ڵ� p ��ڵ� q Ϊ��
	}

	DuLNode* prior_node = p->prior; // ��ȡ�ڵ� p ��ǰһ���ڵ�
	q->next = p;
	q->prior = prior_node;
	p->prior = q;
	prior_node->next = q;

	return SUCCESS; // ���سɹ�״̬
}


Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	//�������ݣ�q����p��
	if (p == NULL || q == NULL) {
		return ERROR; // ���ش���״̬������ڵ� p ��ڵ� q Ϊ��
	}

	DuLNode* Next_node = p->next; // ��ȡ�ڵ� p ��ǰһ���ڵ�

	if (Next_node != NULL) {
		Next_node->prior = q;
	}

	q->next = Next_node;
	q->prior = p;
	p->next = q;

	return SUCCESS; // ���سɹ�״̬
}


Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	//ɾ���ڵ㣺ɾȥp���һ���ڵ㲢������ֵ����e
	if (p == NULL || p->next == NULL) {
		return ERROR; // ���ش���״̬������ڵ� p ��ڵ� p �ĺ�һ���ڵ�Ϊ��
	}

	DuLNode* Next_node = p->next; 
	//e = (DuLNode*)malloc(sizeof(DuLNode));
	*e = Next_node->data;

	p->next = Next_node->next;//ʵ��ɾ��
	Next_node->prior = NULL;
	Next_node->next->prior = p;
	Next_node->next = NULL;
	free(Next_node);

}


void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	//����������ÿһ���ڵ�����ʹ�ú���visit()
	DuLinkedList curr = L->next;
	while (curr->next != NULL) {
		visit(curr->data);
		 curr=curr->next;
	}


}


#endif