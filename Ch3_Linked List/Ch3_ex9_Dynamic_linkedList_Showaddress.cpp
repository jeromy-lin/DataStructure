/*
    資料結構範例   
    第三章 : Linked List 
    範例 9 : 依序建立動態 Linked List 
    請同學觀察三個節點的動態設計方法
    並觀察記憶體顯示狀況 
*/

#include <stdio.h>
#include <stdlib.h>

// 定義節點結構
typedef struct Node {
    int data;
    struct Node *next;  // next 為指向下一個節點的指標
} Node;

int main() {
    // 動態分配記憶體來創建節點
    Node *newNode1 = (Node *)malloc(sizeof(Node));
    Node *newNode2 = (Node *)malloc(sizeof(Node));
    Node *newNode3 = (Node *)malloc(sizeof(Node));

    // 設定 head 指向第一個節點    
    Node *head = newNode1;

    // 設定節點的值和指向下一個節點 
    newNode1->data = 10;
    newNode1->next = newNode2;

    newNode2->data = 20;
    newNode2->next = newNode3;

    newNode3->data = 30;
    newNode3->next = NULL;

    // Linked List Address顯示表格 
    printf("\n======================================================\n");
    printf("| Node# | Address          | Data | Next Address     |\n");

    // 使用 head 串聯鏈結串列並列印
    Node *current = head;
    int nodeNum = 1;
    while (current != NULL) {
        printf("| %-5d | %p | %-4d | %p |\n", nodeNum, current, current->data, current->next);
        current = current->next;
        nodeNum++;
    }
    printf("======================================================\n");
    // 釋放記憶體
    free(newNode1);
    free(newNode2);
    free(newNode3);
    return 0;
}

