/*
	資料結構範例   
	第六章 : Sort 
	範例 3 : 插入排序
	以固定陣列進行插入排序法		
*/

#include <stdio.h>  

int main() {
    int arr[] = {3, 7, 1, 6, 8};   
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, key; // key 是暫存要插入的數值

    printf("排序前的陣列  :");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // 插入排序開始：從第2個元素( index == 1)開始排序
    for (i = 1; i < n; i++) {
        key = arr[i];       // 把目前這個元素存起來
        j = i - 1;          // 從前一個已排序元素開始往前比較

        // 將比 key 大的元素一一往後移動
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // 把較大的元素往後移動
            j--;                  // 繼續往前比較
        }

        // 插入 key 到正確的位置
        arr[j + 1] = key;

        // 顯示每一輪的排序結果
        printf("第 %d 輪排序後：", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    // 顯示最終排序結果
    printf("排序結果     ：");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

