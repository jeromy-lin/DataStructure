/*
	資料結構範例   
	第三章 : Circular Linked List 
	範例 12: 建立環狀鏈結串列並刪除指定節點 
*/
#include <stdio.h>
#include <stdlib.h>

// 定義鏈結串列節點結構
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 計算環狀鏈結串列長度
int getLength(Node *linkedList) {
    if (linkedList == NULL) return 0;
    int length = 0;
    Node *current = linkedList;
    do {
        length++;
        current = current->next;
    } while (current != linkedList);
    return length;
}

// 新增節點到環狀鏈結串列尾端
Node* appendNode(Node *linkedList, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("記憶體分配失敗！\n");
        return linkedList;
    }
    newNode->data = newData;
    newNode->next = newNode;

    if (linkedList == NULL) {
        return newNode;
    }

    Node *current = linkedList;
    while (current->next != linkedList) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = linkedList;
    return linkedList;
}

// 刪除指定位置的節點
Node* deleteNode(Node *linkedList, int position) {
    if (linkedList == NULL) {
        printf("鏈結串列為空！\n");
        return NULL;
    }

    int length = getLength(linkedList);
    if (position < 1 || position > length) {
        printf("位置超出範圍！\n");
        return linkedList;
    }

    Node *current = linkedList, *prev = NULL;
    if (position == 1) {
        while (current->next != linkedList) {
            current = current->next;
        }
        if (linkedList == linkedList->next) {
            free(linkedList);
            return NULL;
        }
        current->next = linkedList->next;
        free(linkedList);
        return current->next;
    }

    current = linkedList;
    for (int i = 1; i < position; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
    return linkedList;
}

// 顯示環狀鏈結串列內容
void printList(Node *linkedList) {
    if (linkedList == NULL) {
        printf("鏈結串列為空！\n");
        return;
    }
    Node *current = linkedList;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != linkedList);
    printf("(回到起點)\n");
}

// 釋放記憶體
void freeList(Node *linkedList) {
    if (linkedList == NULL) return;
    Node *current = linkedList;
    Node *nextNode;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != linkedList);
}

int main() {
    Node *linkedList = NULL;
    
    for (int i = 1; i <= 10; i++) {
        linkedList = appendNode(linkedList, i);
    }

    printf("原始環狀鏈結串列: ");
    printList(linkedList);

    int position;
    printf("請輸入要刪除的位置 (1~10): ");
    scanf("%d", &position);

    linkedList = deleteNode(linkedList, position);
    
    printf("刪除後的環狀鏈結串列: ");
    printList(linkedList);

    freeList(linkedList);
    return 0;
}

