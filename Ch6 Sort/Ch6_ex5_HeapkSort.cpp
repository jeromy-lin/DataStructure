/*
	��Ƶ��c�d��   
	�Ĥ��� : Sort 
	�d�� 6 : Heap Sort Heap�ƧǪk 
	
*/

#include <stdio.h>
#include <math.h>

// ��ơG�洫����
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �C�L�Y�ƨ�� 
void printSpaces(int count) {
    for (int i = 0; i < count; i++)
        printf(" ");
}

// �C�L Heap ���𪬵��c�]���j�^
void printHeapTree(int arr[], int n, int index, int indent) {
    if (index >= n) return;

    // �k�l��
    printHeapTree(arr, n, 2 * index + 2, indent + 6);

    // ��e�`�I
    printSpaces(indent);
    printf("%d\n", arr[index]);

    // ���l��
    printHeapTree(arr, n, 2 * index + 1, indent + 6);
}

// �C�L�ثe�� Heap ���A
void showHeap(int arr[], int n, const char* message) {
    printf("\n%s\n", message);
    printHeapTree(arr, n, 0, 0);
    printf("\n");
}

// �����̤j�� Max Heap Tree
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ��n�Ƨ�
void heapSort(int arr[], int n) {
    printf("\n[�إ� Max Heap �L�{]\n");
    for (int i = n / 2 - 1, step = 1; i >= 0; i--, step++) {
        heapify(arr, n, i);
        char msg[50];
        sprintf(msg, "Step %d: heapify(%d)", step, i);
        showHeap(arr, n, msg);
    }

    showHeap(arr, n, "�إ� Max Heap �����G");

    printf("\n[�ƧǹL�{]\n");
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        printf("���ʳ̤j�� %d ����ݡ]���� %d�^�G\n", arr[i], i);
        heapify(arr, i, 0);

        char msg[50];
        sprintf(msg, "Heapify ����]�Ѿl %d �Ӥ����^", i);
        showHeap(arr, i, msg);
    }
}


int main() {
    int arr[] = {45, 83, 7, 61, 12 , 99, 44, 77, 14, 29 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("��l�}�C�G");
    printArray(arr, n);

    showHeap(arr, n, "\n[��l�𪬵��c]");

    heapSort(arr, n);

    printf("�Ƨǫ�}�C�G");
    printArray(arr, n);

    return 0;
}


