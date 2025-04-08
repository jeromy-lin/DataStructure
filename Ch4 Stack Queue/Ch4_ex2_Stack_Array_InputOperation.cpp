/*
	��Ƶ��c�d��   
	�ĥ|�� : Stack and Queue 
	�d�� 2 : Stack �ŧi�H�ΨϥΤ�k(Array)
	�H��J�ƭȶi��stack�ާ@
    ��J 1 : Push
    ��J 2 : Pop
    ��J 3 : Peek
    ��J 4 : Exit
     
    �����쪺�P�ǥi�H�ۦ�m��  
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // �w�q���|�j�p

// �ϥ� typedef �w�q���|���c
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// ��l�ư��|
void initStack(Stack* stack) {
    stack->top = -1;
}

// �ˬd���|�O�_����
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// �ˬd���|�O�_����
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// ��ܰ��|�����e
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

// push ����
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full, cannot push %d\n", value);
    } else {
        stack->top += 1;
        stack->arr[stack->top] = value;
        printf("%d has been pushed to the stack\n", value);
        printStack(stack);
    }
}

// pop ����
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop element\n");
        return -1;
    } else {
        int value = stack->arr[stack->top];
        stack->top -= 1;
        printf("Popped element: %d\n", value);
        printStack(stack);
        return value;
    }
}

// �d�ݰ��|��������
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot view top element\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

int main() {
    Stack stack;
    int choice, value;
    initStack(&stack);

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Push
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:  // Pop
                pop(&stack);
                break;
            case 3:  // Peek
                printf("Top element of the stack: %d\n", peek(&stack));
                break;
            case 4:  // Exit
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

