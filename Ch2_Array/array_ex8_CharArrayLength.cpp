/*
	資料結構範例   
	第二章 : Array 
	範例 8 : 計算字元陣列的長度 
*/

#include <stdio.h>
// 計算字串長度的函數 (不使用 strlen)
int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != NULL){
        length++;
    }
    return length;
    //當字串不為空 累加length	
    //思考點 NULL 可替換?  
}

int main() {
    // 使用一維字元陣列 (可修改內容)
    char str1[] = "Hello World";
    // 使用 char 指標 (指向字串常數，內容不可修改)
    const char *str2 = "Joy of C Programming :)";

    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
    // 使用自訂函數計算字串長度
    printf("\nLength of str1: %d\n", my_strlen(str1));
    printf("Length of str2: %d\n", my_strlen(str2));

    return 0;
}

