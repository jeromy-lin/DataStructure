/*
	��Ƶ��c�d��   
	�ĤT�� : Linked List 
	�d�� 2 : Typedef struct �ŧi�H�ΨϥΤ�k ���Ы��A�ŧi 
	�ЦP�ǯS�O�[��ϥ�typedef struct �ŧi�@���ܼƥH�Ϋ����ܼƤ��t�O 
	 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct animal {
    int id;               
    char species[50];     
    struct animal *next;  
} Animal, *AnimalPtr;  //�W�[���Ы��A 

int main() {
    // �ϥ� Animal �ŧi�ܼ�
    Animal a1;
    a1.id = 101;
    strcpy(a1.species, "Dog");
    a1.next = NULL;

    // �ϥ� AnimalPtr �ŧi����
    AnimalPtr a2 = (AnimalPtr)malloc(sizeof(Animal));
    if (a2 == NULL) {
        printf("�O������t����\n");
        return 1;
    }
    a2->id = 102;
    strcpy(a2->species, "Cat");
    a2->next = NULL;

    // ��ܵ��G
    printf("Animal �ܼ� (. �B��l): ID=%d, Species=%s\n", a1.id, a1.species);
    printf("Animal ���� (-> �B��l): ID=%d, Species=%s\n", a2->id, a2->species);

    // ����O����
    free(a2);
    return 0;
}

