/*
	��Ƶ��c�d��   
	�ĤT�� : Linked List 
	�d�� 9 : �s�Wnew linked list node 
	�����ק� main ���� head�A���ݭn�^�ǭ�
	�A�X�ݭn���� head �ܼƪ����ҡ]�p insertAtHead�^
	** �y�k�������[�A�]���n�ǻ� &head
	�����Ъ����� 
*/


#include <stdio.h>
#include <stdlib.h>

// �w�q�쵲��C�`�I���c
typedef struct Node {
    int data;            // �x�s�ƾ�
    struct Node *next;   // ���V�U�@�Ӹ`�I������
} Node;

// �s�W�`�I���쵲��C����
void appendNode(Node **head, int newData) {
    // �إ߷s�`�I
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�O������t���ѡI\n");
        return;
    }
    newNode->data = newData;
    newNode->next = NULL;

    // �p�G�쵲��C���šA���s�`�I���� head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // ���̫�@�Ӹ`�I
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // ���̫�@�Ӹ`�I�� next ���V�s�`�I
    temp->next = newNode;
}

// ��X�쵲��C���e
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ����O����
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;  // ��l���쵲��C����

    // �s�W�`�I
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);

    // ����쵲��C
    printf("�쵲��C���e: ");
    printList(head);

    // ����O����
    freeList(head);

    return 0;
}

