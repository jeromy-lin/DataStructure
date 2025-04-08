/*
	資料結構範例   
	第四章 : Stack and Queue 
	範例 2 : Stack 宣告以及使用方法(Array)
	以輸入數值進行stack操作
    輸入 1 : Push
    輸入 2 : Pop
    輸入 3 : Peek
    輸入 4 : Exit
     
    有興趣的同學可以自行練習  
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // 定義堆疊大小

// 使用 typedef 定義堆疊結構
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// 初始化堆疊
void initStack(Stack* stack) {
    stack->top = -1;
}

// 檢查堆疊是否為空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 檢查堆疊是否為滿
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// 顯示堆疊的內容
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

// push 元素
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

// pop 元素
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

// 查看堆疊頂部元素
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

