#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int BuildArr(int* p, int len)
{
	srand((int)time(0));
	*p = rand() % 100 - 49;  //获得-49至50范围内的数
	for (int i = 1; i < len; i++)
		*(p + i) = rand() % 100 - 49;  //获得-49至50范围内的数
	return 0;
}

void OutputSort(int* p, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d  ", *(p + i));

}

int BubbleSort(void)
{/*
 该函数对数组排序并输出；
 */
	int len;
	printf("需要多长的数组？");
	scanf_s("%d", &len);

	int *p = (int*)malloc(sizeof(int)*len);

	BuildArr(p,len);

	printf("随机生成的%d位数组为：", len);
	OutputSort(p, len);

	for (int i = 0; i < len; i++)     //典型冒泡算法
		for (int j = len-1; j > i; j--)
			if (*(p + j) > *(p + j - 1))
			{
				int temp = *(p + j);
				*(p + j) = *(p + j - 1);
				*(p + j - 1) = temp;
			}

	printf("\n排序后的%d位数组为：", len);
	OutputSort(p, len);

	return 0;
}