/*
    ��Ƶ��c�d��   
    �ĤT�� : Linked List 
    �d�� 9 : �̧ǫإ߰ʺA Linked List 
    �ЦP���[��T�Ӹ`�I���ʺA�]�p��k
    ���[��O������ܪ��p 
*/

#include <stdio.h>
#include <stdlib.h>

// �w�q�`�I���c
typedef struct Node {
    int data;
    struct Node *next;  // next �����V�U�@�Ӹ`�I������
} Node;

int main() {
    // �ʺA���t�O����ӳЫظ`�I
    Node *newNode1 = (Node *)malloc(sizeof(Node));
    Node *newNode2 = (Node *)malloc(sizeof(Node));
    Node *newNode3 = (Node *)malloc(sizeof(Node));

    // �]�w head ���V�Ĥ@�Ӹ`�I    
    Node *head = newNode1;

    // �]�w�`�I���ȩM���V�U�@�Ӹ`�I 
    newNode1->data = 10;
    newNode1->next = newNode2;

    newNode2->data = 20;
    newNode2->next = newNode3;

    newNode3->data = 30;
    newNode3->next = NULL;

    // Linked List Address��ܪ�� 
    printf("\n======================================================\n");
    printf("| Node# | Address          | Data | Next Address     |\n");

    // �ϥ� head ���p�쵲��C�æC�L
    Node *current = head;
    int nodeNum = 1;
    while (current != NULL) {
        printf("| %-5d | %p | %-4d | %p |\n", nodeNum, current, current->data, current->next);
        current = current->next;
        nodeNum++;
    }
    printf("======================================================\n");
    // ����O����
    free(newNode1);
    free(newNode2);
    free(newNode3);
    return 0;
}

