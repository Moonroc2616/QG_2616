#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkStack.h"

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

//链栈

Status initLStack(LinkStack* s) {
	//初始化栈
	s->top = NULL;
	s->count =0;
	return SUCCESS;
}


Status isEmptyLStack(LinkStack* s) {
	//判断栈是否为空
	if (s->top == NULL) {
		printf("栈链为空\n");
		return SUCCESS;
	}
	else {
		//printf("栈链不为空\n");
		return ERROR;
	}
}

Status creat5Stack(LinkStack* s) {
	//创建一个五个节点的栈链，data为1--5，便于检查错误
	if (s == NULL) {
		printf("栈链为空\n");
		return ERROR;
	}

	StackNode* temp = NULL;
	int n = 0;
	while (s->count < 5) {
		temp = (StackNode*)malloc(sizeof(StackNode));
		if (temp == NULL) {
			printf("临时节点开辟空间失败\n");
			return ERROR;
		}

		temp->data = n + 1;
		temp->next = s->top;
		s->top = temp;

		s->count++;
		n++;
	}

	return SUCCESS;
}


Status printStack(LinkStack* s) {
	//打印栈链便于检验
	 if (s == NULL||s->top == NULL) {
		printf("栈链为空\n");
		return SUCCESS;
	}


	//StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	 StackNode* temp = s->top;
	while (temp != NULL) {
		printf(" data=%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	printf("count=%d\n", s->count);

	return SUCCESS;
}


Status getTopLStack(LinkStack* s, ElemType* e)//得到栈顶元素
{
		*e = s->top->data;
}


Status clearLStack(LinkStack* s) {
	StackNode* temp=NULL;
	if (s->top != NULL&&s!=NULL) {
		while (s->top != NULL) {
			temp = s->top;
			s->top = s->top->next;
			free(temp);
		}
		s->count = 0; // 清空栈后，将计数器重置为 0
		return SUCCESS;
	}
	else {
		//printf("栈链自为空\n");
		return SUCCESS;
	}
}


Status destroyLStack(LinkStack* s)//销毁栈
{
	clearLStack(s);
	free(s);
	/*s->top = NULL;
	s = NULL;*/
	
	return SUCCESS;
}


Status LStackLength(LinkStack* s, int* length)//检测栈长度
{
	if (s->top == NULL) {
		*length = 0;
		return ERROR;
	}
	int n = 0;
	StackNode* current = s->top;
	while (current != NULL) {
		n++;
		current = current->next;
	}

	*length = n;
	return SUCCESS; // 返回成功状态
}


Status pushLStack(LinkStack* s, ElemType data)//入栈
{
	if (s == NULL) {
		printf("栈链为空\n");
		return ERROR;
	}

	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		printf("临时节点开辟空间失败\n");
		return ERROR;
	}

	temp->data = data;
	temp->next = s->top;
	s->top = temp;
	s->count++;
	return SUCCESS;
}


Status popLStack(LinkStack* s, ElemType* data)//出栈
{
	if (s->top == NULL) {
		printf("栈为空，无法出栈\n");
		return ERROR; // 返回错误状态
	}

	
	//StackNode* curr = (StackNode*)malloc(sizeof(StackNode));
	StackNode* curr=s->top;
	s->top=curr->next ;
	*data = curr->data;
	free(curr);
	s->count--;
}





#endif