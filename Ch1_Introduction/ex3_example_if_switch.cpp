#include <stdio.h>

int main() {
    int score;
 	int num;

    // 使用者輸入分數
    printf("請輸入分數: ");
    scanf("%d", &score);

    // if-else-if 條件判斷
    if (score >= 90) {
        printf("等級 A\n");
    } else if (score >= 80) {
        printf("等級 B\n");
    } else if (score >= 70) {
        printf("等級 C\n");
    } else {
        printf("不及格\n");
    }
 
    // 使用者輸入數字
    printf("請輸入數字 (1-3): ");
    scanf("%d", &num);

    // switch-case 判斷
    switch (num) {
        case 1:
            printf("你選擇了一號\n");
            break;
        case 2:
            printf("你選擇了二號\n");
            break;
        case 3:
            printf("你選擇了三號\n");
            break;
        default:
            printf("輸入超出範圍\n");
    }
    return 0;
}

