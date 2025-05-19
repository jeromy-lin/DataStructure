/*
    資料結構範例
    第五章 : Tree
    範例 7 : 以固定陣列建立最小 heap tree 
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 100
int heap_arr[MAX_HEAP_SIZE]; 
// 從 index=1 開始存放 heap 元素, 請同學注意tree設計原則 
int heap_size = 0;

//Heap Tree 的下沉運作 : heapify-down Min-Heap
void heapify_down(int idx) {
    int smallest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;
    // 找出三者中的最小值
    if (left <= heap_size && heap_arr[left] < heap_arr[smallest]) {
        smallest = left;
    }
    if (right <= heap_size && heap_arr[right] < heap_arr[smallest]) {
        smallest = right;
    }
    // 若最小值不是目前節點，交換並遞迴下沉
    if (smallest != idx) {
        int tmp = heap_arr[idx];
        heap_arr[idx] = heap_arr[smallest];
        heap_arr[smallest] = tmp;
        heapify_down(smallest);
    }
}

// 由原始陣列建構min heap (bottom-up)
void build_min_heap(int seq[], int n) {
    heap_size = n;
    // 將 seq 複製到 heap_arr[1..n]
    for (int i = 0; i < n; i++) {
        heap_arr[i+1] = seq[i];
    }
    // 從最後一個non leap node 執行 heapify_down
    for (int i = heap_size / 2; i >= 1; i--) {
        heapify_down(i);
    }
}

// 列印始陣列
void print_original_array(int seq[], int n) {
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n\n");
}

// 列印 heap array
void print_heap_array() {
    printf("Heap Array (index:value):\n");
    for (int i = 1; i <= heap_size; i++) {
        printf("[%d]=%d ", i, heap_arr[i]);
    }
    printf("\n\n");
}

// 以樹狀結構顯示heap tree (先右後左)
void print_heap_tree(int idx, int depth) {
    if (idx > heap_size) return;
    // 印右子樹
    print_heap_tree(2 * idx + 1, depth + 1);

    for (int i = 0; i < depth; i++) printf("    ");
    printf("%d\n", heap_arr[idx]);
    // 印左子樹
    print_heap_tree(2 * idx, depth + 1);
}

int main() {
    int seq[] = {38, 78, 10, 65, 19, 86, 33, 72, 20};
    int n = sizeof(seq) / sizeof(seq[0]);

    // 列印原始陣列
    print_original_array(seq, n);
    // Bottom-up 建構最小heap 
    build_min_heap(seq, n);
    // 列印heap陣列
    print_heap_array();

    printf("Min-Heap Data Struct:\n");
    print_heap_tree(1, 0);

    return 0;
}

