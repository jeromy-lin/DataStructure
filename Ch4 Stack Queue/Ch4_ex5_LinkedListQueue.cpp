/*
	��Ƶ��c�d��   
	�ĥ|�� : Stack & Queue 
	�d�� 5 : �H Array �ŧi Queue �i��T�w�ƭ� Enqueue/Dequeue �m�� 
*/

#include <stdio.h>
#include <stdlib.h>

// �w�q�`�I���c

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue ���c�A�]�t front �M rear ����

typedef struct Queue {
    Node* front;  
    Node* rear;   
} Queue;

// ��l�� queue

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// �ˬdqueue�O�_����

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

// �d�ݫe�ݤ���

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot view front element\n");
        return -1;
    }
    return queue->front->data;
}

// �C�L queue ���A�]�q rear �� front�^

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents (right to left): ");

    // �n�q rear �� front�A�����������`�I���СA�A�f�ǦL�X
    Node* nodes[100];  // ���]���|�W�L 100 �Ӹ`�I
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


