#include <stdio.h>  // Standard Input Output Header

int main() {
    const int SIZE = 10;  // 陣列大小
    int arr[SIZE];        // 宣告一維陣列

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i+1;  // array的值為計數器值 
    }

    // 列印索引、數值與記憶體位置
    printf("Index\tValue\tAddress\n");
    for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t%d\t%p\n", i, arr[i], &arr[i]); 
	}
    return 0;
}

