/*
    資料結構範例
    第五章 : Tree
    範例 3 : Linked List 版 + inOrder Traversal 中序搜尋 
    以固定的二元樹 進行中序搜尋演算法 
    
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>  

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 建立新節點
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("記憶體分配失敗\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 計算樹的高度
int treeHeight(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 列印某一層的節點
void printLevel(Node* root, int level, int space, int width) {
    if (root == NULL) {
        for (int i = 0; i < width; i++) printf(" ");
        return;
    }
    if (level == 1) {
        for (int i = 0; i < space - 1; i++) printf(" ");
        printf("%d", root->data);
        for (int i = 0; i < width - space; i++) printf(" ");
    } else if (level > 1) {
        printLevel(root->left, level - 1, space, width);
        printLevel(root->right, level - 1, space, width);
    }
}

// 水平列印樹
void printTreeHorizontal(Node* root) {
    int h = treeHeight(root);
    int maxWidth = (int)pow(2, h) * 2;

    for (int i = 1; i <= h; i++) {
        int space = maxWidth / (int)pow(2, i);
        printLevel(root, i, space, maxWidth / (int)pow(2, i - 1));
        printf("\n\n");
    }
}

// 中序搜尋口訣 :  (左 -> 中 -> 右)
void inorderTraversal(Node* root) {
    if (root == NULL)
        return; // 如果是空節點，直接返回（exit recursive） 
    
    inorderTraversal(root->left);    // 1. 先走訪左子樹
    printf("%d ", root->data);      // 2. 然後印出自己
    inorderTraversal(root->right);  // 3. 最後走訪右子樹
}

int main() {
    // 建立節點
    Node* root = createNode(0);
    root->left = createNode(1);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->right = createNode(5);
    root->left->left->left = createNode(6);
    root->left->left->right = createNode(7);
    root->right->right->left = createNode(8);
    root->right->right->right = createNode(9);

    printf("Binary Search Tree in In-Order Traversal：\n\n");
    printTreeHorizontal(root);

    printf("\n中序走訪結果：");
    inorderTraversal(root);
    printf("\n");

    return 0;
}


