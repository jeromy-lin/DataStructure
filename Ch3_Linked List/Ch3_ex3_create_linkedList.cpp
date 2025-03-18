/*
	資料結構範例   
	第三章 : Linked List 
	範例 3 : 宣告&建立一般型Linked List 
*/

#include <stdio.h>
#include <stdlib.h>

// 定義 Linked List 的節點
typedef struct Node {
    int data;
    struct Node* next;  
	// 自我參照指標的設計Self-Referential Pointer
} Node;
// 請同學務必熟記 Linked List宣告之C語言撰寫方式 

int main() {

    Node head1;
	head1.data = 10; //設定節點值
	head1.next = NULL; //節點指向Null 
    
	printf("節點資料 : %d\n",head1.data);

    return 0;
}

