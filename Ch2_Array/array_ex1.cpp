#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int SIZE = 10;  // �}�C�j�p
    int arr[SIZE];        // �ŧi�@���}�C
    srand(time(NULL));    // �]�w�üƺؤl

    // �����H���ƨö�J�}�C
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;  // ���� 0~99 ���H����
    }

    // �C�L���ޡB�ƭȻP�O�����m
    printf("Index\tValue\tAddress\n");
    for (int i = 0; i < SIZE; i++)
	{
 
		printf("%d\t%d\t%p\n", i, arr[i], &arr[i]); 
		printf("%d\t%d\t%p\n", i, *(arr+i), (arr+i));
        // �ЦP�Ǽ��O�W�C�g�k, �ǲ߫��Цp�����array����     
		
		printf("\n");
        
    }

    return 0;
}

