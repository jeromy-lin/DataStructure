/*
	資料結構範例   
	第三章 : Linked List 
	範例 1 : Struct & Typedef struct 宣告以及使用方法
	請同學特別觀察使用typedef struct 宣告一般變數以及指標變數之差別 
	 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 使用 struct 宣告 (必須使用 struct person 來定義變數)
struct person {
    int age;               //一般變數
    char name[50];         //一般變數(字串)
};

// 使用 typedef struct 宣告 (可直接使用 Animal 來定義變數)
typedef struct animal {
    int id;               //一般變數
    char species[50];     //一般變數(物種名稱)   
} Animal;

int main() {
    // 使用 struct 宣告 person 變數
    struct person p1;
    p1.age = 25;
    strcpy(p1.name, "Alice");

    // `a1` 是結構變數，直接存取
    Animal a1;
    a1.id = 101;
    strcpy(a1.species, "Dog");

    // `a2` 是指標變數，使用 malloc 動態分配記憶體
    Animal *a2 = (Animal *)malloc(sizeof(Animal));
    if (a2 == NULL) {
        printf("記憶體分配失敗\n");
        return 1;
    }
    a2->id = 102;
    strcpy(a2->species, "Cat");

    printf("使用 struct person (. 運算子):\n");
    printf("Name: %s, Age: %d\n", p1.name, p1.age);

    printf("\n使用 typedef Animal 結構變數 (. 運算子):\n");
    printf("ID: %d, Species: %s\n", a1.id, a1.species);

    printf("\n使用 typedef Animal 指標變數 (-> 運算子):\n");
    printf("ID: %d, Species: %s\n", a2->id, a2->species);

    // 釋放記憶體 
    free(a2);
    return 0;
}


