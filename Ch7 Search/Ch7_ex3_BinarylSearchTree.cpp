/*
	��Ƶ��c�d��   
	�ĤC�� : Search 
	�d�� 3 : Sequential Search Tree �G����j�M�k 
	
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// �إ�Tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// �إ�BST 
Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// �j�M���
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

// �H�𪬮榡�C�L BST
void printTree(Node* root, int space) {
    if (root == NULL) return;

    const int COUNT = 5;
    space += COUNT;

    // ���C�L�k�l��
    printTree(root->right, space);

    // ��ܷ�e�`�I
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // �A�C�L���l��
    printTree(root->left, space);
}

int main() {
    int data[] = {5, 7, 9, 2, 1, 4};
    int n = sizeof(data) / sizeof(data[0]);
    Node* root = NULL;

    // �إ� BST
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // �L�X�𪬵��c
    printf("Binary Search Tree :\n");
    printTree(root, 0);

    // �j�M key
    int key = 4, steps = 0;
    if (search(root, key, &steps)) {
        printf("\n��� %d�A�ΤF %d �B�C\n", key, steps);
    } else {
        printf("\n�䤣�� %d�A�ΤF %d �B�C\n", key, steps);
    }

    return 0;
}

//PS. �P�ǭ̳o�ӽm�߫ܭ��n��!! 

