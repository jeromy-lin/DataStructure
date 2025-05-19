/*
	��Ƶ��c�d��   
	�Ĥ��� : Tree 
	�d�� 1 : �H Array �]�p�G���� 
	��J�ƭ� N, ���͹������G����
	�Ъ`�N��[0]�������ϥ� 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printTree(int *A, int n) {
    int levels = 0;
    int temp = n;

    // �p���`�h��
    while (temp > 0) {
        temp /= 2;
        levels++;
    }

    int maxWidth = (1 << levels) * 2; // �𪺳̤j�e�סA�Ψӱƪ�

    printf("\n�𪺵��c�G\n");

    int idx = 1; // A�����ޱq1�}�l
    for (int l = 0; l < levels; l++) {
        int nodesInLevel = 1 << l; // �� l �h�� 2^l �Ӹ`�I
        int spaceBetween = maxWidth / nodesInLevel; // �C�Ӹ`�I���j

        // �L�e�����Ů�A���̥��䪺�`�I�m��
        for (int s = 0; s < spaceBetween / 2; s++) {
            printf(" ");
        }

        for (int j = 0; j < nodesInLevel && idx <= n; j++) {
            printf("%2d", A[idx]); // �L���e���Ʀr�]����^
            idx++;

            // �C�Ӹ`�I���᪺�Ů�
            for (int s = 0; s < spaceBetween - 2; s++) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("�п�J�`�I�ƶq n�G");
    scanf("%d", &n);

    if (n <= 0) {
        printf("�`�I�ƶq�����j�� 0�C\n");
        return 1;
    }

    int *A = (int *)malloc((n + 1) * sizeof(int)); // A[0] ���ϥ�
    if (A == NULL) {
        printf("�O������t���ѡC\n");
        return 1;
    }

    // �`�I�s���q1��n
    for (int i = 1; i <= n; i++) {
        A[i] = i;
    }

    printf("\n�`�I�P����`�I�����Y�G\n");
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("�`�I A[%d]=%d �O�ڸ`�I�A�S�����`�I\n", i, A[i]);
        } else {
            printf("�`�I A[%d]=%d �����`�I�O A[%d]=%d\n", i, A[i], i/2, A[i/2]);
        }
    }

    printTree(A, n);

    free(A);
    return 0;
}

