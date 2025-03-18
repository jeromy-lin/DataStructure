/*
	��Ƶ��c�d��   
	�ĤT�� : Circular Linked List 
	�d�� 12: �إ������쵲��C�çR�����w�`�I 
*/
#include <stdio.h>
#include <stdlib.h>

// �w�q�쵲��C�`�I���c
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// �p�������쵲��C����
int getLength(Node *linkedList) {
    if (linkedList == NULL) return 0;
    int length = 0;
    Node *current = linkedList;
    do {
        length++;
        current = current->next;
    } while (current != linkedList);
    return length;
}

// �s�W�`�I�������쵲��C����
Node* appendNode(Node *linkedList, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�O������t���ѡI\n");
        return linkedList;
    }
    newNode->data = newData;
    newNode->next = newNode;

    if (linkedList == NULL) {
        return newNode;
    }

    Node *current = linkedList;
    while (current->next != linkedList) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = linkedList;
    return linkedList;
}

// �R�����w��m���`�I
Node* deleteNode(Node *linkedList, int position) {
    if (linkedList == NULL) {
        printf("�쵲��C���šI\n");
        return NULL;
    }

    int length = getLength(linkedList);
    if (position < 1 || position > length) {
        printf("��m�W�X�d��I\n");
        return linkedList;
    }

    Node *current = linkedList, *prev = NULL;
    if (position == 1) {
        while (current->next != linkedList) {
            current = current->next;
        }
        if (linkedList == linkedList->next) {
            free(linkedList);
            return NULL;
        }
        current->next = linkedList->next;
        free(linkedList);
        return current->next;
    }

    current = linkedList;
    for (int i = 1; i < position; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
    return linkedList;
}

// ��������쵲��C���e
void printList(Node *linkedList) {
    if (linkedList == NULL) {
        printf("�쵲��C���šI\n");
        return;
    }
    Node *current = linkedList;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != linkedList);
    printf("(�^��_�I)\n");
}

// ����O����
void freeList(Node *linkedList) {
    if (linkedList == NULL) return;
    Node *current = linkedList;
    Node *nextNode;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != linkedList);
}

int main() {
    Node *linkedList = NULL;
    
    for (int i = 1; i <= 10; i++) {
        linkedList = appendNode(linkedList, i);
    }

    printf("��l�����쵲��C: ");
    printList(linkedList);

    int position;
    printf("�п�J�n�R������m (1~10): ");
    scanf("%d", &position);

    linkedList = deleteNode(linkedList, position);
    
    printf("�R���᪺�����쵲��C: ");
    printList(linkedList);

    freeList(linkedList);
    return 0;
}

