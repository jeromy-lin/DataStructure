#include <stdio.h>

int main() {
    // �ŧi�ê�l�� 2D �}�C �ЦP�ǰO�� row , column���w�q 
    int Cards[4][5] = {
        {102, 207, 302, 401, 108},
        {105, 206, 312, 407, 211},
        {103, 204, 310, 405, 307},
        {113, 209, 309, 408, 406}
    };

    // �C�L 2D �}�C
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", Cards[i][j]);
            printf("%d ,", *(*(Cards + i) + j)); 
        }
        printf("\n"); // ������ܨC�@�C
        //�ЦP�ǹ��1D array pointer�g�k 
    }
    return 0;
}

