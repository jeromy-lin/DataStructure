/*
	��Ƶ��c�d��   
	�ĤT�� : Linked List 
	�d�� 4 : �إ߫��Ы� Linked List 
*/

#include <stdio.h>
#include <stdlib.h>
// �w�q�쵲��C�`�I

typedef struct Node {
    int data;            // �x�s�ƾ�
    struct Node *next;   // ���V�U�@�Ӹ`�I������
} Node;
// Self-Referential Pointer�ۧڰѷӫ��Ъ��]�p
 
int main() {

	// �ϥ� malloc �t�m�O����  
    Node *head1 = (Node *)malloc(sizeof(Node));
    if (head1 == NULL) {
        printf("�O������t���ѡI\n");
        return 1;
    }

    head1->data = 10;  //  �]�w�`�I��
    head1->next = NULL; // �`�I���VNull 

    printf("�`�I���: %d\n", head1->data);
    // ����O����
    free(head1);    
    return 0;
}



