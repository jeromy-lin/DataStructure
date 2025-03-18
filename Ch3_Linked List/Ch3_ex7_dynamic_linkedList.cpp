/*
	資料結構範例   
	第三章 : Linked List 
	範例 7 : 建立動態 Linked List 
*/


#include <stdio.h>
#include <stdlib.h>

// 定義 Linked List 的節點
typedef struct Node {
    int data;
    struct Node* next;  // Self-Referential Pointer
} Node;

int main() {
    // 動態分配三個節點
    Node* head = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));
    Node* third = (Node*)malloc(sizeof(Node));

    // 設定節點的數據與鏈接
    head->data = 1;
    head->next = second;  // 指向第二個節點

    second->data = 2;
    second->next = third;  // 指向第三個節點

    third->data = 3;
    third->next = NULL;    // 結束鏈表

    // 列印鏈結串列
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

