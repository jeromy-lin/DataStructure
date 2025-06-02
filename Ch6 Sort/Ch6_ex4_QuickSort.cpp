/*
	��Ƶ��c�d��   
	�Ĥ��� : Sort 
	�d�� 4 : Quick Sort �ֳt�ƧǪk�]Non-in Place�^

	Note : ���d�ҥH�u�Ĥ@�Ӥ����v�@�� pivot�A
	�è����q���e�H�B�~�}�C�x�s���k�ⳡ���A�X�֡A
	�Ѧ����q�����λP�X�֪��B�J(Divide and Conquer)
	
*/

#include <stdio.h>
#include <stdlib.h>

// ��ܰ}�C
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Non-in Place�ֳt�ƧǥD��ơ]�H�Ĥ@�Ӥ����� pivot�^
void quickSort(int arr[], int n) {
    if (n <= 1) return,; // �򩳱���G1 �ө� 0 �Ӥ���
    int pivot = arr[0]; // �ϥβĤ@�Ӥ����� pivot

    // �ʺA�t�m���k�l�}�C�Ŷ�,  �ЦP�ǥi�H�ǲߦ��]�p�ޥ� 
    int* left = (int*)malloc(n * sizeof(int));
    int* right = (int*)malloc(n * sizeof(int));
    int leftCount = 0, rightCount = 0;
 
    for (int i = 1; i < n; i++) {     // ���ΡG�q�� 1 �Ӥ����}�l
        if (arr[i] <= pivot)
            left[leftCount++] = arr[i];
        else
            right[rightCount++] = arr[i];
    }
    printf("Pivot = %d�G", pivot);  // ��ܥ������ε��G
    for (int i = 0; i < leftCount; i++) printf("%d ", left[i]);
    printf("| %d | ", pivot);
    for (int i = 0; i < rightCount; i++) printf("%d ", right[i]);
    printf("\n");

    quickSort(left, leftCount);       // ���j�Ƨǥ��k�l�}�C     
    quickSort(right, rightCount);     
    
    int index = 0;
    for (int i = 0; i < leftCount; i++) // �X�ֵ��G�^��}�C 
        arr[index++] = left[i];
    arr[index++] = pivot;  
    for (int i = 0; i < rightCount; i++)
        arr[index++] = right[i];
    
    free(left);   // ����ʺA�O���� 
    free(right);  // ����ʺA�O����  
}

int main() {
    int arr[] = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("��l�}�C�G");
    printArray(arr, n);

    quickSort(arr, n); 
	// ���jQuick�Ƨ� , �ǻ�arr index 

    printf("�Ƨǫ�}�C�G");
    printArray(arr, n);

    return 0;
}

	PS. Quick ���g�W���Ѧh�覡, ���d�Ҭ�
	Non-in Place ���]�p��k

