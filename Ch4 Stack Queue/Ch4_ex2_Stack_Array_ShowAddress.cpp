/*
	資料結構範例   
	第四章 : Stack & Queue 
	範例 2 : 以Array宣告Stack進行固定數值 Push/Pop練習 
	並顯示記憶體位址, 同學請觀察記憶體初始位址
	以及操作時候的記憶體位置移動狀況 
	
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // 定義堆疊大小

// 使用 typedef 定義堆疊結構
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// 初始化堆疊，並顯示基底記憶體位址
void initStack(Stack* stack) {
    stack->top = -1;
    printf("Stack initialized at base address: %p\n\n", (void*)stack->arr);
}

// 檢查堆疊是否為空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 檢查堆疊是否為滿
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// 回傳目前堆疊大小
int size(Stack* stack) {
    return stack->top + 1;
}

// 顯示堆疊的內容及記憶體位址
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

// push 元素
int push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full, cannot push %d\n", value);
        return 0;  // 失敗回傳 0
    } else {
        stack->top = stack->top + 1;  // 讓 top 增加 1
        stack->arr[stack->top] = value;
        printf("%d has been pushed to the stack at address: %p\n", value, (void*)&stack->arr[stack->top]);
        printStack(stack);
        return 1;  // 成功回傳 1
    }
}

// pop 元素
int pop(Stack* stack, int* poppedValue) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop element\n");
        return 0;  // 失敗回傳 0
    } else {
        *poppedValue = stack->arr[stack->top];
        stack->top = stack->top - 1;  // 讓 top 減少 1
        printf("Popped element: %d\n", *poppedValue);
        printStack(stack);
        return 1;  // 成功回傳 1
    }
}

// 查看堆疊頂部元素
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
    initStack(&stack);  // 初始化堆疊，並顯示基底記憶體位址

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

