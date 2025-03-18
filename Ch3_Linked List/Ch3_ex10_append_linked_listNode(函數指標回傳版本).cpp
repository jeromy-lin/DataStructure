/*
	資料結構範例   
	第三章 : Linked List 
	範例 10 : 新增new linked list node 
	以 Node* return linkedList
	作為變數回傳 
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

// 在指定位置插入新節點
Node* insertNode(Node *linkedList, int position, int newData) {
    int length = getLength(linkedList);
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("記憶體分配失敗！\n");
        return linkedList;
    }
    newNode->data = newData;
    newNode->next = NULL;

    // 插入到頭部
    if (position == 1) {
        newNode->next = linkedList;
        return newNode;
    }

    // 插入到尾部或中間
    Node *current = linkedList;
    for (int i = 1; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
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
    
    for (int i = 1; i <= 10; i++) {
        linkedList = appendNode(linkedList, i);
    }

    printf("原始鏈結串列: ");
    printList(linkedList);

    int position, newData;
    printf("請輸入要插入的位置 (1~11): ");
    scanf("%d", &position);
    printf("請輸入新節點的數值: ");
    scanf("%d", &newData);

    linkedList = insertNode(linkedList, position, newData);
    
    printf("插入後的鏈結串列: ");
    printList(linkedList);

    freeList(linkedList);
    return 0;
}

