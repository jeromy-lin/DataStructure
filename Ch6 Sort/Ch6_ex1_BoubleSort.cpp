/*
	��Ƶ��c�d��   
	�Ĥ��� : Sort 
	�d�� 1 : ��w�ƧǪk 
	�H�T�w�}�C�i���w�ƧǪk		
*/

#include <stdio.h>

int main() {
    int arr[] = {3, 7, 1, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp;
    
	printf("Bubble Sort\n");
    printf("�Ƨǫe���}�C: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // ��w�Ƨ�
    for (int i = 0; i < n - 1; i++) {
        // �C�@���|��̤j���Ʀr����̥k��
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Bubble Sort ��z : �V�w�w�@�˯B�W�� 
				// �Y�n�i��洫�A�ݳz�L�@�ӥt�~�]�m���Ȧs�Ŷ��A
				// ���N�j����Ʃ�J�Ȧs
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // ��ܱƧǵ��G
    printf("\n�Ƨǫ᪺�}�C: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

