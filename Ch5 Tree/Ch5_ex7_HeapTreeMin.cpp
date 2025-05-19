/*
    ��Ƶ��c�d��
    �Ĥ��� : Tree
    �d�� 7 : �H�T�w�}�C�إ̤߳p heap tree 
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 100
int heap_arr[MAX_HEAP_SIZE]; 
// �q index=1 �}�l�s�� heap ����, �ЦP�Ǫ`�Ntree�]�p��h 
int heap_size = 0;

//Heap Tree ���U�I�B�@ : heapify-down Min-Heap
void heapify_down(int idx) {
    int smallest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;
    // ��X�T�̤����̤p��
    if (left <= heap_size && heap_arr[left] < heap_arr[smallest]) {
        smallest = left;
    }
    if (right <= heap_size && heap_arr[right] < heap_arr[smallest]) {
        smallest = right;
    }
    // �Y�̤p�Ȥ��O�ثe�`�I�A�洫�û��j�U�I
    if (smallest != idx) {
        int tmp = heap_arr[idx];
        heap_arr[idx] = heap_arr[smallest];
        heap_arr[smallest] = tmp;
        heapify_down(smallest);
    }
}

// �ѭ�l�}�C�غcmin heap (bottom-up)
void build_min_heap(int seq[], int n) {
    heap_size = n;
    // �N seq �ƻs�� heap_arr[1..n]
    for (int i = 0; i < n; i++) {
        heap_arr[i+1] = seq[i];
    }
    // �q�̫�@��non leap node ���� heapify_down
    for (int i = heap_size / 2; i >= 1; i--) {
        heapify_down(i);
    }
}

// �C�L�l�}�C
void print_original_array(int seq[], int n) {
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n\n");
}

// �C�L heap array
void print_heap_array() {
    printf("Heap Array (index:value):\n");
    for (int i = 1; i <= heap_size; i++) {
        printf("[%d]=%d ", i, heap_arr[i]);
    }
    printf("\n\n");
}

// �H�𪬵��c���heap tree (���k�ᥪ)
void print_heap_tree(int idx, int depth) {
    if (idx > heap_size) return;
    // �L�k�l��
    print_heap_tree(2 * idx + 1, depth + 1);

    for (int i = 0; i < depth; i++) printf("    ");
    printf("%d\n", heap_arr[idx]);
    // �L���l��
    print_heap_tree(2 * idx, depth + 1);
}

int main() {
    int seq[] = {38, 78, 10, 65, 19, 86, 33, 72, 20};
    int n = sizeof(seq) / sizeof(seq[0]);

    // �C�L��l�}�C
    print_original_array(seq, n);
    // Bottom-up �غc�̤pheap 
    build_min_heap(seq, n);
    // �C�Lheap�}�C
    print_heap_array();

    printf("Min-Heap Data Struct:\n");
    print_heap_tree(1, 0);

    return 0;
}

