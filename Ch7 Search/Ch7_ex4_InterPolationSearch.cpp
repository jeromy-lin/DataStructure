/*
	��Ƶ��c�d��   
	�ĤC�� : Search 
	�d�� 4 : Interpolation Search �����j�M�k
		
*/

#include <stdio.h>

int interpolationSearch(int arr[], int size, int key) {
    int low = 0, high = size - 1; 
    while (low <= high && key >= arr[low] && key <= arr[high]) {       
        if (arr[high] == arr[low]) {
            if (arr[low] == key)
                return low; 
            else
                return -1;
        } 
        // ���Ȥ��� �ЦP�ǹ�����q���� Mid = low + (key - A[low])/(A[high] - A[low])*(high - low) 
        int mid = low + ((double)(key - arr[low]) / (arr[high] - arr[low])) * (high - low);
        printf("�w����m�G%d�A�Ȭ��G%d\n", mid, arr[mid]);

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; 
}

int main() {
    int data[] = {1, 3, 15, 27, 38, 44, 46, 50, 58, 100};
    int size = sizeof(data) / sizeof(data[0]);
    int key = 50;
    int result = interpolationSearch(data, size, key);

    if (result != -1)
        printf("��� %d�A�b���� %d�C\n", key, result);
    else
        printf("�䤣�� %d�C\n", key);

    return 0;
}


