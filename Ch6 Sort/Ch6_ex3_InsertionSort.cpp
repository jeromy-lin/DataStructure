/*
	��Ƶ��c�d��   
	�Ĥ��� : Sort 
	�d�� 3 : ���J�Ƨ�
	�H�T�w�}�C�i�洡�J�ƧǪk		
*/

#include <stdio.h>  

int main() {
    int arr[] = {3, 7, 1, 6, 8};   
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, key; // key �O�Ȧs�n���J���ƭ�

    printf("�Ƨǫe���}�C  :");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // ���J�ƧǶ}�l�G�q��2�Ӥ���( index == 1)�}�l�Ƨ�
    for (i = 1; i < n; i++) {
        key = arr[i];       // ��ثe�o�Ӥ����s�_��
        j = i - 1;          // �q�e�@�Ӥw�ƧǤ����}�l���e���

        // �N�� key �j�������@�@���Ჾ��
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // ����j���������Ჾ��
            j--;                  // �~�򩹫e���
        }

        // ���J key �쥿�T����m
        arr[j + 1] = key;

        // ��ܨC�@�����Ƨǵ��G
        printf("�� %d ���Ƨǫ�G", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    // ��̲ܳױƧǵ��G
    printf("�Ƨǵ��G     �G");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

