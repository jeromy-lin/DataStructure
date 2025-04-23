/*
	資料結構範例   
	第四章 : Stack & Queue 
	範例 4 : 以 Array 宣告 Queue 進行固定數值 Enqueue/Dequeue 練習 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // 定義佇列大小

// 使用 typedef 定義佇列結構

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// 初始化佇列

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

// 檢查佇列是否為空

int isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

// 檢查佇列是否為滿

int isFull(Queue* queue) {
    return queue->rear == MAX - 1;
}

// 回傳目前佇列大小

int size(Queue* queue) {
    return isEmpty(queue) ? 0 : queue->rear - queue->front + 1;
}

// 顯示佇列的內容
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contents (front -> rear): ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

// Enqueue (加入元素)
int enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return 0;  // 失敗回傳 0
    } else {
        queue->rear++;
        queue->arr[queue->rear] = value;
        printf("%d has been enqueued\n", value);
        printQueue(queue);
        return 1;  // 成功回傳 1
    }
}

// Dequeue (移除元素)
int dequeue(Queue* queue, int* dequeuedValue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue\n");
        return 0;  // 失敗回傳 0
    } else {
        *dequeuedValue = queue->arr[queue->front];
        queue->front++;
        printf("Dequeued element: %d\n", *dequeuedValue);
        printQueue(queue);
        return 1;  // 成功回傳 1
    }
}

// 查看佇列的前端元素
int peek(Queue* queue, int* frontValue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot view front element\n");
        return 0;
    } else {
        *frontValue = queue->arr[queue->front];
        return 1;
    }
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);  // Queue is full, cannot enqueue

    int frontValue;
    if (peek(&queue, &frontValue)) {
        printf("Front element of the queue: %d\n", frontValue);
    }

    int dequeuedValue;
    dequeue(&queue, &dequeuedValue);
    dequeue(&queue, &dequeuedValue);

    if (peek(&queue, &frontValue)) {
        printf("Front element of the queue: %d\n", frontValue);
    }

    printf("Queue size: %d\n", size(&queue));

    return 0;
}
