#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student
{
	int age;
	double score;
	char name[20];
};

int main(void)
{
	struct Student st1 = { 32,6.6,"С��"};
	//struct Student st2 ;
	//st2.age = 67;
	//strcpy_s(st2.name, 20, "С��");  //�ַ�����ֵ����ʹ�����ַ�ʽ����
	//st2.score = 5.4;

	//getchars();

	//Circle();

	BubbleSort();

	//printf("%d %.3f %s", st1.age, st1.score, st1.name);
	//printf("%d %.3f %s", st2.age, st2.score, st2.name);

	return 1;
}