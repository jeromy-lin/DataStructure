#include <stdio.h>

int main() {
    int score;
 	int num;

    // �ϥΪ̿�J����
    printf("�п�J����: ");
    scanf("%d", &score);

    // if-else-if ����P�_
    if (score >= 90) {
        printf("���� A\n");
    } else if (score >= 80) {
        printf("���� B\n");
    } else if (score >= 70) {
        printf("���� C\n");
    } else {
        printf("���ή�\n");
    }
 
    // �ϥΪ̿�J�Ʀr
    printf("�п�J�Ʀr (1-3): ");
    scanf("%d", &num);

    // switch-case �P�_
    switch (num) {
        case 1:
            printf("�A��ܤF�@��\n");
            break;
        case 2:
            printf("�A��ܤF�G��\n");
            break;
        case 3:
            printf("�A��ܤF�T��\n");
            break;
        default:
            printf("��J�W�X�d��\n");
    }
    return 0;
}

