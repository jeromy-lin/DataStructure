/*
	��Ƶ��c�d��   
	�ĤG�� : Array 
	�d�� 8 : �p��r���}�C������ 
*/

#include <stdio.h>
// �p��r����ת���� (���ϥ� strlen)
int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != NULL){
        length++;
    }
    return length;
    //��r�ꤣ���� �֥[length	
    //����I NULL �i����?  
}

int main() {
    // �ϥΤ@���r���}�C (�i�ק鷺�e)
    char str1[] = "Hello World";
    // �ϥ� char ���� (���V�r��`�ơA���e���i�ק�)
    const char *str2 = "Joy of C Programming :)";

    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
    // �ϥΦۭq��ƭp��r�����
    printf("\nLength of str1: %d\n", my_strlen(str1));
    printf("Length of str2: %d\n", my_strlen(str2));

    return 0;
}

