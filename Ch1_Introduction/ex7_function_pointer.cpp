#include <stdio.h>

// 定義加減的函數
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int (*operation)(int, int);  // 宣告一個指向兩個整數作為參數並返回整數的函數指標
     // 此為function pointer 標準撰寫方法 請同學熟記
    int x = 10, y = 5;
    
    // 使用指標指向函數 add
    operation = add;
    printf("The sum of %d and %d is: %d\n", x, y, operation(x, y));  // 呼叫 add 函數

    // 使用指標指向函數 subtract
    operation = subtract;
    printf("The difference of %d and %d is: %d\n", x, y, operation(x, y));  // 呼叫 subtract 函數

    return 0;
}

