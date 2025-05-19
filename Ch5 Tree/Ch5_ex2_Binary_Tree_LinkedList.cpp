/*
    ��Ƶ��c�d��
    �Ĥ��� : Tree
    �d�� 2 : Linked List �� + ���j�إ߾�`�I 
    ��J�ƭ� N, ���͹������G����
    
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
        printf("�O������t���ѡC\n");
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
        printf("%*d%*s", space, root->data, width - space, "");
    } else if (level > 1) {
        printLevel(root->left, level - 1, space, width);
        printLevel(root->right, level - 1, space, width);
    }
}

// �����C�L��
void printTreeHorizontal(Node* root) {
    int h = treeHeight(root);
    int maxWidth = (int)pow(2, h) * 2; // �𪺳̤j�e��

    for (int i = 1; i <= h; i++) {
        int space = maxWidth / (int)pow(2, i);
        printLevel(root, i, space, maxWidth / (int)pow(2, i - 1));
        printf("\n\n");
    }
}

// ����O����
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    printf("�п�J�`�I�ƶq n�G");
    scanf("%d", &n);

    if (n <= 0) {
        printf("�`�I�ƶq�����j�� 0�C\n");
        return 1;
    }

    Node* root = buildTree(n, 1);

    printf("\n�𪺤����i�}���c�G\n");
    printTreeHorizontal(root);

    freeTree(root);

    return 0;
}

