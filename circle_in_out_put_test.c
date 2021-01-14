/*
时间：2021年1月12日17点06分
功能：给struct Student 型变量 st1 赋值，然后输出
目的：
	测试在函数间传送指针和传送数据时，对其内部的值进行修改，
	通过频繁的printf输出，观测这种修改在函数的什么阶段生效，
	今后要注重把握这种延迟生效、局部生效的影响。


*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int global_age = 54;
struct Student
{
	int age;
	double score;
	char name[20];
};

void InputStudent(struct Student* sst)
{
	srand(time(0));
	//sst->age = rand() % 33 + 1;  //能获得随即年龄， 但因为间隔时间太短导致两次随机数一样
	sst->age = ++global_age;
	printf("第一次随机给年龄 %d \n", sst->age);

}

void OutputStudent(struct Student sst)  //详见总结1：不发送指针，1是数据传输慢，2更改不了原数据
{
	InputStudent(&sst);
	printf("%d %.3f %s\n", sst.age, sst.score, sst.name);
}

void Circle(void)
{
	struct Student st1 = { 32,6.6,"小张" };
	
	printf("主函数中第1次输出（原始值）  %d %.3f %s\n", st1.age, st1.score, st1.name);
	InputStudent(&st1);
	printf("主函数中第2次输出（第1次随机年龄）  %d %.3f %s\n", st1.age, st1.score, st1.name);
	OutputStudent(st1);
	printf("主函数中第3次输出（第2次随机年龄）  %d %.3f %s\n", st1.age, st1.score, st1.name);
	
}


/*
-------------------------------------------------
位置：约21行OutputStudent()总结1
总结1：指针的好处
	1.函数间发送指针，能快速传输数据【重要原因】
	2.函数间发送指针，减少内存的耗用【重要原因

总结1的补充：指针的好处
	3.指针能表示一些复杂的数据结构
	4.使函数返回一个以上的值（正常只能由return返回1个值）【重要原因】
	5.能直接访问硬件
	6.能够方便的处理字符串
	7.使理解面向对象语言中引用的灵魂

-------------------------------------------------
输出结果：
	1行	主函数中第1次输出（原始值）  32 6.600 小张
	2行	第一次随机给年龄 55
	3行	主函数中第2次输出（第1次随机年龄）  55 6.600 小张
	4行	第一次随机给年龄 56
	5行	56 6.600 小张
	6行	主函数中第3次输出（第2次随机年龄）  55 6.600 小张
--------------------------------------------------
总结2：
	注意把握5行，在OutputStudent内部生效
			6行，在主函数中不生效
	是由于outputstudent（变量）中传递的是变量数据，不是变量指针

小结：推荐使用 结构体指针变量 作为函数参数在传递
---------------------------------------------------
总结3：一些小知识点
	1.结构体定义时，末尾加  ；
	2.结构体数据不能加减乘除，只能赋值（SG：st1 = st2)
---------------------------------------------------
*/