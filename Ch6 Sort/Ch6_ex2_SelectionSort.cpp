/*
	資料結構範例   
	第六章 : Sort 
	範例 2 : Selection Sort 選擇排序法 
*/

#include <stdio.h>

int main() {
    // 初始化陣列 arr，並計算元素個數 n
    int arr[] = {3, 7, 1, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, min_idx, temp;

    printf("Selection  Sort\n");

    // 顯示排序前的陣列
    printf("排序前的陣列 : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 外層迴圈控制每一輪選擇排序（要進行 n-1 輪）
    for (i = 0; i < n - 1; i++) {
        min_idx = i; // 假設目前的 i 為最小值的索引

        // 內層迴圈從 i+1 開始找出最小值
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // 更新最小值的位置
            }
        }

        // 如果找到的最小值不是自己，則與目前的 i 做交換
        if (min_idx != i) {
            temp = arr[i];              // 使用暫存變數 temp 儲存 arr[i]
            arr[i] = arr[min_idx];      // 將較小的值放設置於arr[i] 
            arr[min_idx] = temp;        // 將原來的值放到儲存於
			                            // 原來的最小值位置
        }

        // 顯示每一輪排序後的結果
        printf("第 %d 輪排序後：", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    // 顯示最終排序完成後的陣列
    printf("排序結果     ：");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

