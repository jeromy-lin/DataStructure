/*
	��Ƶ��c�d��   
	�ĤG�� : Array 
	�d�� 8.1 : �Hstrlen�p��r���}�C������ 
*/

#include <stdio.h>
#include <string.h> // strlen �һݪ����Y��

int main() {
    // �ϥΤ@���r���}�C (�i�ק鷺�e)
    char str1[] = "Hello World";
    // �ϥ� char ���� (���V�r��`�ơA���e���i�ק�)
    const char *str2 = "Joy of C Programming :)";

    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
	printf("\n");
    // �p��r�����
    printf("Length of str1: %lu\n", strlen(str1));
    printf("Length of str2: %lu\n", strlen(str2));


    return 0;
}

