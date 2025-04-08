/*
	��Ƶ��c�d��   
	�ĥ|�� : Stack and Queue 
	�d�� 3 : Stack �ŧi�H�ΨϥΤ�k(Linked list)
	
*/

#include <stdio.h>
#include <stdlib.h>

// �w�q���|(stack)���`�I���c
typedef struct stack {
    int value;          // �s����|(stack)��������
    struct stack* next; // ���V�U�@�Ӹ`�I�]�U�@�Ӱ��|(stack)�����^
} stack;

stack* head = NULL;     // ���V���|(stack)�����ݡ]�̤W�h�^

// ��l�ư��|(stack)
void initStack() {
    head = NULL;       // �]�m���|(stack)����
}

// �ˬd���|(stack)�O�_����
int isEmpty() {
    return head == NULL;  // �p�G head �� NULL�A��ܰ��|(stack)����
}

// �j�M����ܰ��|(stack)���e
void printStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        stack* current = head;  // �]�w�j�M����
        printf("Stack contents: ");
        while (current != NULL) {  // �j�M���|(stack)�A�v�@�C�L����
            printf("%d ", current->value);
            current = current->next;  // ���ʨ�U�@�Ӹ`�I
        }
        printf("\n");
    }
}

// push �ާ@�G�N�s�������J���|(stack)

void push(int value) {
    stack* newStack = (stack*)malloc(sizeof(stack));  
	// �ŧilinked list�O�o�n..�ʺA���t�O����
	
    if (newStack == NULL) {  // �ˬd�O������t�O�_���\
        printf("Memory allocation failed\n");
        return;
    }
    newStack->value = value;  // �]�m�s�`�I����
    newStack->next = head;    // ���s�`�I���V��e�����|(stack)����
    head = newStack;          // ��s head�A�Ϩ���V�s�����|(stack)����

    printf("%d has been pushed to the stack\n", value);
    printStack();
}

// pop �ާ@�G�����ê�^���|(stack)�����ݤ���

int pop() {
    if (isEmpty()) {  // �p�G���|(stack)���šA�h�L�k���� pop
        printf("Stack is empty, cannot pop element\n");
        return -1;
    } else {
        stack* temp = head;  // �O����e�����ݸ`�I
        int value = temp->value;  // ���o���ݸ`�I����
        head = head->next;  // ���� head�A�Ϩ���V�U�@�Ӹ`�I
        free(temp);  // ����쳻�ݸ`�I���O����

        printf("Popped element: %d\n", value);
        printStack();
        return value;
    }
}

// peek �ާ@�G��^���|(stack)�����ݤ����]�����R���^

int peek() {
    if (isEmpty()) {  // �p�G���|(stack)���šA�h�L�k���� peek
        printf("Stack is empty, cannot view top element\n");
        return -1;
    } else {
        return head->value;  // ��^���ݤ�������
    }
}

// �D�{��
int main() {
    // ��l�ư��|(stack)
    initStack();

    // ���� push �ާ@�A�N�����[�J���|(stack)
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    // ���o���|(stack)���ݪ�����
    printf("Top element of the stack: %d\n", peek());

    // ���� pop �ާ@�A�������|(stack)���ݤ���
    pop();
    pop();

    // �A�����o���|(stack)���ݪ�����
    printf("Top element of the stack: %d\n", peek());

    return 0;
}

