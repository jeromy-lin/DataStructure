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
    int delete_index;

    // 顯示原始陣列
    printf("Original array:\n");
    printArray(array, size);

    // 請同學選擇要刪除的索引
    printf("Enter the index (0-9) to delete the value: ");
    scanf("%d", &delete_index);

    // 檢查索引範圍
    if (delete_index < 0 || delete_index >= size) {
        printf("Invalid index! Please enter a valid index.\n");
        return 1;  // 結束程式
    }

    // 移動元素，覆蓋要刪除的元素
    for (int move_index = delete_index; move_index < size - 1; move_index++) {
        array[move_index] = array[move_index + 1];
    }

    size--;  // 更新陣列大小

    // 顯示刪除後的陣列
    printf("Array after deletion:\n");
    printArray(array, size);

    return 0;
}

