/*
	資料結構範例   
	第二章 : Array 
	範例 9 : 兩字串串接 使用array 
*/
#include <stdio.h>

// 自訂函數：使用陣列手動串接兩個字串
void concat_strings(char result[], const char str1[], const char str2[]) {
    int i, j;

    // 複製 str1 到 result
    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = str1[i];
    }
    // 複製 str2 到 result（從 i 位置開始）
    for (j = 0; str2[j] != '\0'; j++, i++) {
        result[i] = str2[j];
    }
    result[i] = '\0'; // 確保字串結尾
}

int main() {
    char str1[] = "Hello World";  
    char str2[] = " Joy of C Programming :)";
    char result[100]; // 宣告足夠大的陣列來存放結果

    printf("Before concatenation:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n\n", str2);

    // 呼叫函數來串接字串
    concat_strings(result, str1, str2);

    printf("After concatenation:\n");
    printf("Concatenated String: %s\n", result);

    return 0;
}

