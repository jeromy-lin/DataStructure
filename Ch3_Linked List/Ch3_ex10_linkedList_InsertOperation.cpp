/*
    資料結構範例   
    第三章 : Linked List 
    範例 10 : 節點建立插入範例 

*/

#include <stdio.h>
#include <stdlib.h>

// 定義鏈結串列節點結構
typedef struct Node {
    int data;          // 節點資料
    struct Node *next; // 指向下一個節點的指標
} Node;

// 計算鏈結串列長度
int getLength(Node *linkedList) {
    int length = 0;      // 初始化長度為 0
    
    
    Node *current = linkedList; // 從鏈結串列的頭節點開始
    while (current != NULL) {    // 當當前節點不為 NULL 時，繼續遍歷
        length++;            // 長度加 1
        current = current->next; // 移動到下一個節點
    }
    return length;  // 回傳鏈結串列的長度
}

// 新增節點到鏈結串列尾端
Node* appendNode(Node *linkedList, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // 動態分配新節點的記憶體
    if (newNode == NULL) { // 如果記憶體分配失敗
        printf("記憶體分配失敗！\n");
        return linkedList;  // 返回原鏈結串列
    }
    newNode->data = newData;    // 設置新節點的資料
    newNode->next = NULL;       // 新節點的 next 設為 NULL，表示它是鏈結串列的尾端

    if (linkedList == NULL) {    // 如果鏈結串列為空
        return newNode;          // 返回新節點，成為唯一的節點
    }

    Node *current = linkedList;  // 從頭節點開始遍歷
    while (current->next != NULL) {  // 找到尾端節點
        current = current->next;  // 移動到下一個節點
    }
    current->next = newNode;   // 將尾端節點的 next 指向新節點
    return linkedList;          // 返回更新後的鏈結串列
}

// 在指定位置插入新節點
Node* insertNode(Node *linkedList, int position, int newData) {
    int length = getLength(linkedList);   // 獲取鏈結串列的長度
    Node *newNode = (Node *)malloc(sizeof(Node)); // 動態分配新節點的記憶體
    if (newNode == NULL) { // 如果記憶體分配失敗
        printf("記憶體分配失敗！\n");
        return linkedList;  // 返回原鏈結串列
    }
    newNode->data = newData;   // 設置新節點的資料
    newNode->next = NULL;      // 新節點的 next 設為 NULL，預設為尾端

    // 插入到頭部
    if (position == 1) {
        newNode->next = linkedList; // 新節點的 next 指向原來的頭節點
        return newNode;             // 返回新節點，成為新的頭節點
    }

    // 插入到尾部或中間
    Node *current = linkedList;  // 從頭節點開始遍歷
    for (int i = 1; i < position - 1 && current->next != NULL; i++) { 
        current = current->next;  // 遍歷到指定位置的前一個節點
    }
    newNode->next = current->next;  // 新節點的 next 指向當前節點的 next
    current->next = newNode;        // 當前節點的 next 指向新節點
    return linkedList;              // 返回更新後的鏈結串列
}

// 顯示鏈結串列內容
void printList(Node *linkedList) {
    Node *current = linkedList;  // 從頭節點開始遍歷
    while (current != NULL) {    // 當當前節點不為 NULL 時，繼續遍歷
        printf("%d -> ", current->data); // 顯示當前節點的資料
        current = current->next; // 移動到下一個節點
    }
    printf("NULL\n");  // 輸出結尾 NULL 表示鏈結串列的結束
}

// 釋放記憶體
void freeList(Node *linkedList) {
    Node *current;       // 用來遍歷鏈結串列的指標
    while (linkedList != NULL) {  // 當鏈結串列不為空時
        current = linkedList;    // 當前節點
        linkedList = linkedList->next; // 移動到下一個節點
        free(current);  // 釋放當前節點的記憶體
    }
}

int main() {
    // 宣告一個初始化空的鏈結串列, 此為Node結構指標變數型別宣告
    Node *linkedList = NULL;  

    // 新增 1 到  5 節點到鏈結串列
    for (int i = 1; i <= 5; i++) {
        linkedList = appendNode(linkedList, i);  
        // 呼叫 appendNode 函數新增linkedList節點
        // 請同學注意"回傳值"的與函數名稱之對應
        // Node* appendNode(Node *linkedList, int newData)
    }

    printf("原始鏈結串列: ");
    printList(linkedList);  // 顯示原始的鏈結串列

    int position, newData;
    printf("請輸入要插入的位置 (1~6): ");
    scanf("%d", &position);  // 讀取插入位置
    printf("請輸入新節點的數值: ");
    scanf("%d", &newData);   // 讀取新節點的資料

    linkedList = insertNode(linkedList, position, newData); 
    
	/*上述範例 為linked list 以及指標變數寫入的重要觀念
	 
	呼叫 insertNode 插入新節點
    輸入為指標變數的"address" 回傳也是要對照之型別
     回傳為更新後的鏈結串列的"address位址"
     因此函數必須要以相同的型別來宣告
    Node* insertNode(Node *linkedList, int position, int newData)
    linkedList 只是「原始指標的拷貝」  
	
	*/
    
    printf("插入後的鏈結串列: ");
    printList(linkedList);  // 顯示插入後的鏈結串列

    freeList(linkedList);  // 釋放鏈結串列所佔的記憶體
    return 0;
}

