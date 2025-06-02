/*
	資料結構範例   
	第六章 : Sort 
	範例 6 : Heap Sort Heap排序法 
	
*/

#include <stdio.h>
#include <math.h>

// 函數：交換元素
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 列印縮排函數 
void printSpaces(int count) {
    for (int i = 0; i < count; i++)
        printf(" ");
}

// 列印 Heap 的樹狀結構（遞迴）
void printHeapTree(int arr[], int n, int index, int indent) {
    if (index >= n) return;

    // 右子樹
    printHeapTree(arr, n, 2 * index + 2, indent + 6);

    // 當前節點
    printSpaces(indent);
    printf("%d\n", arr[index]);

    // 左子樹
    printHeapTree(arr, n, 2 * index + 1, indent + 6);
}

// 列印目前的 Heap 狀態
void showHeap(int arr[], int n, const char* message) {
    printf("\n%s\n", message);
    printHeapTree(arr, n, 0, 0);
    printf("\n");
}

// 維持最大堆 Max Heap Tree
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 堆積排序
void heapSort(int arr[], int n) {
    printf("\n[建立 Max Heap 過程]\n");
    for (int i = n / 2 - 1, step = 1; i >= 0; i--, step++) {
        heapify(arr, n, i);
        char msg[50];
        sprintf(msg, "Step %d: heapify(%d)", step, i);
        showHeap(arr, n, msg);
    }

    showHeap(arr, n, "建立 Max Heap 完成：");

    printf("\n[排序過程]\n");
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        printf("移動最大值 %d 到尾端（索引 %d）：\n", arr[i], i);
        heapify(arr, i, 0);

        char msg[50];
        sprintf(msg, "Heapify 之後（剩餘 %d 個元素）", i);
        showHeap(arr, i, msg);
    }
}


int main() {
    int arr[] = {45, 83, 7, 61, 12 , 99, 44, 77, 14, 29 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始陣列：");
    printArray(arr, n);

    showHeap(arr, n, "\n[原始樹狀結構]");

    heapSort(arr, n);

    printf("排序後陣列：");
    printArray(arr, n);

    return 0;
}


