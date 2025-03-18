/*
	資料結構範例   
	第三章 : Linked List 
	範例 9 : 新增new linked list node 
	Linked List宣告為Global 不需要透過函數傳遞 
	TIPS : 此範例以全域變數宣告
	Linked List 請同學先了解運作模式
	在學習如何透過指標變數傳遞Linked List 
*/

#include <stdio.h>
#include <stdlib.h>

// 定義鏈結串列節點結構
typedef struct Node {
    int data;            
    struct Node *next;   
} Node;

// 宣告全域變數 鏈結串列的節點 
Node *linkedList = NULL;

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


void appendNode(int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("記憶體分配失敗！\n");
        return;
    }
    newNode->data = newData;
    newNode->next = NULL;

    // 如果 linkedList 是空的，將新節點作為head
    if (linkedList == NULL) {
        linkedList = newNode;
        return;
    }

    Node *current = linkedList;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// 在指定位置插入新節點
void insertNode(int position, int newData) {
    int length = getLength(linkedList);

    // 創建新節點
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("記憶體分配失敗！\n");
        return;
    }
    newNode->data = newData;
    newNode->next = NULL;

    Node *current = linkedList;
    //以 current 避免 更改linkedList
	//造成程式節點編輯錯亂 

    // 情況 1：插入到頭部
    if (position == 1) {
        newNode->next = linkedList;
        linkedList = newNode;  
		// 更新 linkedList 指標，將新節點設為頭節點
        return;
    }

    // 情況 2：插入到尾部 
	//(EX: postion=10,輸入11則為尾部)
    if (position > length) {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return;
    }

    // 情況 3：中間插入, 指定位置 counter為輸入位置-1
	// EX: 在5位置插入, 則counter數到 4 
    for (int i = 1; i < position - 1; i++) {
        if (current->next == NULL) break;
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// 顯示鏈結串列內容
void printList() {
    Node *current = linkedList;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 釋放記憶體
void freeList() {
    Node *current;
    while (linkedList != NULL) {
        current = linkedList;
        linkedList = linkedList->next;
        free(current);
    }
}

int main() {
    // 使用 for 迴圈自動產生 10 個節點
    for (int i = 1; i <= 10; i++) {
        appendNode(i);  // 傳遞新數值給 appendNode
    }

    printf("原始鏈結串列: ");
    printList();

    // 請同學輸入插入位置與新節點資訊 
    int position, newData;
    printf("請輸入要插入的位置 (1~11): ");
    scanf("%d", &position);
    printf("請輸入新節點的數值: ");
    scanf("%d", &newData);

    insertNode(position, newData);  
	// 傳遞位置和新數據給 insertNode

    printf("插入後的鏈結串列: ");
    printList();

    freeList();  // 釋放記憶體
    return 0;
}

