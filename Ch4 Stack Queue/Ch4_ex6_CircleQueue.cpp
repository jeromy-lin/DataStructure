/*
	��Ƶ��c�d��   
	�ĥ|�� : Stack & Queue 
	�d�� 6 : �H Array �ŧi ���� Queue 
	�i��T�w�ƭ� Enqueue/Dequeue �m�� 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // �w�q��C�j�p

// �ϥ� typedef �w�q��C���c
typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
    int count;  
} Queue;

// ��l�Ʀ�C
void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->count = 0;
}

// �ˬd��C�O�_����
int isEmpty(Queue* queue) {
    return queue->count == 0;
}

// �ˬd��C�O�_����
int isFull(Queue* queue) {
    return queue->count == MAX;
}

// �^�ǥثe��C�j�p
int size(Queue* queue) {
    return queue->count;
}

// ��ܦ�C�����e
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contents (front -> rear): ");
        for (int i = 0; i < queue->count; i++) {
            int index = (queue->front + i) % MAX;
            printf("%d ", queue->arr[index]);
        }
        printf("\n");
    }
}

// Enqueue (�[�J����)
int enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return 0;
    } else {
        queue->arr[queue->rear] = value;
        queue->rear = (queue->rear + 1) % MAX;
        queue->count++;
        printf("%d has been enqueued\n", value);
        printQueue(queue);
        return 1;
    }
}

// Dequeue (��������)
int dequeue(Queue* queue, int* dequeuedValue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue\n");
        return 0;
    } else {
        *dequeuedValue = queue->arr[queue->front];
        queue->front = (queue->front + 1) % MAX;
        queue->count--;
        printf("Dequeued element: %d\n", *dequeuedValue);
        printQueue(queue);
        return 1;
    }
}

// �d�ݦ�C���e�ݤ���
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
    enqueue(&queue, 60);  // Queue is full

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

    enqueue(&queue, 60);  

    printf("Queue size: %d\n", size(&queue));

    return 0;
}

