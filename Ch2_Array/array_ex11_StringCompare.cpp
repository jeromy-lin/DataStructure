/*
	��Ƶ��c�d��   
	�ĤG�� : Array 
	�d�� 11 : ��r��걵 ����æ^�ǵ��G 
*/

#include <stdio.h>

int main() {
    char str1[] = "Hello World Joy of C Programming :)";
    char str2[] = "Hello Student, Welcome of C Programming :)";
    int i = 0;

    // �ϥ� for �j��v�r�����Ӧr�� �Hindex 0���_�l�}�l��� 
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            printf("The strings are different at character %d.\n", i);
            break;
        }
        i++;
    }

    // �p�G�j�鵲���ɨS���o�{���P�A�h�r��ۦP
    if (str1[i] == '\0' && str2[i] == '\0') {
        printf("The strings are identical.\n");
    }

    return 0;
}

