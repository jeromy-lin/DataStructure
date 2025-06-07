/*
	資料結構範例   
	第七章 : Search 
	範例 1 : Sequential Search 循序搜尋法
	
*/

#include <stdio.h>

int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // 找到目標值，回傳array index
        }
    }
    return -1; // 未搜尋到目標值 
}

int main() {
    // 預定義一串整數陣列
    int arr[] = {15, 23, 7, 89, 42, 55, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, index;

    printf("原始陣列：");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 輸入要搜尋的目標值
    printf("請輸入要搜尋的數值：");
    scanf("%d", &target);

    // 執行循序搜尋
    index = sequentialSearch(arr, size, target);

    // 顯示結果
    if (index != -1) {
        printf("找到數值: %d 於index: %d。\n", target, index);
    } else {
        printf("找不到數值 %d。\n", target);
    }

    return 0;
}



