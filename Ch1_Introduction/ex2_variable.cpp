#include <stdio.h>  // �зǿ�J��X�禡�w
#define PI 3.14159  // �w�q�`�ơ]�����^

int main() {
    // 1. �ܼƻP��ƫ��O
    int a = 10;
    float b = 3.14;
    char c = 'A';
    double d = 1.23456789;

    // 2. ��X�ܼƤ��e
    printf("���: %d\n", a);
    printf("�B�I��: %.2f\n", b);
    printf("�r��: %c\n", c);
    printf("����ׯB�I��: %.8f\n", d);

    // 3. ��J�P��X
    int num;
    printf("�п�J�@�Ӿ��: ");
    scanf("%d", &num);
    printf("�A��J���Ʀr�O: %d\n", num);

    // 4. �B��l�ܽd
    int x = 5, y = 2;
    printf("x + y = %d\n", x + y);  // ��N�B��
    printf("x - y = %d\n", x - y);
    printf("x * y = %d\n", x * y);
    printf("x / y = %d\n", x / y);
    printf("x %% y = %d\n", x % y);  // ���l��

    // ���Y�B��l
    printf("x > y? %d\n", x > y);   // 1�]�u�^
    printf("x == y? %d\n", x == y); // 0�]���^

    // �޿�B��l
    printf("(x > 0 && y < 10)? %d\n", (x > 0 && y < 10)); // 1�]�u�^

    // �줸�B��l
    printf("x & y = %d\n", x & y); // �줸AND
    printf("x | y = %d\n", x | y); // �줸OR
    printf("x ^ y = %d\n", x ^ y); // �줸XOR
    printf("x << 1 = %d\n", x << 1); // ����
    printf("x >> 1 = %d\n", x >> 1); // �k��

    return 0;
}

