#include <stdio.h>

int main() {
    int sum = 0;  // �x�s 1 �� 100 ���`�M

    // �ϥ� for �j��p�� 1 �� 100 ���`�M
    for (int i = 1; i <= 100; i++) {
        sum += i;
        if (sum >= 50) {  // ���`�M�F��ζW�L 50 �ɸ��X�j��
            printf("�`�M�F�� 50�A���X�j��C��e�`�M��: %d\n", sum);
            break;  // ���X�j��
        }
    }

    // �ϥ� for �j���X 1 �� 10
    printf("1 �� 10 ���Ʀr��: ");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}

