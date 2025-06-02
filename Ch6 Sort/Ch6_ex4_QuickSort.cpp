/*
	資料結構範例   
	第六章 : Sort 
	範例 4 : Quick Sort 快速排序法（Non-in Place）

	Note : 本範例以「第一個元素」作為 pivot，
	並依講義內容以額外陣列儲存左右兩部分再合併，
	參考講義為分割與合併的步驟(Divide and Conquer)
	
*/

#include <stdio.h>
#include <stdlib.h>

// 顯示陣列
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Non-in Place快速排序主函數（以第一個元素為 pivot）
void quickSort(int arr[], int n) {
    if (n <= 1) return,; // 基底條件：1 個或 0 個元素
    int pivot = arr[0]; // 使用第一個元素當 pivot

    // 動態配置左右子陣列空間,  請同學可以學習此設計技巧 
    int* left = (int*)malloc(n * sizeof(int));
    int* right = (int*)malloc(n * sizeof(int));
    int leftCount = 0, rightCount = 0;
 
    for (int i = 1; i < n; i++) {     // 分割：從第 1 個元素開始
        if (arr[i] <= pivot)
            left[leftCount++] = arr[i];
        else
            right[rightCount++] = arr[i];
    }
    printf("Pivot = %d：", pivot);  // 顯示本次分割結果
    for (int i = 0; i < leftCount; i++) printf("%d ", left[i]);
    printf("| %d | ", pivot);
    for (int i = 0; i < rightCount; i++) printf("%d ", right[i]);
    printf("\n");

    quickSort(left, leftCount);       // 遞迴排序左右子陣列     
    quickSort(right, rightCount);     
    
    int index = 0;
    for (int i = 0; i < leftCount; i++) // 合併結果回原陣列 
        arr[index++] = left[i];
    arr[index++] = pivot;  
    for (int i = 0; i < rightCount; i++)
        arr[index++] = right[i];
    
    free(left);   // 釋放動態記憶體 
    free(right);  // 釋放動態記憶體  
}

int main() {
    int arr[] = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始陣列：");
    printArray(arr, n);

    quickSort(arr, n); 
	// 遞迴Quick排序 , 傳遞arr index 

    printf("排序後陣列：");
    printArray(arr, n);

    return 0;
}

	PS. Quick 撰寫上有諸多方式, 本範例為
	Non-in Place 的設計方法

