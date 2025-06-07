/*
	��Ƶ��c�d��   
	�ĤC�� : Search 
	�d�� 1 : Sequential Search �`�Ƿj�M�k
	
*/

#include <stdio.h>

int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // ���ؼЭȡA�^��array index
        }
    }
    return -1; // ���j�M��ؼЭ� 
}

int main() {
    // �w�w�q�@���ư}�C
    int arr[] = {15, 23, 7, 89, 42, 55, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, index;

    printf("��l�}�C�G");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ��J�n�j�M���ؼЭ�
    printf("�п�J�n�j�M���ƭȡG");
    scanf("%d", &target);

    // ����`�Ƿj�M
    index = sequentialSearch(arr, size, target);

    // ��ܵ��G
    if (index != -1) {
        printf("���ƭ�: %d ��index: %d�C\n", target, index);
    } else {
        printf("�䤣��ƭ� %d�C\n", target);
    }

    return 0;
}



