#include <stdio.h>

// �w�q�[����
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int (*operation)(int, int);  // �ŧi�@�ӫ��V��Ӿ�Ƨ@���Ѽƨê�^��ƪ���ƫ���

    int x = 10, y = 5;
    
    // �ϥΫ��Ы��V��� add
    operation = add;
    printf("The sum of %d and %d is: %d\n", x, y, operation(x, y));  // �I�s add ���

    // �ϥΫ��Ы��V��� subtract
    operation = subtract;
    printf("The difference of %d and %d is: %d\n", x, y, operation(x, y));  // �I�s subtract ���

    return 0;
}

