/*
	資料結構範例   
	第三章 : Linked List 
	範例 2 : Typedef struct 宣告以及使用方法 指標型態宣告 
	請同學特別觀察使用typedef struct 宣告一般變數以及指標變數之差別 
	 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct animal {
    int id;               
    char species[50];     
    struct animal *next;  
} Animal, *AnimalPtr;  //增加指標型態 

int main() {
    // 使用 Animal 宣告變數
    Animal a1;
    a1.id = 101;
    strcpy(a1.species, "Dog");
    a1.next = NULL;

    // 使用 AnimalPtr 宣告指標
    AnimalPtr a2 = (AnimalPtr)malloc(sizeof(Animal));
    if (a2 == NULL) {
        printf("記憶體分配失敗\n");
        return 1;
    }
    a2->id = 102;
    strcpy(a2->species, "Cat");
    a2->next = NULL;

    // 顯示結果
    printf("Animal 變數 (. 運算子): ID=%d, Species=%s\n", a1.id, a1.species);
    printf("Animal 指標 (-> 運算子): ID=%d, Species=%s\n", a2->id, a2->species);

    // 釋放記憶體
    free(a2);
    return 0;
}

