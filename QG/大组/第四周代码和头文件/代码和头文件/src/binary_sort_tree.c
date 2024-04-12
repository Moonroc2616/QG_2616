#include<stdio.h>
#include<stdlib.h>
#include "binary_sort_tree.h"
#include <stdbool.h>

#define STACK_SIZE 100

#pragma once
#ifndef BINARYSORTTREE_BINARY_SORT_TREE_C
#define BINARYSORTTREE_BINARY_SORT_TREE_C

// 定义栈结构体
typedef struct Stack {
    NodePtr data[STACK_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack* stack) {
    stack->top = -1;
}

// 判断栈是否为空
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 入栈
void push(Stack* stack, NodePtr node) {
    if (stack->top < STACK_SIZE - 1) {
        stack->data[++stack->top] = node;
    }
}

// 出栈
NodePtr pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return NULL;
}
//以上为栈相关操作，用于实现非递归相关功能



Status BST_init(BinarySortTreePtr BST) {
    if (BST == NULL) {
        return failed; // 指针为空，初始化失败
    }

    BST->root = NULL; // 将根节点置空，表示二叉排序树为空树
    return succeed;
}



Status BST_insert(BinarySortTreePtr BST, ElemType value) {
    if (BST == NULL) {
        return failed; // 指针为空，插入失败
    }

    NodePtr newNode = (NodePtr)malloc(sizeof(Node)); // 分配新节点内存
    if (newNode == NULL) {
        return failed; // 内存分配失败，插入失败
    }

    newNode->value = value; // 设置新节点的值
    newNode->left = NULL;
    newNode->right = NULL;

    if (BST->root == NULL) {
        BST->root = newNode; // 如果根节点为空，直接将新节点设置为根节点
        return succeed;
    }

    NodePtr current = BST->root;
    NodePtr parent = NULL;

    // 寻找插入位置
    while (current != NULL) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        }
        else if (value > current->value) {
            current = current->right;
        }
        else {
            free(newNode); // 释放内存，插入失败（不允许插入重复值）
            return failed;
        }
    }

    // 插入新节点
    if (value < parent->value) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    return succeed;
}

BST_delete(BinarySortTreePtr bst, ElemType value) {
    if (bst->root == NULL) {
        // 空树
        return failed;
    }

    NodePtr parent = NULL;
    NodePtr current = bst->root;
    while (current != NULL && current->value != value) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    if (current == NULL) {
        // 没找到值为 value 的节点
        printf("没找到值为 value 的节点");
        return failed;
    }

    if (current->left == NULL) {
        if (parent == NULL) {
            // 删除根节点
            bst->root = current->right;
        }
        else {
            if (parent->left == current) {
                parent->left = current->right;
            }
            else {
                parent->right = current->right;
            }
        }
        free(current);
    }
    else if (current->right == NULL) {
        if (parent == NULL) {
            // 删除根节点
            bst->root = current->left;
        }
        else {
            if (parent->left == current) {
                parent->left = current->left;
            }
            else {
                parent->right = current->left;
            }
        }
        free(current);
    }
    else {
        // 节点有两个孩子
        NodePtr successor = current->right;
        parent = NULL;
        while (successor->left != NULL) {
            parent = successor;
            successor = successor->left;
        }

        current->value = successor->value;
        if (parent != NULL) {
            parent->left = successor->right;
        }
        else {
            current->right = successor->right;
        }
        free(successor);
    }
    return succeed;
}
//如果要删除的节点 current 没有左孩子（即 current->left == NULL），
// 那么它可以直接被删除。如果 current 恰好是根节点（即 parent == NULL），则更新根节点为当前节点的右孩子；否则，将当前节点的右孩子连接到当前节点的父节点的相应位置（左孩子或右孩子），然后释放当前节点的内存。

//如果要删除的节点 current 没有右孩子（即 current->right == NULL），与上述情况类似，只是操作方向相反。如果 current 是根节点，则更新根节点为当前节点的左孩子；
// 否则，将当前节点的左孩子连接到当前节点的父节点的相应位置，然后释放当前节点的内存。

//如果要删除的节点 current 既有左孩子又有右孩子，那么需要找到它的中序后继节点。
// 中序后继节点是当前节点的右子树中的最左边的节点。
// 首先，找到右子树中最左边的节点并记录其父节点，
// 然后将中序后继节点的值复制到当前节点，最后删除中序后继节点。
// 删除中序后继节点的方法与删除没有左孩子或右孩子的节点相同，
// 只是将中序后继节点的右孩子（如果存在）连接到其父节点的左孩子


BST_search(BinarySortTreePtr bst, ElemType value) {
    if (bst == NULL || bst->root == NULL) {
        return failed; // 如果BST为空，则搜索失败
    }

    NodePtr current = bst->root;
    while (current != NULL) {
        if (current->value == value) {
            return succeed; // 如果找到了匹配的节点，则搜索成功
        }
        else if (current->value > value) {
            current = current->left; // 如果当前节点值大于要搜索的值，则向左子树搜索
        }
        else {
            current = current->right; // 如果当前节点值小于要搜索的值，则向右子树搜索
        }
    }

    printf("没有找到匹配的节点");
    return failed; // 遍历完整个树仍然没有找到匹配的节点，则搜索失败
}

BST_preorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst->root == NULL) {
        return failed;
    }

    Stack stack;
    initStack(&stack);
    NodePtr current = bst->root;
    while (current != NULL || !isEmpty(&stack)) {
        if (current != NULL) {
            visit(current);
            push(&stack, current->right); // 先将右子树入栈，因为栈是先进后出的
            current = current->left;
        }
        else {
            current = pop(&stack);
        }
    }

    return succeed;
}

BST_preorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    // 若树为空，则遍历失败
    if (bst->root == NULL) {
        return failed;
    }
    // 访问根节点
    visit(bst->root);
    // 递归遍历左子树
    if (bst->root->left != NULL) {
        BST_preorderR(&(BinarySortTree) { bst->root->left }, visit);
    }
    // 递归遍历右子树
    if (bst->root->right != NULL) {
        BST_preorderR(&(BinarySortTree) { bst->root->right }, visit);
    }
    return succeed;
}

BST_inorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL || bst->root == NULL) // 如果 BST 为空，直接返回失败
        return failed;

    Stack stack; // 创建一个栈
    initStack(&stack); // 初始化栈

    NodePtr current = bst->root; // 从根节点开始

    while (current != NULL || !isEmpty(&stack)) {
        // 将当前节点的所有左子节点入栈
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        // 弹出栈顶元素，并访问它
        current = pop(&stack);
        visit(current);

        // 将右子节点设为当前节点，继续遍历右子树
        current = current->right;
    }

    return succeed; // 遍历完成，返回成功
}

BST_inorderR_Helper(NodePtr node, void (*visit)(NodePtr)) {
    if (node == NULL) {
        return succeed; // 如果当前节点为空，直接返回成功
    }
    // 遍历左子树
    BST_inorderR_Helper(node->left, visit);
    // 访问当前节点
    visit(node);
    // 遍历右子树
    BST_inorderR_Helper(node->right, visit);
    return succeed;
}

BST_inorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL || bst->root == NULL) {
        return failed; // 如果 BST 为空，直接返回失败
    }
    // 递归遍历
    return BST_inorderR_Helper(bst->root, visit);
}

// BST后序遍历的非递归实现
Status BST_postorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL || bst->root == NULL) {
        return failed; // 如果 BST 为空，直接返回失败
    }
    Stack stack1, stack2; // 使用两个栈来实现后序遍历
    initStack(&stack1);
    initStack(&stack2);
    NodePtr current = bst->root;
    push(&stack1, current); // 根节点入栈

    // 在第一个栈中进行先序遍历
    while (!isEmpty(&stack1)) {
        current = pop(&stack1);
        if (current != NULL) {
            push(&stack1, current->left);
            push(&stack1, current->right);
            push(&stack2, current); // 将先序遍历的结果存入第二个栈
        }
    }

    // 在第二个栈中逆序输出结果，即为后序遍历的结果
    while (!isEmpty(&stack2)) {
        current = pop(&stack2);
        visit(current);
    }
    return succeed;
}

// BST后序遍历的递归实现
Status BST_postorderR_Helper(NodePtr node, void (*visit)(NodePtr)) {
    if (node == NULL) {
        return succeed; // 如果当前节点为空，直接返回成功
    }
    // 遍历左子树
    BST_postorderR_Helper(node->left, visit);
    // 遍历右子树
    BST_postorderR_Helper(node->right, visit);
    // 访问当前节点
    visit(node);
    return succeed;
}

Status BST_postorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL || bst->root == NULL) {
        return failed; // 如果 BST 为空，直接返回失败
    }
    // 递归遍历
    return BST_postorderR_Helper(bst->root, visit);
}

// BST层序遍历
Status BST_levelOrder(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL || bst->root == NULL) {
        return failed; // 如果 BST 为空，直接返回失败
    }
    NodePtr queue[STACK_SIZE]; // 使用数组模拟队列
    int front = 0, rear = 0;
    queue[rear++] = bst->root; // 根节点入队

    while (front != rear) {
        NodePtr current = queue[front++]; // 出队
        visit(current); // 访问节点
        if (current->left != NULL) {
            queue[rear++] = current->left; // 左子节点入队
        }
        if (current->right != NULL) {
            queue[rear++] = current->right; // 右子节点入队
        }
    }
    return succeed;
}
#endif