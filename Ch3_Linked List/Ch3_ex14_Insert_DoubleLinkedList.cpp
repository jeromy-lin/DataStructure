/*
	��Ƶ��c�d��   
	�ĤT�� : Circular Linked List 
	�d�� 14: �إ������쵲��C�ô��J���w�`�I 
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

// �b���w��m���J�s�`�I
Node* insertAtPosition(Node* head, int newData, int position) {
    if (position < 1) {
        printf("�L�Ī���m�I\n");
        return head;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("�O������t���ѡI\n");
        return head;
    }
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (position == 1) { 
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }
    
    Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("��m�W�X�d��A�L�k���J�I\n");
        free(newNode);
        return head;
    }
    
    newNode->next = current->next;
    if (current->next != NULL)
        current->next->prev = newNode;
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
    
    // ���إ� 1~10 �����V�쵲��C
    for (int i = 1; i <= 10; i++) {
        linkedList = appendNode(linkedList, i);
    }
    printList(linkedList);
    
    int value, position;
    while (1) {
        printf("��J�ƭ� (1~100, ��J 0 ����): ");
        scanf("%d", &value);
        if (value == 0) break;
        if (value < 1 || value > 100) {
            printf("�п�J 1~100 �������ƭȡI\n");
            continue;
        }
        
        printf("��J���J��m: ");
        scanf("%d", &position);
        
        linkedList = insertAtPosition(linkedList, value, position);
        printList(linkedList);
    }
    
    freeList(linkedList);
    return 0;
}

