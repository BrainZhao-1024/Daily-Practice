#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct Student
{
	int age;
	double score;
	char name[20];
};

void getchars(void)
{
	struct Student st1 = { 32,6.6,"С��" };
	struct Student st2;
	st2.age = 67;
	strcpy_s(st2.name, 20, "С��");  //�ַ�����ֵ����ʹ�����ַ�ʽ����
	st2.score = 5.4;

	struct Student* pir;
	pir = &st1;

	pir->age = 12;  //����
	(*pir).age = 13;
	st1.age = 14;
	//*pir.age = 14;  //error
	//st1->age = 15;  //error

	//С�᣺pir->age �ȼ��� *(pir).age �ȼ��� st1.age
	//      pir->    �ȼ��� *(pir).    �ȼ��� st1.

	printf("%d %.3f %s", st1.age, st1.score, st1.name);
	printf("%d %.3f %s", st2.age, st2.score, st2.name);

}