/*
	資料結構範例   
	第三章 : Circular Linked List 
	範例 15: 建立環狀鏈結串列並刪除指定節點 
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

// 刪除指定位置的節點
Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL || position < 1) {
        printf("無效的位置或鏈結串列為空！\n");
        return head;
    }
    Node* current = head;
    if (position == 1) { 
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(current);
        return head;
    }
    
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("位置超出範圍，無法刪除！\n");
        return head;
    }
    
    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;
    
    free(current);
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
    
    int position;
    while (1) {
        printf("輸入要刪除的節點位置 (輸入 0 結束): ");
        scanf("%d", &position);
        if (position == 0) break;
        
        linkedList = deleteAtPosition(linkedList, position);
        printList(linkedList);
    }
    
    freeList(linkedList);
    return 0;
}

