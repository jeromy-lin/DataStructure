#include <stdio.h>
 
int main()
{ 
    int x;            /* �ŧi�@�Ӫ�����ܼ� */
    int *ptr;         /* �ŧi�@�ӫ��V��ƪ������ܼ� 
	//("*ptr" �O��ƫ��O�A�]�� ptr �����O�@�ӫ��V��ƪ�����) */
 
    ptr = &x;         /* ��ȡG�N x ����}�ᵹ ptr */
    printf("Please enter a number: ");
    scanf( "%d", &x );  /* ��J�ƭȡA�N��s�J x�A�i�H�ϥ� ptr �ӥN�� &x */
    printf( "*ptr : %d\n", *ptr );   /* �ϥ� *ptr �ӸѤޥΡA��� ptr ���V���ȡA�]�N�O x ���� */
    printf( "&ptr : %d\n", &ptr );  /* �ϥ� &��� ptr ���O�����} */ 
    printf( "ptr  : %d\n",  ptr );   /* �ϥ� ��� ptr ���s�񪺭� */ 
    printf( "&x   : %d\n",  &x ); /* �ϥ� &x �A��� x ���O�����} */
    printf( "x    : %d\n",  x );   /* �ϥ� x �A��� x ���ܼƭ� */
    getchar(); /* ���ݨϥΪ̫��U Enter �� */

}




