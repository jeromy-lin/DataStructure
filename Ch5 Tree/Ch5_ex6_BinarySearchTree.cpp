/*
    資料結構範例
    第五章 : Tree
    範例 6 : 以固定陣列建立binary search tree 
    
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left; 
	struct Node *right;
} Node;

// 建立新節點
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 插入資料進 BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 中序走訪印出 注意 : 結果會是排序後的Tree node

int main() {
    int values[] = {28, 23, 33, 41, 22, 24}; 
    int n = sizeof(values) / sizeof(values[0]);
    
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("BST 中序走訪（排序結果）：");
    inorder(root);
    printf("\n");

    return 0;
}
     //C 語言中固定產生array大小計算 
    //請同學參考 array element的計算方法 , sizeof(values=24), 代表整個陣列的總大小 , sizeof(values[0]) → 代表陣列中一個元素的大小
    // 24 / 4 = 6 個element

