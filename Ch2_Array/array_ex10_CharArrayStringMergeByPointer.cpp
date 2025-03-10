/*
	��Ƶ��c�d��   
	�ĤG�� : Array 
	�d�� 10 : ��r��걵 �ϥ�array + char * 
*/

#include <stdio.h>

// �ۭq��ơG�ϥΫ��жǻ��Ӧ걵��Ӧr��
void concat_strings(char *result, const char str1[], const char *str2) {
    int i, j;
    // �ƻs str1 �� result
    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = str1[i];
    }

    // �ƻs str2 �� result�]�q i ��m�}�l�^
    //for (j = 0; str2[j] != '\0'; j++, i++) {
    //    result[i] = str2[j];
   // }

    // �ƻs str2 �� result�]�q i ��m�}�l�^�ϥΫ���*
    for (j = 0; *(str2 + j) != '\0'; j++, i++) {
        result[i] = *(str2 + j);  // �� *str2 �s���r��
    }
    result[i] = '\0'; // �T�O�r�굲��
}

int main() {
    char str1[] = "Hello World";  
    const char *str2 = " Joy of C Programming :)";
    char result[100]; // �ŧi�����j���}�C�Ӧs�񵲪G

    printf("Before concatenation:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n\n", str2);

    // �I�s��ƨӦ걵�r��
    concat_strings(result, str1, str2);

    printf("After concatenation:\n");
    printf("Concatenated String: %s\n", result);

    return 0;
}


