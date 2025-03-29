/*
    ��Ƶ��c�d��   
    �ĤT�� : Linked List 
    �d�� 10 : �`�I�إߴ��J�d�� 

*/

#include <stdio.h>
#include <stdlib.h>

// �w�q�쵲��C�`�I���c
typedef struct Node {
    int data;          // �`�I���
    struct Node *next; // ���V�U�@�Ӹ`�I������
} Node;

// �p���쵲��C����
int getLength(Node *linkedList) {
    int length = 0;      // ��l�ƪ��׬� 0
    
    
    Node *current = linkedList; // �q�쵲��C���Y�`�I�}�l
    while (current != NULL) {    // ���e�`�I���� NULL �ɡA�~��M��
        length++;            // ���ץ[ 1
        current = current->next; // ���ʨ�U�@�Ӹ`�I
    }
    return length;  // �^���쵲��C������
}

// �s�W�`�I���쵲��C����
Node* appendNode(Node *linkedList, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // �ʺA���t�s�`�I���O����
    if (newNode == NULL) { // �p�G�O������t����
        printf("�O������t���ѡI\n");
        return linkedList;  // ��^���쵲��C
    }
    newNode->data = newData;    // �]�m�s�`�I�����
    newNode->next = NULL;       // �s�`�I�� next �]�� NULL�A��ܥ��O�쵲��C������

    if (linkedList == NULL) {    // �p�G�쵲��C����
        return newNode;          // ��^�s�`�I�A�����ߤ@���`�I
    }

    Node *current = linkedList;  // �q�Y�`�I�}�l�M��
    while (current->next != NULL) {  // �����ݸ`�I
        current = current->next;  // ���ʨ�U�@�Ӹ`�I
    }
    current->next = newNode;   // �N���ݸ`�I�� next ���V�s�`�I
    return linkedList;          // ��^��s�᪺�쵲��C
}

// �b���w��m���J�s�`�I
Node* insertNode(Node *linkedList, int position, int newData) {
    int length = getLength(linkedList);   // ����쵲��C������
    Node *newNode = (Node *)malloc(sizeof(Node)); // �ʺA���t�s�`�I���O����
    if (newNode == NULL) { // �p�G�O������t����
        printf("�O������t���ѡI\n");
        return linkedList;  // ��^���쵲��C
    }
    newNode->data = newData;   // �]�m�s�`�I�����
    newNode->next = NULL;      // �s�`�I�� next �]�� NULL�A�w�]������

    // ���J���Y��
    if (position == 1) {
        newNode->next = linkedList; // �s�`�I�� next ���V��Ӫ��Y�`�I
        return newNode;             // ��^�s�`�I�A�����s���Y�`�I
    }

    // ���J������Τ���
    Node *current = linkedList;  // �q�Y�`�I�}�l�M��
    for (int i = 1; i < position - 1 && current->next != NULL; i++) { 
        current = current->next;  // �M������w��m���e�@�Ӹ`�I
    }
    newNode->next = current->next;  // �s�`�I�� next ���V��e�`�I�� next
    current->next = newNode;        // ��e�`�I�� next ���V�s�`�I
    return linkedList;              // ��^��s�᪺�쵲��C
}

// ����쵲��C���e
void printList(Node *linkedList) {
    Node *current = linkedList;  // �q�Y�`�I�}�l�M��
    while (current != NULL) {    // ���e�`�I���� NULL �ɡA�~��M��
        printf("%d -> ", current->data); // ��ܷ�e�`�I�����
        current = current->next; // ���ʨ�U�@�Ӹ`�I
    }
    printf("NULL\n");  // ��X���� NULL ����쵲��C������
}

// ����O����
void freeList(Node *linkedList) {
    Node *current;       // �ΨӹM���쵲��C������
    while (linkedList != NULL) {  // ���쵲��C�����Ů�
        current = linkedList;    // ��e�`�I
        linkedList = linkedList->next; // ���ʨ�U�@�Ӹ`�I
        free(current);  // �����e�`�I���O����
    }
}

int main() {
    // �ŧi�@�Ӫ�l�ƪŪ��쵲��C, ����Node���c�����ܼƫ��O�ŧi
    Node *linkedList = NULL;  

    // �s�W 1 ��  5 �`�I���쵲��C
    for (int i = 1; i <= 5; i++) {
        linkedList = appendNode(linkedList, i);  
        // �I�s appendNode ��Ʒs�WlinkedList�`�I
        // �ЦP�Ǫ`�N"�^�ǭ�"���P��ƦW�٤�����
        // Node* appendNode(Node *linkedList, int newData)
    }

    printf("��l�쵲��C: ");
    printList(linkedList);  // ��ܭ�l���쵲��C

    int position, newData;
    printf("�п�J�n���J����m (1~6): ");
    scanf("%d", &position);  // Ū�����J��m
    printf("�п�J�s�`�I���ƭ�: ");
    scanf("%d", &newData);   // Ū���s�`�I�����

    linkedList = insertNode(linkedList, position, newData); 
    
	/*�W�z�d�� ��linked list �H�Ϋ����ܼƼg�J�����n�[��
	 
	�I�s insertNode ���J�s�`�I
    ��J�������ܼƪ�"address" �^�Ǥ]�O�n��Ӥ����O
     �^�Ǭ���s�᪺�쵲��C��"address��}"
     �]����ƥ����n�H�ۦP�����O�ӫŧi
    Node* insertNode(Node *linkedList, int position, int newData)
    linkedList �u�O�u��l���Ъ������v  
	
	*/
    
    printf("���J�᪺�쵲��C: ");
    printList(linkedList);  // ��ܴ��J�᪺�쵲��C

    freeList(linkedList);  // �����쵲��C�Ҧ����O����
    return 0;
}

