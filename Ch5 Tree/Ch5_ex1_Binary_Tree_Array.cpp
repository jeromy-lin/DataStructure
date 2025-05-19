/*
	資料結構範例   
	第五章 : Tree 
	範例 1 : 以 Array 設計二元樹 
	輸入數值 N, 產生對應的二元樹
	請注意第[0]元素不使用 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printTree(int *A, int n) {
    int levels = 0;
    int temp = n;

    // 計算總層數
    while (temp > 0) {
        temp /= 2;
        levels++;
    }

    int maxWidth = (1 << levels) * 2; // 樹的最大寬度，用來排版

    printf("\n樹的結構：\n");

    int idx = 1; // A的索引從1開始
    for (int l = 0; l < levels; l++) {
        int nodesInLevel = 1 << l; // 第 l 層有 2^l 個節點
        int spaceBetween = maxWidth / nodesInLevel; // 每個節點間隔

        // 印前面的空格，讓最左邊的節點置中
        for (int s = 0; s < spaceBetween / 2; s++) {
            printf(" ");
        }

        for (int j = 0; j < nodesInLevel && idx <= n; j++) {
            printf("%2d", A[idx]); // 印兩格寬的數字（對齊）
            idx++;

            // 每個節點之後的空格
            for (int s = 0; s < spaceBetween - 2; s++) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("請輸入節點數量 n：");
    scanf("%d", &n);

    if (n <= 0) {
        printf("節點數量必須大於 0。\n");
        return 1;
    }

    int *A = (int *)malloc((n + 1) * sizeof(int)); // A[0] 不使用
    if (A == NULL) {
        printf("記憶體分配失敗。\n");
        return 1;
    }

    // 節點編號從1到n
    for (int i = 1; i <= n; i++) {
        A[i] = i;
    }

    printf("\n節點與其父節點的關係：\n");
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("節點 A[%d]=%d 是根節點，沒有父節點\n", i, A[i]);
        } else {
            printf("節點 A[%d]=%d 的父節點是 A[%d]=%d\n", i, A[i], i/2, A[i/2]);
        }
    }

    printTree(A, n);

    free(A);
    return 0;
}

