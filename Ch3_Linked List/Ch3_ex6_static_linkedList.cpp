/*
	��Ƶ��c�d��   
	�ĤT�� : Linked List 
	�d�� 6 : �إ�static Linked List 
*/


#include <stdio.h>

#define SIZE 3  // �}�C�j�p (�`�I�ƶq)

// �w�q Linked List ���`�I (�R�A�}�C����)
typedef struct {
    int data;
    int next;  // �ί��ިӼ������� (-1 �N�� NULL)
} Node;

int main() {
    // �ŧi�@�Ӱ}�C�Ӧs�x Linked List
    Node list[SIZE];

    // ��l�Ƹ`�I
    list[0].data = 1;
    list[0].next = 1;  // ���V�}�C�������� 1 (�ĤG�Ӹ`�I)

    list[1].data = 2;
    list[1].next = 2;  // ���V�}�C�������� 2 (�ĤT�Ӹ`�I)

    list[2].data = 3;
    list[2].next = -1; // -1 �N�� NULL (�쵲��C����)

        int index = 0;
    while (index != -1) {
        printf("%d -> ", list[index].data);
        index = list[index].next;
    }
    printf("NULL\n");

    return 0;
}

