/*
    ��Ƶ��c�d��   
    �ĤT�� : Linked List 
    �d�� 10 : �`�I�إߧR���d�� 

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

// �R�����w��m���`�I
Node* deleteNode(Node *linkedList, int position) {
    if (linkedList == NULL) {
        printf("�쵲��C���šA�L�k�R���I\n");
        return NULL;
    }
    
    int length = getLength(linkedList);
    if (position < 1 || position > length) {
        printf("�L�Ī���m�I\n");
        return linkedList;
    }
    
    Node *temp;
    if (position == 1) {
        temp = linkedList;
        linkedList = linkedList->next;
        free(temp);
        return linkedList;
    }
    
    Node *current = linkedList;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }
    temp = current->next;
    current->next = temp->next;
    free(temp);
    
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
    for (int i = 1; i <= 5; i++) {
        linkedList = appendNode(linkedList, i);
    }

    printf("��l�쵲��C: ");
    printList(linkedList);
    
    int position;
    printf("�п�J�n�R������m (1~5): ");
    scanf("%d", &position);
    
    linkedList = deleteNode(linkedList, position);
    
    printf("�R���᪺�쵲��C: ");
    printList(linkedList);
    
    freeList(linkedList);
    return 0;
}

