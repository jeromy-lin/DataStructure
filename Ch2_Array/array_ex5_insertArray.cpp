#include <stdio.h>

void printArray(int array[], int size) {
    // 列印陣列中的所有元素以及其索引
    for (int index = 0; index < size; index++) {
        printf("Index: %d, Value: %d\n", index, array[index]);
    }
    printf("\n");
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // 初始的1到10的陣列
    int size = 10;  // 當前陣列大小
    int input_value, insert_index;

    // 顯示原始陣列
    printf("Original array:\n");
    printArray(array, size);
    // 提示同學輸入一個數值範圍1~100
    printf("Enter a value (1-100) to insert into the array: ");
    scanf("%d", &input_value);

    // 檢查輸入是否在有效範圍內
    if (input_value < 1 || input_value > 100) {
        printf("Invalid input! Please enter a number between 1 and 100.\n");
        return 1;  // 結束程式
    }

    // 請同學選擇插入位置
    printf("Enter the index (0-10) to insert the value: ");
    scanf("%d", &insert_index);

    // 檢查索引範圍
    if (insert_index < 0 || insert_index > size) {
        printf("Invalid index! Please enter a valid index.\n");
        return 1;  // 結束程式
    }
    // 移動原來的array元素，為新元素騰出空間
    for (int move_index = size; move_index > insert_index; move_index--) {
        array[move_index] = array[move_index - 1];
    }

    // 插入新元素
    array[insert_index] = input_value;
    size++;  // 更新陣列大小

    // 顯示插入後的陣列
    printf("Array after insertion:\n");
    printArray(array, size);
    return 0;
}

