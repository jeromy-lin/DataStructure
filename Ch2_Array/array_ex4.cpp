#include <stdio.h>

int main() {
    // 宣告並初始化 2D 陣列 請同學記住 row , column的定義 
    int Cards[4][5] = {
        {102, 207, 302, 401, 108},
        {105, 206, 312, 407, 211},
        {103, 204, 310, 405, 307},
        {113, 209, 309, 408, 406}
    };

    // 列印 2D 陣列
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", Cards[i][j]);
            printf("%d ,", *(*(Cards + i) + j)); 
        }
        printf("\n"); // 換行顯示每一列
        //請同學對照1D array pointer寫法 
    }
    return 0;
}

