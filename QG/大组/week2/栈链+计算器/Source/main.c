#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkStack.h"
#include <ctype.h>	//用于检验是否为字母，数字的头文件

#define MAX_SIZE 100 //计算器表达式最大长度

//struct EXP {
//	int flg;
//	int data1;
//	char data2;
//	struct EXP* next;
//};

int main()
{
	Status handleExp(LinkStack * s, char exp[], char exp2[]);
	void caculator(LinkStack * stack);
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));	// 为LinkStack结构体分配内存
	ElemType* e = (ElemType*)malloc(sizeof(ElemType));	 // 分配内存给 e
	int* length = (int*)malloc(sizeof(int));

	printf("1.开始测试initLStack\n");
	if (initLStack(stack) == SUCCESS) {
		printf("initLStack成功\n");
	}
	else {
		printf("initLStack失败\n");
	}


	//接下来生成一个五个长度的栈链便于打印，检查
	creat5Stack(stack);
	printStack(stack);



	printf("\n2.开始测试isEmptyLStack\n");
	if (isEmptyLStack(stack) == ERROR) {	//ERROR意味着不为空
		printf("isEmptyLStack成功\n");
	}
	else {
		printf("isEmptyLStack失败\n");
	}


	printf("\n3.开始测试getTopLStackk\n");
	getTopLStack(stack, e);
	printStack(stack);
	if (*e == stack->top->data) {
		printf("栈顶元素e=%d\ngetTopLStackk成功\n", stack->top->data);
	}
	else {
		printf("getTopLStackk失败\n");
	}


	printf("\n4.开始测试clearLStack\n");
	 clearLStack(stack);	//清空栈
	 printStack(stack);
	 if (stack->top == NULL) {
		 printf("clearLStack成功\n");
	 }
	 else {
		 printf("clearLStack失败\n");
	 }


	 printf("\n5.开始测试destroyLStack\n");
	 if (destroyLStack(stack) == SUCCESS) {
		 printf("destroyLStac成功\n");
	 }
	 else {
		 printf("destroyLStac失败\n");
	 }
	 //clearLStack(stack);

	 stack = (LinkStack*)malloc(sizeof(LinkStack));	// 为LinkStack结构体分配内存
	 initLStack(stack);
	 creat5Stack(stack);	//再次新建一个五个结点的栈链便于后续检查

	 printf("\n6.开始测试LStackLength\n");
	 printStack(stack);
	 LStackLength(stack, length);
	 if (*length == stack->count) {
		 printf("LStackLength成功\n");
	 }
	 else {
		 printf("LStackLength失败\n");
	 }


	 printf("\n7.开始测试pushLStack\n");
	 double input = 99;
	 pushLStack(stack, input);
	 printStack(stack);
	 if (stack->top->data == input) {
		 printf("pushLStack成功\n");
	 }
	 else {
		 printf("pushLStack成功失败");
	 }


	 printf("\n8.开始测试popLStack\n");
	 ElemType* output = (ElemType*)malloc(sizeof(ElemType));
	 int flg = stack->top->data;
	 printf("flg=%d\n", flg);
	 popLStack(stack, output);
	 printf("output=%d\n", *output);
	 printStack(stack);

	 if (flg == *output) {
		 printf("popLStack成功\n");
	 }
	 else {
		 printf("popLStack失败\n");
	 }

	 while (getchar != '!') {
		 printf("\n摁下enter后清屏，并进入计算器");
		 getchar();
		 system("cls");  // 清屏命令
		 destroyLStack(stack);//销毁栈
		 stack = (LinkStack*)malloc(sizeof(LinkStack));	// 为LinkStack结构体分配内存
		 initLStack(stack);
		 //以上是销毁自定义栈链，并重新初始化以便开始计算机功能
		 caculator(stack);
	 }
	
	return 0;
}
void caculator(LinkStack* stack) {
	//以下开始为计算器功能
	printf("请输入一个四则运算表达式(英文输入法)：\n");
	char exp[MAX_SIZE] = { 0 };
	fgets(exp, MAX_SIZE, stdin);	//接收四则运算
	char exp2[MAX_SIZE] = { 0 };	//存放后缀表达式
	
	if (handleExp(stack, exp, exp2) == ERROR) {	//进行转化为后缀处理
		return;
	}

	initLStack(stack);		//重新初始化以便开始计算后缀表达式

	//以下循环用于计算后缀表达式
	//思路：exp2中存放了字符类型后缀表达式，将数字转入exp3中，同时遍历两个数组，遇到exp2运算符字符计算exp3即可。
	double exp3[MAX_SIZE] = { 0 };
	for (int n = 0; n < MAX_SIZE; n++) {
		//if((exp2[n]>='0')&&(exp2[n]<='9')) {
		//	exp3[n] = atof(&exp2[n]);	//将数字字符转化为double存入exp3
		//}
		//else {
		//	exp3[n] = -1;
		//}
		//
		exp[n] = '#';	//重新初始化exp
	}
	for (int n = 0, y = 0; n < MAX_SIZE; n++) {	//形成 1 # 1 # +这种形式把每个字符分隔
		exp[y] = exp2[n];
		y += 2;
		if (exp2[n] == '\0') {
			break;
		}
	}

	//printf("exp:");
	//for (int n = 0, y = 0; n < MAX_SIZE; n++, y + 2) {	//形成 1 # 1 # +这种形式把每个字符分隔
	//	printf("%c", exp[n]);
	//	}

	int flg2 = 0;
	for (int n = 0, y = 0; n < MAX_SIZE; n++) {
		if (exp[n] == '#') {
			if (exp[n + 1] == '#')
				break;
			continue;
		}
		if ((exp[n] >= '0') && (exp[n] <= '9')) {
			exp3[y] = atof(&exp[n]);	//将数字字符转化为double存入exp3
			y++;
		}
		else {	//如果遇到exp2的运算符
			exp3[y] = -1;
			y++;
		}
		flg2 = y;
	}
	exp3[flg2 - 1] = 99;
	//printf("flg2:%d", flg2);
	/*printf("\nexp3:");
	for (int n = 0; n < MAX_SIZE; n++) {
		if (exp3[n] == 99) {
			break;
		}
		printf("%f ", exp3[n]);
	}*/
	printf("\n");

	int A, B;
	A = B = 0;
	for (int n = 0; n < MAX_SIZE; n++) {
		if (exp3[n] == 99) {
			break;
		}
		if (exp3[n] == -1) {

			if (exp2[n] == '+' || exp2[n] == '-' || exp2[n] == '*' || exp2[n] == '/') {
				popLStack(stack, &A);	//获取栈顶往下两个栈内元素
				popLStack(stack, &B);
				if (exp2[n] == '+') {
					pushLStack(stack, (A + B));
				}
				else if (exp2[n] == '-') {
					pushLStack(stack, (A - B));
				}
				else if (exp2[n] == '*') {
					pushLStack(stack, (A * B));
				}
				else if (exp2[n] == '/') {
					pushLStack(stack, (A / B));
				}
			}
		}
		else {
			pushLStack(stack, exp3[n]);
		}

	}

	//printStack(stack);
	//popLStack(stack, &A);	//获取栈顶往下两个栈内元素
	//popLStack(stack, &B);
	//printf("\nA=%d,B=%d\n", A, B);

	//if (pushLStack(stack, (A+B)) == SUCCESS) {
	//	printf("push!!!!!!!!!!\n");
	//}
	//printStack(stack);

	int result = getTopLStack(stack, &result);
	printf("result=%d", result);
}

Status handleExp(LinkStack* s,char exp[],char exp2[])
{
	//此循环用于判别输入是否正确
	for (int n = 0; n < MAX_SIZE; n++) {
		if (exp[n] == '\0') {	//如果遇到结束标识，则结束
			break;
		}
		//如果不是数字，且不是四则运算，则结束运行
		if (exp[n] == '+' || exp[n] == '-' || exp[n] == '*' || exp[n] == '/' ||exp[n]=='('|| exp[n] == ')') {	//若已遍历完表达式
			//printf("开始计算\n");
			break;
		}
		else if (exp[n]>='0' && exp[n] <= '9'){
			break; 
}
		else {
			printf("请输入正确的数学表达式\n");
			return ERROR;
		}
	}

		
	//此循环用于中缀改后缀
	int y = 0;
	for (int n=0; n < MAX_SIZE; n++)	{
		//如果是数字，直接输出
		if (isdigit(exp[n])) {	
			exp2[y]=exp[n];
			y++; 
			//printf("%s", exp2);
		}

		//如果是左括号，入栈
		else if (exp[n] == '(') {	
			pushLStack(s, exp[n]);
			//printf("test'（'=%c\n", s->top->data);
		}

		//如果是‘)’,栈内一直输出直到遇到（，'('出栈但不输出
		else if (exp[n] == ')') {	
			if (s->count==0) {	//判断出输入‘）’但栈内无元素的情况
				printf("请输入正确的算数表达式\n");
				return;
			}
			else {
				ElemType top;
				getTopLStack(s, &top);
				while (!isEmptyLStack(s) && top != '(') {
					ElemType e;
					popLStack(s, &e);
					exp2[y] = e;	//输出栈内元素
					y++;
					getTopLStack(s, &top);
				}
				if (!isEmptyLStack(s) && top == '(') {
					ElemType e;
					popLStack(s, &e);  // 弹出 '('
				}
				else {
					// 没有匹配的 '('，处理错误逻辑
				}
			}
		}

		//如果是乘除，直接入栈
		else if (exp[n] == '*' || exp[n] == '/') {
			pushLStack(s, exp[n]);
		}

		//如果是加减，判断栈内有没有乘除，若有，一直出栈直到没有，然后入栈。
		else if (exp[n] == '+' || exp[n] == '-') {
			if (s->top == NULL||s==NULL) {
				pushLStack(s, exp[n]);
			}
			else {
				// 判断栈内是否有乘除号，如果有，则连续出栈直到栈内没有乘除号
				ElemType top;
				getTopLStack(s, &top);
				while (!isEmptyLStack(s) && (top == '*' || top == '/'))
				{
					ElemType e;
					popLStack(s, &e);
					getTopLStack(s, &top);
					exp2[y] = e;
					y++;
				}
				// 将当前加号或减号入栈
				pushLStack(s, exp[n]);
			}
			
		}

		//如果表达式exp遍历完毕，输出栈内所有元素
		if (exp[n] == '\0') {			
				StackNode* curr = s->top;
				while (curr != NULL) {
					if (s->count == 0) {	//遍历完成，若栈链为空，结束循环
						break;
					}
					ElemType e;
					popLStack(s, &e);
					//printf("121212");
					exp2[y] = e;
					y++;
					curr->next = curr;

				}			
		}

	}

	printf("后缀表达式:");
	for (int n = 0; n <= y; n++) {
		if (exp2[n] != '\0') {
			printf("%c ", exp2[n]);
		}
		else {
			break;
		}
	}

	return SUCCESS;
}

