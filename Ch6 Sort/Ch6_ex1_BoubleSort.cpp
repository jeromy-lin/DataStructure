/*
	資料結構範例   
	第六章 : Sort 
	範例 1 : 氣泡排序法 
	以固定陣列進行氣泡排序法		
*/

#include <stdio.h>

int main() {
    int arr[] = {3, 7, 1, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp;
    
	printf("Bubble Sort\n");
    printf("排序前的陣列: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // 氣泡排序
    for (int i = 0; i < n - 1; i++) {
        // 每一輪會把最大的數字移到最右邊
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Bubble Sort 原理 : 向泡泡一樣浮上來 
				// 若要進行交換，需透過一個另外設置的暫存空間，
				// 先將大的資料放入暫存
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 顯示排序結果
    printf("\n排序後的陣列: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

