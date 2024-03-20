#include "duLinked.h"
#include <stdio.h>
#include <stdlib.h>

void printList(DuLNode* head) {
	//��ӡ������ڼ��
	printf("������˫������:\n");
	//if (head == NULL || head->next == NULL) {
	//	printf("����Ϊ��\n");
	//	return;
	//}
	DuLNode* current = head->next; // ��ͷ������һ���ڵ㿪ʼ����
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("����\n");
}

void valuesToDuLinkedList(DuLNode* head) {
	DuLNode* current = head;

	// Ϊ����ڵ㸳ֵ
	for (int i = 0; i < 5; i++) {
		DuLNode* newNode = (DuLNode*)malloc(sizeof(DuLNode));
		newNode->data = (i+1);
		newNode->prior = current;
		newNode->next = NULL;
		current->next = newNode;
		current = newNode;
	}

	// �������һ���ڵ��ǰ��ָ��
	current->next = NULL;
}

void visit(int n) {
	printf(" %d",n);
}

int main() 
{
	DuLNode* L = NULL;//ͷ���
	DuLNode* q = (DuLNode * )malloc(sizeof(DuLNode));//���ڲ���ǰ���빦�ܵĽڵ�
	q->data = 2616;
	q->next = NULL;
	q->prior = NULL;

	DuLNode* p = (DuLNode*)malloc(sizeof(DuLNode));//���ڲ��Ժ���빦�ܵĽڵ�
	p->data = 2518;
	p->next = NULL;
	p->prior = NULL;
	
	int e=-1;
	
	printf("1.���Գ�ʼ��˫������InitList_DuL\n");
	if (InitList_DuL(&L) == SUCCESS) {
		printf("InitList_DuL�ɹ�\n");
	}
	else {
		printf("ʧ��\n");
	}


	valuesToDuLinkedList(L);
	printList(L);


	printf("\n2.����ɾ��˫������DestroyList_DuL\n");
	DestroyList_DuL(&L);
	if (L) {
		printf("DestroyList_DuL�ɹ�\n"); 
	}
	else {
		printf("ʧ��\n");
	}


	printf("\n3.���Բ���˫������InsertBeforeList_DuL\n");
	InitList_DuL(&L);	//ɾ����������´���������ֵ
	valuesToDuLinkedList(L);	
	printList(L);

	InsertBeforeList_DuL(L->next->next, q);
	if (L) {
		printf("InsertBeforeList_DuL�ɹ�\n");
		printList(L);
	}
	else {
		printf("ʧ��\n");
	}


	printf("\n4.���Բ���˫������InsertAfterList_DuL\n");
	InsertAfterList_DuL(L->next->next, p);
	if (L->next) {
		printf("InsertAfterList_DuL�ɹ�\n");
		printList(L);
	}
	else {
		printf("ʧ��\n");
	}


	printf("\n5.����ɾ��˫������ڵ�DeleteList_DuLL\n");
	DeleteList_DuL(L,&e);
	if (e!=-1) {
		printf("DeleteList_DuLL�ɹ�\n");
		printList(L);
		printf("e=%d\n", e);
	}
	else {
		printf("ʧ��\n");
	}


	printf("\n5.����ɾ��˫������ڵ�TraverseList_DuL\n");
	TraverseList_DuL(L, visit);
	printList(L);

	return 0;
}