/*
    ��Ƶ��c�d��
    �Ĥ��� : Tree
    �d�� 4 : Linked List �� + PostOrder Traversal ��Ƿj�M 
    �H�T�w���G���� �i���Ƿj�M�t��k 
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>  

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// �إ߷s�`�I
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�O������t����\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// �p��𪺰���
int treeHeight(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// �C�L�Y�@�h���`�I
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

// �����C�L��
void printTreeHorizontal(Node* root) {
    int h = treeHeight(root);
    int maxWidth = (int)pow(2, h) * 2;

    for (int i = 1; i <= h; i++) {
        int space = maxWidth / (int)pow(2, i);
        printLevel(root, i, space, maxWidth / (int)pow(2, i - 1));
        printf("\n\n");
    }
}

// ��Ƿj�M�f�Z :  (�� -> �k -> ��)
void postorderTraversal(Node* root) {
    if (root == NULL)
        return; // �p�G�O�Ÿ`�I�A������^�]exit recursive�^ 
    
    postorderTraversal(root->left);    // 1. �����X���l��
    postorderTraversal(root->right);   // 2. �A���X�k�l��
    printf("%d ", root->data);          // 3. �̫�L�X�ۤv
}

int main() {
    // �إ߸`�I
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

    printf("Binary Search Tree in Post Order Traversal�G\n\n");
    printTreeHorizontal(root);

    printf("\n��Ǩ��X���G�G");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

