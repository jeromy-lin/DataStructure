/*
	資料結構範例   
	第二章 : Array 
	範例 11 : 兩字串串接 比較並回傳結果 
*/

#include <stdio.h>

int main() {
    char str1[] = "Hello World Joy of C Programming :)";
    char str2[] = "Hello Student, Welcome of C Programming :)";
    int i = 0;

    // 使用 for 迴圈逐字比較兩個字串 以index 0為起始開始比較 
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            printf("The strings are different at character %d.\n", i);
            break;
        }
        i++;
    }

    // 如果迴圈結束時沒有發現不同，則字串相同
    if (str1[i] == '\0' && str2[i] == '\0') {
        printf("The strings are identical.\n");
    }

    return 0;
}

