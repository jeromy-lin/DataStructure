/*
	��Ƶ��c�d��   
	�ĤT�� : Linked List 
	�d�� 1 : Struct & Typedef struct �ŧi�H�ΨϥΤ�k
	�ЦP�ǯS�O�[��ϥ�typedef struct �ŧi�@���ܼƥH�Ϋ����ܼƤ��t�O 
	 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ϥ� struct �ŧi (�����ϥ� struct person �өw�q�ܼ�)
struct person {
    int age;               //�@���ܼ�
    char name[50];         //�@���ܼ�(�r��)
};

// �ϥ� typedef struct �ŧi (�i�����ϥ� Animal �өw�q�ܼ�)
typedef struct animal {
    int id;               //�@���ܼ�
    char species[50];     //�@���ܼ�(���ئW��)   
} Animal;

int main() {
    // �ϥ� struct �ŧi person �ܼ�
    struct person p1;
    p1.age = 25;
    strcpy(p1.name, "Alice");

    // `a1` �O���c�ܼơA�����s��
    Animal a1;
    a1.id = 101;
    strcpy(a1.species, "Dog");

    // `a2` �O�����ܼơA�ϥ� malloc �ʺA���t�O����
    Animal *a2 = (Animal *)malloc(sizeof(Animal));
    if (a2 == NULL) {
        printf("�O������t����\n");
        return 1;
    }
    a2->id = 102;
    strcpy(a2->species, "Cat");

    printf("�ϥ� struct person (. �B��l):\n");
    printf("Name: %s, Age: %d\n", p1.name, p1.age);

    printf("\n�ϥ� typedef Animal ���c�ܼ� (. �B��l):\n");
    printf("ID: %d, Species: %s\n", a1.id, a1.species);

    printf("\n�ϥ� typedef Animal �����ܼ� (-> �B��l):\n");
    printf("ID: %d, Species: %s\n", a2->id, a2->species);

    // ����O���� 
    free(a2);
    return 0;
}


