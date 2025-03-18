/*
	��Ƶ��c�d��   
	�ĤT�� : Linked List 
	�d�� 9 : �s�Wnew linked list node 
	Linked List�ŧi��Global ���ݭn�z�L��ƶǻ� 
	TIPS : ���d�ҥH�����ܼƫŧi
	Linked List �ЦP�ǥ��F�ѹB�@�Ҧ�
	�b�ǲߦp��z�L�����ܼƶǻ�Linked List 
*/

#include <stdio.h>
#include <stdlib.h>

// �w�q�쵲��C�`�I���c
typedef struct Node {
    int data;            
    struct Node *next;   
} Node;

// �ŧi�����ܼ� �쵲��C���`�I 
Node *linkedList = NULL;

// �p���쵲��C����
int getLength(Node *linkedList) {
    int length = 0;
    Node *current = linkedList;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}


void appendNode(int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�O������t���ѡI\n");
        return;
    }
    newNode->data = newData;
    newNode->next = NULL;

    // �p�G linkedList �O�Ū��A�N�s�`�I�@��head
    if (linkedList == NULL) {
        linkedList = newNode;
        return;
    }

    Node *current = linkedList;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// �b���w��m���J�s�`�I
void insertNode(int position, int newData) {
    int length = getLength(linkedList);

    // �Ыطs�`�I
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�O������t���ѡI\n");
        return;
    }
    newNode->data = newData;
    newNode->next = NULL;

    Node *current = linkedList;
    //�H current �קK ���linkedList
	//�y���{���`�I�s����� 

    // ���p 1�G���J���Y��
    if (position == 1) {
        newNode->next = linkedList;
        linkedList = newNode;  
		// ��s linkedList ���СA�N�s�`�I�]���Y�`�I
        return;
    }

    // ���p 2�G���J����� 
	//(EX: postion=10,��J11�h������)
    if (position > length) {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return;
    }

    // ���p 3�G�������J, ���w��m counter����J��m-1
	// EX: �b5��m���J, �hcounter�ƨ� 4 
    for (int i = 1; i < position - 1; i++) {
        if (current->next == NULL) break;
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// ����쵲��C���e
void printList() {
    Node *current = linkedList;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ����O����
void freeList() {
    Node *current;
    while (linkedList != NULL) {
        current = linkedList;
        linkedList = linkedList->next;
        free(current);
    }
}

int main() {
    // �ϥ� for �j��۰ʲ��� 10 �Ӹ`�I
    for (int i = 1; i <= 10; i++) {
        appendNode(i);  // �ǻ��s�ƭȵ� appendNode
    }

    printf("��l�쵲��C: ");
    printList();

    // �ЦP�ǿ�J���J��m�P�s�`�I��T 
    int position, newData;
    printf("�п�J�n���J����m (1~11): ");
    scanf("%d", &position);
    printf("�п�J�s�`�I���ƭ�: ");
    scanf("%d", &newData);

    insertNode(position, newData);  
	// �ǻ���m�M�s�ƾڵ� insertNode

    printf("���J�᪺�쵲��C: ");
    printList();

    freeList();  // ����O����
    return 0;
}

