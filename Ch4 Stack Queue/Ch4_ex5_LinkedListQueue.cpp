/*
	資料結構範例   
	第四章 : Stack & Queue 
	範例 5 : 以 Array 宣告 Queue 進行固定數值 Enqueue/Dequeue 練習 
*/

#include <stdio.h>
#include <stdlib.h>

// 定義節點結構

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue 結構，包含 front 和 rear 指標

typedef struct Queue {
    Node* front;  
    Node* rear;   
} Queue;

// 初始化 queue

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// 檢查queue是否為空

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}
void printQueue(Queue* queue);


void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d has been enqueued to the queue\n", value);
    printQueue(queue);
}


int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue element\n");
        return -1;
    }

    Node* temp = queue->front;
    int value = temp->data;

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    printf("Dequeued element: %d\n", value);
    printQueue(queue);
    return value;
}

// 查看前端元素

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot view front element\n");
        return -1;
    }
    return queue->front->data;
}

// 列印 queue 狀態（從 rear 到 front）

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents (right to left): ");

    // 要從 rear 到 front，必須先收集節點指標，再逆序印出
    Node* nodes[100];  // 假設不會超過 100 個節點
    int count = 0;

    Node* current = queue->front;
    while (current != NULL) {
        nodes[count++] = current;
        current = current->next;
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", nodes[i]->data);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);  

    printf("Front element of the queue: %d\n", peek(&queue));

    dequeue(&queue);
    dequeue(&queue);

    printf("Front element of the queue: %d\n", peek(&queue));

    return 0;
}


