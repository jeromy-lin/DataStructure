/*
	��Ƶ��c�d��   
	�ĤC�� : Search 
	�d�� 2 : �G���j�M�k (Binary Search)
	
*/

#include <stdio.h>
#include <stdlib.h> // �ϥ� qsort()��� 

// ����禡�A���� qsort �i�滼�W�Ƨ�, �Ъ`�Nconst void *...�O��ӡu�q�Ϋ��Сv�A
// �N�� qsort() �Ƕi�Ӫ���Ӱ}�C��������}
// �]���ڭ̥����n�ۤv�૬�����T�����O

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


// �G���j�M�k�禡, �b�w�ƧǪ���ư}�C����M���w�� target ��
int binarySearch(int arr[], int size, int target) {
    int left = 0;            // ����ɱq�� 0 �Ӥ����}�l
    int right = size - 1;    // �k��ɬ��̫�@�Ӥ���������

    while (left <= right) {  // ��j�M ���϶��٦��������P�w
        int mid = (left + right) / 2;     // ���o����index�]�H��ƪ����k�i��p��^ 

        if (arr[mid] == target) {         //�p�G�������ȴN�O�ؼЭȡA�^�ǥ������� 
            return mid; 
        } else if (arr[mid] < target) {   // �p�G�ؼЭȤ���j�A���k�b��j�M
            left = mid + 1;               // �Y�p�j�M�϶����k�b��]�ư� mid�^
        } else {                          // �p�G�ؼЭȤ���p�A�����b��j�M
            right = mid - 1;              // �Y�p�j�M�϶������b��]�ư� mid�^
        }
    }
    return -1; // �p�G�j�鵲�����䤣��ؼЭȡA�^�� -1 ��ܥ����
}

int main() {
    int arr[] = {8, 1, 99, 76, 88, 45, 15, 33, 24};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 88;

    // �ЦP�ǥi�H�Ѭ����qquick���ϥΤ�k
	// �ǻ�����,�����Ӽ�,�����j�p,�H��compare��� 
	 
    qsort(arr, size, sizeof(int), compare);

    // ��ܱƧǫ�}�C
    printf("�Ƨǫ�}�C�G");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ����G���j�M
    int index = binarySearch(arr, size, target);

    if (index != -1) {
        printf("���ؼЭ� : %d , �Ƨǫ᪺���� : %d�C\n", target, index);
    } else {
        printf("�䤣��ؼЭ� %d�C\n", target);
    }

    return 0;
}




