/*
	資料結構範例   
	第七章 : Search 
	範例 3 : Sequential Search Tree 二元樹搜尋法 
	
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// 建立Tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 建立BST 
Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// 搜尋資料
int search(Node* root, int key, int* steps) {
    while (root != NULL) {
        (*steps)++;
        if (key == root->data)
            return 1;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}

// 以樹狀格式列印 BST
void printTree(Node* root, int space) {
    if (root == NULL) return;

    const int COUNT = 5;
    space += COUNT;

    // 先列印右子樹
    printTree(root->right, space);

    // 顯示當前節點
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // 再列印左子樹
    printTree(root->left, space);
}

int main() {
    int data[] = {5, 7, 9, 2, 1, 4};
    int n = sizeof(data) / sizeof(data[0]);
    Node* root = NULL;

    // 建立 BST
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // 印出樹狀結構
    printf("Binary Search Tree :\n");
    printTree(root, 0);

    // 搜尋 key
    int key = 4, steps = 0;
    if (search(root, key, &steps)) {
        printf("\n找到 %d，用了 %d 步。\n", key, steps);
    } else {
        printf("\n找不到 %d，用了 %d 步。\n", key, steps);
    }

    return 0;
}

//PS. 同學們這個練習很重要喔!! 

