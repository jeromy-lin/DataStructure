/*
    資料結構範例   
    第三章 : Linked List 
    範例 10 : 節點建立刪除範例 

*/

#include <stdio.h>
#include <stdlib.h>

// 定義鏈結串列節點結構
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 計算鏈結串列長度
int getLength(Node *linkedList) {
    int length = 0;
    Node *current = linkedList;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// 新增節點到鏈結串列尾端
Node* appendNode(Node *linkedList, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("記憶體分配失敗！\n");
        return linkedList;
    }
    newNode->data = newData;
    newNode->next = NULL;

    if (linkedList == NULL) {
        return newNode;
    }

    Node *current = linkedList;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return linkedList;
}

// 刪除指定位置的節點
Node* deleteNode(Node *linkedList, int position) {
    if (linkedList == NULL) {
        printf("鏈結串列為空，無法刪除！\n");
        return NULL;
    }
    
    int length = getLength(linkedList);
    if (position < 1 || position > length) {
        printf("無效的位置！\n");
        return linkedList;
    }
    
    Node *temp;
    if (position == 1) {
        temp = linkedList;
        linkedList = linkedList->next;
        free(temp);
        return linkedList;
    }
    
    Node *current = linkedList;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }
    temp = current->next;
    current->next = temp->next;
    free(temp);
    
    return linkedList;
}

// 顯示鏈結串列內容
void printList(Node *linkedList) {
    Node *current = linkedList;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 釋放記憶體
void freeList(Node *linkedList) {
    Node *current;
    while (linkedList != NULL) {
        current = linkedList;
        linkedList = linkedList->next;
        free(current);
    }
}

int main() {
    Node *linkedList = NULL;
    for (int i = 1; i <= 5; i++) {
        linkedList = appendNode(linkedList, i);
    }

    printf("原始鏈結串列: ");
    printList(linkedList);
    
    int position;
    printf("請輸入要刪除的位置 (1~5): ");
    scanf("%d", &position);
    
    linkedList = deleteNode(linkedList, position);
    
    printf("刪除後的鏈結串列: ");
    printList(linkedList);
    
    freeList(linkedList);
    return 0;
}

