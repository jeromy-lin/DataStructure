/*
	資料結構範例   
	第三章 : Linked List 
	範例 4 : 建立指標型 Linked List 
*/

#include <stdio.h>
#include <stdlib.h>
// 定義鏈結串列節點

typedef struct Node {
    int data;            // 儲存數據
    struct Node *next;   // 指向下一個節點的指標
} Node;
// Self-Referential Pointer自我參照指標的設計
 
int main() {

	// 使用 malloc 配置記憶體  
    Node *head1 = (Node *)malloc(sizeof(Node));
    if (head1 == NULL) {
        printf("記憶體分配失敗！\n");
        return 1;
    }

    head1->data = 10;  //  設定節點值
    head1->next = NULL; // 節點指向Null 

    printf("節點資料: %d\n", head1->data);
    // 釋放記憶體
    free(head1);    
    return 0;
}



