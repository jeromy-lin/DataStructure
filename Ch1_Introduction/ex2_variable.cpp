#include <stdio.h>  // 標準輸入輸出函式庫
#define PI 3.14159  // 定義常數（巨集）

int main() {
    // 1. 變數與資料型別
    int a = 10;
    float b = 3.14;
    char c = 'A';
    double d = 1.23456789;

    // 2. 輸出變數內容
    printf("整數: %d\n", a);
    printf("浮點數: %.2f\n", b);
    printf("字元: %c\n", c);
    printf("雙精度浮點數: %.8f\n", d);

    // 3. 輸入與輸出
    int num;
    printf("請輸入一個整數: ");
    scanf("%d", &num);
    printf("你輸入的數字是: %d\n", num);

    // 4. 運算子示範
    int x = 5, y = 2;
    printf("x + y = %d\n", x + y);  // 算術運算
    printf("x - y = %d\n", x - y);
    printf("x * y = %d\n", x * y);
    printf("x / y = %d\n", x / y);
    printf("x %% y = %d\n", x % y);  // 取餘數

    // 關係運算子
    printf("x > y? %d\n", x > y);   // 1（真）
    printf("x == y? %d\n", x == y); // 0（假）

    // 邏輯運算子
    printf("(x > 0 && y < 10)? %d\n", (x > 0 && y < 10)); // 1（真）

    // 位元運算子
    printf("x & y = %d\n", x & y); // 位元AND
    printf("x | y = %d\n", x | y); // 位元OR
    printf("x ^ y = %d\n", x ^ y); // 位元XOR
    printf("x << 1 = %d\n", x << 1); // 左移
    printf("x >> 1 = %d\n", x >> 1); // 右移

    return 0;
}

