#include <stdio.h>
#include <stdlib.h>  //malloc �M realloc ���

void printArray(int array[], int size) {
    // �C�L�}�C�����Ҧ������H�Ψ����
    for (int index = 0; index < size; index++) {
        printf("Index: %d, Value: %d\n", index, array[index]);
    }
    printf("\n");
}

int main() {
    int *array = (int *)malloc(10 * sizeof(int));  // ��l�}�C�j�p��10
    int size = 10;  // ��e�}�C�j�p
    int input_value, insert_index;
    char continue_insert;

    // ��l�ư}�C
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    // ��ܭ�l�}�C
    printf("Original array:\n");
    printArray(array, size);

    // ���P�ǥi�H���_���J�ƭ�
    do {
        // ���ܦP�ǿ�J�@�ӼƭȽd��1~100
        printf("Enter a value (1-100) to insert into the array: ");
        scanf("%d", &input_value);

        // �ˬd��J�O�_�b���Ľd��
        if (input_value < 1 || input_value > 100) {
            printf("Invalid input! Please enter a number between 1 and 100.\n");
            continue;  // �p�G��J�L�ġA�~�����P�ǭ��s��J
        }

        // �ЦP�ǿ�ܴ��J��m
        printf("Enter the index (0-%d) to insert the value: ", size);
        scanf("%d", &insert_index);

        // �ˬd���޽d��
        if (insert_index < 0 || insert_index > size) {
            printf("Invalid index! Please enter a valid index.\n");
            continue;  // �p�G���޵L�ġA�~�����P�ǭ��s��J
        }

        // �ϥ� realloc ���s���t�O����A���}�C�W�[�@�Ӧ�m
        array = (int *)realloc(array, (size + 1) * sizeof(int));

        // ���ʤ����A���s�����˥X�Ŷ�
        for (int move_index = size; move_index > insert_index; move_index--) {
            array[move_index] = array[move_index - 1];
        }

        // ���J�s����
        array[insert_index] = input_value;
        size++;  // ��s�}�C�j�p

        // ��ܴ��J�᪺�}�C
        printf("Array after insertion:\n");
        printArray(array, size);

        // �߰ݬO�_�~�򴡤J
        printf("Do you want to insert another value? (y/n): ");
        scanf(" %c", &continue_insert);  // �ϥΪťզr�ŨӲM���e�����w�İ�

    } while (continue_insert == 'y' || continue_insert == 'Y');  // �P�ǿ�Jy��Y���~��

    // ����O����
    free(array);

    return 0;
}

