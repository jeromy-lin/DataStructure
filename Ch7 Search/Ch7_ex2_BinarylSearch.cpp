/*
	資料結構範例   
	第七章 : Search 
	範例 2 : 二分搜尋法 (Binary Search)
	
*/

#include <stdio.h>
#include <stdlib.h> // 使用 qsort()函數 

// 比較函式，提供 qsort 進行遞增排序, 請注意const void *...是兩個「通用指標」，
// 代表 qsort() 傳進來的兩個陣列元素的位址
// 因此我們必須要自己轉型成正確的型別

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


// 二分搜尋法函式, 在已排序的整數陣列中找尋指定的 target 值
int binarySearch(int arr[], int size, int target) {
    int left = 0;            // 左邊界從第 0 個元素開始
    int right = size - 1;    // 右邊界為最後一個元素的索引

    while (left <= right) {  // 當搜尋 的區間還有元素的判定
        int mid = (left + right) / 2;     // 取得中間index（以整數的除法進行計算） 

        if (arr[mid] == target) {         //如果中間的值就是目標值，回傳它的索引 
            return mid; 
        } else if (arr[mid] < target) {   // 如果目標值比較大，往右半邊搜尋
            left = mid + 1;               // 縮小搜尋區間為右半邊（排除 mid）
        } else {                          // 如果目標值比較小，往左半邊搜尋
            right = mid - 1;              // 縮小搜尋區間為左半邊（排除 mid）
        }
    }
    return -1; // 如果迴圈結束仍找不到目標值，回傳 -1 表示未找到
}

int main() {
    int arr[] = {8, 1, 99, 76, 88, 45, 15, 33, 24};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 88;

    // 請同學可以參看講義quick的使用方法
	// 傳遞指標,元素個數,元素大小,以及compare函數 
	 
    qsort(arr, size, sizeof(int), compare);

    // 顯示排序後陣列
    printf("排序後陣列：");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 執行二分搜尋
    int index = binarySearch(arr, size, target);

    if (index != -1) {
        printf("找到目標值 : %d , 排序後的索引 : %d。\n", target, index);
    } else {
        printf("找不到目標值 %d。\n", target);
    }

    return 0;
}




