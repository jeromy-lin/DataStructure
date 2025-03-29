/*
	資料結構範例   
	第三章 : Circular Linked List 
	範例 13: 建立環狀鏈結串列
*/

#include <stdio.h>
#include <stdlib.h>

// 定義雙向鏈結串列節點結構
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

// 新增節點到鏈結串列尾端
Node* appendNode(Node* head, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("記憶體分配失敗！\n");
        return head;
    }
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        return newNode;  
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// 印出鏈結串列 (正向)
void printList(Node* head) {
    Node* current = head;
    printf("鏈結串列: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 釋放鏈結串列記憶體
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* linkedList = NULL;
    
    // 先使用 for 迴圈建立 1~10 的雙向鏈結串列
    for (int i = 1; i <= 10; i++) {
        linkedList = appendNode(linkedList, i);
    }
    printList(linkedList);
    
    freeList(linkedList);
    return 0;
}

