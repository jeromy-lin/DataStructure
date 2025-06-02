/*
	��Ƶ��c�d��   
	�Ĥ��� : Sort 
	�d�� 2 : Selection Sort ��ܱƧǪk 
*/

#include <stdio.h>

int main() {
    // ��l�ư}�C arr�A�íp�⤸���Ӽ� n
    int arr[] = {3, 7, 1, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, min_idx, temp;

    printf("Selection  Sort\n");

    // ��ܱƧǫe���}�C
    printf("�Ƨǫe���}�C : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // �~�h�j�鱱��C�@����ܱƧǡ]�n�i�� n-1 ���^
    for (i = 0; i < n - 1; i++) {
        min_idx = i; // ���]�ثe�� i ���̤p�Ȫ�����

        // ���h�j��q i+1 �}�l��X�̤p��
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // ��s�̤p�Ȫ���m
            }
        }

        // �p�G��쪺�̤p�Ȥ��O�ۤv�A�h�P�ثe�� i ���洫
        if (min_idx != i) {
            temp = arr[i];              // �ϥμȦs�ܼ� temp �x�s arr[i]
            arr[i] = arr[min_idx];      // �N���p���ȩ�]�m��arr[i] 
            arr[min_idx] = temp;        // �N��Ӫ��ȩ���x�s��
			                            // ��Ӫ��̤p�Ȧ�m
        }

        // ��ܨC�@���Ƨǫ᪺���G
        printf("�� %d ���Ƨǫ�G", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    // ��̲ܳױƧǧ����᪺�}�C
    printf("�Ƨǵ��G     �G");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

