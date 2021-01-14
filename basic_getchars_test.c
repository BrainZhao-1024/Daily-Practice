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
	struct Student st1 = { 32,6.6,"小张" };
	struct Student st2;
	st2.age = 67;
	strcpy_s(st2.name, 20, "小王");  //字符串赋值必须使用这种方式！！
	st2.score = 5.4;

	struct Student* pir;
	pir = &st1;

	pir->age = 12;  //常用
	(*pir).age = 13;
	st1.age = 14;
	//*pir.age = 14;  //error
	//st1->age = 15;  //error

	//小结：pir->age 等价于 *(pir).age 等价于 st1.age
	//      pir->    等价于 *(pir).    等价于 st1.

	printf("%d %.3f %s", st1.age, st1.score, st1.name);
	printf("%d %.3f %s", st2.age, st2.score, st2.name);

}