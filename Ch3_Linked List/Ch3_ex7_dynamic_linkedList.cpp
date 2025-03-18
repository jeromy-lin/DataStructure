/*
	��Ƶ��c�d��   
	�ĤT�� : Linked List 
	�d�� 7 : �إ߰ʺA Linked List 
*/


#include <stdio.h>
#include <stdlib.h>

// �w�q Linked List ���`�I
typedef struct Node {
    int data;
    struct Node* next;  // Self-Referential Pointer
} Node;

int main() {
    // �ʺA���t�T�Ӹ`�I
    Node* head = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));
    Node* third = (Node*)malloc(sizeof(Node));

    // �]�w�`�I���ƾڻP�챵
    head->data = 1;
    head->next = second;  // ���V�ĤG�Ӹ`�I

    second->data = 2;
    second->next = third;  // ���V�ĤT�Ӹ`�I

    third->data = 3;
    third->next = NULL;    // �������

    // �C�L�쵲��C
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

