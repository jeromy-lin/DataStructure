/*
	資料結構範例   
	第二章 : Array 
	範例 8.1 : 以strlen計算字元陣列的長度 
*/

#include <stdio.h>
#include <string.h> // strlen 所需的標頭檔

int main() {
    // 使用一維字元陣列 (可修改內容)
    char str1[] = "Hello World";
    // 使用 char 指標 (指向字串常數，內容不可修改)
    const char *str2 = "Joy of C Programming :)";

    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
	printf("\n");
    // 計算字串長度
    printf("Length of str1: %lu\n", strlen(str1));
    printf("Length of str2: %lu\n", strlen(str2));


    return 0;
}

