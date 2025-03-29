/*
	資料結構範例   
	第三章 : Circular Linked List 
	範例 14: 建立環狀鏈結串列並插入指定節點 
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

// 在指定位置插入新節點
Node* insertAtPosition(Node* head, int newData, int position) {
    if (position < 1) {
        printf("無效的位置！\n");
        return head;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("記憶體分配失敗！\n");
        return head;
    }
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (position == 1) { 
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }
    
    Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("位置超出範圍，無法插入！\n");
        free(newNode);
        return head;
    }
    
    newNode->next = current->next;
    if (current->next != NULL)
        current->next->prev = newNode;
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
    
    // 先建立 1~10 的雙向鏈結串列
    for (int i = 1; i <= 10; i++) {
        linkedList = appendNode(linkedList, i);
    }
    printList(linkedList);
    
    int value, position;
    while (1) {
        printf("輸入數值 (1~100, 輸入 0 結束): ");
        scanf("%d", &value);
        if (value == 0) break;
        if (value < 1 || value > 100) {
            printf("請輸入 1~100 之間的數值！\n");
            continue;
        }
        
        printf("輸入插入位置: ");
        scanf("%d", &position);
        
        linkedList = insertAtPosition(linkedList, value, position);
        printList(linkedList);
    }
    
    freeList(linkedList);
    return 0;
}

