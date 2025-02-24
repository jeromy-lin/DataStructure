#include <stdio.h>
 
int main()
{ 
    int x;            /* 宣告一個的整數變數 */
    int *ptr;         /* 宣告一個指向整數的指標變數 
	//("*ptr" 是整數型別，因此 ptr 必須是一個指向整數的指標) */
 
    ptr = &x;         /* 賦值：將 x 的位址賦給 ptr */
    printf("Please enter a number: ");
    scanf( "%d", &x );  /* 輸入數值，將其存入 x，可以使用 ptr 來代替 &x */
    printf( "*ptr : %d\n", *ptr );   /* 使用 *ptr 來解引用，獲取 ptr 指向的值，也就是 x 的值 */
    printf( "&ptr : %d\n", &ptr );  /* 使用 &獲取 ptr 的記憶體位址 */ 
    printf( "ptr  : %d\n",  ptr );   /* 使用 獲取 ptr 的存放的值 */ 
    printf( "&x   : %d\n",  &x ); /* 使用 &x ，獲取 x 的記憶體位址 */
    printf( "x    : %d\n",  x );   /* 使用 x ，獲取 x 的變數值 */
    getchar(); /* 等待使用者按下 Enter 鍵 */

}




