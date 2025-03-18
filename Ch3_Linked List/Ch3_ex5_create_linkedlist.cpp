/*
	��Ƶ��c�d��   
	�ĤT�� : Linked List 
	�d�� 5 : �إ� �@�뫬�P���Ы� Linked List 
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
    // �H�w�qlinked list ��ƫ��A��Node���O 
	// �W�٬� head 
	// �ϥ� malloc �t�m�O����  
    Node *head1 = (Node *)malloc(sizeof(Node));
	Node  head2;
    if (head1 == NULL) {
        printf("�O������t���ѡI\n");
        return 1;
    }

    head1->data = 10;  //  �]�w�`�I��
    head1->next = NULL; // �`�I���VNull 

    head2.data = 20;  //  �]�w�`�I��
    head2.next = NULL;  //  �]�w�`�I��

    printf("head1�`�I���: %d\n", head1->data);
 	printf("head2�`�I���: %d\n", head2.data);
    // ����O����
    free(head1);
    
    return 0;
}

