#include <stdio.h>

int main() {
    int sum = 0;  // 儲存 1 到 100 的總和

    // 使用 for 迴圈計算 1 到 100 的總和
    for (int i = 1; i <= 100; i++) {
        sum += i;
        if (sum >= 50) {  // 當總和達到或超過 50 時跳出迴圈
            printf("總和達到 50，跳出迴圈。當前總和為: %d\n", sum);
            break;  // 跳出迴圈
        }
    }

    // 使用 for 迴圈輸出 1 到 10
    printf("1 到 10 的數字為: ");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}

