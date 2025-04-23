/*
	��Ƶ��c�d��   
	�ĥ|�� : Stack & Queue 
	�d�� 4 : �H Array �ŧi Queue �i��T�w�ƭ� Enqueue/Dequeue �m�� 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // �w�q��C�j�p

// �ϥ� typedef �w�q��C���c

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// ��l�Ʀ�C

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

// �ˬd��C�O�_����

int isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

// �ˬd��C�O�_����

int isFull(Queue* queue) {
    return queue->rear == MAX - 1;
}

// �^�ǥثe��C�j�p

int size(Queue* queue) {
    return isEmpty(queue) ? 0 : queue->rear - queue->front + 1;
}

// ��ܦ�C�����e
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

// Enqueue (�[�J����)
int enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return 0;  // ���Ѧ^�� 0
    } else {
        queue->rear++;
        queue->arr[queue->rear] = value;
        printf("%d has been enqueued\n", value);
        printQueue(queue);
        return 1;  // ���\�^�� 1
    }
}

// Dequeue (��������)
int dequeue(Queue* queue, int* dequeuedValue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue\n");
        return 0;  // ���Ѧ^�� 0
    } else {
        *dequeuedValue = queue->arr[queue->front];
        queue->front++;
        printf("Dequeued element: %d\n", *dequeuedValue);
        printQueue(queue);
        return 1;  // ���\�^�� 1
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
