/*
	��Ƶ��c�d��   
	�ĤT�� : Linked List 
	�d�� 3 : �ŧi&�إߤ@�뫬Linked List 
*/

#include <stdio.h>
#include <stdlib.h>

// �w�q Linked List ���`�I
typedef struct Node {
    int data;
    struct Node* next;  
	// �ۧڰѷӫ��Ъ��]�pSelf-Referential Pointer
} Node;
// �ЦP�ǰȥ����O Linked List�ŧi��C�y�����g�覡 

int main() {

    Node head1;
	head1.data = 10; //�]�w�`�I��
	head1.next = NULL; //�`�I���VNull 
    
	printf("�`�I��� : %d\n",head1.data);

    return 0;
}

