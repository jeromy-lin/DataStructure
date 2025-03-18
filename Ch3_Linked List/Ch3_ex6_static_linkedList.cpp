/*
	資料結構範例   
	第三章 : Linked List 
	範例 6 : 建立static Linked List 
*/


#include <stdio.h>

#define SIZE 3  // 陣列大小 (節點數量)

// 定義 Linked List 的節點 (靜態陣列版本)
typedef struct {
    int data;
    int next;  // 用索引來模擬指標 (-1 代表 NULL)
} Node;

int main() {
    // 宣告一個陣列來存儲 Linked List
    Node list[SIZE];

    // 初始化節點
    list[0].data = 1;
    list[0].next = 1;  // 指向陣列中的索引 1 (第二個節點)

    list[1].data = 2;
    list[1].next = 2;  // 指向陣列中的索引 2 (第三個節點)

    list[2].data = 3;
    list[2].next = -1; // -1 代表 NULL (鏈結串列結尾)

        int index = 0;
    while (index != -1) {
        printf("%d -> ", list[index].data);
        index = list[index].next;
    }
    printf("NULL\n");

    return 0;
}

