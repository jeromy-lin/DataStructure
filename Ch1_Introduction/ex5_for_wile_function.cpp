#include <stdio.h>

// �Ƶ{���G�p���ӼƦr���`�M
int add(int a, int b) {
    return a + b;
}

// �Ƶ{���G��ܰT��
void displayMessage(int count) {
    printf("�o�O�� %d ����ܰT��\n", count);
}

int main() {
    int counter = 0;  // �p�ƾ���l��
    int sum;

    // �ϥ� while �j��
    while (counter < 3) {
        displayMessage(counter + 1);  // �I�s�Ƶ{����ܰT��
        counter++;
    }

    // �ϥ� do while �j��
    counter = 0;
    do {
        displayMessage(counter + 1);  // �I�s�Ƶ{����ܰT��
        counter++;
    } while (counter < 2);

    // �I�s add �禡�p���`�M����ܵ��G
    sum = add(5, 7);
    printf("5 + 7 ���`�M�O: %d\n", sum);

    return 0;
}
