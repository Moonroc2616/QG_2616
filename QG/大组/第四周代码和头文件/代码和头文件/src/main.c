#include<stdio.h>
#include<stdlib.h>
#include "binary_sort_tree.h"


//打印树
void printBinaryTree(Node* root, int level) {
	if (root == NULL) // 空节点，直接返回
		return;

	// 递归打印右子树
	printBinaryTree(root->right, level + 1);

	// 打印节点数据
	for (int i = 0; i < level; i++)
		printf("   "); // 打印缩进
	printf("%d\n", root->value);

	// 递归打印左子树
	printBinaryTree(root->left, level + 1);
}


void printNodeValue(NodePtr node) {
	printf("%d ", node->value);
}
//打印节点：用于检验前序便利等是否成功





int main() {
	BinarySortTree* BST = (BinarySortTree*)malloc(sizeof(NodePtr)); // 为 BST 分配内存
	printf("现在测试BST_init\n");
	if (BST_init(&BST) == succeed) {
		printf("BST_init成功！\n");
	}
	else {
		printf("BST_init失败！\n");
	}

	printf("\n现在测试BST_insert\n");
	if (BST_insert(&BST,1) == succeed) {
		printf("BST_insert成功！二叉树如下\n");
		printBinaryTree(BST,0);
	}
	else {
		printf("BST_insert失败！\n");
	}
	printf("现在为二叉树赋值：\n");
		BST_insert(&BST, 2);
		BST_insert(&BST, 3);
		BST_insert(&BST, 4);
		BST_insert(&BST, 5);
		printBinaryTree(BST, 0);


	printf("\n现在测试BST_delete  元素2\n");
	if (BST_delete(&BST,2) == succeed) {
		printf("BST_deletet成功！\n");
		printBinaryTree(BST, 0);
	}
	else {
		printf("BST_delete失败！\n");
	}

	printf("\n现在测试BST_search   元素2\n");
	if (BST_search(&BST, 2) == succeed) {
		printf("BST_search成功！\n");
		printBinaryTree(BST, 0);
	}
	else {
		printf("BST_search失败！\n");
	}

	printf("\n现在测试BST_search   元素3\n");
	if (BST_search(&BST, 3) == succeed) {
		printf("BST_search成功！\n");
		printBinaryTree(BST, 0);
	}
	else {
		printf("BST_search失败！\n");
	}


	printf("\n现在测试BST_preorderI\n");
	if (BST_preorderI(&BST, printNodeValue) == succeed) {
		printf("\nBST_preorderI成功！\n");
	}
	else {
		printf("BST_preorderI失败！\n");
	}


	printf("\n现在测试BST_preorderR\n");
	if (BST_preorderI(&BST, printNodeValue) == succeed) {
		printf("\nBST_preorderR成功！\n");
	}
	else {
		printf("BST_preorderR失败！\n");
	}


	printf("\n现在测试BST_inorderI\n");
	if (BST_inorderI(&BST, printNodeValue) == succeed) {
		printf("\nBST_inorderI成功！\n");
	}
	else {
		printf("BST_inorderI失败！\n");
	}

	printf("\n现在测试BST_inorderR\n");
	if (BST_inorderR(&BST, printNodeValue) == succeed) {
		printf("\BST_inorderR成功！\n");
	}
	else {
		printf("BST_inorderR失败！\n");
	}

	printf("\n现在测试BST_postorderI\n");
	if (BST_postorderI(&BST, printNodeValue) == succeed) {
		printf("\BST_postorderI成功！\n");
	}
	else {
		printf("BST_postorderI失败！\n");
	}

	printf("\n现在测试BST_postorderR\n");
	if (BST_postorderR(&BST, printNodeValue) == succeed) {
		printf("\BST_postorderR成功！\n");
	}
	else {
		printf("BST_postorderR失败！\n");
	}

	printf("\n现在测试BST_levelOrder\n");
	if (BST_levelOrder(&BST, printNodeValue) == succeed) {
		printf("\BST_levelOrder成功！\n");
	}
	else {
		printf("BST_levelOrder失败！\n");
	}




	// 在程序结束前释放 BST 指向的内存
	free(BST);
	getchar();
	return 0;
}