/*
	資料結構範例   
	第七章 : Search 
	範例 4 : Interpolation Search 內插搜尋法
		
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
        // 插值公式 請同學對照講義公式 Mid = low + (key - A[low])/(A[high] - A[low])*(high - low) 
        int mid = low + ((double)(key - arr[low]) / (arr[high] - arr[low])) * (high - low);
        printf("預測位置：%d，值為：%d\n", mid, arr[mid]);

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
        printf("找到 %d，在索引 %d。\n", key, result);
    else
        printf("找不到 %d。\n", key);

    return 0;
}


