/*
	��Ƶ��c�d��   
	�ĥ|�� : Stack & Queue 
	�d�� 2 : �HArray�ŧiStack�i��T�w�ƭ� Push/Pop�m�� 
	����ܰO�����}, �P�ǽ��[��O�����l��}
	�H�ξާ@�ɭԪ��O�����m���ʪ��p 
	
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // �w�q���|�j�p

// �ϥ� typedef �w�q���|���c
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// ��l�ư��|�A����ܰ򩳰O�����}
void initStack(Stack* stack) {
    stack->top = -1;
    printf("Stack initialized at base address: %p\n\n", (void*)stack->arr);
}

// �ˬd���|�O�_����
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// �ˬd���|�O�_����
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// �^�ǥثe���|�j�p
int size(Stack* stack) {
    return stack->top + 1;
}

// ��ܰ��|�����e�ΰO�����}
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents (top -> bottom):\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("Value: %d at Address: %p\n", stack->arr[i], (void*)&stack->arr[i]);
        }
        printf("\n");
    }
}

// push ����
int push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full, cannot push %d\n", value);
        return 0;  // ���Ѧ^�� 0
    } else {
        stack->top = stack->top + 1;  // �� top �W�[ 1
        stack->arr[stack->top] = value;
        printf("%d has been pushed to the stack at address: %p\n", value, (void*)&stack->arr[stack->top]);
        printStack(stack);
        return 1;  // ���\�^�� 1
    }
}

// pop ����
int pop(Stack* stack, int* poppedValue) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop element\n");
        return 0;  // ���Ѧ^�� 0
    } else {
        *poppedValue = stack->arr[stack->top];
        stack->top = stack->top - 1;  // �� top ��� 1
        printf("Popped element: %d\n", *poppedValue);
        printStack(stack);
        return 1;  // ���\�^�� 1
    }
}

// �d�ݰ��|��������
int peek(Stack* stack, int* topValue) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot view top element\n");
        return 0;  
    } else {
        *topValue = stack->arr[stack->top];
        return 1;
    }
}

int main() {
    Stack stack;
    initStack(&stack);  // ��l�ư��|�A����ܰ򩳰O�����}

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);  // Stack is full, cannot push

    int topValue;
    if (peek(&stack, &topValue)) {
        printf("Top element of the stack: %d\n", topValue);
    }

    int poppedValue;
    pop(&stack, &poppedValue);
    pop(&stack, &poppedValue);

    if (peek(&stack, &topValue)) {
        printf("Top element of the stack: %d\n", topValue);
    }

    printf("Stack size: %d\n", size(&stack));

    return 0;
}

