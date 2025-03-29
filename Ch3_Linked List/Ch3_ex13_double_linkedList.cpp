/*
	��Ƶ��c�d��   
	�ĤT�� : Circular Linked List 
	�d�� 13: �إ������쵲��C
*/

#include <stdio.h>
#include <stdlib.h>

// �w�q���V�쵲��C�`�I���c
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

// �s�W�`�I���쵲��C����
Node* appendNode(Node* head, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("�O������t���ѡI\n");
        return head;
    }
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        return newNode;  
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// �L�X�쵲��C (���V)
void printList(Node* head) {
    Node* current = head;
    printf("�쵲��C: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// �����쵲��C�O����
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* linkedList = NULL;
    
    // ���ϥ� for �j��إ� 1~10 �����V�쵲��C
    for (int i = 1; i <= 10; i++) {
        linkedList = appendNode(linkedList, i);
    }
    printList(linkedList);
    
    freeList(linkedList);
    return 0;
}

