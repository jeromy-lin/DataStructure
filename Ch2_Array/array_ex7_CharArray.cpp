/*
	資料結構範例   
	第二章 : Array 
	範例 7 : 以char以及char* 變數建立字串陣列 
*/

#include <stdio.h>

int main() {
    // 使用一維字元陣列 (可修改內容)
    char str1[] = "Hello World";
    // 使用char指標 (指向字串常數，內容不可修改)
    const char *str2 = "Joy of C Programming :)";
	// 請同學思考出現 warring 原因 
   
    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
 
    str1[0] = 'h'; //更改str1的第一個字元 
	printf("\nstr1 : %s\n", str1); // 變成 "hello World"

    return 0;
}

 	// str2[0] = 'j'; //請同學嘗試修改 
	// 並思考錯誤原因. 因為它指向的是字串常數
    // str2[0] = 'j'; // 這會導致未定義行為 (程式可能崩潰)

