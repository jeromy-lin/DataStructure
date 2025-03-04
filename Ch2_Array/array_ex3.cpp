#include <stdio.h>
int main() {
    // 宣告並初始化 2D 陣列 請同學記住row and column之定義
	// 2D array [4] 為總row的數量 [5] 分別為其column之代表 
	   
    int Cards[4][5] = {
        {102, 207, 302, 401, 108},
        {105, 206, 312, 407, 211},
        {103, 204, 310, 405, 307},
        {113, 209, 309, 408, 406}
    };
    // 輸出每個索引值 (Index)、
	// 對應的陣列數值 (Value) 及其記憶體位置 (Address)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            // 輸出索引、數值和記憶體位置
            printf("Index: [%d][%d], Value: %d, Address: %p\n", 
                   i, j, Cards[i][j], (void*)&Cards[i][j]);
        }
    }
    return 0;
}

