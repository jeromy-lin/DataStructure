/*
	資料結構範例   
	第三章 : Linked List 
	範例 9 : 新增new linked list node 
	直接修改 main 內的 head，不需要回傳值
	適合需要改變 head 變數的情境（如 insertAtHead）
	** 語法較不直觀，因為要傳遞 &head
	為指標的指標 
*/


#include <stdio.h>
#include <stdlib.h>

// 定義鏈結串列節點結構
typedef struct Node {
    int data;            // 儲存數據
    struct Node *next;   // 指向下一個節點的指標
} Node;

// 新增節點到鏈結串列尾端
void appendNode(Node **head, int newData) {
    // 建立新節點
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("記憶體分配失敗！\n");
        return;
    }
    newNode->data = newData;
    newNode->next = NULL;

    // 如果鏈結串列為空，讓新節點成為 head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // 找到最後一個節點
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // 讓最後一個節點的 next 指向新節點
    temp->next = newNode;
}

// 輸出鏈結串列內容
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 釋放記憶體
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;  // 初始化鏈結串列為空

    // 新增節點
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);

    // 顯示鏈結串列
    printf("鏈結串列內容: ");
    printList(head);

    // 釋放記憶體
    freeList(head);

    return 0;
}

