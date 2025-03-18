/*
	��Ƶ��c�d��   
	�ĤT�� : Linked List 
	�d�� 10 : �s�Wnew linked list node 
	�H Node* return linkedList
	�@���ܼƦ^�� 
*/
#include <stdio.h>
#include <stdlib.h>

// �w�q�쵲��C�`�I���c
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// �p���쵲��C����
int getLength(Node *linkedList) {
    int length = 0;
    Node *current = linkedList;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// �s�W�`�I���쵲��C����
Node* appendNode(Node *linkedList, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�O������t���ѡI\n");
        return linkedList;
    }
    newNode->data = newData;
    newNode->next = NULL;

    if (linkedList == NULL) {
        return newNode;
    }

    Node *current = linkedList;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return linkedList;
}

// �b���w��m���J�s�`�I
Node* insertNode(Node *linkedList, int position, int newData) {
    int length = getLength(linkedList);
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�O������t���ѡI\n");
        return linkedList;
    }
    newNode->data = newData;
    newNode->next = NULL;

    // ���J���Y��
    if (position == 1) {
        newNode->next = linkedList;
        return newNode;
    }

    // ���J������Τ���
    Node *current = linkedList;
    for (int i = 1; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return linkedList;
}

// ����쵲��C���e
void printList(Node *linkedList) {
    Node *current = linkedList;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ����O����
void freeList(Node *linkedList) {
    Node *current;
    while (linkedList != NULL) {
        current = linkedList;
        linkedList = linkedList->next;
        free(current);
    }
}

int main() {
    Node *linkedList = NULL;
    
    for (int i = 1; i <= 10; i++) {
        linkedList = appendNode(linkedList, i);
    }

    printf("��l�쵲��C: ");
    printList(linkedList);

    int position, newData;
    printf("�п�J�n���J����m (1~11): ");
    scanf("%d", &position);
    printf("�п�J�s�`�I���ƭ�: ");
    scanf("%d", &newData);

    linkedList = insertNode(linkedList, position, newData);
    
    printf("���J�᪺�쵲��C: ");
    printList(linkedList);

    freeList(linkedList);
    return 0;
}

