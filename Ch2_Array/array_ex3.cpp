#include <stdio.h>
int main() {
    // �ŧi�ê�l�� 2D �}�C �ЦP�ǰO��row and column���w�q
	// 2D array [4] ���`row���ƶq [5] ���O����column���N�� 
	   
    int Cards[4][5] = {
        {102, 207, 302, 401, 108},
        {105, 206, 312, 407, 211},
        {103, 204, 310, 405, 307},
        {113, 209, 309, 408, 406}
    };
    // ��X�C�ӯ��ޭ� (Index)�B
	// �������}�C�ƭ� (Value) �Ψ�O�����m (Address)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            // ��X���ޡB�ƭȩM�O�����m
            printf("Index: [%d][%d], Value: %d, Address: %p\n", 
                   i, j, Cards[i][j], (void*)&Cards[i][j]);
        }
    }
    return 0;
}

