#include <stdio.h>  // Standard Input Output Header

int main() {
    const int SIZE = 10;  // �}�C�j�p
    int arr[SIZE];        // �ŧi�@���}�C

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i+1;  // array���Ȭ��p�ƾ��� 
    }

    // �C�L���ޡB�ƭȻP�O�����m
    printf("Index\tValue\tAddress\n");
    for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t%d\t%p\n", i, arr[i], &arr[i]); 
	}
    return 0;
}

