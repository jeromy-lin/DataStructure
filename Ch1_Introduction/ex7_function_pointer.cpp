#include <stdio.h>

// ﹚竡搭ㄧ计
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int (*operation)(int, int);  // ㄢ俱计把计俱计ㄧ计夹

    int x = 10, y = 5;
    
    // ㄏノ夹ㄧ计 add
    operation = add;
    printf("The sum of %d and %d is: %d\n", x, y, operation(x, y));  // ㊣ add ㄧ计

    // ㄏノ夹ㄧ计 subtract
    operation = subtract;
    printf("The difference of %d and %d is: %d\n", x, y, operation(x, y));  // ㊣ subtract ㄧ计

    return 0;
}

