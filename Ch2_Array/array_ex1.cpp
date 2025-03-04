#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int SIZE = 10;  // 陣列大小
    int arr[SIZE];        // 宣告一維陣列
    srand(time(NULL));    // 設定亂數種子

    // 產生隨機數並填入陣列
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;  // 產生 0~99 的隨機數
    }

    // 列印索引、數值與記憶體位置
    printf("Index\tValue\tAddress\n");
    for (int i = 0; i < SIZE; i++)
	{
 
		printf("%d\t%d\t%p\n", i, arr[i], &arr[i]); 
		printf("%d\t%d\t%p\n", i, *(arr+i), (arr+i));
        // 請同學熟記上列寫法, 學習指標如何取用array索引     
		
		printf("\n");
        
    }

    return 0;
}

