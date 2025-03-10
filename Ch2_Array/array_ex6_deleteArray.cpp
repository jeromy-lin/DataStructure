#include <stdio.h>

void printArray(int array[], int size) {
    // �C�L�}�C�����Ҧ������H�Ψ����
    for (int index = 0; index < size; index++) {
        printf("Index: %d, Value: %d\n", index, array[index]);
    }
    printf("\n");
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // ��l��1��10���}�C
    int size = 10;  // ��e�}�C�j�p
    int delete_index;

    // ��ܭ�l�}�C
    printf("Original array:\n");
    printArray(array, size);

    // �ЦP�ǿ�ܭn�R��������
    printf("Enter the index (0-9) to delete the value: ");
    scanf("%d", &delete_index);

    // �ˬd���޽d��
    if (delete_index < 0 || delete_index >= size) {
        printf("Invalid index! Please enter a valid index.\n");
        return 1;  // �����{��
    }

    // ���ʤ����A�л\�n�R��������
    for (int move_index = delete_index; move_index < size - 1; move_index++) {
        array[move_index] = array[move_index + 1];
    }

    size--;  // ��s�}�C�j�p

    // ��ܧR���᪺�}�C
    printf("Array after deletion:\n");
    printArray(array, size);

    return 0;
}

