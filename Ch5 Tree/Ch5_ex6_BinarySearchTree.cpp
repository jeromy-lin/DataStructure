/*
    ��Ƶ��c�d��
    �Ĥ��� : Tree
    �d�� 6 : �H�T�w�}�C�إ�binary search tree 
    
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left; 
	struct Node *right;
} Node;

// �إ߷s�`�I
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ���J��ƶi BST
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

// ���Ǩ��X�L�X �`�N : ���G�|�O�Ƨǫ᪺Tree node

int main() {
    int values[] = {28, 23, 33, 41, 22, 24}; 
    int n = sizeof(values) / sizeof(values[0]);
    
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("BST ���Ǩ��X�]�Ƨǵ��G�^�G");
    inorder(root);
    printf("\n");

    return 0;
}
     //C �y�����T�w����array�j�p�p�� 
    //�ЦP�ǰѦ� array element���p���k , sizeof(values=24), �N���Ӱ}�C���`�j�p , sizeof(values[0]) �� �N��}�C���@�Ӥ������j�p
    // 24 / 4 = 6 ��element

