/*
    資料結構範例
    第五章 : Tree
    範例 2 : Linked List 版 + 遞迴建立樹節點 
    輸入數值 N, 產生對應的二元樹
    
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("記憶體分配失敗。\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(int n, int index) {
    if (index > n) return NULL;
    Node* root = createNode(index);
    root->left = buildTree(n, 2 * index);
    root->right = buildTree(n, 2 * index + 1);
    return root;
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
        printf("%*d%*s", space, root->data, width - space, "");
    } else if (level > 1) {
        printLevel(root->left, level - 1, space, width);
        printLevel(root->right, level - 1, space, width);
    }
}

// 水平列印樹
void printTreeHorizontal(Node* root) {
    int h = treeHeight(root);
    int maxWidth = (int)pow(2, h) * 2; // 樹的最大寬度

    for (int i = 1; i <= h; i++) {
        int space = maxWidth / (int)pow(2, i);
        printLevel(root, i, space, maxWidth / (int)pow(2, i - 1));
        printf("\n\n");
    }
}

// 釋放記憶體
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    printf("請輸入節點數量 n：");
    scanf("%d", &n);

    if (n <= 0) {
        printf("節點數量必須大於 0。\n");
        return 1;
    }

    Node* root = buildTree(n, 1);

    printf("\n樹的水平展開結構：\n");
    printTreeHorizontal(root);

    freeTree(root);

    return 0;
}

