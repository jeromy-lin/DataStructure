/*
	資料結構範例   
	第三章 : Linked List 
	範例 8 : 指標的位置練習 
*/


#include <stdio.h>
#include <stdlib.h>

// 定義鏈結串列的節點
typedef struct node {
    int data;          
    struct node* next; // 指向下一個節點的指標
} Node;

int main() {
    // 1: 宣告一個 int 指標變數，並指向一個 int 數值
    int value = 10;
//  int *ptr = &value; // ptr 指向變數 value 的記憶體位置
//	int* ptr = &value; // ptr 指向變數 value 的記憶體位置
    int * ptr = &value; // ptr 指向變數 value 的記憶體位置

    printf("Value: %d\n", value);
    printf("Pointer Address: %p\n", (void*)ptr);
    printf("Pointer Dereference: %d\n\n", *ptr);

    // 2: 建立鏈結串列
    Node* head = NULL; // 初始化鏈結串列為空

    // 3: 新增節點
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->data = 10;
    newNode1->next = head;
    head = newNode1;

    Node * newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->data = 20;
    newNode2->next = head;
    head = newNode2;

    Node *newNode3 = (Node*)malloc(sizeof(Node));
    newNode3->data = 30;
    newNode3->next = head;
    head = newNode3;

    // 4: 列印鏈結串列內容
    printf("Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

