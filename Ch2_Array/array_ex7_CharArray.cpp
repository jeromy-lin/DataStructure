/*
	��Ƶ��c�d��   
	�ĤG�� : Array 
	�d�� 7 : �Hchar�H��char* �ܼƫإߦr��}�C 
*/

#include <stdio.h>

int main() {
    // �ϥΤ@���r���}�C (�i�ק鷺�e)
    char str1[] = "Hello World";
    // �ϥ�char���� (���V�r��`�ơA���e���i�ק�)
    const char *str2 = "Joy of C Programming :)";
	// �ЦP�ǫ�ҥX�{ warring ��] 
   
    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
 
    str1[0] = 'h'; //���str1���Ĥ@�Ӧr�� 
	printf("\nstr1 : %s\n", str1); // �ܦ� "hello World"

    return 0;
}

 	// str2[0] = 'j'; //�ЦP�ǹ��խק� 
	// �ë�ҿ��~��]. �]�������V���O�r��`��
    // str2[0] = 'j'; // �o�|�ɭP���w�q�欰 (�{���i��Y��)

