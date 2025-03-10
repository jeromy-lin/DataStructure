#include <stdio.h>
#include <stdlib.h>  //malloc 和 realloc 函數

void printArray(int array[], int size) {
    // 列印陣列中的所有元素以及其索引
    for (int index = 0; index < size; index++) {
        printf("Index: %d, Value: %d\n", index, array[index]);
    }
    printf("\n");
}

int main() {
    int *array = (int *)malloc(10 * sizeof(int));  // 初始陣列大小為10
    int size = 10;  // 當前陣列大小
    int input_value, insert_index;
    char continue_insert;

    // 初始化陣列
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    // 顯示原始陣列
    printf("Original array:\n");
    printArray(array, size);

    // 讓同學可以不斷插入數值
    do {
        // 提示同學輸入一個數值範圍1~100
        printf("Enter a value (1-100) to insert into the array: ");
        scanf("%d", &input_value);

        // 檢查輸入是否在有效範圍內
        if (input_value < 1 || input_value > 100) {
            printf("Invalid input! Please enter a number between 1 and 100.\n");
            continue;  // 如果輸入無效，繼續讓同學重新輸入
        }

        // 請同學選擇插入位置
        printf("Enter the index (0-%d) to insert the value: ", size);
        scanf("%d", &insert_index);

        // 檢查索引範圍
        if (insert_index < 0 || insert_index > size) {
            printf("Invalid index! Please enter a valid index.\n");
            continue;  // 如果索引無效，繼續讓同學重新輸入
        }

        // 使用 realloc 重新分配記憶體，為陣列增加一個位置
        array = (int *)realloc(array, (size + 1) * sizeof(int));

        // 移動元素，為新元素騰出空間
        for (int move_index = size; move_index > insert_index; move_index--) {
            array[move_index] = array[move_index - 1];
        }

        // 插入新元素
        array[insert_index] = input_value;
        size++;  // 更新陣列大小

        // 顯示插入後的陣列
        printf("Array after insertion:\n");
        printArray(array, size);

        // 詢問是否繼續插入
        printf("Do you want to insert another value? (y/n): ");
        scanf(" %c", &continue_insert);  // 使用空白字符來清除前面的緩衝區

    } while (continue_insert == 'y' || continue_insert == 'Y');  // 同學輸入y或Y時繼續

    // 釋放記憶體
    free(array);

    return 0;
}

