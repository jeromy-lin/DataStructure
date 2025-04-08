/*
	資料結構範例   
	第四章 : Stack and Queue 
	範例 3 : Stack 宣告以及使用方法(Linked list)
	
*/

#include <stdio.h>
#include <stdlib.h>

// 定義堆疊(stack)的節點結構
typedef struct stack {
    int value;          // 存放堆疊(stack)元素的值
    struct stack* next; // 指向下一個節點（下一個堆疊(stack)元素）
} stack;

stack* head = NULL;     // 指向堆疊(stack)的頂端（最上層）

// 初始化堆疊(stack)
void initStack() {
    head = NULL;       // 設置堆疊(stack)為空
}

// 檢查堆疊(stack)是否為空
int isEmpty() {
    return head == NULL;  // 如果 head 為 NULL，表示堆疊(stack)為空
}

// 搜尋並顯示堆疊(stack)內容
void printStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        stack* current = head;  // 設定搜尋指標
        printf("Stack contents: ");
        while (current != NULL) {  // 搜尋堆疊(stack)，逐一列印元素
            printf("%d ", current->value);
            current = current->next;  // 移動到下一個節點
        }
        printf("\n");
    }
}

// push 操作：將新元素壓入堆疊(stack)

void push(int value) {
    stack* newStack = (stack*)malloc(sizeof(stack));  
	// 宣告linked list記得要..動態分配記憶體
	
    if (newStack == NULL) {  // 檢查記憶體分配是否成功
        printf("Memory allocation failed\n");
        return;
    }
    newStack->value = value;  // 設置新節點的值
    newStack->next = head;    // 讓新節點指向當前的堆疊(stack)頂端
    head = newStack;          // 更新 head，使其指向新的堆疊(stack)頂端

    printf("%d has been pushed to the stack\n", value);
    printStack();
}

// pop 操作：移除並返回堆疊(stack)的頂端元素

int pop() {
    if (isEmpty()) {  // 如果堆疊(stack)為空，則無法執行 pop
        printf("Stack is empty, cannot pop element\n");
        return -1;
    } else {
        stack* temp = head;  // 記錄當前的頂端節點
        int value = temp->value;  // 取得頂端節點的值
        head = head->next;  // 移動 head，使其指向下一個節點
        free(temp);  // 釋放原頂端節點的記憶體

        printf("Popped element: %d\n", value);
        printStack();
        return value;
    }
}

// peek 操作：返回堆疊(stack)的頂端元素（但不刪除）

int peek() {
    if (isEmpty()) {  // 如果堆疊(stack)為空，則無法執行 peek
        printf("Stack is empty, cannot view top element\n");
        return -1;
    } else {
        return head->value;  // 返回頂端元素的值
    }
}

// 主程式
int main() {
    // 初始化堆疊(stack)
    initStack();

    // 執行 push 操作，將元素加入堆疊(stack)
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    // 取得堆疊(stack)頂端的元素
    printf("Top element of the stack: %d\n", peek());

    // 執行 pop 操作，移除堆疊(stack)頂端元素
    pop();
    pop();

    // 再次取得堆疊(stack)頂端的元素
    printf("Top element of the stack: %d\n", peek());

    return 0;
}

