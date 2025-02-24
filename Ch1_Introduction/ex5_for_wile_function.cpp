#include <stdio.h>

// 副程式：計算兩個數字的總和
int add(int a, int b) {
    return a + b;
}

// 副程式：顯示訊息
void displayMessage(int count) {
    printf("這是第 %d 次顯示訊息\n", count);
}

int main() {
    int counter = 0;  // 計數器初始化
    int sum;

    // 使用 while 迴圈
    while (counter < 3) {
        displayMessage(counter + 1);  // 呼叫副程式顯示訊息
        counter++;
    }

    // 使用 do while 迴圈
    counter = 0;
    do {
        displayMessage(counter + 1);  // 呼叫副程式顯示訊息
        counter++;
    } while (counter < 2);

    // 呼叫 add 函式計算總和並顯示結果
    sum = add(5, 7);
    printf("5 + 7 的總和是: %d\n", sum);

    return 0;
}
