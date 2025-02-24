#include <stdio.h>

int main()
{
	
	printf("Hello, World!\n"); // 輸出字串
	printf("Integer：%d，Float：%.2f\n", 10, 3.14);
	
	int num;
	scanf("%d", &num); // 讀取整數，必須使用 `&` 取得變數位址	
		
	return 0;	
}



