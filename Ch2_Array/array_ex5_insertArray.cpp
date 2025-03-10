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
    int input_value, insert_index;

    // ��ܭ�l�}�C
    printf("Original array:\n");
    printArray(array, size);
    // ���ܦP�ǿ�J�@�ӼƭȽd��1~100
    printf("Enter a value (1-100) to insert into the array: ");
    scanf("%d", &input_value);

    // �ˬd��J�O�_�b���Ľd��
    if (input_value < 1 || input_value > 100) {
        printf("Invalid input! Please enter a number between 1 and 100.\n");
        return 1;  // �����{��
    }

    // �ЦP�ǿ�ܴ��J��m
    printf("Enter the index (0-10) to insert the value: ");
    scanf("%d", &insert_index);

    // �ˬd���޽d��
    if (insert_index < 0 || insert_index > size) {
        printf("Invalid index! Please enter a valid index.\n");
        return 1;  // �����{��
    }
    // ���ʭ�Ӫ�array�����A���s�����˥X�Ŷ�
    for (int move_index = size; move_index > insert_index; move_index--) {
        array[move_index] = array[move_index - 1];
    }

    // ���J�s����
    array[insert_index] = input_value;
    size++;  // ��s�}�C�j�p

    // ��ܴ��J�᪺�}�C
    printf("Array after insertion:\n");
    printArray(array, size);
    return 0;
}

