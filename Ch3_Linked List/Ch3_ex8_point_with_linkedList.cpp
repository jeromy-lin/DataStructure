/*
	��Ƶ��c�d��   
	�ĤT�� : Linked List 
	�d�� 8 : ���Ъ���m�m�� 
*/


#include <stdio.h>
#include <stdlib.h>

// �w�q�쵲��C���`�I
typedef struct node {
    int data;          
    struct node* next; // ���V�U�@�Ӹ`�I������
} Node;

int main() {
    // 1: �ŧi�@�� int �����ܼơA�ë��V�@�� int �ƭ�
    int value = 10;
//  int *ptr = &value; // ptr ���V�ܼ� value ���O�����m
//	int* ptr = &value; // ptr ���V�ܼ� value ���O�����m
    int * ptr = &value; // ptr ���V�ܼ� value ���O�����m

    printf("Value: %d\n", value);
    printf("Pointer Address: %p\n", (void*)ptr);
    printf("Pointer Dereference: %d\n\n", *ptr);

    // 2: �إ��쵲��C
    Node* head = NULL; // ��l���쵲��C����

    // 3: �s�W�`�I
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->data = 10;
    newNode1->next = head;
    head = newNode1;

    Node * newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->data = 20;
    newNode2->next = head;
    head = newNode2;

    Node *newNode3 = (Node*)malloc(sizeof(Node));
    newNode3->data = 30;
    newNode3->next = head;
    head = newNode3;

    // 4: �C�L�쵲��C���e
    printf("Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

